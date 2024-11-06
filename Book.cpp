/*
    Book class implementation
    10/11/24
    J Seger
*/

#include "Book.h"

Book::Book(){
    title = "Title";
    author = "Author";
    year = 1900;
}

Book::Book(std::string t, std::string a, int y){
    title = t;
    author = a;
    year = y;
}

std::string Book::getTitle(){
    return title;
}

std::string Book::getAuthor(){
    return author;
}

int Book::getYear(){
    return year;
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

//friend of Book
std::ostream& operator<<(std::ostream& out, Book const& c)
{
    out << c.title << " by " << c.author << " (" << c.year << ")";
    return out;
}

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
        case CompareBy::AuthorFront: return (b.lastWord(b.getAuthor()) > b.lastWord(author)); break; //swapping signs to make it sort A - Z
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
    if (x.find(' ') != std::string::npos){
        return x.substr(x.find(' ') + 1);
    }
    return x;
}