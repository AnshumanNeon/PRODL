compiler = gcc-9

compiler_flags = -Wall -Werror -Wpedantic

include_dir = include
src_dir = src
build_dir = build

src_files = $(wildcard $(src_dir)/*.c)

target = PRODL

$(build_dir)/$(target):
	mkdir -p $(build_dir)
	$(compiler) $(compiler_flags) -I$(include_dir) $(src_files) test/test.c -o $@

clean:
	rm -rf $(build_dir)

.PHONY: $(build_dir)/$(target) clean
