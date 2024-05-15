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
    while(fgetc(file)){
        if(feof(file)){
            break;
        } else if(fgetc(file) == '\n'){
            height++;
            if(height >= max_height){
            max_height = height;
        }
        
        } 
    
    }
    return max_height;
}

//Loads Maze into struct
int LoadMaze(Maze *this, FILE *file){
    char c;
    int x = 0;
    int y = 0;
    this->Map[100][100];
    while (fgetc(file)){
        c = fgetc(file);
        this->Map[x][y] = c;
        x++;
        if(c == '\n'){
            y++;
            x = 0;
        }
    }
}

int main(){
    
    char filename[100];
    Maze Main; 
    Maze* Ptr = &Main;
    char temp;
    printf("Enter Filename: ");
    scanf("%s", filename);
    FILE *input = fopen(filename, "r");
    int width =  getWidth(input);
    int height = getHeight(input);
    LoadMaze(Ptr, input);
    printf("%d %d\n", width, height);
    for(int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            
            printf("%c", Main.Map[i][j]);
        }
    }
       
    return 0;
}