/**----------------------------------------------------------------------------
FileName: WordTree.cpp
Author: Stephen Deguchi
Student ID#: 1672539
1/8/17
Storage container for the words that are being counted in the ifstream
*/
#include "WordTree.h"
#include <iostream>
#include <iomanip>

//-----------------------------------------------------------------------------
// Constructor
/**
 * Default constructor for WordTree class, starts out empty with nothing in its
 * root.
 */
WordTree::WordTree() {

	//root of the tree
   root = nullptr;
}
//-----------------------------------------------------------------------------
// Destructor
/**
 * Destructor for the WordTree class, calls on MakeEmpty recursive helper to
 * delete all the nodes in the tree
 */
WordTree::~WordTree() {

   //empty out the tree
	MakeEmptyHelper(root);
}

//-----------------------------------------------------------------------------
// operator<<
/**
 * Overload the << operator for the WordTree class
 * Prints out all the WordNodes in the tree
 * @param output : ostream
 * @param tree : WordTree : the tree will be printed
 * @return ostream output
 */
ostream &operator<<(ostream &output, const WordTree &tree) {

   //display the nodes of the tree in alphabetical order
   tree.display(output);
   return output;
}
//-----------------------------------------------------------------------------
// display
/**
 * prints out the tree, calls on DisplayHelper recusive function to print out
 * each node in order
 * @param output : ostream : print out each node
 */
void WordTree::display(ostream &output) const {

   output << setw(24) << "word" << setw(24) << "count" << endl;

   //call recursive helper
   displayHelper(root, output);
}
//-----------------------------------------------------------------------------
// displayHelper
/**
 * recursive helper o print out the tree
 * @param node : pointer to current node in the WordTree
 * @param output : ostream : print out of the node
 * Precondition: root of tree must not be empty to print out a ndoe
 */
void WordTree::displayHelper(WordNode *node, ostream &output) const {

   //node is empty
   if (node == nullptr) {
      return;
   }
   //print out left subtree
   displayHelper(node->left, output);

   //print out current node
   output << setw(24) << node->word << setw(24) << node->count << endl;

   //print out right subtree
   displayHelper(node->right, output);


}
//-----------------------------------------------------------------------------
// Add
/**
 * Takes a word and adds it to the tree or increments the count for a word if
 * it is already in the tree
 * @param word : word that is being added to the tree
 */
void WordTree::Add(const string word) {

   //call recursive helper
   AddHelper(root, word);
}
//-----------------------------------------------------------------------------
// AddHelper
/**
 * recursive helper function for Add that sets the new position of the WordNode
 * @param node : pointer to the WordNode being checked for the word to add
 * @param word : word being added to the tree
 */
void WordTree::AddHelper(WordNode *&node, const string word) {

   //word is not in the tree, create a new WordNode
   if (node == nullptr) {
      node = new WordNode(word);
      return;
   }
   //word is in the tree, increase the count
   else if (node->word.compare(word) == 0) {
      node->count++;
      return;
   }
   //word is less than current word, traverse left
   else if (node->word.compare(word) > 0) {
      return AddHelper(node->left, word);
   }
   //word is greater than current word, traverse right
   else {
      return AddHelper(node->right, word);
   }
}
//-----------------------------------------------------------------------------
// NumWords
/**
 * Counts the number of words in the tree, calls recursive funtion NumWords
 * Helper
 * @return int: count of words in tree
 */
int WordTree::NumWords() const {

	//call recursive helper
   return NumWordsHelper(root);
}
//-----------------------------------------------------------------------------
// NumWordsHelper
/**
 * recursive helper function for NumWords
 * @param node: pointer to the current WordNode being counted
 * @return int: 1 or 0 if the node is null or not
 */
int WordTree::NumWordsHelper(WordNode *node) const {
   if (node == nullptr)return 0;

	//add root, left subtree, and right subtree to count
   return 1 + NumWordsHelper(node->left) + NumWordsHelper(node->right);
}
//-----------------------------------------------------------------------------
// MakeEmptyHelper
/**
 * recursive helper function for MakeEmpty
 * @param node: pointer to a WordNode of the current node to delete
 */
void WordTree::MakeEmptyHelper(WordNode *node) {
   if (node == nullptr)return;

	//delete left subtree
   MakeEmptyHelper(node->left);

	//delete right subtree
   MakeEmptyHelper(node->right);

	//delete root
   delete node;
   node = nullptr;
}