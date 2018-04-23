.PHONY: all

libZGL.so: ./src/initializer.cpp
	${CXX} -shared -fPIC -Wl,-soname,$@ -m32 $< -o $@

all: libZGL.so