/******************************************************************************
  ENGR 200-02                                                DATE: 9/10/2015

  ASSIGNMENT #2                       Author: Christian Hansen             
*******************************************************************************

  PROGRAM DESCRIPTION:
  This program will calculate the approximate time for electrons to travel from
  the cathode to the anode in a vacuum tube.

  DESCRIPTION OF VARIABLES:
  NAME       | TYPE     |  DESCRIPTION                                
  -----------------------------------------------------------------------------
  charge     | Symbolic | Gives the charge of an electron in coulombs
  mass       | Symbolic | Gives the mass of an electron in kilograms
  accel      |  Double  | Captures accelerating voltage from user input 
  rad1       |  Double  | Captures radius of cathode in inches from user input
  rad2       |  Double  | Captures radius of anode in inches from user input
  nlog       |  Double  | Calculates the natural log of rad2/rad1
  time       |  Double  | Calculates the electron's travel time
******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define charge 1.60206E-19
#define mass 9.1083E-31

/* Main function */
int main(void)
{
   /* Declare variables */
   double accel,rad1,rad2,nlog,time;
   
   /* Print main heading */
   printf("*******************************************");
   printf("\n           ELECTRON TRAVEL TIME\n\n");

   /* Enter air temperature and wind speed */
   printf("Enter the accelerating voltage: ");
   scanf("%lf",&accel);
   printf("Enter the cathode radius      : ");
   scanf("%lf",&rad1);
   printf("Enter the anode radius        : ");
   scanf("%lf",&rad2);
      
   /* Calculate natural log of rad2/rad1 and electron travel time */
   nlog = log(rad2/rad1);
   time = sqrt((2.0*mass)/(charge*accel))*rad1;
   time = time*nlog;
   time = time*(1.0+nlog/3.0+pow(nlog,2)/10.0+pow(nlog,3)
                /42.0+pow(nlog,4)/216.0); 
   
   /* Print output values */
   printf("\n\nRESULTS:\n");
   printf("Accelerating voltage = %6.2f volts",accel);
   printf("\nCathode radius       = %6.2f inches",rad1);
   printf("\nAnode radius         = %6.2f inches",rad2);
   printf("\nElectron travel time = %12.5E seconds",time);
   printf("\n*******************************************");
   
   /* Exit program */
   printf("\n\n\nPress Enter to quit.\n");
   getchar();
   getchar();
   return 0;
}   
/*****************************************************************************/
