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
package com.android.server;

import android.content.Context;
import android.os.ISizeofService;
import android.util.Log;

public class SizeofService extends ISizeofService.Stub {
    private static final String TAG = "SizeofService";
    private Context mContext;
    private int mNativePointer;

    public SizeofService(Context context) {
        super();
        mContext = context;
        Log.i(TAG, "SizeofService started");

        mNativePointer = init_native();
    }

    public int sizeOfChar() {
        return sizeof_char_native(mNativePointer);
    }

    public int sizeOfShort() {
        return sizeof_short_native(mNativePointer);
    }

    public int sizeOfInt() {
        return sizeof_int_native(mNativePointer);
    }

    public int sizeOfLong() {
        return sizeof_long_native(mNativePointer);
    }

    public int sizeOfFloat() {
        return sizeof_float_native(mNativePointer);
    }

    public int sizeOfDouble() {
        return sizeof_double_native(mNativePointer);
    }

    protected void finalize() throws Throwable {
        finalize_native(mNativePointer);
        super.finalize();
    }

    private static native int init_native();
    private static native void finalize_native(int ptr);
    private static native int sizeof_char_native(int ptr);
    private static native int sizeof_short_native(int ptr);
    private static native int sizeof_int_native(int ptr);
    private static native int sizeof_long_native(int ptr);
    private static native int sizeof_float_native(int ptr);
    private static native int sizeof_double_native(int ptr);
}
