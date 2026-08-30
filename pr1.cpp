#include<iostream>
using namespace std;
class complex{
	float x;
	float y;
	
public:
	complex(){
		x=0;
		y=0;
		}
		

	friend istream &operator >> (istream &input , complex &t){
		cout<<"Enter the real part : ";
		input>>t.x;
		cout<<"Enter the imaginary part: ";
		input>>t.y;
		}
		
	friend ostream &operator << (ostream &output , complex &t){
		output<<t.x<<"+i"<<t.y<<endl;
		}
		
	complex operator+(complex c){
		complex temp;
		temp.x = x+c.x;
		temp.y = y+c.y;
		return(temp);
		}
		
	complex operator*(complex c){
		complex temp2;
		temp2.x = (x*c.x) - ( y*c.y );
		temp2.y = (x*c.y) + ( y*c.x);
		return (temp2);
		}
};
	
int main(){
	complex c1,c2,c3,c4;
	cout<<"Default Constructor Value = \n ";
	cout<<c1;
	cout<<"Enter the 1st complex number: \n";
	cin>>c1;
	cout<<"Enter the 2st complex number: \n";
	cin>>c2;
	c3 = c1 + c2;
	c4 = c1 * c2;
	cout<<"First complex number is : \n";
	cout<<c1;
	cout<<"Second complex number is : \n";
	cout<<c2;
	cout<<"Addition of complex numbers is : \n";
	cout<<c3;
	cout<<"Multiplication of complex numbers is : \n";
	cout<<c4;
	
	return 0;
	}
	
	