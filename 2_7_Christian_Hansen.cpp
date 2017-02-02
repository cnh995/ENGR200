/******************************************************************************
  ENGR 200-02                                                DATE: 11/5/2015

  ASSIGNMENT #7                       Author: Christian Hansen             
*******************************************************************************

  PROGRAM DESCRIPTION:
  This program will read data from an input file, find the date that a tsunami
  was recorded, maximum wave height in feet, and number of fatalities then
  print results to the screen and to an output file.

  DESCRIPTION OF VARIABLES:
  NAME      | TYPE     |  DESCRIPTION                                
  -----------------------------------------------------------------------------
  month     |   char   | Month read from input file
  location  |   char   | Location from input file 
  wheight   |  double  | Wave height from input file
  avgheight |  double  | Average wave height
  totheight |  double  | Total wave height
  minheight |  double  | Minimum wave height
  maxheight |  double  | Maximum wave height
  date      |   int    | Date from input file
  year      |   int    | Year from input file
  deaths    |   int    | Number of deaths from input file
  i         |   int    | Loop control variable
  ndata     |   int    | Number of data points in the input file
  tdata     |  struct  | Array of tsunami data
******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\tsunamis.txt"
#define outputfile "u:\\engr 200\\tsunami_analysis.txt"

/* Structure to represent tsunamis */
struct storms
{
   char month[10],location[17];
   double wheight;
   int date,year,deaths;
};

/* Main function */
int main(void)
{
   /* Declare and initialize variables */
   int i,ndata;
   double avgheight,minheight,maxheight,totheight=0;
   struct storms tdata[10];
   FILE *tsunamis, *analysis;
   
   /* Open files */
   tsunamis = fopen(inputfile,"r");
   analysis = fopen(outputfile,"w");
   
   /* Verify input file and read control number */
   if (tsunamis == NULL)
   {
      printf("\n\n\nError opening input file.");
      printf("\n\n\nPress Enter to quit.");
      getchar(); getchar();
      return 0;
   }
   else
   {   
     /* Read control numbers and table name */
     fscanf(tsunamis,"%i",&ndata);

     /* Print main heading */
     printf("                         TSUNAMI ANALYSIS\n\n\n\n"
            "Month       Day   Year   Location       Wave Height   Fatalities\n"
            "----------------------------------------------------------------"
            "\n");
     fprintf(analysis,"                         TSUNAMI ANALYSIS\n\n\n\n"
            "Month       Day   Year   Location       Wave Height   Fatalities\n"
            "----------------------------------------------------------------"
            "\n");
     
     /* Read values from the input file, store in array */
     for(i=0;i <= ndata-1;i++)
        fscanf(tsunamis,"%s %i %i %s %lf %i",&tdata[i].month,&tdata[i].date
               ,&tdata[i].year,&tdata[i].location,&tdata[i].wheight
               ,&tdata[i].deaths);
     
     /* Find total and average wave height */
     for(i=1;i <= ndata-1;i++)
        totheight = totheight+tdata[i].wheight;
        
     avgheight = totheight/ndata;
     
     /* Find minimum and maximum heights */
     minheight = tdata[i].wheight;
     maxheight = tdata[i].wheight;
       
     for(i=0;i <= ndata-1;i++)
        {
           if(tdata[i].wheight > maxheight)
               maxheight = tdata[i].wheight;
           if(tdata[i].wheight < minheight)
               minheight = tdata[i].wheight;
         }        
   }
     
     /* Printing the data from the input file */
     for(i=0;i<=ndata-1;i++)
     {
        printf("%-10s   %2i   %4i   %-17s %5.1f         %4i\n",tdata[i].month
              ,tdata[i].date,tdata[i].year,tdata[i].location,tdata[i].wheight
              ,tdata[i].deaths);  
        fprintf(analysis,"%-10s   %2i   %4i   %-17s %5.1f         %4i\n"
              ,tdata[i].month,tdata[i].date,tdata[i].year,tdata[i].location
              ,tdata[i].wheight,tdata[i].deaths);
     }

     /* Find which locations had waves with above average height */
     

     /* Printing summary report */
     printf("\n\nSummary Report:\n"
            "Maximum wave height in feet: %4.1f\n"
            "Minimum wave height in feet:  %3.1f\n"
            "Average wave height in feet: %4.1f\n"
            "\n\n\nTsunamis with greater than average wave height:"
            "\n"
            ,maxheight,minheight,avgheight);
     fprintf(analysis,"\n\nSummary Report:\n"
            "Maximum wave height in feet: %4.1f\n"
            "Minimum wave height in feet:  %3.1f\n"
            "Average wave height in feet: %4.1f\n"
            "\n\n\nTsunamis with greater than average wave height:"
            "\n"
            ,maxheight,minheight,avgheight);
            
      for(i=0;i<=ndata-1;i++)
         if(tdata[i].wheight>avgheight)
           {
              printf("%-17s\n",tdata[i].location);
              fprintf(analysis,"%-17s\n",tdata[i].location);
           }
            
   /* Close the files */
   fclose(tsunamis);
   fclose(analysis);
   
   /* Exit program */
   printf("\n\n\nPress Enter to quit.\n");
   getchar();
   getchar();
   return 0;
}   
/******************************************************************************/
