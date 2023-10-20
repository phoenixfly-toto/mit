#include "kernel/types.h"
#include "user/user.h"
#define MAX_PARAM_LEN 100
#define MAX_PARAM_CNT 100
#define MAX_STDIN_LEN 100
#define STDIN_FILENO  100



void fmt_params(char* line, char** params, int* cnt){
    char cur_param[MAX_PARAM_LEN];
    int cur_param_len = 0;
    for(int i=0; i<strlen(line);i++){
        if((line[i] == ' ' || line[i] == '\n')&& cur_param_len!=0){
            params[*cnt] = malloc(MAX_PARAM_LEN);//分配内存以存储当前参数，并将指针存储在params数组的当前索引位置*cnt上
            memmove(params[*cnt], cur_param, cur_param_len);//将cur_param中的内容复制到新分配的内存中。
            params[*cnt][cur_param_len] = 0;//在新分配的内存的末尾添加一个字符串终止符。
            cur_param_len = 0;//置0以准备存储下一个参数
            (*cnt)++;

        }
        else{
            cur_param[cur_param_len] = line[i];
            cur_param_len++;
        }
    }

}


int main(int argc,char *argv[]){

    //读取xargs后的命令以及参数
    if(argc == 1) exit(0);
    char* params[MAX_PARAM_CNT];
    int cnt = 0;
    for(int i=1; i<argc; i++){
        params[i-1] = argv[i];
        cnt++;
    }

    //读取‘|’产生的标准输入
    char r_buf[MAX_STDIN_LEN];
    while(read(STDIN_FILENO, r_buf, MAX_STDIN_LEN) > 0){//逐行读取
        if(fork()==0){
            //子进程
            fmt_params(r_buf,params,&cnt);
                exec(params[0],params);  
            }else{
                //父进程
                wait(0);
            }
    }
    exit(0);
}