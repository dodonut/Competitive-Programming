
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>
using std::cin;
using std::string;
bool done = false;

int mat[9][9];
bool check[9][9];

void print_mat() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", mat[i][j]);
            if ((j + 1) % 3 == 0) printf("  ");
        }
        if ((i + 1) % 3 == 0) printf("\n");
        printf("\n");
    }
}

bool valid(int r, int c, int value) {
    for (int i = 0; i < 9; i++) {
        if (mat[r][i] == value || mat[i][c] == value) {
            return false;
        }
    }

    for (int i = 3 * (r / 3); i < 3 * ((r + 3) / 3); i++) {
        for (int j = 3 * (c / 3); j < 3 * ((c + 3) / 3); j++) {
            if (mat[i][j] == value) {
                return false;
            }
        }
    }

    return true;
}

void solve_sudoku(int pos, int value) {
    if (pos == 81) {
        done = true; return;
    }
    if (value > 9) return;
    while(check[pos/9][pos%9] != 0) pos++;
    int r = pos / 9;
    int c = pos % 9;
    if(!valid(r,c,value)) solve_sudoku(pos, value + 1);
    else {
        for (int i = pos; i < 81 && !done; i++) {
            mat[r][c] = value;
            solve_sudoku(pos + 1, 1);
            while(!valid(r,c,value) && !done) {
                value++;
            }
            if (value > 9) {
                mat[r][c] = 0;
                break;
            }
        }
    }
}


int main() {
    string c;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            mat[i][j] = 0;
            check[i][j] = 0;
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> c;
            if (c != "x") {
                mat[i][j] = std::stoi(c);
                check[i][j] = 1;
            }
        }
    }

    solve_sudoku(0, 1);

    print_mat();
}

