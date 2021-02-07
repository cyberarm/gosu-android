LOCAL_PATH := $(call my-dir)

###########################
#
# OpenAL shared library
#
###########################

include $(CLEAR_VARS)

LOCAL_MODULE := openal

LOCAL_C_INCLUDES := \
					$(LOCAL_PATH)/include

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

LOCAL_SRC_FILES := \
	$(wildcard $(LOCAL_PATH)/alc/*.c) \

LOCAL_CFLAGS += -DAL_BUILD_LIBRARY -DAL_ALEXT_PROTOTYPES
 
LOCAL_LDLIBS := -lOpenSLES

ifeq ($(NDK_DEBUG),1)
    cmd-strip :=
endif

include $(BUILD_SHARED_LIBRARY)

