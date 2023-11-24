#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
    system("clear || cls");
}

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