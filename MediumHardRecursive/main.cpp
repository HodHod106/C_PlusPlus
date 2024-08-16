#include<iostream>
using namespace std;


void right_max_v1(int arr[],int len){

    if (len==1) return;

    if(arr[len-1]>arr[len-2]) arr[len-2]= arr[len-1];
    right_max_v1(arr,len-1);
}

void right_max_v2(int arr[],int len){
    if (len==1) return;

    right_max_v2(arr+1,len-1);
    arr[0] = max(arr[0],arr[1]);

}
void right_max_v3(int arr[],int len,int start_pos = 0){
    if (start_pos==len-1)
        return;

    right_max_v3(arr,len,start_pos+1);
    arr[start_pos] = max(arr[start_pos],arr[start_pos+1]);
}

int suffix_sum(int arr[],int len,int last_n ){

    if(last_n==0){
        return 0;
    }
    return arr[len-1] + suffix_sum(arr,len-1,last_n-1);
}

int prefix_sum_v1(int arr[],int last_n ){

    if(last_n==0){
        return 0;
    }
    return arr[0] + prefix_sum_v1(arr+1,last_n-1);
}

int prefix_sum_v2(int arr[],int last_n ){

    if(last_n==0){
        return 0;
    }
    return arr[0] + prefix_sum_v2(arr+1,last_n-1);
}

int main(){
    int arr[] = {1,3,5,2,4,1};
    right_max_v3(arr,6);
    for(int i = 0 ; i<6 ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<suffix_sum(arr,2);
    cout<<prefix_sum_v1(arr,2);

    return 0;
}
