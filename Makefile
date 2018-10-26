export NDK_PROJECT_PATH:=$(shell pwd)
CFLAGS = -Wall -fexceptions -Wfatal-errors -Wall -std=gnu++11
LDFLAGS =
RESINC =
LIBDIR =
LOCAL_PATH := $(call my-dir)


ifeq ($(OS),Windows_NT)
    CC = gcc.exe
    CXX = g++.exe
    AR = ar.exe
    LD = g++.exe
    WINDRES = windres.exe
    CFLAGS += -DOS_WIN
    PATHSEP2=\\
    WORKDIR = %cd%
    LOCAL_C_INCLUDES := $(WORKDIR)\\src\\include
else
    CC = gcc
    CXX = g++
    AR = ar
    LD = g++
    PATHSEP2=/
    LOCAL_C_INCLUDES := $(shell pwd)/src/include
    CFLAGS += -I$(LOCAL_C_INCLUDES)
    LIB = -I/usr/local/include/ -L/usr/local/lib/ -I/usr/include/ -I$(LOCAL_C_INCLUDES)
endif



prefix=~/bin

INC_RELEASE =  $(INC)

RESINC_RELEASE =  $(RESINC)
RCFLAGS_RELEASE =  $(RCFLAGS)
LIBDIR_RELEASE =  $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE =  $(LDFLAGS) -s

ifeq ($(DEBUG), 1)
    CFLAGS_RELEASE =  $(CFLAGS) -g
    OBJDIR_RELEASE = obj$(PATHSEP2)Debug
    OUTPUT         = Debug
else
    CFLAGS_RELEASE =  $(CFLAGS) -O3
    OBJDIR_RELEASE = obj$(PATHSEP2)Release
    OUTPUT         = Release
endif

DEP_RELEASE =
ifeq ($(OS),Windows_NT)
    OUT_RELEASE = bin$(PATHSEP2)$(OUTPUT)$(PATHSEP2)readgpt.exe
else
    OUT_RELEASE = bin$(PATHSEP2)$(OUTPUT)$(PATHSEP2)readgpt
endif

OBJ_RELEASE = $(OBJDIR_RELEASE)$(PATHSEP2)src$(PATHSEP2)main.o \
	$(OBJDIR_RELEASE)$(PATHSEP2)src$(PATHSEP2)model$(PATHSEP2)GPT.o \
	$(OBJDIR_RELEASE)$(PATHSEP2)src$(PATHSEP2)util$(PATHSEP2)Log.o

before_release:
	@mkdir -p bin$(PATHSEP2)$(OUTPUT)
	@mkdir -p $(OBJDIR_RELEASE)$(PATHSEP2)src
	@mkdir -p $(OBJDIR_RELEASE)$(PATHSEP2)src$(PATHSEP2)model
	@mkdir -p $(OBJDIR_RELEASE)$(PATHSEP2)src$(PATHSEP2)util

after_release:

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LDFLAGS_release) $(LIBDIR_RELEASE) $(OBJ_RELEASE) $(LIB_RELEASE) -o $(OUT_RELEASE)

$(OBJDIR_RELEASE)$(PATHSEP2)src$(PATHSEP2)main.o: src$(PATHSEP2)main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src$(PATHSEP2)main.cpp \
    -o $(OBJDIR_RELEASE)$(PATHSEP2)src$(PATHSEP2)main.o
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src$(PATHSEP2)model$(PATHSEP2)GPT.cpp \
    -o $(OBJDIR_RELEASE)$(PATHSEP2)src$(PATHSEP2)model$(PATHSEP2)GPT.o
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src$(PATHSEP2)util$(PATHSEP2)Log.cpp \
    -o $(OBJDIR_RELEASE)$(PATHSEP2)src$(PATHSEP2)util$(PATHSEP2)Log.o

linux: before_release out_release after_release
	@echo Compiling Linux
windows:
	@echo Compiling windows
android:
	@echo Compiling Android
	$(CONFIG_ANDROID_NDK_BUILD_TOOL)/ndk-build NDK_APPLICATION_MK=src/Application.mk

clean:
	@rm -rf obj 
	@rm -rf bin 
	@rm -rf libs 
