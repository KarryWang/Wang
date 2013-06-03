#include"candidate.h"
#include<ctime>
#include<cstdlib>
#include<mysql.h>
#define MAX_CANDIDATE_ID 1000000

Candidate::Candidate(string can_name)
{
	name = can_name;
	srand((unsigned)time(NULL));
	id = rand() % MAX_CANDIDATE_ID;
}
