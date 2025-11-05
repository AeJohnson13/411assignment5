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
#include <algorithm>
using std::sort;

// checkpair
// given two Bridges a and b, will return true if the city indexs 
// are in ascending order
// implemeted to be used as a comparison for std::sort, will
// sort the bridges by east bank index in ascending order, and 
// sort the bridges with the same east bank index. by west bank index,
// also in ascending order
bool checkpair(const Bridge& a,
			   const Bridge& b)
{
	if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}
	
//bridges 
//      given the integers representing the number of cities on the west
//      and east bank, and a vector of descriptions of bridges. Returns the 
//      maximum total toll that can be collected from a legal set of bridges
int bridges(int w, 
			int e,
			const vector<Bridge>& bridges){

	const size_t n = bridges.size(); 
	vector<Bridge> sorted = bridges;



    sort(sorted.begin(), sorted.end(), checkpair);

	vector<int> maxes(n);		
    for(size_t i = 0; i < n; i++)
    	maxes[i] = sorted[i][2];
	
    for(size_t i=0; i<n; i++)
	{
        for(size_t j=0; j<i; j++){
            if (sorted[i][0] > sorted[j][0] && sorted[i][1] > sorted[j][1])
                 maxes[i] = std::max(maxes[i], maxes[j] + sorted[i][2]);
		}
	}  

    int maxtoll = 0;
    for(size_t i=0; i<n; i++){
        if (maxtoll < maxes[i])
            maxtoll = maxes[i];
	}
    return maxtoll;        
}


