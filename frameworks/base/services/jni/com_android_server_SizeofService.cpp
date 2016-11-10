/*
 * Copyright (C) 2016 Onik
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#define LOG_TAG "SizeofServiceJNI"

#include "jni.h"
#include "JNIHelp.h"
#include "android_runtime/AndroidRuntime.h"

#include <utils/misc.h>
#include <utils/Log.h>
#include <hardware/hardware.h>
#include <hardware/sizeofhw.h>

#include <stdio.h>

namespace android
{

sizeofhw_device_t* sizeofhw_dev;

static jint init_native(JNIEnv *env, jobject clazz)
{
    int err;
    hw_module_t* module;
    sizeofhw_device_t* dev = NULL;

    err = hw_get_module(SIZEOFHW_HARDWARE_MODULE_ID, (hw_module_t const**)&module);
    if (err == 0) {
        if (module->methods->open(module, "SizeofServiceJNI calling open", ((hw_device_t**) &dev)) != 0) {
            return 0;
        }
    }

    return (jint)dev;
}

static void finalize_native(JNIEnv *env, jobject clazz, int ptr)
{
    sizeofhw_device_t* dev = (sizeofhw_device_t*)ptr;

    if (dev == NULL) {
        return;
    }

    free(dev);
}

static int sizeof_char_native(JNIEnv *env, jobject clazz, int ptr)
{
    sizeofhw_device_t* dev = (sizeofhw_device_t*)ptr;

    if (dev == NULL) {
        return 0;
    }

    return dev->sizeof_char();
}

static int sizeof_short_native(JNIEnv *env, jobject clazz, int ptr)
{
    sizeofhw_device_t* dev = (sizeofhw_device_t*)ptr;

    if (dev == NULL) {
        return 0;
    }

    return dev->sizeof_short();
}

static int sizeof_int_native(JNIEnv *env, jobject clazz, int ptr)
{
    sizeofhw_device_t* dev = (sizeofhw_device_t*)ptr;

    if (dev == NULL) {
        return 0;
    }

    return dev->sizeof_int();
}

static int sizeof_long_native(JNIEnv *env, jobject clazz, int ptr)
{
    sizeofhw_device_t* dev = (sizeofhw_device_t*)ptr;

    if (dev == NULL) {
        return 0;
    }

    return dev->sizeof_long();
}

static int sizeof_float_native(JNIEnv *env, jobject clazz, int ptr)
{
    sizeofhw_device_t* dev = (sizeofhw_device_t*)ptr;

    if (dev == NULL) {
        return 0;
    }

    return dev->sizeof_float();
}

static int sizeof_double_native(JNIEnv *env, jobject clazz, int ptr)
{
    sizeofhw_device_t* dev = (sizeofhw_device_t*)ptr;

    if (dev == NULL) {
        return 0;
    }

    return dev->sizeof_double();
}

static JNINativeMethod method_table[] = {
    { "init_native",            "()I", (void*)init_native },
    { "finalize_native",        "(I)V", (void*)finalize_native },
    { "sizeof_char_native",     "(I)I", (void*)sizeof_char_native},
    { "sizeof_short_native",    "(I)I", (void*)sizeof_short_native},
    { "sizeof_int_native",      "(I)I", (void*)sizeof_int_native},
    { "sizeof_long_native",     "(I)I", (void*)sizeof_long_native},
    { "sizeof_float_native",    "(I)I", (void*)sizeof_float_native},
    { "sizeof_double_native",   "(I)I", (void*)sizeof_double_native},
};

int register_android_server_SizeofService(JNIEnv *env)
{
    return jniRegisterNativeMethods(env, "com/android/server/SizeofService",
            method_table, NELEM(method_table));

};

};