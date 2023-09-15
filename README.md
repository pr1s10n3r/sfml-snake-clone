## Install Dependencies

My main development environment is a Linux PC with KDE Neon, so I could not
(and by that I mean I didn't want) test on other distributions such as Fedora.

### Installing Dependencies on Debian/Ubuntu

```shell
sudo apt update
sudo apt install \
    libxrandr-dev \
    libxcursor-dev \
    libudev-dev \
    libopenal-dev \
    libflac-dev \
    libvorbis-dev \
    libgl1-mesa-dev \
    libegl1-mesa-dev \
    libdrm-dev \
    libgbm-dev \
    libfreetype6-dev
```

## Building

The build process is done through [CMake](https://cmake.org/). To generate the required build
files and then compile them, run these commands:

```shell
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug
```