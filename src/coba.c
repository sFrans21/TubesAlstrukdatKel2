#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "coba.h"

void clearScreen() {
    system("clear || cls");
}

// void delay(unsigned int mseconds) {
//     clock_t goal = mseconds + clock();
//     while (goal > clock());
// }

// void animateASCII() {
//     int i;
//     for (i = 0; i < 5; i++) { // Loop a few times for the blinking effect
//         printf("\033[2J\033[1;1H"); // ANSI escape code to clear screen and move cursor to (1,1)
//         printf("  _       _                                     _       _                      \n");
//         printf(" ( )  _  ( )                                   ( )  _  ( )                     \n");
//         printf(" | | ( ) | |   _ _  _   _    _ _   ___     __  | | ( ) | |   _ _  _   _    __  \n");
//         printf(" | | | | | | /'_` )( ) ( ) /'_` )/' _ `\\ /'_ `\\| | | | | | /'_` )( ) ( ) /'__`\\\n");
//         printf(" | (_/ \\_) |( (_| || (_) |( (_| || ( ) |( (_) || (_/ \\_) |( (_| || \\_/ |(  ___/\n");
//         printf(" `\\___x___/'`\\__,_)`\\__, |`\\__,_)(_) (_)`\\__  |`\\___x___/'`\\__,_)`\\___/'`\\____)\n");
//         printf("                    ( )_| |              ( )_) |                                \n");
//         printf("                    `\\___/'               `\\___/'                                \n");

//         delay(400); // Delay for 500 milliseconds
//         // printf("\033[2J\033[1;1H"); // Clear screen again
//         // delay(200); // Delay again
//     }
// }

void displayLoadingBar(int progress) {
    printf("\033[1;33m"); // Set text color to yellow
    printf("Loading: [");
    for (int i = 0; i < 20; ++i) {
        if (i < progress / 5) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%\n", progress);
    printf("\n\033[0m\n"); // Reset text color
}

void displayStartBar(int progress) {
    printf("\033[1;33m"); // Set text color to yellow
    printf("WayangWave is starting: [");
    for (int i = 0; i < 20; ++i) {
        if (i < progress / 5) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%\n", progress);
    printf("\n\033[0m\n"); // Reset text color
}
void animateSpinner(int duration) {
    const char spinner[] = { '|', '/', '-', '\\' };
    int i = 0;
    time_t start_time = time(NULL);
    int progress = 0;

    // displayHeader();

    while ((time(NULL) - start_time) < duration) {
        clearScreen();
        // displayHeader();
        displayLoadingBar(progress);
        printf("\033[1;33m"); // Set text color to yellow
        printf("Loading... %c\n", spinner[i]);
        printf("\033[0m\n"); // Reset text color

        // Update loading progress
        progress = (int)(((time(NULL) - start_time) / (double)duration) * 125);

        // Delay for animation effect
        for (int j = 0; j < 70000000; j++) {
            // Intentional delay to simulate animation
        }

        i = (i + 1) % 4; // Cycle through spinner characters
    }
    {
        clearScreen();
    }
}

void animateSpinnerStart(int duration) {
    const char spinner[] = { '|', '/', '-', '\\' };
    int i = 0;
    time_t start_time = time(NULL);
    int progress = 0;

    // displayHeader();

    while ((time(NULL) - start_time) < duration) {
        clearScreen();
        // displayHeader();
        displayStartBar(progress);
        printf("\033[1;33m"); // Set text color to yellow
        printf("Loading... %c\n", spinner[i]);
        printf("\033[0m\n"); // Reset text color

        // Update loading progress
        progress = (int)(((time(NULL) - start_time) / (double)duration) * 125);

        // Delay for animation effect
        for (int j = 0; j < 70000000; j++) {
            // Intentional delay to simulate animation
        }

        i = (i + 1) % 4; // Cycle through spinner characters
    }
    {
        clearScreen();
    }
}

// int main() {
//     int duration = 5; // Duration of the animation in seconds
//     animateSpinner(duration);

//     return 0;
// }
