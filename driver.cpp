/*
    Driver code for Library BST program (CSC 1310 Program 3)
    J Seger
    11/6/24
*/

#include "BinaryTree.h"
#include <fstream>

void importFile(std::string, BinaryTree*); //imports books in order from file
void exportFile(std::string, BinaryTree*); //saves books in new order to file
void inpVer(int& out, int lowerBound, int upperBound, std::string qText = "Enter choice:   ", std::string invText = "Input invalid.");
void addBook(BinaryTree*);
//void editBook(BinaryTree&);
void removeBook(BinaryTree*);
void reSort(BinaryTree*);

int main(){

    Book::thing = CompareBy::AuthorFront;
    BinaryTree* library = nullptr;
    library = new BinaryTree;
    std::string inFilename = "bookData.txt";
    std::string outFilename = "outFile.txt";
    importFile(inFilename, library);

    bool done = false;
    int choice = -1;

    std::cout << "\n\nWelcome to your Library! (Now with BST!)";
    while(!done){
        std::cout << "\n\n";
        (*library).displayInOrder();
        std::cout << "\nTree depth is: " << (*library).getTreeDepth();

        //Temp
        (*library).printTreeNodes();

        std::cout << "\n\nWhat would you like to do?";
        std::cout << "\n\t1. Add book";
        std::cout << "\n\t2. Remove book";
        std::cout << "\n\t3. Re-sort list";
        std::cout << "\n\t4. Save and exit program";

        inpVer(choice, 1, 5);

        switch(choice){
            case 1: addBook(library); break;
            case 2: removeBook(library); break;
            case 3: reSort(library); break;
            case 4: exportFile(outFilename, library); done = true; break;
            default: break;
        }
    }

    std::cout << "\n\nGood-bye!";
    delete library;    

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

void importFile(std::string inFile, BinaryTree* library){
    std::cout << "\nImporting from " << inFile << "... ";
    std::ifstream InFile(inFile);
    std::string tempString;
    while(getline(InFile, tempString)){
        std::string title = tempString.substr(0, tempString.find(';')); //grab the title
        tempString.erase(0, tempString.find(';')+1); //erase the title

        std::string author = tempString.substr(0, tempString.find(';')); //repeat for author
        tempString.erase(0, tempString.find(';')+1);

        (*library).insertNode(Book(title, author, stoi(tempString))); //what's left in tempString is the year
    }
    InFile.close();
}
void exportFile(std::string outFile, BinaryTree* library){
    std::cout << "2";
}
void addBook(BinaryTree* library){
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

    (*library).insertNode(Book(title, author, year));
}
/*void editBook(BinaryTree& library){
    std::string bookToEdit;
    std::cout << "\nWhich book would you like to edit? (index)";
    int editChoice;
    inpVer(editChoice, 1, library.getTreeSize());
    std::cout << "What would you like to change? Title (1), Author (2), or Year(3)";
    int attChoice;
    inpVer(attChoice, 1, 3);

}*/
void removeBook(BinaryTree* library){
    std::cout << "\nWhich book would you like to remove? (index)";
    int removeChoice;
    inpVer(removeChoice, 1, (*library).getTreeSize());
    (*library).remove(((*library).searchNodebyIndex(removeChoice))->value);
}
void reSort(BinaryTree* library){
    std::cout << "\nRe-sort by...";
    std::cout << "\n\t1. Title A-Z";
    std::cout << "\n\t2. Title Z-A";
    std::cout << "\n\t3. Author A-Z";
    std::cout << "\n\t4. Author Z-A";
    std::cout << "\n\t5. Year Lo-Hi";
    std::cout << "\n\t6. Year Hi-Lo";
    int sortchoice;
    inpVer(sortchoice, 1, 6);
    switch(sortchoice){ //changes sorting criteria to user selection
        case 1: Book::thing = CompareBy::TitleFront; break;
        case 2: Book::thing = CompareBy::TitleBack; break;
        case 3: Book::thing = CompareBy::AuthorFront; break;
        case 4: Book::thing = CompareBy::AuthorBack; break;
        case 5: Book::thing = CompareBy::YearFront; break;
        case 6: Book::thing = CompareBy::YearBack; break;
        default: Book::thing = CompareBy::AuthorFront; break;
    }
    BinaryTree* library2 = nullptr;
    (*library).createNewTree(library2);
    delete library;
    library = library2;
}