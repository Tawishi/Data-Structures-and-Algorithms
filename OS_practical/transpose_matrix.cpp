#include<iostream> 
using namespace std; 
int r,c; 
void readMatrix(int *a) { //function for reading matrix from user 
for(int i=0;i<r;i++) 
for(int j=0;j<c;j++) 
cin>>*(a + i*r + j); 
} 
void showMatrix(int *a, int r, int c) { //function for showing matrix in output 
for(int i=0;i<r;i++) { 
for(int j=0;j<c;j++) 
cout<<*(a + i*r + j)<<" "; 
cout<<endl; 
} 
} 
int main() { 
cout<<"Enter number of rows and columns : "; 
cin>>r>>c; 
int a[r][c], t[c][r]; 
cout<<"\nEnter matrix : "; 
readMatrix(a[0]);
cout<<"\nMatrix :\n";
showMatrix(a[0],r,c);
cout<<"\nTranspose of matrix is : \n"; 
for(int i=0;i<r;i++) 
for(int j=0;j<c;j++) 
t[i][j] = a[j][i]; //transpose of matrix
showMatrix(t[0],c,r);
return 0; 
} 

