#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getWidth(FILE *file){
    
    char c;
    int width = 0;
    int max_width = 0;
    while(fgetc(file) != '\n'){
        width++;
        if(width >= max_width){
            max_width = width;
        } 
    
    }
    return max_width;
}

int main(){
    
    char filename[100];
    printf("Enter Filename: ");
    scanf("%s", filename);
    FILE *input = fopen(filename, "r");
    int width =  getWidth(input);
    printf("%d\n", width);
       
    return 0;
}