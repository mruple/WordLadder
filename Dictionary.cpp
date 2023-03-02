//
//  Dictionary.cpp
//  Assignment2
//
//  Created by Mitchell Ruple on 9/23/21.
//

#include "Dictionary.hpp"
#include <algorithm>


inline Dictionary::Dictionary()
{
    //target = "";
    //length = 0;
}
inline Dictionary::Dictionary(const Dictionary&)
{
}
inline Dictionary::~Dictionary()
{
}//delete the

inline void Dictionary::setWord(std::string Word)
{
    word.push_back(Word);
    
}
inline void Dictionary::setTarget(std::string settarg)
{
    target = settarg;
}//sets the string to the target member
inline void Dictionary::setLength(long int size)
{
    length = size;
}//sets the length to the private member length
inline void Dictionary::wordFind()
{
   

    for(int i=0; i<word.size(); i++)
    {
        if(word[i].length() == target.length())
        {
            setWords.push_back(word[i]);
            
        }
    }
    
}

inline void Dictionary::search(const std::string& searchWord, const long int length, std::vector<std::string>& ladder)
{
    if (setWords.empty())
    {
        wordFind();
    }
    ladder.push_back(searchWord); //puts the start word on ladder

    //Search the dictionary
    for (auto it = setWords.begin(); it != setWords.end(); ++it)
    {
        //making sure the word we found in the dictionary not already in the ladder
        if (std::find(ladder.begin(), ladder.end(), *it) == ladder.end())
        {
            //compares the lengths of the two words (startword and the word in the dictionary)
            if (strWord(ladder.back(), *it))
            {
                std::vector<std::vector<std::string> > ladderList; // vector of ladders with the potential ladders to solve
                //if theres an one letter difference

                std::vector<std::string> tempLadder; // single possible ladder
                tempLadder.reserve(ladder.size()); // reserve memory for tempLadder to avoid unnecessary reallocation
                tempLadder = ladder; // set it to the ladder passed into the function

                ladderList.push_back(tempLadder); //add possible ladder to the list of the possible ladders

                for (auto& possibleLadder : ladderList) // iterate through list of possible ladders
                {
                    //if last entry of possible ladder is one letter off of the target
                    if (strWord(ladder.back(), target))
                    {
                        ladder.push_back(target); //add the target to end of the ladder
                        for (auto& word : ladder)
                        {
                            std::cout << word << std::endl; // print ladder
                        }
                        return;
                    }
                    else
                    {
                        search(*it, length, possibleLadder); //recurse with vector of possible ladders
                    }
                }

                return;
            }
        }
    }
} 
inline bool Dictionary::compare(std::string first, std::string second)
{
    if(first.length() == second.length())
    {
        return 1;
    }
    return 0;
}
inline bool Dictionary::strWord(std::string vectStr, std::string temptarg)
{
    int count = 0;
    for(int i=0; i < vectStr.length(); i++)
    {
        if(vectStr[i] == temptarg[i])
        {
            count++;
        }
    }
    if(count > 1)
    {
        return true;
    }else
    {
        return false;
        
    }
    
}

