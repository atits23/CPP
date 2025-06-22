//Selection Sort
#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}

 void selection_sort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int min=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);    //O(N^2)
    }
 }

 // Bubble Sort
 void Bubble_Sort(int arr[],int n){
    for(int i=n-1;i>=1;i++){
        int didswap=0;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap=1;  //O(N^2)
            }
        }
        if(!didswap){
            break;
        }
    }
 }

 //Insertion Sort

 