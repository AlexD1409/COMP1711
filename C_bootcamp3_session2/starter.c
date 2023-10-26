#include <stdio.h>
int main() {
    char filename [] = "input.txt";
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) 
    {
        perror("");
        return 1;
    }

    int buffersize = 100;
    char line_buffer[buffersize];
    while (fgets(line_buffer, buffersize, file) !=NULL) //easier to have seperate while loop for reading in from files
    {
        printf("%s", line_buffer);
    }
    fclose(file);
    return 0;
}