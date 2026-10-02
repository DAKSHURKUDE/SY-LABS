#include<iostream>
#include<string>

using namespace std;

class UserException
{
	public:
		string message;
		
		UserException(string msg)
		{
			message = msg;
		}	
};

int main()
{
	int age;
	int income;
	string city;
	string vehicle;
	
	cout<<"Enter your Age: ";
	cin>>age;
	cout<<"Enter your Income: ";
	cin>>income;
	cout<<"Enter your City: ";
	cin>>city;
	cout<<"Do you have a 4-Wheeler? (yes / no): ";
	cin>>vehicle;
	
	try
	{
		if(age < 18 || age > 55)
			throw UserException("Age must be between 18 and 55 !!");
			
		if(income < 50000 || income > 100000)
			throw UserException("Income must be between 50,000 and 1,00,000 !!");
			
		if(city != "Pune" &&
		   city != "Mumbai" &&
		   city != "Bangalore" &&
		   city != "Hyderabad")
		   	throw UserException("User City must be among Pune, Mumbai, Bangalore, Hyderabad !!");
		   	
		if(vehicle != "yes")
		   	throw UserException("User must have a 4-Wheeler !!");
		   	
		cout<<"\nUser satisfies all the conditions !!"<< endl;
	}
	
	catch(UserException &e)
	{
		cout<<"\nException Caught: "<< e.message << endl;
	}
	
	return 0;
}

// OUTPUT

/*

student@student:~$ ./a.out
Enter your Age: 20
Enter your Income: 70000
Enter your City: Pune
Do you have a 4-Wheeler? (yes / no): no

Exception Caught: User must have a 4-Wheeler !!

student@student:~$ ./a.out
Enter your Age: 20
Enter your Income: 70000
Enter your City: Pune
Do you have a 4-Wheeler? (yes / no): yes

User satisfies all the conditions !!

*/

