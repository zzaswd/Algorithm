#include <vector>
#include <queue>

// 한 좌표가 선택되면 그 좌표 기준 4 방향을 모두 확인하는데 그때 사용하는 두개의 배열.
// dx, dy가 한번에 1,1씩 증가하는 경우는 없기 때문에 서로 0 과 1/-1이 교차하는 배열.
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

using namespace std;

// 100x100이라는 것은 문제에 주어졌고, 모든 좌표를 경유하는지 안하는지 체크하는 배열.
// 이를 기준으로 4 방향 중 들렸던 곳은 안가는 방식으로 알고리즘이 진행된다.
int visited[100][100];

// 특정 영역을 만났을 때 그 영역을 모두 탐색하기 위한 queue
// 주변 4 방향의 좌표들 중 범위 제한 혹은 방문했던 것, 다른 색인 좌표들을 제외하고
// 모두 queue에 삽입 -> queue가 empty 될 때까지 반복.
queue <pair<int, int>> q;

vector<int> solution(int m, int n, vector<vector<int>> picture) {

    // 전역변수를 사용하기 위해선 solution 함수에서 반드시 초기화 진행해야 한다.
    for (int idx = 0; idx < m; idx++) {
        for (int jdx = 0; jdx < n; jdx++) {
            visited[idx][jdx] = 0;
        }
    }

    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int idx = 0; idx < m; idx++) {
        for (int jdx = 0; jdx < n; jdx++) {
            if (visited[idx][jdx] == 0 && picture[idx][jdx] != 0) {
                // 경유하지 않았고, 그 영역에 색깔이 존재한다면 바로 영역을 +1해준다.
                // 이는 꽤나 의심스러운데 아래 queue while문에서 현재 idx,jdx 좌표의 색과
                // 같은 이어지는 좌표는 모두 경유하기 때문에 
                // 한 for문에서 하나의 영역이 체크될 수 밖에 없다.
                number_of_area++;
                int color = picture[idx][jdx]; // 현재 색 체크
                int size = 0; // 이어지는 영역의 사이즈를 체크하기 위해 매 for문 마다 초기화
                visited[idx][jdx] = 1; // 경유했으니 1로 변환.
                q.push({ idx,jdx }); // 해당 노드를 queue에 push.
                size++; // 한 노드를 체크했으니 size + 1

                        // 여기가 하이라이트. 
                while (!q.empty()) {
                    // queue에 삽입된 좌표들 중 맨 처음 노드를 pop 해준다.
                    auto cur = q.front();
                    q.pop();
                    // 그리고 그 노드를 기준으로 4 방향을 모두 확인해보는데
                    // 이 때 for문이 돌 때마다 변화된 좌표가 영역을 벗어나진 않는 지,
                    // 이미 경유한 곳은 아닌 지, 같은 색깔로 이어지는 곳은 맞는 지를 확인한다.
                    // 아무런 문제가 없다면 그 좌표를 queue에 삽입하고 그곳은 지낫다고 표기,
                    // 그리고 size까지 + 1 해준다.
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx >= m || nx < 0 || ny >= n || ny < 0) continue;
                        if (visited[nx][ny] != 0 || picture[nx][ny] != color) continue;
                        visited[nx][ny] = 1;
                        q.push({ nx,ny });
                        size++;
                    }
                }

                // while문이 끝나게 되면 이어지는 색깔의 모든 좌표를 경유하게 되고
                // 그때가 한 영역의 size를 알 수 있게 된다.
                // 따라서 한 영역의 size와 max를 비교하여 max size를 선택한다.
                if (size >= max_size_of_one_area) max_size_of_one_area = size;
            }
            // 이제 다음 for 문을 돌건데 아마 많은 좌표가 이미 경유되었기 때문에
            // 상당히 많은 수의 for문이 continue로 지나갈 것이다.
        }
    }


    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}