#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

const int maxn = 100000 + 50, TYPE_NUM = 0, TYPE_SUM = 1;
LL N, A, B, numSegma[maxn], sumSegma[maxn];

struct BIT {
    LL bit[maxn], n;
    void init(int _n) {
        n = _n + 5;
        memset(bit, 0, sizeof(bit));
    }
    void update(int x, LL a) {
        x++;
        if (x <= 0)
            return;
        for (; x <= n; x += (x & -x))
            bit[x] += a;
    }
    LL query(int x) {
        x++;
        if (x <= 0)
            return 0;
        LL ret = 0;
        for (; x; x -= (x & -x))
            ret += bit[x];
        return ret;
    }
} bitNum[2], bitSum[2];

void Update(int type, int type2, LL x) {
    if (type2 == TYPE_NUM) {
        bitNum[type].update(x + 1, 1);
        //printf("update: %d %lld\n", type, x);
    } else {
        bitSum[type].update(x + 1, x);
        //printf("query: %d %lld\n", type, x);
    }
}

LL Query(int type, int type2, LL x) {
    if (type2 == TYPE_NUM)
        return bitNum[type].query(x);
    else
        return bitSum[type].query(x);
}

void Init() {
    bitNum[0].init(B);
    bitNum[1].init(B);
    bitSum[0].init(B);
    bitSum[1].init(B);
}

int main() {
    int test;    scanf("%d", &test);
    while (test--) {
        int in1, in2, in3;
        scanf("%d %d %d", &in1, &in2, &in3);
        N = in1;
        N--;
        A = in2;
        B = in3;

        if (A > B)
            swap(A, B);
        // A <= B

        LL num1 = (N - 1) / A + 1;
        LL num2 = num1 - 1;
        LL rem1 = num1 % B;
        LL rem2 = num2 % B;

        Init();
        for (LL x = 0; x < rem1; x++) {
            Update(0, TYPE_NUM, x * A % B);
            Update(0, TYPE_SUM, x * A % B);
        }
        for (LL x = 0; x < rem2; x++) {
            Update(1, TYPE_NUM, x * A % B);
            Update(1, TYPE_SUM, x * A % B);
        }

        memset(numSegma, 0, sizeof(numSegma));
        memset(sumSegma, 0, sizeof(sumSegma));
        for (LL i = 0; i < B; i++) {
            LL x = i * A % B;
            numSegma[x]++;
            sumSegma[x] += x;
        }
        for (LL x = 1; x < B; x++) {
            numSegma[x] += numSegma[x - 1];
            sumSegma[x] += sumSegma[x - 1];
        }

        LL res = 0;
        for (LL x = 0; x < A && x < N; x++) {
            LL num = (N -x) / A + 1;
            LL mul = num / B;
            LL rem = num % B;

            int type = (num == num1) ? 0 : 1;
            // < B - x
            LL numGreater0 = Query(type, TYPE_NUM, B - x);
            LL numGreater = mul * numSegma[B - x - 1] + numGreater0; 
            LL numLess = num - numGreater;

            LL tmp = sumSegma[B - x - 1] ;
            LL tmp2 = Query(type, TYPE_SUM, B - x);
            LL sumGreater = mul * sumSegma[B - x - 1] + tmp2 + x * numGreater;
            //LL sumLess = mul * (sumSegma[B - 1] - tmp + x - B) 
                //+ (Query(type, TYPE_SUM, B) - tmp2 + (x - B) * (rem - numGreater0));
            LL sumLess = mul * (sumSegma[B - 1] - sumSegma[B - x - 1])
                + (Query(type, TYPE_SUM, B) - tmp2) + (x - B) * numLess;
            LL add = sumGreater - sumLess + (numLess - numGreater) * x;
//printf("[x:%lld][ng:%lld][nl:%lld][sg:%lld][sl:%lld]\n", x, numGreater, numLess, sumGreater, sumLess);
            res += add;
        }
        cout << res << endl;
    }
    return 0;
}
