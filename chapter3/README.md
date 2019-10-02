*  1  
int open(const char *pathname, int oflag,.../*, mode_t mode * / )  
仅当创建新文件时才使用第三个参数
新版本的open才有创建的功能
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
ssize_t write(int filedes, const void *buff, size_tn bytes)  
*  6  
ssize_t read(int filedes, void *buff, size_tn bytes)  
*  7
int dup(int oldfd)  
dup(fd)等效于   
fcntl(fd, F_DUPFD, 0)  
*  8  
int dup2(int fd, int fd2)  
dup2(oldfd, newfd)等效于   
close(oldfd)  
fcntl(oldfd, F_DUPFD, newfd)  
*  9  
int fsync(int fd)  
只对由文件描述符fd指定的一个文件起作用，并且等待写磁盘操作结束才返回。
*  10  
int fdatasync(int fd)  
类似于fsync，但是它只影响文件的数据部分。而除数据外，fsync还会同步更新文件的属性。
* 11  
void sync(void)  
该函数只是将所有修改过的块缓冲区排入写队列，然后就返回，他并不等待实际写磁盘操作结束  
**标准的I/O函数（如fread,fwrite）会在内存建立缓冲，该函数刷新内存缓冲，将内容写入内核缓冲，要想将其写入磁盘，还需要调用fsync（先调用fflsuh然后再调用fsync，否则不起作用）  
内存缓冲-----fflush---------〉内核缓冲--------fsync-----〉磁盘**
* 12  
int fcntl(int fd, int cmd)
int fcntl(int fd, int cmd, long arg)
int fcntl(int fd, int cmd ,struct flock* lock)
