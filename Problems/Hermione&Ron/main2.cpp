#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
char mat[100][100];
int result;

void recorre(int r, int c, int res) {
    int dir = 0;
    if(r > m || r < 0 || c > n || c < 0)
        return;
    if(mat[r][c] == 'X')
        return;
    if(mat[r][c] == '*') {
        result = res;
        return;
    }

    if(c + 1 < n && mat[r][c + 1] == '.')
        dir++;
    if(c - 1 >= 0 && mat[r][c - 1] == '.')
        dir++;
    if(r + 1 < m && mat[r + 1][c] == '.')
        dir++;
    if(r - 1 >= 0 && mat[r - 1][c] == '.')
        dir++;

    if(dir > 1)
        res++;

    mat[r][c] = 'X';

    recorre(r + 1, c, res);
    recorre(r - 1, c, res);
    recorre(r, c + 1, res);
    recorre(r, c - 1, res);
}


int main() {
    
    int test, k, x, y;
    
    cin >> test;
    
    while(test > 0){
        result = 0;
        cin >> m >> n;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                cin >> mat[i][j];
                
                if (mat[i][j] == 'M') {
                    x = i;
                    y = j;
                }
            }
        }
        
        cin >> k;
        recorre(x, y, 0);
        if (k == result)
            cout << "Impressed" << endl;
        else
            cout << "Oops!" << endl;
        test--;

        for(int i = 0; i < 100; i++)
        	for(int j = 0; j < 100; j++)
        		mat[i][j] = 'X';
    }
    return 0;
}