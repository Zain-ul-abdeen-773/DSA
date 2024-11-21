#include<iostream>
using namespace std;

void Bubble_sort(double arr[],int size){
   for(int i=0;i<size-1;++i){
     for(int j = 0;j<size-i-1;j++){
        if(arr[j]>arr[j+1]){
            arr[j] = arr[j] + arr[j+1];
            arr[j+1] = arr[j] - arr[j+1];
            arr[j] = arr[j] - arr[j+1];
        }
     }
   }
}
void print(double a[],int size){
    cout<<"Bubble sorted List:"<<endl;
    for(int i=0;i<size;i++ ){
        cout<<a[i]<<" ";
    }
}

int main(){

    double array[] = {23.4,-2,45.9,-76};
    int size = sizeof(array)/sizeof(array[0]);
    Bubble_sort(array,size);
    print(array,size);
    return 0;
    
}