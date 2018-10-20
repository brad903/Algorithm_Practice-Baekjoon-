#include <vector>
#include <iostream>
using namespace std;

int d[41];
int zero[41];
int one[41];

void fibonacci(int n) {
    
    if(d[n-1] == 0) {
        fibonacci(n - 1);
    }
    if(d[n-2] == 0) {
        fibonacci(n - 2);
    }

    d[n] = 1;
    zero[n] = zero[n-1] + zero[n-2];
    one[n] = one[n-1] + one[n-2];
}

int main() {
    d[0] = 1, d[1] = 1, d[2] = 1;
    zero[0] = 1, zero[1] = 0, zero[2] = 1;
    one[0] = 0, one[1] = 1, one[2] = 1;

    int input;
    scanf("%d", &input);
    for(int i = 0 ; i < input; i++) {
        int temp;
        scanf("%d", &temp);
        if(temp > 2) {
            fibonacci(temp);
        }
        printf("%d %d\n", zero[temp], one[temp]);
    }
    return 0;
}