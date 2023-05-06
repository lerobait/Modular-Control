CC = clang-14
C_OPTS = -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wlogical-not-parentheses -Wunused-variable -Wnull-dereference -Werror=vla 
LAB_OPTS = -I./src src/lib.c
V_FLAGS=--tool=memcheck --leak-check=full --show-reachable=yes \
	--undef-value-errors=yes --track-origins=no --child-silent-after-fork=no \
	--trace-children=no --error-exitcode=1

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin test.bin

test.bin: test/test.c
	$(CC) $(C_OPTS) $(LAB_OPTS) $< -o ./dist/$@ -lcheck -lm -lsubunit

test: clean prep compile
	./dist/test.bin

main.bin: src/main.c
	$(CC) $(C_OPTS) $(LAB_OPTS) $< -o ./dist/$@ -lm
run: clean prep compile
	./dist/main.bin
leak-check: clean prep compile
	valgrind $(V_FLAGS) --log-file=dist/valgrind.log --xml-file=dist/valgrind.xml --xml=yes dist/main.bin
	valgrind $(V_FLAGS) --log-file=dist/valgrind.log --xml-file=dist/valgrind.xml --xml=yes dist/test.bin

check:
	clang-format --verbose -dry-run --Werror src/*
	clang-tidy src/*.c  -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump
doxygen:
	doxygen
