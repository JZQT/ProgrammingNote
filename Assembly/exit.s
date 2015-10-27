# 退出并向Linux内核返回一个状态码的简单程序
# 编译后的程序运行完后立刻在Shell中执行`echo $?`可查看该程序退出的状态码

.section .data
.section .text
.globl _start

_start:
    movl $1, %eax   # 退出程序的Linux系统调用号
    movl $0, %ebx   # exit系统调用的参数，也就是退出的状态码
    int $0x80
