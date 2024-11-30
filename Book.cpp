/*
    Book class implementation
    10/11/24
    J Seger
    Edited 11/6 for different comparisons
*/

#include "Book.h"

CompareBy Book::thing = CompareBy::AuthorFront; //default comparison

Book::Book(){
    title = "Title";
    author = "Author";
    year = 1900;
    index = -1;
}

Book::Book(std::string t, std::string a, int y){
    title = t;
    author = a;
    year = y;
    index = -1;
}

std::string Book::getTitle() const{
    return title;
}

std::string Book::getAuthor() const{
    return author;
}

int Book::getYear() const{
    return year;
}

int Book::getIndex() const{
    return index;
}

void Book::setTitle(std::string x){
    title = x;
}

void Book::setAuthor(std::string x){
    author = x;
}

void Book::setYear(int x){
    year = x;
}

void Book::setIndex(int x){
    index = x;
}

//friend of Book
std::ostream& operator<<(std::ostream& out, Book const& c)
{
    if(c.index >= 10)
        out << c.index << ": " << c.title << std::string(50-c.title.length(), ' ') << " by " << c.author << std::string(30-c.author.length(), ' ') << " (" << c.year << ")";
    else
        out << "0" << c.index << ": " << c.title << std::string(50-c.title.length(), ' ') << " by " << c.author << std::string(30-c.author.length(), ' ') << " (" << c.year << ")";
    return out;
}
//Max title space 50, max author space 30

bool Book::operator<(Book& b){
    switch(thing){
        case CompareBy::TitleFront: return (b.getTitle() > title); break;
        case CompareBy::TitleBack: return (b.getTitle() < title); break;
        case CompareBy::AuthorFront: return (b.lastWord(b.getAuthor()) > b.lastWord(author)); break; //swapping signs to make it sort A - Z
        case CompareBy::AuthorBack: return (b.lastWord(b.getAuthor()) < b.lastWord(author)); break;
        case CompareBy::YearFront: return (b.getYear() > year); break;
        case CompareBy::YearBack: return (b.getYear() < year); break;
        default: return false; break;
    }
}
bool Book::operator>(Book& b){
    switch(thing){
        case CompareBy::TitleFront: return (b.getTitle() > title); break;
        case CompareBy::TitleBack: return (b.getTitle() < title); break;
        case CompareBy::AuthorFront: return (b.lastWord(b.getAuthor()) < b.lastWord(author)); break; //swapping signs to make it sort A - Z
        case CompareBy::AuthorBack: return (b.lastWord(b.getAuthor()) < b.lastWord(author)); break;
        case CompareBy::YearFront: return (b.getYear() > year); break;
        case CompareBy::YearBack: return (b.getYear() < year); break;
        default: return false; break;
    }
}
bool Book::operator==(Book& b){
    switch(thing){
        case CompareBy::TitleFront:
        case CompareBy::TitleBack: return (b.getTitle() == title); break;
        case CompareBy::AuthorFront: 
        case CompareBy::AuthorBack: return (b.lastWord(b.getAuthor()) == b.lastWord(author)); break;
        case CompareBy::YearFront: 
        case CompareBy::YearBack: return (b.getYear() == year); break;
        default: return false; break;
    }
}

//If Author has firstname, sort by lastname
//If not, sort by whatever name is in list
std::string Book::lastWord(std::string x){
    if (x.find_last_of(' ') != std::string::npos){
        //std::cout << "\nLast word of " << x << " is " << x.substr(x.find_last_of(' ') + 1);
        return x.substr(x.find_last_of(' ') + 1);
    }
    return x;
}