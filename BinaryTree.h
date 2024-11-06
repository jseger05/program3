/*
    Copied from given BST files
    Adjusted to Book by J Seger
    11/6/24
*/

// Specification file for the BinaryTree class
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Book.h"

class BinaryTree
{
	private:
		struct TreeNode
		{
			Book value;         // The value in the node
			TreeNode *left;    // Pointer to left child node
			TreeNode *right;   // Pointer to right child node
		};

		TreeNode *root;       // Pointer to the root node

		void insert(TreeNode *&, TreeNode *&);
		void destroySubTree(TreeNode *);
		void deleteNode(Book&, TreeNode *&);
		void makeDeletion(TreeNode *&);
		void displayInOrder(TreeNode *) const;
		void displayPreOrder(TreeNode *) const;
		void displayPostOrder(TreeNode *) const;

	public:

		BinaryTree()		// Constructor
		{ root = NULL; }

	
		~BinaryTree()	// Destructor
		{ destroySubTree(root); }

		void insertNode(Book&);
		bool searchNode(Book&);
		void remove(Book&);

		void displayInOrder() const
		{  displayInOrder(root); }

		void displayPreOrder() const
		{  displayPreOrder(root); }

		void displayPostOrder() const
		{  displayPostOrder(root); }
};
#endif