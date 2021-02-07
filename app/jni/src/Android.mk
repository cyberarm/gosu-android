LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL2
GOSU_PATH := ../gosu

#LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(GOSU_PATH)/include

# Add your application source files here...
LOCAL_SRC_FILES := gosu_app.cpp

LOCAL_SHARED_LIBRARIES := gosu

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
