#include "h_getkeyPresses.h"

/*
-- handle keypress
*/
void handleKeyPress(bool *isEnabled, char i){
	switch(i){
			//0
		case VK_NUMPAD0:
			if(isEnabled[0]== false){
				isEnabled[0] = true;
			}
			else{
				isEnabled[0] = false;
			}
			break;
			//1
		case VK_NUMPAD1:
			if(isEnabled[1]== false){
				isEnabled[1] = true;
			}
			else{
				isEnabled[1] = false;
			}
			break;
			//2
		case VK_NUMPAD2:
			if(isEnabled[2]== false){
				isEnabled[2] = true;
			}
			else{
				isEnabled[2] = false;
			}
			break;
			//3
		case VK_NUMPAD3:
			if(isEnabled[3]== false){
				isEnabled[3] = true;
			}
			else{
				isEnabled[3] = false;
			}
			break;
			//4
		case VK_NUMPAD4:
			if(isEnabled[4]== false){
				isEnabled[4] = true;
			}
			else{
				isEnabled[4] = false;
			}
			break;
			//5
		case VK_NUMPAD5:
			if(isEnabled[5]== false){
				isEnabled[5] = true;
			}
			else{
				isEnabled[5] = false;
			}
			break;
			//6
		case VK_NUMPAD6:
			if(isEnabled[6]== false){
				isEnabled[6] = true;
			}
			else{
				isEnabled[6] = false;
			}
			break;
			//7
		case VK_NUMPAD7:
			if(isEnabled[7]== false){
				isEnabled[7] = true;
			}
			else{
				isEnabled[7] = false;
			}
			break;
			//8
		case VK_NUMPAD8:
			if(isEnabled[8]== false){
				isEnabled[8] = true;
			}
			else{
				isEnabled[8] = false;
			}
			break;
	}
}

/*
-- press the keys
*/
void sendInput(bool *isEnabled){	
	INPUT ip;
	int ind;
	ind = 0;
	for(ind = 0; ind < MAX_KEYS ; ind++){
		//just press the key if it should
		if(isEnabled[ind] == true){
			ip.type = INPUT_KEYBOARD;
			ip.ki.time = 0;
			ip.ki.dwFlags = KEYEVENTF_UNICODE;
			ip.ki.wScan = 0;
			//for each keystroke
			switch(ind){
		
			case 0:
				ip.ki.wVk = 0x30;
				break;
			case 1:
				ip.ki.wVk = 0x31;
				break;
			case 2:
				ip.ki.wVk = 0x32;
				break;
			case 3:
				ip.ki.wVk = 0x33;
				break;
			case 4:
				ip.ki.wVk = 0x34;
				break;
			case 5:
				ip.ki.wVk = 0x35;
				break;
			case 6:
				ip.ki.wVk = 0x36;
				break;
			case 7:
				ip.ki.wVk = 0x37;
				break;
			case 8:
				ip.ki.wVk = 0x38;
				break;
			}
			ip.ki.dwExtraInfo = 0;
			SendInput(1, &ip, sizeof(INPUT));
		}
	}
}

/*
-- turns all keys off
*/
void clearAll(bool *isEnabled){
	int i;
	i = 0;
	
	for(i = 0; i < MAX_KEYS; i++){
		isEnabled[i] = false;
	}
}