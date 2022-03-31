#include "Dispatcher.h"

int main(int argc, char** argv) {
	Keybind leave, queue, lqueue;
	leave.keys.emplace_back(VK_END);
	queue.keys.emplace_back(VK_NUMPAD7);
	queue.keys.emplace_back(VK_NEXT);
	lqueue.keys.emplace_back(VK_NUMPAD8);
	lqueue.keys.emplace_back(VK_NEXT);
	leave.name = "END";
	queue.name = "PGDOWN + NUMPAD7";
	lqueue.name = "PGDOWN + NUMPAD8";
	Dispatcher disp;
	disp.binds.push_back(&leave);
	disp.binds.push_back(&queue);
	disp.binds.push_back(&lqueue);
	disp.Start();
	return 0;
}