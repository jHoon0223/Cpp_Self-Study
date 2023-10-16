#include <cstdio> 
#include <vector> 

using namespace std; 

int N; 
long long B; 

vector<int> matrixMul(vector<int> &A, vector<int> &B){
    vector<int> C(N*N); 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
               	C[i*N+j] = (C[i*N+j] + A[i*N+k] * B[k*N+j]) % 1000;
            }
        }
    }
    return C;
}
vector<int> solve(vector<int> &A, long long p){
    if(p == 1) return A; 

    vector<int> C = solve(A, p/2);
    C = matrixMul(C , C);

    if(p%2 == 1) C = matrixMul(C, A); 

    return C;
}

int main(){
    scanf("%d %lld", &N, &B);

    vector<int> A(N*N), total;
    for(int i = 0; i < N * N; i++) scanf("%d", &A[i]); 

    total = solve(A, B);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", total[i * N + j] % 1000); 
        }
        printf("\n");
    }   

    return 0; 
}