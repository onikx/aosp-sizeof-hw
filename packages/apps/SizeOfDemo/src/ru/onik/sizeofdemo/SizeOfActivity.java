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
package ru.onik.sizeofdemo;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.os.SizeofManager;
import android.text.TextUtils;
import android.view.KeyEvent;
import android.view.inputmethod.EditorInfo;
import android.widget.EditText;
import android.widget.TextView;

public class SizeOfActivity extends Activity {
    private TextView mOutput;
    private SizeofManager mSizeofManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_layout);

        mSizeofManager = (SizeofManager) getSystemService(Context.SIZEOF_SERVICE);
        mOutput = (TextView) findViewById(R.id.tv);

        showNativeSizeof();
    }

    private void showNativeSizeof() {
        StringBuilder strBuilder = new StringBuilder();
        strBuilder.append("Native sizeofs:\n")
                .append("\tsizeof char\t\tis ").append(mSizeofManager.sizeOfChar()).append(" byte(s)\n")
                .append("\tsizeof short\t\tis ").append(mSizeofManager.sizeOfShort()).append(" byte(s)\n")
                .append("\tsizeof int\t\t\tis ").append(mSizeofManager.sizeOfInt()).append(" byte(s)\n")
                .append("\tsizeof long\t\tis ").append(mSizeofManager.sizeOfLong()).append(" byte(s)\n")
                .append("\tsizeof float\t\tis ").append(mSizeofManager.sizeOfFloat()).append(" byte(s)\n")
                .append("\tsizeof double\tis ").append(mSizeofManager.sizeOfDouble()).append(" byte(s)\n");

        mOutput.setText(strBuilder.toString());
    }
}
