#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    } else {
        char buffer[2];
        int count = 0;
        for (int i = 1; i < argc; i ++) {
            FILE *fp = fopen(argv[i], "rb");
            if (fp == NULL) {
                printf("wunzip: cannot open file\n");
                exit(1);
            }
            
            while (fread(&count, 4, 1, fp)) {
                fread(buffer, 1, 1, fp);
                for (int i = 0; i < count; i ++) {
                    printf("%s", buffer);
                }
            }
          
            fclose(fp);
        }
    }
    
    return 0;
}






