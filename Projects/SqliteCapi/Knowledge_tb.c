#include <stdio.h>
#include <stdlib.h>
#include "Knowledge_tb.h"


static Knowledge * getNext(Knowledge * self)
{
	return self->next;
}

static void print(Knowledge * self)
{
	printf("==================\n");
	printf("id = %d\n", self->id);
	printf("abbrev = %s\n", self->abbrev);
	printf("full_name = %s\n", self->full_name);
	printf("chinese = %s\n", self->chinese);
	printf("description = %s\n", self->description);
	printf("==================\n");
}

Knowledge * NewKnowledge(void)
{
	Knowledge * know;
	know = (Knowledge *)malloc(sizeof(Knowledge));
	know->next = NULL;
	know->getNext = getNext;
	know->print = print;
	return know;
}
