#include <stdio.h>
#include "playlist.h"
#include "ADT/mesinkata.h"

void CreatePlayList(DynamicList *DaftarPlaylist) 
{
    printf("Masukkan nama playlist yang ingin dibuat : \n");
    StartCommand();  
    int i = 0;
    int count = 0;
    while (currentCommand.Length > i) {
        if (currentCommand.TabWord[i] != ' ') {
            count++;
        }
        i++;
    }
    if (count >= 3) {
        char *comm = wordToString(currentCommand);
        InsertLast(&list_dinamis.A[list_dinamis.NEff+1],currentCommand) ;
        CreateEmptylistb(&list_dinamis.A[list_dinamis.NEff - 1]);
        printf("\n Playlist %s berhasil dibuat!", comm);
    } else {
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
    }
}

void PlaylistAddSong(ListPenyanyi lp, MapAlbum m2,SetLagu S ,ListDinamik *daftarplaylist) {
    printf("Daftar Penyanyi:\n");
    DisplayListPenyanyi(lp);
    printf("\n");

    printf("Masukkan Nama Penyanyi: ");
    StartCommand();
    if(!isMemberListPenyanyi(currentCommand,lp)){
        printf("Nama Penyanyi  ");
        displayWord(currentCommand);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        return;
    }
    Word penyanyitemp ;
    CreateWord2(currentCommand.Length,currentCommand.TabWord,&penyanyitemp);

    char *comm=wordToString(currentCommand);
    int idxpenyanyi=albumtoidpenyanyi(lp,currentCommand);

    printf("\n");
    printf("Daftar Album oleh %s:\n",comm);
    displayMapAlbum(m2,idxpenyanyi);

    printf("\n");
    printf("Masukkan Nama Album yang dipilih: ");
    StartCommand();
    Word albumtemp;
    CreateWord2(currentCommand.Length,currentCommand.TabWord,&albumtemp);
    if (!IsMemberMapAlbum(m2,currentCommand)){
        printf("Album ");
        displayWord(currentCommand);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        return;
    }
    char *comm1=wordToString(currentCommand);
    int idxalbum=laguAlbumID(currentCommand,m2);
    printf("\n");
    printf("Daftar Lagu Album %s oleh %s : \n",comm1,comm);
    DisplaySetLagu(S,idxalbum);
    int countlagu = CountLaguByAlbumID(&S,idxalbum);
    printf("\n");
    printf("Masukkan ID Lagu yang dipilih: ");
    StartCommand();
    int idxlagu=wordToInt(currentCommand);
    if((idxlagu<=0) || (idxlagu > countlagu)){
        printf("ID lagu tidak valid\n");
        return;
    }
    Word namalagu=namalagufromalbum(S,idxalbum,idxlagu);
    displayWordNewLine(namalagu);
    displayWordNewLine(penyanyitemp);
    displayWordNewLine(albumtemp);
    printf("\n");
    printf("Daftar Playlist Pengguna :\n");
    DisplayLD(*daftarplaylist);
    printf("\n");

    // Meminta input ID Playlist
    printf("Masukkan ID Playlist yang dipilih : ");
    StartCommand(); // Mulai membaca kata
    printf("\n");
    int id_playlist = wordToInt(currentCommand) - 1;

    if(IsIdxValidLD(*daftarplaylist,id_playlist)){
        Word playlist;
        Detail d;
        PasteWord(Title(daftarplaylist->Content[id_playlist]), &playlist);      
        CreateD(&d, penyanyitemp, albumtemp, namalagu);
        // insert ke linkedlist
        InsertSB(&daftarplaylist->Content[id_playlist], d, LengthSB(daftarplaylist->Content[id_playlist]));;        
        printf("Lagu dengan judul \"");
        displayWord(namalagu);
        printf("\" pada album ");
        displayWord(albumtemp);
        printf(" oleh penyanyi \n");
        displayWord(penyanyitemp);
        printf(" berhasil ditambahkan ke dalam playlist ");
        displayWord(playlist);
        printf(".\n"); 
    }
    else {
        printf("ID Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", id_playlist + 1);
        return;
    }
}


void PlaylistAddAlbum (ListPenyanyi lp, MapAlbum m2,SetLagu S ,ListDinamik *daftarplaylist) {
    printf("Daftar Penyanyi:\n");
    DisplayListPenyanyi(lp);
    printf("\n");

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    StartCommand();
    if(!isMemberListPenyanyi(currentCommand,lp)){
        printf("Nama Penyanyi  ");
        displayWord(currentCommand);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        return;
    }
    Word penyanyitemp ;
    CreateWord2(currentCommand.Length,currentCommand.TabWord,&penyanyitemp);

    char *comm=wordToString(currentCommand);
    int idxpenyanyi=albumtoidpenyanyi(lp,currentCommand);

    printf("\n");
    printf("Daftar Album oleh %s:\n",comm);
    displayMapAlbum(m2,idxpenyanyi);

    printf("\n");
    printf("Masukkan Judul Album yang dipilih: ");
    StartCommand();
    Word albumtemp;
    CreateWord2(currentCommand.Length,currentCommand.TabWord,&albumtemp);
    if (!IsMemberMapAlbum(m2,currentCommand)){
        printf("Album ");
        displayWord(currentCommand);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        return;
    }
    char *comm1=wordToString(currentCommand);
    int idxalbum=laguAlbumID(currentCommand,m2);
    printf("\n");
    printf("Daftar Playlist Pengguna :\n");
    DisplayLD(*daftarplaylist);
    printf("\n");

    // Meminta input ID Playlist
    printf("Masukkan ID Playlist yang dipilih : ");
    StartCommand(); // Mulai membaca kata
    printf("\n");
    int id_playlist = wordToInt(currentCommand) - 1;
    if (IsIdxValidLD(*daftarplaylist, id_playlist)) {
        Word playlist;
        Detail d;
        PasteWord(Title(daftarplaylist->Content[id_playlist]), &playlist);
        Word lagu;
        DisplaySetLagu(S,idxalbum);
        /*for (int i = 0; i < ValueM(LaguAlbum, album).Length; i++) {
            PasteWord(ValueM(LaguAlbum, album).Content[i], &lagu);
            CreateD(&d, penyanyitemp, albumtemp, lagu);
            InsertSB(&DaftarPlaylist.Content[id_playlist], d, LengthSB(DaftarPlaylist.Content[id_playlist]));
        }*/
        
        printf("Album dengan judul \"");
        displayWord(albumtemp);
        printf("\" berhasil ditambahkan ke dalam playlist pengguna \"");
        displayWord(playlist);
        printf("\".\n");
    }
    else {
        printf("ID Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", id_playlist + 1);
    }
}