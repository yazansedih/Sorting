// Yazan Al Sedih - 12010059
#include <iostream>
#include <vector>

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

int numOfDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void redixSort(int arr[], int size, int n){

    int key = 0;
    int mod = 1;
    while (n >= 0)
    { 
        int* pass = new int [size];

        for (int i = 0; i < size; i++)
        { 
            bool flag = false;
            key = (arr[i] / mod) % 10;   

            if (i == 0){
                pass[i] = arr[i];
            }

            for (int x = i-1; x >=0 ; x--)
            {
                if (flag)
                    break;
                
                int temp = (pass[x] / mod) % 10;
                if (key < temp)
                {
                    int t = pass[x];
                    pass[x] = arr[i];
                    pass[x+1] = t;
                }
                else {
                    pass[x+1] = arr[i];
                    flag = true;
                }
            }
            
        }

        for (int i = 0; i < size; i++)
        {
            arr[i] = pass[i];
        }

        delete[] pass;
        mod = mod * 10;
        n--; 
    }
}

int main(){

    // int arr[] = {5,4200,65555,101,9,88,55};
    // int size = sizeof(arr) / sizeof(int); 

    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    int n = numOfDigits(getMax(arr, size));
    redixSort(arr, size, n);
    print(arr, size);

    return 0;
}