#include "main.h"

INT main(INT argc, char* argv[])
{
    INT num;

    char* choice1[2] = { "Encrypt", "Decrypt" };

    char* choice2[2] = { "Yes", "No" };

    if (argc < 2) {

        printf("Would you want to encrypt all file within specific folder?\n");



        return 1;

    }

    printf("obsm made by Sigma\nChoose Encrypt or Decrypt\n(If you want to decrypt file, you need to put key and nonce on same dir)\nDir: %s\n\n\nUse arrow keys to select, then press Enter key:\n", argv[1]);

    num = selectionmenu((sizeof(choice1) / sizeof(choice1[0])), choice1);

    FILE* out = fopen(argv[1], "rb+");

    if (!out) {

        perror("[ERROR]fopen:");
 
        return 1;

    }

    Crypt(out, num);
    
    return 0;

}