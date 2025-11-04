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
using std::size_t;

bool checkset(vector<Bridge> &set,
			  Bridge curr)
{
// need to do some table shit here
	for( auto bridge : set){
		if(bridge[1] == curr[1])
			return false;
		if(bridge[0] == curr[0])
			return false;
  	if (bridge[0] < curr[0] && bridge[1] > curr[1])
 			return false;
		if (bridge[0] > curr[0] && bridge[1] < curr[1])
  		return false;
	}
	return true;
}

int sum_of(vector<Bridge>& set)
{
	if(set.size() == 0)
		return 0;
	int sum = 0;	
	for(auto i : set){
		sum+=i[2];
	}
	return sum;
}
	

void bridgeRecur(size_t i, 
				const vector<Bridge>& bridges, 							
				int& maxes, 
				vector<Bridge>& subset) 
{
  // base case
	// checks for a higher max and updates if one is found
  if (i == bridges.size()) {
  int sum = sum_of(subset);
    if(sum > maxes)
		  maxes = sum;
		return;   
    }
    
		// check if the current bridge can be added,
		// if it can, add to subset and recurse
		if(checkset(subset, bridges[i])){
    	subset.push_back(bridges[i]);
    	bridgeRecur(i+1, bridges, maxes, subset);
		subset.pop_back();
    }
    // recurse without including the current bridge 
    bridgeRecur(i+1, bridges, maxes, subset);
}




int bridges(int w, 
			int e,
			const vector<Bridge> & bridges){
	int max = 0;
	vector<Bridge> subsets = {};
	bridgeRecur(size_t(0), bridges, max, subsets);
	return max;
}
