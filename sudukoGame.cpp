#include <iostream>
using namespace std;

class Sudoku {
private:
    int grid[9][9];

public:
    Sudoku() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                grid[i][j] = 0;
            }
        }
    }

    void display() {
       // cout << "\n    0 1 2   3 4 5   6 7 8" << endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == 0)
                {
                    grid[i][j]=0;
                    cout << grid[i][j]<<" ";}
                else cout << grid[i][j] << " ";
            }
            cout << endl;
        
        }
        cout << endl;
    }

    bool isSafe(int row, int col, int num) {
        // Check Row
        for (int x = 0; x < 9; x++) {
            if (grid[row][x] == num) {
                return false;
            }
        }

        // Check Column
        for (int x = 0; x < 9; x++) {
            if (grid[x][col] == num) {
                return false;
            }
        }

        // Check 3x3 Subgrid
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    bool makeMove(int row, int col, int num) {
        if (row < 0 || row > 8 || col < 0 || col > 8) {
            cout << "Error: Position out of bounds! Use 0-8." << endl;
            return false;
        }
        if (num < 1 || num > 9) {
            cout << "Error: Number must be between 1 and 9." << endl;
            return false;
        }
        if (grid[row][col] != 0) {
            cout << "Error: Cell already occupied!" << endl;
            return false;
        }
        
        if (isSafe(row, col, num)) {
            grid[row][col] = num;
            cout << "Success: Placed " << num << " at (" << row << ", " << col << ")" << endl;
            return true;
        } else {
            cout << "Invalid Move! Number violates Sudoku rules (row, column, or 3x3 block)." << endl;
            return false;
        }
    }
};

int main() {
    Sudoku game;
    int row, col, num;
    
    cout << "=== SUDOKU GAME ===" << endl;
    cout << "Enter coordinates and number to fill the board." << endl;
    
    while (true) {
        game.display();
        
        cout << "Enter Row (0-8), Column (0-8), and Number (1-9)." << endl;
        cout << "Enter -1 to Exit." << endl;
        cout << "Input: ";
        
        if (!(cin >> row)) {
            // Handle non-integer input to avoid infinite loop
            cin.clear();
            cin.ignore(10000, '\n'); 
            cout << "Invalid input. Please enter numbers." << endl;
            continue;
        }
        
        if (row == -1) {
            cout << "Exiting..." << endl;
            break;
        }
        
        cin >> col >> num;
        
        game.makeMove(row, col, num);
    }

    return 0;
}