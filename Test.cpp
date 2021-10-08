#include <iostream>

using namespace std;

// method to find an index for a given binary / base sixteen value
int find(string val, string list[])
{
  for (int i=0; i<16; i++)	// go through the list
  {
    if (list[i]==val)		// if the value at the current index matches the given value ...
      return i;			// return the index number
  }
  
  return 0;
}

int main(int argc, char* argv[])
{
  char input;		// initialize a value for reading in inputs
  
  // initialize arrays for bases two and sixteen
  string listTwo[] = {"0","1","10","11","100","101","110","111","1000","1001","1010","1011","1100","1101","1110","1111"};
  string listTwoOther[] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
  string listSixt[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
  
  string val;		// binary / base sixteen value to read in
  
  while (input != 'q')	// while the input is not 'q' ...
  {
    cout << ">>> ";	// print our prompt
    cin >> input;	// read in the input
    if (input == 't')	// we're converting binary to base sixteen
    {
      // print prompt
      cout << "Enter a binary number >>> ";
      cin >> val;				// read in the value
      cout << "Base Two: " << val << endl;	// print out the binary value
      int length = val.length();		// store the length of the value in a separate int
      if (length>4)				// if the value is greater than 1111
      {
        string *binary = new string[length];	// initialize a new string
        cout << "Base Sixteen: ";		// initial prompt
        for (int i=0; i<length; i+=4)		// go through the length of the value
        {
          binary[i] = val.at(i);
          binary[i] += val.at(i+1);
          binary[i] += val.at(i+2);
          binary[i] += val.at(i+3);
          // convert the value at the given index and print it out
          cout << listSixt[ find(binary[i], listTwoOther) ];
          
          cout << " ";
        }
        cout << endl;
      }
      
      else	// simply use the index to find the base sixteen equivalent and print it out
        cout << "Base Sixteen: " << listSixt[ find(val, listTwo) ] << endl;
    }
    
    else if (input == 's') // we're converting base sixteen to binary
    {
      // print prompt
      cout << "Enter a base 16 number >>> ";
      cin >> val;				// read in the value
      cout << "Base Sixteen: " << val << endl;	// print out the base sixteen value
      int length = val.length();		// store the length of the value in a separate int
      if (length>1)				// if the value is greater than F
      {
        string *baseSixt = new string[length];	// initialize a new string
        cout << "Base Two: ";			// initial prompt
        for (int i=0; i<length; i++)		// go through the length of the value
        {
          baseSixt[i] = val.at(i);		// convert the value at the given index and print it out
          cout << listTwoOther[ find(baseSixt[i], listSixt) ] << " ";
        }
        cout << endl;
      }
      
      else	// use the index to find the binary equivalent and print it out
        cout << "Base Two: " << listTwo[ find(val, listSixt) ] << endl;
    }
    
    else if (input == 'q')
      return 0;		  // end the program
  }
}
