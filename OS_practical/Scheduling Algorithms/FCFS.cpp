#include <bits/stdc++.h>
using namespace std;

vector<int> findWaitingTime(vector<int> burst_time) {
	vector<int> waiting_time (burst_time.size(),0);
	for(int i=1;i<burst_time.size();i++) {
		waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
	}
	return waiting_time;
}

vector<int> findTurnAroundTime(vector<int> burst_time, vector<int> waiting_time) {
	vector<int> turn_around_time;
	for(int i=0;i<burst_time.size();i++) {
		turn_around_time[i] = burst_time[i] + waiting_time[i];
	}
	return turn_around_time;
}

int findTotalTime(vector<int> values) {
	int sum=0;
	for(int i=0;i<values.size();i++)
		sum += values[i];
	return sum;
}

void findAverageTime(vector<int> burst_time) {
        vector<int> waiting_time_values = findWaitingTime(burst_time);
	int totalWaitingTime = findTotalTime(waiting_time_values);
	float average_waiting_time = float(totalWaitingTime)/float(burst_time.size());

	vector<int> turn_around_time_values = findTurnAroundTime(burst_time,waiting_time_values);
	int totalTurnAroundTime = findTotalTime(turn_around_time_values);
	float average_turn_around_time = float(totalTurnAroundTime)/float(burst_time.size());
	cout << "Processes  "<< " Burst time  "
         << " Waiting time\t\t"<<"Turn Around Time \n";
	for(int i=0;i<burst_time.size();i++) {
		cout<<i+1<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time_values[i]<<"\t\t"<<turn_around_time_values[i]<<"\n";
	}
	cout<<"Average waiting time = "<<average_waiting_time<<"\n";
	cout<<"Average turn-around time = "<<average_turn_around_time<<"\n";
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
