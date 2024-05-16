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



int operator1(char op1){
    const char *operators[]= {"<", ">", "(", ")", "+", "-", "*", "/", "|", "&", ";", ",", ":", "=", "$", "@","[", "]", "{", "}"};
    int i = 0;
    for(i=0; i<20; i++){
        if(operators[i][0]==op1){
            return 1;
        }
    }
    return 0;
}
int operator2(char op1,char op2){
    const char *operators[] = {":=", "..", "<<", ">>", "<>", "<=", ">=", "**", "!=", "=>", "{:" ,"}:"};
    int i = 0;
    for(i=0;i<12;i++){
        if(operators[i][0]==op1 && operators[i][1]==op2){
            return 1;
        }
    }
    return 0;
}
//for removing space
void tokenize(char *line, int length){
    static int incomment=0;
    int start = 0;
    int end = 0;
    for(end=0;end<length;end++){
        if(incomment==1){
            start = end;
            end++;
            while(end<length && (line[end-1]!='*' || line[end]!='/')){
                end++;
            }
            if(end<length-1){
                incomment=0;
                lex(line,start,++end,length,"Comment",0);
            }else{
                lex(line,start,end-1,length,"Comment",0);
            }
            start=end;
            end--;
        }else if(line[end]=='\''){
            lex(line,start,end,length,"Token",1);
            start=end;
            end++;
            if(line[end]=='\\'){
                end++;
            }
            end++;
            lex(line,start,++end,length,"Char",1);
            start=end;
            end--;
        }
        else if(line[end]=='"'){
            lex(line,start,end,length,"Token",1);
            start=end;
            end++;
            while(end<length && line[end]!='"'){
                end++;
            }
            lex(line,start,++end,length,"String",1);
            start=end;
            end--;
        }
        else if(line[end]=='/' && line[end+1]=='*'){
            lex(line,start,end,length,"Token",1);
            start=end;
            end++;
            while(end<length && (line[end-1]!='*'|| line[end]!='/')){
                end++;
            }
            if(end>=length-1){
                incomment=1;
                end-=2;
            }
            lex(line,start,++end,length,"Comment",1);
            start=end;
            end--;
        }
        //checking for operators
        else if(operator2(line[end],line[end+1])){
            lex(line,start,end,length,"Token",1);
            start=end;
            end++;
            lex(line,start,++end,length,"Operator",1);
            start=end;
            end--;
        }
         else if(operator1(line[end])){
            lex(line,start,end,length,"Token",1);
            start=end;
            //end++;
            lex(line,start,++end,length,"Operator",1);
            start=end;
            end--;
        }
        //double over singles
        else if(isspace(line[end])){
            lex(line,start,end,length,"Token",1);
            start=end;
        }
    }
}

int IfKeyWord(char *token){
    if(strcmp(token,"accessor")==0){
        return 1;
    }
    if(strcmp(token,"and")==0){
        return 1;
    }
    if(strcmp(token,"array")==0){
        return 1;
    }
    if(strcmp(token,"bool")==0){
        return 1;
    }
    if(strcmp(token,"case")==0){
        return 1;
    }
    if(strcmp(token,"character")==0){
        return 1;
    }
    if(strcmp(token,"constant")==0){
        return 1;
    }
    if(strcmp(token,"else")==0){
        return 1;
    }
    if(strcmp(token,"elseif")==0){
        return 1;
    }
    if(strcmp(token,"end")==0){
        return 1;
    }
    if(strcmp(token,"exit")==0){
        return 1;
    }
    if(strcmp(token,"float")==0){
        return 1;
    }
    if(strcmp(token,"func")==0){
        return 1;
    }
    if(strcmp(token,"if")==0){
        return 1;
    }
    if(strcmp(token,"ifc")==0){
        return 1;
    }
    if(strcmp(token,"in")==0){
        return 1;
    }
    if(strcmp(token,"integer")==0){
        return 1;
    }
    if(strcmp(token,"is")==0){
        return 1;
    }
    if(strcmp(token,"mutator")==0){
        return 1;
    }
    if(strcmp(token,"nature")==0){
        return 1;
    }
    if(strcmp(token,"null")==0){
        return 1;
    }
    if(strcmp(token,"of")==0){
        return 1;
    }
    if(strcmp(token,"or")==0){
        return 1;
    }
    if(strcmp(token,"other")==0){
        return 1;
    }
    if(strcmp(token,"out")==0){
        return 1;
    }
    if(strcmp(token,"pkg")==0){
        return 1;
    }
    if(strcmp(token,"positive")==0){
        return 1;
    }
    if(strcmp(token,"proc")==0){
        return 1;
    }
    if(strcmp(token,"ptr")==0){
        return 1;
    }
    if(strcmp(token,"ptr")==0){
        return 1;
    }
    if(strcmp(token,"ptr")==0){
        return 1;
    }
    if(strcmp(token,"range")==0){
        return 1;
    }
    if(strcmp(token,"subtype")==0){
        return 1;
    }
    if(strcmp(token,"then")==0){
        return 1;
    }
    if(strcmp(token,"type")==0){
        return 1;
    }
    if(strcmp(token,"when")==0){
        return 1;
    }
    if(strcmp(token,"while")==0){
        return 1;
    }
    return 0;
}


// Assign meaning to tokens
void lex(char *line, int start, int end, int length, char *type, int cmpt) {
   char token[MAXTOKEN];
   while (start<length && isspace(line[start])&& cmpt){
      start++;
   }
   if(end>length-1){
     // end-=3;
   }
   if(start>= end){
      return;
   }
   //char token[MAXTOKEN];
   strncpy(token,&line[start],end-start);
   token[end-start]='\0';
   if(IfKeyWord(token)){
      printf("%s: %s\n","Keyword",token);
   }else{
      printf("%s: %s\n",type, token);
   } 
}
