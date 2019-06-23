1.1
----
DIR结构体 
struct __dirstream   
{   
    void *__fd;    
    char *__data;    
    int __entry_data;    
    char *__ptr;    
    int __entry_ptr;    
    size_t __allocation;    
    size_t __size;    
	__libc_lock_define (, __lock)    
};   
typedef struct __dirstream DIR; 
DIR *dp = opendir(path) 

dirent结构体 
struct dirent   
{   
	long d_ino; /* inode number 索引节点号 */  
	off_t d_off; /* offset to this dirent 在目录文件中的偏移 */  
	unsigned short d_reclen; /* length of this d_name 文件名长 */  
	unsigned char d_type; /* the type of d_name 文件类型 */ 
	char d_name [NAME_MAX+1]; /* file name (null-terminated) 文件名，最长255字符 */  
};
struct dirent *dirp = readdir(dp)

1.2
1.3
---
stdin等属于标准库处理的输入流，其声明为 FILE 型的，对应的函数前面都有f开头，如fopen/fread/fwrite/fclose/getc/putc 标准库调用等
STDIN_FILENO等属于系统API接口库，其声明为 int 型，是一个打开文件句柄，对应的函数主要包括open/read/write/close 等系统级调用。

1.4
---
getpid获取进程ID

1.5
---
fork对父进程返回子进程的ID，对子进程返回0
子进程调用execlp执行新程序文件

1.6
---
strerror根据errno值返回错误字符串指针
perror输出errno对应的错误消息

1.7
---
getuid和getgid返回用户ID和组ID

1.8
---
signal指定某种信号的处理方式
waitpid等待进程结束

1.5
---