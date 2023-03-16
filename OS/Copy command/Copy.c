#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc > 3) {
        printf("Invalid arguments \n");
        exit(0);
    }
    else {
        FILE *fp1, *fp2;

        fp1 = fopen(argv[1], "r");
        fp2 = fopen(argv[2], "w");

        if(fp1 == NULL) {
            printf("Cannot open file %s \n", argv[1]);
            exit(0);
        }
        if(fp2 == NULL) {
            printf("Cannot open file %s \n", argv[2]);
            exit(0);
        }

        char c;
        c = fgetc(fp1);
        while(c != EOF) {
            fputc(c, fp2);
            c = fgetc(fp1);
        }
        printf("Contents copied to %s", argv[2]);
        fclose(fp1);
        fclose(fp2);
    }
    
    return 0;
}