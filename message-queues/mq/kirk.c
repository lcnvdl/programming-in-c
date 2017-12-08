#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "mq.h"

int main(void)
{
    //struct my_msgbuf buf;
    MessageQueue buf;
    int msqid;
    key_t key;

    // if ((key = ftok("kirk.c", 'B')) == -1) {
    //     perror("ftok");
    //     exit(1);
    // }

    // if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
    //     perror("msgget");
    //     exit(1);
    // }
    
    msqid = createMessageQueue(4312);

    printf("Enter lines of text, ^D to quit:\n");

    buf.mtype = 1; /* we don't really care in this case */
    //fgets(buf.info.mtext, sizeof buf.info.mtext, stdin);
    //while(fgets(buf.info.mtext, sizeof buf.info.mtext, stdin) != NULL) {
    while(1)
      {
          printf("aca@");
            int len = strlen(buf.info.mtext);


        buf.info.nro_jugador = 99;
        buf.info.nro_pensado = 23;
        /* ditch newline at end, if it exists */
        //if (buf.info.mtext[len-1] == '\n') buf.info.mtext[len-1] = '\0';

        // if (msgsnd(msqid, &buf, sizeof(buf.info), 0) == -1) /* +1 for '\0' */
        //     perror("msgsnd");

        printf("\n enviooo");
        sendMessageQueue(msqid, &buf);
        printf("\n eespero");
        usleep(1000*800);
    }

    cleanMessageQueue(msqid);
    // if (msgctl(msqid, IPC_RMID, NULL) == -1) {
    //     perror("msgctl");
    //     exit(1);
    // }

    return 0;
}