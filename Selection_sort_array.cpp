#include<iostream>
using namespace std;

void Selection_sort(double arr[],int size){
    for(int i = 0;i<size-1;++i){
        int min_idx = i;
        for(int s = i+1;s<size;s++){
            if(arr[s]<arr[min_idx]){
                min_idx = s;
            }
            swap(arr[min_idx],arr[i]);
        }
    }
}
void print(double arr[],int b){
    cout<<"Selection sorted Array!"<<endl;
    for(int i = 0;i<b;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){

    double array[] = {23.4,-2,45.9,-76};
    int size = sizeof(array)/sizeof(array[0]);
    Selection_sort(array,size);
    print(array,size);
    return 0;
    
}