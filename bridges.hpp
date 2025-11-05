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
// [0] is west city # 
// [1] is east city #
// [2] is bridge toll value
using Bridge = std::vector<int>;


//  checkpair
//  Implementation in source file
bool checkpair(const Bridge& a,
			   const Bridge& b);

// bridges
// Implementation in source file
int bridges(int w,
            int e,
            const std::vector<Bridge> & bridges);

#endif //#ifndef FILE_BRIDGES_HPP_INCLUDED
