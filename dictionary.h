// Project #3: Word Search Part B
// 
// Group Members: Lisa Byrne, Kaite O'Flaherty, Alek Tunik
//
// Description: Header file for the dictionary class
// Assumption: 
// Work done: added quicksort function

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector> 
#include "d_except.h"
#include "d_matrix.h"
#include "heap.h"

using namespace std;

class dictionary
// Read words from dictionary file and store in vector
// Print list of words from dictionary
// Sort words in alphabetical order
// Look up word in the dictionary to see if it exists
{
    public:
    void readDict();
    friend ostream& operator<<(ostream& ostr, const vector<string> words);
    void selectionSortWords();
    void quicksortWords(int left, int right);
    void heapSortWords();
    int partition(int left, int right);
    bool lookupWords(string target);
    int getSize();

    private:
    vector<string> _words;

}; // End dictionary class

void dictionary::readDict()
// Read words from dictionary file
{
    // Read file and add words line by line to 'words' vector
    string temp;
    ifstream infile;
    infile.open("Dictionary"); // Put path of file in quotes
    if(!infile)
    {
        cerr << "Couldn't open Dictionary file, check path" << endl;
    }
    while (getline (infile, temp))
    {
        _words.push_back(temp);
    }
} // End readDict

int dictionary::getSize()
// returns number of words in dictionary
{
    return _words.size();
}

ostream& operator<<(ostream& ostr, const vector<string> words)
// Overloaded cout operator to print word list
{
    int count = 0;
    for (int i = 0; i < words.size(); i++ )
    {
        ostr << words[i] << endl;
        count++;
    }
    return ostr;
} // End overloaded cout operator

void dictionary::selectionSortWords()
// Sort words using selection sort
{
    for (int i = 0; i < _words.size()-1; i++)
    {
        int min = i;
        for (int j = i+1; j < _words.size(); j++)
        {
            if (_words[j] < _words[min])
            {
                min = j;
            }
        }
        swap(_words[i], _words[min]);
    }
} // End sortWords

void dictionary::quicksortWords(int left, int right)
// Sort words using quicksort
{
    int s; // partitioning index
    if (left < right) // if there are atleast two elements in subarray
    {
        s = partition(left, right);
        // divide list into two and keep paritioning
        quicksortWords(left, s-1);
        quicksortWords(s+1, right);
    }
} // End quicksortWords

void dictionary::heapSortWords()
// Declares and populates heap with dictionary
// Sort dictionary using heapsort function
{
    heap<string> h;
    _words = h.heapsort(_words);
}

int dictionary::partition(int left, int right)
// Function that makes last element a pivot, and swaps all strings smaller than 
// pivot to left of pivot, and moves pivot element to its correct position
{
    string pivot = _words[right]; // rightmost element becomes pivot
    int i = left - 1; // tracks position for swap with pivot
    for (int j = left; j < right; j++)
    {
        // if the current string is lower in alphabet than pivot
        if (_words[j] < pivot) 
        {
            i++; // increment swap position
            swap(_words[i], _words[j]); // swap string lowest in alphabet left
        }
    }
    swap(_words[i+1], _words[right]); // swap pivot into the correct location
    return (i+1); // return new pivot index
} // End of partition

bool dictionary::lookupWords(string word)
// Lookup words using binary search
// If found, return true and print word
// Return false otherwise
{
    int first = 0;
    int last = _words.size();
    string target = word + "\r";

    while (first <= last)
    {
        int mid = first + (last-first)/2;
        string midVal = _words[mid];

        // search left half
        if (target > _words[mid])
        {
            first = mid + 1;
        }
        // search right half
        else if (target < _words[mid])
        {
            last = mid - 1;
        }
        else
        // Check if target word is found
        {
            // cout << "Houston, we've got eyes on the target: " << _words[mid] << endl;
            return true;
        }
    } // End while
    return false;
} // End lookupWords