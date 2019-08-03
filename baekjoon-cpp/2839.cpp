#include <stdio.h>
#include <algorithm>
using namespace std;
int d[5001];

int main() {
    d[1] = -1, d[2] = -1, d[3] = 1, d[4] = -1, d[5] = 1;
    int a;
    scanf("%d", &a);

    for(int i = 6; i <= a; i++) {
        int temp = -1;
        for(int j = 3; j <= i/2; j++) {
            if(d[j] > 0 && d[i - j] > 0) {
                if(temp > 0) {
                    temp = min(temp, d[j] + d[i - j]);
                    continue;
                }
                    temp = d[j] + d[i - j];
            }
        }
        d[i] = temp;
    }

    printf("%d\n", d[a]);
}