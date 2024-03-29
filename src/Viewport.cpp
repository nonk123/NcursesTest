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

#include "Viewport.hpp"

#include <ncurses.h>

#include <algorithm>

using namespace NcursesTest;

void Viewport::draw(WINDOW* window, Buffer buffer) {
    int windowW = 0;
    int windowH = 0;

    getmaxyx(window, windowH, windowW);

    for (int i = 0; i < std::min(windowW, w); i++)
        for (int j = 0; j < std::min(windowH, h); j++)
            if (buffer.check(x + i, y + j))
                mvwaddch(window, j, i, buffer.get(x + i, y + j));
}
