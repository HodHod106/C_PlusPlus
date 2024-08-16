#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;

bool sortByValueDesc(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int main(){
    vector<int>v = {1,2};
    int k = 2;
    map<int,int> m;
    for(int i : v) m[i]++;

//    map<int,int> rev_m;
//
//    for(auto p : m) {
//
//        rev_m[p.second]=p.first;
//    }

    vector<pair<int, int>> sortedMAP(m.begin(), m.end());
    sort(sortedMAP.begin(), sortedMAP.end(), sortByValue);



//    cout<<rev_m.size();
//// hint next day > handle nubers repeats only once
//    vector<int>arranged_vector;
//    for(auto p : rev_m) arranged_vector.push_back(p.second);//
//
//    vector<int>ans;
//    while(k--){
//        ans.push_back(arranged_vector.back());
//        arranged_vector.pop_back();
//    }
//
//    for(auto i : ans) cout<<i<<endl;


    return 0;
}
