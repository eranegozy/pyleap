# make.sh (for clang, on osx)
clang++ -shared -I include lib/osx/libLeap.dylib -o libLeapC.so LeapC.cpp
mv libLeapC.so ../pyleap/osx
