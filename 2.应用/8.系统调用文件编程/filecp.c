#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
   int fd_s= 0;
   int fd_t= 0;
   char buf[512];
   int count = 0;
   /*打开源文件*/
   fd_s = open(argv[1], O_RDONLY);
  
   /*打开目标文件*/
   fd_t = open(argv[2], O_WRONLY | O_CREAT, 0666);

   /*读源文件*/
   /*写目标文件*/
   while((count = read(fd_s, buf, 512)) > 0) 
       write(fd_t, buf, count);
   
   
   /*关闭文件*/
   close(fd_s);
   close(fd_t);
   
   return 0;
   
}
