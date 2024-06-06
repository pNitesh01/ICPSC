#include <bits/stdc++.h>
using namespace std;

signed main(){
    /*
        PROBLEM 1:
        You are given the arrival and leaving times of n customers in a restaurant.
        What was the maximum number of customers in the restaurant at any time?
        arrival = [1, 2, 10, 5, 5]
        leaving = [4, 5, 12, 9, 12]
    */
    int n;
    vector<int> arrival(n), leaving(n);

    vector<pair<int, int>> times;
    // first value is current time
    // second value is -1(entry) or 1(leaves)

    for(int i=0; i<n; i++){
        times.push_back({arrival[i], -1});
        times.push_back({leaving[i], 1});
    }

    sort(times.begin(), times.end());
    int currCustomers = 0, maxCustomers = 0;

    for(auto &[time, type]: times){
        if(type == 1){
            currCustomers++;
            maxCustomers = max(maxCustomers, currCustomers);
        } else{
            currCustomers--;
        }
    }


    /*
        PROBLEM 2:
        Given an array of n integers.
        Find for each position the nearest position to its left having a smaller or equal value.

        Optimal: Monotonic Stack O(n)
        Searching and Sorting: Practise O(n logn)
    */
    vector<int> arr(n);
    vector<pair<int, int>> values;
    // first value is element value
    // second is index

    for(int i=0; i<n; i++){
        values.push_back({arr[i], i});
    }

    sort(values.begin(), values.end());
    set<int> indexesCoveredTillNow;

    for(int i=0; i<n; i++){
        int current_ind = values[i].second;
        // all the indexes that came before this has element smaller or equal to current_ind

        // out of all indexes covered till now, find the max index which is less than current_ind
        auto it = indexesCoveredTillNow.lower_bound(current_ind);
        if(it != indexesCoveredTillNow.begin()){ // element is present
            it--;
        } else{
            // no answer
        }
        indexesCoveredTillNow.insert(current_ind);
    }

    /*
        MINI PROBLEM:
        Two types of queries-
        - add an element
        - find max element <= x

        Use set data-structure
    */


    /*
        PROBLEM 3:
        You are given a playlist of a radio station.
        The playlist has a total of n songs.
        What is the longest sequence of successive songs where each song is unique?

        [1, 4, 5, 1, 10, 12, 10, 5]
        ans = [4, 5, 1, 10, 12]
    */
    vector<int> playlist(n);
    int left = 0, right = 0;
    int maxLength = 0;
    map<int, int> lastOccurance;

    for(right=0; right<n; right++){
        if(lastOccurance.find(playlist[right]) != lastOccurance.end()){
            left = max(left, lastOccurance[playlist[right]] + 1);
        }

        lastOccurance[playlist[right]] = right;
        maxLength = max(maxLength, right-left+1);
    }


    /*
        PROBLEM 4:
        N jobs are given, each job has a start time, end time.
        Find the maximum number of jobs that can be done without overlapping.        
    */
    vector<pair<int, int>> jobs;
    // first is start time
    // second is end time

    sort(jobs.begin(), jobs.end(), [](pair<int, int> job1, pair<int, int> job2){
        return job1.second < job2.second;
    });

    int cntJob = 0, currTime = 0;
    for(auto &[startTime, endTime]: jobs){
        if(startTime > currTime){
            cntJob++;
            currTime = endTime;
        }
    }


    /*
        PROBLEM 5: (HW)
        You have n coins with positive integer values.
        What is the smallest sum you cannot create using a subset of the coins?
    */
    vector<int> coins(n);
    int nextCoin = 1, ans;
    for(int coin: coins){
        if(coin > nextCoin){
            ans = nextCoin; break;
        } else{
            nextCoin += coin;
        }
    }

    ans = nextCoin;


    /*
        PROBLEM 6: (HW)
        There is a street of length n whose positions are numbered 0,1,2.....n.
        Initially there are no traffic light.
        but m sets of traffic lights are added to the street one after another.
        Your task is to calculate the length of the longest passage without traffic lights after each addition.

        n=8 m=3
        ip: 3 6 2
        op: 5 3 3
    */


    return 0;
}