#include <iostream>
#include <string>
#include <Windows.h>
#include <winuser.h>
#include <chrono>
#include <thread>
#include <vector>
#include "Helpers.h"

//convert to KeyBind class, KeyBindHost contains all KeyBinds to listen out for on different threads
using namespace std;

const chrono::milliseconds REST_TIME(50);

int main(int argc, char* argv[]) {
    vector<int> keycodes;
    
    keycodes.push_back(96);
    keycodes.push_back(97);
    keycodes.push_back(98);
    keycodes.push_back(99);
    keycodes.push_back(100);

    //Helpers::getKeycodes(argc, argv, keycodes); //commented for test above
    bool isPressed = false;
    bool isEnabled = true;

    while (isEnabled) {
        if (Helpers::isKeyBindActivated(keycodes)) {
            cout << "Keybind activated" << endl; //replace this with pipe back to js
        }
        this_thread::sleep_for(REST_TIME);
        Helpers::getEnabled(isEnabled);
    }

    return 0;
}

//https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getkeystate?redirectedfrom=MSDN
//https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
//https://github.com/TylerWray2/GlobalDiscordInputHandler/blob/master/WCInputHandler.cpp