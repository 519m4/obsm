#pragma once
/*Includes*/
#include <Windows.h>
#include <stdio.h>
#include <stdint.h>
#include <bcrypt.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/types.h>
#include <winternl.h>
#include <io.h>
#include "Algorithms/Chacha20.h"
#include "lib/includes/include.h"
/*Libs*/
#pragma comment(lib, "bcrypt.lib")
#pragma comment(lib, "volatileaccessu.lib")
#pragma warning(disable : 4996)
#define CHUNK (4 * 1024 * 1024)
//VOID Crypt(FILE* outstream, FILE* cxstream, INT selection);
VOID Crypt(FILE* outstream, INT selection);
#pragma region public
uint8_t key[32];
uint8_t nonce[12];
#pragma endregion