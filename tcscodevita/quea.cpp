#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

struct Cell {
    int x, y, dist;
};

// Helper function to check if the cell is valid
bool isValid(int x, int y, int M, int N, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    return (x >= 0 && x < M && y >= 0 && y < N && grid[x][y] == 0 && !visited[x][y]);
}

// Function to calculate the new coordinates after applying a move
pair<int, int> getNextMove(int x, int y, int dir, int moveX, int moveY) {
    switch(dir) {
        case 0: // Forward
            return {x + moveX, y + moveY};
        case 1: // Right (90 degrees clockwise)
            return {x + moveY, y - moveX};
        case 2: // Left (90 degrees anticlockwise)
            return {x - moveY, y + moveX};
        case 3: // Backward (180 degrees)
            return {x - moveX, y - moveY};
    }
    return {x, y};
}

int minMovesToReachDestination(int M, int N, vector<vector<int>>& grid, pair<int, int> src, pair<int, int> dest, pair<int, int> moveRule) {
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    queue<Cell> q;

    // Starting from the source
    q.push({src.first, src.second, 0});
    visited[src.first][src.second] = true;

    // 4 possible directions (forward, right, left, backward)
    int directions = 4;

    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        // If we reached the destination
        if (current.x == dest.first && current.y == dest.second)
            return current.dist;

        // Try all 4 directions
        for (int i = 0; i < directions; ++i) {
            pair<int, int> nextMove = getNextMove(current.x, current.y, i, moveRule.first, moveRule.second);
            int nextX = nextMove.first;
            int nextY = nextMove.second;

            if (isValid(nextX, nextY, M, N, grid, visited)) {
                visited[nextX][nextY] = true;
                q.push({nextX, nextY, current.dist + 1});
            }
        }
    }

    // If no path exists
    return -1;
}
int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];

    pair<int, int> src, dest, moveRule;
    cin >> src.first >> src.second;
    cin >> dest.first >> dest.second;
    cin >> moveRule.first >> moveRule.second;

    int result = minMovesToReachDestination(M, N, grid, src, dest, moveRule);
    
    // Ensure that the output is exactly one integer
    cout << result;

    return 0;
}
