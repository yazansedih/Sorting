// Yazan Al Sedih - 12010059
#include <iostream>

using namespace std;

void print(int arr[],int size);
void insertionSort(int arr[],int size);

int main(){

    // int arr[] = {8,2,4,1,9,3,6};
    // int size = sizeof(arr) / sizeof(int); 
    int size;
    // cout << "Enter size of array: ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    insertionSort(arr,size);
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

void insertionSort(int arr[],int size){
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
