#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;
int main()
{
    int heights[100];
    std::fill_n(heights,100,1);
    int check = 0,totalsum = 0;
    while (heights[check] != 0)
    {
        std::cin >> heights[check];
        if (heights[check] == 0)
        {
            break;
        }
        while (heights[check] < 100 || heights[check] > 199)
        {
            std::cout << "Wrong height, the value must be between 100 cm and 199 cm.\n";
            std::cin >> heights[check];
        }
        totalsum = totalsum + heights[check];
        check += 1;
                
    }
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    std::cout << "Number of children = " << check << std::endl;
    double avgheight;
    avgheight = 1.0 * totalsum / check;
    std::cout << "Average heights in the array = " << std::fixed << std::setprecision(2) << avgheight << std::endl; 
    // Standard Deviation
    double standev;
    if (check == 0)
    {
        standev = 0;
    }
    else 
    {
    for (int i = 0; i < check; i++)
    {
        standev += pow(heights[i] - avgheight,2);
    }
    }
    
    std:: cout << "Standard Deviation of the heights in the array = " << sqrt (standev/check) << std::endl;
    std::cout << "Values in the dataset = ";
    for (int i = 0; i <check-1; i++)
    {
        std::cout << heights[i] << ",";
    }
    std::cout << heights[check-1]<< std::endl;
    std::cout << "Histogram showing the numbers of children in each of the height ranges:"<< std::endl;
    int stars[10];
    std::fill_n(stars,10,0);
    int x = 100, y = 110, z = 0, test = 0;;
    for(int i = 0; i < check; i++)
    {
        x = 100;
        y = 110;
        test = 0;
        z = 0;
        while (z == 0)
        {
            if (heights[i] >=x && heights[i] <y){
            stars[test] += 1;
            z = 1;
            }
            else 
            {
                z = 0;
                x += 10;
                y+= 10;
                test+= 1;
            }

        }
    
    }
    x = 100;
    for (int i = 0; i < 10; i++)
    {
        std::cout << x << " | ";
        for (int k = 0; k < stars[i];k++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
        x += 10;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    unsigned long int duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << "Execution time: " << duration << endl;
    return 0;
}