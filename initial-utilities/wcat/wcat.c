#include <stdio.h>
#include <stdlib.h>

void cat(char* input) {
    FILE *fp = fopen(input, "r");
    if (fp == NULL) {
        printf("wcat: cannot open file\n");
        exit(1);
    }
    char buffer[60];
    while (1) {
        fgets(buffer, 60, fp);
        if(feof(fp)) {
            break;
        }
        printf("%s", buffer);
    }
    fclose(fp);
}
int main(int argc, char* argv[]) {
    if (argc <= 1) {
        return 0;
    }
    for (int i = 1; i < argc; i ++) {
        cat(argv[i]);
    }
    
    return 0;
}






