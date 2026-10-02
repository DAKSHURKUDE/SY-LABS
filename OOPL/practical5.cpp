/* 
Write a C++ program to implement the following data structures and its operations using linked list :
1) Stack 2)Queue
*/  

#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
}*top=NULL,
*front,
*rear;

node *create()
{
int a;
cout<<"Enter the element: \n";
cin>>a;
node *temp = new node;
temp -> data = a;
temp -> next = NULL;
return temp;
}

void push()
{
node *ptr = create();
if(top == NULL)
	top = ptr;
else
{
ptr -> next = top;
top = ptr;
}
cout<<"Element Inserted Successfully in Stack !! \n";
}

void display_stack()
{
cout<<"Elements in Stack are : \n";
node *ptr = top;
while(ptr != NULL)
{
	cout<< ptr -> data<< " ";
	ptr = ptr -> next;

}
cout<<endl;
}

void display_queue()
{
cout<<"Elements in Queue are : \n";
node *ptr = front;
while(ptr != NULL)
{
	cout<< ptr -> data<< " ";
	ptr = ptr -> next;

}
cout<<endl;
}

void pop()
{
if(top == NULL)
	cout<<"Stack is Empty !!\n";
else
{
	node *temp = top;
	top = top -> next;
	cout<<"Deleted Element : " << temp -> data<<"\n";
	delete temp;	
}
}

void enqueue()
{
node *ptr;
ptr = create();
if(front == NULL)
{
	front=ptr;
	rear = ptr;
}
else
{
	rear -> next = ptr;
	rear = ptr;
}
cout<<"Element Inserted Succesfully in Queue !!\n";
}

void dequeue()
{
if(front == NULL)
	cout<<"Queue is Empty !!\n";
else
{
	node *temp;
	temp = front;
	front = front -> next;
	if(front == NULL)
		rear = NULL;
	cout<<"Deleted Element is : " << temp -> data << "\n";
	delete temp;
}
}


int main()
{
	cout<<"Stack : \n";
	push();
	push();
	display_stack();
	pop();
	
	cout<<"\nQueue : \n";
	enqueue();
	enqueue();
	display_queue();
	dequeue();
	return 0;
}


//OUTPUT

/*

Stack : 
Enter the element: 
5
Element Inserted Successfully in Stack !! 
Enter the element: 
8
Element Inserted Successfully in Stack !! 
Elements in Stack are : 
8 5 
Deleted Element : 8

Queue : 
Enter the element: 
3
Element Inserted Succesfully in Queue !!
Enter the element: 
6
Element Inserted Succesfully in Queue !!
Elements in Queue are : 
3 6 
Deleted Element is : 3

*/
	
