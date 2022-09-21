// Program written by Jimmy Carrero
// The purpose of this program is to manage a library of books. This library can be generated automatically or books can be 
// manually added by the user. Books can also be removed or have their information displayed.
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Class for holding information on books.
class BookInfo
{
    protected:
        string author;
        string title;

    public:
        // Getters
        string get_author();
        string get_title();

        // Setters
        void set_author(string new_author);
        void set_title(string new_title);

        // Constructors
        BookInfo(); // Default constructor
        BookInfo(string author_value, string title_value); // Makes a book with the given author and title.
        BookInfo(string title_value); // Makes a book with the given Title and sets the author to "Unkown".

        // Methods
        string info(); // Method that returns both the Title and Author of the book in one string

};
// Class for holding updated books (has more than 1 edition).
class UpdatedBook : public BookInfo
{

    int edition;
    
    public:
        // Getters
        int get_edition();
        
        // Setters
        void set_edition(int new_edition);

        // Constructors
        UpdatedBook();
        UpdatedBook(string Author, string Title, int Edition);

        // Methods
        int ed(); // Method that returns the book's edition
};
// Class for holding a vector of books
class BookLibrary
{
    vector<UpdatedBook> library; //vector<type of value it holds> name of vector;

    public:
    // Getters
    vector<UpdatedBook> get_library();

    // Setters
    void set_library(vector<UpdatedBook> new_library);

    // Constructors
    BookLibrary(); // Default constructor that sets an empty library.
    BookLibrary(vector<UpdatedBook> lib_to_add); // Constructor that adds a vector to an existing BookLibrary vector.

    // Methods
    void addbook(UpdatedBook book_to_add); // Method that adds a book to the current vector.
    int manybooks(); // Method that returns how many books are in the current library.
    void print_info(); // Method that returns the information about all of the books in the library.
    friend void fill_library(BookLibrary& library_to_fill); // friend fucntion that will add books from a csv file.
    friend void erase_book(BookLibrary& where_book_is, int position_of_book);

};
// Prototype for function that will fill the library
void fill_library(BookLibrary& library_to_fill);
// Prototype for function that converts char to int
int digit_to_int(string c);
// Prototype for function that erases a book from a library (an element from a vector) given its position.
void erase_book(BookLibrary& where_book_is, int position_of_book);

int main()
{
    // Create a library
    BookLibrary MyLibrary;

    // Repeat these steps until the user logs out
    while (true)
    {
        char choice;
        cout << "Hello there, welcome to your virtual library. Here are your options: " << endl;
        cout << "1. Type \'G\' to generate a library of a specified size (requires the file \"books.csv\" to be located in the same diretory as the program)." << endl;
        cout << "2. Type \'A\' to add a book to your library." << endl;
        cout << "3. Type \'R\' to remove a book from your library (requires ISBN or book name)." << endl;
        cout << "4. Type \'P\' to display the information of the current books in your library." << endl;
        cout << "5. Type \'Q\' to quit the program." << endl;

        // variable that holds the user's choice
        cin >> choice;
        if(choice == 'Q' || choice == 'q')
        {
            cout << "Thanks for choosing our virtual library. Have a nice day!" << endl;
            break;
        }
        else if (choice == 'G' || choice == 'g')
        {
            fill_library(MyLibrary);
            cout << "Your library has been filled." << endl << endl << endl;
        }
        else if (choice == 'A' || choice == 'a')
        {
            // Book fro holding the info that is going to be passed to library
            UpdatedBook tmpbook;
            string tmp_author, tmp_title;
            int tmp_edition;

            // Ask user for book title and assign it to temp variable
            cout << "What is the title of the book you wish to add to your library?" << endl;
            cin >> tmp_title;
            // Ask user for book author and assign it to temp variable
            cout << "Who is the book's author?" << endl;
            cin >> tmp_author;
            // Ask user for book edition (ISBN) and assign it to temp variable
            cout << "What is the books edition (ISBN)?" << endl;
            cin >> tmp_edition;

            // Set the given values to the temp book
            tmpbook.set_title(tmp_title);
            tmpbook.set_author(tmp_author);
            tmpbook.set_edition(tmp_edition);

            // Add the temp book to the actual library
            MyLibrary.addbook(tmpbook);
        }
        else if (choice == 'R' || choice == 'r')
        {
            char choice_2;
            int position;
            // Function for removing elements from vectors
            cout << "If you know the position of the book within the library, type \'Y\'.\nIf not, type\'N\'."<<endl;
            cin >> choice_2;
            if (choice_2 == 'Y' || choice_2 == 'y')
            {
                cout << "What is the position of the book within the library?" << endl;
                cin >> position;
                erase_book(MyLibrary, position);
            }
            else
            {
                MyLibrary.print_info();
                cout << "Find your book in the list above and take note of its position (the number after the word book)."<< endl;
                erase_book(MyLibrary, position);    
            }
        }
        else if (choice == 'P' || choice == 'p')
        {
            MyLibrary.print_info();
        }
    }
    return 0;
}

// Getters
string BookInfo::get_author()
{
    return author;
}
string BookInfo::get_title()
{
    return title;
}
int UpdatedBook::get_edition()
{
    return edition;
}
vector<UpdatedBook> BookLibrary::get_library()
{
    return library;
}
        
// Setters
void BookInfo::set_author(string new_author)
{
    author = new_author;
}
void BookInfo::set_title(string new_title)
{
    title = new_title;
}
void UpdatedBook::set_edition(int new_edition)
{
    edition = new_edition;
}
void BookLibrary::set_library(vector<UpdatedBook> new_library)
{
    library = new_library;
}

// Constructors
BookInfo::BookInfo()
{
    author = "Unkown";
    title = "Unkown";
}
BookInfo::BookInfo(string author_value, string title_value) // Makes a book with the given author and title.
{
    author = author_value;
    title = title_value;
}
BookInfo::BookInfo(string title_value) // Makes a book with the given Title and sets the author to "Unkown".
{
    author = "Unkown";
    title = title_value;
}
UpdatedBook::UpdatedBook() // Default constructor
{
    author = "Unknown";
    title = "Unknown";
    edition = 0;
}
UpdatedBook::UpdatedBook(string author_value, string title_value, int edition_value) // Makes a book with the given information.
{
    author = author_value;
    title = title_value;
    edition = edition_value;
}
BookLibrary::BookLibrary() // Default constructor that sets an empty library.
{
    // This is empty because the vector library is empty by default, no need to construct it as such (see line 56 of this code).
}
BookLibrary::BookLibrary(vector<UpdatedBook> lib_to_add) // Constructor that adds a vector to an existing BookLibrary vector.
{
    library.insert(library.end(), lib_to_add.begin(), lib_to_add.end());
}

// Methods
string BookInfo::info() // Method that returns both the Title and Author of the book in one string
{
    string full_info = author + ": " + title;
    return full_info;
}
int UpdatedBook::ed() // Method that returns the book's edition
{
    return edition;
}
void BookLibrary::addbook(UpdatedBook book_to_add) // Method that adds a book to the current vector.
{
    library.push_back(book_to_add);
}
int BookLibrary::manybooks() // Method that returns how many books are in the current library.
{
    return (library.size());
}
void BookLibrary::print_info() // Method that returns the information about all of the books in the library.
{
    for (int i = 0; i < library.size(); i++)
    {
        cout << "Book " << i + 1 << ": " << library.at(i).get_title() << ", by " << library.at(i).get_author() << ", edition " << library.at(i).get_edition() << "." << endl;
    }
}

// Function definitions
void fill_library(BookLibrary& library_to_fill) // Function for filling a library from a given csv file
{
    // Variable that hold the ammount of books that will be added to the library
    int manybooks = 0;

    // Ask the user how many books he wants to add to the library
    cout << "How many books do you want to add to the library?" << endl;

    // Assign that value to manybooks
    cin >> manybooks;

    // Create an object for holding the file we want to read from
    ifstream bookfile;

    // open books.csv or create it if it doesnt exist
    bookfile.open("books.csv");

    // Variable where we are going to store the current line of the csv file
    string line = "";

    // Get rid of the first line (containing only headers)
    getline(bookfile, line);

    // while there are lines in the csv file, keep getting them (need to change this to occur a limited number of times as there are over 200K books in the provided file)
    for(int i = 0; i < manybooks; i++)
    {
        // Get the next line from the file
        getline(bookfile, line);

        // Temporary bbok for holding values that will be passed to the actual book library
        UpdatedBook tmp_book;

        // Holds book ISBN (string version), title and author
        string string_ISBN, title, author;
        // Holds the ISBN once it has been changed from string to int
        int ISBN;

        // stringstream object named inputStream that was constructed with "line", as an argument.
        stringstream inputString(line);

        // Getting editionn (ISBN), title and author and save those values to their respective variables
        getline(inputString, string_ISBN, ';');
        getline(inputString, title, ';');
        getline(inputString, author, ';');

        // Change the ISBN string to an int type string
        ISBN = digit_to_int(string_ISBN);  // A logic error is being caused because the csv file has " before and after the ISBN value and the function does not know how to deal with that

        // Save those values ina tmp book that will later be passed on to the actual library
        tmp_book.set_edition(ISBN);
        tmp_book.set_title(title);
        tmp_book.set_author(author);

        // Assign those values to the objects in the vector
        library_to_fill.library.push_back(tmp_book);

        // Reset the current line from memory in preparation for the next one
        line = "";
    }
    // Close the bookfile
    bookfile.close();
}
int digit_to_int(string c) // Function that removes the " character from a string (can be modified to delete any character) and return the numeric value
{
    // Remove any instance of the " character
    c.erase(remove(c.begin(), c.end(), '"'), c.end());
    // int for holding the converted string of numbers
    int x;
    // Convert them via this dark magic that I have no idea how it works, but it does so I am not complaining
    stringstream degree(c);
    // Assign the dark magic value to x
    degree >> x;
    // Self explainatory
    return(x);
}
void erase_book(BookLibrary& where_book_is, int position_of_book) // Function that erases a book from a library (an element from a vector) given its position.
{
    where_book_is.library.erase(where_book_is.library.begin() + (position_of_book - 1));
}