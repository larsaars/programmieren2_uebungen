#include <stdio.h>

#define true 1
#define false 0

int main(int argc, char **argv) {
	int c, nl = 0, ws = 0, cs = 0;
	int lastWasSpace = false;	

	FILE *file = fopen(argv[1], "r");
	if(file == NULL){
		perror("Error: ");
		return -1;
	}

	while(!feof(file)) {
		c = fgetc(file);
		cs++;
		
		if(c == '\n')
			nl++;	
		
		if(c == ' ') {
			if(!lastWasSpace)
				ws++;
			lastWasSpace = true;
		} else {
			lastWasSpace = false;
		}
	}

	printf("%d  %d  %d  %s\n", nl, ws, cs, argv[1]);

	fclose(file);
}

