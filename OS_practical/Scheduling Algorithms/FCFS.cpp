#include <bits/stdc++.h>
using namespace std;

void findAverageTime(vector<int> burst_time) {
	float average_waiting_time =  findTotalTime(findWaitingTime(burst_time))/burst_time.size();
	cout << "Processes  "<< " Burst time  "
         << " Waiting time  \n";
	cout<<"Average waiting time = "<<average_waiting_time<<"\n";
}

vector<int> findWaitingTime(vector<int> burst_time) {
	int size = burst_time.size();
	int waiting_time[size];
	waiting_time[0] = 0;
	for(int i=1;i<size;i++) {
		waiting_time[i] = waiting_time[i-1]+burst_time[i-1];
	}
	return waiting_time;
}

int findTotalTime(vector<int> values) {
	int sum=0;
	for(int i=0;i<values.size();i++)
		sum += values[i];
	return sum;
}

int main() {
	vector<int> burst_time;
	int i=0;
	char choice='y';
	while(choice='y' || choice='Y') {
		cout<<"Enter process CPU burst time (milliseconds): ";
		cin>>burst_time[i];
		i++;
		findAverageTime(burst_time);
		cout<<"\nMore processes (y/n)?"<<"\t"; 
	}
	return 0;
}
