#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRIES 6

struct WordWithHint{
    char word[MAX_WORD_LENGTH];
    char hint[MAX_WORD_LENGTH];
};

void displayWord(const char word[], const bool guessed[]);
void drawHangman(int tries);

int main(void)
{
    srand(time(NULL));
    struct WordWithHint wordList[] = {
        {"osmic", "My codename"},
        {"gokul", "My realname"},
        {"developer", "What i want to be?"},
        {"trader", "How i will make money"}
    };
    int wordIndex = rand() % 4;

    const char* secretWord = wordList[wordIndex].word;
    const char* hint = wordList[wordIndex].hint;
    
    int wordLength = strlen(secretWord);
    char guessedWord[MAX_WORD_LENGTH] = {0};
    bool guessedLetter[26] = {false}; 

    printf("Welcome to Hangman!!!\n");
    printf("Hint: %s\n", hint);

    int tries = 0;

    while (tries < MAX_TRIES)
    {
            printf("\n");
    		    displayWord(guessedWord, guessedLetter);
    		    drawHangman(tries);

            char guess;
            printf("Enter the Letter: ");
            scanf(" %c", &guess);
            guess = tolower(guess);

            if (guessedLetter[guess - 'a'])
            {
                printf("You Already Guessed that letter\n");
                printf("Try again\n");
                continue;
            }

            guessedLetter[guess - 'a'] = true;

            bool found = false;
            for (int i = 0; i<wordLength;i++){
                if (secretWord[i]== guess){
                    found = true;
                    guessedWord[i] = guess;
                }
            }
            if (found)
            {
                printf("Good Guess\n");
            }
            else
            {
                printf("Sorry, the letter '%c' is not in the word\n", guess);
                tries++;
            }
            if (strcmp(secretWord,guessedWord) == 0)
            {
                printf("\n Congratulation you have guessed the word :  '%s'", secretWord);
                break;
            }
    }
    if (tries >= MAX_TRIES){
      printf("Sorry you are not of tries Secret word has : %s", secretWord);
    }   
}

void displayWord(const char word[], const bool guessed[])
{
    printf("Word: ");
    for (int i = 0; word[i] != '\0';i++)
    {
        if (guessed[word[i] - 'a'])
        {
            printf("%c ",word[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

void drawHangman(int tries)
{
    const char* hangmanParts[]
    = { "	 _________", " |		 |",
			" |		 O", " |	 /|\\",
			" |	 / \\", " |" }; 

    printf("\n");
    for (int i = 0; i <= tries;i++)
    {
        	printf("%s\n", hangmanParts[i]);
    }
}
