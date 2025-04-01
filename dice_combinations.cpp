#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define pb push_back 
#define eb pop_back
#define pll pair<ll,ll>
#define vi vector<ll>
#define mp_ make_pair 
#define all(v) v.begin(),v.end()
#define f(i,start,end) for(ll i=start;i<end;i++)  
#define vii vector<vector<ll>>
#define vip vector<pair<ll,ll>>
#define mp unordered_map<ll,ll>




struct Compare {
    bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b) {
        if (a.first == b.first) 
            return a.second < b.second; // Sort second element in descending order
        return a.first > b.first; // Sort first element in ascending order
    }
};


ll MOD = 1e9+7;
int rec(ll n,vector<int>& dp){
    if(n==0) return 1%MOD;
    if(n<0) return 0;

    if(dp[n]!=-1) return dp[n];

    ll sum = 0;
    f(i,1,7){
        sum += rec(n-i,dp)%MOD;
    }

    return dp[n] = sum%MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #ifndef file_io
    //         freopen("input.txt", "r", stdin);
    //         freopen("output1.txt", "w", stdout);
    // #endif
    ll n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<rec(n,dp)<<endl;

}
