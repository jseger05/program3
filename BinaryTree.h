/*
    Copied from given BST files
    Adjusted to Book by J Seger
    11/6/24
*/

// Specification file for the BinaryTree class
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Book.h"
#include <iomanip>

class BinaryTree
{
	private:
		int size, longestTitle, longestAuthor, depth = 0;

		struct TreeNode
		{
			Book value;         // The value in the node
			TreeNode *left;    // Pointer to left child node
			TreeNode *right;   // Pointer to right child node
		};

		TreeNode *root;       // Pointer to the root node

		void insert(TreeNode *&, TreeNode *&, int);
		void destroySubTree(TreeNode *);
		void deleteNode(Book&, TreeNode *&);
		void makeDeletion(TreeNode *&);
		void displayInOrder(TreeNode *) const;
		void displayPreOrder(TreeNode *) const;
		void displayPostOrder(TreeNode *) const;
		void printTreeNodes(TreeNode*) const;

		TreeNode* checkNodeIndex(TreeNode*, int);
		std::string returnInOrder(TreeNode *) const;

	public:

		BinaryTree()		// Constructor
		{ root = NULL; }

	
		~BinaryTree()	// Destructor
		{ destroySubTree(root); }

		void insertNode(Book const&);
		bool searchNode(Book&);
		void remove(Book&);

		void displayInOrder() const
		{  displayInOrder(root); }

		void displayPreOrder() const
		{  displayPreOrder(root); }

		void displayPostOrder() const
		{  displayPostOrder(root); }

		//New stuff

		int getTreeSize(){ //not accurate
			return size;
		}
		int getTreeDepth(){
			return depth;
		}

		TreeNode* searchNodebyIndex(int num);

		void printTreeNodes(){
			printTreeNodes(root);
		}

		std::string returnInOrder() const
		{  return returnInOrder(root); }
};
#endif