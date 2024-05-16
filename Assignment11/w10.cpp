#include<iostream>
using namespace std;

//classes
class Animal{
public:
     void Speak1(){ cout << "Speak1 Animal" << endl; }
     void Speak2(){ cout << "Speak2 Animal" << endl;}
     void Speak3(){ cout << "Speak3 Animal" << endl;}
};

class Dog: public Animal{
public:
     void Speak1(){ cout << "Speak1 Dog" << endl; }
     void Speak2(){ cout << "Speak2 Dog" << endl;}
     void Speak3(){ cout << "Speak3 Dog" << endl;}
};

class PetDog: public Dog{
  public:
     void Speak1(){ cout << "Speak1 PetDog" << endl; }
     void Speak2(){ cout << "Speak2 PetDog" << endl;}
     void Speak3(){ cout << "Speak3 PetDog" << endl;}
};


int main(){
    Dog* pDog1 = new Dog();
    pDog1->Speak1();
    pDog1->Speak2();
    pDog1->Speak3();
}
