#include "main.h"

VOID WDeletefile(const char* origin) {

	char* buf = "2";
	FILE* file = fopen(origin, "wb");

	fwrite(buf, 1, 8, file);

	INT desc = _fileno(file);

	_chsize_s(desc, 8 * 2);

	fclose(file);

	remove(origin);
}