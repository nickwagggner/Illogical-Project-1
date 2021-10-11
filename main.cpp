/*
ILLOGICAL OPERATORS  
---------------------
Blake Reiger
Harrison Wiswall
Nick Wagner
Skyeler Knuuttila

Menu-driven program to converts numbers from bases...
  - 10 to 2
  - 2 to 10
  - 16 to 2
  - 2 to 16
*/

#include <iostream>
#include <list>

using namespace std;

//converts numbers in base ten to binary
void baseTentoTwo(int baseTen)
{
  //creates a stack to hold the binary numbers that make the answer
  list<int> answer;
  
  //while the base 10 number isnt 1...
  while(baseTen != 0)
  {
    //if the current number is odd
    if(baseTen % 2 == 1)
    {
      //add a 1 to the answer stack and divide the base 10 number by 2
      answer.push_back(1);
      baseTen = baseTen/2;
    }
    
    //if the current number is even
    else if(baseTen % 2 == 0)
    {
      //add a 0 to the answer stack and divide the base 10 number by 2
      answer.push_back(0);
      baseTen = baseTen/2;
    }
  }
  
  //while there are numbers in the stack...
  while(!answer.empty())
  {
    //print out the top element and remove it from the stack
    cout<<answer.back();
    answer.pop_back();
  }
  
  cout<<endl;
}

int twoPow(int exponent) 
{
  if(exponent == 0)
  {
    return 1;
  }

  int count = 2;

  for(int i = 1; i < exponent; i++)
  {
    count *= 2;
  }

  return count;
}

//converts binary numbers to base 10
int baseTwotoTen(int readIn)
{
  list <int> organize;
  int addToList;

    while(readIn != 0) 
    {
      addToList = readIn % 10;
      organize.push_front(addToList);
      readIn = readIn / 10;
    }

    int length = organize.size();

    int *baseTwo = new int[length];

    for(int i = 0; i < length; i++)
    {
      baseTwo[i] = organize.back();
      organize.pop_back();
    }

    int baseTen = 0;
    for(int i = 0; i < length; i++)
    {
      if(baseTwo[i] == 1)
      {
        baseTen += twoPow(i);
      }
    }

    return baseTen;
}

// method to find an index for a given binary / base sixteen value
int find(string val, string list[])
{
  // go through the list
  for (int i=0; i<16; i++)
  {
    // if the value at the current index matches the given value ...
    if (list[i]==val)
    {
      //return the index number
      return i;
    }
  }
  
  return 0;
}

void baseSixTeentoTwo(string val)
{
  // initialize arrays for bases two and sixteen
  string listTwo[] = {"0","1","10","11","100","101","110","111","1000","1001","1010","1011","1100","1101","1110","1111"};
  string listTwoOther[] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
  string listSixt[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

  // store the length of the value in a separate int
  int length = val.length();

  // if the value is greater than F
  if (length>1)
  {
    // initialize a new string
    string *baseSixt = new string[length];

    // go through the length of the value
    for (int i=0; i<length; i++)
    {
      // convert the value at the given index and print it out
      baseSixt[i] = val.at(i);
      cout << listTwoOther[ find(baseSixt[i], listSixt) ] << " ";
    }
    
    cout << endl;
  }
  
  else  // use the index to find the binary equivalent and print it out
    cout << listTwo[ find(val, listSixt) ] << endl;
}

int main(int argc, char *argv[])
{
  cout<<"|-----------------------------------------|\nTeam Illogical Operators Conversion Project\n|-----------------------------------------|\n";
  
  char c;
  
  long num;

  bool running = true;
  
  while(running)
  {
    cout << "Select a conversion method\n" << "1) Convert base 10 to binary\n" << "2) Convert binary to base 10\n" << "3) Convert base 16 to binary\n" << "4) Convert binary to base 16\n" << "5) End Program" <<endl<<endl<<">>>";
    cin>> c;
    
    if(c=='1')
    {
      cout<< "Enter a Base10 number to be converted to Binary: ";
      cin>>num;
      cout<<"\nResult: ";
      baseTentoTwo(num);
      cout<<endl;
    }

    else if (c=='2')
    {
      cout << "Enter a Binary number to be converted to Base10: ";
      cin>>num;

      list <int> organize;
      long readIn = num;
      int addToList;

      while(readIn != 0)
      {
        addToList = readIn % 10;
        organize.push_front(addToList);
        readIn = readIn / 10;
      }

      int length = organize.size();
      int *baseTwo = new int[length];

      for(int i = 0; i < length; i++)
      {
        baseTwo[i] = organize.back();
        organize.pop_back();
      }
      
      int baseTen = 0;
      for(int i = 0; i < length; i++)
      {
        if(baseTwo[i] == 1)
        {
          baseTen += twoPow(i);
        }
      }

      cout<<"\nResult: "<<baseTen<<endl<<endl;
    }

    else if (c=='3')
    {
      string val;
      cout << "Enter a Base16 number to be converted to Binary: ";
      cin>>val;
      cout<<"\nResult: ";
      baseSixTeentoTwo(val);
      cout<<endl;
    }

    else if (c=='4')
    {
      cout<< "Enter a Binary number to be converted to Base16: ";
      string val;
      cin>>val;

      cout<<endl;

      // initialize arrays for bases two and sixteen
      string listTwo[] = {"0","1","10","11","100","101","110","111","1000","1001","1010","1011","1100","1101","1110","1111"};
      string listTwoOther[] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
      string listSixt[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

      // store the length of the value in a separate int
      int length = val.length();

      // if the value is greater than 1111
      if (length>4)
      {
        // initialize a new string
        string *binary = new string[length];
        
        cout << "Result: ";

        // go through the length of the value
        for (int i=0; i<length; i+=4)
        {
          // convert the value at the given index and print it out
          binary[i] = val.at(i);
          binary[i] += val.at(i+1);
          binary[i] += val.at(i+2);
          binary[i] += val.at(i+3);

          cout << listSixt[ find(binary[i], listTwoOther) ];
          cout << " ";
        }
        
        cout << endl<<endl;
      }
      
      else
      {
        // simply use the index to find the base sixteen equivalent and print it out
        cout << "Result: " << listSixt[ find(val, listTwo) ] << endl<<endl;
      }  
    }

    else if(c=='5')
    {
      cout<<"Exiting program"<<endl;
      running = false;
    }

    else
    {
      cout << "enter correct input"<<endl<<endl; 
    }
    
    num=0;
  }

  return 0;
}
