#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <WinUser.h>
#include <chrono>
#include <thread>

using namespace std;

static const chrono::milliseconds POLL(20);

struct Keybind {
	Keybind() {};	
	vector<int> keys;
	string name;
	bool run = true;
	void Dispatch() {
		thread key_thread([this]() {
			bool is_pressed = true;
			while (run) {
				for (vector<int>::iterator it = keys.begin(); it != keys.end(); it++) {
					is_pressed = is_pressed && (GetKeyState(*it) & 0x8000);
				}
				if (is_pressed) { cout << name << endl; this_thread::sleep_for(chrono::seconds(1)); }
				is_pressed = true;
				this_thread::sleep_for(POLL);
			}
			return;
		});

		key_thread.detach();
	};


};