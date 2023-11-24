#include "playlist.h"
#include <stdlib.h>
#include <stdio.h>

//CREATEPLAYLIST
void CreatePlaylist (DynamicList Playlist)
{
    
    int countKarakter = 0;
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
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silahkan coba lagi.\n");

    }

}
//PLAYLISTADDSONG

void PlaylistAddSong(StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, DynamicList *Playlist, LinierList *LaguPlaylist)
{
    int idxp;
    int idxa;

    if (!isEmptyDynamic(&Playlist))
    {
        printf("Daftar Penyanyi : \n");
        PrintPenyanyi(penyanyi); //print penyanyi
        
        printf("\n");
        printf("Masukkan Nama Penyanyi yang dipilih : ");
        StartWordInput();
        printf("\n");

        int i = 0;
        boolean penyanyivalid = false;

        while (!penyanyivalid && (i < LengthStatic(penyanyi))){
            if (isEqual(penyanyi.items[i], currentWord)){
                penyanyivalid = true;
            }
            else{
                i++;
            }
        }

        if (penyanyivalid){
            Word jenengepenyanyi = currentWord;
            printf("Daftar Album oleh : ");
            PrintAlbum(penyanyiAlbums, currentWord);
            printf("\n");

            int index = 0;
            for (int i = 0; i < penyanyiAlbums.Count; i++){
                if (isEqual(penyanyiAlbums.Elements[i].Key, jenengepenyanyi))
                {
                    printf("\t%d.", index+1);
                    DisplayWord((penyanyiAlbums.Elements[i].Key));
                    index ++;
                    printf("\n");
                }
            }
            printf("\n");

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
                        Word jenengelagu = albumsong.Elements[count - 1].Elements[i].Key;
                        printf("Daftar Playlist Pengguna :\n");
                        if (!IsListEmptyDynamic)
                        {
                            int index = 0;
                            for (int i = 0; i < LengthListDynamic(Playlist); i++)
                            {
                                printf("\t%d. ", index+1);
                                DisplayWord(GetDynamic(Playlist, i));
                                index++;
                                printf("\n");
                            }
                        }
                        printf("\n");

                        printf("Masukkan ID Playlist yang dipilih : ");
                        StartWordMark();
                        printf("\n");
                        int ID_Playlist = WordToInt(currentWord);

                        if (ID_Playlist > 0 && ID_Playlist <= LengthListDynamic(Playlist))
                        {
                            Word PlaylistPilihan = GetDynamic(Playlist, ID_Playlist-1);
                            Word MarkSC = {";", 1};
                            Word Pilihan = ConcatWord(jenengepenyanyi, MarkSC);
                            Pilihan = ConcatWord(Pilihan, jenengealbum);
                            Pilihan = ConcatWord(Pilihan, MarkSC);
                            Pilihan = ConcatWord(Pilihan, jenengelagu);

                            addressLinier P = First(LaguPlaylist);
                            boolean LaguAda = false;
                            int count = 0;
                            while (!LaguAda && count < NbElmt)
                            {
                                if (isEqual(SplitWordMark(SplitWordMark(Info(P))), jenengelagu))
                                {
                                    LaguAda = true;
                                }
                                else
                                {
                                    count++;
                                    P = Next(P);
                                }
                            }   
                            if (!LaguAda)
                            {
                                InsVLast(&LaguPlaylist, Pilihan);
                                printf("Lagu dengan judul \"");
                                DisplayWord(jenengelagu);
                                printf("\" pada album ");
                                DisplayWord(jenengealbum);
                                printf(" oleh penyanyi \n");
                                DisplayWord(jenengepenyanyi);
                                printf(" berhasil ditambahkan ke dalam playlist ");
                                DisplayWord(PlaylistPilihan);
                                printf(".\n");
                            }
                            else
                            {
                                printf("Lagu ");
                                DisplayWord(jenengelagu);
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

            



//===========================================================
