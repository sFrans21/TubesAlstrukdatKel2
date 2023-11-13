#include "./src/console.c"
#include <stdio.h>
#include "help.h"
int main()
{
    system("cls||clear");
    srand(time(NULL));

    Map penyanyiAlbums;
    Map albumLagu;
    List penyanyiList;

    /*Games = MakeArrayDin();
    CreateQueue(&GamesQueue);
    CreateEmptyStack(&History);*/

    boolean saved = false;
    boolean endProgram = false;
    char *command;
    command = (char *)malloc(50 * sizeof(char));

    printf("    W   W  EEEEE  L      CCCC  OOO  M   M  EEEEE  !\n");
    printf("    W   W  E      L     C     O   O MM MM  E      !\n");
    printf("    W W W  EEEE   L     C     O   O M M M  EEEE   !\n");
    printf("    W W W  E      L     C     O   O M   M  E      \n");
    printf("     W W   EEEEE  LLLL   CCCC  OOO  M   M  EEEEE  !\n");

    printf("                                  PERINGATAN!!!\n");
    printf("======================================================================================\n");
    printf("PROGRAM AKAN ERROR ATAU BERHENTI KETIKA MENJALANKAN COMMAND YANG MEMILIKI KARAKTER '.'\n");
    printf("======================================================================================\n\n");
    printf("Selamat datang di WayangWave\n\n");
    printf("Jalankan command START atau LOAD <nama file> untuk membuka file.\n");
    printf("Jalankan command QUIT untuk keluar dari program.");
    while (endProgram == false)
    {
        printf("\nJalankan command HELP untuk melihat daftar commands yang tersedia.");
        printf("\nENTER COMMAND: ");

        inputString(0, command);
        system("cls||clear");
        if (IsEmpty(Penyanyi))
        {
            if (compareString(upper(command), "START") == true)
            {
            }
            else if (compareString(upper(command), "LOAD") == true)
            {
                char *inputfile;
                inputfile = (char *)malloc(30 * sizeof(char));
                ADVWord(0);
                if (currentChar == '\n')
                {
                    wordToString(currentWord, inputfile);
                    if (compareString(upper(inputfile), "LOAD") == false)
                    {
                    }
                    else
                    {
                        printf("Command belum memiliki parameter. Silahkan input command sesuai format LOAD <filename tanpa .txt>\n");
                    }
                }
            }
            else if (compareString(upper(command), "QUIT") == true)
            {
            }
            else if (compareString(upper(command), "HELP") == true)
            {
                showhelp();
                return 0;
            }
            else
            {
                printf("Belum ada file yang dibuka. Silahkan buka file terlebih dahulu.\n");
                printf("Jalankan command START atau LOAD <filename> untuk membuka file.\n");
                printf("Jalankan command QUIT untuk keluar dari program.\n");
            }
        }
        else
        {
            if (compareString(upper(command), "SAVE") == true)
            {
                char *inputfile;
                inputfile = (char *)malloc(50 * sizeof(char));
                ADVWord(0);
                if (currentChar == '\n')
                {
                    wordToString(currentWord, inputfile);
                    if (compareString(upper(inputfile), "SAVE") == false)
                    {
                    }
                    else
                    {
                        printf("Command belum memiliki parameter. Silahkan input command sesuai format SAVE <filename tanpa .txt>\n");
                    }
                }
            }
        }
    }
}