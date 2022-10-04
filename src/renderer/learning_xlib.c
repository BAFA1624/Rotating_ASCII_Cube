#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>

void setSizeHint(
        Display* display, Window window,
        int minWidth, int minHeight,
        int maxWidth, int maxHeight);

Status toggleMaximize(Display* display, Window window);

int main() {
    // Vars for later
    int width  = 800;
    int height = 600;

    // Get connection to X Server.
    // Passing NULL/0 returns the default window defined in the environment variables.
    Display* display = XOpenDisplay(0);
    if (!display) {
        printf("No display available\n!");
        exit(1);
    }

    /* Need to get a root window. Windows have a tree structure, so must all have a parent.
     * We are making a normal top level window, so our parent must be the "desktop".
     * */
    int root = DefaultRootWindow(display);
    /* We also get the default screen. In X, a screen is generally just an area/buffer to be rendered to.
     * This can be via a graphics device onto a monitor, or completely in software to an in-memory target.
     * */
    int defaultScreen = DefaultScreen(display);

    /* Next we define our requirements for our render target.
     * Back in 1984 this was more interesting with a variety of color depths & monochrome displays.
     * Nowadays this is almost always the same, 24bits for RGB-8-8-8 and TrueColor.
     * */
    int screenBitDepth = 24;
    /* XMatchVisual takes our requirements, matches them against an internal list of visual infos
     * that this hardware supports, and then returns the best fit.
     * */
    XVisualInfo visinfo;
    if (!XMatchVisualInfo(display, defaultScreen, screenBitDepth, TrueColor, &visinfo)) {
        printf("No matching visual info.\n");
        exit(1);
    }

    /* Next we create the window.
     * We use the "XSetWindowAttributes" structure to set attributes for the window we are creating.
     * We set the background_pixel to black & create a colromap from the visinfo we created earlier.
     * Then we define "attributeMask", which tells "XCreateWindow" which of the attributes we want to
     * get used.
     * */
    XSetWindowAttributes windowAttr;
    windowAttr.bit_gravity = StaticGravity; // Helps prevent flicker on resize
    windowAttr.background_pixel = 0;
    windowAttr.colormap =
        XCreateColormap(
            display,
            root,
            visinfo.visual,
            AllocNone
        );
    windowAttr.event_mask = StructureNotifyMask | KeyPressMask | KeyReleaseMask;
    unsigned long attributeMask = CWBitGravity | CWBackPixel | CWColormap | CWEventMask;

    /* "XCreateWindow" is pretty self explanatory at this point, "XCreateSimpleWindow" also exists.
     * "InputOutput" means this window will receive and handle incoming events & also output to the
     * screen.
     * */
    Window window =
        XCreateWindow(
            display, root,
            0, 0,
            width, height, 0,
            visinfo.depth, InputOutput,
            visinfo.visual, attributeMask,
            &windowAttr
        );
    if (!window) {
        printf("Window wasn't created properly\n");
        exit(1);
    }

    // Set an appropriate name for the window.
    XStoreName(display, window, "Hello, World!");

    // Set min + max width/height for window
    setSizeHint(display, window, 100, 50, 0, 0);

    // Map the window onto the display.
    XMapWindow(display, window);

    // Toggle fullscreen
    // toggleMaximize(display, window);

    // Flushes output buffer, ensuring all commands are sent to the server.
    XFlush(display);

    // 32 bits per pixel: 3 x 8bits for RGB value.
    int pixelBits = 32;
    int pixelBytes = pixelBits / 8;
    // Get buffer
    int windowBufferSize = width * height * pixelBytes;
    char* mem = (char*) malloc(windowBufferSize);
    if (!mem) {
        printf("Memory allocation for write buffer failed.\n");
        exit(1);
    }

    // The arguments for XCreateImage are as follows:
    // - Display* display (connection to the X-server),
    // - Visual* visual (the visual structure),
    // - unsigned int depth (depth of the image),
    // - int format (format for the image),
    // - int offset (no. of pixels to ignore at the beginning of each scanline),
    // - char* data (specifies the image data),
    // - unsigned int width (width of image in pixels),
    // - unsigned int height (height of image in pixels),
    // - int bitmap_pad (specifies quantum of a scanline [8,16,32]),
    // - int bytes_per_line (no. of bytes in client image between scanlines)
    //
    // Pass buffer to a compatible image structure.
    // In XLib speach:
    // - A bitmap is an image stored and used locally.
    // - A pixmap is a bitmap that can be set to the X server, and then displayed
    //   on a monitor.
    //
    // There are a couple of types of pixmap:
    // - XYPixmap: A series of bitmaps, one for each bit plane of the image, using
    //   the bitmap padding rules from the connection setup.
    // - ZPixmap: A series of bits, nibbles, bytes, or words; one for each pixel.
    XImage* xWindowBuffer =
        XCreateImage(
            display, visinfo.visual, visinfo.depth,
            ZPixmap, 0, mem, width, height,
            pixelBits, 0);

    // Create a graphic context. Information for X which is hardware specific.
    GC defaultGC = DefaultGC(display, defaultScreen);

    // Set a display property so the window manager sends a message about window deletion so
    // we can handle it ourselves.
    Atom WM_DELETE_WINDOW = XInternAtom(display, "WM_DELETE_WINDOW", False);
    if (!XSetWMProtocols(display, window, &WM_DELETE_WINDOW, 1)) {
        printf("Couldn't register WM_DELETE_WINDOW property.\n");
    }

    bool sizeChange = false;
    bool windowOpen = true;

    // Basic event loop
    while (windowOpen) { // MAIN_LOOP

        XEvent ev;
        // int XPending(Display* display) returns no. of events received from the X-Server
        // but have not been removed from the event queue yet.
        while (XPending(display) > 0) { // EVENT_LOOP
            // Retrieves next event from queue and removes it.
            // If empty, flushes the ouput buffer and blocks until an event is received.
            XNextEvent(display, &ev);
            //printf("%d\n", ev.type);
            switch(ev.type) {
                case DestroyNotify: {
                    //printf("Destroy notification received.\n");
                    // Cast generic event to XDestroyWindowEvent*
                    XDestroyWindowEvent* e = (XDestroyWindowEvent*) &ev;
                    // If target of destroy event is our window, set windowOpen to false
                    if (e->window == window) {
                        windowOpen = false;
                    }
                } break;
                case ClientMessage: {
                    //printf("Client message received.\n");
                    // Cast event to XClientMessageEvent
                    XClientMessageEvent* e = (XClientMessageEvent*)&ev;

                    // If delete window event.
                    if ((Atom)e->data.l[0] == WM_DELETE_WINDOW) {
                        // Destroy window, also destroys any child windows.
                        XDestroyWindow(display, window);
                        windowOpen = false;
                    }
                } break;
                case ConfigureNotify: {
                    //printf("Updating size.\n");
                    XConfigureEvent* e = (XConfigureEvent*)&ev;
                    width  = e->width;
                    height = e->height;
                    sizeChange = true;
                } break;
                case KeyPress: {
                    XKeyPressedEvent* e = (XKeyPressedEvent*)&ev;
                    if (e->keycode == XKeysymToKeycode(display, XK_Left)) printf("Left arrow pressed\n");
                    if (e->keycode == XKeysymToKeycode(display, XK_Right)) printf("Right arrow pressed\n");
                    if (e->keycode == XKeysymToKeycode(display, XK_Up)) printf("Up arrow pressed\n");
                    if (e->keycode == XKeysymToKeycode(display, XK_Down)) printf("Down arrow pressed\n");
                }
                case KeyRelease: {
                    XKeyPressedEvent* e = (XKeyPressedEvent*)&ev;

                    if (e->keycode == XKeysymToKeycode(display, XK_Left)) printf("Left arrow released\n");
                    if (e->keycode == XKeysymToKeycode(display, XK_Right)) printf("Right arrow released\n");
                    if (e->keycode == XKeysymToKeycode(display, XK_Up)) printf("Up arrow released\n");
                    if (e->keycode == XKeysymToKeycode(display, XK_Down)) printf("Down arrow released\n");
                }
         }
    } // EVENT_LOOP

        // Adjust picture on window resize
        if (sizeChange) {
            sizeChange = false;
            // Free memory allocated for displayed image.
            // This also frees the char* buffer we allocated.
            XDestroyImage(xWindowBuffer);
            windowBufferSize = width * height * pixelBytes;
            mem = (char*)malloc(windowBufferSize);

            xWindowBuffer =
                XCreateImage(
                    display, visinfo.visual, visinfo.depth,
                    ZPixmap, 0, mem, width, height,
                    pixelBits, 0);
        }

        // Drawing a grid of black lines to the screen.
        int pitch = width * pixelBytes;
        for (int y = 0; y < height; ++y) {
            char* row = mem + (y * pitch);
            for (int x = 0; x < width; ++x) {
                unsigned* p = (unsigned*) (row + (x * pixelBytes));
                if (x%16 && y%16) { // Draw black
                    *p = 0xffffffff;
                }
                else { // Draw white
                    *p = 0;
                }
            }
        }

        XPutImage(display, window,
                defaultGC, xWindowBuffer, 0, 0, 0, 0,
                width, height);

    } // MAIN_LOOP
    
    return 0;
}

void setSizeHint(
        Display* display, Window window,
        int minWidth, int minHeight,
        int maxWidth, int maxHeight) {
    XSizeHints* hints = XAllocSizeHints();
    if (minWidth > 0 && minHeight > 0) hints->flags |= PMinSize;
    if (maxWidth > 0 && maxWidth > minWidth &&
            maxHeight > 0 && maxHeight > minHeight) {
        hints->flags |= PMaxSize;
    }

    hints->min_width = minWidth;
    hints->min_height = minHeight;
    hints->max_width = maxWidth;
    hints->max_height = maxHeight;

    XSetWMNormalHints(display, window, hints);

    XFree((void*)hints);
}

/* Time to learn the API to communicate w/ the iwndow manager, atoms & properties.
 * Information and properties about our window are stored insdie X in so called "properties".
 * These "properties" are identified by unique labels known as "atoms".
 * Essentially, X calles key-value pairs atom-property pairs.
 * */
Status toggleMaximize(Display* display, Window window) {
    XClientMessageEvent ev;

    Atom wmState = XInternAtom(display, "_NET_WM_STATE", False);
    Atom maxH    = XInternAtom(display, "_NET_WM_STATE_MAXIMIZED_HORZ", False);
    Atom maxV    = XInternAtom(display, "_NET_WM_STATE_MAXIMIZED_VERT", False);

    if (wmState == None) return 0;

    ev.type = ClientMessage;
    ev.format = 32;
    ev.window = window;
    ev.message_type = wmState;
    ev.data.l[0] = 2;
    ev.data.l[1] = maxH;
    ev.data.l[2] = maxV;
    ev.data.l[3] = 1;

    return
        XSendEvent(
            display, DefaultRootWindow(display),
            False, SubstructureNotifyMask, (XEvent*)&ev
        );
}

