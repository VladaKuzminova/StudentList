#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//this method is for getting an input from a user for the Student structure
void inputStudents(Student * students[ ], int size){
	
	//loop to make sure that user inputs on every positions of the structure
	for (int index = 0; index < size; index++) {
	    
		Student *student = (Student*) malloc(sizeof(Student));
	    students[index] = student;
	    
	    
	    printf("\nEnter Student %d's name: ", index+1);
		scanf("%s", student->name);
		
		//loop to check if value is valid. It must be greater than 0 and less or equals a 100	    
		do{
			printf("CSharp grade: ");
			scanf("%lf", &student->cSharp);
			    	
			if(student->cSharp < 0 || student->cSharp > 100){
			    printf("\nGrade cannot be negative or greater than 100\n\n");
			} else {
				continue;
			}
		} while(student->cSharp < 0 || student->cSharp > 100);
		
		//loop to check if value is valid. It must be greater than 0 and less or equals a 100		    
		do{
			printf("Math grade: ");
			scanf("%lf", &student->math);
			    	
			if(student->math < 0 || student->math > 100){
				printf("\nGrade cannot be negative or greater than 100\n\n");
			} else {
				continue;
			}
		} while(student->math < 0 || student->math > 100);
		
		//loop to check if value is valid. It must be greater than 0 and less or equals a 100		    
		do{
			printf("Systems grade: ");
			scanf("%lf", &student->systems);
			    	
			if(student->systems < 0 || student->systems > 100){
			    printf("\nGrade cannot be negative or greater than 100\n\n");
			} else {
				continue;
			}
		} while(student->systems < 0 || student->systems > 100);
			      
		printf("\n");
	
	}	
}

//this method calculates statistics of the class 
void statsStudents(Student * students[ ], int size, double stats[ ]) {

	//assigning values to the stats array
	//stats[0] - gets the max value
	//stats[1] - gets the min value
	//stats[2] - gets the average of min and max
	stats[0] = 300, stats[1] = 0, stats[2] = 0;
	
	//loop to iterate through the whole array
	//to calculate the min, max, and average of the user input values
	for (int index = 0; index < size; index++) {
		
		students[index]->total = students[index]->cSharp + students[index]->math + students[index]->systems;
		stats[2] += students[index]->total;
		
		//to assign the max value
		if (students[index]->total < stats[0]) {
			stats[0] = students[index]->total;
		}
		
		//to assign the min value
		if (students[index]->total > stats[1]) {
			stats[1] = students[index]->total;
		}
	}
	
	stats[2] = stats[2]/size; //calculate the average of all values
}

void printStudents(Student * students[ ], int size, const double stats[ ]){
	//designing the table
	printf("\n-------------------------------------------------------------\n-------------------------------------------------------------\n\n");
	printf("Number\tCSharp\tMath\tSystems\tTotal\tName\n");
	
	//loop to iterate through the array and print values
	for (int i = 0; i < size; i++) {
		printf("%d\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%s\n", (i+1), students[i]->cSharp, students[i]->math, students[i]->systems, students[i]->total, students[i]->name);
	}

	printf("\n\nStatistics of the class: \n");
	printf("min = %.2lf, max = %.2lf, avg = %.2lf\n\n", stats[0], stats[1], stats[2]);
}
