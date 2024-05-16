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
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Assign meaning to tokens
void lex(char *line, int start, int end,int length, char *type, int cmpt);

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

// Assign meaning to tokens
void lex(char *line, int start, int end, int length, char *type, int cmpt) {
   while ( start<length &&  isspace(line[start])&& start < end && cmpt){
      start++;
   }
   if(end>length-1){
      end-=2;
   }
   if (start >= end){
      return;
   }
   char token[MAXTOKEN];
   strncpy(token,&line[start],end - start);
   token[end-start]='\0';
   printf("%s: %s\n",type, token);
}

// Break the string down into tokens
void tokenize(char *line, int length){
   int start=0, end=0;
   static int line_char=0;
   for( end = 0; end < length ; end++){
      if(line_char==1){
         start = end;
         end++;
         while((line[end]!='/' || line[end-1] !='*') && end < length ){
            end++;
         }
         if(end <= length-2 ){
            line_char=0;
         }
         lex(line,start,++end,length,"Comment",0);
         start = end;
         end-=2;

      }
      else if(line[end]=='"' ){
         lex(line,start,end,length, "Token",1);
         start = end;
         end++;
         while(line[end]!='"' && end < length ){
            end++;
         }
         lex(line,start,++end,length,"String",1);
         start = end;
         end--;
      }

      else if(line[end]=='\'' ){
         lex(line,start,end,length, "Token",1);
         start = end;
         end++;
         if(line[end]=='\\'){
            end++;
         }
         end++;
         lex(line,start,++end,length,"Char",1);
         start = end;
         end--;
      }
      else if(line[end]=='/' && line[end+1]== '*'){
         //lex(line,start,end,length, "Token")
         lex(line,start,end,length, "Token",1);
         start = end;
         end++;
         while(end < length && (line[end]!='/' || line[end-1]!='*')){
            end +=1;
         }
         if(end>length-2 ){
            line_char=1;
         }
         lex(line,start,++end,length,"Comment",1);
         start = end;
         end-=2;
      }
      else if(isspace(line[end])){
         lex(line,start,end,length, "Token",1);
         start = end;
      }
   }
}
