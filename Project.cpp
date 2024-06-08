#include <iostream>
#include <algorithm>
using namespace std;
string book_name[4][2];
int title;
int author;
class USER
{
    private:
    string username;
    string password;
    public:
    void create_account()
    {
        cout<<"Enter username\n";
        cin>>username;
        cout<<"Enter password\n";
        cin>>password;
    }
    bool login()
    {
        string input_username, input_password;
        cout<<"Enter username:\n";
        cin>>input_username;
        cout<<"Enter password:\n";
        cin>>input_password;

        if(input_username == username && input_password == password)
            return true;
        else   
            return false;
    }

};
class BOOKS
{
    public:
    void add_books()
    {
        
        cout<<"Enter the title and author\n";
        for(title = 0;title <= 3; title++)
        {
            for(author = 0;author <= 1; author++)
            cin>>book_name[title][author];
        }
    }
    void display_books()
    {
        cout<<"The books in the library are as follows\n";
        for(title = 0;title <= 3; title++)
        {
            for(author = 0; author <= 1 ; author++)
            cout<<book_name[title][author]<<"\t\n";
        }
    }
    void remove_books()
    {
        string remove_book;
        cout<<"Enter the name or title of the book you wish to remove:"<<endl;
        cin>>remove_book;
        bool found = false;
        for(title = 0; title<= 3; title++)
        {
            for(author = 0; author <=1 ;author++)
            {
                if(book_name[title][author]==remove_book)
                {
                    found = true;
                    for(int k = author; k <= 3; k++)
                    {
                        book_name[title][0] = book_name[k+1][0];
                        book_name[title][1] = book_name[k+1][1];
                    }
                    author--;
                    break;
                }
            }
            if(found)
                break;
        }
        if(!found)
            cout <<"Book not found!\n";
    }
};
class LIBRARY
{
    public:
    void search_book()
    {
        string search_book;
        cout<<"Enter the title or author of the book:\n";
        cin>>search_book;
        bool found = false;
        for(title = 0;title < 3;title++)
        {
            for(author = 0;author <=3;author++)
            {
                if(book_name[title][author]== search_book)
                {
                    found = true;
                    cout<<"Book found!\n";
                    cout<<search_book;
                    break;
                }
            }
            if(found)
                break;
        }
        if(!found)
            cout<<"Book not found!\n";
    }
};

main()
{
    USER user;
    user.create_account();
    if(user.login())
    {
        class BOOKS bse;
            bse.add_books();
            bse.display_books();
            bse.remove_books();
            class LIBRARY bbit;
            bbit.search_book();
    }
}
