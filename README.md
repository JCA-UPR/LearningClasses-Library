# LearningClasses-Library
Define a class called BookInfo that is an abstract data type (ADT) to store information about a book. Your class must have two fields of type string, the first to store the author's name and the second to store the book title. Include the following member functions: a constructor to set the book title and author, a second constructor that sets the book title by passing it as a single parameter and the author to "unknown", and a method to get the author and title concatenated into a single C++ string. Write a driver program to test your class by creating some book objects and printing them using your member functions.

Define a new class called UpdatedBook that inherits the BookInfo class created earlier. This new class must contain an integer field for the edition number of the book, a constructor to create the UpdatedBook object accepting as input the author, title and edition number of the book, and a getter method to return the edition number.

Define another class called BookLibrary. This class must contain a field that stores a vector (review this Prog. I topic in section 8.3 of the class book) of UpdatedBook objects. Your BookLibrary class must have the following methods: a default constructor; a constructor that accepts an existing vector of UpdatedBook objects; a method to add a book to the library; a method to get the number of books in the library; and a method to print information about each book in the library. Write a test program that creates a library and a few books. Your program should add and remove these books from the library and print information about the books in the library.

Remarks: 

Upload your solution in a single cpp file.
Use headers with your file information and description. Make a short description of each class before declaring it and document how to use it. 
Use at least 10 example books, if you want real examples, you can get them from the following "Dataset": https://www.kaggle.com/datasets/saurabhbagchi/books-dataset, extract only the requested information.
Your solution will be compared with that of your peers and Internet sites. It is recommended to write it from scratch in your own style.  

Translated with www.DeepL.com/Translator (free version)
