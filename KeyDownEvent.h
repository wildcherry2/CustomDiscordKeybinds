#pragma once
#include <stdio.h>

class KeyDownEvent {
	public:
		KeyDownEvent(int keycode) {
			this->keycode = keycode;
			//listenHandler = bind(&KeyDownEvent::listen, &(*this));
		}

		void listen() {
			bool press = false;
			while (!press) {
				if (GetAsyncKeyState(keycode) & 0x01) {
					press = true;
				}
			}
			//activeFlag = false;
		}

		bool getPressed() { return pressed; }
		void setPressed(bool val) { pressed = val; }
		void resetPressed() { pressed = false; }
		int* getKeycode() { return &keycode; }

		/*function<void()>* getListenHandler() {
			return &listenHandler;
		}*/

	private:
		int keycode;
		bool pressed = false;
		//void(KeyDownEvent::* listenHandler)();
		//function<void()> listenHandler;
};