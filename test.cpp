#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector <string> histogram;
    for (int i = 100; i < 8; i+=10) {
        string s = to_string(i);
        s += " | ";
        cout << s << endl;
        // histogram.push_back(s);
    }
}