int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int a[33] = {0,};
    for(int i = 0; i<33; i++){
        a[i] = N%2;
        N = N/2;
    }
    int length = 0;
    int longest_length = 0;
    int start = 0;
    for(int i = 32; i>=0; i--){
        if(a[i] == 1){
            start = i;
            longest_length = max(length, longest_length);
            length = 0;
        }
        else{
            if(start > i){
                length++;
            }
        }
    }
    
    return longest_length;
}