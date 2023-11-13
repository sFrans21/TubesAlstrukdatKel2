#include <stdio.h>
#include "help.h"

void showhelp()
{
    if (/*program dipanggil sebelum masuk sesi*/)
    {
        printf("=====[ Menu Help WayangWave ]=====\n");
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    }

    if (/*program dipanggil setelah masuk sesi. (command start sudah dijalankan)*/)
    {
        printf("1. LIST -> Untuk menampilkan daftar lagu, penyanyi, album, dan playlist\n");
        printf("2. PLAY -> Untuk memulai suatu lagu\n");
        printf("3. QUEUE -> Untuk memanipulasi queue (urutan) lagu\n");
        printf("4. SONG -> Menavigasi lagu yang ada pada queue lagu saat ini\n");
        printf("5. PLAYLIST -> Melakukan basic command untuk playlist yaitu CREATE, ADD, SWAP, REMOVE dan DELETE.\n");
        printf("    5.1 CREATE -> Membuat playlist baru dan ditambahkan pada daftar playlist pengguna.\n");
        printf("    5.2 ADD -> Menambahkan lagu pada suatu playlist yang telah ada sebelumnya pada daftar playlist pengguna.\n");
        printf("    5.3 SWAP -> Menukar lagu pada urutan ke x dan juga urutan ke y di playlist dengan urutan ke id.\n");
        printf("    5.4 REMOVE ->  Menghapus lagu dengan urutan n pada playlist dengan index id.\n");
        printf("    5.5 DELETE -> Melakukan penghapusan suatu existing playlist dalam daftar playlist pengguna.\n");
        printf("6. STATUS -> menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar.\n");
        printf("7. SAVE -> menyimpan state aplikasi terbaru ke dalam suatu file.\n");
        printf("8. QUIT -> Untuk keluar dari sesi\n");
    }
}