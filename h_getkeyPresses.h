#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#define WINVER 0x0500
#include <Windows.h>

#define MAX_KEYS 9

void handleKeyPress(bool *isEnabled, char i);
void sendInput(bool *isEnabled);
void clearAll(bool *isEnabled);