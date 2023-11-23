#include <stdio.h>
#include <stdlib.h>
#include "song.h"
#include "../boolean.h"


// asumsi jika queue/RiwayatLagu kosong pasti ada current song untu

void songNext(SQueue *q, RiwayatLagu *RL, CurrentSong*CS)
{
    if (isQueueEmptyBELV(*q))
    {
        printf("Queue kosong, memutar kembali lagu");
        printf("\"");
        printWord((*CS).SongTitle);
        printf("\"");
        printf("oleh");
        printf("\"");
        printWord((*CS).SingerName);
    }
    else
    {
        RincianLaguStack CSR;
        CSR.namaPenyanyi = DuplicateKata(CS->SingerName);
        CSR.namaAlbum = DuplicateKata(CS->AlbumName);
        CSR.namaLagu = DuplicateKata(CS->SongTitle);
        Push(RL, CSR);
        dequeue(q, CS);
        printf("Memutar lagu selanjutnya");
        printf("\"");
        printWord((*CS).SongTitle);
        printf("\"");
        printf("oleh");
        printf("\"");
        printWord((*CS).SingerName);
        printf("\"");
    }
}

void songPrevious(SQueue *q, RiwayatLagu *RL, CurrentSong *CS)
{
    if (IsEmptyRiwayat(*RL))
    {
        printf("Queue kosong, memutar kembali lagu");
        printf("\"");
        printWord((*CS).SongTitle);
        printf("\"");
        printf("oleh");
        printf("\"");
        printWord((*CS).SingerName);
        printf("\"");
    }
    else
    {
        RincianLaguStack CSR;
        CurrentSong tempSong;
        enqueue(q, *CS);
        for (int i = 0; i < lengthQ(*q) - 1; i++)
        {
            dequeue(q, &tempSong);
            enqueue(q, tempSong);
        }
        Pop(RL, &CSR);
        CS->SingerName = DuplicateKata(CSR.namaPenyanyi);
        CS->AlbumName = DuplicateKata(CSR.namaAlbum);
        CS->SongTitle = DuplicateKata(CSR.namaLagu);
        printf("Memutar lagu sebelumnya");
        printf("\"");
        printWord((*CS).SongTitle);
        printf("\"");
        printf("oleh");
        printf("\"");
        printWord((*CS).SingerName);
        printf("\"");
    }
}