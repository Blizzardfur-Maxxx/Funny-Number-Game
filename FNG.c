#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int number, guess, points;
void logo() {
    printf("  _______ _             __                         \n");
    printf(" |__   __| |           / _|                        \n");
    printf("    | |  | |__   ___  | |_ _   _ _ __  _ __  _   _ \n");
    printf("    | |  | '_ \\ / _ \\ |  _| | | | '_ \\| '_ \\| | | |\n");
    printf("    | |  | | | |  __/ | | | |_| | | | | | | | |_| |\n");
    printf("    |_|  |_| |_|\\___| |_|  \\__,_|_| |_|_| |_|\\__, |\n");
    printf("                       | |                    __/ |\n");
    printf("  _ __  _   _ _ __ ___ | |__   ___ _ __      |___/ \n");
    printf(" | '_ \\| | | | '_ ` _ \\| '_ \\ / _ \\ '__|           \n");
    printf(" | | | | |_| | | | | | | |_) |  __/ |              \n");
    printf(" |_|_|_|\\__,_|_| |_| |_|_.__/ \\___|_|      ____    \n");
    printf("  / ____|                                _|___ \\   \n");
    printf(" | |  __  __ _ _ __ ___   ___           (_) __) |  \n");
    printf(" | | |_ |/ _` | '_ ` _ \\ / _ \\             |__ <   \n");
    printf(" | |__| | (_| | | | | | |  __/           _ ___) |  \n");
    printf("  \\_____|\\__,_|_| |_| |_|\\___|          (_)____/   \n");
                                                   
}                                                  

void randnum() {
    srand(time(NULL));
    number = rand() % 10 + 1;
}

int main() {
    randnum();
    logo();
    printf("Welcome to the funny number guess game! \n");
    while(1)
    {
        printf("Guess a number here! : \n");
        if (number <= 5)
        {
            printf("hint: number is 5 or bellow! \n");
        }
        else
        {
            printf("hint: number is 5 or above 5! \n");
        }
        scanf("%d", &guess);
        if (guess == number)
        {
            points += 1;
            printf("YOU WIN AND GET A POINT :3\n");
            printf("Your current points: %d\n", points);
            printf("your current points are : %d\n", points);
            printf("Do you want to play again? Enter y for YES, or any other key to exit: ");
            char play_again;
            scanf(" %c", &play_again);
            if (play_again == 'y' || play_again == 'Y')
            {
                randnum();
            }
            else
            {
                break;
            }
        }
        else
        {
            printf("YOU LOST :(  your points are : %d\n", points);
            printf("and the number was : %d\n", number);
            printf("Do you want to play again? Enter y for YES, or any other key to exit: ");
            char play_again;
            scanf(" %c", &play_again);
            if (play_again == 'y' || play_again == 'Y')
            {
                randnum();
            }
            else
            {
                printf("your final  points are : %d\n", points);
                break;
            }
        }
    }
    return 0;
}