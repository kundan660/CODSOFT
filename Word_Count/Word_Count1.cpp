#include<iostream>
#include<fstream>

using namespace std;

int main()
{
   char filename[30], ch, content[1000];
   int totalCount = 0, currentIndex = 0, wordCount = 0;
   ifstream inputFile;
   cout<<"WORD COUNT PROGRAM\n";

   cout << "Enter the name of the file: ";
   cin >> filename;

   inputFile.open(filename, ifstream::in);

   if (!inputFile)
   {
      cout << endl << "File doesn't exist or access denied!";
      return 0;
   }

   while (inputFile >> noskipws >> ch)
   {
      content[totalCount] = ch;
      totalCount++;
   }

   inputFile.close();
   content[totalCount] = '\0';

   while (content[currentIndex] != '\0')
   {
      if (content[currentIndex] == '\n')
      {
         if (content[currentIndex + 1] != '\0' && content[currentIndex + 1] != ' ')
            wordCount++;
         currentIndex++;
      }
      else if (content[currentIndex] != ' ')
         currentIndex++;
      else
      {
         if (content[currentIndex + 1] != '\0' && content[currentIndex + 1] != ' ')
            wordCount++;
         currentIndex++;
      }
   }

   cout << endl << "Total words in the file: " << wordCount << endl;

   return 0;
}

