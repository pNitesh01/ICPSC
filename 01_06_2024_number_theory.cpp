#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000100
int is_prime[MAXN];
// vector<int> prime_factors[MAXN];
int prime_factors[MAXN];

map<int, vector<int>> mp;

void precompute(){
    for(int i=2; i<MAXN; i++){
        is_prime[i] = 1;
    }

    for(int i=2; i<MAXN; i++){ // O(N loglogN)
        if(is_prime[i]){
            // prime_factors[i].push_back(i);
            prime_factors[i] = 1;

            for(int j=2*i; j<MAXN; j+=i){
                is_prime[j] = 0;
                // prime_factors[j].push_back(i);
                prime_factors[j]++;
            }
        }
    }

    for(int i=1; i<MAXN; i++){
        mp[prime_factors[i]].push_back(i);
    }
}

signed main(){
    /*
        PROBLEM 1:
        link: https://codeforces.com/problemset/problem/1458/A
    */
    int n, m;
    vector<int> arr(n), brr(m);

    sort(arr.begin(), arr.end());
    int preval = 0;
    for(int i=1; i<n; i++){
        preval = __gcd(preval, arr[i] - arr[i-1]);
    }

    for(int j=0; j<m; j++){
        cout << __gcd(arr[0]+brr[j], preval) << " ";
    }


    /*
        PROBLEM 2:
        link: https://www.spoj.com/problems/NFACTOR/

        Optimize - 1. prefix sum
                    - 2. [l, r] how many x? hash - map of positions
                    #(<=r) - #(<l) => 
    */
    precompute();
    int n, a, b; // no of primes btw [a, b] == n ?
    int cnt = 0;
    for(int i=a; i<=b; i++){
        cnt += (prime_factors[i]==n);
    }

    int lessThanA = lower_bound(mp[n].begin(), mp[n].end(), a) - mp[n].begin();
    int lessThanEqualB = upper_bound(mp[n].begin(), mp[n].end(), b) - mp[n].begin();
    int ans = lessThanEqualB - lessThanA;
    cout << ans << endl;
    
    return 0;
}