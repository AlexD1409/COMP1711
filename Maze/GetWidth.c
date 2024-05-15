#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Limits for maze sizes
#define SizeMax 100
#define SizeMin 5

typedef struct Position{
    int x;
    int y;
}Position;

typedef struct MazeData{
    int height;
    int width;
    Position start;
    Position end; 
    char Map[100][100];
}Maze;

//Finds Maze Width
int getWidth(FILE *file){
    
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

//Finds Maze Height
int getHeight(FILE *file){
    
    int height = 1;
    int max_height = 0;
    char row[100];
    while(fgets(row, 100, file)){        
            height++;
            if(max_height < height){
                max_height = height;
            }
            
    }    
    return max_height;
}

//Loads Maze into struct
int LoadMaze(Maze *this, FILE *file, int max_width, int max_height){
    char c;
    this->Map[100][100];
    //Copying character 1 by 1 into 2d array Map   
    for(int x = 0; x <= max_width; x++){
        for(int y = 0; y < max_height; y++){
            c = fgetc(file);
            if(c == EOF){
                break;
            }
            this->Map[x][y] = c;
            }
        }
    
    
    return 1;
}

//Prints maze
void PrintMaze(Maze *this, int width, int height){
    for(int i = 0; i <= width; i++){
        for (int j = 0; j < height; j++){
            
            printf("%c", this->Map[i][j]);          
        }    
    }
    printf("\n");
}

int main(){
    
    char filename[100];
    Maze Main; 
    Maze* Ptr = &Main;
    printf("Enter Filename: ");
    scanf("%s", filename);
    FILE *input = fopen(filename, "r");
    int width =  getWidth(input);
    int height = getHeight(input);
    rewind(input);
    LoadMaze(Ptr, input, width, height);
    PrintMaze(Ptr, width, height);
    
    return 0;
}