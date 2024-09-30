#include <stdio.h>

#define BOARD_SIZE_ROW 19
#define BOARD_SIZE_COL 17

//player details
typedef struct{
    int pos_x, pos_y;
    char displayed_as;
} character;

//node(points in map) details
typedef struct{
    int pos_x, pos_y;
    int walkable;
    int goal;
    char displayed_as;
} node;

character player;
node board[BOARD_SIZE_ROW][BOARD_SIZE_COL];

//Map related functions
void createBoard();
void displayedMap();
void updateMap();

//player related functions
void move(char direction);

int main(){
    createBoard();
    updateMap();
    move('s');
    move('s');
    move('s');
    move('s');
    move('s');
    move('a');
    move('a');
    move('s');
    move('s');
    move('a');
    move('a');
    move('a');
    move('a');
    move('s');
    move('s');
    move('s');
    move('s');
    move('s');
    move('s');
    move('s');
    move('s');
    move('d');
    move('d');
    move('w');
    move('w');
    move('w');
    move('d');
    move('d');
    move('s');
    move('s');
    move('s');
    move('d');
    move('d');
    move('d');
    move('d');
    move('s');
    move('s');
    displayedMap();
    
    return 0;
}

void createBoard(){
    for (int i = 0; i < BOARD_SIZE_ROW; i++){
        for (int j = 0; j < BOARD_SIZE_COL; j++){
            /*
                I am using struct as C does not have class and struct does not allow pre-setted values
                as such this function specifically this part sets them to their position and to 0 and as walls
            */
            board[i][j].pos_x = j;
            board[i][j].pos_y = i;
            board[i][j].walkable = 0;
            board[i][j].displayed_as = 'w';
            board[i][j].goal = 0;
        }
    }
}

void displayedMap(){
    //Iterate or basically go through every single item in the map and print or display them
    for (int i = 0; i < BOARD_SIZE_ROW; i++){
        for (int j = 0; j < BOARD_SIZE_COL; j++){
            if (player.pos_y == i && player.pos_x == j){
                printf("  %c  ", player.displayed_as);
            }
            else {
                printf("  %c  ", board[i][j].displayed_as);
            }
            
            //This is for the end of the column so it goes to the next row
            if (j == BOARD_SIZE_COL - 1){
                printf("\n");
            }
        }
    }

    //Congratulating you if you actually find and reached the goal
    if (board[player.pos_y][player.pos_x].goal == 1){
        printf(">>>>>>>CONGRATULATIONS YOU COMPLETED MY VERY TERIBLE CREATION OF A MAZE<<<<<<<");
    }

}

void updateMap(){
    //Absolute brute force its 10:20pm don't blame me
    /*
        Each element is a set of 4 values which are in this order {row, column, True or False(i just set the neccessary path as True as
        by default they are False), what they are seen as (s = start, f = floor, g = goal)}
     */
    int map[129][4] = {{1, 7, 1, 's'}, {2, 1, 1, 'f'}, {2, 2, 1, 'f'}, {2, 3, 1, 'f'}, {2, 4, 1, 'f'}, {2, 5, 1, 'f'}, {2, 6, 1, 'f'}, 
    {2, 7, 1, 'f'}, {2, 8, 1, 'f'}, {2, 9, 1, 'f'}, {2, 10, 1, 'f'}, {2, 11, 1, 'f'}, {2, 12, 1, 'f'}, {2, 13, 1, 'f'}, {2, 15, 1, 'f'}, 
    {3, 1, 1, 'f'}, {3, 3, 1, 'f'}, {3, 7, 1, 'f'}, {3, 11, 1, 'f'}, {3, 13, 1, 'f'}, {3, 15, 1, 'f'}, {4, 1, 1, 'f'}, {4, 3, 1, 'f'}, 
    {4, 4, 1, 'f'}, {4, 5, 1, 'f'}, {4, 7, 1, 'f'}, {4, 9, 1, 'f'}, {4, 10, 1, 'f'}, {4, 11, 1, 'f'}, {4, 13, 1, 'f'}, {4, 14, 1, 'f'}, 
    {4, 15, 1, 'f'}, {5, 1, 1, 'f'}, {5, 7, 1, 'f'}, {5, 9, 1, 'f'}, {6, 1, 1, 'f'}, {6, 2, 1, 'f'}, {6, 3, 1, 'f'}, {6, 5, 1, 'f'}, {6, 6, 1, 'f'}, 
    {6, 7, 1, 'f'}, {6, 9, 1, 'f'}, {6, 11, 1, 'f'}, {6, 12, 1, 'f'}, {6, 13, 1, 'f'}, {6, 14, 1, 'f'}, {6, 15, 1, 'f'}, {7, 5, 1, 'f'}, 
    {7, 9, 1, 'f'}, {7, 11, 1, 'f'}, {7, 15, 1, 'f'}, {8, 1, 1, 'f'}, {8, 2, 1, 'f'}, {8, 3, 1, 'f'}, {8, 4, 1, 'f'}, {8, 5, 1, 'f'}, {8, 7, 1, 'f'}, 
    {8, 8, 1, 'f'}, {8, 9, 1, 'f'}, {8, 11, 1, 'f'}, {8, 12, 1, 'f'}, {8, 13, 1, 'f'}, {8, 15, 1, 'f'}, {9, 1, 1, 'f'}, {9, 5, 1, 'f'}, {9, 9, 1, 'f'}, 
    {9, 13, 1, 'f'}, {9, 15, 1, 'f'}, {10, 1, 1, 'f'}, {10, 3, 1, 'f'}, {10, 5, 1, 'f'}, {10, 6, 1, 'f'}, {10, 7, 1, 'f'}, {10, 9, 1, 'f'}, 
    {10, 10, 1, 'f'}, {10, 11, 1, 'f'}, {10, 13, 1, 'f'}, {10, 15, 1, 'f'}, {11, 1, 1, 'f'}, {11, 3, 1, 'f'}, {11, 7, 1, 'f'}, {11, 11, 1, 'f'}, 
    {11, 13, 1, 'f'}, {12, 1, 1, 'f'}, {12, 3, 1, 'f'}, {12, 4, 1, 'f'}, {12, 5, 1, 'f'}, {12, 6, 1, 'f'}, {12, 7, 1, 'f'}, {12, 9, 1, 'f'}, 
    {12, 10, 1, 'f'}, {12, 11, 1, 'f'}, {12, 13, 1, 'f'}, {12, 14, 1, 'f'}, {12, 15, 1, 'f'}, {13, 1, 1, 'f'}, {13, 11, 1, 'f'}, {13, 15, 1, 'f'}, 
    {14, 1, 1, 'f'}, {14, 3, 1, 'f'}, {14, 4, 1, 'f'}, {14, 5, 1, 'f'}, {14, 7, 1, 'f'}, {14, 8, 1, 'f'}, {14, 9, 1, 'f'}, {14, 10, 1, 'f'}, 
    {14, 11, 1, 'f'}, {14, 12, 1, 'f'}, {14, 13, 1, 'f'}, {14, 15, 1, 'f'}, {15, 1, 1, 'f'}, {15, 3, 1, 'f'}, {15, 5, 1, 'f'}, {15, 13, 1, 'f'}, 
    {15, 15, 1, 'f'}, {16, 1, 1, 'f'}, {16, 2, 1, 'f'}, {16, 3, 1, 'f'}, {16, 5, 1, 'f'}, {16, 6, 1, 'f'}, {16, 7, 1, 'f'}, {16, 8, 1, 'f'}, 
    {16, 9, 1, 'f'}, {16, 11, 1, 'f'}, {16, 12, 1, 'f'}, {16, 13, 1, 'f'}, {16, 14, 1, 'f'}, {16, 15, 1, 'f'}, {17, 9, 1, 'g'}};

    //for each element change the neccessary data of the nodes on the board
    for (int i = 0; i < 129; i++){
        if (map[i][3] == 's'){
            player.pos_y = map[i][0];
            player.pos_x = map[i][1];
            player.displayed_as = 'p';
        }
        if (map[i][3] == 'g'){
            board[map[i][0]][map[i][1]].goal = 1;
        }
        board[map[i][0]][map[i][1]].walkable = map[i][2];
        board[map[i][0]][map[i][1]].displayed_as = map[i][3];
    }
}

void move(char direction){
    //Basic direction movement using case to determine direction
    switch (direction){
        case 'w':
            if (board[player.pos_y - 1][player.pos_x].walkable == 1){
                player.pos_y -= 1;
            }
            break;
        case 's':
            if (board[player.pos_y + 1][player.pos_x].walkable == 1){
                player.pos_y += 1;
            }
            break;
        case 'd':
            if (board[player.pos_y][player.pos_x + 1].walkable == 1){
                player.pos_x += 1;
            }
            break;
        case 'a':
            if (board[player.pos_y][player.pos_x - 1].walkable == 1){
                player.pos_x -= 1;
            }
            break;
        default:
            printf(">>>>>>>IF YOU SEE THIS IT MEANS SOMETHING BROKE SO DON'T ASK ME<<<<<<<");
            break;
    }
}