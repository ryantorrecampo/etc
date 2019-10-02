#include <iostream>
using namespace std;


void makearr(int *&size, int *gradesarr)
{
    
    for (int i = 0; i < *size; i++)
    {
        gradesarr[i] = 0;
    }
}

void addval(int *numaddedptr, int *gradesarr, int*size)
{
    
     if (*numaddedptr == *size)
    {   
        int oldSize = *size;
        *size = *size * 2;
        int *resizearr = new int[*size];
        for (int i = 0; i < oldSize; i++)
        {
            
            resizearr[i] = gradesarr[i];
        }
        delete [] resizearr;
        for (int i = *numaddedptr; i < *size; i++ )
        {
            gradesarr[i] = 0;
        }
    }

    int newgrade;
    cout << "Enter the new grade: ";
    cin >> newgrade;
    while (newgrade < 0 || newgrade > 100)
    {
        cout << "Enter the new grade: ";
        cin >> newgrade;
    }
    gradesarr[*numaddedptr] = newgrade; 
    *numaddedptr += 1;
    

}

void delval(int *gradesarr, int *size, int *numaddedptr)
{
    int badval;
    cout << "Enter the grade to be deleted: ";
    cin >> badval;
    bool found = false;
    for (int i = 0; i < *size; i++)
    {
        if (gradesarr[i] == badval)
        { 
            found = true;
            for ( ; i < *size - 1; i++)
            {
                gradesarr[i] = gradesarr[i+1];
            }
            *numaddedptr = *numaddedptr -1;
            for (int k = *numaddedptr; k < *size; k++ )
            {
                gradesarr[k] = 0;
            }
            
        }
      
        
    }
    if(!found){
        cout << "Element is not in the array" << endl;
    }
    if (*numaddedptr == *size/2)
    {   
        int oldSize = *size;
        *size = *size / 2;
        int *resizearr = new int[*size];
        for (int i = 0; i < oldSize; i++)
        {
            resizearr[i] = gradesarr[i];
        }
        delete [] resizearr;
        for (int i = *numaddedptr + 1; i < *size; i++ )
        {
            gradesarr[i] = 0;
        }
    
    }
   
}
void printarray(int *numaddedptr, int *gradesarr, int *size)
{
    cout << "Grades = ";
    for (int i = 0; i < *numaddedptr; i++)
    {
        cout << *gradesarr << " ";
        gradesarr++;
    }
    cout << "\n" << endl;
    cout << *size <<" " << *numaddedptr<< endl;
}

void printMem(int *numaddedptr, int *size) {
    cout << "Unused MEM space in bytes = " << (*size-*numaddedptr)*4 << endl;
}

void sort(int *gradesarr, int *numaddedptr){
    for (int i = 0; i < *numaddedptr; i++) {
        for (int j = i + 1; j < *numaddedptr; j++) {
            if(gradesarr[i] > gradesarr[j]) {
                int temp = gradesarr[i];
                gradesarr[i] = gradesarr[j];
                gradesarr[j] = temp;
            }
        }
    }
}

int main()
{
    int *gradesarr;
    int *size;
    bool valid = true;
    int choice;
    int numadded = 0;
    int *numaddedptr;
    numaddedptr = &numadded;
    bool allowed = false;

    while (valid){
        cout <<"(1) Create array, (2) Add grade, (3) Delete grade, (4) Print array, (5) Unused memory, (6) Sort array, (7) Exit: ";
        cin >> choice;
        switch(choice){
            case 1:
                int size1;
                cout << "Enter the array size: ";
                cin >> size1;
                size = &size1;
                gradesarr = new int[*size];
                makearr(size,gradesarr);
                allowed = true;
                break;
            case 2:{
                if(!allowed){
                    cout << "The array does not exist" << endl;
                    break;
                }          
                addval(numaddedptr,gradesarr,size);
                break;
                }
            case 3:{
                if(!allowed){
                    cout << "The array does not exist" << endl;
                    break;
                }
                delval(gradesarr, size, numaddedptr);
                break;
                }
            case 4:{
                if(!allowed){
                    cout << "The array does not exist" << endl;
                    break;
                }
                printarray(numaddedptr,gradesarr,size);
                break;
                }
            case 5: {
                if(!allowed){
                    cout << "The array does not exist" << endl;
                    break;
                }
                printMem(numaddedptr, size);
                break;
                }
            case 6: {
                if(!allowed){
                    cout << "The array does not exist" << endl;
                    break;
                }
                sort(gradesarr, numaddedptr);
                
            break;
            }
            case 7:
                valid = false;
                break;
                    
        }
    }
}
