#include <bits/stdc++.h>
using namespace std;

class Process {
	public:
	float burst_time;
	float arrival_time;
	float id;
};

bool less_than(Process p1, Process p2) {
		return (p1.burst_time < p2.burst_time);
}

vector<float> findWaitingTime(vector<Process> processes) {
	vector<float> waiting_time (processes.size(),0);
	waiting_time[0] = 0;
	for(int i=1;i<waiting_time.size();i++) {
		waiting_time[i] = waiting_time[i-1] + processes[i-1].burst_time - processes[i].arrival_time;
	}
	return waiting_time;
}

vector<float> findTurnAroundTime(vector<Process> processes, vector<float> waiting_time) {
	vector<float> turn_around_time (processes.size(),0);
	for(int i=0;i<turn_around_time.size();i++) {
		turn_around_time[i] = processes[i].burst_time + waiting_time[i];
	}
	return turn_around_time;
}

float findTotalTime(vector<float> values) {
	float sum=0;
	for(int i=0;i<values.size();i++)
		sum += values[i];
	return sum;
}

void findAverageTime(vector<Process> processes) {
    vector<float> waiting_time_values = findWaitingTime(processes);
	float totalWaitingTime = findTotalTime(waiting_time_values);
	float average_waiting_time = totalWaitingTime/waiting_time_values.size();

	vector<float> turn_around_time_values = findTurnAroundTime(processes, waiting_time_values);
	float totalTurnAroundTime = findTotalTime(turn_around_time_values);
	float average_turn_around_time = totalTurnAroundTime/turn_around_time_values.size();

	cout << "Processes  "<<"Arrival time " <<" Burst time  "
         << "\tWaiting time\t"<<"Turn Around Time \n";
	for(int i=0;i<processes.size();i++) {
		cout<<processes[i].id<<"\t\t"<<processes[i].arrival_time<<"\t\t"<<processes[i].burst_time<<"\t\t"<<waiting_time_values[i]<<"\t\t"<<turn_around_time_values[i]<<"\n";
	}
	cout<<"Average waiting time = "<<average_waiting_time<<"\n";
	cout<<"Average turn-around time = "<<average_turn_around_time<<"\n";
}


void sort_processes(vector<Process>& processes) {
	sort(processes.begin(),processes.end(),less_than);
}

int main() {
	int n,i=0;
	float time, arrival_time_input;
    cout<<"Enter the number of processes : ";
    cin>>n;
	vector<Process> processes (n, {0,0,0});
	while(n--) {
		processes[i].id = i;
		cout<<"Process "<<i+1<<"\n";
		cout<<"Enter arrival time: ";
		cin>>arrival_time_input;
		processes[i].arrival_time = arrival_time_input;
		cout<<"Enter process CPU burst time (milliseconds): ";
		cin>>time;
		processes[i].burst_time = time;
		i++;
	}
	sort_processes(processes);
    findAverageTime(processes);
	return 0;
}
