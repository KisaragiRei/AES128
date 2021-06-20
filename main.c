#include "aes.h"
// 与http://tool.chacuo.net/cryptaes结果一致
// 模式ECB 填充no padding 数据块128位 输出hex 字符集GB2312

/*
 * 输入16bytes密钥:61616161616161616161616161616161
 * 选择操作:
 * 1-字节码加密
 * 2-字节码解密
 * 3-文件加密
 * 4-文件解密
 * 1
 * 输入需要加密的字节码:61616161616161616161616161616161
 * 加密结果:51 88 c6 47 4b 22 8c bd d2 42 e9 12 5e be 1d 53
 */

int main()
{
    int choice;
    bytes key[128]; // 128位密钥
    bytes plain_text[16]; // 字节加密的明文
    bytes cipher_text[16]; // 字节加密的密文
    printf("输入16bytes密钥:");
    myscanf(key);

    init_mt(NULL, NULL, NULL, NULL, key); // 对密钥矩阵初始化
    key_ext(); // 密钥扩展

    printf("选择操作:\n");
    printf("1-字节码加密\n");
    printf("2-字节码解密\n");
    printf("3-文件加密\n");
    printf("4-文件解密\n");

    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            printf("输入需要加密的字节码:");
            myscanf(plain_text);
            aes_encrypt(plain_text, cipher_text);
            printf("加密结果:");
            myprintf(cipher_text, 16);
            break;
        case 2:
            printf("输入需要解密的字节码:");
            myscanf(cipher_text);
            aes_decrypt(cipher_text, plain_text);
            printf("解密结果:");
            myprintf(plain_text, 16);
            break;
        case 3:
            file_encrypt();
            break;
        case 4:
            file_decrypt();
            break;
        default:
            printf("错误输入\n");

    }

    return 0;
}
