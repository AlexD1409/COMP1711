#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int isdate(char date[]) {
    if (strlen(date) != 10) {
        return 0;
    } 
    if (!isdigit(date[0])) {
        return 0;
    } 
    if (!isdigit(date[1])) {
        return 0;
    } 
    if (!isdigit(date[2])) {
        return 0;
    } 
    if (!isdigit(date[3])) {
        return 0;
    } 
    if (date[4] != '-'){
        return 0;
    }
    if (!isdigit(date[5])) {
        return 0;
    } 
    if (!isdigit(date[6])) {
        return 0;
    } 
    if (date[7] != '-'){
        return 0;
    }
    if (!isdigit(date[8])) {
        return 0;
    } 
    if (!isdigit(date[9])) {
        return 0;
    } 

    return 1;

}

int istime(char time[]) {
    if (strlen(time) != 5) {
        return 0;
    } 
    if (!isdigit(time[0])) {
        return 0;
    } 
    if (!isdigit(time[1])) {
        return 0;
    } 
    if (time[2] != ':'){
        return 0;
    }
    if (!isdigit(time[3])) {
        return 0;
    } 
    if (!isdigit(time[4])) {
        return 0;
    }
    return 1;

}

void sort(SORTED steps[], SORTED date[], SORTED time[], int records){
    int i, j, minimum;
    char tempdate[11];
    char temptime[11];

    for (i=1; i<records; i++){
        minimum = steps[i].steps;
        strcpy(tempdate,steps[i].date);
        strcpy(temptime,steps[i].time);
        j = i - 1;
            while (j >= 0 && steps[j].steps > minimum){
                steps[j+1].steps = steps[j].steps;
                strcpy(steps[j+1].date,steps[j].date);
                strcpy(steps[j+1].time,steps[j].time);
                j=j-1;
            }
            steps[j+1].steps = minimum;
            strcpy(steps[j+1].date,tempdate);
            strcpy(steps[j+1].time,temptime);
    }
}

int main(){

    FITNESS_DATA data[100];
    SORTED sortdata[100];
    char filename[100];
    char *tempname;
    char finalname[100];
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
        int check = atoi(data[counter].steps);
        if((isdate(data[counter].date) && istime(data[counter].time) && atoi(data[counter].steps)) != 1){
            printf("Error: Invalid file\n");
            return 1;
        } else {
        sortdata[counter].steps = atoi(data[counter].steps);
        strcpy(sortdata[counter].date, data[counter].date);
        strcpy(sortdata[counter].time, data[counter].time);
        counter++;
        totalrecords++;
        }
    }

    sort(sortdata, sortdata, sortdata, totalrecords); 

    tempname = strtok(filename, ".csv");
    strcat(tempname, ".csv.tsv");
    strcpy(finalname, tempname);
    
    FILE *output;    

    for (int i = 0; i < counter; i++){
    output = fopen(finalname, "a");
    fprintf(output, "%s\t%s\t%d", sortdata[i].date, sortdata[i].time, sortdata[i].steps);
    }

    printf("Data sorted and written to %s\n", finalname);

    return 0;
    
}