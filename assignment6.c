#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(){
    int stat,pno,pipeEnds[2];
    char message_recieved[50];

    stat=pipe(pipeEnds);
    if(stat==-1){
        printf("Pipe creation is unsuccessful");
        exit(1);
    }else{
        pno=fork();
        if(pno==-1){
            printf("Process creation is unsuccessful");
            exit(0);
        }else if(pno>0){
            close(pipeEnds[0]);
            write(pipeEnds[1],"Hello from Parent",18);
            close(pipeEnds[1]);
            exit(0);
        }else{
            close(pipeEnds[1]);
            read(pipeEnds[0],message_recieved,18);
            close(pipeEnds[0]);
            printf("%s \n",message_recieved);
            exit(0);
        }
    }
}
