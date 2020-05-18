# build_linux.sh
# this is built with rpath, which assumes that libLeap.so will be in the same directory 
# as the cwd when libLeapC.so is loaded. This ends up being similar behavior to how
# windows handles dlls by default. Good discussion of this here:
# https://amir.rachum.com/blog/2016/09/17/shared-libraries/
clang++ -shared -I include lib/linux/libLeap.so -o libLeapC.so -fpic -Wl,-rpath,. LeapC.cpp
mv libLeapC.so ../pyleap/linux
