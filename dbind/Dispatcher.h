#pragma once
#include "Keybind.h"

struct Dispatcher {
	thread disp_thread;
	vector<Keybind*> binds;
	bool run = true;
	void Start() {
		disp_thread = thread([this]() {
			for (vector<Keybind*>::iterator it = binds.begin(); it != binds.end(); it++) {
				Keybind* ptr = *it;
				ptr->Dispatch();
			}
			while (run) { 
				for (vector<Keybind*>::iterator it = binds.begin(); it != binds.end(); it++) {
					Keybind* ptr = *it;
					run = run && ptr->run;
				}
				this_thread::sleep_for(POLL);
			}
		});

		disp_thread.join();
	};
};
