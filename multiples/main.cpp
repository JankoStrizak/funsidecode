#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b, int c){
    if (a > b){
        if (b > c){
            return c;
        }else{
            return b;
        }
    } else {
        if (a > c){
            return c;
        }else{
            return a;
        }
    }
}

int alg(int n) {
    vector<int> v;
    v.push_back(1);

    int two = 0;
    int three = 0;
    int five = 0;
    int small;

    for (int i = n-1; i > 0; i--) {
        small = min(v[two]*2, v[three]*3, v[five]*5);
        v.push_back(small);
        if (small == v[two]*2) {
            two++;
        }
        if (small == v[three]*3) {
            three++;
        }
        if (small == v[five]*5) {
            five++;
        }
    }
    int r = v.back();
    v.clear();
    return r;
}

int main() {
    bool q = false;
    string input;
    while(!q){
        std::getline (std::cin,input);

        if (input == "quit"){
            q = true;
        }else{
            int n = stoi(input);
            n = alg(n);
            cout << n << endl;
        }
    }
}
