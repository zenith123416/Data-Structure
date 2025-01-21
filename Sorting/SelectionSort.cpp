#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of data: ";
    cin >> n;
    int arr[n];
    cout << "Enter data: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }

    cout << "New array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
}
