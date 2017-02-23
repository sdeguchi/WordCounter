/**----------------------------------------------------------------------------
FileName: WordTree.h
Author: Stephen Deguchi
Student ID#: 1672539
1/8/17
Storage and data container for the words that are being counted in the ifstream
*/

#ifndef WORDCOUNTER_WORDTREE_H
#define WORDCOUNTER_WORDTREE_H

#include<string>

using namespace std;

class WordTree {
//-----------------------------------------------------------------------------
// operator<<
/**
 * Overload the << operator for the WordTree class
 * Prints out all the WordNodes in the tree
 * @param output : ostream
 * @param tree : WordTree : the tree will be printed
 * @return ostream output
 */
	friend ostream &operator<<(ostream &, const WordTree &);

public:
//-----------------------------------------------------------------------------
// Constructor
/**
 * Default constructor for WordTree class, starts out empty with nothing in its
 * root.
 */
	WordTree();
//-----------------------------------------------------------------------------
// Destructor
/**
 * Destructor for the WordTree class, calls on MakeEmpty recursive helper to
 * delete all the nodes in the tree and make them null
 */
	~WordTree();
//-----------------------------------------------------------------------------
// Add
/**
 * Takes a word and adds it to the tree or increments the count for a word if
 * it is already in the tree
 * @param word : word that is being added to the tree
 */
	void Add(const string);
//-----------------------------------------------------------------------------
// NumWords
/**
 * Counts the number of words in the tree, calls recursive funtion NumWords
 * Helper
 * @return int: count of words in tree
 */
	int NumWords() const;
//-----------------------------------------------------------------------------
// display
/**
 * prints out the tree, calls on DisplayHelper recusive function to print out
 * each node in order
 * @param output : ostream : print out each node
 */
	void display(ostream &) const;

private:
	//data storage for each word and count
	struct WordNode {

		//word that has been counted
		string word;
		//number of times word has appeared
		int count;
		//WordNode with word that comes before current WordNode
		WordNode *left;
		//WordNode with word that comes after current WordNode
		WordNode *right;

		//WordNode convenience constructor
		WordNode(string word):word(word),count(1),left(nullptr),right(nullptr){}
	};

	//first word in the tree
	WordNode *root;
//-----------------------------------------------------------------------------
// displayHelper
/**
 * recursive helper o print out the tree
 * @param node : pointer to current node in the WordTree
 * @param output : ostream : print out of the node
 * Precondition: root of tree must not be empty to print out a ndoe
 */
	void displayHelper(WordNode *, ostream &) const;
//-----------------------------------------------------------------------------
// AddHelper
/**
 * recursive helper function for Add that sets the new position of the WordNode
 * @param node : pointer to the WordNode being checked for the word to add
 * @param word : word being added to the tree
 */
	void AddHelper(WordNode *&, const string);
//-----------------------------------------------------------------------------
// NumWordsHelper
/**
 * recursive helper function for NumWords
 * @param node: pointer to the current WordNode being counted
 * @return int: 1 or 0 if the node is null or not
 */
	int NumWordsHelper(WordNode *) const;
//-----------------------------------------------------------------------------
// MakeEmptyHelper
/**
 * recursive helper function for MakeEmpty
 * @param node: pointer to a WordNode of the current node to delete
 */
	void MakeEmptyHelper(WordNode *);
};

#endif //WORDCOUNTER_WORDTREE_H
