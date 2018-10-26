LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE :=readgpt
LOCAL_SRC_FILES := main.cpp model/GPT.cpp util/Log.cpp
LOCAL_CPPFLAGS := -std=gnu++0x -Wall -fPIE              # whatever g++ flags you like
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog -fPIE -pie   # whatever ld flags you like
LOCAL_CPP_FEATURES += exceptions
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
include $(BUILD_EXECUTABLE)    # <-- Use this to build an executable.
