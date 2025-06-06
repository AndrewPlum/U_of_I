/*
Andrew Plum
Professor Wilder
CS 240
10/21/22
*/

    /*
    ***Assignment #3 - msh.c***
    */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "sys/wait.h"
#include "unistd.h"

void read_command(char cmd[], char *par[]) {
    char line[1024];
    int count = 0, i = 0, j = 0;
    char *array[100], *pch;

    for (;;) {
        int c = fgetc(stdin);
        line[count++] = (char) c;
        if (c == '\n') {
            break;
        }
        if (count == 1) {
            return;
        }
        pch = strtok(line, "\n");

        while (pch != NULL)
        {
            array[i++] = strdup(pch);
            pch = strtok(NULL, "\n");
        }

        strcpy(cmd, array[0]);

        for(j = 0; j < i; j++){
            par[j] = array[j];
            par[i] = NULL;
        }
    }
}

void type_prompt() {
    static int first_time = 1;
    if (first_time) {
        const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
        write(STDERR_FILENO, CLEAR_SCREEN_ANSI, 12);
        first_time = 0;
    }

    printf(">:");
}

int main() {
    char cmd[100], command[100], *parameters[20];

    //char *envp[] = { (char *) "PATH=C:\\Windows\\System32", 0 };
    char *envp[] = { (char *) "PATH=/bin/sh", 0 };
    while(1) {
        type_prompt();
        read_command(command, parameters);
        if (fork() != 0) {
            wait(NULL);
        } else {
            //strcpy(cmd, "C:\\Windows\\System32");
            //strcpy(cmd, "/bin/sh/");
            strcpy(cmd, "msh");
            strcpy(cmd, command);
            execvp(cmd, parameters);
            //execve(cmd, parameters, envp);
        }
        if (strcmp(command, "exit") == 0) {
            break;
        }
    }
    return 0;
}
