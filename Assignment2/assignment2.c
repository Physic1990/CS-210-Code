/*********************************************
 * Id: nira0376
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * Comment about what this program does
 *********************************************/


#define MAXTOKEN  256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Assign meaning to tokens
void lex(char *line, int start, int end,int length, char *type);

// Break the string down into tokens
void tokenize(char *line, int length);


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
      tokenize(line, read);
   }

   fclose(fp);
   if (line) {
      free(line);
   }
   exit(EXIT_SUCCESS);
}

//Break the string dowm into tokens
void tokenize(char *line, int length)
{
   int tokenStart = 0;
   int end=0;

   for(end=0; end<length;end++)
   {
      if(line[end] == '"'){
         lex(line, tokenStart, end, length, "Token");
         tokenStart = end;
	 end++;

         while(end < length && line[end] != '"'){
	    end++;
	 }

         lex(line, tokenStart, ++end, length, "String");
         tokenStart = end;
	 end--;
      } 
      else if(isspace(line[end])){
         lex(line, tokenStart, end, length, "Token");
         tokenStart = end;
      } 
   }
}


//Assign meaning to tokens
void lex(char *line, int start, int end, int length, char *type)
{
   char token[MAXTOKEN];
   while(start < length && isspace(line[start]) && start < end)
   {
      start++;
   }
   if(start >= end){
      return;
   } 
   strncpy(token, &line[start], end - start);
   token[end-start] = '\0';
   printf("%s: %s\n", type, token);
}

