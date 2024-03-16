#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grep(char* match, char* input) {
    FILE *fp = fopen(input, "r");
    if (fp == NULL) {
        printf("wgrep: cannot open file\n");
        exit(1);
    }
    
    char* buffer = NULL;
    size_t size = 32;
    while (getline(&buffer,&size,fp) != -1) {
        //fgets(buffer, 60, fp);
        
        //printf("%s", buffer);
        if(strstr(buffer, match)) {
            printf("%s", buffer);
        }
        
    }
    fclose(fp);
}
int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    } else if (argc == 2) {
        char* buffer = NULL;
        size_t size = 32;
        while (getline(&buffer,&size,stdin) != -1) {
            if(strstr(buffer, argv[1])) {
                printf("%s", buffer);
            }
        }
    } else {
        for (int i = 2; i < argc; i ++) {
            grep(argv[1], argv[i]);
        }
    }
    
    return 0;
}






