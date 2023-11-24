#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(unsigned int mseconds) {
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void animateASCII() {
    int i;
    for (i = 0; i < 10; i++) { // Loop a few times for the blinking effect
        printf("\033[2J\033[1;1H"); // ANSI escape code to clear screen and move cursor to (1,1)
        printf("  _       _                                     _       _                      \n");
        printf(" ( )  _  ( )                                   ( )  _  ( )                     \n");
        printf(" | | ( ) | |   _ _  _   _    _ _   ___     __  | | ( ) | |   _ _  _   _    __  \n");
        printf(" | | | | | | /'_` )( ) ( ) /'_` )/' _ `\\ /'_ `\\| | | | | | /'_` )( ) ( ) /'__`\\\n");
        printf(" | (_/ \\_) |( (_| || (_) |( (_| || ( ) |( (_) || (_/ \\_) |( (_| || \\_/ |(  ___/\n");
        printf(" `\\___x___/'`\\__,_)`\\__, |`\\__,_)(_) (_)`\\__  |`\\___x___/'`\\__,_)`\\___/'`\\____)\n");
        printf("                    ( )_| |              ( )_) |                                \n");
        printf("                    `\\___/'               `\\___/'                                \n");

        delay(500); // Delay for 500 milliseconds
        printf("\033[2J\033[1;1H"); // Clear screen again
        delay(500); // Delay again
    }
    return 0;
}
