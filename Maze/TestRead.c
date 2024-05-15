#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char temp;
    char filename[100];
    printf("Enter Filename: ");
    scanf("%s", filename);
    FILE *input = fopen(filename, "r");
    if (input == NULL) {
        printf("Error: invalid file\n");
        return 1;
    } else {
        while(1){
        char c = fgetc(input);
        if (feof(input)){
            break;
        } else {

            printf("%c", c);
    }
        }
    }

        
    return 0;
}