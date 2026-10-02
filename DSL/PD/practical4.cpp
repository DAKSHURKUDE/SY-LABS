/*
Create a Student Record Management System using a linked list in C++.Use a singly linked list to store student data (RollNo, Name,Marks).Perform operations: Add, Delete, Update, Search. Displayrecords in ascending/descending order based on marks or rollnumber.
*/

#include<iostream>
#include<string>

using namespace std;

struct student
{
	int rollNo;
	string name;
	int marks;
	student *next;
}*head;

student *create(){
	student *temp = new student;
	cout<<"Enter the name of the Student: ";
	cin >> temp -> name;
	cout<<"Enter the Roll No. : ";
	cin >> temp -> rollNo;
	cout <<"Enter the Marks : ";
	cin >> temp -> marks;
	temp -> next = NULL;
	return temp;
}

void add()
{
	student *temp = create();
	if(head == NULL || head -> rollNo >= temp -> rollNo )
	{
		temp -> next = head;
		head = temp;
	}
	
	else{
		student *ptr = head;
		while(ptr -> next != NULL && temp -> rollNo > ptr -> next -> rollNo){
			ptr = ptr -> next;
		}
		temp -> next = ptr -> next;
		ptr -> next = temp;
	}
	
	cout << "\nStudent Record Inserted Successsfully!!" << endl;
}

void update()
{
	int rollNo;
	cout << "\nEnter the Roll Number you want to Update: ";
	cin >> rollNo;

	student *ptr = head;

	while(ptr -> rollNo != rollNo)
	{
		ptr = ptr -> next;
	}
	
	cout << "Enter the New Marks: ";
	cin >> ptr -> marks;
	
	cout << "\nStudent Record Updated Successfully !!" << endl;
}

void search()
{
	int rollNo;
	cout << "\nEnter the Roll Number to Search: ";
	cin >> rollNo;
	
	student *ptr = head;

	while(ptr -> rollNo != rollNo)
	{
		ptr = ptr -> next;
	}
	
	cout << "Student Name: " << ptr -> name << endl;
	cout << "Student Marks: " << ptr -> marks << endl;
}

void del()
{
	int rollNo;
	cout << "\nEnter the Roll Number you want to Delete: ";
	cin >> rollNo;
	
	if(head == NULL)
	{
		cout << "\nStudent Record Not Found !!" << endl;
		return;
	}
	
	if(head -> rollNo == rollNo)
	{
		student *temp = head;
		head = head -> next;
		delete temp;
		cout << "\nStudent Record Deleted Successfully !!" << endl;
		return;
	}
	
	student *ptr = head;

	while(ptr -> next != NULL && ptr -> next -> rollNo != rollNo)
	{
		ptr = ptr -> next;
	}
	student *temp = ptr -> next;
	ptr -> next = ptr -> next -> next;
	delete temp;
	cout << "\nStudent Record Deleted Successfully !!" << endl;
}


void display()
{
	if(head == NULL)
	{
		cout << "\nStudent Record Not Found !!" << endl;
		return;
	}

	student *ptr = head;
	cout << "\nStudent Details are : \n" << endl;

	while(ptr != NULL ){
		cout << "Student Name: " << ptr -> name << endl;
		cout << "Student Roll No.: " << ptr -> rollNo << endl;
		cout << "Student Marks: " << ptr -> marks << endl;
		ptr = ptr -> next;
	}
	cout << endl;
}


int main()
{
	int choice;
	while(choice != 0)
	{ 
		cout << "\nSTUDENT RECORD MANAGEMENT SYSTEM" << endl;
		cout << "1. Add Student Record" << endl;
		cout << "2. Update Student Record" << endl;
		cout << "3. Search Student Record" << endl;
		cout << "4. Delete Student Record" << endl;
		cout << "5. Display Student Record" << endl;
		cout << "6. Exit" << endl;
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch(choice)
		{
			case 1:
				add();
				break;
			case 2:
				update();
				break;
			case 3:
				search();
				break;
			case 4:
				del();
				break;
			case 5:
				display();
				break;
			case 6:
				cout << "\nExiting the Program..." << endl;
				exit(0);
			default:
				cout << "\nInvalid Choice, Try Again !!" << endl;
		}
	}
	return 0;
}

/*

OUTPUT:

STUDENT RECORD MANAGEMENT SYSTEM
1. Add Student Record
2. Update Student Record
3. Search Student Record
4. Delete Student Record
5. Display Student Record
6. Exit

Enter your choice: 1
Enter the name of the Student: Daksh
Enter the Roll No. : 1
Enter the Marks : 76

Student Record Inserted Successsfully!!

STUDENT RECORD MANAGEMENT SYSTEM
1. Add Student Record
2. Update Student Record
3. Search Student Record
4. Delete Student Record
5. Display Student Record
6. Exit

Enter your choice: 1
Enter the name of the Student: Ayush
Enter the Roll No. : 3
Enter the Marks : 87

Student Record Inserted Successsfully!!

STUDENT RECORD MANAGEMENT SYSTEM
1. Add Student Record
2. Update Student Record
3. Search Student Record
4. Delete Student Record
5. Display Student Record
6. Exit

Enter your choice: 1
Enter the name of the Student: Atharv
Enter the Roll No. : 2
Enter the Marks : 56

Student Record Inserted Successsfully!!

STUDENT RECORD MANAGEMENT SYSTEM
1. Add Student Record
2. Update Student Record
3. Search Student Record
4. Delete Student Record
5. Display Student Record
6. Exit

Enter your choice: 5

Student Details are : 

Student Name: Daksh
Student Roll No.: 1
Student Marks: 76
Student Name: Atharv
Student Roll No.: 2
Student Marks: 56
Student Name: Ayush
Student Roll No.: 3
Student Marks: 87


STUDENT RECORD MANAGEMENT SYSTEM
1. Add Student Record
2. Update Student Record
3. Search Student Record
4. Delete Student Record
5. Display Student Record
6. Exit

Enter your choice: 2

Enter the Roll Number you want to Update: 2
Enter the New Marks: 58

Student Record Updated Successfully !!

STUDENT RECORD MANAGEMENT SYSTEM
1. Add Student Record
2. Update Student Record
3. Search Student Record
4. Delete Student Record
5. Display Student Record
6. Exit

Enter your choice: 5

Student Details are : 

Student Name: Daksh
Student Roll No.: 1
Student Marks: 76
Student Name: Atharv
Student Roll No.: 2
Student Marks: 58
Student Name: Ayush
Student Roll No.: 3
Student Marks: 87


STUDENT RECORD MANAGEMENT SYSTEM
1. Add Student Record
2. Update Student Record
3. Search Student Record
4. Delete Student Record
5. Display Student Record
6. Exit

Enter your choice: 3

Enter the Roll Number to Search: 3
Student Name: Ayush
Student Marks: 87

STUDENT RECORD MANAGEMENT SYSTEM
1. Add Student Record
2. Update Student Record
3. Search Student Record
4. Delete Student Record
5. Display Student Record
6. Exit

Enter your choice: 4

Enter the Roll Number you want to Delete: 3

Student Record Deleted Successfully !!

STUDENT RECORD MANAGEMENT SYSTEM
1. Add Student Record
2. Update Student Record
3. Search Student Record
4. Delete Student Record
5. Display Student Record
6. Exit

Enter your choice: 5

Student Details are : 

Student Name: Daksh
Student Roll No.: 1
Student Marks: 76
Student Name: Atharv
Student Roll No.: 2
Student Marks: 58


STUDENT RECORD MANAGEMENT SYSTEM
1. Add Student Record
2. Update Student Record
3. Search Student Record
4. Delete Student Record
5. Display Student Record
6. Exit

Enter your choice: 6
Exiting the Program...

*/