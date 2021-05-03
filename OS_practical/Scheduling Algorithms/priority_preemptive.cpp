#include <bits/stdc++.h>
using namespace std;

class Process {
	public:
	float burst_time;
	float arrival_time;
	int id;
    int priority;
};

vector<float> findWaitingTime(vector<Process> processes) {
    int N = processes.size();
	vector<float> waiting_time (N,0);

	int remaining_time[N], time=0, completed=0, critical=0, current_priority=INT_MAX, finish_time=0;
	bool ongoing_process = false; 

	for(int i=0;i<N;i++)
		remaining_time[i] = processes[i].burst_time;
	
	while(completed != N) {
		for(int i=0;i<N;i++) {
			if((processes[i].arrival_time <= time) && (processes[i].priority<current_priority) && (remaining_time[i]>0)) {
				current_priority = processes[i].priority;
				critical = i;
				ongoing_process = true;
			}
		}

		if(ongoing_process != true) {
			time++;
			continue;
		}

		remaining_time[critical]--;

		if(remaining_time[critical] == 0) {
			completed++;
			finish_time = time+1;
			ongoing_process = false;

			waiting_time[critical] = finish_time - processes[critical].burst_time - processes[critical].arrival_time;

			current_priority = INT_MAX;

			if(waiting_time[critical] < 0 )
				waiting_time[critical] = 0;

		}
		time++;
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

	cout << "Processes  "<<"Arrival time " <<"  Priority  "<<"  Burst time  "
         << "\tWaiting time\t"<<"Turn Around Time \n";
	for(int i=0;i<processes.size();i++) {
		cout<<processes[i].id+1<<"\t\t"<<processes[i].arrival_time<<"\t\t"<<processes[i].priority<<"\t\t"<<processes[i].burst_time<<"\t\t"<<waiting_time_values[i]<<"\t\t"<<turn_around_time_values[i]<<"\n";
	}

	cout<<"Average waiting time = "<<average_waiting_time<<"\n";
	cout<<"Average turn-around time = "<<average_turn_around_time<<"\n";
}

int main() {
	int n,i=0;
	float time, arrival_time_input;
    int priority_input;
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
        cout<<"Enter process priority: ";
		cin>>priority_input;
		processes[i].priority = priority_input;
		i++;
	}
    findAverageTime(processes);
	return 0;
}