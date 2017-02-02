/******************************************************************************
  ENGR 200-02                                                DATE: 9/3/2015

  ASSIGNMENT #1                       Author: Christian Hansen             
*******************************************************************************

  PROGRAM DESCRIPTION:
  This program will calculate the wind chill in degrees Fahrenheit, the time it
  takes to get frostbite in minutes, and will print the results after the user 
  inputs air temperature and wind speed.

  DESCRIPTION OF VARIABLES:
  NAME       | TYPE |  DESCRIPTION                                
  -----------------------------------------------------------------------------
  temp       | Double | Captures air temperature in F from user input
  speed      | Double | Captures wind speed in mph from user input
  chill      | Double | Calculates wind chill from user inputs
  time       | Double | Calculates time it takes in minutes to get frosbite
   
******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>

/* Main function */
int main(void)
{
   /* Declare variables */
   double temp,speed,chill,time;
   
   /* Print main heading */
   printf("*********************************");
   printf("\n  WIND CHILL AND FROSTBITE TIME\n\n\n\n");

   /* Enter air temperature and wind speed */
   printf("Enter the air temperature in degrees Fahrenheit: ");
   scanf("%lf",&temp);
   printf("Enter the wind speed in miles per hour         : ");
   scanf("%lf",&speed);
   
   /* Calculate wind chill and frostbite time */
   chill = 35.74+0.6215*temp-pow(speed,0.16)*35.75+0.4275*temp*pow(speed,0.16);
   time = (-24.5*(0.667*speed*8.0/5.0+4.8)+2111.0);
   time = time*pow(-4.8-(temp-32.0)*(5.0/9.0),-1.668);
   printf("*********************************");
   
   /* Print output values */
   printf("\n\n\nRESULTS\n");
   printf("\n\nYou entered:\n");
   printf("Air temperature =   %3.1f degrees Fahrenheit",temp);
   printf("\nWind speed      =  %4.1f miles per hour",speed);
   printf("\n\nCalculations:");
   printf("\nWindchill       = %4.1f degrees Fahrenheit",chill);
   printf("\nFrostbite time  =  %4.1f minutes",time);
   
   /* Exit program */
   printf("\n\n\nPress Enter to quit.\n");
   getchar();
   getchar();
   return 0;
}   
/*****************************************************************************/
