#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

#define USERNAME_BUFFER 50
#define PASSWORD_BUFFER 50
#define NAME_BUFFER 50
#define PHONE_BUFFER 15

// Function declarations
int MainMenu();
void gotoxy(int x, int y);
void createAc();
void writePersonToFile(FILE *fp);
void writePassToFile(FILE *fp);

// General Details of the person
struct PersonDetails {
    char username[USERNAME_BUFFER];
    char firstName[NAME_BUFFER];
    char lastName[NAME_BUFFER];
    char fatherName[NAME_BUFFER];
    char motherName[NAME_BUFFER];
    char phoneNumber[PHONE_BUFFER]; 
    int day, month, year;
    unsigned long amount; 
};
struct PersonDetails Person;

// Used to transfer money and 
struct TransMoney {
    char toUsername[USERNAME_BUFFER];
    char amount[20]; // Changed to char array to handle numbers as strings
};

// Used for login and others
struct Password {
    char username[USERNAME_BUFFER];
    char password[PASSWORD_BUFFER];
};
struct Password passData;

int main(void) {
    MainMenu();
    return 0;
}

int MainMenu() {
    int choice;
    gotoxy(20, 3);

    // Creating a Main menu for the user
    system("cls");
    printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
    gotoxy(18, 5);
    printf("**********************************");
    gotoxy(25, 7);
    printf("DEVELOPER-OSMIC");
    gotoxy(20, 10);
    printf("1.... CREATE A BANK ACCOUNT");
    gotoxy(20, 12);
    printf("2.... ALREADY A USER? SIGN IN");
    gotoxy(20, 14);
    printf("3.... EXIT\n\n");
    printf("\n\nENTER YOUR CHOICE..");

    scanf("%d", &choice);

    switch (choice) {
    case 1:
        system("cls");
        printf("\n\n USERNAME 50 CHARACTERS MAX!!");
        printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
        createAc();
        break;
    case 2:
        printf("login();"); // Placeholder for login function
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Invalid choice. Please enter a number between 1 and 3.\n");
        break;
    }
    return 0;
}

void createAc() {
    int ch;
    int i = 0;
    FILE *fpointer;
    system("cls");
    printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

    printf("\n\nFIRST NAME..");
    scanf("%s", Person.firstName);
    printf("\n\nLAST NAME..");
    scanf("%s", Person.lastName);
    printf("\n\nFATHER'S NAME..");
    scanf("%s", Person.fatherName);
    printf("\n\nMOTHER'S NAME..");
    scanf("%s", Person.motherName);
    printf("\n\nDATE OF BIRTH..\nDATE-");
    scanf("%d", &Person.day);
    printf("MONTH-");
    scanf("%d", &Person.month);
    printf("YEAR-");
    scanf("%d", &Person.year);
    printf("\n\nPHONE NUMBER..");
    scanf("%s", Person.phoneNumber); // Assuming phone number is a string
    printf("\n\nUSERNAME.. ");
    scanf("%s", Person.username);
    strcpy(passData.username, Person.username);

    printf("\n\nPASSWORD..");
    while (i < PASSWORD_BUFFER - 1) {
        ch = getch(); // Take each char entered as input
        if (ch == '\r') { // User pressed Enter key
            break;
        } else if (ch == '\b') { // User pressed backspace key
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else {
            passData.password[i++] = ch;
            printf("*");
        }
    }
    passData.password[i] = '\0';
    printf("\nPassword saved successfully.\n");

    // Writing in the details file
    fpointer = fopen("details.txt", "ab");
    if (fpointer == NULL) {
        perror("Error Opening the File");
        return;
    }
    writePersonToFile(fpointer);
    fclose(fpointer);

    // Write username and password in the username file
    fpointer = fopen("username.txt", "ab");
    if (fpointer == NULL) {
        perror("Error Opening the File");
        return;
    }
    writePassToFile(fpointer);
    fclose(fpointer);
}

void writePersonToFile(FILE *fp) {
    fprintf(fp, "%s,%s,%s,%s,%s,%s,%02d-%02d-%04d,%lu\n",
            Person.username,
            Person.firstName,
            Person.lastName,
            Person.fatherName,
            Person.motherName,
            Person.phoneNumber,
            Person.day, Person.month, Person.year,
            Person.amount);
}

void writePassToFile(FILE *fp) {
    fprintf(fp, "%s,%s\n", passData.username, passData.password);
}

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
