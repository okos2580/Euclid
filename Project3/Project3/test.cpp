#include <iostream>
#include <cstdlib>
#include <ctime>
#include "euclid.h"
#include "test.h"

using namespace std;

void test() {
    srand(time(NULL)); // ���� �õ� �ʱ�ȭ

    const int N = 1000; // �׽�Ʈ ���̽��� ��
    int a[N], b[N];

    // �ſ� ū �� ���� �� N�� ����
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 1000000000 + 1; // 1 �̻� 1000000000 ������ ������ ��
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
