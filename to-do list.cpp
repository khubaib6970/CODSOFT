#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
struct node{
	string task;
	node *next;
	node *prev;
	bool status;
	node(string value){
		task=value;
		next=NULL;
		prev=NULL;
		status=false;
	}
};
class linkedList{
		node *head;
		int length;
		node *curr;
		node *temp;
	public:
		linkedList(){
			length=0;
			head=NULL;
		}
		~linkedList(){
			while (head!=NULL) {
            node* temp=head;
            head=head->next;
            delete temp;
        }
		}
		bool getStatus(int pos){
			curr=head;
			for(int i=1;i<pos;i++){
				curr=curr->next;
			}
			return curr->status;
		}
		void complete(int pos){
			curr=head;
			for(int i=1;i<pos; i++){
				curr=curr->next;
			}
			curr->status=true;
		}
		int getLength(){
			return length;
		}
		void insert(int pos, string val){
			if(pos<1 || pos> (length+1))
				cout<<"Invalid position"<<endl;
			else if(pos==1){
				if(length==0){
					temp= new node(val);
					head=temp;
					length++;
				}
				else{
					temp= new node(val);
					temp->next=head;
					head->prev=temp;
					head=temp;
					length++;
				}
			}
			else{
				temp=new node(val);
				curr=head;
				for(int i=1;i<(pos-1);i++)
					curr=curr->next;
				
				temp->next=curr->next;
				if(curr->next!=NULL)
					curr->next->prev=temp;
				curr->next=temp;
				temp->prev=curr;
				length++;
			}
		}		
		void printTask(int order){
		    if(order==1){
		        curr=head;
		        for(int i=1;curr!=NULL;i++){
		            if(curr->status==true){
		            	string task=curr->task;
		            	int len=task.length();
		            	cout<<i<<"). "<<curr->task<<setw(40-len)<<setfill('-')<<"Completed"<<endl;
					}
		            else{
		            	string task=curr->task;
		            	int len=task.length();
		            	cout<<i<<"). "<<curr->task<<setw(40-len)<<setfill('-')<<"Incomplete"<<endl;
					}
		            curr=curr->next;
		        }
		        cout<<endl;
		    } 
			else if(order==2){
				if(length==0)
					return;
		        curr=head;
		        while(curr->next!=NULL){
		            curr=curr->next;
		        }
		        for(int i=1;curr!=NULL;i++){
		            if(curr->status==true){
		            	string task=curr->task;
		            	int len=task.length();
		            	cout<<i<<"). "<<curr->task<<setw(40-len)<<setfill('-')<<"Completed"<<endl;
					}
		            else{
		            	string task=curr->task;
		            	int len=task.length();
		            	cout<<i<<"). "<<curr->task<<setw(40-len)<<setfill('-')<<"Incomplete"<<endl;
					}
		            curr=curr->prev;
		        }
		        cout<<endl;
		    }
		}
		void remove(int pos){
			if(length==0||pos<1||pos>length){
				cout<<"Invalid Position"<<endl;
				return;
			}
			curr=head;
			for(int i=1;i<pos;i++){
				curr=curr->next;
			}
			if(curr->prev!=NULL)
				curr->prev->next=curr->next;
			else
				head=head->next;
			if(curr->next!=NULL)
				curr->next->prev=curr->prev;
			delete curr;
			curr=head;
			length--;				
		}
};
int main(){
	linkedList l;
	int option;
	do{
		cout<<"Select An Option:"				<<endl;
		cout<<"1) Add Task"						<<endl;
		cout<<"2) Mark Task as Completed"		<<endl;
		cout<<"3) View Tasks"					<<endl;
		cout<<"4) Remove Tasks"					<<endl;
		cout<<"5) Remove All Completed Tasks"	<<endl;
		cout<<"6) Exit"							<<endl;
		cin>>option;
		system("CLS");
		if(option==1){
			int priorOption;
			string taskName;
			cout<<"Enter The Task Name:"<<endl;
			cin.ignore();
			getline(cin,taskName);
			cout<<"What Is The Task's Priority"<<endl;
			cout<<"1) Top Priority."<<endl;
			cout<<"2) Least Priority."<<endl;
			cout<<"3) Somewhere Between. Let Me Specify The Number."<<endl;
			cin>>priorOption;
			if(priorOption==1){
				l.insert(1,taskName);
			}
			else if(priorOption==2){
				l.insert(l.getLength()+1,taskName);
			}
			else if(priorOption==3){
				int priorPos;
				if(l.getLength()==0){
					cout<<"No List Exists Currently. Task Added In The Top."<<endl;
					priorPos=1;
					l.insert(priorPos,taskName);
				}
				else if(l.getLength()==1||l.getLength()==2){
					cout<<"Rate How Much Important It Is From 1 To "<<l.getLength()<<" :"<<endl;
					cin>>priorPos;
					l.insert(priorPos,taskName);
				}
				else{
					cout<<"Rate How Much Important It Is From 2 To "<<l.getLength()<<" :"<<endl;
					cin>>priorPos;
					l.insert(priorPos,taskName);
				}
			}
			else{
				cout<<"Invalid Choice Of Input."<<endl;
			}	
		}
		else if(option==2){
			l.printTask(1);
			int pos;
			cout<<"Enter The Task Number Which Is Completed: ";
			cin>>pos;
			if(pos>l.getLength()||pos<1)
				cout<<"Invalid Position."<<endl;
			else{
				l.complete(pos);
				cout<<"Task Status Updated Successfully"<<endl<<endl;
			}
		}
		else if(option==3){
			int order;
			cout<<"Enter The Printing Order:"<<endl;
			cout<<"1) Forward Order"<<endl;
			cout<<"2) Reverse Order"<<endl;
			cin>>order;
			l.printTask(order);
		}	
		else if(option==4){
			l.printTask(1);
			int pos;
			cout<<"Enter The Task Number Which You Want To Delete: ";
			cin>>pos;
			if(pos>l.getLength()||pos<1)
				cout<<"Invalid Position."<<endl;
			else{
				l.remove(pos);
				cout<<"Task Removed Successfully"<<endl<<endl;
			}
		}
		else if(option==5){
			int i=1;
			while(i<=l.getLength()){
			    if(l.getStatus(i)==true)
			        l.remove(i);
				else
			        i++;
			}
			cout << "All Completed Tasks Removed Successfully" << endl;
		}	
		else
			exit(1);
	}while(option!=6);
}