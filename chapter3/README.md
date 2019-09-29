*  1  
int open(const char *pathname, int oflag,.../*, mode_t mode * / )  
仅当创建新文件时才使用第三个参数
创建函数时需要关注下
*  2  
int creat(const char *pathname, mode_t mode)  
S_IRUSR：用户读权限  
S_IWUSR：用户写权限  
S_IRGRP：用户组读权限  
S_IWGRP：用户组写权限  
S_IROTH：其他组都权限  
S_IWOTH：其他组写权限  
创建 FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)
*  3  
int close (int filedes)  
*  4  
off_t lseek(int filedes, off_to ffset, int whence)  
*  5  
