#include <stdio.h>
#include <stdlib.h>
#define MAX 1024*1024*50 // 50MB

typedef unsigned char bytes;

extern bytes table[256][256]; // gf256乘法的表格 优化计算速度
extern bytes key_mt[4][44]; // 密钥矩阵
extern bytes sbox[16][16];
extern bytes sbox_n[16][16];
extern bytes col[4][4]; // 列混合矩阵
extern bytes col_n[4][4]; // 逆列混合矩阵

// bytes gf256_add(bytes a, bytes b); // gf256上的加法 异或
bytes gf256_mul(bytes a, bytes b); // gf256上的乘法 查表
int myscanf(bytes* a); // 转换字符形式的十六进制输入 例如将"0x39c5bb"转换为0x39c5bb 返回输入字节数
void init_mt(bytes* plain_text, bytes plain_mt[][4],  bytes* cipher_text, bytes cipher_mt[][4], bytes* key); // 初始化状态矩阵
void bytes_sub(bytes* a, bytes* out); // 字节代换
void bytes_sub_n(bytes* a, bytes* out); // 逆字节代换
void swap_bytes(bytes* a, bytes* b); // 交换字节
void key_ext(); // 密钥扩展
void aes_encrypt(bytes* plain_text, bytes* cipher_text); // aes加密
void aes_decrypt(bytes* cipher_text, bytes* plain_text); // aes解密
void row_shift(bytes a[][4]); // 行移位
void row_shift_n(bytes a[][4]); // 逆行移位
int readfile(char* fname, bytes* content); // 从文件读取字节 返回字节数
void roude_key_add(bytes text[][4], int n); // 轮密钥加 第一个参数是明文/密文状态矩阵 第二个是密钥的位置
void file_encrypt(); // 文件加密
void file_decrypt(); // 文件解密
void col_mix(bytes text[][4]); // 列混合
void col_mix_n(bytes text[][4]); // 逆列混合
void myprintf(bytes* a, int count);
void writefile(char* fname, bytes* content, int size); // 将content的前size个字节写入文件fname
void printmt(bytes a[][4]); // 打印4*4状态矩阵

