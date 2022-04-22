# image_resizer
A simple c++ program that uses libpng and OpenCL to resize images.

# Tools
- OS: Void linux
- Compiler: gcc
- Editor: neovim

# Prerequisites
- make
- cmake
- pkg-config
- libpng:
  I grabbed the source code(version: 1.6.37) from it's official website.
  After downloading the source code, there's a nice and self-explanatory INSTALL document.
  To recap i ran the following commands to build libpng:
  ```
  cmake . -DCMAKE_INSTALL_PREFIX=/home/linarcx/libpng
  make
  make install
  ```

- OpenCl
  There's a `libclc` package in VoidLinux that i used it.

# Build
```
git clone https://github.com/LinArcX/image_resizer
cd image_resizer
mkdir -p output/cmake output/debug output/release
cd output/cmake/
cmake -DCMAKE_BUILD_TYPE=Release ../..
make -j8
```

And finally run the program:

`../release/image_resizer`

## License
![License](https://img.shields.io/github/license/LinArcX/image_resizer.svg)