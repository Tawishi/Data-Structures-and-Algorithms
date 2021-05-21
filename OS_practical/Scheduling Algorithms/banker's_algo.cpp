#include<bits/stdc++.h>

using namespace std;

size_t m,n;


// resouce allocation
void resource(vector<vector<int>> need, vector<int> available, vector<vector<int>> allocation) {
    vector<vector<int>> request;
    for(auto i=0;i<n;i++) {
        for(auto j=0;j<m;j++) {
            if(request[i][j] > need[i][j])
                cout<<"error\n"; //error
            if(request[i][j] > available[j])
                cout<<"wait\n";
            
            available[j] -= request[i][j];
            allocation[i][j] += request[i][j];
            need[i][j] -= request[i][j]; 
        }
    }
    cout<<"Request granted\n";
}

// calculate need
void calculateNeed(vector<vector<int>> need,vector<vector<int>> &max, vector<vector<int>> allocation) {
    for(int i=0;i<n;i++) {
        for(auto j=0;j<n;j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

// safety algorithm
bool safety(vector<vector<int>> &max, vector<int> available, vector<vector<int>> need, vector<vector<int>> allocation) {
    vector<int> work(available.begin(), available.end());
    vector<bool> finish; // false for all n

    for(auto i=0;i<n;i++) {
        if(finish[i]==false) {
            // need[i] <= work
            for(auto j=0;j<m;j++) {
                if(need[i][j] > work[j])
                    break;

                work[j] += allocation[i][j];
                finish[i] = true;                
            }
        }
    }
    for(auto i=0;i<n;i++) {
        if(finish[i] == false)
            return 0;
    }
    return 1;
}

int main() {
    cout<<"Enter the number of resources";
    cin>>m;
    vector<int> available;
    for(auto i=0;i<m;i++) {
        cout<<"Enter the number of instances of resouce "<<i+1<<" :";
        cin>>available[i];
    }
    cout<<"Enter the number of processes";
    cin>>n;
    vector<vector<int>> max;
    cout<<"\nEnter maximum process requirement:";
    for(auto i=0;i<n;i++) {
        for(auto j=0;i<m;j++)
            cin>>max[i][j];
    }

    vector<vector<int>> allocation (n, vector<int> (m, 0));

    vector<vector<int>> need;
    calculateNeed(need, max, allocation);

    bool safe = safety(max,available,need, allocation);
    cout<<safe<<"\n";
    return 0;
}