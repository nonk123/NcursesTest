/*
 * MIT License
 * 
 * Copyright (c) 2019 nonk123
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "Buffer.hpp"

#include <string>

using namespace NcursesTest;

void Buffer::setContents(std::string contents, int w, int h) {
    this->contents = contents;
    this->w = w;
    this->h = h;

    check(this->contents);
}

void Buffer::check(std::string& str) {
    std::string tmp(w * h, ' ');

    if (contents.length() > w * h)
        for (int i = 0; i < w * h; i++)
            tmp[i] = contents[i];
    else if (contents.length() < w * h)
        for (int i = 0; i < w * h; i++)
            if (i < contents.length()) tmp[i] = contents[i];
            else tmp[i] = defaultCharacter;
    else
        return;

    str = tmp;
}

void Buffer::fill(int x, int y, int w, int h, char fill) {
    for (int i = x; i < x + w; i++)
        for (int j = y; j < y + h; j++)
            if (check(i, j))
                set(i, j, fill);
}

void Buffer::put(int x, int y, std::string str) {
    int col = x;
    int row = y;

    for (int i = 0; i < str.length(); i++) {
        if (col > w || str[i] == '\n' || str[i] == '\r') {
            col = x;
            row++;
        } else if (row > h) {
            break;
        }

        set(col++, row, str[i]);
    }
}
