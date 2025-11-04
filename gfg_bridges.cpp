#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// north-south coordinates of each City Pair
struct CityPairs {
    int north, south;
};

// comparison function to sort the given set of CityPairs
bool compare(const CityPairs& a, const CityPairs& b) {
    if (a.south == b.south)
        return a.north < b.north;
    return a.south < b.south;
}

// function to find the maximum number of bridges that can be built
int maxBridges(CityPairs values[], int n) {
    vector<int> lis(n, 1);

    sort(values, values + n, compare);

    // logic of longest increasing subsequence on northern coordinates
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (values[i].north > values[j].north && lis[i] < 1 + lis[j])
                lis[i] = 1 + lis[j];

    int maxcount = lis[0];
    for (int i = 1; i < n; i++){
        cout << lis[i] << "\n";
        if (maxcount < lis[i])
            maxcount = lis[i];
    }
    return maxcount;
}

// Driver program to test above
int main() {
    CityPairs values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};
    int n = 4;
    cout << "Maximum number of bridges = " << maxBridges(values, n) << endl;
    return 0;
}