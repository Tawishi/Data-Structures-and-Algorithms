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
cout<<"Enter size of matrix : "; 
cin>>r;
c = r;
int a[r][c], sum = 0;
cout<<"\nEnter matrix : ";
readMatrix(a[0]);
cout<<"\nMatrix :\n";
showMatrix(a[0]);
cout<<"\nSum of diagonal elements is : \n";
for(int i=0;i<r;i++)
sum += a[i][i]; //diagonal sum
cout<<sum<<"\n";
return 0;
}

