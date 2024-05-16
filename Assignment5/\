%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

extern int yylex();
void yyerror(char *msg);
%}

%union{
  double f;
}

%token <f> NUM
%type <f> E A T G F
%%

S : E           {printf("%f\n",$1);}
  ;

E : E '+' A     {$$ = $1 + $3; printf("%f + %f\n",$1,$3);}
  | E '-' A     {$$ = $1 - $3; printf("%f - %f\n",$1,$3);}
  | A           {$$ = $1; printf("%f\n",$1);}
  ;

A : T '#' A     {$$ = ($3+1) + $1 ; printf("%f # %f\n",$1,$3);}
  | T           {$$ = $1; printf("%f\n",$1);}

T : T '*' G     {$$ = $1 * $3; printf("%f * %f\n",$1,$3);}
  | T '/' G     {$$ = $1 / $3; printf("%f / %f\n",$1,$3);}
  | G           {$$ = $1; printf("%f\n",$1);}
  ;

G : G '<' F     {$$ = powf($1,$3); printf("%f < %f\n",$1,$3);}
  | F           {$$ = $1; printf("%f\n",$1);}
  ;

F : '(' E ')'   {$$ = $2; printf("(%f)\n" ,$2);}
  | '-' F       {$$ =-$2; printf("-%f\n",$2);}
  | NUM         {$$ = $1; printf("%f\n",$1);}
  ;
%%

void yyerror(char *msg){
   fprintf(stderr, "%s\n", msg);
   exit(1);
}

int main(){
    yyparse();
}

