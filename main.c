#include "aes.h"
// ��http://tool.chacuo.net/cryptaes���һ��
// ģʽECB ���no padding ���ݿ�128λ ���hex �ַ���GB2312

/*
 * ����16bytes��Կ:61616161616161616161616161616161
 * ѡ�����:
 * 1-�ֽ������
 * 2-�ֽ������
 * 3-�ļ�����
 * 4-�ļ�����
 * 1
 * ������Ҫ���ܵ��ֽ���:61616161616161616161616161616161
 * ���ܽ��:51 88 c6 47 4b 22 8c bd d2 42 e9 12 5e be 1d 53
 */

int main()
{
    int choice;
    bytes key[128]; // 128λ��Կ
    bytes plain_text[16]; // �ֽڼ��ܵ�����
    bytes cipher_text[16]; // �ֽڼ��ܵ�����
    printf("����16bytes��Կ:");
    myscanf(key);

    init_mt(NULL, NULL, NULL, NULL, key); // ����Կ�����ʼ��
    key_ext(); // ��Կ��չ

    printf("ѡ�����:\n");
    printf("1-�ֽ������\n");
    printf("2-�ֽ������\n");
    printf("3-�ļ�����\n");
    printf("4-�ļ�����\n");

    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            printf("������Ҫ���ܵ��ֽ���:");
            myscanf(plain_text);
            aes_encrypt(plain_text, cipher_text);
            printf("���ܽ��:");
            myprintf(cipher_text, 16);
            break;
        case 2:
            printf("������Ҫ���ܵ��ֽ���:");
            myscanf(cipher_text);
            aes_decrypt(cipher_text, plain_text);
            printf("���ܽ��:");
            myprintf(plain_text, 16);
            break;
        case 3:
            file_encrypt();
            break;
        case 4:
            file_decrypt();
            break;
        default:
            printf("��������\n");

    }

    return 0;
}
