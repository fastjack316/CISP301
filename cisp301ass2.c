/* preamble

	Program Assignment 1 and 2 CISP 301
	Author: Seth Mackling
	Date: 8/31/2016
	Purpose: Assemble fake employee pay statement
	
	9/12/2016 Seth Mackling strcpy strcat series added, formatting fixed for columns
	9/12/2016 Seth Mackling redirect output to file instead of stdout
	9/19/2016 Seth Mackling begin work to convert assignment 1 to assignment 2

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    #define REPORTHEADINGS "     Name                   Pay Rate     Hours     Gross Pay     Tax Paid     Net Pay\n" //formatting is broken right now
  	#define format         "     %-23s%7.2f%11.2f%14.2f%13.2f%12.2f\n" //figure out the right numbers here and how to append , between first last

int main(void)
    {
			char answer;
			int employeecount;
			int silly; // the need for this variable seems silly to me
			char result[52+1]; //output
			float TAXRATE; //constant taxrate
			FILE * reportFile; //step 1: declare a report file variable
			reportFile = fopen("report.txt","wt"); //step 2: create a report file in write-text mode
			if (reportFile == NULL)
			                  {
                              printf(" File open request has failed \n");
                              printf(" Terminating application \n");
                              fflush(stdin);
                              getchar();
                              exit(-100); //error handling for inability to create file
                              }
			float payratetotal, hourstotal, grosstotal, taxtotal, finaltotal; //variables needed for running totals
			float payrateavg, hoursavg, grossavg, taxavg, finalavg;
			char DIVIDER [85+1] = "     ================================================================================\n";
			
              struct employees // store all employee data linked together
                     {
                     char firstname[10+1];
                     char lastname[20+1];
                     float payrate;
                     float hours;
					 float gross;
					 float tax;
					 float net;
                     } emp[9]; // inefficiently assign static memory because i don't know how to use pointers yet
			TAXRATE = 0.15; //define constant	

			employeecount = 0;  //initialize a counter to progress through array
			//inits all running total variables to 0
			payratetotal = hourstotal = grosstotal = taxtotal = finaltotal = payrateavg = hoursavg = grossavg = taxavg = finalavg = 0;
		do
			{
                         if (employeecount = 10) //escape function to prevent overflowing memory allocation
                            break;
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
		emp[employeecount].tax = emp[employeecount].gross * TAXRATE; // calculate tax using static value equal to 15%
		emp[employeecount].net = emp[employeecount].gross - emp[employeecount].tax;
	      employeecount++; // increments array
	      printf(" Do you have another employee (Y / N) ?");
	      fflush(stdin);
	      scanf("%c",&answer);
		} while (answer == 'Y' || answer == 'y');
		printf(REPORTHEADINGS);
		fprintf(reportFile,REPORTHEADINGS); //step 3: fprintf to print to file instead of stdout
		fprintf(reportFile,DIVIDER);
		for (silly = 0; silly < employeecount; silly++) // iterate outputs through array
		{
				strcpy(result,emp[silly].lastname); //constructs the single string name
				strcat(strcat(result,", "),emp[silly].firstname);
				printf(format,result,emp[silly].payrate,emp[silly].hours,emp[silly].gross,emp[silly].tax,emp[silly].net); 
				//cats all the outputs to a formatted line
				fprintf(reportFile,format,result,emp[silly].payrate,emp[silly].hours,emp[silly].gross,emp[silly].tax,emp[silly].net);//step 3: fprintf to print to file instead of stdout
				//captures each employee's values to a total
                hourstotal += emp[silly].hours;
                payratetotal += emp[silly].payrate;
                grosstotal += emp[silly].gross;
                taxtotal += emp[silly].tax;
                finaltotal += emp[silly].net;
		}
		//calculation block for averages
		payrateavg /= employeecount;
		hoursavg /= employeecount;
		grossavg /= employeecount;
		taxavg /= employeecount;
		finalavg /= employeecount;
		
		printf("\n");
        printf(format,"Totals",payratetotal,hourstotal,grosstotal,taxtotal,finaltotal);
        printf(format,"Averages",payrateavg,hoursavg,grossavg,taxavg,finalavg);
        fprintf(reportFile,"\n");
		fprintf(reportFile,format,"Totals",payratetotal,hourstotal,grosstotal,taxtotal,finaltotal);
		fprintf(reportFile,format,"Averages",payrateavg,hoursavg,grossavg,taxavg,finalavg);
		fflush(stdin); // allows viewing output
	    getchar();
	    fclose(reportFile);//step 4: ALWAYS close files
		return 0;
}

