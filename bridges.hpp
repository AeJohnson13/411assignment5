// bridges.hpp
// Alex E. Johnson
//
// For CS 411 Fall 2025
// Prototypes for bridges.cpp
// Used in Assignemnt 2, Exercies A

#ifndef FILE_BRIDGES_HPP_INCLUDED
#define FILE_BRIDGES_HPP_INCLUDED

#include <vector> 
// for std::vector


// each Bridge is represented by a vector of integers, 
// will always have size 3
using Bridge = std::vector<int>;

// subsets
//  Implementation in source file
std::vector<std::vector<Bridge> > subsets(const std::vector<Bridge> &bridges);

//  checkset
//  Implementation in source file
bool checkset(std::vector<Bridge> & set);

//  findMax
//  Implementation in source file
int findMax(std::vector<std::vector<Bridge> > possibleSets);


// bridges
// Implementation in source file
int bridges(int w,
            int e,
            const std::vector<Bridge> & bridges);

#endif //#ifndef FILE_BRIDGES_HPP_INCLUDED
