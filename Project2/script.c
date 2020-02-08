/*
 *script.c
 *Prabhat Bhootra
 *Professor Chris Armen
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define stringlen 500

void uppercase(char s[]);
void removechars(char s[]);
int testInstruction();
void print(char t, signed char s[], int f);       //function prototypes

// main to accept file input for interpreter
void main(){

	signed char registers[4];
	signed char memory[8];

	int x, y;
	for (x = 0; x < 4; x++){
		registers[x] = 0;
	}
	for (y = 0; y < 8; y++){
		memory[y] = 0;
	}

	struct{
		unsigned int ZF: 1;
		unsigned int SF: 1;
		unsigned int OF: 1;
	} flag;	

	flag.ZF = 0;
	flag.SF = 0;
	flag.OF = 0;
	char c[stringlen][stringlen] = {};
	int condition = 0;

	while (condition == 0){
		printf("\nEnter instruction>\n");		
		if (scanf("%s", c[0]) == EOF){
			break;
		}
		uppercase(c[0]);
		
			
		if (strcmp(c[0], "READ") == 0){	
			flag.ZF = 0;
			flag.SF = 0;
			flag.OF = 0;
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s", c[1]);
			removechars(c[1]);
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s", c[2]);
			removechars(c[2]);
			uppercase(c[2]);
			if (atoi(c[1]) == 0){
				printf("Invalid data or invalid data syntax");
				continue;
			}
			if ((atoi(c[1]) > 127) || (atoi(c[1]) < -128)){
				flag.OF = 1;
			}
			if (atoi(c[1]) < 0) {
				flag.SF = 1;
			}
			if (c[1] == 0) {
				flag.ZF = 1;
			}
			if ((c[2][0] == 'M') && ((c[2][1] - '0') < 8) && (isdigit(c[2][1]))){
				memory[(c[2][1] - '0')] = atoi(c[1]);
			}
			else if ((c[2][0] == 'R') && ((c[2][1] - '0') < 4) && (isdigit(c[2][1]))){
				registers[(c[2][1] - '0')] = atoi(c[1]);
			}
			else{
				printf("Invalid register/memory location.\n");
				continue;
			}				
		}
		else if (strcmp(c[0], "WRITE") == 0){
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[1]); 
			removechars(c[1]);
			uppercase(c[1]);
			if ((c[1][0] == 'M') && ((c[1][1] - '0') < 8) && (isdigit(c[1][1]))){
				printf("Value: %X\n", memory[c[1][1] - '0']);
			}
			else if ((c[1][0] == 'R') && ((c[1][1] - '0') < 4) && (isdigit(c[1][1]))){
				printf("Value: %X\n", registers[c[1][1] - '0']);
			}
			else{
				printf("Invalid register/memory location.");
				continue;
			}				
		}
		else if (strcmp(c[0], "PRINTS") == 0){
			print('R', registers, 0);
			print('R', registers, 1);
			print('R', registers, 2);
			print('R', registers, 3);
			print('M', memory, 0);
			print('M', memory, 1);
			print('M', memory, 2);
			print('M', memory, 3);
			print('M', memory, 4);
			print('M', memory, 5);
			print('M', memory, 6);
			print('M', memory, 7);
			printf("    %2X", flag.ZF);
			printf("    %2X", flag.SF);
			printf("    %2X", flag.OF);
			printf("\n");
			printf("--");
			printf("    --");
			printf("    --");
			printf("    --");
			printf("    --");
			printf("    --");
			printf("    --");
			printf("    --");
			printf("    --");
			printf("    --");
			printf("    --");
			printf("    --");
			printf("    --");
			printf("    --");
			printf("    --");
			printf("\n");
			printf("R0");
			printf("    R1");
			printf("    R2");
			printf("    R3");
			printf("    M0");
			printf("    M1");
			printf("    M2");
			printf("    M3");
			printf("    M4");
			printf("    M5");
			printf("    M6");
			printf("    M7");
			printf("    ZF");
			printf("    SF");
			printf("    OF");
			printf("\n");
		}
		else if (strcmp(c[0], "MOVE") == 0){
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[1]); 
			removechars(c[1]);
			uppercase(c[1]);
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[2]); 
			removechars(c[2]);
			uppercase(c[2]);
			if ((c[1][0] == 'M') && ((c[1][1] - '0') < 8) && (isdigit(c[1][1]))){
				if ((c[2][0] == 'R') && ((c[2][1] - '0') < 4) && (isdigit(c[2][1]))){
					registers[c[2][1] - '0'] = memory[c[1][1] - '0'];
				}
				else if (c[2][0] == 'M'){
					printf("Move can't be used from memory to memory.\n");
					continue;
				}
				else{
					printf("Invalid register/memory location.\n");
					continue;
				}
			}
			else if ((c[1][0] == 'R') && ((c[1][1] - '0') < 4) && (isdigit(c[1][1]))){
				if ((c[2][0] == 'M') && ((c[2][1] - '0') < 8) && (isdigit(c[2][1]))){
					memory[c[2][1] - '0'] = registers[c[1][1] - '0'];
				}
				else if ((c[2][0] == 'R') && ((c[2][1] - '0') < 4) && (isdigit(c[2][1]))){
					registers[c[2][1] - '0'] = registers[c[1][1] - '0'];
				}
				else{
					printf("Invalid register/memory location.\n");
					continue;
				}
			}
			else{
				printf("Invalid register/memory location.\n");
				continue;
			}	
		}
		else if (strcmp(c[0], "ADD") == 0){
			flag.ZF = 0;
			flag.SF = 0;
			flag.OF = 0;
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[1]); 
			removechars(c[1]);
			uppercase(c[1]);
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[2]); 
			removechars(c[2]);
			uppercase(c[2]);
			if ((c[1][0] == 'M') && ((c[1][1] - '0') < 8) && (isdigit(c[1][1]))){
				if ((c[2][0] == 'R') && ((c[2][1] - '0') < 4) && (isdigit(c[2][1]))){
					if (((memory[c[1][1] - '0'] + registers[c[2][1] - '0']) > 127) || ((memory[c[1][1] - '0'] + registers[c[2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((memory[c[1][1] - '0'] + registers[c[2][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((memory[c[1][1] - '0'] + registers[c[2][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = memory[c[1][1] - '0'] + registers[c[2][1] - '0'];
				}
				else if (c[2][0] == 'M'){
					printf("Add can't be used from memory to memory.\n");
					continue;
				}
				else{
					printf("Invalid register/memory location.\n");
					continue;
				}
			}
			else if ((c[1][0] == 'R') && ((c[1][1] - '0') < 4) && (isdigit(c[1][1]))){
				if ((c[2][0] == 'M') && ((c[2][1] - '0') < 8) && (isdigit(c[2][1]))){
					if (((memory[c[2][1] - '0'] + registers[c[1][1] - '0']) > 127) || ((memory[c[2][1] - '0'] + registers[c[1][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((memory[c[2][1] - '0'] + registers[c[1][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((memory[c[2][1] - '0'] + registers[c[1][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = memory[c[2][1] - '0'] + registers[c[1][1] - '0'];
				}
				else if ((c[2][0] == 'R') && ((c[2][1] - '0') < 4) && (isdigit(c[2][1]))){
					if (((registers[c[1][1] - '0'] + registers[c[2][1] - '0']) > 127) || ((registers[c[1][1] - '0'] + registers[c[2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[1][1] - '0'] + registers[c[2][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[1][1] - '0'] + registers[c[2][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[1][1] - '0'] + registers[c[2][1] - '0'];
				}
				else{
					printf("Invalid register/memory location.\n");
					continue;
				}
			}
			else{
				printf("Invalid register/memory location.\n");
				continue;
			}
		}
		else if (strcmp(c[0], "SUB") == 0){
			flag.ZF = 0;
			flag.SF = 0;
			flag.OF = 0;
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[1]); 
			removechars(c[1]);
			uppercase(c[1]);
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[2]); 
			removechars(c[2]);
			uppercase(c[2]);
			if ((c[1][0] == 'M') && ((c[1][1] - '0') < 8) && (isdigit(c[1][1]))){
				if ((c[2][0] == 'R') && ((c[2][1] - '0') < 4) && (isdigit(c[2][1]))){
					if (((registers[c[2][1] - '0'] - memory[c[1][1] - '0']) > 127) || ((registers[c[2][1] - '0'] - memory[c[1][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[2][1] - '0'] - memory[c[1][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[2][1] - '0'] - memory[c[1][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[2][1] - '0'] - memory[c[1][1] - '0'];
				}
				else if (c[2][0] == 'M'){
					printf("Sub can't be used from memory to memory.\n");
					continue;
				}
				else{
					printf("Invalid register/memory location.\n");
					continue;
				}
			}
			else if ((c[1][0] == 'R') && ((c[1][1] - '0') < 4) && (isdigit(c[1][1]))){
				if ((c[2][0] == 'M') && ((c[2][1] - '0') < 8) && (isdigit(c[2][1]))){
					if (((memory[c[2][1] - '0'] - registers[c[1][1] - '0']) > 127) || ((memory[c[2][1] - '0'] - registers[c[1][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((memory[c[2][1] - '0'] - registers[c[1][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((memory[c[2][1] - '0'] - registers[c[1][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = memory[c[2][1] - '0'] - registers[c[1][1] - '0'];
				}
				else if ((c[2][0] == 'R') && ((c[2][1] - '0') < 4) && (isdigit(c[2][1]))){
					if (((registers[c[2][1] - '0'] - registers[c[1][1] - '0']) > 127) || ((registers[c[2][1] - '0'] - registers[c[1][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[2][1] - '0'] - registers[c[1][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[2][1] - '0'] - registers[c[1][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[2][1] - '0'] - registers[c[1][1] - '0'];
				}
				else{
					printf("Invalid register/memory location.\n");
					continue;
				}
			}
			else{
				printf("Invalid register/memory location.\n");
				continue;
			}
		}
		else if (strcmp(c[0], "MULT") == 0){
			flag.ZF = 0;
			flag.SF = 0;
			flag.OF = 0;
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[1]); 
			removechars(c[1]);
			uppercase(c[1]);
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[2]); 
			removechars(c[2]);
			uppercase(c[2]);	
			if ((c[1][0] == 'M') && ((c[1][1] - '0') < 8) && (isdigit(c[1][1]))){
				if ((c[2][0] == 'R') && ((c[2][1] - '0') < 4) && (isdigit(c[2][1]))){
					if (((registers[c[2][1] - '0'] * memory[c[1][1] - '0']) > 127) || ((registers[c[2][1] - '0'] * memory[c[1][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[2][1] - '0'] * memory[c[1][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[2][1] - '0'] * memory[c[1][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[2][1] - '0'] * memory[c[1][1] - '0'];
				}
				else if (c[2][0] == 'M'){
					printf("Mult can't be used from memory to memory.\n");
					continue;
				}
				else{
					printf("Invalid register/memory location.\n");
					continue;
				}
			}
			else if ((c[1][0] == 'R') && ((c[1][1] - '0') < 4) && (isdigit(c[1][1]))){
				if ((c[2][0] == 'M') && ((c[2][1] - '0') < 8) && (isdigit(c[2][1]))){
					if (((memory[c[2][1] - '0'] * registers[c[1][1] - '0']) > 127) || ((memory[c[2][1] - '0'] * registers[c[1][1] - '0']) < -128)){
						flag.OF = 1;
					} 
					if ((memory[c[2][1] - '0'] * registers[c[1][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((memory[c[2][1] - '0'] * registers[c[1][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = memory[c[2][1] - '0'] * registers[c[1][1] - '0'];
				}
				else if ((c[2][0] == 'R') && ((c[2][1] - '0') < 4) && (isdigit(c[2][1]))){
					if (((registers[c[2][1] - '0'] * registers[c[1][1] - '0']) > 127) || ((registers[c[2][1] - '0'] * registers[c[1][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[2][1] - '0'] * registers[c[1][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[2][1] - '0'] * registers[c[1][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[2][1] - '0'] * registers[c[1][1] - '0'];
				}
				else{
					printf("Invalid register/memory location.\n");
					continue;
				}
			}
			else{
				printf("Invalid register/memory location.\n");
				continue;
			}
		}
		else if (strcmp(c[0], "DIV") == 0){
			flag.ZF = 0;
			flag.SF = 0;
			flag.OF = 0;
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[1]); 
			removechars(c[1]);
			uppercase(c[1]);
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[2]); 
			removechars(c[2]);
			uppercase(c[2]);	
			if ((c[1][0] == 'M') && ((c[1][1] - '0') < 8) && (isdigit(c[1][1]))){
				if ((c[2][0] == 'R') && ((c[2][1] - '0') < 4) && (isdigit(c[2][1]))){
					if (((memory[c[1][1] - '0']/registers[c[2][1] - '0']) > 127) || ((memory[c[1][1] - '0']/registers[c[2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((memory[c[1][1] - '0']/registers[c[2][1] - '0']) < 0){
						flag.SF  = 1;
					}
					if ((memory[c[1][1] - '0']/registers[c[2][1] - '0']) == 0){
						flag.ZF  = 1;
					}
					registers[0] = memory[c[1][1] - '0']/registers[c[2][1] - '0'];
				}
				else if (c[2][0] == 'M'){
					printf("Div can't be used from memory to memory.\n");
					continue;
				}
				else{
					printf("Invalid register/memory location.\n");
					continue;
				}
			}
			else if ((c[1][0] == 'R') && ((c[1][1] - '0') < 4) && (isdigit(c[1][1]))){
				if ((c[2][0] == 'M') && ((c[2][1] - '0') < 8) && (isdigit(c[2][1]))){
					if (((registers[c[1][1] - '0']/memory[c[2][1] - '0']) > 127) || ((registers[c[1][1] - '0']/memory[c[2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[1][1] - '0']/memory[c[2][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[1][1] - '0']/memory[c[2][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[1][1] - '0']/memory[c[2][1] - '0'];
				}
				else if ((c[2][0] == 'R') && ((c[2][1] - '0') < 4) && (isdigit(c[2][1]))){
					if (((registers[c[1][1] - '0']/registers[c[2][1] - '0']) > 127) || ((registers[c[1][1] - '0']/registers[c[2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[1][1] - '0']/registers[c[2][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[1][1] - '0']/registers[c[2][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[1][1] - '0']/registers[c[2][1] - '0'];
				}
				else{
					printf("Invalid register/memory location.\n");
					continue;
				}
			}
			else{
				printf("Invalid register/memory location.\n");
				continue;
			}
		}
		else if (strcmp(c[0], "MOD") == 0){
			flag.ZF = 0;
			flag.SF = 0;
			flag.OF = 0;
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[1]); 
			removechars(c[1]);
			uppercase(c[1]);
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[2]); 
			removechars(c[2]);
			uppercase(c[2]);	
			if ((c[1][0] == 'M') && ((c[1][1] - '0') < 8) && (isdigit(c[1][1]))){
				if ((c[2][0] == 'R') && ((c[2][1] - '0') < 4) && (isdigit(c[2][1]))){
					if (((memory[c[1][1] - '0']%registers[c[2][1] - '0']) > 127) || ((memory[c[1][1] - '0']%registers[c[2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((memory[c[1][1] - '0']%registers[c[2][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((memory[c[1][1] - '0']%registers[c[2][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = memory[c[1][1] - '0']%registers[c[2][1] - '0'];
				}
				else if (c[2][0] == 'M'){
					printf("Mod can't be used from memory to memory.\n");
					continue;
				}
				else{
					printf("Invalid register/memory location.\n");
					continue;
				}
			}
			else if ((c[1][0] == 'R') && ((c[1][1] - '0') < 4) && (isdigit(c[1][1]))){
				if ((c[2][0] == 'M') && ((c[2][1] - '0') < 8) && (isdigit(c[2][1]))){
					if (((registers[c[1][1] - '0']%memory[c[2][1] - '0']) > 127) || ((registers[c[1][1] - '0']%memory[c[2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[1][1] - '0']%memory[c[2][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[1][1] - '0']%memory[c[2][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[1][1] - '0']%memory[c[2][1] - '0'];
				}
				else if ((c[2][0] == 'R') && ((c[2][1] - '0') < 4) && (isdigit(c[2][1]))){
					if (((registers[c[1][1] - '0']%registers[c[2][1] - '0']) > 127) || ((registers[c[1][1] - '0']%registers[c[2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[1][1] - '0']%registers[c[2][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[1][1] - '0']%registers[c[2][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[1][1] - '0']%registers[c[2][1] - '0'];
				}
				else{
					printf("Invalid register/memory location.\n");
					continue;
				}
			}
			else{
				printf("Invalid register/memory location.\n");
				continue;
			}
		}
		else if (strcmp(c[0], "COMP") == 0){
			flag.ZF = 0;
			flag.SF = 0;
			flag.OF = 0;
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[1]); 
			removechars(c[1]);
			uppercase(c[1]);
			if (testInstruction() == -1){
				continue;
			}
			scanf("%s",c[2]); 
			removechars(c[2]);
			uppercase(c[2]);	
			if ((c[1][0] == 'R') && ((c[1][1] - '0') < 4) && (isdigit(c[1][1]))){
				if ((c[2][0] == 'R') && ((c[2][1] - '0') < 4) && (isdigit(c[2][1]))){
					if (registers[c[1][1] - '0'] > registers[c[2][1] - '0']){
						flag.ZF = 0;
						flag.SF = 1;
					}
					else if (registers[c[1][1] - '0'] < registers[c[2][1] - '0']){
						flag.ZF = 0;
						flag.SF = 0;
					}
					else{
						flag.ZF = 1;
						flag.SF = 0;
					}
				}
				else{
					printf("Comp can only be used on valid registers. Not on memory locations\n");
					continue;
				}
			}
			else{
				printf("Comp can only be used on valid registers. Not on memory locations\n");
				continue;
			}
			
		}
		else if (strcmp(c[0], "QUIT") == 0){
			condition = -1;
		}
		else{
			printf("Please enter a valid instruction");
			continue;
		}
	}
			
} //main

/* functions used in main */
void uppercase(char s[]) {
	int d = 0; 
	while (s[d] != '\0') {
		if (s[d] >= 'a' && s[d] <= 'z') {
         		s[d] = s[d] - 32;
      		}
        	d++;
   	}
}

void removechars(char s[]){
	int i, j;
 	while (s[i] != '\0'){
		if ((s[i] == ',') || s[i] == ' '){
			j = i;
			while (s[j] != '\0'){
				s[j] = s[j+1];
				j++;
			}
		}
		i++;
	}
}
int testInstruction(){
	char h;
	h = getchar();
	if (h == '\n'){
		printf("Invalid instruction.\n");
		return -1;
	}
	return 0;
}

void print(char t, signed char s[], int f){
	if (t == 'R'){
		if (f == 0){
			if (s[f] == 0){
				printf("%c", '?');
			}
			else{
				printf("%X", s[f]);
			}
		}
		else{
			if (s[f] == 0){
				printf("    %2c", '?');
			}
			else{
				printf("    %2X", s[f]);
			}
		}
	}
	else{
		if (s[f] == 0){
			printf("    %2c", '?');
		}
		else{
			printf("    %2X", s[f]);
		}
	}
}
