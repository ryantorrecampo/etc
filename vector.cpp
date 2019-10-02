#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> itemCounts(3);
    itemCounts.at(0) = 122;
    itemCounts.at(1) = 119;
    itemCounts.at(2) = 117;
    itemCounts.push_back(144);
    cout << itemCounts.at(1) << endl;
    cout << itemCounts.back() << endl;
    // cout << itemCounts.pop_back() << endl;
    // cout << itemCounts << endl;
    return 0;
}