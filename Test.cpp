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
  string listTwo[] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
  string listSixt[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
  
  string val;		// binary / base sixteen value to read in
  
  while (input != 'q')	// while the input is not 'q' ...
  {
    cout << ">>> ";	// print our prompt
    cin >> input;	// read in the input
    if (input == 't')	// we're converting binary to base sixteen
    {
      // read in the whole line
      cin >> val;
      // print out the binary value
      cout << "Base Two: " << val << endl;
      // use the index to find the base sixteen equivalent and print it out
      cout << "Base Sixteen: " << listSixt[ find(val, listTwo) ] << endl;
    }
    
    else if (input == 's') // we're converting base sixteen to binary
    {
      // read in the whole line
      cin >> val;
      // print out the base sixteen value
      cout << "Base Sixteen: " << val << endl;
      // use the index to find the binary equivalent and print it out
      cout << "Base Two: " << listTwo[ find(val, listSixt) ] << endl;
    }
    
    else if (input == 'q')
      return 0;		  // end the program
  }
}

/*
string readIn;
cout << "Enter a base 16 number >>>";
cin >> readIn;
int length = readIn.length();
string baseSixteen = new string[length];
for(int 1 = 0; i < length; i++) {
	baseSixteen[i] = readIn.at(i);
}
//use this array to find the binary numbers associated with
*/
