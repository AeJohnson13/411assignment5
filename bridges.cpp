// bridges.cpp
// Alex E. Johnson
// 2025-10-31
//
// For CS 411 Fall 2025
// Defines functinos for bridges.hpp
// Used in Assignemnt 5, Exercies A
// Tested with bridge_test2.cpp

#include "./bridges.hpp"

#include <vector>
using std::vector;


// bridges
//      given the integers representing the number of cities on the west
//      and east bank, and a vector of descriptions of bridges. Returns the 
//      maximum total toll that can be collected from a legal set of bridges
int bridges(int w,
            int e,
            const vector<Bridge> &bridges)
{
// base case
if(w == 1 && e == 1)
  return bridges[1][2]
    
//recursive case


}
