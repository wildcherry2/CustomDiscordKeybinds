//#pragma once
//#include <vector>
//using namespace std;
//class Helpers {
//	public:
//		static void getKeycodes(int& argc, char**& argv, vector<int>& keyCodes) {
//			for (int i = 1; i < argc; i++) {
//				keyCodes.push_back(stoi(string(argv[i])));
//			}
//		}
//
//		static bool isKeyBindActivated(vector<int>& keyCodes) {
//			bool ret = true;
//			vector<int>::iterator prev = keyCodes.begin();
//
//			for (vector<int>::iterator current = keyCodes.begin(); (current != keyCodes.end()) && ret; current++) {
//				ret = (GetKeyState(*current) & 0x8000);
//				prev++;
//			}
//			return ret;
//		}
//
//		static void getEnabled(bool& isEnabled) {
//			isEnabled = !(GetKeyState(VK_ESCAPE) & 0x8000);
//		}
//};