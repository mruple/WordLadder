//
//  main.cpp
//  Assignment2
//
//  Created by Mitchell Ruple on 9/16/21.
//

#include <iostream>
#include "Dictionary.cpp"
#include <fstream>
#include <assert.h>
#include <vector>



void getData(Dictionary& word)
{
    
    std::ifstream infile;
    std::string letter;
    long int size;
    
    infile.open("Dictionary.txt");
    while(!infile.eof())
    {
        getline(infile, letter);
        infile >> letter;
        word.setWord(letter);
        size = letter.length();
        word.setLength(size);
       
    }
    
    
}



int main() {
    Dictionary word;
    short int choice;
    std::string first;
    std::string first1;
    bool flag = 0;
    std::cout << "To enter the Dictionary text file please press 1: ";
    std::cin >> choice;
    assert(choice == 1);
    getData(word);
    
    while(!flag)
    {
    std::cout << "Please enter the first word: ";
    std::cin >> first;
    std::cout << "Please enter the target word: ";
    std::cin >> first1;
    word.setTarget(first1);
        if(word.compare(first, first1) != 1)
            {
                std::cout << "Please enter two words with the same length";
            }
        else
            {
                flag = 1;
            }
    
    }
    
    std::vector<std::string> Ladder;
    
    word.search(first, first.length(), Ladder);
    
    
    
    
    return 0;
}
