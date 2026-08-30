#include<iostream>
#include<string>

using namespace std;

class Student
{
	string nm , drv_lic , clss , dob ;
	int roll;
	char *div , *bdgp;
	long long ctnum;
	
public:
	Student()
	{
	nm = "";
	dob = "";
	clss = "";
	roll = 0;
	ctnum = 0;
	div = new char[6];
	bdgp = new char[3];
	}

	~Student()
	{
		delete[] div;
		delete[] bdgp;
	}
	
	friend class addinfo;
	
	void inputinfo()
	{
		cin.ignore();
		cout<<"\n\n____________________*STUDENT DATABASE*__________________________\n\n";
		cout<<"Student Name: ";
		getline(cin,nm);
		cout<<"\nClass: ";
		getline(cin,clss);
		cout<<"\nDivision: ";
		div = new char[10];
		cin>>div;
		cout<<"\nRoll Number: ";
		cin>>roll;
		cout<<"\nDate of Birth ( Format - dd/mm/yyyy ): ";
		cin.ignore();
		getline(cin,dob);
		cout<<"\nBlood Group ( A+ , A- , B+ , B- , AB+ , AB- , O+ , O- ): ";
		bdgp = new char[10];
		cin>>bdgp;
		cout<<"\nEnter Driving License Number: ";
		cin>>drv_lic;
	}
};

class addinfo
{
public:
	long long ctnum;
	
	void getinfo()
	{
	try
	{
		cout<<"\nContact Number: ";
		cin>>ctnum;
		if (ctnum < 1000000000 || ctnum > 9999999999)
			throw ctnum;
	}
	catch (long long ctnum)
	{
		cout<<"\nException Caught!";
		cout<<"\nContact Number Entered is too long!\nTry again!!";
		cout<<"\nContact Number: ";
		cin>>ctnum;
	}
}
	
	int getroll(Student &obj)
	{
		return obj.roll;
	}
	
	void show(Student &obj);
};

void addinfo::show(Student &obj)
{
	cout<<"\nStudent Name: " << obj.nm;
	cout<<"\nClass: " << obj.clss;
	cout<<"\nDivision: " << obj.div;
	cout<<"\nRoll Number: " <<obj.roll;
	cout<<"\nDate of Birth: " <<obj.dob;
	cout<<"\nBlood Group: " <<obj.bdgp;
	cout<<"\nContact Number: "<<obj.ctnum;
	cout<<"\n---------------------------------------------------------------\n";
}

int main()
{
	Student a[30];
	int i,n;
	cout<<"Enter the number of students: ";
	cin>>n;
	addinfo s[30];
	for (i=0 ; i<n ; i++)
	{
		cout<<"\n--------------------------------------------------------\n\nEnter the details of Student "<<i+1;
		a[i].inputinfo();
		s[i].getinfo();
	}
	cout<<
"\n________________________________________________________________________"<<endl;
	for (i=0; i<n ; i++)
	{
		s[i].show(a[i]);
	}
	while(true)
	{
		int r,ch;
		int flag=0;
		cout<<"\nEnter Roll No. of the Student to get info: ";
		cin>>r;
		for (i=0; i<n ; i++)
		{
			if(r == s[i].getroll(a[i]))
			{
				s[i].show(a[i]);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "\nRecord Not Found!";
		cout<<"\nDo you want to continue? (Enter 1 for Yes , 0 for No): ";
		cin >> ch;
		if(ch!=1)
			break;
		}
		cout<<"\nEnding the Program!";
		return 0;
}
		
		


	
		

