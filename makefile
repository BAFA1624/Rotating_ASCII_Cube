project_name=RAC

cc=gcc

dbg_dir = debug
rel_dir = release
src_dir = src
obj_dir = obj
bin_dir = bin

cstd=c17
libs=-lm
cflags=-Wall -Wextra -pedantic -Werror -std=$(cstd) $(libs)

debug: cflags += -O0 -ggdb -g
debug: build_dir = debug
test: build_dir = debug
release: cflags += -O3 -DNDEBUG
release: build_dir = release

srcs = $(wildcard $(src_dir)/*.c)
objs = $(patsubst $(src_dir)/%.c, $(build_dir)/$(obj_dir)/%.o, $(srcs))

bin = $(build_dir)/$(bin_dir)/$(project_name)

all: debug

test: debug
	./$(bin)

debug: $(bin)

release: $(bin)

$(bin): $(objs)
	$(cc) $(cflags) $(objs) -o $(build_dir)/$(bin_dir)/$(project_name)

$(build_dir)/$(obj_dir)/%.o: $(src_dir)/%.c
	$(cc) $(cflags) -c $< -o $(build_dir)/$(obj_dir)/$*.o

clean_dbg:
	$(RM) -r $(dbg_dir)/$(obj_dir)/* $(dbg_dir)/$(bin_dir)/*

clean_rel:
	$(RM) -r $(rel_dir)/$(obj_dir)/* $(rel_dir)/$(bin_dir)/*

clean:
	$(RM) -r $(rel_dir)/$(bin_dir)/* $(rel_dir)/$(obj_dir)/* $(dbg_dir)/$(bin_dir)/* $(dbg_dir)/$(obj_dir)/*
