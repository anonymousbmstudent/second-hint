cc  = gcc
src = src/main.c src/compare.c


ifeq ($(OS),Windows_NT)
	lib          = deps/libsecret.dll
	target       = build/second-hint.exe
	cc_lib_flags = -O2 -Wall -Wextra -DSECRET_EXPORTS -shared
else
	lib          = deps/libsecret.so
	target       = build/second-hint
	cc_lib_flags = -O2 -Wall -Wextra -shared -fPIC 
endif


cc_flags = -O2 -Wall -Wextra -Ldeps -lsecret


make_lib:
	$(cc) $(cc_lib_flags) -o $(lib) src/secret.c


all: $(src) make_lib
	mkdir -p build
	$(cc) $(cc_flags) -o $(target) $(src)
ifeq ($(OS),Windows_NT)
	copy "$(lib)" build/
endif


run: all
ifeq ($(OS),Windows_NT)
	./$(target)
else
	LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):deps ./$(target)
endif


clean:
ifeq ($(OS),Windows_NT)
	rmdir /s /q "build"
else
	rm -rf build
endif


.PHONY: all run clean
