#include <getopt.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

void readFile(char * file_name){
FILE * fPointer;
fPointer = fopen(file_name,"r");
char lines[200];
while(! feof(fPointer)){
fgets(lines, 200,fPointer);
puts(lines);

}
fclose(fPointer);

}


int main(int argc, char *argv[]) {

if ((atoi(argv[argc-1]) > 999) && (atoi(argv[argc-1]) < 10000)){
//printf("%s\n", argv[argc-1]);
int pid =atoi(argv[argc-1]);

   int option;
   char * file_name;

   while ((option = getopt(argc, argv, "hf:")) !=-1){
        switch (option){
case 'h' :
printf("Hello World\n");
break;
case 'f' : 

file_name = optarg;
readFile(file_name);
break;
default :
break;
        }

   }

} else{
printf("Error - command format is $ my_kill -options pid\n");
exit(-1);

}
    return 0;
}