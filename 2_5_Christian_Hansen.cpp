/******************************************************************************
  ENGR 200-02                                                DATE: 10/13/2015

  ASSIGNMENT #5                       Author: Christian Hansen             
*******************************************************************************

  PROGRAM DESCRIPTION:
  This program will read data from an input file, compute the altitude and
  velocity of a weather balloon.

  DESCRIPTION OF VARIABLES:
  NAME     | TYPE     |  DESCRIPTION                                
  -----------------------------------------------------------------------------
  radius   |  Double  | Reads radius from input file
  angle    |  Double  | Reads angle from input file in degrees
  anglerad |  Double  | Calculates angle in radians
  rad      |  Double  | One-dimensional array to store radius from input
  ang      |  Double  | One-dimensional array to store angle from input
  x        |  Double  | One-dimensional array to store calculated x value
  y        |  Double  | One-dimensional array to store calculated y value
  i        | Integer  | Loop control variable
  ndata    | Integer  | Number of data values in input file
  pi       | Symbolic | Constant
******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\polardata.txt"
#define outputfile "u:\\engr 200\\cartesiandata.txt"
#define pi 3.14159
/* Main function */
int main(void)
{
   /* Declare and initialize variables */
   int ndata,i;
   double radius,angle,anglerad;
   double rad[10] = {0.0};
   double ang[10] = {0.0};
   double x[10] = {0.0};
   double y[10] = {0.0};
   FILE *polar, *cartesian;
   
   /* Open files */
   polar = fopen(inputfile,"r");
   cartesian = fopen(outputfile,"w");
   
   /* Verify input file and read control number */
   if (polar == NULL)
   {
      printf("\n\n\nError opening input file.");
      printf("\n\n\nPress Enter to quit.");
      getchar(); getchar();
      return 0;
   }
   else
   {   
     /* Read control number */
     fscanf(polar,"%i",&ndata);
     
     /* Print main heading */
     printf("Conversion Table -- Polar to Cartesian\n\n");
     printf("       Polar                Cartesian\n"); 
     printf("Radius    Angle(deg)        X       Y\n");
     fprintf(cartesian,"Conversion Table -- Polar to Cartesian\n\n");
     fprintf(cartesian,"       Polar                Cartesian\n"); 
     fprintf(cartesian,"Radius    Angle(deg)        "                      
                              "X       Y\n");

     
     /* Read values from the input file, print table using user defined func */
     for(i=0;i <= ndata-1;i++)
     {
        fscanf(polar,"%lf %lf",&radius,&angle);
        rad[i] = radius;
        ang[i] = angle;
     }
     for(i=0;i <= ndata-1;i++)
     {
        anglerad = ang[i]*pi/180.0;
        x[i] = rad[i]*cos(anglerad);
        y[i] = rad[i]*sin(anglerad);
     }
     for(i=0;i <= ndata-1;i++)
     {
        printf("%7.3f   %8.3f       %5.1f   %5.1f\n",rad[i],ang[i],
                x[i],y[i]);
        fprintf(cartesian,"%7.3f   %8.3f       %5.1f   %5.1f\n",
                rad[i],ang[i],x[i],y[i]);
     }
   }
     
   /* Close the files */
   fclose(polar);
   fclose(cartesian);
   
   /* Exit program */
   printf("\n\n\nPress Enter to quit.\n");
   getchar();
   getchar();
   return 0;
}   
/******************************************************************************/
