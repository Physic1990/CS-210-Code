#define MAXTOKEN 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// This is the function you need to write
void parser(char *line, int length);

int main(int argc, char *argv[])
{
   if(argc<2)
   {
      printf("Please specify input file.\n");
      printf("%s /y/shared/Engineering/cs-drbc/assignments/cs210/w01_in1.txt\n", argv[0]);
      return 1;
   }
   FILE * fp;
   char * line = NULL;
   size_t len = 0;
   ssize_t read;

   fp = fopen(argv[1], "r");
   if (fp == NULL){
      printf("Error: Could not open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
  }

   while ((read = getline(&line, &len, fp)) != -1) {
      parser(line, read);
   }

   fclose(fp);
   if (line) {
      free(line);
   }
   exit(EXIT_SUCCESS);
}

void parser(char *line, int length) {
   //********************** Fill in your code here ******************
}

