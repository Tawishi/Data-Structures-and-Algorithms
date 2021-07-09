#include<iostream> 
using namespace std; 
int r,c; 
int main() { 
    cout<<"Enter number of rows and columns : "; 
    cin>>r>>c; 
    int a[r][c], t[c][r]; 
    cout<<"\nEnter matrix : "; 
    for(int i=0;i<r;i++) 
        for(int j=0;j<c;j++) 
            cin>>a[i][j]; 
    cout<<"\nMatrix :\n";
    for(int i=0;i<r;i++) {
        cout<<"\n"; 
        for(int j=0;j<c;j++) 
            cout<<a[i][j]<<" ";
    }  
    cout<<"\nTranspose of matrix is : \n"; 
    for(int i=0;i<r;i++) 
        for(int j=0;j<c;j++) {
            t[j][i] = a[i][j]; //transpose of matrix
        }
    for(int i=0;i<c;i++) {
        cout<<"\n";
        for(int j=0;j<r;j++) 
            cout<<t[i][j]<<" ";
    }
    return 0;
}

