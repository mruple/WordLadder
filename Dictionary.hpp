//
//  Dictionary.hpp
//  Assignment2
//
//  Created by Mitchell Ruple on 9/23/21.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

class Dictionary
{
private:
    std::vector<std::string> word; //Dictionary.txt words
    std::vector<std::string> setWords; //possible target words
    std::string target;
    long int length; //length of words
    
public:
    inline Dictionary();
    inline Dictionary(const Dictionary&);
    inline ~Dictionary(); //delete the
    
    inline void setWord(std::string);
    inline void setTarget(std::string); //sets the string to the target member
    inline void setLength(long int); //sets the length to the private member length
    inline void wordFind();
    inline void search(const std::string&, const long int, std::vector<std::string>&); //search for the one letter difference words
    inline bool compare(std::string, std::string);
    inline bool strWord(std::string,std::string);
    inline std::vector<std::string> getWord()
    {
        return word;
    }
};

#endif /* Dictionary_hpp */
