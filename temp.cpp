#include <iostream>

using namespace std;

void createArray(int *array, int *size) {
    for(int i = 0; i < *size; i++) {
        array[i] = 0;
    }
}

void printArray(int *array, int *size, int *totalElements) {
    cout << "Number of grades: " << *totalElements << endl;
    cout << "Maximum amount of grades: " << *size << endl;
    for(int i = 0; i < *size; i++) {
        // if(array[i] == 0) break;
        // else {
        //     cout << array[i] << " \n";
        // }
        cout << array[i] << " \n";
    }
}

void addGrade(int *array, int *size, int value, int *totalElements) {

    if (*totalElements == *size) {   
        int oldSize = *size;
        *size = *size * 2;
        int *resizearr = new int[*size];
        for(int i = 0; i < *size; i++) {
          resizearr[i] = 0;
        }
        for(int i = 0; i < oldSize; i++) {
          resizearr[i] = array[i];
        }
        array = resizearr;
        delete [] resizearr;
    }
    cout << "Intermediate printing..." << endl;
    for(int i = 0; i < *size; i++) {
      cout << array[i] << endl;
    }

    array[*totalElements] = value;
    *totalElements+=1;
}

int main() {

    bool loop = true;
    int opt;
    int *arr_ptr;
    int arrSize = 0;
    int *arrSize_ptr = &arrSize;
    int numElements = 0;
    int *totalElements = &numElements;
    bool allowed = false;

    while(loop) {
        cout << "-----------------------------------" << endl;
        cout << "Choose an option:" << endl;
        cout << "(1) Create array, (2) Add grade, (3) Delete grade, (4) Print array, (5) Unused memory, (6) Sort array, (7) Exit" << endl;
        cout << "-----------------------------------" << endl;
        cin >> opt;

        switch(opt) {
            case 1:{
                cout << "Enter the size of the array:" << endl;
                cin >> arrSize;
                arr_ptr = new int[arrSize];
                createArray(arr_ptr, arrSize_ptr);
                allowed = true;
                break;
            }
            case 2:{
                if(!allowed) {
                    cout << "Please enter grades first." << endl;
                    break;
                }
                cout << "Enter the new grade:" << endl;
                int grade;
                cin >> grade;
                addGrade(arr_ptr, arrSize_ptr, grade, totalElements);
                break;
            }
            case 4:{
                if(!allowed) {
                    cout << "Please enter grades first." << endl;
                    break;
                }
                cout << "Now printing the array...\n";
                printArray(arr_ptr, arrSize_ptr, totalElements);
                break;
            }
            case 7:{
                loop = false;
                break;
            }
        }
    }

    return 0;
}
