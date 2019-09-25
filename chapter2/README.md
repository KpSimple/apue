sysconf()用于获得与文件或目录无关的限制值，以及系统特征选项；pathconf()和fpathconf()用于获得与文件或目录有关的限制值  
这三个函数的原型为：  
* long int sysconf(int parameter);  
* long int pathconf(const char *pathname，int parameter);  
* long int fpathconf(int filedes，int parameter);

![](https://github.com/KpSimple/apue/blob/master/chapter2/sysconf.png)  
对sysconf的限制及name参数  
![](https://github.com/KpSimple/apue/blob/master/chapter2/pathconf.png)  
对pathconf和fpathconf的限制及name参数
