#include<bits/stdc++.h>

using namespace std;

int _mutex = 1;
int full = 0, empty = 10, item = 0;

void producer() {
    --_mutex;
    ++full;
    --empty;
    item++;
    cout<<"\nProducer produces item "<<item;
    ++_mutex;

}

void consumer() {
    --_mutex;
    --full;
    ++empty;
    cout<<"\nConsumer consumes item "<<item;
    item--;
    ++_mutex;
}

int main() {
    cout<<"\n1. Press 1 for Producer"
        <<"\n2. Press 2 for Consumer"
        << "\n3. Press 3 to Exit";

    int n;
    for (int i = 1; i > 0; i++) {
  
        cout<<"\nEnter your choice:";
        cin>>n;
  
        // Switch Cases
        switch (n) {
        case 1:
  
            if ((_mutex == 1) && (empty != 0)) {
                producer();
            }
  
            else {
                cout<<"Buffer is full!";
            }
            break;
  
        case 2:

            if ((_mutex == 1) && (full != 0)) {
                consumer();
            }
  
            else {
                cout<<"Buffer is empty!";
            }
            break;
  
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}