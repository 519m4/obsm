#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

int selectionmenu(int n, const char* strings[]);
int checknum(int maxcount, int currentcursor);
void Draw_menu_test(int current, const char* options[], int maxcount, HANDLE consolehandle, WORD attributesaved);