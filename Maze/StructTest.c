#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Limits for maze sizes
#define SizeMax 100
#define SizeMin 5

typedef struct Position{
    int x;
    int y;
}Position, PlayerPos;

typedef struct MazeData{
    int height;
    int width;
    Position start;
    Position end; 
    char **map;
}Maze;

int main(){

    char linebuffer[100];
    char Maze[100][100];
    char temp;
    int x = 0;
    int y = 0;
    int x_max = 0;
    int y_max = 0;
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
            printf("Invalid character in maze\n");
            break;
       } else {
        if(c != '\n'){
            Maze[x][y] = c;
            x = x + 1;
            if(x_max <= x){
                x_max = x;
            }
        } else{
            Maze[x][y] = c;
            y = y + 1;
            x = 0;
            if(y_max <= y){
                x_max = y;
            }else{
        printf("Invalid file entered\n");
        }
       } 
        return 0;
       }
    }
    }

    //Print maze
    int i = 0;
    int n = 0;
    for (i = 0; n < y_max; i++){
        printf("%c", Maze[i][n]);
        n++;
        if(Maze[i][n] == '\n'){
            n = 0;
            i++;
        }
    }

    printf("%c", Maze[0][0]);
        
    return 0;
}