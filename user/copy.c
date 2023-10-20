#include "kernel/types.h"
#include "user/user.h"

int main(){
    char buf[64];

    while(1){
        //从console读取，通过system call的read函数实现
        int n = read(0, buf, sizeof(buf));
        if(n <= 0){
            break;
            //console输出，通过system call的wwrite数实现
            write(1, buf, n);
        }
    }

    exit(0);
}
