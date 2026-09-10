#include<stdio.h>

void input(float a[])
{
    int n;
    printf("Enter the number of students:\n");
    scanf("%d", &n);
    printf("Enter the percentage of Students:\n");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%f",&a[i]);
    }
}

void selection(float a[])
{
    int n = sizeof(a)/sizeof(a[0]);
    int min;
    float temp;

    for(int i=0; i<n-1; i++)
    {
        min = i;

        for(int j= i+1 ; j<n; j++)
        {
            if(a[j] < a[min])
            min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void insertion(float a[])
{
    int n = sizeof(a)/sizeof(a[0]);
    float key;

    for(int i = 1; i<n; i++)
    {
        key = a[i];
        int j = i -1;

        while (j>=0 && a[j]>key)
        {
            a[j+1]= a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void bubble(float a[])
{
    int n = sizeof(a)/sizeof(a[0]);
    float temp;
    
    for(int i = 0; i < n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void display(float a[])
{
    int n = sizeof(a)/sizeof(a[0]);

    for(int i =0; i < n ; i++)
    {
        printf("%.2f",a[i]);
    }
    printf("\n");
}

int main()
{
    int choice , n;
    float a[50];

    input(a);

    printf("Enter the Sort to be Performed:\n1 - Selection Sort\n2 - Bubble Sort\n3 - Insertion Sort\nEnter : ");

    switch(choice)
    {
        case 1:
            selection(a);
            printf("Sorted array using Selection Sort:\n");
            display(a);
            break;

        case 2:
            bubble(a);
            printf("Sorted array using Bubble Sort:\n");
            display(a);
            break;

        case 3:
            insertion(a);
            printf("Sorted array using Insertion Sort:\n");
            display(a);
            break;

        default:
            printf("Invalid choice!!");
    }

    if (choice >= 1 && choice <= 3)
    {
       printf("\nTop Five Students:\n");
       
       if(n<5)
        {
            for (int i = n-1; i >= 0; i--)
            {
                printf("%.2f\n", a[i]);
            }
        }
        else
        {
            for (int i = n-1; i >= n-5; i--)
            {
                printf("%.2f\n", a[i]);
            }
        }
    }
    return 0;
}