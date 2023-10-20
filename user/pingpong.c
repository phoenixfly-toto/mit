#include "kernel/types.h"
#include "user/user.h"

int main(){
    int p[2];//定义一个数组作为管道的文件描述符
    pipe(p);//创建管道

    int pid = fork();//创建子进程，并将子进程的进程ID存储在变量 pid 中。父进程中，pid 存储的是子进程的进程ID，而在子进程中，fork() 返回的是0。
    if(!pid){
        read(p[0], &pid, 4);//子进程从管道的读取端 p[0] 读取数据，并将数据存储在变量 pid 中。
        printf("%d: received ping\n",pid);
    }
    else{
        write(p[1], &pid, 4);
        wait(0);
        printf("%d: received pong\n",pid);
    }

    exit(0);
}