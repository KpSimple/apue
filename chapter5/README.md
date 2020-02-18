本章说明了标准I/O库的相关函数
1.  
void setbuf(FILE *fp, char *buf );  
buf:  
nonnull 长度为BUFSIZE的用户缓存全缓存或行缓存  
NULL （无缓存） 不带缓存  

int setvbuf(FILE *fp, char *buf, int mode, size_t size);  
返回：若成功则为0，若出错则为非0  
mode:  
_IOFBF 全缓存  
_IOLBF 行缓存  
_IONBF 不带缓存  
buf:  
nonnull 长度为BUFSIZE的用户缓存  
NULL (无缓存)  
2.  
int fflush(FILE *fp) ;
返回：若成功则为0，若出错则为EOF  
此函数使该流所有未写的数据都被传递至内核  
3.  

