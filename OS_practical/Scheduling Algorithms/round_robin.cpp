#include <bits/stdc++.h>
using namespace std;

#define QUANTA 2

class Process {
	public:
	int burst_time;
	int arrival_time;
	int id;
};

vector<int> findWaitingTime(vector<Process> processes, int quanta) {
	int N = processes.size();
    vector<int> waiting_time (N,0);
    int time=0, remaining_time[N], completed=0;
    for(int i=0;i<N;i++)
        remaining_time[i] = processes[i].burst_time;
	
    while(completed !=N) {
        for(int i=0;i<N;i++) {
            if(processes[i].arrival_time <= time) {
                if(remaining_time[i] > 0) {
                    if(remaining_time[i] > quanta) {
                        time += quanta;
                        remaining_time[i] -= quanta;
                    }
                    else {
                        time += remaining_time[i];
                        waiting_time[i] = time - processes[i].arrival_time - processes[i].burst_time;
                        remaining_time[i] = 0;
                        completed++;
                    }
                }
            }
	    }
    }
	return waiting_time;
}

vector<int> findTurnAroundTime(vector<Process> processes, vector<int> waiting_time) {
	vector<int> turn_around_time (processes.size(),0);
	for(int i=0;i<turn_around_time.size();i++) {
		turn_around_time[i] = processes[i].burst_time + waiting_time[i];
	}
	return turn_around_time;
}

int findTotalTime(vector<int> values) {
	int sum=0;
	for(int i=0;i<values.size();i++)
		sum += values[i];
	return sum;
}

void findAverageTime(vector<Process> processes, int quanta) {
    vector<int> waiting_time_values = findWaitingTime(processes, quanta);
	int totalWaitingTime = findTotalTime(waiting_time_values);
	float average_waiting_time = float(totalWaitingTime)/float(waiting_time_values.size());

	vector<int> turn_around_time_values = findTurnAroundTime(processes, waiting_time_values);
	int totalTurnAroundTime = findTotalTime(turn_around_time_values);
	float average_turn_around_time = float(totalTurnAroundTime)/float(turn_around_time_values.size());

	cout << "Processes  "<<"Arrival time " <<" Burst time  "
         << "\tWaiting time\t"<<"Turn Around Time \n";
    
	for(int i=0;i<processes.size();i++) {
		cout<<processes[i].id<<"\t\t"<<processes[i].arrival_time<<"\t\t"<<processes[i].burst_time<<"\t\t"<<waiting_time_values[i]<<"\t\t"<<turn_around_time_values[i]<<"\n";
	}
	cout<<"Average waiting time = "<<average_waiting_time<<"\n";
	cout<<"Average turn-around time = "<<average_turn_around_time<<"\n";
}

int main() {
	int n, i=0, time, arrival_time_input, quanta;
    cout<<"Enter the time quanta: ";
    cin>>quanta;
    cout<<"Enter the number of processes : ";
    cin>>n;
	vector<Process> processes (n, {0,0,0});
	while(n--) {
		processes[i].id = i+1;
		cout<<"Process "<<i+1<<"\n";
		cout<<"Enter arrival time: ";
		cin>>arrival_time_input;
		processes[i].arrival_time = arrival_time_input;
		cout<<"Enter process CPU burst time (milliseconds): ";
		cin>>time;
		processes[i].burst_time = time;
		i++;
	}
    findAverageTime(processes,quanta);
	return 0;
}
