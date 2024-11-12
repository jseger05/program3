/*
    Copied from given BST files
    Adjusted to Book by J Seger
    11/6/24
*/

// Implementation file for the BinaryTree class
#include <iostream>
#include "BinaryTree.h"
using namespace std;

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void BinaryTree::insertNode(Book const& num)
{
   TreeNode *newNode = NULL;	// Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->value = num;
   newNode->left = newNode->right = NULL;
   
   // Insert the node.
   insert(root, newNode, 1);

   if(num.getTitle().length() > longestTitle){
      longestTitle = num.getTitle().length();
   }
   if(num.getAuthor().length() > longestAuthor){
      longestAuthor = num.getAuthor().length();
   }
}

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode, int thisDepth)
{
   if(thisDepth > depth){
      depth = thisDepth;
   }
   //std::cout << "ThisDepth is " << thisDepth;

   if (nodePtr == NULL){
      nodePtr = newNode;      // Insert the node.
      size++;
      nodePtr->value.setIndex(size); //set new size as the new index                  
   }else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode, (thisDepth+1));     // Search the left branch
   else 
      insert(nodePtr->right, newNode, (thisDepth+1));    // Search the right branch
}



//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void BinaryTree::destroySubTree(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   
//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************

bool BinaryTree::searchNode(Book& num)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->value == num)
         return true;
      else if (num < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************

void BinaryTree::remove(Book& num)
{
   deleteNode(num, root);
}


//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************

void BinaryTree::deleteNode(Book& num, TreeNode *&nodePtr)
{
   if (num < nodePtr->value)
      deleteNode(num, nodePtr->left);
   else if (num > nodePtr->value)
      deleteNode(num, nodePtr->right);
   else
      makeDeletion(nodePtr);
}


//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************

void BinaryTree::makeDeletion(TreeNode *&nodePtr)
{
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr = NULL;

   if (nodePtr == NULL)
      cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else
   {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void BinaryTree::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
	  //cout << "\nLeft, nodePtr->left is " << nodePtr->left;
      displayInOrder(nodePtr->left);
	  //cout << "\nNode";
      cout << nodePtr->value << endl;
	  //cout << "\nRight, nodePtr->right is " << nodePtr->right;
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

void BinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

void BinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}

//Get size of tree function
/*int BinaryTree::getTreeSize(){
   return BinaryTree::size;
}*/

BinaryTree::TreeNode* BinaryTree::searchNodebyIndex(int num)
{
   TreeNode *nodePtr = root;

   /*std::cout << "\nStarting search with index " << num;
   while (nodePtr)
   {
      if ((nodePtr->value).getIndex() == num)
         {std::cout << "\nLocated index!"; return nodePtr; }
      else if (num < (nodePtr->value).getIndex())
         { std::cout << "\n" << num << " is less than current index " << (nodePtr->value).getIndex(); nodePtr = nodePtr->left;}
      else
         { std::cout << "\n" << num << " is greater than current index " << (nodePtr->value).getIndex(); nodePtr = nodePtr->right;}
   }
   std::cout << "\nCould not locate index";
   return nullptr;*/

   return checkNodeIndex(nodePtr, num);
}

BinaryTree::TreeNode* BinaryTree::checkNodeIndex(BinaryTree::TreeNode* nodePtr, int num){
   if(nodePtr){
      if(nodePtr->value.getIndex() == num){
         return nodePtr; //found the index
      }
      TreeNode* nodePtr2 = checkNodeIndex(nodePtr->left, num);
      if(nodePtr2){ //if it's not null...
         return nodePtr2; //We found it, so return that
      }
      TreeNode* nodePtr3 = checkNodeIndex(nodePtr->right, num);
      if(nodePtr3){ //if it's not null...
         return nodePtr3; //We found it, so return that
      }
   }
   return nullptr; //if we get here, we didn't find it
}

void BinaryTree::printTreeNodes(TreeNode *nodePtr) const{
   if (nodePtr)
   {
      cout << "\n" << nodePtr->value.getIndex() << " links to: "; 
      if(nodePtr->left)
         cout << nodePtr->left->value.getIndex(); 
      if(nodePtr->right)
         cout << " and " << nodePtr->right->value.getIndex();
      printTreeNodes(nodePtr->left);
      printTreeNodes(nodePtr->right);
   }
}

void BinaryTree::createNewTree(BinaryTree* newTree){   
   newTree = new BinaryTree;
   addNode(newTree, root);
}

void BinaryTree::addNode(BinaryTree* newTree, BinaryTree::TreeNode* nodePtr){
   if (nodePtr)
   {
      addNode(newTree, nodePtr->left);
      (*newTree).insertNode(nodePtr->value);
      addNode(newTree, nodePtr->right);
   }
}