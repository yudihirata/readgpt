export PATH:=$(PATH):$(CONFIG_ANDROID_NDK_BUILD_TOOL)
export NDK_PROJECT_PATH:=$(shell pwd)
APP_BUILD_SCRIPT=src/Android.mk
APP_OPTIM := release

# This variable stores a set of C compiler flags that the build system passes to the compiler when
# compiling any C or C++ source code for any of the modules. You can use this variable to change
# the build of a given module according to the application that needs it, instead of having to
#  modify the Android.mk file itself.
APP_CFLAGS :=

APP_ABI := all 

APP_PLATFORM := android-23

APP_STL := c++_static

# Define this variable as 4.9 to select that version of the GCC compiler. Define this variable as
# clang to select the Clang compiler, which is the default value for NDK r13 and later.
NDK_TOOLCHAIN_VERSION := clang
