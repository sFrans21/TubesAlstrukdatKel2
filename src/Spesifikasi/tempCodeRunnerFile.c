if (!isQueueEmpty(*UrutanLagu))
// {
//     fprintf(outputfile,"%d\n",lengthQueue(*UrutanLagu));
//     for (int i = UrutanLagu->idxHead ; i < UrutanLagu->idxTail;i++){
//         char currsong[50];
//         int k = 0;

//         while (k < 50 && UrutanLagu->buffer[i].TabWord[k] != '\0')
//         {
//         currsong[k] = UrutanLagu->buffer[i].TabWord[k];
//         k++;
//         }
//         currsong[k] = '\0';
//         char currPen[50];
//         char currAlb[50];

//         carialbumpenyanyi(*penyanyiAlbums, *albumsong, currsong, currPen, currAlb);
//         fprintf(outputfile, "%s;", currPen);
//         fprintf(outputfile, "%s\n", currAlb);
//         fprintf(outputfile, "%s;", currsong);
//         }
//     }