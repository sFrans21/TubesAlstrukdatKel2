#include "playlist.h"
#include <stdlib.h>
#include <stdio.h>

void CreatePlaylist (DynamicList Playlist)
{
    {    int countKarakter = 0;
    printf("Masukkan nama playlist yang ingin di buat : ");
    StartWordMark();
    printf("\n");

    for ( int i = 0; i < currentWord.Length; i++){
        if (currentWord.TabWord[i] != BLANK){
            countKarakter++;
        }
    }

    if (countKarakter >= 3){
        
        CreateEmptyDynamic(&Playlist);
        InsertLastDynamic (&Playlist, currentWord);
        printf("Playlist ");
        DisplayWord (currentWord);
        printf(" berhasil dibuat! \n");
        printf("\n Silahkan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
    }
    else
    {
        (printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silahkan coba lagi.\n"));
    }

}
}


void PlaylistAddSong(StaticList penyanyi, Map penyanyiAlbums, maps albumsong, DynamicList Playlist)
{
    {
    int idxp;
    int idxa;

    if (!isEmptyDynamic(&Playlist));
        printf("Daftar Penyanyi : \n");
        PrintPenyanyi(penyanyi);
        // printf("Daftar Penyanyi :\n");
        // for(int i=0; i< penyanyi.itemCount; i++){
        //     printf("   %d. %s\n", i+1, (penyanyi).items[i].TabWord);
        // }

        printf("\n");
        printf("Masukkan Nama Penyanyi yang dipilih : ");
        StartWordInput();
        printf("\n");

        int i = 0;
        boolean penyanyivalid = false;
        while (!penyanyivalid && (i < LengthList(penyanyi))){
            if (isEqual(penyanyi.items[i], currentWord)){
                penyanyivalid = true;
            }
            else{
                i++;
            }
        }

        if (penyanyivalid){
            Word jenengepenyanyi = currentWord;
            printf("Daftar Album oleh : %s", currentWord);
            PrintAlbum(penyanyiAlbums, currentWord);
            printf("\n");
            for(int i=0; i<penyanyi.itemCount;i++){
                if (isEqual(currentWord,(penyanyi).items[i]))
                    {idxp=i;}
        }

        printf("Masukkan Judul Album yang dipilih : ");
        StartWordInput();
        PrintLagu(albumsong, currentWord, idxp);
        
        printf("Masukkan ID Lagu yang dipilih : ");
        StartWordInput();

        PrintPenyanyi(penyanyi);
        printf("Daftar Playlist Pengguna : ");
                    
            for (int i = 0; i < Playlist; i++)
            {
                printf("\033[1;34m%d.``````````````````  ", (i + 1));
                printf("\033[1;34m%s\n", M.A[i].TabWord);
            }
        

        if (penyanyivalid){
            Word jenengepenyanyi = currentWord;
            printf("Daftar Album oleh %s : \n", (penyanyi).items[idxp].TabWord);
            for (int i=0;i<penyanyiAlbums.Elements[idxp].Value.Count;i++){
                printf("   %d. %s\n", i+1,(penyanyiAlbums.Elements[idxp].Value.Elements[i].TabWord));}
                printf("\n");
//=============================album=========================
            boolean albumvalid = false;
            printf("Masukkan Judul Album yang dipilih : ");
            StartWordInput();
            printf("\n");

            int i = 0;
            while (!albumvalid && i < penyanyiAlbums.Count){
                if (isEqual(penyanyiAlbums.Elements[i].Key,currentWord) && isEqual(penyanyiAlbums.Elements[i].Key, jenengepenyanyi)){
                    albumvalid = true;
                }
                else{
                    i++;
                }
            }
            if (albumvalid){
                Word jenengealbum = currentWord;

                printf("Daftar Lagu Album %s oleh %s : \n", albumsong.Elements[idxp].Elements[idxa].Key.TabWord, penyanyi.items[idxp].TabWord );
                for(int i=0;i<albumsong.Elements[idxp].Elements[idxa].Value.Count;i++){
                    printf("    %d. %s \n", i+1, albumsong.Elements[idxp].Elements[idxa].Value.Elements[i].TabWord);
                }
                
                int index = 0;
                for (int i = 0; i < albumsong.count; i++){
                        if (isEqual(albumsong.Elements[idxp].Elements[idxa].Key, jenengealbum))
                        {
                            printf("\t%d. ", index+1);
                            DisplayWord(albumsong.Elements[i].Elements[i].Key);
                            index++;
                            printf("\n");
                        }
                    }
                    printf("\n");

                    printf("Masukkan ID Lagu yang dipilih : ");
                    StartWordMark();
                    printf("\n");
                    int ID_Lagu = WordToInt(currentWord);

                    if (ID_Lagu > 0 && ID_Lagu <= index)
                    {
                        int check = 0;
                        int count = 0;
                        while (count < albumsong.count && check < ID_Lagu)
                        {
                            if (isEqual(albumsong.Elements[count].Elements[i].Key, jenengealbum))
                            {
                                check++;
                            }
                            count++;
                        }
                        Word LaguPilihan = albumsong.Elements[count - 1].Elements[i].Key;
                        printf("Daftar Playlist Pengguna :\n");
                        if (!IsListEmptyDynamic)
                        {
                            int index = 0;
                            for (int i = 0; i < LengthListDynamic(*Playlist); i++)
                            {
                                printf("\t%d. ", index+1);
                                DisplayWord(GetDynamic(*Playlist, i));
                                index++;
                                printf("\n");
                            }
                        }
                        printf("\n");

                        printf("Masukkan ID Playlist yang dipilih : ");
                        StartWordMark();
                        printf("\n");
                        int ID_Playlist = WordToInt(currentWord);

                        if (ID_Playlist > 0 && ID_Playlist <= LengthListDynamic(*Playlist))
                        {
                            Word PlaylistPilihan = GetDynamic(*Playlist, ID_Playlist-1);
                            Word MarkSC = {";", 1};
                            Word Pilihan = ConcatWord(jenengepenyanyi, MarkSC);
                            Pilihan = ConcatWord(Pilihan, jenengealbum);
                            Pilihan = ConcatWord(Pilihan, MarkSC);
                            Pilihan = ConcatWord(Pilihan, LaguPilihan);
                            address P = First(*Playlist);
                            boolean LaguSudahAda = false;
                            int count = 0;
                            while (!LaguSudahAda && count < NbElmt)
                            {
                                if (isEqual(SplitWordMark(SplitWordMark(Info(P))), LaguPilihan))
                                {
                                    LaguSudahAda = true;
                                }
                                else
                                {
                                    count++;
                                    P = Next(P);
                                }
                            }
                            if (!LaguSudahAda)
                            {
                                InsVLast(Playlist, Pilihan);
                                printf("Lagu dengan judul \"");
                                DisplayWord(LaguPilihan);
                                printf("\" pada album ");
                                DisplayWord(jenengealbum);
                                printf(" oleh penyanyi ");
                                DisplayWord(jenengepenyanyi);
                                printf(" berhasil ditambahkan ke dalam playlist ");
                                DisplayWord(PlaylistPilihan);
                                printf(".\n");
                            }
                            else
                            {
                                printf("Lagu ");
                                DisplayWord(LaguPilihan);
                                printf(" sudah ada di playlist ");
                                DisplayWord(PlaylistPilihan);
                                printf(".\n");
                            }
                        }
                        else
                        {
                            printf("Playlist tidak ada dalam daftar. Silakan coba lagi!\n");
                        }
                    }
                    else
                    {
                        printf("Lagu tidak ada dalam daftar. Silakan coba lagi!\n");
                    }
                }
                else
                {
                    printf("Album ");
                    DisplayWord(currentWord);
                    printf(" tidak ada dalam daftar. Silakan coba lagi!\n");
                }
            }
            else
            {
                printf("Penyanyi ");
                DisplayWord(currentWord);
                printf(" tidak ada dalam daftar. Silakan coba lagi!\n");
            }
        }
        else
        {
            printf("Kamu tidak memiliki playlist. Silakan buat terlebih dahulu!\n");
        }
}




void PlaylistAddAlbum(StaticList penyanyi, Map singeralbum, maps albumsong);


void PlaylistSwap(Word Word);

void PlaylistRemove(Word Word);

void PlaylistDelete();
