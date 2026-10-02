#include<fstream>
#include<iostream>
using namespace std;

int main()
{
	char data[100];
	int age;
	
	ofstream outfile;
	outfile.open("file.txt");
	
	cout<<"Enter your name: ";
	cin.getline(data, 100);
	outfile << data << endl;
	cout<<"Enter your age: ";
	cin >> data;
	outfile << data << endl;
	
	outfile.close();
	
	ifstream infile;
	infile.open("file.txt");
	
	cout<<"Information in the file: "<<endl;
	infile >> data ;
	cout<< data << endl;
	infile >> data ;
	cout<< data << endl;
	infile.close();
	
	return 0;
}
	
