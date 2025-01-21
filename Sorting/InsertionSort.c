#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of data: ";
    cin >> n;
    int arr[n];
    cout << "Enter data: ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    for(int i=1; i<n; i++){
        for(int j=i; j>0 && arr[j-1]>arr[j]; j--){
            swap(arr[j], arr[j-1]);
        }
    }

    cout << "New Sorted Array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
}

