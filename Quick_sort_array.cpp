#include<iostream>
using namespace std;
int partition(int arr[],int left,int right){
    int pivot = arr[left];
    int i = left + 1;
    int j = right;
    while(true){
        while(i < right && arr[i] < pivot){
            i++;
        }
        while(j > left && arr[j] >= pivot){
            j--;
        }
        if(i >= j){
            break;
        }
        swap(arr[i],arr[j]);
    }
    swap(arr[left],arr[j]);
    return j;
}
void  QuickSort(int arr[],int left,int right){
    if(left < right){
        int x = partition(arr,left,right);
        QuickSort(arr,left,x);
        QuickSort(arr,x+1,right);
    }
}
void print(int arr[],int size){
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {34,56,21,-1,20,67,809,801};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted Array: ";
    print(arr,size);
    QuickSort(arr,0,size - 1);
    cout<<"Sorted Array: ";
    print(arr,size);
    return 9;
}
