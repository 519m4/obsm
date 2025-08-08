#include "main.h"

BOOL test(VOID) {

	HANDLE hfind;
	WIN32_FIND_DATA win32fd;

	hfind = FindFirstFile("c:\\*.*", &win32fd);

	if (hfind == INVALID_HANDLE_VALUE) {

		return FALSE;

	}

	do {

		if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {

			printf("%s (DIR)\n", win32fd.cFileName);

		}
		else {

			printf("%s (File)\n", win32fd.cFileName);

		}

	} while (FindNextFile(hfind, &win32fd));

	FindClose(hfind);

	return TRUE;

}