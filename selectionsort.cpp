//Jasmine Lawrence
//Selection Sort Algorithm: This will sort the unsorted array of integers by finding the smallest value in the array and swaping it with the current value. 
//IDE: Visual Studio Code, Hardware: Windows 11 laptop, Complier: g++ (MinGW-w64)


//HOW TO RUN: 
//1. Open the terminal in Visual Studio Code
//2. Navigate to the directory where the file is located using Input Generator to create input files
//3. Compile the code using the command: g++ selectionsort.cpp -o selectionsort
//4. Run with an input file name as an argument: .\selectionsort (enter input file name)  (if no argument is provided type the file name when prompted)
//5. The program will display the sorted numbers then the time taken to sort the numbers in microseconds


#include <iostream>
#include <fstream>
#include <vector> 
#include <string>
#include <chrono>
#include <utility>
using namespace std;

void selectionSort(vector<int>& arr){                //Selection sort function
  int n = arr.size();                                //stores the number of elements so it doesn't have to be called repeatedly
  int minIndex;                                      //creates a variable for the minimum index
  for (int i = 0; i < arr.size() - 1; i++){
    minIndex = i;                                   //initialize the minimum index to current index
    for (int j = i +1; j < arr.size(); j++){
      if (arr[j] < arr[minIndex]){
        minIndex = j;                              //if the current element is less than the minimum index, set the minimum index to the current index
      }
    }
    if (minIndex != i){                             //if the minimum index is already not in that position
      swap(arr[i], arr[minIndex]);                 //swaps the smallest element with the current element position
    }
  }
}

int main(int argc, char* argv[]) {                //main function taking command line arguments and holding them with argv

  string filename;                                //variable for filename
  if (argc > 1) {
    filename = argv[1];                           //if there is a command line argument save the program as the filename
  } else {
    cout << "Provide input file name: ";          //or else it asks for input file name 
    cin >> filename;
  }

ifstream inFile(filename);                      //creates an input file stream to read the file
if (!inFile){                                           //checks if the file can be opened
  cerr << "Error opening file: " << filename << endl;  //if the file cannot be opened, display an error message
  return 1;                                      //return 1 to indicate there was an error
}

vector<int> numbers;                                   //creates a vector to hold the integers from the file
int value;                                              //variable to hold the integer value read from the file
while (inFile >> value) {
  numbers.push_back(value);                            //reads the numbers from the file and adds to the end of the vector
}
inFile.close();                                                             //closes the file after reading the numbers

if (numbers.empty()) {
  cerr << "No numbers found in the file: " << filename << endl;               //checks if the file is empty and dsiplays an error message
  return 1;                                                                   //returns 1 to show error
}

auto start = chrono::high_resolution_clock::now();                                     //starts timer
selectionSort(numbers);                                                                //calls the selection sort function to run
auto stop = chrono::high_resolution_clock::now();                                      //stops the timer
auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);             //calculates the duration of the sorting process in microseconds

for (int i = 0; i < numbers.size(); i++) {
  cout << numbers[i];                                                                     //prints the sorted numbers 
  if (i + 1 < numbers.size()) cout << " ";                                                //adds a white space in between the numbers when printed
}
cout << endl;                                                                             //ends the line

cout << "Selection sort time: " << duration.count() << " microseconds" << endl;            //displays the duration of the sorting process
return 0;

}
