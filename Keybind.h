#pragma once
#include <cstdlib>
#include <Windows.h>
#include <winuser.h>
#include <chrono>
#include <thread>
//#include <iostream>

//convert to KeyBind class, KeyBindHost contains all KeyBinds to listen out for on different threads
using namespace std;

static const chrono::milliseconds REST_TIME(25);

class Keybind {
    public:
        Keybind(int& numkeys, char* argv[]) {
            this->argc = argc;
            this->argv = argv;
            this->numkeys = numkeys;
            this->Listen();
        }

        void Listen() {
            for (it = 0; it < numkeys; it++)
                keycodes[it] = atoi(argv[it + 1]);

            while (isEnabled) {
                for (it = 0; ret && (it < numkeys); it++) {
                    ret = (GetKeyState(keycodes[it]) & 0x8000);
                }
                if (ret) { /*cout << "active" << endl;*/ /*do something */ }
                ret = true;
                this_thread::sleep_for(REST_TIME);
                isEnabled = !(GetKeyState(VK_ESCAPE) & 0x8000);
            }
        }
    private:
        int argc;
        char** argv;
        int keycodes[4] = { -1,-1,-1,-1 };
        bool ret = true, isEnabled = true;
        unsigned int numkeys;
        unsigned int it = 0;
};