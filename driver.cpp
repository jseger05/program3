/*
    Driver code for Library BST program (CSC 1310 Program 3)
    J Seger
    11/6/24
*/

#include "BinaryTree.h"

void importFile(std::string, BinaryTree&); //imports books in order from file
void exportFile(std::string, BinaryTree&); //saves books in new order to file
void inpVer(int& out, int lowerBound, int upperBound, std::string qText = "Enter choice:   ", std::string invText = "Input invalid.");
void addBook(BinaryTree&);
void editBook(BinaryTree&);
void removeBook(BinaryTree&);
void reSort(BinaryTree&);

int main(){

    BinaryTree library;
    std::string inFilename = "bookData.txt";
    std::string outFilename = "outFile.txt";
    importFile(inFilename, library);

    bool done = false;
    int choice = -1;

    std::cout << "\n\nWelcome to your Library! (Now with BST!)";
    while(!done){
        std::cout << "\n\n";
        library.displayInOrder();

        std::cout << "\n\nWhat would you like to do?";
        std::cout << "\n\t1. Add book";
        std::cout << "\n\t2. Edit book";
        std::cout << "\n\t3. Remove book";
        std::cout << "\n\t4. Re-sort list";
        std::cout << "\n\t5. Save and exit program";

        inpVer(choice, 1, 5);

        switch(choice){
            case 1: addBook(library); break;
            case 2: editBook(library); break;
            case 3: removeBook(library); break;
            case 4: reSort(library); break;
            case 5: exportFile(outFilename, library); done = true; break;
            default: break;
        }
    }

    std::cout << "\n\nGood-bye!";

    return 0;
}

/*
    Name:       inpVer
    Args:       int& out, int lowerBound, int upperBound, string qText, string invText
    Purpose:    Take user input and ensure it is an int that is within given bounds. Takes optional prompt and invalid strings to personalize
*/
//Only for int input verification!
void inpVer(int& out, int lowerBound, int upperBound, std::string qText, std::string invText){
    bool works;
    do{ 
        works = false;
        std::cout << "\n" << qText;
        std::cin >> out;
        if(std::cin.fail()){ 
            std::cin.clear();
            std::cin.ignore(100000000000000000, '\n'); 
            std::cout << "\n" << invText;
        }else if(out > upperBound || out < lowerBound){
            std::cout << "\n" << invText;
        }else{
            works = true;
        }
    }while(!works);
}

void importFile(std::string inFile, BinaryTree& library){
    std::cout << "1";
}
void exportFile(std::string outFile, BinaryTree& library){
    std::cout << "2";
}
void addBook(BinaryTree& library){
    std::string title, author;
    int year;
    
    std::cin.clear();
    std::cin.ignore(100000000000000000, '\n'); 
    std::cout << "\n\tWhat is the title of the new book? ";
    getline(std::cin, title);
    std::cout << "\n\tWho is the author of the new book? ";
    getline(std::cin, author);
    std::cout << "\n\tWhen was the new book published? ";
    std::cin >> year;

    library.insertNode(Book(title, author, year));
}
void editBook(BinaryTree& library){
    std::cout << "4";
}
void removeBook(BinaryTree& library){
    std::cout << "5";
}
void reSort(BinaryTree& library){
    std::cout << "6";
}