#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
	cout<<"|-----------------------------------------|\nTeam Illogical Operators Conversion Project\n|-----------------------------------------|\n";
  	char c;
  	int num;
  	while(c!='5'){
	    cout << "Enter a number to be converted\n" << "1) Convert base 10 to binary\n" << "2) Convert binary to base 10\n" << "3) Convert base 16 to binary\n" << "4) Convert binary to base 16\n" << "5) End Program" <<endl;
	    cin>> c;
	    if(c=='1'){
	    	cout<< "Enter a Base10 number to be converted to Binary: ";
	    	cin>>num;
	    	//cout<<"\nResult: "<<baseTentoTwo(num)<<endl;
	    }else if (c=='2'){
	    	cout << "Enter a Binary number to be converted to Base10: ";
	    	cin>>num;
	    	//cout<<"\nResult: "<<baseTwotoTen(num)<<endl;//change function names if needed
	    }else if (c=='3'){
	    	cout << "Enter a Base16 number to be converted to Binary: ";
	    	cin>>num;
	    	//cout<<"\nResult: "<<baseSixTeentoTwo(num)<<endl;
	    }else if (c=='4'){
	    	 cout<< "Enter a Binary number to be converted to Base16: ";
	    	 cin>>num;
	    	 //cout<<"\nResult: "<<baseTwotoSixTeen(num)<<endl;
	    }else if(c=='5'){
	    	cout<<"Exiting program"<<endl;
	    }
	}

	return 0;
}
