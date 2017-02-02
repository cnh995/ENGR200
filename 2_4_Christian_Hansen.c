/******************************************************************************
  ENGR 200-02                                                DATE: 9/29/2015

  ASSIGNMENT #4                       Author: Christian Hansen             
*******************************************************************************

  PROGRAM DESCRIPTION:
  This program will read data from an input file, compute the altitude and
  velocity of a weather balloon.

  DESCRIPTION OF VARIABLES:
  NAME         | TYPE     |  DESCRIPTION                                
  -----------------------------------------------------------------------------
  time         | Integer  | Reads number of hours from input file
  ndata        | Integer  | Number of data values in input file
  i            | Integer  | Loop control variable
  computed_vel |  Double  | Computed velocity of the balloon
  computer_alt |  Double  | Computed altitude of the balloon
******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\launch.txt"
#define outputfile "u:\\engr 200\\balloon_results.txt"

/* Main function */
int main(void)
{
   /* Declare and initialize variables */
   double altitude(int time);
   double velocity(int time);
   int time,ndata,i;
   double computed_vel,computed_alt;
   FILE *launch, *results;
   
   /* Open files */
   launch = fopen(inputfile,"r");
   results = fopen(outputfile,"w");
   
   /* Verify input file and read control number */
   if (launch == NULL)
   {
      printf("\n\n\nError opening input file.");
      printf("\n\n\nPress Enter to quit.");
      getchar(); getchar();
      return 0;
   }
   else
   {   
     /* Read control number */
     fscanf(launch,"%i",&ndata);
     
     /* Print main heading */
     printf("-------------------------------------\n");
     printf("         WEATHER BALLOON PROGRAM\n"); 
     printf("-------------------------------------\n\n");
     printf(" TIME      ALTITUDE      VELOCITY\n");
     printf("(hours)    (meters)       (m/hr)\n");
     fprintf(results,"-------------------------------------\n");
     fprintf(results,"         WEATHER BALLOON PROGRAM\n"); 
     fprintf(results,"-------------------------------------\n\n");
     fprintf(results," TIME      ALTITUDE     VELOCITY\n");
     fprintf(results,"(hours)    (meters)      (m/hr)\n");
     
     /* Read values from the input file, print table using user defined func */
     for(i=0;i <= ndata;i++)
     {
        time = i;
        computed_alt = altitude(time);
        computed_vel = velocity(time);
        printf("  %2i         %5.0f        %5.0f\n",time,
                computed_alt,computed_vel);        
        fprintf(results,"  %2i         %5.0f        %5.0f\n",
                time,computed_alt,computed_vel);
     }
   }
     
   /* Close the files */
   fclose(launch);
   fclose(results);
   
   /* Exit program */
   printf("\n\n\nPress Enter to quit.\n");
   getchar();
   getchar();
   return 0;
}   
/**********************************************************************
   This function will calculate the altitude of a balloon after receiving
   time.
**********************************************************************/
double altitude(int time)
{
   /* Declare variables */
   double balloon_alt;
   
   /* Compute balloon mass */
   balloon_alt = -0.12*pow(time,4)+12.0*pow(time,3)-380.0*pow(time,2)
                 +4100.0*time+220.0;
   
   /* Return balloon mass */
   return balloon_alt;
}
/*********************************************************************/

/**********************************************************************
   This function will calculate the velocity of a balloon after receiving
   time.
**********************************************************************/
double velocity(int time)
{
   /* Declare variables */
   double balloon_vel;
   
   /* Compute balloon mass */
   balloon_vel = -0.48*pow(time,3)+36.0*pow(time,2)-760*time+4100.0;
   
   /* Return balloon mass */
   return balloon_vel;
}
/*********************************************************************/
