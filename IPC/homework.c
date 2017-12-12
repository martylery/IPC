#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
	// char buffer[512];
	pid_t pid = fork();
	int fd;

	char* fifodest = "./fifo";
	mkfifo(fifodest, 0666);

	if(pid == 0) {
		// printf("Entered Write Mode..\n");
		char buffer[512] = "this is the message send by the named pipe";
						//Writes..
		// while(1) {
			fd = open(fifodest, O_WRONLY);
			ssize_t status = 0;
			
			status = write(fd, buffer, 512);
			close(fd);

		// }	


	} 
	else {

		char buffer[512];
		// printf("Entered Read Mode..\n"); 
						//Reads..
		// while(1) {
			fd = open(fifodest, O_RDONLY);
			read(fd, buffer, 512);

			printf("Message from other process: %s\n", buffer);
			close(fd);
		// }
	}
}