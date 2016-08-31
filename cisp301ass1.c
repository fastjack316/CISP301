/* preamble

	Program Assignment 1 CISP 301
	Author: Seth Mackling
	Date: 8/31/2016
	Purpose: Display record of fake employee pay

*/

#include <stdio.h>
#include <conio.h>

    #define REPORTHEADINGS "     Name                   Pay Rate     Hours     Gross    Tax    Net\n"
  	#define format         "     %-15s%-20s%8.2f%10.2f%10.2f%8.2f%10.2f\n"

int main(void)
    {
			char answer;
			int employeecount;
			
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
	      //gross = hours * payrate;   /* processing */
	      if (emp[employeecount].hours <= 40)
             emp[employeecount].gross = emp[employeecount].hours * emp[employeecount].payrate;
          else
             emp[employeecount].gross = 40 * emp[employeecount].payrate +1.5*emp[employeecount].payrate*(emp[employeecount].hours-40);
		emp[employeecount].tax = emp[employeecount].gross * 0.15; // calculate tax using static value
		emp[employeecount].net = emp[employeecount].gross - emp[employeecount].tax;
	      employeecount++; // add 1 to variable
	      printf(" Do you have another employee (Y / N) ?");
	      fflush(stdin); // REQUIRED for a single character input
	      scanf("%c",&answer);
		} while (answer == 'Y' || answer == 'y');
		printf(REPORTHEADINGS);
	      printf(format,emp[0].firstname,emp[0].lastname,emp[0].payrate,emp[0].hours,emp[0].gross,emp[0].tax,emp[0].net); // one line output for test purposes
		  
		 fflush(stdin); // fflush + getchar pauses screen
	    getchar();
		return 0;
	}
	
