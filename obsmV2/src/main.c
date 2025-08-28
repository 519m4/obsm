#include "main.h"

INT main(INT argc, char* argv[])
{
    INT num;

    if (argc < 2) {

        printf("Drag and drop to encrypt/decrypt file.");
        return;
    
    }

    SetFileAttributesA(argv[1], FILE_ATTRIBUTE_NORMAL);

    char* choice1[2] = { "Encrypt", "Decrypt" };

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