#include <cstdio>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int n;
    scanf("%d", &n);

    vector<int> a(n+1);

    for(int i=1; i<=n; i++){
        int num;
        scanf("%d", &a[i]);
    }

    bool change = false;
    for(int i=1; i<=n; i++){
        change = false;
        for(int j=1; j<=n-1; j++){
            if(a[j] > a[j+1]){
                change = true;
                swap(a[j], a[j+1]);
            }
        }
        if(change == false){
            printf("%d\n", i);
            break;
        }
    }
    


    return 0;
}