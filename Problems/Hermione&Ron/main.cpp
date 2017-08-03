#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
char mat[100][100];

int recorre(int r, int c) {
    cout<<"entra"<<endl;
    int dir = 0;
    if(r > m || r < 0 || c > n || c < 0)
        return 0;
    if(mat[r][c] == 'X')
        return 0;
    if(mat[r][c] == '*') {
        cout << *res << endl;
        return *res;
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
        *res++;

    mat[r][c] = 'X';
    recorre(r + 1, c, res);
    recorre(r - 1, c, res);
    recorre(r, c + 1, res);
    recorre(r, c - 1, res);
}


int main() {
    
    int test, k, result, x, y;
    
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
        result = recorre(x, y);
        if (k == result)
            cout << "Impressed" << endl;
        else
            cout << "Oops" << endl;
        test--;
    }
    return 0;
}