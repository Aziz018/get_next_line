#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2;
    char *line1;
    char *line2;

    // Open two files for reading
    fd1 = open("README.md", O_RDONLY);
    fd2 = open("example.txt", O_RDONLY);

    if (fd1 == -1 || fd2 == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Read lines from the first file

    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
	while (line1 != NULL && line2 != NULL)
	{
		printf("File 1: %s\n", line1);
    	free(line1);
    	line1 = get_next_line(fd1);
		printf("File 2: %s\n", line2);
    	free(line2);
    	line2 = get_next_line(fd2);
	}
	
    return 0;
}
