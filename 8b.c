#include <stdio.h>
#define ll long long

// 打印整數的二進制表示
void printBinary(unsigned int num) {
    unsigned int mask = 1 << 31;  // 從最高位開始

    for (int i = 0; i < 32; i++) {
        if (num & mask) {
            putchar('1');
        } else {
            putchar('0');
        }
        mask >>= 1;  // 掩碼右移一位
    }
    putchar('\n');
}

void get(float a) {
    unsigned int get_hex;
    get_hex = *(unsigned int*)&a;  // hex必須要用unsigned int來取值
                                   ///  printf("hex: %08x\n", get_hex); // 使用%08x確保輸出8位的十六進制數

    // 打印二進制表示
    //  printf("bin: ");
    printBinary(get_hex);
}

int main() {
    float r;

    // 讀取直到EOF
    while (scanf("%f", &r) != EOF) {
        get(r);
    }

    return 0;
}
