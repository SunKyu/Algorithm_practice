#include<iostream>
using namespace std;

int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if(B==0){
        return 1;
    }
    int count = 0;
    count = B/K;
    if(A==0){
        return count+1;
    }
    count = count - A/K;
    if(A%K==0)
        count++;
    return count;
}
int main(void){
    cout<<solution(0, 0, 11)<<endl;
    cout<<solution(1, 1, 11)<<endl;
    cout<<solution(6, 11, 2)<<endl;
    cout<<solution(0, 10, 2)<<endl;

}