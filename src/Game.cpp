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

#include "Game.hpp"

#include <ncurses.h>

#include "Viewport.hpp"
#include "Buffer.hpp"

using namespace NcursesTest;

void Game::initializeNcurses() {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
}

int Game::run() {
    int code = 0;

    const int fps = 3;
    timeout(1000 / fps);

    Viewport viewport(150, 40);
    int x = -40, y = -7;

    Buffer buffer(500, 15);

    buffer.fill(0, 0, 1, 20, '|');
    buffer.set(10, 10, '*');
    buffer.fill(20, 0, 1, 20, '|');
    buffer.set(30, 5, '^');
    buffer.fill(40, 0, 1, 20, '|');
    buffer.set(50, 7, '#');
    buffer.fill(60, 0, 1, 20, '|');
    buffer.set(70, 6, '(');
    buffer.fill(80, 0, 1, 20, '|');
    buffer.set(90, 9, ')');
    buffer.fill(100, 0, 1, 20, '|');
    buffer.set(110, 8, '{');
    buffer.fill(120, 0, 1, 20, '|');

    std::string instructions = "q to quit, hjkl to move";
    Viewport guiViewport(instructions.length(), 1);

    Buffer guiBuffer(instructions.length(), 1);

    int w = 0, h = 0;

    while (true) {
        viewport.x = x;
        viewport.y = y;

        getScreenSize(w, h);
        guiBuffer.setContents(instructions, w, h);

        mvaddstr(0, 0, std::string(w * h, ' ').c_str());

        viewport.draw(stdscr, buffer);
        guiViewport.draw(stdscr, guiBuffer);

        char c = getch();

        if (c == 'q')
            break;
        else if (c == 'k')
            y -= 5;
        else if (c == 'j')
            y += 5;
        else if (c == 'h')
            x -= 5;
        else if (c == 'l')
            x += 5;
    }

    endwin();
    return code;
}
