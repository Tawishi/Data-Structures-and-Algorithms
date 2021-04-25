#include <bits/stdc++.h>
using namespace std;

vector<int> findWaitingTime(vector<int> burst_time) {
	cout<<"finding waiting times\n";
	int size = burst_time.size();
	vector<int> waiting_time;
	waiting_time[0] = 0;
	for(int i=1;i<size;i++) {
		waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
	}
	return waiting_time;
}

int findTotalTime(vector<int> values) {
	cout<<"finding total waiting time\n";
	int sum=0;
	for(int i=0;i<values.size();i++)
		sum += values[i];
	cout<<"\nSum "<<sum<<"\n";
	return sum;
}

void findAverageTime(vector<int> burst_time) {
	cout<<"finding average waiting times\n";
        vector<int> waiting_time_values = findWaitingTime(burst_time);
	int totalWaitingTime = findTotalTime(waiting_time_values);
	float average_waiting_time =  totalWaitingTime/burst_time.size();
	cout << "Processes  "<< " Burst time  "
         << " Waiting time  \n";
	cout<<"Average waiting time = "<<average_waiting_time<<"\n";
}

int main() {
	vector<int> burst_time;
	int i=0, time, n;
        cout<<"Enter the number of processes : ";
        cin>>n;
	while(n--) {
		cout<<"Enter process CPU burst time (milliseconds): ";
		cin>>time;
		burst_time.push_back(time);
	}
        findAverageTime(burst_time);
	return 0;
}
