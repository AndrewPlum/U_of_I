/*
Andrew Plum
Professor Wilder
CS 240
11/19/2022
*/

    /*
    ***Assignment #4 - ksim.cpp***
    */
					
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ksim_link_list_node.h" // header file I created
#include"ksim_link_list.h" // header file I created

// constant int

const int input_max = 1024; // put max

// prototypes

int makearg(char *s, char ***args);

// main function

int main(){

    // variable declarations

	int i;
    int tick_time;
    int num_lead_zeros;
    int remainder;
    char input_line[input_max];
    char input_line_makearg_manipulated[input_max];
    int argc;
    char **argv;

	// create link_list objects

	link_list new_process_queue("New", -1);
	link_list ready_process_queue("Ready", -1);
	link_list running_process_queue("Running", -1);
	link_list exit_process_queue("Exit", -1);
	link_list block_queue_1("Blocked", 0);
	link_list block_queue_2("Blocked", 1);
	link_list block_queue_3("Blocked", 2);
	link_list block_queue_4("Blocked", 3);

    // initialize tick_time

    tick_time = 0;

    // loop prompt

    while(1){

        if(tick_time > 999999999){
            tick_time -= 999999999;
            tick_time--;
        }

        // prompt user and get user input

        printf("ksim-"); // prompt
		num_lead_zeros = 9;
        remainder = tick_time;
        do{
            remainder = remainder / 10;
            num_lead_zeros--;
        }while(remainder > 0);
        while(num_lead_zeros > 0){
            printf("0"); // print padded zeros
            num_lead_zeros--;
        }
        printf("%d> ", tick_time); // print tick value
        fgets(input_line, input_max, stdin); // get user input

        // copy input_line

        strcpy(input_line_makearg_manipulated, input_line);

        // makearg() called and input_line sent for formatting

        argc = makearg(input_line_makearg_manipulated, &argv);

		// decode user input

		if((strcmp(input_line, "\n") !=  0) && (argc != 0)){

			// if "exit" inputted by user exit loop

			if((strcmp(argv[0], "exit") == 0) && (argc == 1)){
				break;
			} else if(strcmp(argv[0], "exit") == 0){
				printf("ERROR: Wrong number of operands.\n");
			} else

			// if "add" inputted by user add process

			if((strcmp(argv[0], "add") == 0) && (argc == 2)){
				if(new_process_queue.find(argv[1]) // if process does not exist already, add process
				|| ready_process_queue.find(argv[1]) // this is one long if statement put on multiple lines
				|| running_process_queue.find(argv[1])  // so I can see it on on page
				|| exit_process_queue.find(argv[1])  
				|| block_queue_1.find(argv[1])  
				|| block_queue_2.find(argv[1])  
				|| block_queue_3.find(argv[1])  
				|| block_queue_4.find(argv[1])){ 
					printf("Process named \"%s\" is already being hosted.\n", argv[1]);
				} else {
					new_process_queue.append(argv[1], tick_time);
					tick_time += 32;
				}
			} else if(strcmp(argv[0], "add") == 0){
				printf("Opcode \"add\" requires 1 operand.\n");
			} else
			
			// if "io-event" inputted by user io-event() called

			if((strcmp(argv[0], "io-event") == 0) && (argc == 2)){
				if(strcmp(argv[1], "0") == 0){
					if(!(block_queue_1.empty())){
						char *temp;
						int size = block_queue_1.return_size();
						for(i = 0; i < size; i++){
							block_queue_1.back(temp);
							block_queue_1.remove_back();
							ready_process_queue.push(temp, tick_time);
							printf("Process \"%s\" moved from Blocked (iodev=0) to Ready.\n", temp);
						}
						tick_time += 1;
					} else {
						printf("No processes waiting on device 0.\n");
					}
				} else if(strcmp(argv[1], "1") == 0){
					if(!(block_queue_2.empty())){
						char *temp;
						int size = block_queue_2.return_size();
						for(i = 0; i < size; i++){
							block_queue_2.back(temp);
							block_queue_2.remove_back();
							ready_process_queue.push(temp, tick_time);
							printf("Process \"%s\" moved from Blocked (iodev=1) to Ready.\n", temp);
						}
						tick_time += 1;
					} else {
						printf("No processes waiting on device 1.\n");
					}
				} else if(strcmp(argv[1], "2") == 0){
					if(!(block_queue_3.empty())){
						char *temp;
						int size = block_queue_3.return_size();
						for(i = 0; i < size; i++){
							block_queue_3.back(temp);
							block_queue_3.remove_back();
							ready_process_queue.push(temp, tick_time);
							printf("Process \"%s\" moved from Blocked (iodev=2) to Ready.\n", temp);
						}
						tick_time += 1;
					} else {
						printf("No processes waiting on device 2.\n");
					}
				} else if(strcmp(argv[1], "3") == 0){
					if(!(block_queue_4.empty())){
						char *temp;
						int size = block_queue_4.return_size();
						for(i = 0; i < size; i++){
							block_queue_4.back(temp);
							block_queue_4.remove_back();
							ready_process_queue.push(temp, tick_time);
							printf("Process \"%s\" moved from Blocked (iodev=3) to Ready.\n", temp);
						}
						tick_time += 1;
					} else {
						printf("No processes waiting on device 3.\n");
					}
				} else {
					printf("Device number entered is not in existing range: [0-3]\n");
				}
			} else if(strcmp(argv[0], "io-event") == 0){
				printf("ERROR: Wrong number of operands.\n");
			} else
			
			// if "query" inputted by user query() called

			if((strcmp(argv[0], "query") == 0) && (argc == 1)){ // print all processes
				new_process_queue.print_list();
				ready_process_queue.print_list();
				running_process_queue.print_list();
				exit_process_queue.print_list();
				block_queue_1.print_list();
				block_queue_2.print_list();
				block_queue_3.print_list();
				block_queue_4.print_list();	
			} else if((strcmp(argv[0], "query") == 0) && (argc == 2)){ // print all processes
				if(strcmp(argv[1], "all") == 0){	
					new_process_queue.print_list();
					ready_process_queue.print_list();
					running_process_queue.print_list();
					exit_process_queue.print_list();
					block_queue_1.print_list();
					block_queue_2.print_list();
					block_queue_3.print_list();
					block_queue_4.print_list();					
				} else if(new_process_queue.find(argv[1])){ // print individual process...
					new_process_queue.find_print(argv[1]);
				} else if(ready_process_queue.find(argv[1])){ 
					ready_process_queue.find_print(argv[1]); 
				} else if(running_process_queue.find(argv[1])){
					running_process_queue.find_print(argv[1]);
				} else if(exit_process_queue.find(argv[1])){
					exit_process_queue.find_print(argv[1]);  
				} else if(block_queue_1.find(argv[1])){
					block_queue_1.find_print(argv[1]);  
				} else if(block_queue_2.find(argv[1])){
					block_queue_2.find_print(argv[1]);  
				} else if(block_queue_3.find(argv[1])){  
					block_queue_3.find_print(argv[1]);
				} else if(block_queue_4.find(argv[1])){
					block_queue_4.find_print(argv[1]);
				} else { // if no process found
					printf("Process \"%s\" not found.\n", argv[1]);
				}
			} else if(strcmp(argv[0], "query") == 0){
				printf("ERROR: Wrong number of operands.\n");
			} else
			
			// if "release" inputted by user release() called

			if((strcmp(argv[0], "release") == 0) && (argc == 1)){
				if(!(running_process_queue.empty())){ // if running process queue not empty
					char *temp;
					running_process_queue.front(temp);
					running_process_queue.pop();
					exit_process_queue.append(temp, tick_time);
					printf("Process \"%s\" moved from Running to Exit.\n", temp);
					tick_time += 32;
				} else {
					printf("No process is currently Running.\n");
				}
			} else if(strcmp(argv[0], "release") == 0){
				printf("ERROR: Wrong number of operands.\n");
			} else
			
			// if "step" inputted by user step() called
			
			if((strcmp(argv[0], "step") == 0) && (argc == 1)){
				if(!(exit_process_queue.empty())){ // if exit process queue not empty
					char *temp;
					int size = exit_process_queue.return_size();
					for(i = 0; i < size; i++){
						exit_process_queue.front(temp);
						exit_process_queue.pop(); // pop same process from exit queue
						printf("Process \"%s\" is banished to the void.\n", temp);
					}
				}
				if(!(block_queue_1.empty())){ // if first block queue not empty
					if((tick_time - block_queue_1.return_front_initial_blocked_tick_time()) >= 1024){
						char *temp;
						block_queue_1.front(temp);
						block_queue_1.pop();
						ready_process_queue.push(temp, tick_time);
						printf("Process \"%s\" moved from Blocked (iodev=0) to Ready.\n", temp);
					}
				}
				if(!(block_queue_2.empty())){ // if second block queue not empty
					if((tick_time - block_queue_2.return_front_initial_blocked_tick_time()) >= 1024){
						char *temp;
						block_queue_2.front(temp);
						block_queue_2.pop();
						ready_process_queue.push(temp, tick_time);
						printf("Process \"%s\" moved from Blocked (iodev=1) to Ready.\n", temp);
					}
				}
				if(!(block_queue_3.empty())){ // if third block queue not empty
					if((tick_time - block_queue_3.return_front_initial_blocked_tick_time()) >= 1024){
						char *temp;
						block_queue_3.front(temp);
						block_queue_3.pop();
						ready_process_queue.push(temp, tick_time);
						printf("Process \"%s\" moved from Blocked (iodev=2) to Ready.\n", temp);
					}
				}
				if(!(block_queue_4.empty())){ // if fourth block queue not empty
					if((tick_time - block_queue_4.return_front_initial_blocked_tick_time()) >= 1024){
						char *temp;
						block_queue_4.front(temp);
						block_queue_4.pop();
						ready_process_queue.push(temp, tick_time);
						printf("Process \"%s\" moved from Blocked (iodev=3) to Ready.\n", temp);
					}
				}
				if(!(new_process_queue.empty())){ // if new process queue not empty
					char *temp;
					new_process_queue.front(temp);
					new_process_queue.pop();
					ready_process_queue.push(temp, tick_time);
					printf("Process \"%s\" moved from New to Ready.\n", temp);
				}
				if(!(running_process_queue.empty())){ // if running process queue not empty
					char *temp;
					running_process_queue.front(temp);
					running_process_queue.pop();
					ready_process_queue.append(temp, tick_time);
					printf("Process \"%s\" moved from Running to Ready.\n", temp);
				}
				if(!(ready_process_queue.empty())){ // if ready process queue not empty
					char *temp;
					ready_process_queue.front(temp);
					ready_process_queue.pop();
					running_process_queue.append(temp, tick_time);
					printf("Process \"%s\" moved from Ready to Running.\n", temp);
					tick_time += 256;
				} else {
					tick_time += 1;
				}
			} else if(strcmp(argv[0], "step") == 0){
				printf("ERROR: Wrong number of operands.\n");
			} else
		
			// if "wait" inputted user wait() called

			if((strcmp(argv[0], "wait") == 0) && (argc == 2)){
				if(!(running_process_queue.empty())){
					if(strcmp(argv[1], "0") == 0){
						char *temp;
						running_process_queue.front(temp);
						running_process_queue.pop();
						block_queue_1.append(temp, tick_time);
						printf("Process \"%s\" moved from Running to Blocked.\n", temp);
						tick_time += 1;
					} else if(strcmp(argv[1], "1") == 0){
						char *temp;
						running_process_queue.front(temp);
						running_process_queue.pop();
						block_queue_2.append(temp, tick_time);
						printf("Process \"%s\" moved from Running to Blocked.\n", temp);
						tick_time += 1;
					} else if(strcmp(argv[1], "2") == 0){
						char *temp;
						running_process_queue.front(temp);
						running_process_queue.pop();
						block_queue_3.append(temp, tick_time);
						printf("Process \"%s\" moved from Running to Blocked.\n", temp);
						tick_time += 1;
					} else if(strcmp(argv[1], "3") == 0){
						char *temp;
						running_process_queue.front(temp);
						running_process_queue.pop();
						block_queue_4.append(temp, tick_time);
						printf("Process \"%s\" moved from Running to Blocked.\n", temp);
						tick_time += 1;
					} else {
						printf("Device number entered is not in existing range: [0-3]\n");
					}
				} else {
					printf("No process is currently Running.\n");
				}
			} else if(strcmp(argv[0], "wait") == 0){
				printf("ERROR: Wrong number of operands.\n");
			} else 
			
			// if anything else entered invalid command 
		
			{
				printf("ERROR: Invalid command.\n");
			}
			
			// PRINT LIST FOR DEBUGGING
			
			/*
			printf("\nNew processes:\n");
			new_process_queue.print_list();
			
			printf("\nReady process:\n");
			ready_process_queue.print_list();
			
			printf("\nRunning processes:\n");
			running_process_queue.print_list();
			
			printf("\nExit procceses:\n");
			exit_process_queue.print_list();
			
			printf("\n1st blocked queue processes:\n");
			block_queue_1.print_list();
			
			printf("\n2nd blocked queue processes:\n");
			block_queue_2.print_list();
			
			printf("\n3rd blocked queue processes:\n");
			block_queue_3.print_list();
			
			printf("\n4th blocked queue processes:\n");
			block_queue_4.print_list();
			*/
			
		}
    }

    // free memory

    free(argv);

    // end of main()

    return 0;
}

// definitions

int makearg(char *s, char ***args){

    // variable declarations

    int count = 0;
    int i = 0;
    char *word;

    // memory allocation

    *args = (char **) malloc(strlen(s) * sizeof(char));

    // return -1 if memory allocation fails

    if(*args == NULL){
        count = -1;
        return count;
    }

    //count number of words and format args

    count = 0;
    word = strtok(s, " \n");
    while(word != NULL){
        args[0][count] = word;
        count++;
        word = strtok(NULL, " \n");
    }

    // return

    return count; // should return -1 if error
}
