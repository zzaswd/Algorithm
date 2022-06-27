#include <string>
#include <vector>

using namespace std;


// 4 1 4 1   ---
// 3 2 3 2
// 갈색 수가 적으니 갈색 수로 해야겠다.
// 갈색 수 반띵
// 가로 세로 구하면 되는데
// 세로는 1부터 시작
// 이때 가로 길이가 세로보다 2는 커야 함.
// 그래야 전체 가로길이가 세로보다 길다.

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int temp = brown + yellow;
    int half_brown = brown / 2;
    int x = half_brown - 1, y = 1; // x+y = half_brown

    while (x > y - 1) {
        if ((x - 2) * y == yellow)
            break;
        x--;
        y++;
    }
    answer.push_back(x);
    answer.push_back(y + 2);

    return answer;
}