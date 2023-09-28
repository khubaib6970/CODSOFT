#include <iostream>
#include <ctime>

using namespace std;

int main(){
	
	srand(time(0));
	
	int ranNum = rand() %2000+1;
	int userNum;
	
	do
	{
		fflush; 
		cout<<endl<<"Guess The Number: ";
		cin>>userNum;
		if(userNum>ranNum)
		{ 
			if(userNum>ranNum*2)
				cout<<"Your Guess Is Too High! Try Again."<<endl;
			else
				cout<<"Your Guess Is High! Try Again."<<endl;
		}
		if(userNum<ranNum)
		{
			if(userNum<ranNum/2)
				cout<<"Your Guess Is Too Low! Try Again."<<endl;
			else
				cout<<"Your Guess Is Low! Try Again."<<endl;
		}
		
	}while(userNum!=ranNum);
	
	cout<<endl;
	cout<<"Well Done! You Have Guessed The Number Correctly."<<endl;
}