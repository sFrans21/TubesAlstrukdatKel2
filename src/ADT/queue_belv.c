#include "queue_belv.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Kreator *** */
void CreateQueue(SQueue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isQueueEmpty(SQueue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

boolean isQueueFull(SQueue q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu ketika IDX_HEAD=0 dan IDX_TAIL=CAPACITY-1 */
    return (lengthQueue(q) == CAPACITY-1);
}

int lengthQueue(SQueue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    /* KAMUS LOKAL */
    int length;

    /* ALGORITMA */
    if (isQueueEmpty(q)) {
        length = 0;
    } else if (IDX_TAIL(q) >= IDX_HEAD(q)){ /*Ketika tail berada di belakang head*/
        length = (IDX_TAIL(q) - IDX_HEAD(q)) + 1;
    } else { /*Ketika tail berada di depan head*/
        length = (IDX_TAIL(q) - IDX_HEAD(q)) + (CAPACITY + 1);
    }

    return length;
}

/* *** Primitif Add/Delete *** */
void enqueue(SQueue *q, CurrentSong val){
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    if (isQueueEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        int i;
        if (IDX_HEAD(*q) != 0) { /* Ketika tail sudah berada di posisi paling terakhir, tetapi array belum full, maka tail akan maju ke index awal yakni 0*/
            for (i=IDX_HEAD(*q); i <= IDX_TAIL(*q); i++) {
                (*q).QueueDetail[i - IDX_HEAD(*q)] = (*q).QueueDetail[i];
            }
            IDX_TAIL(*q) += 1;
        } else if (IDX_TAIL(*q) == CAPACITY-1) {
            IDX_TAIL(*q) += 1;
        } else {
            IDX_TAIL(*q) += 1;
        }
    } 
    TAIL(*q) = val;
}