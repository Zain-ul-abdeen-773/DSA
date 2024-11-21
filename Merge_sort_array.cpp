#include<iostream>
using namespace std;

void merge(int arr[],int left,int mid,int right){
    
  int n1 = mid-left+1;
  int n2 = right-mid;
  int *a,*b;
  a = new int[n1];
  b = new int[n2];

  for(int i=0 ; i<n1 ; i++){
    a[i] = arr[left+i];
  }

  for(int j=0 ; j<n2 ;j++){
    b[j] = arr[mid+1+j];
  }

  int x = 0;
  int y = 0;
  int z = left;

  while(x<n1 && y<n2){
    if(a[x]<=b[y]){
        arr[z] = a[x];
        x++;
    }
    else{
        arr[z] = b[y];
        y++;
    }
    z++;
  }

  while(x < n1){
    arr[z] = a[x];
    x++;
    z++;
  }

  while(y < n2){
    arr[z] = b[y];
    y++;
    z++;
  }

  delete a;
  delete b;
}

void mergesort(int arr[],int left,int right){
    if(left<right){
       int mid = left + (right-left)/2;
       mergesort(arr,left,mid);
       mergesort(arr,mid+1,right);
       merge(arr,left,mid,right);
    }

}

void display(int array[],int size){
    for(int i =0;i<size;i++){
        cout<<array[i];
        if(i != size-1){
            cout<<" -> ";
        }
    }
    cout<<endl;
}

int main(){
    int array[] =  {23,21,33,10,-23,-455,908,567,566};
    int size = sizeof(array)/sizeof(array[0]);
    display(array,size);
    mergesort(array,0,size-1);
    display(array,size);
    return 0;
}