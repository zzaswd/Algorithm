#include <vector>
#include <queue>

// �� ��ǥ�� ���õǸ� �� ��ǥ ���� 4 ������ ��� Ȯ���ϴµ� �׶� ����ϴ� �ΰ��� �迭.
// dx, dy�� �ѹ��� 1,1�� �����ϴ� ���� ���� ������ ���� 0 �� 1/-1�� �����ϴ� �迭.
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

using namespace std;

// 100x100�̶�� ���� ������ �־�����, ��� ��ǥ�� �����ϴ��� ���ϴ��� üũ�ϴ� �迭.
// �̸� �������� 4 ���� �� ��ȴ� ���� �Ȱ��� ������� �˰����� ����ȴ�.
int visited[100][100];

// Ư�� ������ ������ �� �� ������ ��� Ž���ϱ� ���� queue
// �ֺ� 4 ������ ��ǥ�� �� ���� ���� Ȥ�� �湮�ߴ� ��, �ٸ� ���� ��ǥ���� �����ϰ�
// ��� queue�� ���� -> queue�� empty �� ������ �ݺ�.
queue <pair<int, int>> q;

vector<int> solution(int m, int n, vector<vector<int>> picture) {

    // ���������� ����ϱ� ���ؼ� solution �Լ����� �ݵ�� �ʱ�ȭ �����ؾ� �Ѵ�.
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
                // �������� �ʾҰ�, �� ������ ������ �����Ѵٸ� �ٷ� ������ +1���ش�.
                // �̴� �ϳ� �ǽɽ���� �Ʒ� queue while������ ���� idx,jdx ��ǥ�� ����
                // ���� �̾����� ��ǥ�� ��� �����ϱ� ������ 
                // �� for������ �ϳ��� ������ üũ�� �� �ۿ� ����.
                number_of_area++;
                int color = picture[idx][jdx]; // ���� �� üũ
                int size = 0; // �̾����� ������ ����� üũ�ϱ� ���� �� for�� ���� �ʱ�ȭ
                visited[idx][jdx] = 1; // ���������� 1�� ��ȯ.
                q.push({ idx,jdx }); // �ش� ��带 queue�� push.
                size++; // �� ��带 üũ������ size + 1

                        // ���Ⱑ ���̶���Ʈ. 
                while (!q.empty()) {
                    // queue�� ���Ե� ��ǥ�� �� �� ó�� ��带 pop ���ش�.
                    auto cur = q.front();
                    q.pop();
                    // �׸��� �� ��带 �������� 4 ������ ��� Ȯ���غ��µ�
                    // �� �� for���� �� ������ ��ȭ�� ��ǥ�� ������ ����� �ʴ� ��,
                    // �̹� ������ ���� �ƴ� ��, ���� ����� �̾����� ���� �´� ���� Ȯ���Ѵ�.
                    // �ƹ��� ������ ���ٸ� �� ��ǥ�� queue�� �����ϰ� �װ��� �����ٰ� ǥ��,
                    // �׸��� size���� + 1 ���ش�.
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

                // while���� ������ �Ǹ� �̾����� ������ ��� ��ǥ�� �����ϰ� �ǰ�
                // �׶��� �� ������ size�� �� �� �ְ� �ȴ�.
                // ���� �� ������ size�� max�� ���Ͽ� max size�� �����Ѵ�.
                if (size >= max_size_of_one_area) max_size_of_one_area = size;
            }
            // ���� ���� for ���� ���ǵ� �Ƹ� ���� ��ǥ�� �̹� �����Ǿ��� ������
            // ����� ���� ���� for���� continue�� ������ ���̴�.
        }
    }


    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}