本章说明了标准I/O库的相关函数  
### 1.    
#### void setbuf(FILE *fp, char *buf );  
buf:  
nonnull 长度为BUFSIZE的用户缓存全缓存或行缓存  
NULL （无缓存） 不带缓存  

#### int setvbuf(FILE *fp, char *buf, int mode, size_t size);  
返回：若成功则为0，若出错则为非0  
mode:  
_IOFBF 全缓存  
_IOLBF 行缓存  
_IONBF 不带缓存  
buf:  
nonnull 长度为BUFSIZE的用户缓存  
NULL (无缓存)  

### 2.  
#### int fflush(FILE *fp) ;
返回：若成功则为0，若出错则为EOF  
此函数使该流所有未写的数据都被传递至内核  

### 3.  
#### FILE *fopen(const char *pathname, const char *type);
若成功则为文件指针，若出错则为NULL

pathname，文件名  
type，打开方式  

字符及其含义：  
打开方式由r,w,a,t,b,+这六个字符拼成，含义如下  
r(read)：读  
w(write)：写  
a(append)：追加  
t(txt)：文本文件，可省略  
b(banary)：二进制文件  

"r"            打开文字文件只读          
"w"           创建文字文件只写         
"a"           增补, 如果文件不存在则创建一个     
"r+"          打开一个文字文件读/写        
"w+"         创建一个文字文件读/写          
"a+"         打开或创建一个文件增补          
"b"           二进制文件(可以和上面每一项合用)          
"t"           文这文件(默认项)  

使用方式及含义  
“rt”　　　　　　只读打开一个文本文件，只允许读数据  
“wt”　　　　　　只写打开或建立一个文本文件，只允许写数据  
“at”　　　　　　追加打开一个文本文件，并在文件末尾写数据  
“rb”　　　　　　只读打开一个二进制文件，只允许读数据  
“wb”　　　　 　  只写打开或建立一个二进制文件，只允许写数据  
“ab” 　　　　 　 追加打开一个二进制文件，并在文件末尾写数据  
“rt+”　　　　　  读写打开一个文本文件，允许读和写  
“wt+”　　　　　 读写打开或建立一个文本文件，允许读写  
“at+”　　　　　  读写打开一个文本文件，允许读，或在文件末追加数据  
“rb+”　　　　　  读写打开一个二进制文件，允许读和写  
“wb+”　　　　　 读写打开或建立一个二进制文件，允许读和写  
“ab+” 　　　　 　读写打开一个二进制文件，允许读，或在文件末追加数据  

①　用”r”打开文件时，该文件必须存在，只读  
②　用”w”打开文件时，若文件不存在，则创建，若存在，则将其删除，再创建一个文件  
③　用”a”打开文件时，可在其末尾写数据  
  
### 4.  
#### FILE *freopen(const char *pathname, const char *type, FILE *fp)  
常用来重定向了标准流，用pathname的流代替fp  

### 5.  
#### FILE *fdopen(int filedes, const char *type)  
打开一个现存的文件描述符  

### 6.  
#### int fclose(FILE *fp)  
调用fclose关闭一个打开的流

### 7.  
以下三个函数可用于一次读一个字符
#### int getc(FILE *fp)  
#### int fgetc(FILE *fp)
#### int getchar(void)  
三个函数的返回：若成功则为下一个字符，若已处文件尾端或出错则为EOF  

### 8.  
一次输出一个字符
#### int putc(int c, FILE *fp )  
#### int fputc(int c, FILE *fp）  
#### int putchar(int c)  
三个函数返回：若成功则为C，若出错则为EOF  

### 9.  
每次输入一行
#### char *fgets(char *buf, int n，FILE * fp)  
#### char *gets(char *buf)  
两个函数返回：若成功则为buf，若已处文件尾端或出错则为NULL  

### 10.  
每次输出一行
#### int fputs(const char *str, FILE *fp)  
#### int puts(const char *str)  
两个函数返回：若成功则为非负值，若出错则为EOF  

### 11.  
读和写二进制文件
#### size_t fread(void *ptr, size_t size, size_tn obj, FILE *fp)   
#### size_t fwrite(const void *ptr, size_t size, size_tn obj, FILE *fp)  
ptr	  指向要读取的数组中首个对象的指针
size	每个对象的大小（单位是字节）
obj	要读取的对象个数
fp	输入流
两个函数的返回：读或写的对象数  

### 12.  
#### long ftell(FILE *fp)  
返回：若成功则为当前文件位置指示，若出错则为－1L  

### 13.  
fseek定位一个二进制文件  
指定一个字节offset，以及解释这种位移量的方式  
#### int fseek(FILE *fp,long offset,int whence)  
SEEKSET表示从文件的起始位置开始，SEEKCUR表示从当前文件位置，SEEKEND表示从文件的尾端
返回：若成功则为0，若出错则为非0  

### 14.  
fgetpos将文件位置指示器的当前值存入由pos指向的对象中,在以后调用fsetpos时，可以使用
此值将流重新定位至该位置
#### int fgetpos(FILE *fp, fpos_t *pos)  
#### int fsetpos(FILE *fp, const fpos_t *pos)  
两个函数返回：若成功则为0，若出错则为非0  

### 15.
printf将格式化数据写到标准输出，fprintf写至指定的流,sprin f将格式化的字符送入数组buf中  
#### int printf(const char *format, ...)  
#### int fprintf(FILE *fp, const char *format, ...)  
两个函数返回：若成功则为输出字符数，若输出出错则为负值  
#### int sprintf(char *buf, const char *format, ...)  
返回：存入数组的字符数  

### 16.  
#### int vprintf(const char *format, va_list arg)  
#### int vfprintf(FILE *fp, const char *format, va_list arg)  
两个函数返回：若成功则为输出字符数，若输出出错则为负值  
#### int vsprintf(char *buf, const char * format, va_list arg)  
返回：存入数组的字符数  

### 17.  
#### int scanf(const char *format, ...)  
#### int fscanf(FILE *fp, const char *format, ...)  
#### int sscanf(const char *buf, const char * format, ...)  
三个函数返回：指定的输入项数，若输入出错，或在任意变换前已至文件尾端则为EOF  

### 18.  
tmpnam产生一个与现在文件名不同的一个有效路径名字符串
#### char *tmpnam(char *ptr)  
返回：指向一唯一路径名的指针  
tmpfile创建一个临时二进制文件（类型w b +），在关闭该文件或程序结束时将自动删除这种文件  
#### FILE *tmpfile(void)  
返回：若成功则为文件指针，若出错则为NULL  
