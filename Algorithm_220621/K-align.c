#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto com : commands) {
        vector<int> align;
        for (int idx = com[0] - 1; idx < com[1]; idx++) {
            align.push_back(array.at(idx));
        }

        sort(align.begin(), align.end());

        answer.push_back(align[com[2] - 1]);
    }

    return answer;
}