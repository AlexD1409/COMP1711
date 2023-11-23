#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char date[11];
	char time[6];
	char steps[1000];
} FITNESS_DATA;

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

int main() {
    
    int record0;
    int record1;
    int record2;
    int i = 0; 
    int buffer = 50;

    char line_buffer[buffer];

    FITNESS_DATA data[10000];
    
    FILE *file = fopen("FitnessData_2023.csv", "r");
    
    while (fgets(line_buffer, buffer, file) !=NULL){

        tokeniseRecord(line_buffer, ",", data[i].date, data[i].time, data[i].steps);
        i++;
        
    }

    record0 = atoi(data[0].steps);
    record1 = atoi(data[1].steps);
    record2 = atoi(data[2].steps);
    printf("Number of records in file: %d\n", i);
    printf("%s/%s/%d\n", data[0].date,data[0].time,record0);
    printf("%s/%s/%d\n", data[1].date,data[1].time,record1);
    printf("%s/%s/%d\n", data[2].date,data[2].time,record2);

    return 0;

}