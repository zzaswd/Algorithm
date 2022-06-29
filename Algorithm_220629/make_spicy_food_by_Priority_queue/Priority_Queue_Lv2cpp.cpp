
#if 1 // Priority Queue. 블로그 참고, 효율성 굳

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
// [1,2,3] K= 11, S=2
using namespace std;

#define MAX_SIZE 1000000

int heap[MAX_SIZE] = { 0 };
void push(int item, int* n) {
    int i;
    i = ++(*n);

    while (i != 1 && heap[i / 2] > item) {
        heap[i] = heap[i / 2];
        i = i / 2;
    }
    heap[i] = item;
}

int delete_h(int* n) {
    int first, temp, parent, child;
    first = heap[1];
    temp = heap[(*n)--];
    parent = 1;
    child = 2;

    while (child <= *n) {
        if ((child < *n) && (heap[child] > heap[child + 1]))
            child++;

        if (temp <= heap[child])
            break;

        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }

    heap[parent] = temp;
    return first;
}


int solution(vector<int> scoville, int K) {
    int answer = 0;
    int n = 0;
    heap[2] = -1;
    //memset(heap,-1,sizeof(heap));

    for (int idx = 0; idx < scoville.size(); idx++) {
        push(scoville[idx], &n);
    }

    if (heap[1] >= K) return 0;
    if (heap[2] == -1) return -1;


    while (heap[1] < K) {
        answer++;
        int a = delete_h(&n);
        int b = delete_h(&n);
        push(a + 2 * b, &n);
        if (n < 2)
            if (a + 2 * b < K)
                return -1;
    }

    return answer;
}




#endif

























#if 0   // 내가 직접 푼 것. 효율성 탈락
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    sort(scoville.begin(), scoville.end());

    if (scoville.size() < 2) {
        if (scoville[0] >= K)
            return 0;
        else
            return -1;
    }
    while (scoville[0] < K) {
        int a = scoville[0];
        scoville.erase(scoville.begin());
        int b = scoville[0];
        scoville.erase(scoville.begin());
        scoville.push_back(a + 2 * b);
        sort(scoville.begin(), scoville.end());
        answer++;
        if (scoville.size() < 2) {
            return -1;
        }
    }

    return answer;
}

#endif