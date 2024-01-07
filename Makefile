all: build
	cd build && ninja
build:
	mkdir -p build && cd build && cmake -GNinja -DCMAKE_CXX_COMPILER=/bin/c++-x86 -DCMAKE_C_COMPILER=/bin/gcc-x86 -DCMAKE_BUILD_TYPE=Debug ..

