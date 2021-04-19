#include<iostream> 
#include<cstdlib> 
using namespace std; 
int main() { 
int m,n,p,q; 
cout<<"Enter number of rows and columns for matrix 1 : "; 
cin>>m>>n; 
int a[m][n]; 
cout<<"\nEnter number of rows and columns for matrix 2: "; 
cin>>p>>q; 
int b[p][q]; 
if(n != p) { //checking multiplication possibility 
cout<<"\nMultiplication not possible.\n"; 
exit(0); 
} 
cout<<"Enter elements of matrix 1 : "; 
for(int s=0;s<m;s++) { 
for(int t=0;t<n;t++) 
cin>>a[s][t]; 
} 
cout<<"\nEnter elements of matrix 2 : "; 
for(int v=0;v<p;v++) { 
for(int w=0;w<q;w++) 
cin>>b[v][w]; 
} 
int c[m][q] ; 
for(int i=0;i<m;i++) { 
for(int j=0;j<q;j++) { 
c[i][j] = 0; 
for(int k=0;k<n;k++) 
c[i][j] += a[i][k]*b[k][j]; //multiplying the matrices 
} 
} 
cout<<"Matrix 1 : "<<endl; 
for(int i=0;i<m;i++) { 
for(int j=0;j<n;j++) 
cout<<a[i][j]<<" "; 
cout<<"\n"; 
} 
cout<<"Matrix 2 : "<<endl; 
for(int i=0;i<p;i++) { 
for(int j=0;j<q;j++) 
cout<<b[i][j]<<" "; 
cout<<"\n"; 
} 
cout<<"\nProduct matrix is : "<<endl; 
for(int i=0;i<m;i++) { 
for(int j=0;j<q;j++) 
cout<<c[i][j]<<" "; 
cout<<"\n"; 
} 
} 

