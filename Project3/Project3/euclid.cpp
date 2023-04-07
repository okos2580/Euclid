#include "euclid.h"
int euclid_recursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return euclid_recursive(b, a % b);
    }

}

int euclid_repeatitive(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}