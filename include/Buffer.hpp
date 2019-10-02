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

#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <string>

namespace NcursesTest {
    const char defaultCharacter = ' ';

    class Buffer {
      private:
        std::string contents;
        int w, h;

      public:
        Buffer(std::string contents, int w, int h) {
            setContents(contents, w, h);
        }

        Buffer(int w, int h, char fill = defaultCharacter)
            : Buffer(std::string(w * h, fill), w, h) {
        }

        std::string getContents() {
            return contents;
        }

        void setContents(std::string contents, int w, int h);

        int getWidth() {
            return w;
        }

        int getHeight() {
            return h;
        }

        bool check(int x, int y) {
            return x >= 0 && x < w && y >= 0 && y < h;
        }

        void check(std::string& str);

        char get(int x, int y) {
            return check(x, y) ? contents[x + w * y] : defaultCharacter;
        }

        char set(int x, int y, char value) {
            return check(x, y) ? contents[x + w * y] = value : defaultCharacter;
        }

        void fill(int x, int y, int w, int h, char fill);

        void put(int x, int y, std::string str);
    };
}

#endif
