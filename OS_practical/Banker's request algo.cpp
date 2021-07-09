#include<iostream>
using namespace std;

const int N = 5;

const int M = 3;

// Function to find the need of each process
void calculateNeed(int need[N][M], int maxm[N][M],
				int allot[N][M])
{
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)

			need[i][j] = maxm[i][j] - allot[i][j];
}

// resouce allocation
void resource(int need[N][M], int available[M], int allocation[N][M]) {
    int request[M];
    int p;
    cout<<"\nEnter requesting process : ";
    cin>>p;
    cout<<"Enter the request : ";
    for(int i=0;i<M;i++)
        cin>>request[i];
    for(int j=0;j<M;j++) {
        if(request[j] > need[p][j]) {
            cout<<"error\n"; //error
            return;
        }
        if(request[j] > available[j]) {
            cout<<"wait\n";
            return;
        }
        available[j] -= request[j];
        allocation[p][j] += request[j];
        need[p][j] -= request[j]; 
    }
    cout<<"Request granted\n";
}

// Function to find the system is in safe state or not
bool isSafe(int processes[], int avail[], int maxm[][M],
			int allot[][M], int need[][M])
{
	
	calculateNeed(need, maxm, allot);


	bool finish[N] = {0};


	int safeSeq[N];


	int work[M];
	for (int i = 0; i < M ; i++)
		work[i] = avail[i];

	
	int count = 0;
	while (count < N)
	{

		bool found = false;
		for (int p = 0; p < N; p++)
		{

			if (finish[p] == 0)
			{

				int j;
				for (j = 0; j < M; j++)
					if (need[p][j] > work[j])
						break;

				// If all needs of p were satisfied.
				if (j == M)
				{

					for (int k = 0 ; k < M ; k++)
						work[k] += allot[p][k];


					safeSeq[count++] = p;

					finish[p] = 1;

					found = true;
				}
			}
		}


		if (found == false)
		{
			cout << "System is not in safe state";
			return false;
		}
	}


	cout << "System is in safe state.\nSafe"
		" sequence is: ";
	for (int i = 0; i < N ; i++)
		cout << safeSeq[i] << " ";

	return true;
}

// Driver code
int main()
{
	int processes[] = {0, 1, 2, 3, 4};


	int avail[] = {3, 3, 2};


	int maxm[][M] = {{7, 5, 3},
					{3, 2, 2},
					{9, 0, 2},
					{2, 2, 2},
					{4, 3, 3}};


	int allot[][M] = {{0, 1, 0},
					{2, 0, 0},
					{3, 0, 2},
					{2, 1, 1},
					{0, 0, 2}};


    int need[N][M];
    isSafe(processes, avail, maxm, allot, need);
    resource(need, avail, allot);
    isSafe(processes, avail, maxm, allot, need);
	return 0;
}
