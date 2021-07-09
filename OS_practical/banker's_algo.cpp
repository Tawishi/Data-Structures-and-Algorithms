#include<bits/stdc++.h>

using namespace std;

const int m = 3,n = 5;


// resouce allocation
void resource(int need[n][m], int available[m], int allocation[n][m]) {
    int request[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(request[i][j] > need[i][j]) {
                cout<<"error\n"; //error
                return;
            }
            if(request[i][j] > available[j]) {
                cout<<"wait\n";
                return;
            }
            available[j] -= request[i][j];
            allocation[i][j] += request[i][j];
            need[i][j] -= request[i][j]; 
        }
    }
    cout<<"Request granted\n";
}

// calculate need
void calculateNeed(int need[n][m],int max_resources[n][m], int allocation[n][m]) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            need[i][j] = max_resources[i][j] - allocation[i][j];
        }
    }
}

// safety algorithm
void safety(int max_resources[n][m], int available[m], int allocation[n][m]) {
    cout<<"Entered the function";
    int need[n][m];
    calculateNeed(need, max_resources, allocation);
    int work[m];
    int safeSeq[n];
    for(int i=0;i<m;i++) {
        work[i] = available[i];
    }

    bool finish[n]; // false for all n
    for(int i=0;i<n;i++) {
        finish[i] = false;
    }

    int count=0;
    while(count < n) {  
        for(int i=0;i<n;i++) {
            if(finish[i]==false) {
                int j;
                for(j=0;j<m;j++) {
                    if(need[i][j] > work[j])
                        break;
                }
                // need[i][j] <= work[j]
                if(j == m)
                {
                    for(int k=0;i<m;k++) 
                        work[k] += allocation[i][k];
                    finish[i] = true;  
                    //add into safe sequence
                    safeSeq[count++] = i;
                }
                // cout<<"\n";
            }
        }
    }

    for(int i=0;i<n;i++) {
        if(finish[i] == false) {
            cout<<"\nNo safe sequence\n";
            exit(0);
        }

    }

    for(int i=0;i<n;i++)
        cout<<safeSeq[i]<<" ";
    // return safeSeq;
}

int main() {
    // cout<<"Enter the number of resources";
    // cin>>m;
    int available[m];
    for(int i=0;i<m;i++) {
        cout<<"Enter the number of instances of resouce "<<i+1<<" :";
        cin>>available[i];
    }
    // cout<<"Enter the number of processes";
    // cin>>n;
    int max_resources[n][m] = {{7, 5, 3},
                                {3, 2, 2},
                                {9, 0, 2},
                                {2, 2, 2},
                                {4, 3, 3}};
    // int max_resources[n][m];
    // for(int i=0;i<n;i++) {
    //     cout<<"\nEnter maximum resources requirement for process "<<i+1<<" : ";
    //     for(int j=0;j<m;j++)
    //         cin>>max_resources[i][j];
    // }

    int allocation [n][m] = {{0, 1, 0},
                            {2, 0, 0},
                            {3, 0, 2},
                            {2, 1, 1},
                            {0, 0, 2}};

    // user input for already allocated

    // enter requests
    // for(int i=0;i<n;i++) {
    //     cout<<"\nEnter max_resourcesimum resources requirement for process "<<i+1<<" : ";
    //     for(auto j=0;j<m;j++)
    //         cin>>max_resources[i][j];
    // }


    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++)
    //         cout<<need[i][j]<<" ";
    //     cout<<"\n";
    // }

    cout<<"Calling the function";
    safety(max_resources,available, allocation);
    // for(int i=0;i<n;i++)
    //     cout<<safe[i]<<" ";
    // cout<<"\n";
    return 0;
}