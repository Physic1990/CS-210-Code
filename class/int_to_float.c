#include<stdio.h>
#include<stdlib.h>

union element {int i; float f;};

int main(int argc, char *argv[]){
   union element e;
   e.f = 100.0;
   if(argc > 1){
     e.f = atof(argv[1]);
   }
   printf("Int %d is %f\n", e.i, e.f);
}
