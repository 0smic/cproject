#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


#define HEIGHT 20
#define WIDTH 50
#define PACMAN 'C'
#define FOOD '.'
#define WALL '#'
#define EMPTY ' '
#define DEMON 'X'

// global var
int score = 0;
int rest = 0;
int pacman_x, pacman_y;
int board[HEIGHT][WIDTH]; 
int food = 0;
int res = 0;
int curr = 0;

void init(){

    // Putting wall in the border
    for (int i = 0; i< HEIGHT;i++){
        for (int j = 0; j<WIDTH; j++){
            if (i == 0 || j == 0 || j == WIDTH -1 || i == HEIGHT - 1){
                board[i][j] = WALL;
            }else{
                board[i][j] = EMPTY;
            }
        }
    }

    // puttin walls inside  randomely
    int count = 100;
    while (count != 0){
        int i = rand() % (HEIGHT - 1);
        int j = rand() % (WIDTH - 1);
        if (board[i][j] != WALL && board[i][j] != PACMAN){
            board[i][j] = WALL;
            count--;
        }
    }
    
    // order using row
    int val = 5;
    while(val != 0){
        int cols = rand() % (WIDTH + 1);
        for(int i = 1; i< HEIGHT - 3;i++ ){
            if (board[i][cols] != WALL && board[i][cols] != PACMAN){
                board[i][cols] = WALL;
            }
        }
        val--;
    }

    count = 30; 
    while (count != 0) { 
        int i = (rand() % (HEIGHT + 1)); 
        int j = (rand() % (WIDTH + 1)); 
  
        if (board[i][j] != WALL && board[i][j] != PACMAN) { 
            board[i][j] = DEMON; 
            count--; 
        } 
    } 
    pacman_x = WIDTH / 2;
    pacman_y = HEIGHT / 2;
    board[pacman_y][pacman_x] = PACMAN;

 // Points Placed 
    for (int i = 0; i < HEIGHT; i++) { 
        for (int j = 0; j < WIDTH; j++) { 
            if (i % 2 == 0 && j % 2 == 0 
                && board[i][j] != WALL 
                && board[i][j] != DEMON 
                && board[i][j] != PACMAN) { 
  
                board[i][j] = FOOD; 
                food++; 
            } 
        } 
    } 
    printf("\n");   
}

void move(int move_x, int move_y) 
{ 
    int x = pacman_x + move_x; 
    int y = pacman_y + move_y; 
  
    if (board[y][x] != WALL) { 
        if (board[y][x] == FOOD) { 
            score++; 
            food--; 
            curr++; 
            if (food == 0) { 
                res = 2; 
                return; 
            } 
        } 
        else if (board[y][x] == DEMON) { 
            res = 1; 
        } 
  
        board[pacman_y][pacman_x] = EMPTY; 
        pacman_x = x; 
        pacman_y = y; 
        board[pacman_y][pacman_x] = PACMAN; 
    } 
} 


void draw(){
    system("CLS");
    for(int k = 0 ;k< HEIGHT;k++){
        for (int f = 0; f < WIDTH; f++)
        {
            printf("%c ", board[k][f]);
        }
        printf("\n");
        
    }
}

void intro(){
    system("cls");
    printf(" _ __   __ _  ___ _ __ ___   __ _ _ __  \n");
    printf("| '_ \\ / _` |/ __| '_ ` _ \\ / _` | '_ \\ \n");
    printf("| |_) | (_| | (__| | | | | | (_| | | | |\n");
    printf("| .__/ \\__,_|\\___|_| |_| |_|\\__,_|_| |_|\n");
    printf("| |                                    \n");
    printf("|_|                                    \n");

    printf("\t\t Developer Osmic\n\n");
}

int main(void){
    init(); 
    char ch; 
    food -= 35; 
    int totalFood = food; 
    // Instructions to Play 
    intro();
    printf(" Use buttons for w(up), a(left) , d(right) and "
           "s(down)\nAlso, Press q for quit\n"); 
  
    printf("Enter Y to continue: \n"); 
  
    ch = getch(); 
    if (ch != 'Y' && ch != 'y') { 
        printf("Exit Game! "); 
        return 1; 
    } 
  
    while (1) { 
        draw(); 
        printf("Total Food count: %d\n", totalFood); 
        printf("Total Food eaten: %d\n", curr); 
        if (res == 1) { 
            // Clear screen 
            system("cls"); 
            printf("Game Over! Dead by Demon\n Your Score: "
                   "%d\n", 
                   score); 
            return 1; 
        } 
  
        if (res == 2) { 
            // Clear screen 
            system("cls"); 
            printf("You Win! \n Your Score: %d\n", score); 
            return 1; 
        } 
  
        // Taking the Input from the user 
        ch = getch(); 
  
        // Moving According to the 
        // input character 
        switch (ch) { 
        case 'w': 
            move(0, -1); 
            break; 
        case 's': 
            move(0, 1); 
            break; 
        case 'a': 
            move(-1, 0); 
            break; 
        case 'd': 
            move(1, 0); 
            break; 
        case 'q': 
            printf("Game Over! Your Score: %d\n", score); 
            return 0; 
        } 
    } 
    return 0; 
}
