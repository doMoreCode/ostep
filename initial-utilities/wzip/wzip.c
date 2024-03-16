#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void writeToFile(int count, char *buffer) {
    fwrite(&count, 4, 1, stdout);
    fwrite(buffer, 1, 1, stdout);
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    } else {
        char old[2],new[2];
        int count = 0;
        for (int i = 1; i < argc; i ++) {
            FILE *fp = fopen(argv[i], "rb");
            if (fp == NULL) {
                printf("wzip: cannot open file\n");
                exit(1);
            }
            
            while (fread(new, 1, 1, fp)) {
                if (strcmp(new, old) == 0) {
                    count ++;
                } else {
                    if(old[0] != '\0') {
                        writeToFile(count, old);
                        
                    }

                    count = 1;
                    strcpy(old, new);
                }
            }
          
            fclose(fp);
        }
        writeToFile(count, old);  
    }
    
    return 0;
}






