#include <stdio.h>
#include <stdlib.h>
#include "song.h"
#include "../boolean.h"


// asumsi jika queue/RiwayatLagu kosong pasti ada current song untu

void songNext(Queue *q, Stack *RL, currentsong*CS)
{
    if ((*CS).status == 0)
    {
        if (((*q).idxHead == IDX_UNDEF || (*q).idxTail == IDX_UNDEF))
        {
            printf("%sERROR: %sQueue kosong, Current Song juga kosong\n");
            printf("%sTidak ada lagu yang dapat diputar.\n");
        }
        else
        {
            dequeueLaguNext(q, CS);

            (*CS).status = 1;

            printf("%sOutput: %sMemutar lagu selanjutnya\n");
            printf("\"%s\" oleh \"%s\"\n", (*CS).SongTitle.TabWord, (*CS).SingerName.TabWord);
        }
    }
    else if ((*q).idxHead == IDX_UNDEF || (*q).idxTail == IDX_UNDEF)
    {
        printf("%sOutput: %sQueue kosong, memutar kembali lagu\n");
        printf("\"%s\" oleh \"%s\"\n", (*CS).SongTitle.TabWord, (*CS).SingerName.TabWord);

    }
    else
    {
        PushRiwayatLagu(RL, (*CS).SongTitle, (*CS).AlbumName, (*CS).SingerName);
        dequeueLaguNext(q, CS);

        (*CS).status = 1;

        printf("%sOutput: %sMemutar lagu selanjutnya\n");
        printf("\"%s\" oleh \"%s\"\n", (*CS).SongTitle.TabWord, (*CS).NamaPenyanyi.TabWord);
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
        CS->SingerName = CopyWord(CSR.namaPenyanyi);
        CS->AlbumName = CopyWord(CSR.namaAlbum);
        CS->SongTitle = CopyWord(CSR.namaLagu);
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