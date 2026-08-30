#include<stdio.h>

int average(int a[] , int n ){
	int average , i , sum = 0;
	for(i=0;i<n;i++)
		sum+=a[i];
	average = sum / n;
	printf("Average marks is : %d\n", average);
	}
	
int high_low(int n , int a[] ){
	int i , high = a[0] , low = a[0];
	for(i =0 ; i < n ; i++){
		if(a[i]>high){
		high = a[i];
		}
 		if((a[i]<low)&&(a[i]!=-1)){
 		low = a[i];
 		}
 	}
 	printf("Highest marks : %d\n" , high);
 	printf("Lowest marks : %d\n" , low);
 	}
 	
 int high_freq(int n , int a[]){
 	int i , high_freq = 0 , high_freq_marks;
 	for(int i = 0; i < n; i++){
        int frequency = 0;
        for(int j = 0; j < n; j++){
            if(a[i] == a[j]){
                frequency++;
            }
        }
        if(frequency > high_freq){
            high_freq = frequency;
            high_freq_marks = a[i];
        }
    }
    printf("Marks with high frequency : %d\n",high_freq_marks);
    }
    
int absent(int n ,int a[]){
   	int absent=0;
   	for (int i =0 ; i<n; i++){
		if(a[i] == -1){
			absent++;
		}
	}
	printf("Absent students : %d\n",absent);
	}
   	
int main(){
	int a[60],n ;
	printf("Enter the number of students : ");
	scanf("%d",&n);
	printf("Enter the marks of the students (Enter -1 if student is absent) : \n");
	for(int i = 0 ; i < n ; i++){
		printf("Enter the marks of the student %d : ", i + 1);
		scanf("%d" , &a[i]);
		}
	char choice;
	printf("Enter the choice:\n : 1-Average marks\n2-Highest and lowest marks\n3-Number of absent students\n4-Marks with high frequency\n");
	scanf(" %c" , &choice);
	switch(choice){
		case '1':
			average(a,n);
			break;
		case '2':
			high_low(n,a);
			break;
		case '3':
			absent(n,a);
			break;
		case '4':
			high_freq(n,a);
			break;
		default:
			printf("Invalid choice\n");
			break;
	}
	
	return 0;
	};

	

//OUTPUT

/*

Enter the number of students : 7
Enter the marks of the students (Enter -1 if student is absent) : 
Enter the marks of the student 1 : 68
Enter the marks of the student 2 : 95
Enter the marks of the student 3 : 82
Enter the marks of the student 4 : -1
Enter the marks of the student 5 : 95
Enter the marks of the student 6 : 78
Enter the marks of the student 7 : -1
Enter the choice:
 : 1-Average marks
2-Highest and lowest marks
3-Number of absent students
4-Marks with high frequency
1
Average marks is : 59
2
Highest marks : 95
Lowest marks : 68
3
Absent students : 2
4
Marks with high frequency : 95

*/