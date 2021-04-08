#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name {
    char *vorname, *nachname;
    char call;
    struct name *next_node_ptr;  // pointer to next node for linked list
};

struct name *start_name_node; 

// creates linked list returning nonzero error code
static int create_name_list(int argc, char **argv);

static void print_names();

static void rec_free(struct name *name_node);


int main(int argc, char **argv) {
    if (argc > 1) {
        int errc = create_name_list(argc, argv);
        if (errc) return errc; 
        print_names();
        rec_free(start_name_node);
    } else {
        printf("Es wurden keine Namen angegeben.\n");
        return 22;
    }

    return 0;
}


static int create_name_list(int argc, char **argv) {
    struct name *new_name_node;
    struct name *name_node_buffer;
    int name_node_counter;

    start_name_node = (struct name *)malloc(sizeof(struct name));

    if (start_name_node == NULL) {
        perror("Speicher Fehler.");
        return 12;
    }  

    // check for two (2) spaces in each argument string
    int space_num, i;
    for (space_num = i = 0; argv[1][space_num + i]; 
            argv[1][space_num + i] == ' ' ? space_num++ : i++);
    if (space_num < 2) {
        printf("Falsche Formattierung in: %s\n", argv[1]);
        return 22;
    }

    char *trunc;
    trunc = strtok(argv[1], " ");
    start_name_node->vorname = trunc;
    trunc = strtok(NULL, " ");
    start_name_node->nachname = trunc;
    trunc = strtok(NULL, " ");
    if (!trunc) return 22;
    start_name_node->call = trunc[0];

    start_name_node->next_node_ptr = NULL;

    name_node_buffer = start_name_node;

    for (name_node_counter = 2; name_node_counter <= argc-1; 
         name_node_counter++) {

        new_name_node = (struct name *)malloc(sizeof(struct name));

        if (new_name_node == NULL) {
            printf("Speicher Fehler.");
            return 12;
        }

        // check for two (2) spaces in each argument string
        int space_num, i;
        for (space_num = i = 0; argv[name_node_counter][space_num + i]; 
                argv[name_node_counter][space_num + i] == ' ' 
                ? space_num++ : i++);
        if (space_num < 2) {
            printf("Falsche Formattierung in: %s\n", argv[name_node_counter]);
            return 22;
        } 

        char *trunc;
        trunc = strtok(argv[name_node_counter], " ");
        new_name_node->vorname = trunc;
        trunc = strtok(NULL, " ");
        new_name_node->nachname = trunc;
        trunc = strtok(NULL, " ");
        if (!trunc) return 22;
        new_name_node->call = trunc[0];

        new_name_node->next_node_ptr = NULL;

        name_node_buffer->next_node_ptr = new_name_node;

        name_node_buffer = name_node_buffer->next_node_ptr;
    }

    return 0;
}


static void print_names() {
    struct name *name_node_buffer;
    
    name_node_buffer = start_name_node;

    if (name_node_buffer == NULL) {
        printf("Keine Namen angegeben.");
    } else {
        while (name_node_buffer != NULL) {
            printf("Hallo ");
            if (name_node_buffer->call == 'm') {
                printf("Herr ");
            } else if (name_node_buffer->call == 'f') {
                printf("Frau ");
            }

            if (name_node_buffer->call == '*') {
                printf("%s\n", name_node_buffer->vorname);
            } else {
                printf("%s\n", name_node_buffer->nachname); 
            }

            name_node_buffer = name_node_buffer->next_node_ptr;
        }    
    }
}


void rec_free(struct name *name_node) {
    if (name_node->next_node_ptr != NULL) {
        rec_free(name_node->next_node_ptr);
    }
    free(name_node);
}

