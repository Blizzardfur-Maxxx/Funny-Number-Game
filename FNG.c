#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int number, guess, points;
int range = 10;

FILE *fptr;


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
    number = rand() % range + 1;
}

int main() {
    fptr = fopen("score", "r");
    int points = getw(fptr);
    fclose(fptr);
    fptr = fopen("score", "w");
    points += 1;
    logo();
    printf("Welcome to the funny number guess game! \n");
    printf("your last score was: %d\n", points);
    printf("and for playing heres a free point!\n");
    if (points >= 5000)
    {
        printf("      _                _            _              \n");
        printf("     | |              | |          | |      _____  \n");
        printf("  ___| |__   ___  __ _| |_ ___ _ __| |     /     \\ \n");
        printf(" / __| '_ \\ / _ \\/ _` | __/ _ \\ '__| |    | () () |\n");
        printf("| (__| | | |  __/ (_| | ||  __/ |  |_|     \\  ^  / \n");
        printf(" \\___|_| |_|\\___|\\__,_|\\__\\___|_|  (_)      |||||  \n");
        printf("dam you actually decided to cheat in this game of all games\n");
        printf("well just play it how you like i wont stop ya but its gona get 5x harder now\n");
        range = range * 5;
    }
    else
    {
        printf("no cheats detected\n");
    }    
    randnum();
    while(1)
    {
        if (number <= 5)
        {
            printf("hint: number is 5 or below! \n");
            printf("Guess a number here! : ");

        }
        else
        {
            printf("hint: number is 5 or above 5! \n");
            printf("Guess a number here! : ");
        }
        scanf("%d", &guess);
        if (guess == number)
        {
            points += 1;
            printf("YOU WIN AND GET A POINT :3\n");
            printf("your current points are : %d\n", points);
            printf("Do you want to play again? Enter y for YES, or any other key to exit: \n");
            char play_again;
            scanf(" %c", &play_again);
            if (play_again == 'y' || play_again == 'Y')
            {
                randnum();
            }
            else
            {
                printf("your final  points are : %d\n", points);
                putw(points, fptr);
                fclose(fptr);
                break;
            }
        }
        else
        {
            printf("YOU LOST :(  your points are : %d\n", points);
            printf("and the number was : %d\n", number);
            printf("Do you want to play again? Enter y for YES, or any other key to exit: \n");
            char play_again;
            scanf(" %c", &play_again);
            if (play_again == 'y' || play_again == 'Y')
            {
                randnum();
            }
            else
            {
                printf("your final  points are : %d\n", points);
                putw(points, fptr);
                fclose(fptr);
                break;
            }
        }
    }
    return 0;
}