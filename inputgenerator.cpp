//Jasmine Lawrence

//Generates a text file to be used as input for the sorting algorithms. 
//IDE: Visual Studio Code, Hardware: Windows 11 laptop, Complier: g++ (MinGW-w64)
//HOW TO RUN: Compile the code using the command in the terminal: g++ inputgenerator.cpp -o inputgenerator
//Run the program in terminal: .\inputgenerator  
//Should generate 6 text files: input1.txt, input2.txt, input3.txt, input1_reversed.txt, input2_reversed.txt, input3_reversed.txt



#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(){

  int Size[3] = {100, 1000, 10000}; //array sizes of all input files
  for (int i = 0; i < 3; i++) {
    int n = Size[i];
    string fileID = to_string(i+1);
    string filename = "input" + fileID + ".txt";               //creates the file name based on the array size
    ofstream out(filename);                                    //creates the file to write the integers to
    

  for (int i=1; i <= n; i++){           //creates the ascending order of integers from 1 to n and writes them to the file
    out << i;
    if (i < n){
      out << " ";
    }
  }

  out.close();                                  //closes the file after writing the integers 

  filename = "input" + fileID + "_reversed.txt";        //creates the file name for the reversed input file
  ofstream out2(filename);                              //creates the file to write the integers to

  for (int i = n; i >= 1; i--)            //writes integers in descending order from n to 1 to the file
  {
    out2 << i;
    if (i > 1)
    {
      out2 << " ";
    }
  }
out2.close(); //closes the file after writing the integers 
  }
return 0;
}
