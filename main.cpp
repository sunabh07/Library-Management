#include <stdlib.h>
#include <iostream>
#include "Books.h"

using namespace std;

int main()
{    
    Book b1;
    cout << "WELCOME TO MY BOOK MANAGEMENT " << endl << endl;
    cout << "Press 1 to Insert Book in Database: " << endl;
    cout << "Press 2 to Find Book in Database: " << endl;
    cout << "Press 3 to Update Book Data in Database: " << endl;
    cout << "Press 4 to Delete a Book in Database: " << endl;
    cout << "Press 5 to View all the Books Inside the Database: " << endl;

    int x;
    cin >> x;

    switch (x)
    {
    case 1:
        b1.AddBook();
        break;
    case 2:
        cout << "Press 1 to Find Book By Book Name: " << endl;
        cout << "Press 2 to Find Book By Author Name: " << endl;
        cout << "Press 3 to Find Book By Genre: " << endl;
        int y;
        cin >> y;
        switch (y) {
        case 1:
            b1.FindBook_byname();
            break;
        case 2:
            b1.FindBook_byAuthor();
            break;
        case 3:
            b1.FindBook_byGenre();
            break;
        default:
            cout << "Enter a valid number!!" << endl;
            break;
        }
        break;
     
    case 3:
        cout << "Press 1 to Update Book name: " << endl;
        cout << "Press 2 to Update Author name: " << endl;
        cout << "Press 3 to Update Genre: " << endl;
        cout << "Press 4 to Update Publication Year: " << endl;

        int n;
        cin >> n;

        switch (n)
        {
        case 1:
            b1.UpdateBook_byName();
            break;
        case 2:
            b1.UpdateBook_byAuthor();
            break;
        case 3:
            b1.UpdateBook_byGenre();
            break;
        case 4:
            b1.UpdateBook_byYear();
            break;

        default:
            cout << "Enter a valid number!!" << endl;
            break;
        }
        break;
    case 4:
        b1.DeleteBook();
        break;

    case 5:
        b1.ViewAllBook();
        break;

    default:
        cout << "Enter a valid number!!" << endl;
        break;
    }

   
    return 0;
}