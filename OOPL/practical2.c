/*Write a c program to compute following computation on matrix
	1.Addition of two matrices
	2.Subtraction of two matrices
	3.Multiplication of two matrices
	4.Transpose of a matrix
	(use functions , use switch case)*/
	
#include<stdio.h>

int a[20][20] , b[20][20] , z[20][20] , r1 , c1;
void accept(int r,int c )
{
	
	printf("Enter the first matrix:  \n");
	for(int i = 0 ; i < r; i++){
		for(int j = 0 ; j < c ; j++){
			scanf("%d" , &a[i][j]);
		}
	}
	printf("Enter the second matrix:  \n");
	for(int i = 0 ; i < r; i++){
		for(int j = 0 ; j < c ; j++){
			scanf("%d" , &b[i][j]);
		}
	}
	
}

void display(int r , int c )
{
	printf("First matrix is: \n");
	
	for(int i = 0 ; i < r; i++){
		for(int j = 0 ; j < c ; j++){
			printf("%d " , a[i][j]);
		}
		printf("\n");
	}
	printf("Second matrix is :  \n");
	for(int i = 0 ; i < r; i++){
		for(int j = 0 ; j < c ; j++){
			printf("%d " , b[i][j]);
		};
		printf("\n");
	}
	
}

void add(int r , int c )
{
	printf("Addition of matrices is : \n");
	for(int i = 0 ; i < r; i++){
		for(int j = 0 ; j < c ; j++){
			z[i][j] = a[i][j] + b[i][j];
			printf("%d " , z[i][j]);
		};
		printf("\n");
	}
}

void sub(int r , int c )
{
	printf("Subtraction of matrices is : \n");
	for(int i = 0 ; i < r; i++){
		for(int j = 0 ; j < c ; j++){
			z[i][j] = a[i][j] - b[i][j];
			printf("%d " , z[i][j]);
		};
		printf("\n");
	}
}

void multi(int r , int c)
{
	printf("Multiplication of matrices is : \n");
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			for(int k = 0 ; k < r ; k++){
				z[i][j] += a[i][k] * b[k][j];
			}
			printf("%d ",z[i][j]);	
		}
		printf("\n");
	};
}

void transpose(int r , int c)
{
	printf("Transpose of first matrix is : \n");
	for(int i = 0 ; i < c ; i++){
		for(int j = 0 ; j < r ; j++){
			printf("%d " , a[j][i]);
		}
		printf("\n");
	}
	printf("Transpose of second matrix is : \n");
	for(int i = 0 ; i < c ; i++){
		for(int j = 0 ; j < r ; j++){
			printf("%d " , b[j][i]);
		}
		printf("\n");
	}
}

int main()
{
	
	printf("Enter the no. of rows : \n");
	scanf("%d",&r1);
	printf("Enter the no. of columns : \n");
	scanf("%d",&c1);
	
	accept(r1,c1 );
	display(r1,c1);
	int choice;
	while(choice != 0){
		printf("Enter the operation you want to perform :\n1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Transpose\n0 - Exit\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				add(r1,c1);
				break;
			case 2:
				sub(r1,c1);
				break;
			case 3:
				multi(r1,c1);
				break;
			case 4:
				transpose(r1,c1);
				break;
			default:
				if(choice == 0)
					printf("Ending program...\n");
				else
					printf("Invalid Choice, Try again...\n");
				break;
		}
	}

	return 0;
}

