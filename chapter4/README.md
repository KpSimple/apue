本章内容围绕stat函数，详细介绍了 stat结构中的每一个成员。 

struct stat  
{  
  mode_t     st_mode;       //文件对应的模式，文件，目录等  
  ino_t      st_ino;        //inode节点号  
  dev_t      st_dev;        //设备号码  
  dev_t      st_rdev;       //特殊设备号码  
  nlink_t    st_nlink;      //文件的连接数  
  uid_t      st_uid;        //文件所有者  
  gid_t      st_gid;        //文件所有者对应的  
  off_t      st_size;       //普通文件，对应的文件字节数  
  time_t     st_atime;      //文件最后被访问的时间  
  time_t     st_mtime;      //文件内容最后被修改的时间  
  time_t     st_ctime;      //文件状态改变时间  
  blksize_t  st_blksize;    //文件内容对应的块大小  
  blkcnt_t   st_blocks;     //伟建内容对应的块数量  
};  

stat结构体中的st_mode 则定义了下列数种情况：

    S_IFMT   0170000    文件类型的位遮罩
    S_IFSOCK 0140000    scoket
    S_IFLNK 0120000     符号连接
    S_IFREG 0100000     一般文件
    S_IFBLK 0060000     区块装置
    S_IFDIR 0040000     目录
    S_IFCHR 0020000     字符装置
    S_IFIFO 0010000     先进先出
    
    S_ISUID 04000     文件的(set user-id on execution)位
    S_ISGID 02000     文件的(set group-id on execution)位
    S_ISVTX 01000     文件的sticky位

    S_IRUSR(S_IREAD) 00400     文件所有者具可读取权限
    S_IWUSR(S_IWRITE)00200     文件所有者具可写入权限
    S_IXUSR(S_IEXEC) 00100     文件所有者具可执行权限

    S_IRGRP 00040             用户组具可读取权限
    S_IWGRP 00020             用户组具可写入权限
    S_IXGRP 00010             用户组具可执行权限

    S_IROTH 00004             其他用户具可读取权限
    S_IWOTH 00002             其他用户具可写入权限
    S_IXOTH 00001             其他用户具可执行权限

    上述的文件类型在POSIX中定义了检查这些类型的宏定义：
    S_ISLNK (st_mode)    判断是否为符号连接
    S_ISREG (st_mode)    是否为一般文件
    S_ISDIR (st_mode)    是否为目录
    S_ISCHR (st_mode)    是否为字符装置文件
    S_ISBLK (s3e)        是否为先进先出
    S_ISSOCK (st_mode)   是否为socket

* 1  
int stat(const char *path, struct stat *buf)//返回符号链接对应文件的属性  
int fstat(int fd, struct stat *buf)  
int lstat(const char *path, struct stat *buf)//返回符号链接的属性  
int fstatat(int dirfd, const char *pathname, struct stat *statbuf, int flags)  
第一个参数众所周知是一个文件描述符, 该参数若使用标志AT_FDCWD, 则pathname参数使用的是相对路径,  
如果pathname是一个绝对路径, 则忽略fd参数,   
最后的flags参数若设置了AT_SYMLINK_NOFOLLOW标志则说明fstatat返回符号链接的信息, 否则不返回符号链接的信息.  
* 2  
int access(const char * pathname, int mode)  
mode 说明  
R_OK 测试读许可权  
W_OK 测试写许可权  
X_OK 测试执行许可权  
F_OK 测试文件是否存在  
* 3  
mode_t umask(mode_t c mask)  
umask函数为进程设置文件方式创建屏蔽字，并返回以前的值。 
* 4  
int chmod(const char * pathname, mode_t mode)  
int fchmod(int filedes, mode_t mode )  
这两个函数使我们可以更改现存文件的存取许可权。 
* 5  
int chown(const char * pathname, uid_t owner, gid_t group)  
int fchown(int filedes, uid_t owner, gid_t group)  
int lchown(const char *pathname, uid_t owner, gid_t group)  
chown函数可用于更改文件的用户ID和组ID。
* 6  
int link(const char * existingpath, const char *newpath)  
创建一个向现存文件连接的方法是使用link函数。 
* 7  
int unlink(const char *pathname)  
为了删除一个现存的目录项，可以调用unlink函数。  
* 8  
int remove(const char *pathname)  
我们也可以用remove函数解除对一个文件或目录的连接。对于文件， remove的功能与unlink相同。  
对于目录， remove的功能与rmdir相同。  
可以用于删除文件和目录
* 9  
int rename(const char *oldname, const char * newname)  
文件或目录用rename函数更名。  
* 10  
int symlink(const char * actualpath, const char *sympath )  
symlink函数创建一个符号连接。  
* 11  
int readlink(const char * pathname, char *buf, int bufsize)  
因为open函数跟随符号连接，所以需要有一种方法打开该连接本身，并读该连接中的名字。
readlink函数提供了这种功能。  
* 12  
int utime(const char *pathname, const struct utimbuf * times)
一个文件的存取和修改时间可以用utime函数更改。  
struct utimbuf   
{  
time_t actime; /*access time*/
time_t modtime; /*modification time*/
}  
* 13  
int mkdir(const char *pathname, mode_t mode)  
int rmdir(const char *pathname)  
用mkdir函数创建目录，用rmdir函数删除目录。  
* 14  

