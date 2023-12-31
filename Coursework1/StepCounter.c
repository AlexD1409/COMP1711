#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "FitnessDataStruct.h"

//Defining variabales
int buffer = 100;
FITNESS_DATA data[1000];
char line_buffer[100];
char filename[100];
int counter;
char choice;

//Helper function
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

    printf("Menu options:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n");
      
    while (1) {

        printf("Enter choice: ");
        choice = getchar();
        while (getchar() != '\n');
        
        switch (choice){
            
            case 'A':
            case 'a':

                printf("Input filename: ");
                scanf("%s", filename);
                FILE *input = fopen(filename, "r");
                if (!input){
                    printf("Error: Could not find or open the file.\n");
                    return 1;
                }

                counter = 0;

                while (fgets(line_buffer, buffer, input))
                {
                    tokeniseRecord(line_buffer, ",", data[counter].date, data[counter].time, data[counter].steps);
                    counter++;
                }

                while (getchar() != '\n');
                printf("Menu options:\n");
                printf("A: Specify the filename to be imported\n");
                printf("B: Display the total number of records in the file\n");
                printf("C: Find the date and time of the timeslot with the fewest steps\n");
                printf("D: Find the date and time of the timeslot with the largest number of steps\n");
                printf("E: Find the mean step count of all the records in the file\n");
                printf("F: Find the longest continuous period where the step count is above 500 steps\n");
                break;

            case 'B':
            case 'b':

                printf("Total records: %d\n", counter);  
                printf("Menu options:\n");
                printf("A: Specify the filename to be imported\n");
                printf("B: Display the total number of records in the file\n");
                printf("C: Find the date and time of the timeslot with the fewest steps\n");
                printf("D: Find the date and time of the timeslot with the largest number of steps\n");
                printf("E: Find the mean step count of all the records in the file\n");
                printf("F: Find the longest continuous period where the step count is above 500 steps\n");              
                break;

            case 'C':
            case 'c':
                ;
                int min = atoi(data[0].steps);
                int fewest;

                for(int i = 0; i < counter; i++){
                    if(atoi(data[i].steps) < min){
                        min = atoi(data[i].steps);
                        fewest = i;
                    }
                }

                printf("Fewest steps: %s %s\n", data[fewest].date, data[fewest].time);
                printf("Menu options:\n");
                printf("A: Specify the filename to be imported\n");
                printf("B: Display the total number of records in the file\n");
                printf("C: Find the date and time of the timeslot with the fewest steps\n");
                printf("D: Find the date and time of the timeslot with the largest number of steps\n");
                printf("E: Find the mean step count of all the records in the file\n");
                printf("F: Find the longest continuous period where the step count is above 500 steps\n"); 
                break;
                                
            case 'D':
            case 'd':
                ;
                int max = atoi(data[0].steps);
                int largest;
                
                for (int i = 0; i < counter; i++) {
                    if (atoi(data[i].steps) > max){
                        max = atoi(data[i].steps);
                        largest = i;
                    }
                }

                printf("Largest steps: %s %s\n", data[largest].date, data[largest].time);    
                printf("Menu options:\n");
                printf("A: Specify the filename to be imported\n");
                printf("B: Display the total number of records in the file\n");
                printf("C: Find the date and time of the timeslot with the fewest steps\n");
                printf("D: Find the date and time of the timeslot with the largest number of steps\n");
                printf("E: Find the mean step count of all the records in the file\n");
                printf("F: Find the longest continuous period where the step count is above 500 steps\n");            
                break;

            case 'E':
            case 'e':
                ;
                int roundedmean;
                float mean;
                float total = 0;

                for (int i = 0; i < counter; i++) {
                    total += atoi(data[i].steps);                     
                }

                mean = total/counter;
                roundedmean = round(mean);
                printf("Mean step count: %d\n", roundedmean);  
                printf("Menu options:\n");
                printf("A: Specify the filename to be imported\n");
                printf("B: Display the total number of records in the file\n");
                printf("C: Find the date and time of the timeslot with the fewest steps\n");
                printf("D: Find the date and time of the timeslot with the largest number of steps\n");
                printf("E: Find the mean step count of all the records in the file\n");
                printf("F: Find the longest continuous period where the step count is above 500 steps\n");           
                break;

            case 'F':
            case 'f':
                ;
                int start = 0;
                int end = 0;    
                int longest = 0;
                int gap = 0;

                for (int i = 0; i < counter; i++) {
                    if (atoi(data[i].steps) > 500) {
                        gap++;

                    }   else {                                                    
                            if (gap > longest) {
                                longest = gap - 1;
                                end = i - 1;
                            }
                            gap = 0;
                        }

                }                

                start = end - longest;
                printf("Longest period start: %s %s\nLongest period end: %s %s\n", data[start].date, data[start].time, data[end].date, data[end].time);
                printf("Menu options:\n");
                printf("A: Specify the filename to be imported\n");
                printf("B: Display the total number of records in the file\n");
                printf("C: Find the date and time of the timeslot with the fewest steps\n");
                printf("D: Find the date and time of the timeslot with the largest number of steps\n");
                printf("E: Find the mean step count of all the records in the file\n");
                printf("F: Find the longest continuous period where the step count is above 500 steps\n");
                break;                                
        
            case 'Q':
            case 'q':
                return 0;
                break;

            default: 
                printf("Invalid choice entered, try again\n");
                printf("Menu options:\n");
                printf("A: Specify the filename to be imported\n");
                printf("B: Display the total number of records in the file\n");
                printf("C: Find the date and time of the timeslot with the fewest steps\n");
                printf("D: Find the date and time of the timeslot with the largest number of steps\n");
                printf("E: Find the mean step count of all the records in the file\n");
                printf("F: Find the longest continuous period where the step count is above 500 steps\n");
                break;

        }

    }        
        
    return 0;

}