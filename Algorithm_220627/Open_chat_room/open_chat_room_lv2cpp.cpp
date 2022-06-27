#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> user_data; // map <id, nickname>
    vector<string> in_out;  // mode,id,mode,id ... ������ string vector

    for (int idx = 0; idx < record.size(); idx++) {
        //"Enter id1234 Muzi" �������� �����Ƿ�, �����ϱ� ���� sstream Ȱ��.
        stringstream splited(record[idx]); // string stream���� ����
        string mode;
        string id;
        string nickname;

        // ���� ���� Mode�� �����ؼ� Ȯ���غ���.
        // �� ������ �ش� ��忡 ���� ������ ���ڼ��� �ٸ��� �����̴�.
        getline(splited, mode, ' ');
        if (mode == "Enter" || mode == "Change") {
            getline(splited, id, ' ');
            getline(splited, nickname, ' ');
        }
        else {
            getline(splited, id, ' ');
        }

        // ���� �Ŀ� ��忡 ���� ������ ������ ����
         // Enter�� ��� map�� id�� nickname�� ��Ʈȭ �� ���ε�
         // �̶� �̹� ���� ���̵�� �α��� �� ���� �ִٸ� nickname�� ��ȯ���ִ� ��������
         // �α��� �� ���� ���ٸ�, ���ο� id�� nickname�� insert���ִ� ��. 
        if (mode == "Enter") {
            if (user_data.find(id) != user_data.end()) {
                user_data[id] = nickname;
            }
            else {
                user_data.insert({ id,nickname });
            }
        }

        // ���� change��� enter�� ���� ���̵� ������ ���� �����ϰ� nickname ��ȯ
        else if (mode == "Change") {
            if (user_data.find(id) != user_data.end()) {
                user_data[id] = nickname;
            }
            else {
                cout << "error!. �ٲ� ���̵� ����";
            }
        }
        // ���������� ���� ���� id�� ������� in_out�� ����
        // 2���� ���͸� ����ϸ� ������ ����ϱ� ������� 1���� ���� �̿�
        in_out.push_back(mode);
        in_out.push_back(id);
    }

    // ���Ե� ��� record�� �Ľ�, mode �м�, in_out log�� ����ٸ�,
    // record�� �����ŭ for ������ �����鼭 �ش� ���� ���.
    // ���⼭ ���� ��� ������ ���� idx�ε� �Ʊ� ������ ���ͷ� �����߱� ������
    // 2*idx�� 2*idx + 1 �� ���� mode�� id�� �����Ѵ�.
    // �̹� map�� id�� nickname�� ��Ʈȭ ���ѳ��ұ� ������ 
    // mode�� ���� id�� �ش��ϴ� nickname�� ����ϱ⸸ �ϸ� �ȴ�.
    for (int idx = 0; idx < record.size(); idx++) {
        if (in_out[idx * 2] == "Enter")
            answer.push_back(user_data[in_out[idx * 2 + 1]] + "���� ���Խ��ϴ�.");
        else if (in_out[idx * 2] == "Leave")
            answer.push_back(user_data[in_out[idx * 2 + 1]] + "���� �������ϴ�.");
        else
            continue;
    }


    return answer;
}