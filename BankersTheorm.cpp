#include<iostream>
using namespace std;
 const  int P=3;
     const int R=4;
bool isSafe(int processes[], int avail[], int max[P][R], int need[P][R], int alloc[P][R]) {
    int work[R];
    int safeseq[P];
    bool finish[P] = {false};
    
    for (int i = 0; i < R; i++) {
        work[i] = avail[i];
    }
    
    int p = 0;

    while (p < P) {
        bool done = false;

        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                
                int j;
                
                for (j = 0; j < R; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == R) {
                    
                    for (int k = 0; k < R; k++) {
                        work[k] += alloc[i][k];
                    }

                    safeseq[p++] = i;
                    finish[i] = true;
                    done = true;
                }
            }
        }

        if (!done) {
            cout << "System is not in a safe state.\n";
            return false;
        }

    }

    cout << "System is in a safe state.\nSafe sequence: ";
    for (int i = 0; i < P; i++) {
        cout << "P" << safeseq[i] << " ";
    }
    cout << endl;

    return true;
}



int main(int argc, char const *argv[])
{
   
     int processes[P] = {0, 1, 2};
   int available[R] = {3, 3, 2, 2};
      int max[P][R] = {
        {7, 5, 3, 4},
        {3, 2, 2, 2},
        {9, 0, 2, 2}
    };
     int alloc[P][R] = {
        {0, 1, 0, 2},
        {2, 0, 0, 1},
        {3, 0, 2, 2}
    };
    int need[P][R] = {
        {7, 4, 3, 2},
        {1, 2, 2, 1},
        {6, 0, 0, 0}
    };
     isSafe(processes, available, max, alloc, need);
    return 0;
}
