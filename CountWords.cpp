/**----------------------------------------------------------------------------
FileName: CountWords.cpp
Author: Stephen Deguchi
Student ID#: 1672539
1/8/17
Main for word counter program

 *Input: Input will come from characters read in from cin

 *Output: The output will contain a printout of each word in the WordTree
    storage container including the frequency of the word

 *Usage: The filename to be counted by the word counter is given to cin.
    The program will read from cin and count each word disregarding
    capitalization  and print each word out including the count

    -apostrophes will be removed from beginning and ends of words
	 -two apostrophes signify the end of a word eg. don''t counts "don"
	  and "t" as separate words
	 -numbers will not be included in words eg. 5th will be counted as "th"

 *Assumptions: -Words in the text file are spelled correctly, program will
                    not check spelling
               -The cin contains a valid text file

 *Description of algorithms and variables:
    -WordCount: WordTree containing the counted words
    -word: word being added to the tree
    -WordNode: node in WordTree containing the word data, count and pointers
        to other sibling WordNodes
*/
#include <iostream>
#include "WordTree.h"

using namespace std;

int main() {

   //WordTree to store word count
   WordTree wordcount;

   //string to add characters from cin
   string word = "";

	//read from cin one character at a time
   while (!cin.eof()) {

	   //get a character form cin
      char c;
      cin.get(c);
      tolower(c);

		//current character is a letter or apostrophe, add it to word
      if (isalpha(c) || c == '\'') {
         word.push_back(c);

	      //remove apostrophe from beginning of word
	      if (word.at(0) == '\'') {
		      word.erase(0, 1);
	      }

			//add current word if word contains two consecutive apostrophes
         if (word.length() > 1 && word.at(word.length() - 2) == '\'' && c == '\'') {
               word.erase(word.length() - 2, 2);

	         //add word after removing apostrophes
            if (word != "") {
               wordcount.Add(word);
               word = "";
            }
         }
      }
	   //current character is not a letter or apostrophe
      else {
         if (word != "") {

            //check end of word for apostrophe
            if (word != "" && word.at(word.length() - 1) == '\'') {
               word.erase(word.length() - 1, 1);
            }

            //if "word" contains letters, add to WordTree
            if (word != "") {
               wordcount.Add(word);
	            word = "";
            }
         }
      }
   }

   //print out the words in the text file and their word count
   cout << wordcount << endl;

	//count total number of words
   cout << "Total number of words: " << wordcount.NumWords() << endl;

   return 0;
}