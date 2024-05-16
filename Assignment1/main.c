/*********************************************
 * Id: nira0376
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * Comment about what this program does
 *********************************************/

#define MAXTOKEN 256

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Assign meaning to tokens
//void lex(char *line, int start, int end);

// Break the string down into tokens
void tokenize(char *line, int length);

int main(int argc, char *argv[])
{
   if(argc<2)
   {
      printf("Please specify input file.\n");

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
      tokenize(line, read);
   }
   fclose(fp);
   if (line) {
      free(line);
   }
   exit(EXIT_SUCCESS);

}

//Break the string down into tokens
void tokenize(char *line, int length){
   int start = 0;
   int end = 0;
   char token[MAXTOKEN];
   if(line[start]=='\n'){
      return ;
   }
   while(isspace(line[start])){
      start++;
   }
	
   for(end =start; end < length; end++){
      if(isspace(line[end])){
         strncpy(token, &line[start], end-start+1);
         token[end-start] = '\0';
         printf("Token: %s\n", token);
         while(isspace(line[end])){
		end++;
	}
         start = end;
      }
   
  }
}	    
