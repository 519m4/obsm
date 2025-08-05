#include "main.h"

INT main(INT argc, char* argv[])
{
    char* choice1[2] = { "Encrypt", "Decrypt" };
    char* choice2[2] = { "Yes", "No" };

    if (argc < 2) {
        printf("plz set file bro");
        return 1;
    }
    printf("obsm made by Sigma\nChoose Encrypt or Decrypt\n(If you want to decrypt file, you need to put key and nonce on same dir)\nDir: %s\n", argv[1]);

    INT num = selectionmenu((sizeof(choice1) / sizeof(choice1[0])), choice1);

    FILE* in = fopen(argv[1], "rb");

    FILE* out = (num == 0) ? fopen("enc", "wb") : fopen("decrypted", "wb");

    if (!out) {

        perror("[ERROR]fopen:");
        return 1;

    }

    Chacha20_crypto(in, out, num);

    if (num == 0) {

        printf("\nWould you want to delete origin source file?\n");

        INT num2 = selectionmenu((sizeof(choice2) / sizeof(choice2[0])), choice2);

        if (num2 == 0) {

            remove(argv[1]);

        }

    }

    return 0;

}