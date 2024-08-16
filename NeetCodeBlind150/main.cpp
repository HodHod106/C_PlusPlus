
#include<iostream>
using namespace std;

#include <map>
#include<vector>
#include<algorithm>

int main(){
    cin.tie(0);	cout.tie(0);
    ios_base::sync_with_stdio(0);

    vector<string> v;
    int size; cin>>size;
    while(size--){
        string in; cin>>in;
        v.push_back(in);
    }
    sort(v.begin(),v.end());

    vector<vector<string>>ans;
    vector<string>grang;

    for(int i=1;i<v.size();i++){
        if(v[i]!=v[i-1]){
            grang.push_back(v[i-1]);
            ans.push_back(grang);
            grang.clear();
        }else{
            grang.push_back(v[i-1]);
        }
    }
    if(v[v.size()-1]!= v[v.size()-2]){
        ans.push_back({v[v.size()-1]});
    }else{
        grang.push_back(v[v.size()-1]);
        ans.push_back(grang);
        grang.clear();
    }
    return 0;
}

