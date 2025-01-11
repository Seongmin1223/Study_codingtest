#include <string>
#include <vector>
#define INT_MAX 10000000

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, INT_MAX));
    
    for(int i = 0; i< fares.size(); i++){
        matrix[fares[i][0]][fares[i][1]] = fares[i][2];
        matrix[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for(int i = 1; i <= n; ++i){
        matrix[i][i] = 0;
    }
    
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j) 
                if (matrix[i][j] > matrix[i][k] + matrix[k][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
    
    for(int i = 1; i <= n; ++i)
        if (answer > matrix[s][i] + matrix[i][a] + matrix[i][b])
            answer = matrix[s][i] + matrix[i][a] + matrix[i][b];
    
    return answer;
    
    
}