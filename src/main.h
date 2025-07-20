#pragma once
#include <Windows.h>
#include <stdio.h>
#include <stdint.h>
#include <bcrypt.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/types.h>
#include "Chacha20.h"

#pragma comment(lib, "bcrypt.lib")
#pragma warning(disable : 4996)
#define CHUNK (4 * 1024 * 1024) //4mb

VOID Chacha20_crypto(FILE* instream, FILE* outstream, INT selection);

#pragma region public
uint8_t key[32];
uint8_t nonce[12];
#pragma endregion