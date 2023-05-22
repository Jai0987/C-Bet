// Name: Jainam Kashyap
// Description: This piece of code written in C simulates a simple Casino game of bets in Command Line.
// This code is written for a project to practise C programming
// It takes help from the following youtube video:
// https://youtu.be/PDIyEZfC1wE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rules();
void round1();

int main() {
    rules();
    printf("\n\n");
    round1();
    return 0;
}

void round1() {
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    int deposit1;
    printf("Enter the amount to be deposited for the game: $");
    scanf("%d", &deposit1);

    printf("\n\n");

    printf("Your current balance is $%d\n\n", deposit1);

    int decision = 1; 

    while (decision == 1) { 

        int bet1;
        printf("%s, Enter the money to bet: $", name);
        scanf("%d", &bet1);

        printf("\n\n");

        if (bet1 > deposit1) {
            printf("Bet is greater than the deposit amount, please enter a valid bet.\n");
            printf("Enter Again: $");
            scanf("%d", &bet1);
        }

        printf("\n\n");

        int computer1 = rand() % 10 + 1;
        int guess1;

        printf("Guess a number from 1 to 10: ");
        scanf("%d", &guess1);

        printf("\n\n");

        if (guess1 > 10) {
            printf("Number exceeded the range of values to be guessed.\n");
            printf("Please enter a valid guess between 1 and 10.\n");
            printf("Enter again: $");
            scanf("%d", &guess1);
        }

        printf("\n\n");

        if (guess1 == computer1) {
            printf("You have won $%d\n\n", bet1);

            int bet2 = bet1 * 10;
            int newWon;
        
            if (bet1 == deposit1) {
                newWon = bet2;
            } else {
                newWon = bet2 + deposit1;
            }

            printf("You have won $%d in total\n\n", newWon);

            deposit1 = newWon; 
        } else {
            printf("You have lost $%d\n\n", bet1);

            printf("The correct number is %d\n\n", computer1);

            int newLost = deposit1 - bet1;

            printf("Now you have $%d as balance\n\n", newLost);

            if (newLost == 0) {
                printf("Sorry, you have a $0 balance.\n");
                printf("You have no more money to play.\n");
                printf("Have a nice day.\n");
                break; 
            } else {
                deposit1 = newLost; 

                printf("Press 1 to play again.\n");
                printf("Press 2 to exit.\n");
                printf("Do you want to continue?: ");
                scanf("%d", &decision);
                printf("\n\n");
            }
        }
    }

    if (decision == 2) {
        printf("Thank you for playing!\n");
        printf("Your final balance is $%d\n", deposit1);
        printf("Have a nice day.\n");
    }
}

void rules() {
    printf("=== CASINO GAME RULES ===\n");
    printf("1. Each player starts with a specified deposit amount.\n");
    printf("2. Players can place bets on guessing a number from 1 to 10.\n");
    printf("3. If the guessed number matches the randomly generated number,\n");
    printf("   the player wins and their bet is multiplied by 10.\n");
    printf("4. If the guessed number doesn't match, the player loses their bet.\n");
    printf("5. The player can choose to continue playing or exit the game.\n");
    printf("6. The player's balance is updated accordingly after each round.\n");
    printf("7. If the player's balance reaches zero, they are unable to continue playing.\n");
    printf("8. The game continues until the player decides to exit.\n");
    printf("==========================\n");
}
