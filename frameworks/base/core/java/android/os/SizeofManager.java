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
package android.os;

import android.os.ISizeofService;

public class SizeofManager {
    ISizeofService mService;

    public SizeofManager(ISizeofService service) {
        mService = service;
    }

    public int sizeOfChar() {
        try {
            return mService.sizeOfChar();
        } catch (RemoteException e) {
            return -1;
        }
    }

    public int sizeOfShort() {
        try {
            return mService.sizeOfShort();
        } catch (RemoteException e) {
            return -1;
        }
    }

    public int sizeOfInt() {
        try {
            return mService.sizeOfInt();
        } catch (RemoteException e) {
            return -1;
        }
    }

    public int sizeOfLong() {
        try {
            return mService.sizeOfLong();
        } catch (RemoteException e) {
            return -1;
        }
    }

    public int sizeOfFloat() {
        try {
            return mService.sizeOfFloat();
        } catch (RemoteException e) {
            return -1;
        }
    }

    public int sizeOfDouble() {
        try {
            return mService.sizeOfDouble();
        } catch (RemoteException e) {
            return -1;
        }
    }
}
