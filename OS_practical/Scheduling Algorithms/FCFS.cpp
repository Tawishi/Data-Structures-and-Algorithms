#include <bits/stdc++.h>
using namespace std;

vector<int> findWaitingTime(vector<int> burst_time) {
	int size = burst_time.size();
	vector<int> waiting_time;
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

void findAverageTime(vector<int> burst_time) {
	float average_waiting_time =  findTotalTime(findTotalTime(findWaitingTime(burst_time)))/burst_time.size();
	cout << "Processes  "<< " Burst time  "
         << " Waiting time  \n";
	cout<<"Average waiting time = "<<average_waiting_time<<"\n";
}

int main() {
	vector<int> burst_time;
	int i=0, time;
	char choice='y';
	while(choice=='y' || choice=='Y') {
		cout<<"Enter process CPU burst time (milliseconds): ";
		cin>>time;
		burst_time.push_back(time);
		cout<<"\nMore processes (y/n)?"<<"\t";
		cin>>choice;
	}
        findAverageTime(burst_time);
	return 0;
}
