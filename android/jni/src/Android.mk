LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := main

#SDK_ROOT points to folder with SDL and oxygine-framework
LOCAL_SRC_FILES := ../../../../libraries/SDL/src/main/android/SDL_android_main.c

FILE_LIST := $(wildcard $(LOCAL_PATH)/core_components/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/commands/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/units/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/units/enemies/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/items/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/world/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/ui_components/*.cpp)

LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_STATIC_LIBRARIES := oxygine-framework_static
LOCAL_SHARED_LIBRARIES := SDL2

include $(BUILD_SHARED_LIBRARY)


#import from NDK_MODULE_PATH defined in build.cmd
$(call import-module, oxygine-framework)
