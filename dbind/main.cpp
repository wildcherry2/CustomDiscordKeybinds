#include "Dispatcher.h"

int main(int argc, char** argv) {
	Keybind leave, queue, lqueue;
	leave.keys.emplace_back(VK_END);
	leave.name = "END";
	Dispatcher disp;
	disp.binds.push_back(&leave);
	disp.Start();
	return 0;
}