#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
int main ()
{   

  int nmol;
  int i,k;
  float x,y,z;
  char atom;
  FILE *output;
  FILE *input;
  FILE *fp;
  

       while (1)

        {

     while ((output=fopen("2.crd", "w"))==NULL)
       {
           {
            printf ("Can't open output file\n");
             exit(0);}

       }

          while ((input=fopen("2.xyz", "r"))==NULL)
       {
           {
            printf ("Can't open output file\n");
             exit(0);}

       }
           
          while ((fp=fopen("Molecule_Information", "r"))==NULL)
       {
           {
            printf ("Can't open molecule information\n");
             exit(0);}

       }


           fscanf(input,"%d\n",&nmol);
	   printf("atom numer is %d\n",nmol);
           
	   char t[60],tt[60];
	   char atype[nmol][60],residue[nmol][60];
           for (k = 0;k < nmol;k++)
	   {
		   fscanf(fp,"%s %s\n",&atype[k][60],&residue[k][60]);
		   strcpy(t ,&atype[k][60]);
		   strcpy(tt, &residue[k][60]);
		   //printf("%s %s\n",read_atype,read_residue);
		   
		   
	   }
	   int a_cation = 1;
	   int last = nmol - 1;
	   k = nmol - a_cation +2  ;
	   fscanf(input,"\n");
           i = 2 ;
	   fprintf(output,"* GENERATED BY YNAN\n");
	   fprintf(output,"* DATE\n");
	   fprintf(output,"* \n");
	   fprintf(output,"%10d  EXT\n",nmol);
	   int count=1;
	   int hi=1;
	   float weighting=0.00;
           while ( i < k )
		{
           		fscanf(input,"%s  %f %f %f \n",&atom, &x, &y, &z);
                        fprintf(output,"%10d%10d  %-10s%-8s%20.10f%20.10f%20.10f  %-10s1%27.10f\n",count,hi,&residue[i-2][60],&atype[i-2][60],x,y,z,&residue[i-2][60],weighting);
			i++;
			count++;
		}
           hi=2;
	   printf("i is %d\n",i);
	  
	  while (i < last+3)
	  {
           printf("i ma in the loop\n");
	  fscanf(input,"%s  %f %f %f \n",&atom, &x, &y, &z);
	   fprintf(output,"%10d%10d  %-10s%-8s%20.10f%20.10f%20.10f  %-10s1%27.10f\n",count,hi,&residue[i-2][60],&atype[i-2][60],x,y,z,&residue[i-2][60],weighting);
	   i++;
	  }

           
      fclose(output);
      fclose(input);
      fclose(fp);
      return 0;
       
        }  //while 1


} // main
