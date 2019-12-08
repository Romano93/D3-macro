#include <iostream>
#include <vector>
#include <algorithm>
#define WINVER 0x0500
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "h_getkeyPresses.h"

using namespace std;

int main(){

	FreeConsole();
	//definition
	int counter;
	int target;
	char i;
	bool abbort;
	char last;
	char lastLast;
	//zahlen
	bool isEnabled[MAX_KEYS];
	//time
	clock_t start;
	clock_t end;
	//initialisation
	abbort = false;
	counter = 0;
	last = 1;
	lastLast = 0;
	//random zahlengenerator
	srand (time(NULL));
	target = rand() %200 + 300;
	//zahlen
	for(counter = 0; counter < MAX_KEYS; counter++){
		isEnabled[counter] = false;
	}
	counter = 0;
	//schlaufe
	start = clock();
	end = start + target;
	do{
		for(i = 8; i <= 255; i++){
			if(GetAsyncKeyState(i) == -32767){		
				// the key / on the numpad
				last = i;
				if(i == VK_NUMPAD9){
					abbort = true;
				}
				else if(i == VK_DECIMAL){
					clearAll(isEnabled);
				}
				else{
					handleKeyPress(isEnabled, i);
				}				
			}
			if(abbort){
				break;
			}
			start = clock();
			if(start >= end){
				sendInput(isEnabled);
				start = clock();				
				target = rand() %200 + 300;
				end = start + target;
			}
		}
	}while(!abbort);
	return 0;
}

