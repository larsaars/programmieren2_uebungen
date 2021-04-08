#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char *vn, *nn;
} name;

int main(int argc, char **argv) {
        name *names = malloc((argc - 1) * sizeof(name));
        int spacePos = 0, strlen = 0; 

	for(int i = 1; i < argc; i++) {
		char *currentName = argv[i];
                strlen = strlen(currentName);          

		for(int j = 0; j < strlen; j++){
                    if(currentName[j] == ' '){
                        spacePos = j;
                        break;
                    }         
                }
                
                names[i - 1]->vn = malloc((spacePos + 2) * sizeof(char));
                names[i - 1]->nn = malloc((strlen - spacePos) * sizeof(char));

                strchr

	}

	free(names);
}
