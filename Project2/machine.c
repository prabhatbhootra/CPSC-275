/*
 *machine.c
 *Prabhat Bhootra
 *Professor Chris Armen
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define stringlen 500

void uppercase(char s[]);
void removechars(char s[]);
int testInstruction();
void print(char t, signed char s[], int f);       //function prototypes

/* Main for interpreter that takes command from file and executes jump statements */
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
	char l[stringlen][stringlen] = {};
	int check = 0;
	int condition = 0;
	int p = 0;

	while (check == 0){
		if (scanf("%s", c[p]) == EOF){
			check = -1;
		}
		removechars(c[p]);
		p++;	
	}
	
	int a;
	int b;
	int d;
	for (a = 0; a < stringlen; a++){
		uppercase(c[a]);
		if (strcmp(c[a], "START:") == 0){
			break;
		}
	}

	for (d = a+1; d <= p; d++){
		uppercase(c[d]);
		if (strchr(c[d], ':') != NULL){
			strcpy(l[d], c[d]);
			l[d][strlen(l[d])-1] = '\0';
		}
	}

	b = a + 1;

	while ((b <= p) && (condition == 0)){	
		if (strcmp(c[b], "READ") == 0){	
			flag.ZF = 0;
			flag.SF = 0;
			flag.OF = 0;
			if (atoi(c[b+1]) == 0){
				printf("Invalid data or invalid data syntax\n");
				b++;
				continue;
			}
			if ((atoi(c[b+1]) > 127) || (atoi(c[b+1]) < -128)){
				flag.OF = 1;
			}
			if (atoi(c[b+1]) < 0) {
				flag.SF = 1;
			}
			if (c[b+1] == 0) {
				flag.ZF = 1;
			}
			if ((c[b+2][0] == 'M') && ((c[b+2][1] - '0') < 8) && (isdigit(c[b+2][1]))){
				memory[(c[b+2][1] - '0')] = atoi(c[b+1]);
				b++;
			}
			else if ((c[b+2][0] == 'R') && ((c[b+2][1] - '0') < 4) && (isdigit(c[b+2][1]))){
				registers[(c[b+2][1] - '0')] = atoi(c[b+1]);
				b++;
			}
			else{
				printf("Invalid register/memory location.\n");
				b++;
				continue;
			}
							
		}
		else if (strcmp(c[b], "WRITE") == 0){
			if ((c[b+1][0] == 'M') && ((c[b+1][1] - '0') < 8) && (isdigit(c[b+1][1]))){
				printf("Value: %X\n", memory[c[b+1][1] - '0']);
			}
			else if ((c[b+1][0] == 'R') && ((c[b+1][1] - '0') < 4) && (isdigit(c[b+1][1]))){
				printf("Value: %X\n", registers[c[b+1][1] - '0']);
			}
			else{
				printf("Invalid register/memory location.");
				b++;
				continue;
			}
			b++;				
		}
		else if (strcmp(c[b], "PRINTS") == 0){
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
			b++;
		}
		else if (strcmp(c[b], "MOVE") == 0){
			if ((c[b+1][0] == 'M') && ((c[b+1][1] - '0') < 8) && (isdigit(c[b+1][1]))){
				if ((c[b+2][0] == 'R') && ((c[b+2][1] - '0') < 4) && (isdigit(c[b+2][1]))){
					registers[c[b+2][1] - '0'] = memory[c[b+1][1] - '0'];
					b++;
				}
				else if (c[b+2][0] == 'M'){
					printf("Move can't be used from memory to memory.\n");
					b++;
					continue;
				}
				else{
					printf("Invalid register/memory location.\n");
					b++;
					continue;
				}
			}
			else if ((c[b+1][0] == 'R') && ((c[b+1][1] - '0') < 4) && (isdigit(c[b+1][1]))){
				if ((c[b+2][0] == 'M') && ((c[b+2][1] - '0') < 8) && (isdigit(c[b+2][1]))){
					memory[c[b+2][1] - '0'] = registers[c[b+1][1] - '0'];
					b++;
				}
				else if ((c[b+2][0] == 'R') && ((c[b+2][1] - '0') < 4) && (isdigit(c[b+2][1]))){
					registers[c[b+2][1] - '0'] = registers[c[b+1][1] - '0'];
					b++;
				}
				else{
					printf("Invalid register/memory location.\n");
					b++;
					continue;
				}
			}
			else{
				printf("Invalid register/memory location.\n");
				b++;
				continue;
			}	
		}
		else if (strcmp(c[b], "ADD") == 0){
			flag.ZF = 0;
			flag.SF = 0;
			flag.OF = 0;
			if ((c[b+1][0] == 'M') && ((c[b+1][1] - '0') < 8) && (isdigit(c[b+1][1]))){
				if ((c[b+2][0] == 'R') && ((c[b+2][1] - '0') < 4) && (isdigit(c[b+2][1]))){
					if (((memory[c[b+1][1] - '0'] + registers[c[b+2][1] - '0']) > 127) || ((memory[c[b+1][1] - '0'] + registers[c[b+2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((memory[c[b+1][1] - '0'] + registers[c[b+2][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((memory[c[b+1][1] - '0'] + registers[c[b+2][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = memory[c[b+1][1] - '0'] + registers[c[b+2][1] - '0'];
					b++;
				}
				else if (c[b+2][0] == 'M'){
					printf("Add can't be used from memory to memory.\n");
					b++;
					continue;
				}
				else{
					printf("Invalid register/memory location.\n");
					b++;
					continue;
				}
			}
			else if ((c[b+1][0] == 'R') && ((c[b+1][1] - '0') < 4) && (isdigit(c[b+1][1]))){
				if ((c[b+2][0] == 'M') && ((c[b+2][1] - '0') < 8) && (isdigit(c[b+2][1]))){
					if (((memory[c[b+2][1] - '0'] + registers[c[b+1][1] - '0']) > 127) || ((memory[c[b+2][1] - '0'] + registers[c[b+1][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((memory[c[b+2][1] - '0'] + registers[c[b+1][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((memory[c[b+2][1] - '0'] + registers[c[b+1][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = memory[c[b+2][1] - '0'] + registers[c[b+1][1] - '0'];
					b++;
				}
				else if ((c[b+2][0] == 'R') && ((c[b+2][1] - '0') < 4) && (isdigit(c[b+2][1]))){
					if (((registers[c[b+1][1] - '0'] + registers[c[b+2][1] - '0']) > 127) || ((registers[c[b+1][1] - '0'] + registers[c[b+2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[b+1][1] - '0'] + registers[c[b+2][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[b+1][1] - '0'] + registers[c[b+2][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[b+1][1] - '0'] + registers[c[b+2][1] - '0'];
					b++;
				}
				else{
					printf("Invalid register/memory location.\n");
					b++;
					continue;
				}
			}
			else{
				printf("Invalid register/memory location.\n");
				b++;
				continue;
			}
		}
		else if (strcmp(c[b], "SUB") == 0){
			flag.ZF = 0;
			flag.SF = 0;
			flag.OF = 0;
			if ((c[b+1][0] == 'M') && ((c[b+1][1] - '0') < 8) && (isdigit(c[b+1][1]))){
				if ((c[b+2][0] == 'R') && ((c[b+2][1] - '0') < 4) && (isdigit(c[b+2][1]))){
					if (((registers[c[b+2][1] - '0'] - memory[c[b+1][1] - '0']) > 127) || ((registers[c[b+2][1] - '0'] - memory[c[b+1][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[b+2][1] - '0'] - memory[c[b+1][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[b+2][1] - '0'] - memory[c[b+1][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[b+2][1] - '0'] - memory[c[b+1][1] - '0'];
					b++;
				}
				else if (c[b+2][0] == 'M'){
					printf("Sub can't be used from memory to memory.\n");
					b++;
					continue;
				}
				else{
					printf("Invalid register/memory location.\n");
					b++;
					continue;
				}
			}
			else if ((c[b+1][0] == 'R') && ((c[b+1][1] - '0') < 4) && (isdigit(c[b+1][1]))){
				if ((c[b+2][0] == 'M') && ((c[b+2][1] - '0') < 8) && (isdigit(c[b+2][1]))){
					if (((memory[c[b+2][1] - '0'] - registers[c[b+1][1] - '0']) > 127) || ((memory[c[b+2][1] - '0'] - registers[c[b+1][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((memory[c[b+2][1] - '0'] - registers[c[b+1][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((memory[c[b+2][1] - '0'] - registers[c[b+1][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = memory[c[b+2][1] - '0'] - registers[c[b+1][1] - '0'];
					b++;
				}
				else if ((c[b+2][0] == 'R') && ((c[b+2][1] - '0') < 4) && (isdigit(c[b+2][1]))){
					if (((registers[c[b+2][1] - '0'] - registers[c[b+1][1] - '0']) > 127) || ((registers[c[b+2][1] - '0'] - registers[c[b+1][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[b+2][1] - '0'] - registers[c[b+1][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[b+2][1] - '0'] - registers[c[b+1][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[b+2][1] - '0'] - registers[c[b+1][1] - '0'];
					b++;
				}
				else{
					printf("Invalid register/memory location.\n");
					b++;
					continue;
				}
			}
			else{
				printf("Invalid register/memory location.\n");
				b++;
				continue;
			}
		}
		else if (strcmp(c[b], "MULT") == 0){	
			flag.ZF = 0;
			flag.SF = 0;
			flag.OF = 0;
			if ((c[b+1][0] == 'M') && ((c[b+1][1] - '0') < 8) && (isdigit(c[b+1][1]))){
				if ((c[b+2][0] == 'R') && ((c[b+2][1] - '0') < 4) && (isdigit(c[b+2][1]))){
					if (((registers[c[b+2][1] - '0'] * memory[c[b+1][1] - '0']) > 127) || ((registers[c[b+2][1] - '0'] * memory[c[b+1][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[b+2][1] - '0'] * memory[c[b+1][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[b+2][1] - '0'] * memory[c[b+1][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[b+2][1] - '0'] * memory[c[b+1][1] - '0'];
					b++;
				}
				else if (c[b+2][0] == 'M'){
					printf("Mult can't be used from memory to memory.\n");
					b++;
					continue;
				}
				else{
					printf("Invalid register/memory location.\n");
					b++;
					continue;
				}
			}
			else if ((c[b+1][0] == 'R') && ((c[b+1][1] - '0') < 4) && (isdigit(c[b+1][1]))){
				if ((c[b+2][0] == 'M') && ((c[b+2][1] - '0') < 8) && (isdigit(c[b+2][1]))){
					if (((memory[c[b+2][1] - '0'] * registers[c[b+1][1] - '0']) > 127) || ((memory[c[b+2][1] - '0'] * registers[c[b+1][1] - '0']) < -128)){
						flag.OF = 1;
					} 
					if ((memory[c[b+2][1] - '0'] * registers[c[b+1][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((memory[c[b+2][1] - '0'] * registers[c[b+1][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = memory[c[b+2][1] - '0'] * registers[c[b+1][1] - '0'];
					b++;
				}
				else if ((c[b+2][0] == 'R') && ((c[b+2][1] - '0') < 4) && (isdigit(c[b+2][1]))){
					if (((registers[c[b+2][1] - '0'] * registers[c[b+1][1] - '0']) > 127) || ((registers[c[b+2][1] - '0'] * registers[c[b+1][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[b+2][1] - '0'] * registers[c[b+1][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[b+2][1] - '0'] * registers[c[b+1][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[b+2][1] - '0'] * registers[c[b+1][1] - '0'];
					b++;
				}
				else{
					printf("Invalid register/memory location.\n");
					b++;
					continue;
				}
			}
			else{
				printf("Invalid register/memory location.\n");
				b++;
				continue;
			}
		}
		else if (strcmp(c[b], "DIV") == 0){	
			flag.ZF = 0;
			flag.SF = 0;
			flag.OF = 0;
			if ((c[b+1][0] == 'M') && ((c[b+1][1] - '0') < 8) && (isdigit(c[b+1][1]))){
				if ((c[b+2][0] == 'R') && ((c[b+2][1] - '0') < 4) && (isdigit(c[b+2][1]))){
					if (((memory[c[b+1][1] - '0']/registers[c[b+2][1] - '0']) > 127) || ((memory[c[b+1][1] - '0']/registers[c[b+2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((memory[c[b+1][1] - '0']/registers[c[b+2][1] - '0']) < 0){
						flag.SF  = 1;
					}
					if ((memory[c[b+1][1] - '0']/registers[c[b+2][1] - '0']) == 0){
						flag.ZF  = 1;
					}
					registers[0] = memory[c[b+1][1] - '0']/registers[c[b+2][1] - '0'];
					b++;
				}
				else if (c[b+2][0] == 'M'){
					printf("Div can't be used from memory to memory.\n");
					b++;
					continue;
				}
				else{
					printf("Invalid register/memory location.\n");
					b++;
					continue;
				}
			}
			else if ((c[b+1][0] == 'R') && ((c[b+1][1] - '0') < 4) && (isdigit(c[b+1][1]))){
				if ((c[b+2][0] == 'M') && ((c[b+2][1] - '0') < 8) && (isdigit(c[b+2][1]))){
					if (((registers[c[b+1][1] - '0']/memory[c[b+2][1] - '0']) > 127) || ((registers[c[b+1][1] - '0']/memory[c[b+2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[b+1][1] - '0']/memory[c[b+2][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[b+1][1] - '0']/memory[c[b+2][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[b+1][1] - '0']/memory[c[b+2][1] - '0'];
					b++;
				}
				else if ((c[b+2][0] == 'R') && ((c[b+2][1] - '0') < 4) && (isdigit(c[b+2][1]))){
					if (((registers[c[b+1][1] - '0']/registers[c[b+2][1] - '0']) > 127) || ((registers[c[b+1][1] - '0']/registers[c[b+2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[b+1][1] - '0']/registers[c[b+2][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[b+1][1] - '0']/registers[c[b+2][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[b+1][1] - '0']/registers[c[b+2][1] - '0'];
					b++;
				}
				else{
					printf("Invalid register/memory location.\n");
					b++;
					continue;
				}
			}
			else{
				printf("Invalid register/memory location.\n");
				b++;
				continue;
			}
		}
		else if (strcmp(c[b], "MOD") == 0){
			flag.ZF = 0;
			flag.SF = 0;
			flag.OF = 0;	
			if ((c[b+1][0] == 'M') && ((c[b+1][1] - '0') < 8) && (isdigit(c[b+1][1]))){
				if ((c[b+2][0] == 'R') && ((c[b+2][1] - '0') < 4) && (isdigit(c[b+2][1]))){
					if (((memory[c[b+1][1] - '0']%registers[c[b+2][1] - '0']) > 127) || ((memory[c[b+1][1] - '0']%registers[c[b+2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((memory[c[b+1][1] - '0']%registers[c[b+2][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((memory[c[b+1][1] - '0']%registers[c[b+2][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = memory[c[b+1][1] - '0']%registers[c[b+2][1] - '0'];
					b++;
				}
				else if (c[b+2][0] == 'M'){
					printf("Mod can't be used from memory to memory.\n");
					b++;
					continue;
				}
				else{
					printf("Invalid register/memory location.\n");
					b++;
					continue;
				}
			}
			else if ((c[b+1][0] == 'R') && ((c[b+1][1] - '0') < 4) && (isdigit(c[b+1][1]))){
				if ((c[b+2][0] == 'M') && ((c[b+2][1] - '0') < 8) && (isdigit(c[b+2][1]))){
					if (((registers[c[b+1][1] - '0']%memory[c[b+2][1] - '0']) > 127) || ((registers[c[b+1][1] - '0']%memory[c[b+2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[b+1][1] - '0']%memory[c[b+2][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[b+1][1] - '0']%memory[c[b+2][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[b+1][1] - '0']%memory[c[b+2][1] - '0'];
					b++;
				}
				else if ((c[b+2][0] == 'R') && ((c[b+2][1] - '0') < 4) && (isdigit(c[b+2][1]))){
					if (((registers[c[b+1][1] - '0']%registers[c[b+2][1] - '0']) > 127) || ((registers[c[b+1][1] - '0']%registers[c[b+2][1] - '0']) < -128)){
						flag.OF = 1;
					}
					if ((registers[c[b+1][1] - '0']%registers[c[b+2][1] - '0']) < 0){
						flag.SF = 1;
					}
					if ((registers[c[b+1][1] - '0']%registers[c[b+2][1] - '0']) == 0){
						flag.ZF = 1;
					}
					registers[0] = registers[c[b+1][1] - '0']%registers[c[b+2][1] - '0'];
					b++;
				}
				else{
					printf("Invalid register/memory location.\n");
					b++;
					continue;
				}
			}
			else{
				printf("Invalid register/memory location.\n");
				b++;
				continue;
			}
		}
		else if (strcmp(c[b], "COMP") == 0){	
			flag.ZF = 0;
			flag.SF = 0;
			flag.OF = 0;
			if ((c[b+1][0] == 'R') && ((c[b+1][1] - '0') < 4) && (isdigit(c[b+1][1]))){
				if ((c[b+2][0] == 'R') && ((c[b+2][1] - '0') < 4) && (isdigit(c[b+2][1]))){
					if (registers[c[b+1][1] - '0'] > registers[c[b+2][1] - '0']){
						flag.ZF = 0;
						flag.SF = 1;
						b++;
					}
					else if (registers[c[b+1][1] - '0'] < registers[c[b+2][1] - '0']){
						flag.ZF = 0;
						flag.SF = 0;
						b++;
					}
					else{
						flag.ZF = 1;
						flag.SF = 0;
						b++;
					}
				}
				else{
					printf("Comp can only be used on valid registers. Not on memory locations\n");
					b++;
					continue;
				}
			}
			else{
				printf("Comp can only be used on valid registers. Not on memory locations\n");
				b++;
				continue;
			}
			
		}
		else if (strcmp(c[b], "JMP") == 0){
			int e;
			int condition1 = 0;
			for (e = 0; e <= p; e++){
				if (strcmp(c[b+1], l[e]) == 0){
					b = e + 1;
					condition1 = -1;
					break;
				}
			}	
			if (condition1 == 0){
				b++;
			}
		}
		else if (strcmp(c[b], "JE") == 0){
			if (flag.ZF == 1){
				int e;
				for (e = 0; e <= p; e++){
					if (strcmp(c[b+1], l[e]) == 0){
						b = e + 1;
						break;
					}
				}	
			} else{	
				b++;
			}
		}
		else if (strcmp(c[b], "JNE") == 0){
			if (flag.ZF == 0){
				int e;
				for (e = 0; e <= p; e++){
					if (strcmp(c[b+1], l[e]) == 0){
						b = e + 1;
						break;
					}
				}	
			} else{	
				b++;
			}
		}
		else if (strcmp(c[b], "JG") == 0){
			if (!((flag.SF == 1) && (flag.OF == 1)) && !(flag.ZF == 1)){
				int e;
				for (e = 0; e <= p; e++){
					if (strcmp(c[b+1], l[e]) == 0){
						b = e + 1;
						break;
					}
				}	
			} else{	
				b++;
			}
		}
		else if (strcmp(c[b], "JGE") == 0){
			if (!((flag.SF == 1) && (flag.OF == 1))){
				int e;
				for (e = 0; e <= p; e++){
					if (strcmp(c[b+1], l[e]) == 0){
						b = e + 1;
						break;
					}
				}	
			} else{	
				b++;
			}
		}
		else if (strcmp(c[b], "JL") == 0){
			if ((flag.SF == 1) && (flag.OF == 1)){
				int e;
				for (e = 0; e <= p; e++){
					if (strcmp(c[b+1], l[e]) == 0){
						b = e + 1;
						break;
					}
				}	
			} else{	
				b++;
			}
		}
		else if (strcmp(c[b], "JL") == 0){
			if ((flag.SF == 1) && (flag.OF == 1)){
				int e;
				for (e = 0; e <= p; e++){
					if (strcmp(c[b+1], l[e]) == 0){
						b = e + 1;
						break;
					}
				}	
			} else{	
				b++;
			}
		}
		else if (strcmp(c[b], "JLE") == 0){
			if (((flag.SF == 1) && (flag.OF == 1)) || (flag.ZF == 1)){
				int e;
				for (e = 0; e <= p; e++){
					if (strcmp(c[b+1], l[e]) == 0){
						b = e + 1;
						break;
					}
				}	
			} else{	
				b++;
			}
		}
		else if (strcmp(c[b], "QUIT") == 0){
			condition = -1;
		}
		else{
			printf("--\n");
			b++;
			
		}
		
	}	

}     //main

/* Functions used in main */

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
		if ((s[i] == ',') || (s[i] == ' ')){
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
		printf("Invalid instruction\n");
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


