#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    char *str;
    //int fd = open("test.txt", O_RDONLY);
    int fd2 = open("big.txt", O_RDONLY);
    //int fd4 = open("line", O_RDONLY);
	//int fd3 = open("large.txt", O_RDONLY);
    int i = 1;
    //int j;


	 while(get_next_line(fd2, &str) > 0)
     {
	      //printf("j = %d\n", j);
          printf("line %d = %s\n", i, str);
          free(str);
          i++;
     }
    //printf("j = %d\n", j);
    printf("line %d = %s\n", i, str);
	free(str);
    //printf("get = %d\n", get_next_line(0, &str));
    // printf("get = %d\n", get_next_line(2, &str));
    //printf("line = %s\n", str);
    // printf("get = %d\n", get_next_line(fd, &str));
    // printf("line = %s\n", str);
    // printf("get = %d\n", get_next_line(fd, &str));
    // printf("line = %s\n", str);
    // printf("get = %d\n", get_next_line(fd, &str));
    // printf("line = %s\n", str);
    // printf("get = %d\n", get_next_line(fd, &str));
    // printf("line = %s\n", str);
	/*get_next_line(fd, &str);
	printf("fd 1 = %s\n", str);
	get_next_line(fd2, &str);
	printf("fd 2 = %s\n", str);
	get_next_line(fd2, &str);
	printf("fd 2 = %s\n", str);
	get_next_line(fd, &str);
	printf("fd 1 = %s\n", str);
	get_next_line(fd, &str);
	printf("fd 1 = %s\n", str);
	get_next_line(fd, &str);
	printf("fd 1 = %s\n", str);
	get_next_line(fd, &str);
	printf("fd 1 = %s\n", str);
	get_next_line(fd, &str);
	printf("fd 1 = %s\n", str);
	get_next_line(fd2, &str);
	printf("fd 2 = %s\n", str);
	get_next_line(fd3, &str);	
	printf("fd 3 = %s\n", str);
	get_next_line(fd3, &str);	
	printf("fd 3 = %s\n", str);*/
    return 0;
}
