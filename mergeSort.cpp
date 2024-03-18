// Yazan Al Sedih - 12010059
#include <iostream>

using namespace std;

void print(int arr[],int size);
void merge(int arr[],int l,int m,int r);
void mergeSort(int arr[],int l,int r);

int main(){
    // int arr[] = {5,4,6,1,9,88,12,4};
    // int size = sizeof(arr) / sizeof(int); 
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    mergeSort(arr,0,size-1);
    print(arr,size);

    return 0;
}

void print(int arr[],int size){
    cout << "[";
    for (int i = 0; i < size; i++){
        cout << arr[i];
        if (i != size-1)
            cout << ",";
    }
    cout << "]";
}

void mergeSort(int arr[],int l,int r){
    if (l < r)
    {
        int m = (l + r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void merge(int arr[],int l,int m,int r){
    int n1 = m - l+1;
    int n2 = r - m;

    int* left = new int[n1];
    int* right = new int[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0; int j = 0; int k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
   
    while (i < n1) {
        arr[k] = left[i]; 
        i++; 
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}

