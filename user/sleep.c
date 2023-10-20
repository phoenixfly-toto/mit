#include "kernel/types.h"
#include "user/user.h"

int main(int argn, char *argv[]){
    if(argn != 2){
        printf("wrong argument for sleep");
        exit(1);
    }
    int tag = 1;
    char *p = argv[1];
    while(*p){
        if(*p < '0' || *p > '9'){
            tag = 0;
            break;
        }
        p++;
        if(tag){
            //atoiq将数字字符转换为整数
            sleep(atoi(argv[1]));
            }
        else
            printf(" error\n");       
    }
    exit(0);
}
//int tag = 1：定义一个整数变量 tag，用于标记睡眠时间参数是否合法。
//char *p = argv[1]：将命令行参数的第二个参数（睡眠时间）赋值给指针变量 p。
//while (*p)：通过循环遍历参数字符串中的每个字符。
//if (*p < '0' || *p > '9')：检查当前字符是否为数字字符。如果不是数字字符，则将 tag 设置为0，表示参数非法。
//sleep(atoi(argv[1]))：如果所有字符都是数字字符，则调用 atoi 函数将参数转换为整数，并使用 sleep 函数进行相应的睡眠。