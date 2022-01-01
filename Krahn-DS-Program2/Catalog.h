#ifndef _Catalog_H_
#define _Catalog_H_
#include "LList.h"
#include "Fruit.h"
using namespace std;

//This class creates and contorls a list of fruits based on an input

class Catalog
{
private:
   LList* fruits = new LList(); //list of fruits
   char command; //input that decides what happens
   int numTypes; //number of types of fruits
public:
   void Run();
   void Add();
   void Remove();
   void Print();
};
#endif

