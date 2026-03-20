compiler = gcc-9

compiler_flags = -Wall -Werror -Wpedantic

include_dir = include
src_dir = src
build_dir = build

target = PRODL

$(build_dir)/$(target):
	$(compiler) $(compiler_flags) -I$(include_dir) $(src_files) -o $@

clean:
	rm -rf $(build_dir)

.PHONY: $(build_dir)/$(target) clean
