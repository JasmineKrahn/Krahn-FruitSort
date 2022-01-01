#include "Catalog.h"
#include "LeakWatcher.h"
using namespace std;

//calls appropriate method based on input command
//displays invalid command when an invalid input is read
//stops the program when 'S' is read in
//displays the beginning of the program containing the number of types of fruit
void Catalog::Run()
{
   cin >> numTypes;
   cout << "There are " << numTypes << " types of fruits initially in the list." << endl;
   cout << "They will be read in and inserted in the list in order." << endl;
   for(int i = 0; i < numTypes; i++)
   {
       Add();
       cout << endl;
   }
   cin >> command;
   while (command != 'S')
   {
      cout << endl;
      if (command == 'I')
         Add();
      else if (command == 'D')
         Remove();
      else if (command == 'P')
         Print();
      else
         cout << "Invalid command!";
      cin >> command;
      cout << endl;
   }
   cout << endl << "Normal Termination of program 2!" << endl;
   delete fruits;
}

//Adds a fruit to the list
//Prints out statement of whether fruit was added or not
void Catalog::Add()
{
   InfoType* fruit = new InfoType;
   cin >> fruit;
   InfoType* fruit2 = new InfoType(*fruit);
   if (fruits->Insert(fruit))
      cout << "Added to list:     " << fruit;
   else
      cout << "Already in list:   " << fruit2;
   delete fruit2;
}

//Removes a fruit from the list
//Prints out statement of whether the fruit was deleted or not
void Catalog::Remove()
{
   InfoType* fruit = new InfoType();
   cin >> fruit;
   if (fruits->Delete(*fruit))
      cout << "Deleted from list: " << fruit;
   else
      cout << "Wasn't in list:    " << fruit;
   delete fruit;
}

//Displays fruit in the list
void Catalog::Print()
{
   cout << "Below are the fruits currently in the list";
   fruits->Display(cout);
}