#include <iostream>
#include <list>

using namespace std;

void baseTenToTwo(int baseTen)
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

int main(int argc, char *arv[])
{
	int baseTen = 420;
	
	baseTenToTwo(baseTen);
	
	return 0;
}
