#include <iostream>

using namespace std;

void print(int arr[],int size){
    cout << "[";
    for (int i = 0; i < size; i++){
        cout << arr[i];
        if (i != size-1)
            cout << ",";
    }
    cout << "]";
}

void swap(int arr[],int i,int j){
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;  
}

int partition(int arr[],int l,int r){

    int pivot = l; 

    int i = l;
    int j = r;
    while (i != j)
    {
        if (arr[i] < arr[j]) {
            if (arr[i] == arr[pivot]) j--;
            else i++;
        } 
        else {
            if (arr[i] == arr[pivot])
            {
                swap(arr,i,j);
                pivot = j;
                i++;
            }
            else {
                swap(arr,i,j);
                pivot = i;
                j--;
            }    
        }
    }

    return pivot;
}

void quickSort(int arr[],int l,int r){
    if (l < r)
    {
        int pivot = partition(arr,l,r);
        quickSort(arr,l,pivot -1);
        quickSort(arr,pivot +1,r);
    }
}

int main(){

    // int arr[] = {50,20,1,60,10,30,40};
    // int size = sizeof(arr)/sizeof(int);

    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    quickSort(arr,0,size-1);
    print(arr,size);

    return 0;
}