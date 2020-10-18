#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main(int argc, char const *argv[])
{
    int fd;
    fd = open("desd.txt", O_WRONLY|O_CREAT);// create the path

    if(fd==-1){
        perror("Error");//Error handling
        return -1;
    }

    write(fd,"cdachyd",7);//write into file
    close(fd);// close the file
    
    return 0;
}
