# Instructions for building LeapC for python 3.x

The Leap v2 sdk is only built for python2.7. Building for python 3.x is problematic and annoying, requiring a specific old version of SWIG. It also requires building a new lib for each new version of python 3. 

Instead, we avoid SWIG altogether and use python `ctypes` to load a library directly and create python bindings using pure python code. The only problem is that `libLeap` is a c++ library, so it can't be used with `ctypes`. To get around this, we created a super-minimal c-wrapper to expose a few regular c-functions. We call this library `LeapC` (ie `libLeapC.dylib` or `LeapC.dll`, `libLeapC.so`). With this bridge library, the rest is handled by python in `pyleap/leap.py`.

The source files have been downloaded from [Leapmotion's dev website](https://developer.leapmotion.com/setup/desktop). These are the header files in `include` and the binaries files in `lib`. Please read and accept Leapmotion's EULA before continuing. 

## Mac

- Make sure XCode is installed with command-line tools
- `source build_osx.sh`
- This will build with clang++ and then move the build to the right place.

## Windows

- Make sure Microsoft Visual Studio Community is installed (this is free).
- Open `build_win/LeapC.sln`
- Build it (F7). This should create a Release build and copy it to the right place.

## Linux
- Install clang
- `source build_osx.sh`
