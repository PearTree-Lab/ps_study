// N-Queen
// https://www.acmicpc.net/problem/9663
#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool> > board;
int N;
int answer = 0;

// 해당 위치에 queen을 놔도 되는지 확인
// 해당 위치를 기준으로 정 윗방향, 왼쪽 대각선 윗방향, 오른쪽 대각선 윗방향에 queen이 있으면 false, 없으면 true
bool check(int r, int c)
{
    for (int i = 0; i < N; i++)
    {
        int r1 = r - i;
        int c0 = c, c1 = c - i, c2 = c + i;
        if (r1 >= 0)
        {
            if (board[r1][c0])
                return false;
            if (c1 >= 0 && board[r1][c1])
                return false;
            if (c2 < N && board[r1][c2])
                return false;
        }
    }
    return true;
}

void dfs(int r, int c)
{
    if (r == N - 1)
    {
        answer += 1;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        // (r+1, i) 위치에 queen을 둬도 되는지 확인
        if (!check(r + 1, i))
            continue;
        board[r + 1][i] = true;
        dfs(r + 1, i);
        board[r + 1][i] = false;
    }
}

int main()
{
    cin >> N;
    board = vector<vector<bool> >(N, vector<bool>(N, false));

    // board의 맨 윗줄(row)부터 queen을 둔다.
    // queen을 둔 곳은 board에 체크해둔다.
    for (int i = 0; i < N; i++)
    {
        board[0][i] = true;
        dfs(0, i);
        board[0][i] = false;
    }
    cout << answer << endl;
    return 0;
}