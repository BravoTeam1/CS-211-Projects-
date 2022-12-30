#include <iostream>
using namespace std;

int main() {
    int q[8], c = 0;
    q[0] = 0;
    nc: c++;
    if(c == 8) goto print;
    q[c] = -1;
    nr: q[c]++;
    if(q[c] == 8) goto backtrack;

    for(int i = 0; i < c; i++)
        if(q[c] == q[i] || (c-i) == abs(q[c] - q[i])) goto nr;
    goto nc;

    backtrack: c--;
    if(c == -1) return 0;
    goto nr;
    
    print:
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(q[i] == j) cout << "Q ";
            else cout << "_ " ;
        }
        cout << endl;
    }
    cout << endl;

    goto backtrack;
}