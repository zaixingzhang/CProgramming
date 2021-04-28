#ifndef _KNOWLEDGE_TB_H
#define _KNOWLEDGE_TB_H

#define ABBREV_MAX_SIZE 24
#define FULL_NAME_MAX_SIZE 64 
#define CHINESE_MAX_SIZE 64
#define DESCRIPTION_MAX_SIZE 128

typedef struct knowledge Knowledge; 

typedef Knowledge * (*GETNEXT)(Knowledge * self);
typedef void (*PRINT_KNOWLEDGE)(Knowledge * self);

Knowledge * NewKnowledge(void);

struct knowledge{
	int id;
	char abbrev[ABBREV_MAX_SIZE];
	char full_name[FULL_NAME_MAX_SIZE];
	char chinese[CHINESE_MAX_SIZE];
	char description[DESCRIPTION_MAX_SIZE];	
	Knowledge * next;
	GETNEXT getNext;
	PRINT_KNOWLEDGE print;
};

#endif 
