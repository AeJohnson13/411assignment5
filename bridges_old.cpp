// bridges_old.cpp
// Alex E. Johnson
// 2025-10-
//
// For CS 411 Fall 2025
// Defines functinos for bridges.hpp
// Used in Assignemnt 2, Exercies A

#include "./bridges.hpp"

#include <vector>
using std::vector;


//  subsets
//      given a vector of bridges will return a vector containing each
//      possible vector of bridges makeable from the initial vector 
//      
//      this function is based on the subset function posted here: 
//                              https://www.geeksforgeeks.org/dsa/backtracking-to-find-all-subsets/
vector<vector<Bridge> > subsets(const vector<Bridge> &bridges)
{
    int max = bridges.size();
    vector<vector<Bridge> > result;

    for (int i = 0; i < (1 << max); i++)
    {
        vector<Bridge> subset;

        for (int j = 0; j < max; j++)
        {

            if ((i & (1 << j)) != 0)
            { // bitwise bullshittery
                subset.push_back(bridges[j]);
            }
        }
        result.push_back(subset);
    }
    return result;
}

//  checkset
//      given a vector of bridges will return true if all vectors can be built
//      i.e. bridges aren't crossing and don't connect to the same city twice
bool checkset(vector<Bridge> &set)
{
    int n = set.size();
    for (int i = 0; i < n; i++)
    {
        Bridge bridge1 = set[i];
        for (int j = i + 1; j < n; j++)
        {
            Bridge bridge2 = set[j];
            if (bridge1[0] == bridge2[0])
                return false;
            if (bridge1[1] == bridge2[1])
                return false;
            if (bridge1[0] < bridge2[0] && bridge1[1] > bridge2[1])
                return false;
            if (bridge1[0] > bridge2[0] && bridge1[1] < bridge2[1])
                return false;
        }
    }
    return true;
}


//  findMax
//      given a vector of vector of bridges, will return the highest sum of 
//      bridge tolls for a single vector of bridges
int findMax(vector<vector<Bridge> > possibleSets)
{
    int maximum = 0;
    for (auto currentSet : possibleSets)
    {
        int Sum = 0;
        for (auto currentBridge : currentSet)
        {
            Sum = Sum + currentBridge[2];
        }
        if (Sum > maximum)
            maximum = Sum;
    }
    return maximum;
}


// bridges
//      given the integers representing the number of cities on the west
//      and east bank, and a vector of descriptions of bridges. Returns the 
//      maximum total toll that can be collected from a legal set of bridges
int bridges(int w,
            int e,
            const vector<Bridge> &bridges)
{

    vector<vector<Bridge> > allSubsets = subsets(bridges);

    vector<vector<Bridge> > possibleSets;

    for (auto currentSet : allSubsets)
    {
        if (checkset(currentSet))
        {
            possibleSets.push_back(currentSet);
        }
    }

    int ans = findMax(possibleSets);

    return ans;
}
