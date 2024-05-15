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

//Finds start position 
int getStart(Position *this, FILE *file, int max_width, int max_height){
    char c;
          
    for(int i = 0; i <= max_width; i++){
        for(int j = 0; j < max_height; j++){
            c = fgetc(file);
            if(c == 'S'){
                this->x = i;
                this->y = j;
            }
            
            }
        }
    
    
    return 1;
}

//Finds end position 
int getEnd(Position *this, FILE *file, int max_width, int max_height){
    char c;
          
    for(int i = 0; i <= max_width; i++){
        for(int j = 0; j < max_height; j++){
            c = fgetc(file);
            if(c == 'E'){
                this->x = i;
                this->y = j;
            }
            
            }
        }
    
    
    return 1;
}

//Completion check
int MazeCheck(Position *player, Maze *this){
    if((this->Map[player->x][player->y] == 'E')){
        printf("Complete!\n");
    } else if(this->Map[player->x][player->y] != ' '){
        printf("You've hit a wall!\n");
    }

    return 0;
}

//Prints maze
void PrintMaze(Maze *this, Position *player, int width, int height){
    printf("\n");
    for(int i = 0; i <= width; i++){
        for (int j = 0; j < height; j++){
            if(player->x == i && player->y == j){
                printf("X");
            } else {
            printf("%c", this->Map[i][j]);          
        }    
    }
    
}
printf("\n");
}

int main(){
    
    char filename[100];
    char choice;
    Maze Main; 
    Maze* Ptr = &Main;
    Position Start;
    Position* Strt = &Start;
    Position End;
    Position* Finish = &End;
    Position Player;
    Position* Plyr = &Player;
    printf("Enter Filename: ");
    scanf("%s", filename);
    FILE *input = fopen(filename, "r");
    int width =  getWidth(input);
    int height = getHeight(input);
    rewind(input);
    LoadMaze(Ptr, input, width, height);
    rewind(input);
    getStart(Strt, input, width, height);
    Player.x = Start.x;
    Player.y = Start.y;
    printf("%d %d\n", Player.x, Player.y);
    rewind(input);
    getEnd(Finish, input, width, height);
    printf("%d, %d\n", End.x, End.y);
    
    
    while(1){
        choice = getchar();
        switch (choice){
            case 'W':
            case 'w':
                Player.x--;
                MazeCheck(Plyr, Ptr);
                
                break;

            case 'A':
            case 'a':
                Player.y--;
                MazeCheck(Plyr, Ptr);
                
                break;

            case 'S':
            case 's':
                Player.x++;
                MazeCheck(Plyr, Ptr);
                
                break;

            case 'D':
            case 'd':
                Player.y++;
                MazeCheck(Plyr, Ptr);
                
                break;

            case 'M':
            case 'm':
                rewind(input);
                PrintMaze(Ptr, Plyr, width, height);
                break;
        }
    }
    
    return 0;
}
