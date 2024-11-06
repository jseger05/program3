/*
    Book class header file
    10/11/24
    J Seger
*/

#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

enum class CompareBy{
    TitleFront,
    TitleBack,
    AuthorFront,
    AuthorBack,
    YearFront,
    YearBack
};

class Book{
    private:
        //attributes
        std::string title;
        std::string author;
        int year;
        static CompareBy thing;
    public:
        //constructors
        Book();
        Book(std::string, std::string, int);

        //Getters
        std::string getTitle();
        std::string getAuthor();
        int getYear();

        //Setters
        void setTitle(std::string);
        void setAuthor(std::string);
        void setYear(int);

        //Used for comparisons by author name
        std::string lastWord(std::string);

        //Operator overloads
        friend std::ostream& operator<<(std::ostream& out, Book const& c);
        bool operator<(Book&);
        bool operator>(Book&);
        bool operator==(Book&);
};

#endif