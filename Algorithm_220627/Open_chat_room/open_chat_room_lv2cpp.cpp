#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> user_data; // map <id, nickname>
    vector<string> in_out;  // mode,id,mode,id ... 저장할 string vector

    for (int idx = 0; idx < record.size(); idx++) {
        //"Enter id1234 Muzi" 형식으로 들어오므로, 분할하기 위한 sstream 활용.
        stringstream splited(record[idx]); // string stream으로 분할
        string mode;
        string id;
        string nickname;

        // 가장 먼저 Mode를 분할해서 확인해본다.
        // 그 이유는 해당 모드에 따라 들어오는 인자수가 다르기 때문이다.
        getline(splited, mode, ' ');
        if (mode == "Enter" || mode == "Change") {
            getline(splited, id, ' ');
            getline(splited, nickname, ' ');
        }
        else {
            getline(splited, id, ' ');
        }

        // 분할 후에 모드에 따라 수행할 동작을 정의
         // Enter의 경우 map에 id와 nickname을 세트화 할 것인데
         // 이때 이미 같은 아이디로 로그인 한 적이 있다면 nickname을 변환해주는 방향으로
         // 로그인 한 적이 없다면, 새로운 id와 nickname을 insert해주는 것. 
        if (mode == "Enter") {
            if (user_data.find(id) != user_data.end()) {
                user_data[id] = nickname;
            }
            else {
                user_data.insert({ id,nickname });
            }
        }

        // 만약 change라면 enter의 기존 아이디 존재할 때와 동일하게 nickname 변환
        else if (mode == "Change") {
            if (user_data.find(id) != user_data.end()) {
                user_data[id] = nickname;
            }
            else {
                cout << "error!. 바꿀 아이디가 없다";
            }
        }
        // 마지막으로 현재 모드와 id를 순서대로 in_out에 저장
        // 2차원 벡터를 사용하면 좋은데 사용하기 어려워서 1차원 벡터 이용
        in_out.push_back(mode);
        in_out.push_back(id);
    }

    // 기입된 모든 record로 파싱, mode 분석, in_out log를 남겼다면,
    // record의 사이즈만큼 for 구문을 돌리면서 해당 문구 출력.
    // 여기서 주의 깊게 봐야할 점은 idx인데 아까 일차원 벡터로 저장했기 때문에
    // 2*idx와 2*idx + 1 로 각각 mode와 id에 접근한다.
    // 이미 map에 id와 nickname을 세트화 시켜놓았기 떄문에 
    // mode에 따라 id에 해당하는 nickname을 출력하기만 하면 된다.
    for (int idx = 0; idx < record.size(); idx++) {
        if (in_out[idx * 2] == "Enter")
            answer.push_back(user_data[in_out[idx * 2 + 1]] + "님이 들어왔습니다.");
        else if (in_out[idx * 2] == "Leave")
            answer.push_back(user_data[in_out[idx * 2 + 1]] + "님이 나갔습니다.");
        else
            continue;
    }


    return answer;
}