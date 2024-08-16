
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <array>
using namespace std;
#define all(v) v.begin(),v.end()
#define vint vector<int>
#define vll vector<ll>
typedef long long ll;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
bool isPalindrome(string ss);


int print_lenght_3n_plus_1_seq(int n){ // 6 3 10 5 16 8 4 2 1
    if(n==1)
        return 1;

    if(n&1) return 1+print_lenght_3n_plus_1_seq (3*n+1);
    return 1+print_lenght_3n_plus_1_seq (n/2);
}
int my_pow(int num,int p = 1){ // 7 3
    if (p==0)
        return 1;

    return num * my_pow(num,p-1);
}

int arr_max_num(int arr[],int len){
    if(len==0){
        return arr[0];
    }
    int sub_result = arr_max_num(arr,len-1);
    return max(sub_result,arr[len-1]);
}
int arr_sum(int arr[],int len){
    if(len==1){
        return arr[0];
    }
    int sub_result = arr_sum(arr,len-1);
    return (sub_result+arr[len-1]);
}

double arr_avg(int arr[],int len){
    if(len==1){
        return arr[0];
    }
    double sub_result = arr_avg(arr,len-1);
    sub_result*=(len-1);
    return (sub_result+arr[len-1])/len;
}
////////

void array_increment(int arr[], int len){
    if(len==1) return ;

    array_increment(arr,len-1);
    arr[len-1]+=len-1;
}

void accumulate_arr(int arr[],int len){
    if(len==1){
        return;
    }
    accumulate_arr(arr,len-1);
    arr[len-1]+=arr[len-2];
}
void left_max(int arr[],int len){
    if(len==1) return;
    left_max(arr,len-1);
    if(arr[len-1]<arr[len-2]) arr[len-1]=arr[len-2];
}


////////////////
void solve() {
    cout <<print_lenght_3n_plus_1_seq(6);
    cout<<"\n===*****===\n";

    cout<<my_pow(7,0)<<endl;
    cout<<my_pow(7)<<endl;
    cout<<my_pow(7,3)<<endl;
    cout<<"===*****===\n";

    int arr[] = {1,8,2,10,3};
    cout<<arr_max_num(arr,5)<<endl;
    cout<<"===*****===\n";

    cout<<arr_sum(arr,5)<<endl;
    cout<<"===*****===\n";

    cout<<arr_avg(arr,5)<<endl;
    cout<<"===*****===\n";

    array_increment(arr,5);
    for(int i = 0; i< 5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n===*****===\n";


    accumulate_arr(arr,5);
    for(int i = 0; i< 5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n===*****===\n";



    int arr2[] = {3,1,5,7,4,2};
    left_max(arr2,6);
    for(int i = 0; i< 6; i++){
        cout<<arr2[i]<<" ";
    }

    cout<<"===*****===\n";

}

int main() {
    cin.tie(0);	cout.tie(0);

    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}

ll gcd(ll a, ll b){
    return (b == 0) ? abs(a) : gcd(b, a % b);
}
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
bool isPalindrome(string ss){
    for (int i = 0; i < ss.size() / 2; i++) if (ss[i] != ss[ss.size() - i - 1]) return 0; return 1;
}

