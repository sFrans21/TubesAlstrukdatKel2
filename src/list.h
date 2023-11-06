// void list();

#include <stdio.h>
#include <string.h>

#define MAX_ALBUMS 50
#define MAX_SONGS_PER_ALBUM 20

// Struktur untuk lagu
struct Song
{
      char title[100];
};

// Struktur untuk album
struct Album
{
      char name[100];
      struct Song songs[MAX_SONGS_PER_ALBUM];
      int numSongs;
};

// Fungsi untuk menampilkan album dan lagu dari map
void printAlbumsAndSongs(struct Album albums[], int numAlbums);
// {
//       for (int i = 0; i < numAlbums; i++)
//       {
//             printf("Album: %s\n", albums[i].name);
//             printf("Songs:\n");
//             for (int j = 0; j < albums[i].numSongs; j++)
//             {
//                   printf("- %s\n", albums[i].songs[j].title);
//             }
//             printf("\n");
//       }
// }

int main()
{
      struct Album albumMap[MAX_ALBUMS];
      int numAlbums = 0;

      // Baca file konfigurasi dan isi data ke map
      FILE *file = fopen("ncus.txt", "r");
      if (file)
      {
            char line[100];
            char currentAlbum[100] = "";
            while (fgets(line, sizeof(line), file))
            {
                  if (line[0] == '#')
                  {
                        // Ini adalah komentar, abaikan
                        continue;
                  }

                  char *albumName = strtok(line, ";");
                  char *songTitle = strtok(NULL, ";");

                  if (strcmp(albumName, currentAlbum) != 0)
                  {
                        // Ini album baru
                        strcpy(currentAlbum, albumName);
                        numAlbums++;
                        strcpy(albumMap[numAlbums - 1].name, albumName);
                        albumMap[numAlbums - 1].numSongs = 0;
                  }

                  strcpy(albumMap[numAlbums - 1].songs[albumMap[numAlbums - 1].numSongs].title, songTitle);
                  albumMap[numAlbums - 1].numSongs++;
            }

            fclose(file);
      }

      // Tampilkan album dan lagu dari map
      printAlbumsAndSongs(albumMap, numAlbums);

      return 0;
}
