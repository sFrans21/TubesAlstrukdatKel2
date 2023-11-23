#ifndef SAVE_H
#define SAVE_H

#include "start.h" // Termasuk file header yang diperlukan
#include "../ADT/stack.h"  // Mungkin memerlukan tipe data seperti Set untuk menyimpan lagu
// #include "../ADT/arrayDin.h"   // Memerlukan Map untuk menyimpan album dan lagu
//#include "../ADT/Queue.h"  // Memerlukan List statis untuk daftar penyanyi
#include "../tambahan.h"
#include "queue.h"
#include "../ADT/list_linier.h"
#include "../ADT/Queue.h"
#include "../ADT/queue_belv.h"
#include "../ADT/list_dinamis_belv.h"
#include "../ADT/list_linier_belv.h"
#include "../ADT/stack_belv.h"

typedef struct{
 Word namaPenyanyi;
 Word namaAlbum;
 Word namaLagu;
} RincianLaguStack;

typedef struct{
 RincianLaguStack detil_history[MaxElStack]; /* tabel penyimpan elemen */
 int TopRiwayat; /* alamat TOP: elemen puncak */
} RiwayatLagu;

#define Top(S) (S).TopRiwayat
#define InfoTop(S) (S).detil_history[(S).TopRiwayat]
#define InfoSinger(D) D.namaPenyanyi
#define InfoAlbum(D) D.namaAlbum
#define InfoJudul(D) D.namaLagu


#define NilLinier NULL

typedef struct tElmtlist *addressLinier;
typedef struct {
	Word Penyanyi;
	Word Album;
	Word Lagu;
} SongListLinier;

typedef struct tElmtlist { 
	SongListLinier info;
	addressLinier next;
} ElmtList;

typedef struct {
	addressLinier First;
} LinierList;

typedef struct {
    Word judulPlaylist;
    LinierList judulLagu;
    int countLaguListLinier;
} RincianPlaylist;
typedef struct
{
    RincianPlaylist *IsiPlaylist;
    int Neff;
} DynamicList;

void save(char *inputfile, StaticList *penyanyi, Map *penyanyiAlbums, maps *albumsong, SQueue *UrutanLagu, DynamicList *Playlist, RiwayatLagu *History, LinierList *LaguPlaylist, CurrentSong *CS);

#endif

