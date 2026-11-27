//Jasmine Lawrence

//Insertion Sort Algorithm: This algorithm will sort the unsorted list of integers in ascending order by swaping to the right and inserting elements in the correct position. 
//IDE: Visual Studio Code, Hardware: Windows 11 laptop, Complier: g++ (MinGW-w64)

//HOW TO RUN: 
//1. Open the terminal in Visual Studio Code
//2. Navigate to the directory where the file is located
//3. Compile the code using the command: g++ insertionsort.cpp -o insertionsort
//4. Run with an input file name as an argument: .\insertionsort input1.txt  (if no argument is provided type the file name when prompted)
//5. The program will display the sorted numbers then the time taken to sort the numbers in microseconds



#include <iostream>
#include <fstream>
#include <vector> 
#include <string>
#include <chrono>
using namespace std;

void insertionSort(vector<int>& arr) {        //Insertion sort function
  for (int i=1; i < arr.size(); i++){          //Loops through the array starting from the 2nd element
    int key = arr[i];                           //saves current element in key integer variable
    int j = (int)i -1;                          //saves the previous element in j integer variable
    while (j >= 0 && arr[j] > key) {            //checks if the previous element is greater than the current element
      arr[j+1] = arr[j];                        //if true, swap the previous (or larger) element to the right
      j--;                                      //decrement j to check the next previous element 
    }
    arr[j+1] = key;                             //once the loop is complete, place the current element in that correct position
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

auto start = chrono::high_resolution_clock::now();                                      //starts timer
insertionSort(numbers);                                                                //calls the insertion sort function to run
auto stop = chrono::high_resolution_clock::now();                                      //stops the timer
auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);              //calculates the duration of the sorting process in microseconds
cout << "Time take by insertion sort: " << duration.count() << "microseconds" << endl;    //displays the time taken to sort the numbers

for (int i = 0; i < numbers.size(); i++) {
  cout << numbers[i];                                                                     //prints the sorted numbers 
  if (i + 1 < numbers.size()) cout << " ";                                                //adds a white space in between the numbers when printed
}
cout << endl;                                                                             //ends the line

cout << "Insertion sort time: " << duration.count() << " microseconds" << endl;            //displays the duration of the sorting process
return 0;

}



