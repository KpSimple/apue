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
}  
struct dirent *dirp = readdir(dp)