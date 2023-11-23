#include <stdio.h>
#include <stdlib.h>
#include "load_baru.h"
#include "../tambahan.h"
#include "../ADT/mesinkata.h"

void load(char *inputfile, StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, SQueue *UrutanLagu, DynamicList *Playlist, RiwayatLagu *History, LinierList *LaguPlaylist, CurrentSong *CS){
    Set albums;
    Set songs;
    CreateEmptySet(&albums);
    CreateEmptySet(&songs);
    Map albumLagu;
    CreateEmptymap(&albumLagu);

    char *directory;
    directory = (char *) malloc (50 * sizeof(char));
    stringConcat("../save/", inputfile, directory);

    FILE *open;
    open = fopen(directory, "r");
    if (open != NULL){
        fclose(open);
        StartWordFile(directory, 1);

        int jumlahPenyanyi;
        jumlahPenyanyi = WordToInt(currentWord);
        //printf("%d\n", jumlahPenyanyi);
        for (int i = 0; i < jumlahPenyanyi; i++) {
            ADVWord();
            int jumlahAlbum;
            jumlahAlbum = WordToInt(currentWord);
            //printf("%d ", jumlahAlbum);
            Word namaPenyanyi;
            ADVLine();
            // Membuat salinan dari currentWord ke namaPenyanyi
            for (int j = 0; j < currentWord.Length; j++) {
                namaPenyanyi.TabWord[j] = currentWord.TabWord[j];
            }
            namaPenyanyi.Length = currentWord.Length;
            // Mengirim namaPenyanyi ke setItem

            setItem(penyanyi, i, &namaPenyanyi);
            //printf("%s\n", (*penyanyi).items[i].TabWord);

            for (int z=0; z < jumlahAlbum; z++)
            {
                ADVWord();
                int jumlahLagu;
                jumlahLagu = WordToInt(currentWord);
                //printf("%d ", jumlahLagu);
                ADVLine();
                Word namaAlbum;
                for (int j = 0; j < currentWord.Length; j++) {
                    namaAlbum.TabWord[j] = currentWord.TabWord[j];
                }
                namaAlbum.Length = currentWord.Length;
                InsertSet(&albums, namaAlbum);
                //printf("%s\n", namaAlbum.TabWord);
            
                for (int k=0; k<jumlahLagu; k++)
                {
                    ADVLine();
                    Word judulLagu;
                    for (int j = 0; j < currentWord.Length; j++) {
                        judulLagu.TabWord[j] = currentWord.TabWord[j];
                    }
                    judulLagu.Length = currentWord.Length;
                    InsertSet(&songs, judulLagu);
                    //printf("%s\n", judulLagu.TabWord);
                    for (int b = 0; b < judulLagu.Length; b++){
                        judulLagu.TabWord[b] = '\0';
                    }
                }
                Insertmap(&albumLagu, namaAlbum, songs);
                for (int b = 0; b < namaAlbum.Length; b++){
                    namaAlbum.TabWord[b] = '\0';}   
                CreateEmptySet(&songs);
            }
            Insertmap(penyanyiAlbums, namaPenyanyi, albums);
            insertmaps(albumsong, albumLagu);
            CreateEmptymap(&albumLagu);
            CreateEmptySet(&albums);
            for (int b = 0; b < namaPenyanyi.Length; b++){
                namaPenyanyi.TabWord[b] = '\0';}
        }
        printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");

        // BACA CURRENTSONG
        IgnoreNewline();
        ADVSemicolon();
        if(CekWord(hasil)){
            (*CS).SingerName = hasil;
            ADVSemicolon();
            (*CS).AlbumName = hasil;
            ADVSemicolon();
            (*CS).SongTitle = hasil;
        } else {
            Word baca;
            baca.TabWord[0] = STRIP;
            baca.Length = 1;
            (*CS).SingerName = baca;
            (*CS).AlbumName = baca;
            (*CS).SongTitle = baca;
        }

        // QUEUE
        ADVLine();
        int nQueue = WordToInt(currentWord);
        for (int i = 1; i <= nQueue; i++){
            IgnoreNewline();
            ADVSemicolon();
            Word PenyanyiQueue = hasil;
            ADVSemicolon();
            Word AlbumQueue = hasil;
            ADVSemicolon();
            Word LaguQueue = hasil;
            CurrentSong tempQueue;
            tempQueue.SingerName = PenyanyiQueue;
            tempQueue.AlbumName = AlbumQueue;
            tempQueue.SongTitle = LaguQueue;
            enqueueBELV(UrutanLagu, tempQueue);
        }

        // STACK
        ADVLine();
        int nRLagu = WordToInt(currentWord);
        for (int i = 1; i <= nRLagu; i++){
            IgnoreNewline();
            ADVSemicolon();
            Word PenyanyiStack = hasil;
            ADVSemicolon();
            Word AlbumStack = hasil;
            ADVSemicolon();
            Word LaguStack = hasil;
            RincianLaguStack tempStack;
            tempStack.namaPenyanyi = PenyanyiStack;
            tempStack.namaAlbum = AlbumStack;
            tempStack.namaLagu = LaguStack;
            Push(History, tempStack);
        }

        // ARRAYDIN
        RincianPlaylist createPlaylist;
        ADVLine();
        int nPlaylist = WordToInt(currentWord);
        for (int i = 1; i <= nPlaylist; i++){
            CreateEmptyLinier(&createPlaylist.judulLagu);
            ADVWord();
            int nPLagu = WordToInt(currentWord);
            createPlaylist.countLaguListLinier = nPLagu;
            ADVLine();
            Word namaPlaylist;
            for (int j = 0; j < currentWord.Length; j++) {
                namaPlaylist.TabWord[j] = currentWord.TabWord[j];
            }
            namaPlaylist.Length = currentWord.Length;
            createPlaylist.judulPlaylist = namaPlaylist;
            for (int b = 0; b < namaPlaylist.Length; b++){
                namaPlaylist.TabWord[b] = '\0';
            }

            SongListLinier IsiLaguPlaylist;
            for (int k = 1; k <= nPLagu; k++){
                ADVSemicolon();
                IsiLaguPlaylist.Penyanyi = hasil;
                ADVSemicolon();
                IsiLaguPlaylist.Album = hasil;
                ADVSemicolon();
                IsiLaguPlaylist.Lagu = hasil;
                InsVLast(&createPlaylist.judulLagu, IsiLaguPlaylist);
            }
        }
        InsertLastDynamic(Playlist, createPlaylist);
    } else {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
    }
}