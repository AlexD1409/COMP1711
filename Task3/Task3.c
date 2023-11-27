#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char date[11];
	char time[6];
	char steps[5000];
} FITNESS_DATA;

typedef struct {
	char date[11];
	char time[6];
	int steps;
} SORTED;

int counter = 0;

// Function to tokenize a record
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        
        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);
}

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int steps[], int records){
    int i, j, minimum;

    for (i=1; i<records; i++){
        minimum = steps[i];
        j = i - 1;
            while (j >= 0 && steps[j] > minimum){
                steps[j+1] = steps[j];
                j=j-1;
            }
            steps[j+1] = minimum;
    }
}

int main(){

    FITNESS_DATA data[100];
    SORTED sortdata[100];
    char filename[100];
    char linebuffer[100];
    int sortedsteps[100];
    int buffer = 100;
    int totalrecords = 0;
        
    printf("Enter Filename: ");
    scanf("%s", filename);
    FILE *input = fopen(filename, "r");
    if (!input) {
        printf("Error: invalid file\n");
        return 1;
    }

    while (fgets(linebuffer, buffer, input)){
        tokeniseRecord(linebuffer, "," , data[counter].date, data[counter].time, data[counter].steps);
        sortdata[counter].steps = atoi(data[counter].steps);
        strcpy(sortdata[counter].date, data[counter].date);
        strcpy(sortdata[counter].time, data[counter].time);
        counter++;
        totalrecords++;
    }

    sort(&sortdata->steps, totalrecords);   

    FILE *output;    

    return 0;
    
}