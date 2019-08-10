#include <iostream>
using namespace std;

int d[26][2];

int change_char(char c){
    if(c >= 'A' && c <= 'Z') return c-'A';
    else return -1;
}

void preorder(int i){
    cout << (char)(i+'A');
    if(d[i][0] != -1) preorder(d[i][0]);
    if(d[i][1] != -1) preorder(d[i][1]);
}

void inorder(int i){
    if(d[i][0] != -1) inorder(d[i][0]);
    cout << (char)(i+'A');
    if(d[i][1] != -1) inorder(d[i][1]);
}

void postorder(int i){
    // if(d[i][0] != -1) postorder(d[i][0]);
    // if(d[i][1] != -1) postorder(d[i][1]);
    // cout << (char)(i+'A');
    if(i == -1) return;
    postorder(d[i][0]);
    postorder(d[i][1]);
    cout << (char)(i+'A');
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        char m, l, r;
        cin >> m >> l >> r;
        m = change_char(m); l = change_char(l); r = change_char(r);
        d[m][0] = l;
        d[m][1] = r;
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';

    return 0;
}