#include "main.h"

INT main(INT argc, char* argv[])
{
    INT num;
    INT num2;

    if (argc < 2) {
        printf("plz set file bro");
        return 1;
    }
    printf("[INFO]Enter 0 or 1.\n0:Encrypt file\n1:Decrypt file(you need to put key and nonce on same dir)\n>>");

    scanf_s("%d", &num);

    printf("[INFO]Would you want to delete origin source file?\n>>");

    scanf_s("%d", &num2);


    FILE* in = fopen(argv[1], "rb");

    FILE* out = (num == 0) ? fopen("enc", "wb") : fopen("decrypted", "wb");

    if (!out) {

        perror("[ERROR]fopen:");
        return 1;

    }

    Chacha20_crypto(in, out, num);

    if (num2 == 0) {

        remove(argv[1]);
        return 0;

    }
    return 0;

}