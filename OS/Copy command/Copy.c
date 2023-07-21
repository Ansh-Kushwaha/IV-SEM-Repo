#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc > 3) {
        printf("Invalid arguments \n");
        exit(0);
    }
    else {
        FILE *fp1, *fp2;

        fp1 = fopen(argv[1], "r");
        if (fp1 == NULL) {
            printf("Cannot open file %s \n", argv[1]);
            exit(0);
        }
        if (access(argv[2], F_OK) == 0) {
            printf("Can't copy file already exist \n");
            char comm;
            printf("Do you want to override the contents of the file %s (y/n): ", argv[2]);
            scanf("%c", &comm);
            if (comm != 'y' && comm != 'n') {
                printf("Invalid command aborting\n");
                exit(0);
            }
            else if (comm == 'n')
                exit(0);
        }
        fp2 = fopen(argv[2], "w");

        char c;
        c = fgetc(fp1);
        while (c != EOF) {
            fputc(c, fp2);
            c = fgetc(fp1);
        }
        printf("Contents copied to %s \n", argv[2]);
        fclose(fp1);
        fclose(fp2);
    }
    
    return 0;
}