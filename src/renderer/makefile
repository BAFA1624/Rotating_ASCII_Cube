cc=gcc

std=-c17
cflags=-Wall -Wextra -pedantic
libs=-lX11

src=learning_xlib.c
obj=learning_xlib.o

all: $(obj)
	$(CC) $(cflags) $(cstd) $(libs) $(obj)

$(obj):
	$(CC) $(cflags) $(cstd) $(libs) -c $(src) -o $(obj)

clean:
	rm a.out $(obj)
