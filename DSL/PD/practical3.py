#Write a python program to store roll numbers of students in an array or list who attended training program in random order.Write a funcion for searching wheather a particular student attended the training program or not using linear search and binary search.

def linear_search(list , key):
	for i in range(len(list)):
		if list[i]==key :
			print("Roll Number is Present at index", i)
			return
	
	print("Roll Number is Not Present\n") 
	
def binary_search(list , key):
	for i in range(1,len(list)):
		for j in range(0,len(list)-i):
			if list[j]>list[j+1]:
				temp = list[j+1]
				list[j+1] = list[j]
				list[j] = temp
				
	low = 0
	high = len(list) - 1
	while(low<=high):
		mid = (low + high) // 2
		if list[mid] == key :
			print("Roll Number is Present at index" , mid)
			return
		elif list[mid] > key :
			high = mid - 1
		else :
			low = mid + 1
			
	print("Roll Number is Not Present")
			
l=[]
n=int(input("Enter the number of students: \n"))
print("Enter the Roll Numbers:\n")
for i in range(0,n):
	l.append(int(input()))
	
k=int(input("Enter the Roll No. to Search: \n"))

choice=int(input("Enter the choice :\n1 - Linear Search\n2 - Binary Search\n"))

match(choice):
	case 1:
		linear_search(l,k)
	case 2:
		binary_search(l,k)
	case _:
		print("Invalid Choice")

#OUTPUT

'''

student@student:~$ python3 pr3.py
Enter the number of students: 
5
Enter the Roll Numbers:

54
67
35
27
9
Enter the Roll No. to Search: 
27
Enter the choice :
1 - Linear Search
2 - Binary Search

1
Roll Number is Present at index 3

2
Roll Number is Present at index 1


'''
	

