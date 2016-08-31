/* preamble

	Program Assignment 1 CISP 301
	Author: Seth Mackling
	Date: 8/31/2016
	Purpose: Assemble fake employee pay statement

*/

#include <stdio.h>
#include <conio.h>

    #define REPORTHEADINGS "     Name                   Pay Rate     Hours     Gross    Tax    Net\n" //formatting is broken right now
  	#define format         "     %-15s%-20s%8.2f%10.2f%10.2f%8.2f%10.2f\n" //figure out the right numbers here and how to append , between first last

int main(void)
    {
			char answer;
			int employeecount;
			int silly; // the need for this variable seems silly to me
			
              struct employees // store all employee data linked together
                     {
                     char firstname[15];
                     char lastname[20];
                     float payrate;
                     float hours;
					 float gross;
					 float tax;
					 float net;
                     } emp[9]; // inefficiently assign static memory because i don't know how to use pointers yet
				
			employeecount = 0;  //initialize a counter to progress through array
			do
		{
	      printf("Enter employee's first name ");  // input section
	      scanf("%s",emp[employeecount].firstname);
		  printf("Enter employee's last name ");
		  scanf("%s",emp[employeecount].lastname);
	      printf("Enter hourly pay rate ");
	      scanf("%f",&(emp[employeecount].payrate));
	      printf("Enter hours worked this pay period");
	      scanf("%f",&(emp[employeecount].hours));
	      /* processing block 
		     determines need for overtime, then applies tax and net, stores all data in array */
	      if (emp[employeecount].hours <= 40)
             emp[employeecount].gross = emp[employeecount].hours * emp[employeecount].payrate;
          else
             emp[employeecount].gross = 40 * emp[employeecount].payrate +1.5*emp[employeecount].payrate*(emp[employeecount].hours-40);
		emp[employeecount].tax = emp[employeecount].gross * 0.15; // calculate tax using static value
		emp[employeecount].net = emp[employeecount].gross - emp[employeecount].tax;
	      employeecount++; // increments array
	      printf(" Do you have another employee (Y / N) ?");
	      fflush(stdin);
	      scanf("%c",&answer);
		} while (answer == 'Y' || answer == 'y');
		printf(REPORTHEADINGS);
		for (silly = 0; silly < employeecount; silly++) // iterate outputs through array
		{
				printf(format,emp[silly].firstname,emp[silly].lastname,emp[silly].payrate,emp[silly].hours,emp[silly].gross,emp[silly].tax,emp[silly].net); 
		}
		fflush(stdin); // allows viewing output
	    getchar();
		return 0;
	}
	
