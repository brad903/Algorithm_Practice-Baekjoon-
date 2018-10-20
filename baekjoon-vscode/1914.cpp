#include <iostream>
#include <cmath>
int count = 0;
int limit;

void move(int n, int src, int target) {
    printf("%d %d\n", src, target);
}

void hanoi(int n, int fr, int to) {
    count++;
    if(n == 1) {
        move(n, fr, to);
        return;
    }

    int other = 6 - fr - to;
    hanoi(n-1, fr, other);
    move(n, fr, to);
    hanoi(n-1, other, to);
}

int main() {
    long double input;
    scanf("%Lf", &input);
    limit = input;
    printf("%0.0Lf\n", (long double)pow(2, input));
    if(limit <= 20) {
        hanoi(input, 1, 3);
    }
}