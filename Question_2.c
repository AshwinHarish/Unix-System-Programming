#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main(){
	struct dirent *dir;
	struct stat mystat;
	DIR *dp;
	dp=opendir("/home/aman/college/usp/externals");
	if(dp){
		while(dir=readdir(dp)){
			stat(dir->d_name,&mystat);
			printf("%ld\n",mystat.st_ino);
            printf("%o\n",mystat.st_mode);
            printf("%d\n",mystat.st_uid);
            printf("%s\n",ctime(&mystat.st_atime));
            printf("%s\n",dir->d_name);
		}
	}
}