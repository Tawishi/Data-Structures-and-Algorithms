#include <bits/stdc++.h>
using namespace std;

vector<float> findWaitingTime(vector<float> arrival_time, vector<float> burst_time) {
	vector<float> waiting_time (burst_time.size(),0);
	for(int i=1;i<waiting_time.size();i++) {
		waiting_time[i] = waiting_time[i-1] + burst_time[i-1] - arrival_time[i];
	}
	return waiting_time;
}

vector<float> findTurnAroundTime(vector<float> burst_time, vector<float> waiting_time) {
	vector<float> turn_around_time (burst_time.size(),0);
	for(int i=0;i<turn_around_time.size();i++) {
		turn_around_time[i] = burst_time[i] + waiting_time[i];
	}
	return turn_around_time;
}

float findTotalTime(vector<float> values) {
	float sum=0;
	for(int i=0;i<values.size();i++)
		sum += values[i];
	return sum;
}

void findAverageTime(vector<float> arrival_time, vector<float> burst_time) {
        vector<float> waiting_time_values = findWaitingTime(arrival_time, burst_time);
	float totalWaitingTime = findTotalTime(waiting_time_values);
	float average_waiting_time = totalWaitingTime/waiting_time_values.size();

	vector<float> turn_around_time_values = findTurnAroundTime(burst_time,waiting_time_values);
	float totalTurnAroundTime = findTotalTime(turn_around_time_values);
	float average_turn_around_time = totalTurnAroundTime/turn_around_time_values.size();

	cout << "Processes  "<<"Arrival time " <<" Burst time  "
         << "\tWaiting time\t"<<"Turn Around Time \n";
	for(int i=0;i<burst_time.size();i++) {
		cout<<i+1<<"\t\t"<<arrival_time[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time_values[i]<<"\t\t"<<turn_around_time_values[i]<<"\n";
	}
	cout<<"Average waiting time = "<<average_waiting_time<<" ms\n";
	cout<<"Average turn-around time = "<<average_turn_around_time<<" ms\n";
}

int main() {
	vector<float> burst_time, arrival_time;
	int n,i=1;
	float time, arrival_time_input;
        cout<<"Enter the number of processes : ";
        cin>>n;
	while(n--) {
		cout<<"Process "<<i++<<"\n";
		cout<<"Enter arrival time: ";
		cin>>arrival_time_input;
		arrival_time.push_back(arrival_time_input);
		cout<<"Enter process CPU burst time (milliseconds): ";
		cin>>time;
		burst_time.push_back(time);
	}
        findAverageTime(arrival_time,burst_time);
	return 0;
}
