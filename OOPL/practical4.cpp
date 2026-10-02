#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Books
{
private:
    char *title;
    char *author;
    char *publisher;
    float price;
    int stock;

public:
    // Default constructor
    Books()
    {
        title = new char[100];
        author = new char[100];
        publisher = new char[100];

        strcpy(title, "");
        strcpy(author, "");
        strcpy(publisher, "");

        price = 0.0;
        stock = 0;
    }

    // Parameterized constructor
    Books(const char *t, const char *a, float p,
          const char *pub, int s)
    {
        title = new char[strlen(t) + 1];
        author = new char[strlen(a) + 1];
        publisher = new char[strlen(pub) + 1];

        strcpy(title, t);
        strcpy(author, a);
        strcpy(publisher, pub);

        price = p;
        stock = s;
    }

    // Function to input book details
    void getDetails()
    {
        cout << "\nEnter Book Title: ";
        cin.ignore();
        cin.getline(title, 100);

        cout << "Enter Author: ";
        cin.getline(author, 100);

        cout << "Enter Publisher: ";
        cin.getline(publisher, 100);

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Stock Position: ";
        cin >> stock;
    }

    // Function to search book
    bool searchBook(const char *t, const char *a)
    {
        return (strcmp(title, t) == 0 &&
                strcmp(author, a) == 0);
    }

    // Function to process customer's request
    void purchaseBook()
    {
        int copies;

        cout << "\nEnter number of copies required: ";
        cin >> copies;

        if (copies <= stock)
        {
            float totalCost = copies * price;

            cout << "\nBook Details";
            cout << "\n-------------";
            cout << "\nTitle     : " << title;
            cout << "\nAuthor    : " << author;
            cout << "\nPublisher : " << publisher;
            cout << "\nPrice     : Rs. " << fixed << setprecision(2)
                 << price;
            cout << "\nCopies    : " << copies;
            cout << "\nTotal Cost: Rs. " << totalCost << endl;

            stock = stock - copies;
        }
        else
        {
            cout << "\nRequired copies not in stock." << endl;
        }
    }

    // Display book details
    void display()
    {
        cout << "\nTitle     : " << title;
        cout << "\nAuthor    : " << author;
        cout << "\nPublisher : " << publisher;
        cout << "\nPrice     : Rs. " << price;
        cout << "\nStock     : " << stock << endl;
    }

    // Destructor
    ~Books()
    {
        delete[] title;
        delete[] author;
        delete[] publisher;
    }
};

int main()
{
    int n;
    char searchTitle[100];
    char searchAuthor[100];
    bool found = false;

    cout << "====================================\n";
    cout << "       BOOK SHOP INVENTORY SYSTEM\n";
    cout << "====================================\n";

    cout << "\nEnter number of books in inventory: ";
    cin >> n;

    // Dynamic allocation using new
    Books *inventory = new Books[n];

    // Input inventory details
    cout << "\nEnter Book Details\n";
    cout << "==================\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nBook " << i + 1 << endl;
        inventory[i].getDetails();
    }

    // Search for a book
    cin.ignore();

    cout << "\n\nEnter book title to search: ";
    cin.getline(searchTitle, 100);

    cout << "Enter author name: ";
    cin.getline(searchAuthor, 100);

    // Search inventory
    for (int i = 0; i < n; i++)
    {
        if (inventory[i].searchBook(searchTitle, searchAuthor))
        {
            found = true;

            cout << "\nBook is available.";

            // Process customer's request
            inventory[i].purchaseBook();

            break;
        }
    }

    if (!found)
    {
        cout << "\nBook is not available in the shop." << endl;
    }

    // Release dynamically allocated memory
    delete[] inventory;

    return 0;
}