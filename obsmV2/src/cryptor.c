#include "main.h"

VOID Crypt(FILE* outstream, INT selection) {

	if (selection == 0) { //Gen key & nonce 

		(VOID)BCryptGenRandom(NULL, key, sizeof(key), BCRYPT_USE_SYSTEM_PREFERRED_RNG);
		(VOID)BCryptGenRandom(NULL, nonce, sizeof(nonce), BCRYPT_USE_SYSTEM_PREFERRED_RNG);

		FILE* keyc = fopen("key", "wb");
		FILE* noncec = fopen("nonce", "wb");

		if (!keyc || !noncec) {

			perror("[ERROR]Create keys");
			return;

		}

		fwrite(key, 1, sizeof(key), keyc);
		fwrite(nonce, 1, sizeof(nonce), noncec);
		fclose(keyc);
		fclose(noncec);

	}

	else if (selection == 1) { // read a key & nonce

		FILE* keyfile = fopen("key", "rb");
		FILE* noncefile = fopen("nonce", "rb");

		if (!keyfile || !noncefile) {

			perror("[ERROR]fopen:");
			return;

		}

		fread(key, 1, sizeof(key), keyfile);
		fread(nonce, 1, sizeof(nonce), noncefile);
		fclose(noncefile);
		fclose(keyfile);

	}


	size_t bytes;
	
	long long offsets = 0;

	UINT8* buffer = (UINT8*)malloc(CHUNK);

	if (!buffer) {

		perror("buffer");
		return;

	}

	struct chacha20_context ctx;
	chacha20_init_context(&ctx, key, nonce, 0);

	

	while ((bytes = fread(buffer, 1, CHUNK, outstream)) > 0) {

		chacha20_xor(&ctx, buffer, (UINT)bytes);

		_fseeki64(outstream, offsets, SEEK_SET);

		fwrite(buffer, 1, bytes, outstream);

		offsets += bytes;
		
		_fseeki64(outstream, offsets, SEEK_SET);

	}

	fclose(outstream);
	free(buffer);

	RtlSecureZeroMemory2(&key, sizeof(key));
	RtlSecureZeroMemory2(&key, sizeof(key));

	printf("\nSuccessfully Decrypt/Encrypt.");

	return;

}