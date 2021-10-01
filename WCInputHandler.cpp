#include <iostream>
#include <string>
#include <Windows.h>
#include <winuser.h>
#include <chrono>
#include <thread>
#include <future>

using namespace std;

chrono::milliseconds REST_TIME(50);

int main(int argc, char* argv[]) {
        int numKeysInBind = argc - 1;
        int* keycode = new int[numKeysInBind]; //memory management

        for (int i = 0; i < numKeysInBind; i++) {
            keycode[i] = stoi(string(argv[i + 1]));
        }
        bool press = false;
        switch (numKeysInBind)
        {
        case 1:
            while (!press) {
                if (GetKeyState(keycode[0]) & 0x01) {
                    press = true;
                    cout << "Keypress detected" << endl;
                }
                this_thread::sleep_for(REST_TIME);
            }
        case 2:
            while (!press) {
                if ((GetKeyState(keycode[0]) & 0x8000) && (GetKeyState(keycode[1]) & 0x8000)) {
                    press = true;
                    cout << "Keypress detected" << endl;
                }
                this_thread::sleep_for(REST_TIME);
            }
        default:
            break;
        }
    
    return 1;
}

//handle multiple button presses with 4 bools