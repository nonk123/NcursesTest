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

#include <ctime>
#include <vector>
#include <string>

using namespace NcursesTest;

void Game::initializeNcurses() {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
}

int Game::run() {
    int code = 0;

    int shipX = 0;
    int shipY = 0;

    int w = 0;
    int h = 0;

    const int starSeed = std::time(nullptr);
    const int fumesSeed = std::time(nullptr);

    const float starDensity = 0.006f;
    const float fumesDensity = 0.1f;

    const int fps = 5;
    timeout(1000 / fps);

    std::string ship("<\\-=-/>");
    std::vector<std::string> fumes{ "`", "\'", ",", "." };

    while (true) {
        getScreenSize(w, h);
        buffer = std::string(w * h, ' ');
        shipY = h / 2;

        mvaddstr(0, 0, buffer.c_str());

        std::srand(starSeed);

        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                if (static_cast<float>(std::rand()) / RAND_MAX <= starDensity) {
                    mvaddch(y, x, '*');
                }
            }
        }

        mvaddstr(0, 0, "q to quit");

        std::srand(fumesSeed);

        for (int x = 0; x < shipX; x++) {
            if (static_cast<float>(std::rand()) / RAND_MAX <= fumesDensity) {
                mvaddstr(shipY, x, fumes[std::rand() % fumes.size()].c_str());
            }
        }

        mvaddstr(shipY, shipX, ship.c_str());

        refresh();

        if (getch() == 'q') {
            break;
        }

        shipX++;

        if (shipX > w - ship.length()) {
            break;
        }
    }

    endwin();
    return code;
}
