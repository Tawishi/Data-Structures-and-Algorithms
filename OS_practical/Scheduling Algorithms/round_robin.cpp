#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class process {
	public: 
		int pid; 
		int arrival, burst, wait, turn, temp_burst;
		bool complete;
	
		process() {
			pid = 0;
			arrival = burst = wait = turn = temp_burst = 0;
			complete = false;
		}
};

bool compare1(process p1, process p2) 
{ 
    return p1.arrival < p2.arrival;
}


// TODO : replace maxprocessIndex (ordered) with pid 
void queueUpdation(int queue[],int timer,vector<process> Processes,int n, int maxProccessIndex){
	int zeroIndex;
	for(int i = 0; i < n; i++){
		if(queue[i] == 0){
			zeroIndex = i;
			break;
		}
	}
	queue[zeroIndex] = maxProccessIndex + 1;
}

// updates queue after every preemption
void queueMaintainence(int queue[], int n){
	// (i < n-1) && (queue[i+1] != 0) : go upto second last element, queue has one more element
	for(int i = 0; (i < n-1) && (queue[i+1] != 0) ; i++){
		int temp = queue[i];
		queue[i] = queue[i+1];
		queue[i+1] = temp;
	}
}

void checkNewArrival(int timer, vector<process> Processes, int n, int maxProccessIndex,int queue[]){
	if(timer <= Processes[n-1].arrival) {
		bool newArrival = false;
		for(int j = (maxProccessIndex+1); j < n; j++){
				if(Processes[j].arrival <= timer) {
					if(maxProccessIndex < j){
						maxProccessIndex = j;
						newArrival = true;
				}
			}
		}

		//adds any incoming process to the ready queue
		if(newArrival)
			queueUpdation(queue,timer,Processes,n, maxProccessIndex);
	}
}

int main(){
	int n,quanta, timer = 0, maxProccessIndex = 0;
	float avgWait = 0, avgTT = 0;
	cout << "\nEnter the time quanta : ";
	cin>>quanta;
	cout << "\nEnter the number of processes : ";
	cin>>n;
	// int arrival[n], burst[n], wait[n], turn[n], temp_burst[n];
	int queue[n], arrival_input, burst_input;
	// bool complete[n];
	vector <process> Processes (n,process());
	cout << "\nEnter the arrival time of the processes : ";
	for(int i = 0; i < n; i++) {
		cin>>arrival_input;
		Processes[i].pid = i+1;
		Processes[i].arrival = arrival_input;
	}

	cout << "\nEnter the burst time of the processes : ";
	for(int i = 0; i < n; i++){
		cin>>burst_input;
		Processes[i].burst = burst_input;
		Processes[i].temp_burst = Processes[i].burst;
	}
	
	// sort according to arrival time 
	sort(Processes.begin(), Processes.end(), compare1);

	// for(int i = 0; i < n; i++){
	// 	cout<<Processes[i].pid<<" ";	
	// }

	
	for(int i = 0; i < n; i++){
		Processes[i].complete = false;
		queue[i] = 0;
	}

	// inc timer till first process arrives
	while(timer < Processes[0].arrival)
		timer++;
	queue[0] = 1;
	
	while(true){
		bool flag = true; // flag for exiting while loop once processes finish execution
		for(int i = 0; i < n; i++){
			if(Processes[i].temp_burst != 0){ 
				// if even 1 process has not finished execution, break & continue on
				flag = false;
				break;
			}
		}

		if(flag)
			break; // stop if all process execution done

		// (i < n) && (queue[i] != 0) : process is in the ready queue
		for(int i = 0; (i < n) && (queue[i] != 0); i++){
			int ctr = 0; // current running time

			// RRS: running process for qunta time
			while((ctr < quanta) && (Processes[queue[0]-1].temp_burst > 0)){
				Processes[queue[0]-1].temp_burst -= 1;
				timer += 1;
				ctr++;

				//Checking and Updating the ready queue till all the processes arrive
				checkNewArrival(timer, Processes, n, maxProccessIndex, queue);
			}

			// check if process completed
			if((Processes[queue[0]-1].temp_burst == 0) && (Processes[queue[0]-1].complete == false)){
				//turn array currently stores the completion time
				Processes[queue[0]-1].turn = timer;	
				Processes[queue[0]-1].complete = true;
			}
			
			//checks whether or not CPU is idle
			bool idle = true;
			if(queue[n-1] == 0){
				for(int i = 0; i < n && queue[i] != 0; i++){
					if(Processes[queue[i]-1].complete == false){
						idle = false;
					}
				}
			}
			else
				idle = false;

			if(idle){
				timer++;
				checkNewArrival(timer, Processes, n, maxProccessIndex, queue);
			}
	
			//Maintaining the entires of processes
			//after each premption in the ready Queue
			queueMaintainence(queue,n);
		}
	}

	for(int i = 0; i < n; i++){
		Processes[i].turn = Processes[i].turn - Processes[i].arrival;
		Processes[i].wait = Processes[i].turn - Processes[i].burst;
	}

	cout << "\nProcess No.\tArrival Time\tBurst Time\tWait Time\tTurnAround Time"
		<< endl;
	for(int i = 0; i < n; i++){
		cout<<Processes[i].pid<<"\t\t"<<Processes[i].arrival<<"\t\t"
		<<Processes[i].burst<<"\t\t"<<Processes[i].wait<<"\t\t"<<Processes[i].turn<<endl;
	}
	for(int i =0; i< n; i++){
		avgWait += Processes[i].wait;
		avgTT += Processes[i].turn;
	}
	cout<<"\nAverage wait time : "<<(avgWait/n)
	<<"\nAverage Turn Around Time : "<<(avgTT/n);

	return 0;
	
}
