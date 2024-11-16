#include <iostream>
#include <string>
#include <cctype> // 用于大小写转换

using namespace std;

// 查找第 k 个字符
char findKthCharacter(const string& s, long long k) {
    long long n = s.length();
    bool isFlipped = false; // 是否需要大小写翻转

    // 循环处理，直到 k 映射到初始字符串范围
    while (k > n) {
        if (k > 2 * n) {
            // 如果 k 超出当前层，进入上一层
            n *= 2;
        } else {
            // 如果 k 在当前层的后半部分
            isFlipped = !isFlipped;
            k -= n; // 映射到前半部分
        }
    }

    // 找到原始字符串中的字符
    char result = s[k - 1];
    // 如果需要翻转大小写，处理翻转
    return isFlipped ? (islower(result) ? toupper(result) : tolower(result)) : result;
}

// 测试程序
int main() {
    string s = "aB";
    long long k = 8;

    char result = findKthCharacter(s, k);
    cout << "第 " << k << " 个字符是: " << result << endl;

    return 0;
}

