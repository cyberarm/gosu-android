LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL2
GOSU_PATH := ../gosu

#LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(GOSU_PATH)/include

# Add your application source files here...
LOCAL_SRC_FILES := gosu_app.cpp

LOCAL_SHARED_LIBRARIES := gosu SDL2

LOCAL_LDLIBS := -llog -landroid -lGLESv1_CM -lGLESv2

include $(BUILD_SHARED_LIBRARY)
