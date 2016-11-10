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
#include <errno.h>

#define  LOG_TAG  "sizeofhw_qemu"
#include <stdint.h>
#include <stdlib.h>

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <cutils/native_handle.h>

#include <cutils/log.h>
#include <cutils/sockets.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <hardware/sizeofhw.h>

#define   SIZEOFHW_DEBUG   1

#if SIZEOFHW_DEBUG
#  define D(...)   ALOGD(__VA_ARGS__)
#else
#  define D(...)   ((void)0)
#endif

int size_of_char(void)
{
    return sizeof(char);
}

int size_of_short(void)
{
    return sizeof(short);
}

int size_of_int(void)
{
    return sizeof(int);
}

int size_of_long(void)
{
    return sizeof(long);
}

int size_of_float(void)
{
    return sizeof(float);
}

int size_of_double(void)
{
    return sizeof(double);
}

static int open_sizeofhw(const struct hw_module_t* module, char const* name,
        struct hw_device_t** device)
{
    struct sizeofhw_device_t *dev = malloc(sizeof(struct sizeofhw_device_t));
    memset(dev, 0, sizeof(*dev));

    dev->common.tag = HARDWARE_DEVICE_TAG;
    dev->common.version = 0;
    dev->common.module = (struct hw_module_t*)module;
    dev->sizeof_char    = size_of_char;
    dev->sizeof_short   = size_of_short;
    dev->sizeof_int     = size_of_int;
    dev->sizeof_long    = size_of_long;
    dev->sizeof_float   = size_of_float;
    dev->sizeof_double  = size_of_double;

    *device = (struct hw_device_t*) dev;

    D("SIZEOF HW has been initialized");

    return 0;
}

static struct hw_module_methods_t sizeofhw_module_methods = {
    .open = open_sizeofhw
};

struct hw_module_t HAL_MODULE_INFO_SYM = {
    .tag = HARDWARE_MODULE_TAG,
    .version_major = 1,
    .version_minor = 0,
    .id = SIZEOFHW_HARDWARE_MODULE_ID,
    .name = "Goldfish Sizeof HW Module",
    .author = "Onik",
    .methods = &sizeofhw_module_methods,
};
