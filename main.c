/*
* This program was designed to create a list of Student 

* User inputs the number of students, then enters the grades
* As a result, the table of all the students is printed, with their grades
* In addition, the minimum, maximum and average of total grades of the whole class is printed
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char ** argv){
	
	//a loop to make sure that the number of students is greater or equals 2
	while(true){
		
		//take an input from a user to determine the size of the array 
		printf("Please enter a number of students: ");
		scanf("%d", &size);
		
		//check if the size is greater or equals 2
		if(size < 2){
			printf("\nThe number of students must be greater than 2\n\n");
			continue;
		//if the input is valid, allocate memory for the arrays and call methods 
		//which input students, print students, and calculate statistics
		} else {
			Student ** students;
			students = malloc(sizeof(Student*) * size);
			double * statistics = (double*) malloc(sizeof(double) * size);
		
			inputStudents(students, size); // input a student
			statsStudents(students, size, statistics); // to calculate class statistics
			printStudents(students, size, statistics); // print a student
			
			free(students);
		}
		
		return 0;
	}	
}


