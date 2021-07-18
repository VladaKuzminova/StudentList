typedef struct {
	char name[60];
	double cSharp, math, systems;
	double total;
}Student;

int size; //to determine the size of the memory needed to store an array
void inputStudents(Student * student[ ], int size); // to input students info
void statsStudents(Student * students[ ], int size, double stats[ ]); // to calculate class statistics
void printStudents(Student * students[ ], int size, const double stats[ ]); // to print students & the stats
