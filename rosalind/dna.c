#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFERSIZE 1000
#define _GNU_SOURCE

int main( int argc, char *argv[] )
{

   if(argc != 2){
     fprintf(stderr, "Please input a file name\n");
     exit(1);
   }

   char *my_file = argv[1];

   FILE * fp;
   char * line = NULL;
   size_t len = 0;
   ssize_t read;

   fp = fopen(my_file, "r");
   if (fp == NULL)
      exit(EXIT_FAILURE);

   int a = 0;
   int c = 0;
   int g = 0;
   int t = 0;
   int skipped = 0;
   int i = 0;

   /* printf("Retrieved line of length %zu :\n", read); */
   while ((read = getline(&line, &len, fp)) != -1) {
      /*
      printf("Retrieved line of length %zu :\n", read);
      printf("%s", line);
      */

      /*remove newline*/
      size_t ln = strlen(line) - 1;
      if (line[ln] == '\n')
      line[ln] = '\0';

      for (i = 0; i < strlen(line); i++){
         char x;
         /* memcpy(dest, src, strlen(src)+1); */
         memcpy( &x, &line[i], 1 );
         x = toupper(x);
         switch(x){
            case 'A':
               ++a;
               break;
            case 'C':
               ++c;
               break;
            case 'G':
               ++g;
               break;
            case 'T':
               ++t;
               break;
            default:
               ++skipped;
               break;
         }
      }
   }

   printf("%c %c %c %c %s\n", 'A', 'C', 'G', 'T', "Skipped");
   printf("%i %i %i %i %i\n", a, c, g, t, skipped);

   fclose(fp);
   if (line)
      free(line);

   return 0;
}
