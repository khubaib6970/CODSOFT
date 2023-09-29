#include <iostream>
using namespace std;

int main(){
	
	float num1,num2;
	float result;
	int operation;
	char again='Y';
	
	do
	{
		system("CLS");
		cout<<"Enter First Number: ";
		cin>>num1;
		cout<<"Enter Second Number: ";
		cin>>num2;
		
		cout<<"Enter The Operation To Perform: "<<endl;
		cout<<"1) Addition. (+)"		<<endl;
		cout<<"2) Subtraction. (-)"		<<endl;
		cout<<"3) Multiplication. (*)"	<<endl;
		cout<<"4) Division. (/)"		<<endl;
		
		while(1)
		{
			cin>>operation;
			if(operation>=1&&operation<=4)
				break;
			else
				cout<<"Wrong Input. Please Enter A Valid Operation (1-4):";
		}
		
		if(operation==1)
			result=num1+num2;
		
		else if(operation==2)
			result=num1-num2;
		
		else if(operation==3)
			result=num1*num2;
		
		else if(operation==4)
			result=num1/num2;
			
		cout<<"Result: "<<result<<endl<<endl;
		
		cout<<"Do You Want To Use Calculator Again? Y/N "<<endl;
		cin>>again;
		
	}while(again=='Y'||again=='y');
	
}