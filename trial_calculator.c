//*******CALCULATOR FOR FINDING LENGTH AND WIDTH OF PATCH ANTENNA**********//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//functions decleration
 //double conversion(double);
 void convert(double);
 void main(void)
{
     //Variables
     double c=3*pow(10,11);
  double Er,h,w,Ereff,fo1,fo,L;
  /* c  -   speed of light(constant) 
     Er -   Dielectric constant
     h  -   Hight of substrate
     w  -   Width of patch
     Ereff- Effective dielectric constant
     Fo-    Operating frequency
     Fo1 -  fo is converted into MHz
     L  -   lwngth of patch antenna          */

  printf("Enter operating frequency (fo) of antenna in GHz=\n");
  scanf("%lf",&fo);
  printf("Enter dielectrin constant value=\n");
  scanf("%lf",&Er);
  printf("Enter thickness (h) of substratr in mili meter=\n");
  scanf("%lf",&h);
  
  fo1=(double )fo*pow(10,9); //convert given frequency value into giga Heartz

// fo1=conversion(fo1);

  printf("entered value=\n%.2lf,\n%.2lf,\n%.2lf \n",fo1,Er,h);/*Reprint the given values by user.
  The .2f shows or ensure that only two values after decimal number is shown.*/

// Step-1  find wavelength for patch antenna.
  double lambda = c/fo1;
  printf("Wavelength of patch antenne=%.4lfmm\n",lambda);
 
//printf("Wavelength of given frequency=%lf \n",lambda);

// Step-2 find width(w) of patch antenna.
   w=(c/(2*fo1))*(sqrt(2/(Er+1)));
  //convert(w);
   printf("Width if patch for given fo=%.4lfmm\n",w);

// Step-3 Effrctine dielectric constant (Ereff).
   Ereff=((Er+1)/2)+((Er-1)/2)*(pow(1+(12*(h/w)),(1/2)));
   printf("Effective dielectric constant=%.4lf\n",Ereff);

//Step-4 Finding d(L) 
   double dL=(0.412*((Ereff+0.3)/(Ereff-0.258))*((w/h)+0.264))/((Ereff-0.285)*((w/h)+0.8));

   printf("Calculated value of dL=%.4lfmm",dL);

//Step-5 Finding length of patch
   L=(c/(2*fo1*sqrt(Ereff))-(2*dL));
   printf("\nLength of patch antenna=%.4lfmm\n",L);
   
   system("pause");

}


//convert width of antenna(w) value into scientific value in power of 10
/*void convert(double w)
{
     short exponent=0;
  while(w>=100 )
  {
    w/=10;
    exponent++;
   
  }
  printf("Width if patch for given fo=%.2lf*10^(%d)\n",w,exponent);
}

double conversion(double fo1)
{
    short exponent,a;
    while(fo1>=10)
    {
    fo1/=10;
 a=exponent++;
     } 
     double value=fo1*pow(10,exponent);
     return (value);

}*/
 
