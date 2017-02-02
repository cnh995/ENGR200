/******************************************************************************
  ENGR 200-02                                                DATE: 9/29/2015

  ASSIGNMENT #3                       Author: Christian Hansen             
*******************************************************************************

  PROGRAM DESCRIPTION:
  This program will read data from an input file, compute the hole to depth
  ratio, the ideal number of sticks or dynamite, the ideal powder charge,
  the actual number of sticks, and the actual powder charge, then it will print
  the results to the screen and to an output file.

  DESCRIPTION OF VARIABLES:
  NAME       | TYPE     |  DESCRIPTION                                
  -----------------------------------------------------------------------------
  siteid    | Integer  | Reads site ID number from input file
  holedepth | Integer  | Reads hole depth in feet from input file
  iphratio  |  Double  | Calculates ideal ratio of powder to hole depth 
  isticks   |  Double  | Calculates ideal number of dynamite sticks
  ipowder   |  Double  | Calculates ideal powder charge
  asticks   | Integer  | Calculates actual number of sticks
  apowder   | Integer  | Calculates actual powder charge
  ndata     | Integer  | Number of data values in input file
  i         | Integer  | Loop control variable
******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\explore.txt"
#define outputfile "u:\\engr 200\\results.txt"

/* Main function */
int main(void)
{
   /* Declare and initialize variables */
   double iphratio,isticks,ipowder;
   int  holedepth,siteid,ndata,i,asticks,apowder;
   FILE *explore, *results;
   
   /* Open files */
   explore = fopen(inputfile,"r");
   results = fopen(outputfile,"w");
   
   /* Print main heading */
   printf("         DAILY DRILLING REPORT\n\n");   
   printf("SITE ID  DEPTH   IDEAL POWDER   ACTUAL POWDER   STICKS\n");
   printf("         (ft)    CHARGE (lbs)   CHARGE (lbs)\n\n");
   fprintf(results,"\n         DAILY DRILLING REPORT\n\n");
   fprintf(results,"SITE ID  DEPTH   IDEAL POWDER   ACTUAL POWDER  "
                   " STICKS\n");
   fprintf(results,"         (ft)    CHARGE (lbs)   CHARGE (lbs)\n\n");
   
   /* Verify input file and read control number */
   if (explore == NULL)
   {
      printf("\n\n\nError opening input file.");
      printf("\n\n\nPress Enter to quit.");
      getchar(); getchar();
      return 0;
   }
   else
   {   
     /* Read control number */
     fscanf(explore,"%i",&ndata);
     
     /* Read values from the input file, compute hole to depth ratio, ideal
     number of sticks, ideal powder charge, actual powder charge, and actual
     number of sticks */
     for(i=1;i <= ndata;i++)
     {
        fscanf(explore,"%i,%i",&siteid,&holedepth);
        iphratio = holedepth/3.0;
        isticks = iphratio/2.5;
        ipowder = isticks*5.0;
        apowder = int(ipowder);
        asticks = int(isticks);
           
        if(holedepth < 30)
        {
           printf("%-4i     %-3i   *** HOLE TOO SHALLOW FOR BLASTING ***   \n",
                  siteid,holedepth);        
           fprintf(results,"%-4i     %-3i   "
                           "*** HOLE TOO SHALLOW FOR BLASTING ***   \n",
                           siteid,holedepth);
        }
        else
        {           
           printf("%-4i     %-3i     %-6.2lf         %-3i             %-3i\n",
                  siteid,holedepth,ipowder,apowder,asticks);        
           fprintf(results,"%-4i     %-3i     %-6.2lf         %-3i      "
                     "       %-3i\n",
                    siteid,holedepth,ipowder,apowder,asticks);
        }
     }
   }
     
   /* Close the files */
   fclose(explore);
   fclose(results);
   
   /* Exit program */
   printf("\n\n\nPress Enter to quit.\n");
   getchar();
   getchar();
   return 0;
}   
/*****************************************************************************/
