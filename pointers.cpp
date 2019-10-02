#include <iostream>
using namespace std;

void createArray(int size, int *a) {
    for (int i = 0; i < size ; i++) {
        a[i] = 0;
    }
}

int addGrade(int value, int *a, int actualSize, int *arrSize) {
    int count = 0;
    if(actualSize < *arrSize) {
        while(true){
        if(a[count] == 0){
            a[count] = value;
            actualSize++;
            break;
        }
        count++;
        }
    }
    if(actualSize == *arrSize) {
        cout << "Maximum space reached. Now doubling array size" << endl;
        int oldSize = *arrSize;
        *arrSize = *arrSize*2;
        cout << "New array size: " << *arrSize << endl;
        int *resizeArr = new int[*arrSize];
        for (int i = 0; i < oldSize; i++){
            resizeArr[i] = a[i];
        }
        a = resizeArr;
        delete [] resizeArr;

        // while(true){
        //     if(a[count] == 0){
        //         a[count] = value;
        //         actualSize++;
        //         break;
        //     }
        //     count++;
        // }
    }
    // actualSize++;
    return actualSize;
}

int delGrade(int value, int *a, int actualSize, int *arrSize) {
    int count = 0;
    int index = 0;
    for(int i = 0; i < *arrSize; i++) {
        cout << "looking for " << value << endl;
        if(a[i] == value){
            cout << "found" << endl;
            a[i] = 101;
            index = i;
            actualSize--;
            break;
        }else{
            cout << "Element is not in the array" << endl;
        }
    }

    for(int i = 0; i < *arrSize; i++) {
        if(i == index) {
            while(i < actualSize){
                a[i] = a[i+1];
                i++;
            }
            break;
        }else{
            a[i] = a[i];
        }
    }

    int*resizeArr = new int[*arrSize];
    for (int i = 0; i < *arrSize; i++) {
        if(i < actualSize){
            resizeArr[i] = a[i];
        }else{
            resizeArr[i] = 0;
        }

    }
    a = resizeArr;
    delete [] resizeArr;

    // if(actualSize == (*arrSize/2)) {
    //     cout << "Reducing Array Size." << endl;
    //     *arrSize = *arrSize/2;
    //     cout << "New array size: " << *arrSize << endl;
    //     int *resizeArr = new int[*arrSize];
    //     for (int i = 0; i < *arrSize; i++){
    //         resizeArr[i] = a[i];
    //     }
    //     a = resizeArr;
    //     delete [] resizeArr;
    // }
    return actualSize;
}

void printArr(int *a, int size) {

    for (int i = 0; i < size; i++) {
        cout << a[i] << endl;
    }
}

int main()
{
    int *my_ptr;
    bool loop = true;
    bool allowed = false;
    int arrSize = 0;
    int* arrSize_ptr = &arrSize;
    int actualSize = 0;
    while(loop) {
        cout << "Current arrSize: " << arrSize << endl; 
        int x;
        cout << "-----------------------------------" << endl;
        cout << "Choose an option:" << endl;
        cout << "(1) Create array, (2) Add grade, (3) Delete grade, (4) Print array, (5) Unused memory, (6) Sort array, (7) Exit" << endl;
        cout << "-----------------------------------" << endl;
        
        cin >> x;
        switch(x) {
            case 1:{
                cout << "Enter the size of the array" << endl;
                cin >> arrSize;
                my_ptr = new int[arrSize];
                createArray(arrSize, my_ptr);
                allowed = true;
                break;
                }
            case 2:{
                if(!allowed){
                    cout << "The array does not exist" << endl;
                    break;
                }
                int grade;
                cout << "Enter the new grade: " << endl;
                cin >> grade;
                actualSize = addGrade(grade, my_ptr, actualSize, arrSize_ptr);
                break;
                }
            case 3:{
                if(!allowed){
                    cout << "The array does not exist" << endl;
                    break;
                }
                int grade;
                cout << "Enter the grade to be deleted: " << endl;
                cin >> grade;
                actualSize = delGrade(grade, my_ptr, actualSize, arrSize_ptr);
                break;

                }
            case 4:{
                if(!allowed){
                    cout << "The array does not exist" << endl;
                    break;
                }
                cout << "Printing the array" << endl;
                cout << "Total Elements: " << actualSize << endl;
                cout << "Array Size: " << arrSize << endl;
                printArr(my_ptr, actualSize);
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