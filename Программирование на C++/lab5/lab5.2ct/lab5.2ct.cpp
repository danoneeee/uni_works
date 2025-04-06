#include <iostream>

using namespace std;

int* max_vect(int size, int* arr1, int* arr2)
{
    int* result = new int[size];

    for (int i = 0; i < size; ++i)
    {
        if (arr1[i] > arr2[i])
            result[i] = arr1[i]; 
        else
            result[i] = arr2[i]; 
    }

    return result; 
}

int main()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 2 }; 
    int b[] = { 7, 6, 5, 4, 3, 2, 1, 3 }; 

    int kc = sizeof(a) / sizeof(a[0]);
    int* c;                           

    c = max_vect(kc, a, b);            
    for (int i = 0; i < kc; ++i)   
        cout << c[i] << " ";

    delete[] c;                      

    cout << endl;

    return 0;
}