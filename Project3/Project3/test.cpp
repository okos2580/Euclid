#include <iostream>
#include <cstdlib>
#include <ctime>
#include "euclid.h"
#include "test.h"

using namespace std;

void test() {
    srand(time(NULL)); // 랜덤 시드 초기화

    const int N = 1000; // 테스트 케이스의 수
    int a[N], b[N];

    // 매우 큰 두 수의 쌍 N개 생성
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 1000000000 + 1; // 1 이상 1000000000 이하의 랜덤한 수
        b[i] = rand() % 1000000000 + 1;
    }

    clock_t start_recursive = clock();
    int result_recursive;
    for (int i = 0; i < N; i++) {
        result_recursive = euclid_recursive(a[i], b[i]);
    }
    clock_t end_recursive = clock();

    clock_t start_repeatitive = clock();
    int result_repeatitive;
    for (int i = 0; i < N; i++) {
        result_repeatitive = euclid_repeatitive(a[i], b[i]);
    }
    clock_t end_repeatitive = clock();

    cout << "Recursive: " << result_recursive << endl;
    cout << "Time taken by recursive: " << double(end_recursive - start_recursive) / CLOCKS_PER_SEC << " seconds" << endl;

    cout << "Repeatitive: " << result_repeatitive << endl;
    cout << "Time taken by repeatitive: " << double(end_repeatitive - start_repeatitive) / CLOCKS_PER_SEC << " seconds" << endl;
}
