// building a linked list 
#include<iostream>
using namespace std;

class Node
{
	public :
		//for data members
		string studentID;
		string studentName;
		
		Node *next;
		
	//making a constructor
	
	Node(string id,string name, Node *_next)
	{
		studentID = id;
		studentName = name;
		next = _next;
	}
	//for member function
	Node *Next(){
		return next;
	}
	
	void setNext(Node *_next)
	{
	   next = _next;
	}
	
	string getData()
	{ 
	   return (studentID + "  " + studentName);
	}
	  
	string getName()
	{
		return studentName;
	}
	
	string getID()
	{
		return studentID;
	}
	
	
	}; 
  
    
	//making linkedList class
	class LL 
	{
		public:
			Node *head;
			
				LL(){
				head = NULL;
			}
			
			//Start Node
			
		void AddToStart(string id,string name)
		
			{   cout<<"Student Inserted at the beginning";
				Node *newNode = new Node(id, name, NULL);
				Node *temp = head;
				if(temp !=NULL)
				{
				  newNode->next = head;
				  head = newNode;
				}
				
				else{
					head = newNode;
				}
			}
				
			//End node 
			void AddToEnd(string id,string name)
		
			{
				cout<< "Student Inserted at the last";
				Node *newNode = new Node(id, name, NULL);
				Node *temp = head;
				if(temp !=NULL)
				{
					while(temp->Next() != NULL)
					{
						temp = temp->Next();
					}
					temp->setNext(newNode);
				}
				else
				{
					head = newNode;	
				}
				
			}
	     //Search 
	     string Search(string id)
	     {
	     	Node *temp = head;
	     	if(temp == NULL)
	     	{
	     		return "Student not found";
			 }
			 if(temp->Next() == NULL)
			 {
			 	if(temp->getID() ==id)
				 {
				 	cout<<"Student id Searched is: " << id << endl;
				 	return "Student name is :" + temp->getName();
				  } 
				  else
				  {
				  	return "Student not found";
				  }
			  }
			  else
			  {
			  	Node *prev;
			  	do
			  	{
			  		if(temp->getID() ==id)
			  		{
			  			break;
					  }
					  else{
					  	prev = temp;
					  	temp = temp->Next();
					  }
				  }while(temp != NULL);
				  
				  cout<< "Student id Searched is : " << id << endl;
				  return "Student name is : " + temp->getName();
			  }
			   
			 
		 }
	
	    // Display  
     	void Display()
    	{
		Node *temp = head;
		if(temp == NULL)
		{
			cout << "Empty List" << endl;
			return;
		}
		if (temp->Next() == NULL)
		{
			cout << "Link List of Students are: "<< temp->getData();
			cout << "->";
			cout <<" NULL" << endl;
		}
		else{
			do{
				cout<< temp->getData();
				cout<< " -> ";
				temp= temp->Next();
			}while(temp != NULL);
			cout<<" NULL "<<endl;
		}
	   }
	};

	
	
	
	
					 
					 
					 
main()
{
LL students;
  //while loop to run unless exit is pressed
  while(true)
  {
  	cout<<endl<<"------------------------------"<<endl;
  	cout<<endl<<"Single Link List of Students"<<endl;
  	
 	cout<<endl<<"------------------------------"<<endl;
 	cout<<"1. Insert Student at the beginning"<<endl;
 	cout<<"2. Insert Student at the Last "<<endl;
 	cout<<"3. To Search the student"<<endl;
 	cout<<"4. Display Linked List of Students"<<endl;
 	
 	cout<<"5. Exit"<<endl;
    
    int choice;
    
    cout<<"Enter your choice : ";
    cin >> choice;
    
    
    //User enter choices 
    if(choice == 1)
    {
    	cout<<"Insertiing student at the beginning: "<<endl;
    	string id,name =" ";
    	
    	cout<<"Enter Student ID to be Inserted: ";
    	cin>>id;
    	
    	cout<<"Enter Student Name to be Inserted: ";
    	cin>>name;
    	
    	students.AddToStart(id, name);
	}
  	else if (choice == 2)

    {
    	cout<<"Inserting student at the Last: "<<endl;
    	string id,name =" ";
    	
    	cout<<"Enter Student ID to be Inserted: ";
    	cin>>id;
    	
    	cout<<"Enter Student Name to be Inserted: ";
    	cin>>name;
    	
    	students.AddToEnd(id, name);
	}
	
	else if (choice ==3)
	{
		string id = " ";
		cout<<" To Search the student "<< endl << "Enter the student ID to be Searched :  ";
		cin>>id;
		cout<< students.Search(id);
	}
	
	else if (choice ==4 )
	{
		students.Display();
	}
	
	else if (choice == 5)
	{
		exit(1);
	}
	
  }
	
}
