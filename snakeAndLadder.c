#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int rollDie() {return rand() % 6 + 1; }
int printBoard(int row, int column);
int Start_data();


#define MAX_NAME_LENGHT 20
#define FINAL_POS_VALUE 100
#define INITIAL_POSITION 1
int noOfPlayers;

struct PlayerData
{
    char name[20];
    int position;
};
struct PlayerData *Players = NULL;

int main(void)
{
    char ch;
    int position;
    int row = 10;
    int column = 10;
    int end = false;


    srand(time(NULL));

    if (Start_data() != 0){
        return 1; // exit the porgram
    }
    while(!end){
        for (int i = 0; i < noOfPlayers; i++){
            printf("%s Press Enter to roll Dice... ", Players[i].name);
            if (getchar() == '\n'){
                position = rollDie();
                printf("\n %s : Dice:  %d\n", Players[i].name, position);
                Players[i].position = Players[i].position + position;
                printBoard(row, column);

                if (Players[i].position >= FINAL_POS_VALUE){ // Check for the winner
                    printf("Winner is : %s", Players[i].name);
                    end = true;
                    break;
                }
            }
        }
    }

    free(Players); // Free the allocated memory
    return 0;
}



int Start_data()
{
    printf("How many players wants to play: ");
    scanf(" %d", &noOfPlayers);
    printf("\n No of players: %d\n", noOfPlayers);
    // Allocate the memory for no. of players elements of type struct PlayerData
    Players = (struct PlayerData *)malloc(noOfPlayers * sizeof(struct PlayerData));
    //  Checking if the memory allocated 
    if (Players == NULL){
        fprintf(stderr, "Memory Allocation Failed\n");
        return 1; // Faliure
    }
    
    for (int i = 0; i<noOfPlayers; i++){
        printf("Enter the name of the Player %d :  ", i+1);
        scanf("%s",Players[i].name);
        Players[i].position = INITIAL_POSITION;
    }
    return 0;

}


int printBoard(int row, int column){
    int num = row * column;
    int board[row][column];
    // Adding number in the board
    for (int i = 0; i<row; i++){
        for (int j=0; j<column; j++){
            board[i][j] = num;
            num--;
        }  
    }

    // Print the board in the alternative row direction
    for (int i=0; i<row; i++){
        if (i % 2 == 0){
            // Left to Right
            for (int j = 0; j < column; j++){
                 bool playerPrinted = false;
                for (int c = 0; c < noOfPlayers; c++){
                    if (board[i][j] == Players[c].position){
                        printf("P%d ", c + 1);
                        playerPrinted = true;
                        break;
                    }
                }
                if (!playerPrinted) {
                    printf("%-4d", board[i][j]);
                }
            }
        }
        else {
            // Right to left
            for (int j = column - 1; j >= 0; j--) {
                bool playerPrinted = false;
                for (int c = 0; c < noOfPlayers; c++){
                    if (board[i][j] == Players[c].position){
                        printf("P%d ", c + 1);
                        playerPrinted = true;
                        break; // move to the cell after printing the player
                    }
                }
                if (!playerPrinted) {
                    printf("%-4d", board[i][j]);
                }
            } 
        }
        printf("\n"); 
    }
}

