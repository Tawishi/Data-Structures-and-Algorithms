#include<iostream> 
using namespace std; 
int r,c; 
void readMatrix(int *a) { //function for reading matrix from user 
for(int i=0;i<r;i++) 
for(int j=0;j<c;j++) 
cin>>*(a + i*r + j); 
} 
void showMatrix(int *a) { //function for showing matrix in output 
for(int i=0;i<r;i++) { 
for(int j=0;j<c;j++) 
cout<<*(a + i*r + j)<<" "; 
cout<<endl; 
} 
} 
int main() { 
cout<<"Enter number of rows and columns : "; 
cin>>r>>c; 
int a[r][c],b[r][c],d[r][c]; 
cout<<"\nEnter matrix 1: "; 
readMatrix(a[0]); 
cout<<"\nEnter matrix 2: "; 
readMatrix(b[0]); 
cout<<"\nMatrix 1 :\n"; 
showMatrix(a[0]); 
cout<<"\nMatrix 2 :\n"; 
showMatrix(b[0]); 
cout<<"\nSum of matrices is : \n"; 
for(int i=0;i<r;i++) 
for(int j=0;j<c;j++) 
d[i][j] = a[i][j] + b[i][j]; //adding matrices 

showMatrix(d[0]); 
return 0; 
} 

