CC = clang++
LAB_OPTS = -I./src src/hand.cpp src/player.cpp src/game.cpp
GTEST_DIR = /usr/src/googletest/googletest/include
C_OPTS = -std=c++14 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin test.bin

main.bin: src/main.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@
test.bin: test/test.cpp
	$(CC) $(C_OPTS) $< $(ARCH) -fprofile-instr-generate -fcoverage-mapping -o ./dist/$@ -I$(GTEST_DIR) -lgtest_main -lgtest -lpthread
test: clean prep compile
	./dist/test.bin
run: clean prep compile
	./dist/main.bin
doxygen:
	doxygen Doxyfile
check:
	clang-format --verbose -dry-run --Werror src/* test/*
	cppcheck --enable=all --inconclusive --addon=cert \
		--error-exitcode=1 -v --suppress=unreadVariable:*/main.cpp \
		--suppress=knownConditionTrueFalse:*/main.cpp --suppress=missingIncludeSystem \
		--check-config --suppress=*:*/test.cpp --suppress=unmatchedSuppression:*/main.cpp .
	rm -rf src/*.dump test/*.dump
all: clean prep compile check
# TODO: clang-tidy; scan-build
