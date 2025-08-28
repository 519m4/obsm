#include "main.h"

VOID Crypt(_Inout_ FILE* outstream, _In_ INT selection, _In_opt_ BOOL b) {

	if (selection == 0) { //Gen key & nonce 

		char* choice1[2] = { "Yes", "No" };

		if (PathFileExistsA("key") || PathFileExistsA("nonce")) {

			printf("\nWARNING!\n\nkey file or nonce file is already exists.\nIt'll be overwritten if you continue!\n\nOverwrite file?\n");

			INT num = selectionmenu((sizeof(choice1) / sizeof(choice1[0])), choice1);

			if (num == 1) {

				printf("\nAction cancelled.");

				return;
				
			}

		}

		(VOID)BCryptGenRandom(NULL, key4chacha20, sizeof(key4chacha20), BCRYPT_USE_SYSTEM_PREFERRED_RNG);
		(VOID)BCryptGenRandom(NULL, nonce4chacha20, sizeof(nonce4chacha20), BCRYPT_USE_SYSTEM_PREFERRED_RNG);

		FILE* keyc = fopen("key", "wb");
		FILE* noncec = fopen("nonce", "wb");

		if (!keyc || !noncec) {

			perror("[ERROR]Create keys");
			return;

		}

		fwrite(key4chacha20, 1, sizeof(key4chacha20), keyc);
		fwrite(nonce4chacha20, 1, sizeof(nonce4chacha20), noncec);
		fclose(keyc);
		fclose(noncec);

	}

	else if (selection == 1) { // read a key & nonce

		FILE* keyfilec = fopen("key", "rb");
		FILE* noncefilec = fopen("nonce", "rb");

		if (!keyfilec || !noncefilec) {

			perror("[ERROR]fopen:");
			return;

		}

		fread(key4chacha20, 1, sizeof(key4chacha20), keyfilec);
		fread(nonce4chacha20, 1, sizeof(nonce4chacha20), noncefilec);

		fclose(noncefilec);
		fclose(keyfilec);

	}


	size_t bytes;
	
	long long offsets = 0;

	UINT8* buffer = (UINT8*)malloc(CHUNK);

	if (!buffer) {

		perror("buffer");
		return;

	}

	struct chacha20_context ctx;
	chacha20_init_context(&ctx, key4chacha20, nonce4chacha20, 0);

	

	while ((bytes = fread(buffer, 1, CHUNK, outstream)) > 0) {

		chacha20_xor(&ctx, buffer, (UINT)bytes);

		_fseeki64(outstream, offsets, SEEK_SET);

		fwrite(buffer, 1, bytes, outstream);

		offsets += bytes;
		
		_fseeki64(outstream, offsets, SEEK_SET);

	}

	fclose(outstream);
	free(buffer);

	RtlSecureZeroMemory2(&key4chacha20, sizeof(key4chacha20));
	RtlSecureZeroMemory2(&key4chacha20, sizeof(key4chacha20));

	printf("\nSuccessfully Decrypt/Encrypt.");

	return;

}