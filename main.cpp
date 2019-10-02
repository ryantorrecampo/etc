#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int flag = 1;
    int height[100];
    int totalChildren = 0;
    double totalHeight = 0;
    while (flag != 0) {
        cin >> flag;
        if (flag >= 100 && flag <= 199) {
            height[totalChildren] = flag;
            totalHeight+= (double)height[totalChildren];
            totalChildren++;
            continue;
        } else if (flag != 0) {
            cout << "Wrong height, the value must be between 100 cm and 199 cm.\n";
        } else {
            break;
        }
    }
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    //Total number of children;
    cout << "Number of children = " << totalChildren << endl;
    
    //Average height
    double avgHeight = totalHeight/totalChildren;
    cout << "Average of the heights in the array = " << fixed << setprecision(2) << avgHeight << endl;

    //Standard Deviation
    double stdDev;
    if (totalChildren == 0) {
        stdDev = 0;
    } else {
        for (int i = 0; i < totalChildren; i++) {
            stdDev += pow(height[i] - avgHeight, 2);
        }
    }

    cout << "Standard Deviation of the heights in the array = " << fixed << setprecision(2) << sqrt(stdDev / totalChildren) << endl;
    
    //The values in the data set
    cout << "Values in the dataset = ";
    for (int i = 0; i < totalChildren; i++) {
        if (height[i] > 0 && i < totalChildren-1) {
            cout << height[i] << ",";
        } else if (i == totalChildren-1) {
            cout << height[i] << endl;
        } else {
            break;
        }
    }

    cout << "Histogram showing the numbers of children in each of the height ranges:" << endl;
    //Fill the histogram
    vector <string> histogram;
    for (int i = 100; i < 200; i+=10) {
        string s = to_string(i);
        s += " | ";
        histogram.push_back(s);
    }

    int val;
    for (int i = 0; i < totalChildren; i++) {
        int check = 1;
        int x = 100;
        while(check == 1) {
            if(height[i] >= x && height[i] < x+10) {
                val = (x-100)/10; 
                histogram[val] += '*';
                check = 0;
            }else{
                x+=10;
            }
        }
    }

    for (int i = 0; i < histogram.size(); i++) {
        cout << histogram[i] << endl;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    unsigned long int duration = duration_cast<microseconds>(t2-t1).count();
    cout << duration << endl;

    return 0;
}