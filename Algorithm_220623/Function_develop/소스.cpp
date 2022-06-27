#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> rest;
    int size = speeds.size();

    for (int idx = 0; idx < size; idx++) {
        rest.push_back(100 - progresses[idx]);
    }

    int finish = 0;
    while (1) {
        int count = 0;
        //cout << finish << endl;
        for (int idx = finish; idx < size; idx++) {
            rest[idx] = rest[idx] - speeds[idx];
            if (rest[idx] <= 0) rest[idx] = 0;
        }

        
        for (int idx = finish; idx < size; idx++) {
            if (rest[idx] <= 0) {
                count++;
                while (1) {
                    if (idx == (size - 1) || rest[idx + 1] > 0) {
                        break;
                    }
                    idx++;
                    count++;
                }
                finish += count;
                answer.push_back(count);
            }
            
            break;
        }
        if (finish >= size ) break;
    }
    
    return answer;
}


int main() {
    vector<int> v1 = { 93, 30, 55 };
    vector<int> v2 = { 1,30,5};
    vector<int> answer = solution(v1, v2);
    for (int idx = 0; idx < answer.size(); idx++) {
        cout << answer[idx] << endl;
    }
    
    return 0;
}