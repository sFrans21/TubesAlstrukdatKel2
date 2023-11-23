#ifndef QUEUEBELV_H
#define QUEUEBELV_H

#include "boolean.h"
#include "mesinkata.h"

#define IDX_UNDEFBELV -1
#define CAPACITYBELV 100

/* Definisi elemen dan address */
typedef struct{
 Word SingerName;
 Word AlbumName;
 Word SongTitle;
} CurrentSong;

typedef struct{
 CurrentSong QueueDetail[CAPACITYBELV];
 int idxHeadBELV;
 int idxTailBELV;
} SQueue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEADBELV(q) (q).idxHeadBELV
#define IDX_TAILBELV(q) (q).idxTailBELV
#define     HEADBELV(q) (q).QueueDetail[(q).idxHeadBELV]
#define     TAILBELV(q) (q).QueueDetail[(q).idxTailBELV]

/* *** Kreator *** */
void CreateQueueBELV(SQueue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isQueueEmptyBELV(SQueue q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isQueueFullBELV(SQueue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam QueueDetail melingkar*/

int lengthQueueBELV(SQueue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueBELV(SQueue *q, CurrentSong val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam QueueDetail melingkar. */

void dequeueBELV(SQueue *q, CurrentSong *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
// void displayQueue(SQueue q);
// /* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
//    siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
//    karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
// /* I.S. q boleh kosong */
// /* F.S. Jika q tidak kosong: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika Queue kosong : menulis [] */


#endif