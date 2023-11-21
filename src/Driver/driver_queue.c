#include <stdio.h>
#include "../ADT/Queue.h"

int main() {
    Queue q;
    Word val;

    // Membuat Queue kosong
    CreateQueue(&q);

    // Menambahkan elemen ke dalam Queue
    enqueue(&q, stringToWord("Element1"));
    enqueue(&q, stringToWord("Element2"));
    enqueue(&q, stringToWord("Element3"));

    // Menampilkan isi Queue
    printf("Queue elements: ");
    displayQueue(q);
    printf("\n");

    // Menghapus elemen dari Queue
    dequeue(&q, &val);
    printf("Dequeued element: %s\n", WordToString(val));

    // Menampilkan isi Queue setelah dequeue
    printf("Queue elements after dequeue: ");
    displayQueue(q);
    printf("\n");

    // Menampilkan panjang Queue
    printf("Queue length: %d\n", lengthQueue(q));

    return 0;
}
