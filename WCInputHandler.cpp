#include <iostream>
#include <string>
#include <Windows.h>
#include <winuser.h>
#include <chrono>
#include <thread>

using namespace std;

chrono::milliseconds REST_TIME(50);

int main(int argc, char* argv[]) {
    while (true) {
        int keyCode = stoi(string(argv[1]));
        if (GetAsyncKeyState(keyCode) & 0x01) {
            return 0;
        }
        this_thread::sleep_for(REST_TIME);
    }

    return 1;
}
