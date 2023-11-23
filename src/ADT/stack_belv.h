/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "boolean.h"
#include "mesinkata.h"

#define Undef -1
#define MaxElStack 100

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct{
 Word namaPenyanyi;
 Word namaAlbum;
 Word namaLagu;
} RincianLaguStack;

typedef struct{
 RincianLaguStack detil_history[MaxElStack]; /* tabel penyimpan elemen */
 int TopRiwayat; /* alamat TOP: elemen puncak */
} RiwayatLagu;

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TopRiwayat
#define InfoTop(S) (S).detil_history[(S).TopRiwayat]
#define InfoSinger(D) D.namaPenyanyi
#define InfoAlbum(D) D.namaAlbum
#define InfoJudul(D) D.namaLagu

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyRiwayat(RiwayatLagu *RL);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
/* jadi indeksnya antara 0.. MaxElStack */
/* Ciri stack kosong : TOP bernilai Undef */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyRiwayat(RiwayatLagu RL);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullRiwayat(RiwayatLagu RL);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke RiwayatLagu ************ */
void Push(RiwayatLagu *RL, RincianLaguStack CS);
/* Menambahkan X sebagai elemen RiwayatLagu S. */
/* I.S. S mungkin kosong, tabel penampung elemen RiwayatLagu TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen RiwayatLagu ************ */
void Pop(RiwayatLagu *RL, RincianLaguStack *CS);
/* Menghapus X dari RiwayatLagu S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void DisplayRiwayat(RiwayatLagu RL);
/* Menampilkan Stack pada layar
   I.S. S sembarang, mungkin kosong
   F.S. Isi S ditampilkan ke layar */

void InversStack(RiwayatLagu *RL);
/* Membalik isi dari S
   I.S. S Sembarang, mungkin kosong
   F.S. Isi S terbalik
   Contoh: [2,3,4] menjadi [4,3,2] */
#endif