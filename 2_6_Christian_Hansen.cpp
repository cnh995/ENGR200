/******************************************************************************
  ENGR 200-02                                                DATE: 10/27/2015

  ASSIGNMENT #6                       Author: Christian Hansen             
*******************************************************************************

  PROGRAM DESCRIPTION:
  This program will read data from an input file, find the average elevation in
  the land grid, number of peak elevations, minimum elevation and grid location,
  maximum elevation and grid location, then print results to the screen and to
  an output file.

  DESCRIPTION OF VARIABLES:
  NAME     | TYPE     |  DESCRIPTION                                
  -----------------------------------------------------------------------------
  average  |  Double  | Average elevation in the grid
  maxelev  |  Double  | Maximum elevation in the grid 
  minelev  |  Double  | Minimum elevation in the grid
  grid     |  Double  | Two-dimensional array to store the grid
  total    |  Double  | Adds every point in the grid
  name     |   Char   | One-dimensional array for table name
  xmax     | Integer  | Stores x-coordinate for max value in grid
  ymax     | Integer  | Stores y-coordinate for max value in grid
  xmin     | Integer  | Stores x-coordinate for min value in grid
  ymin     | Integer  | Stores y-coordinate for min value in grid
  i        | Integer  | Loop control variable
  j        | Integer  | Loop control variable
  npeaks   | Integer  | Number of peaks in the grid
  nrow     | Integer  | Number of data values in input file
  ncolumn  | Integer  | Number of data values in input file
******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\terrain.txt"
#define outputfile "u:\\engr 200\\grid_report.txt"

/* Main function */
int main(void)
{
   /* Declare and initialize variables */
   int nrow,ncolumn,npeaks=0,i,j,xmax,ymax,xmin,ymin;
   char name[25];
   double average,maxelev,minelev,total,grid[10][10];
   FILE *terrain, *report;
   
   /* Open files */
   terrain = fopen(inputfile,"r");
   report = fopen(outputfile,"w");
   
   /* Verify input file and read control number */
   if (terrain == NULL)
   {
      printf("\n\n\nError opening input file.");
      printf("\n\n\nPress Enter to quit.");
      getchar(); getchar();
      return 0;
   }
   else
   {   
     /* Read control numbers and table name */
     fscanf(terrain,"%s",&name);
     fscanf(terrain,"%i,%i",&nrow,&ncolumn);

     /* Print main heading */
     printf("                         %25s\n\n"
            "                            (Elevations in feet)\n\n\n"
            "     0       1       2       3       4       5       6"
            "       7       8       9\n",name);
     fprintf(report,"                         %25s\n\n"
            "                            (Elevations in feet)\n\n\n"
            "     0       1       2       3      4        5       6"
            "       7       8       9\n",name);
     
     /* Read values from the input file, print table using user defined func */
     for(i=0;i <= nrow-1;i++)
     {
        printf("\n%1i  ",i);
        fprintf(report,"\n%1i  ",i);
        for(j=0;j <= ncolumn-1;j++)
        {
           fscanf(terrain,"%lf",&grid[i][j]);
           printf("%5.1f   ",grid[i][j]);
           fprintf(report,"%5.1f   ",grid[i][j]);
           total = total + grid[i][j];
        }
     }
     /* Find total number of peaks */
     for(i=1;i <= nrow-2;i++)
        for(j=1;j <= ncolumn-2;j++)
        {
           if(grid[i][j] > grid[i-1][j] && grid[i][j] > grid[i+1][j] &&
              grid[i][j] > grid[i][j-1] && grid[i][j] > grid[i][j+1])
              npeaks++;
        }
     
     /* Find minimum and maximum values and coordinates */
     minelev = grid[i][j];
     maxelev = grid[i][j];  
     for(i=0;i <= nrow-1;i++)
        for(j=0;j <= ncolumn-1;j++)
         {
            if(grid[i][j] > maxelev)
            {
               maxelev = grid[i][j];
               xmax = i;
               ymax = j;
            }
            if(grid[i][j] < minelev)
            {
               minelev = grid[i][j];
               xmin = i;
               ymin = j;
            }
         }        
   }
     
     /* Calculating average and printing the composite report */
     average = total/(nrow*ncolumn);
     printf("\n\n\nCOMPOSITE REPORT\n"
            "Average elevation is %5.1f feet\n"
            "Number of peaks in this grid = %i\n"
            "Minimum elevation is %5.1f feet at grid %i,%i\n"
            "Maximum elevation is %5.1f feet at grid %i,%i\n",
            average,npeaks,minelev,xmin,ymin,maxelev,xmax,ymax);
     fprintf(report,"\n\n\nCOMPOSITE REPORT\n"
            "Average elevation is %5.1f feet\n"
            "Number of peaks in this grid = %i\n"
            "Minimum elevation is %5.1f feet at grid %i,%i\n"
            "Maximum elevation is %5.1f feet at grid %i,%i\n",
            average,npeaks,minelev,xmin,ymin,maxelev,xmax,ymax);
            
   /* Close the files */
   fclose(terrain);
   fclose(report);
   
   /* Exit program */
   printf("\n\n\nPress Enter to quit.\n");
   getchar();
   getchar();
   return 0;
}   
/******************************************************************************/
