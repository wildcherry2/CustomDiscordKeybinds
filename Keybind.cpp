#pragma once
#include "Keybind.h"
#include <vector>

//use vector, adding/removing is a rare event so resize is ok, iterators have very quick access

class KeybindHost {
	public:

	private:

};


int main(int argc, char* argv[]) {
	int numkeys = argc - 1;
	Keybind* kb = new Keybind(numkeys, argv);
}

//https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getkeystate?redirectedfrom=MSDN
//https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
//https://github.com/TylerWray2/GlobalDiscordInputHandler/blob/master/WCInputHandler.cpp