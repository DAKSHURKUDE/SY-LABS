#include<iostream>
#include<stack>
#include<string>

using namespace std;

void paalindrome(string str)
{
    int n = str.length();
    bool isPalindrome = true;

    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
        {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
        cout << str << " is a palindrome." << endl;
    else
        cout << str << " is not a palindrome." << endl;
}

void reverseString(string str)
{
    cout << "Original string: " << str << endl;

    string reversedStr = "";
    stack<char> characters;

    for (char character : str)
    {
        characters.push(character);
    }

    while (!characters.empty())
    {
        reversedStr += characters.top();
        characters.pop();
    }

    cout << "Reversed string: " << reversedStr << endl;
}

int main()
{
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    int choice;

    cout << "Choose an option:\n";
    cout << "1. Check if the string is a palindrome\n";
    cout << "2. Reverse the string\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;  

    switch (choice)
    {
        case 1:
            paalindrome(str);
            break;
        case 2:
            reverseString(str);
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}