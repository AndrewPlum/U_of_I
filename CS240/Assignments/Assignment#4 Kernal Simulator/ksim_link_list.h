/*
Andrew Plum
Professor Wilder
CS 240
11/19/2022
*/

    /*
    ***Assignment #4 - ksim_link_list.h***
    */

#include<stdlib.h>
#include<string.h>

// Link list class

class link_list{
    private:
        node *first;
        node *back;
        int size;
		int device_number;
		char *state;
    public:
        link_list(const char *, const int);  // constructor
 		~link_list(); // destructor
		void push(char *, int); // puts element at the front of the link list
		void append(char *, int); // puts element at the end of the link list
		void front(char *&);
		void back(char *&)
        void pop(); // takes first element out of the link list
		void remove_back(); // takes back element out of link list
        int return_size();
		int return_front_initial_blocked_tick_time();
		bool find(char *);
		void find_print(char *);
        void print_list();
        void clear();
        bool empty();
};

link_list::link_list(const char *state_sent, const int device_number_sent){
    first = NULL;
    back = NULL;
	size = 0;
	device_number = device_number_sent; // -1 means device number not applicable
	state = (char *) malloc((strlen(state_sent) + 1) * sizeof(char));
	strcpy(state, state_sent);
}

link_list::~link_list(){
	if(first != NULL){
		first->~node(); //check
	}
}

void link_list::push(char *x, int tick_time){
	if(size == 0){ // if empty
    	node *temp = new node(x);
    	first = back = temp;
		if(strcmp(state, "Blocked") == 0){
			temp->initial_blocked_tick_time = tick_time;
		} else {
			temp->initial_blocked_tick_time = -1;
		}
		size++;
   		//printf("\nElement successfully appended into link list!\n");
		//printf("Link list size: %d\n\n", size);
    } else {
    	node *temp = new node(x);
    	temp->next = first;
    	first = temp;
		if(strcmp(state, "Blocked") == 0){
			temp->initial_blocked_tick_time = tick_time;
		} else {
			temp->initial_blocked_tick_time = -1;
		}
		size++;
   		//printf("\nElement successfully appended into link list!\n");
		//printf("Link list size: %d\n\n", size);
    }
    return;
}

void link_list::append(char *x, int tick_time){
    if(size == 0){ // if empty
    	node *temp = new node(x);
    	first = back = temp;
		if(strcmp(state, "Blocked") == 0){
			temp->initial_blocked_tick_time = tick_time;
		} else {
			temp->initial_blocked_tick_time = -1;
		}
		size++;
   		//printf("\nElement successfully appended into link list!\n");
		//printf("Link list size: %d\n\n", size);
    } else {
    	node *temp = new node(x);
    	back->next = temp;
    	back = temp;
		if(strcmp(state, "Blocked") == 0){
			temp->initial_blocked_tick_time = tick_time;
		} else {
			temp->initial_blocked_tick_time = -1;
		}
		size++;
   		//printf("\nElement successfully appended into link list!\n");
		//printf("Link list size: %d\n\n", size);
    }
    return;
}

void link_list::front(char *&data){
    if(size > 0){
		int i;
		data = (char *) malloc((strlen(first->name) + 1) * sizeof(char));
		strcpy(data, first->name);
        return;
    } else {
		//printf("\nUnderflow error!\n");
		//printf("Link list size: %d\n\n", size);
    }
    return;
}

void link_list::back(char *&data){
    if(size > 0){
		int i;
		data = (char *) malloc((strlen(first->name) + 1) * sizeof(char));
		strcpy(data, back->name);
        return;
    } else {
		//printf("\nUnderflow error!\n");
		//printf("Link list size: %d\n\n", size);
    }
    return;
}

void link_list::pop(){
    if(!empty()){
        node *temp = first;
    	first = first->next;
    	free(temp);
 		size--;
        //printf("\nElement successfully popped from link list!\n");
		//printf("Link list size: %d\n\n", size);
    } else {
        //printf("\nUnderflow error!\n");
		//printf("Link list size: %d\n\n", size);
    }
    return;
}

void link_list::remove_back(){
    if(!empty()){
        node *temp = first;
        node *temp2 = back;
    	while(temp->next->next != back){ // point to the node that points to the node that points to NULL
            temp = temp->next;
    	}
    	temp->next = NULL;
    	back = temp;
    	free(temp2);
    	size--;
        //printf("\nElement successfully popped from link list!\n");
		//printf("Link list size: %d\n\n", size);
    } else {
        //printf("\nUnderflow error!\n");
		//printf("Link list size: %d\n\n", size);
    }
    return;
}

int link_list::return_size(){
	return size;
}

int link_list::return_front_initial_blocked_tick_time(){
	if(size > 0){
		return first->initial_blocked_tick_time;
	}
	return -1;
}

bool link_list::find(char *x){
	node *p = first;
	while(p != NULL){
		if(strcmp(p->name, x) == 0){
			return true;
		}
		p = p->next;
	}
	return false;
}

void link_list::find_print(char *x){
	node *p = first;
	while(p != NULL){
		if(strcmp(p->name, x) == 0){
			printf("***\n");
			printf("    id: \"%s\"\n", p->name);
			printf("    state: \"%s\"\n", state);
			if(strcmp(state, "Blocked") == 0){
				printf("        waiting on device %d since tick %09d\n", device_number, p->initial_blocked_tick_time);
			}
			printf("***\n");
			return;
		}
		p = p->next;
	}
	//printf("Nothing found.\n");
	return;
}

void link_list::print_list(){
	node *p = first;
	while(p != NULL){
		printf("***\n");
			printf("    id: \"%s\"\n", p->name);
			printf("    state: \"%s\"\n", state);
			if(strcmp(state, "Blocked") == 0){
				printf("        waiting on device %d since tick %09d\n", device_number, p->initial_blocked_tick_time);
			}
			printf("***\n");
		p = p-> next;
	}
}

void link_list::clear(){
    while(first != NULL){
        pop();
    }
}

bool link_list::empty(){
    if(size == 0){
        return true;
    }
    return false;
}
