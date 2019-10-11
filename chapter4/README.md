* 1
int stat(const char *path, struct stat *buf)//返回符号链接对应文件的属性  
int fstat(int fd, struct stat *buf)  
int lstat(const char *path, struct stat *buf)//返回符号链接的属性  
int fstatat(int dirfd, const char *pathname, struct stat *statbuf, int flags)  
第一个参数众所周知是一个文件描述符, 该参数若使用标志AT_FDCWD, 则pathname参数使用的是相对路径,  
如果pathname是一个绝对路径, 则忽略fd参数,   
最后的flags参数若设置了AT_SYMLINK_NOFOLLOW标志则说明fstatat返回符号链接的信息, 否则不返回符号链接的信息.  
