#include<stdio.h>
int main()
{
   char c;
   int d,bit;
   float P,R,D,UCS,E,S20,Sj,DRI,Eg,ng,Lf,Ip,Dbit,Ep,K,Nr,Rf;

   printf("Mechanical Drilling types commonly used in mines:\n");
   printf("a - Rotary Percussive Drilling\n");
   printf("b - Rotary Drilling\n\n");
   printf("Type for which you want to find the ROP (Enter the adjacent alphabet) - \n");
   printf("Your choice? ");
   scanf("%c",&c);

   if (c=='a'){
    printf("\nDifferent methods for Rotary Percussive drilling:\n");
    printf("1 - USBM, 1969\n");
    printf("2 - Norway, 1979\n");
    printf("3 - Benaola, 1985\n\n");
    printf("Your selected method for estimating ROP (Enter the corresponding number. For example, 2 for Norway, 1979): ");
    scanf("%d",&d);

      if(d==1){
        printf("\nUSBM, 1969 -\n\n");
        printf("Drill power in Kg*m/min: ");
        scanf("%f",&P);
        printf("Blast hole diameter in cm: ");
        scanf("%f",&D);
        printf("Uni-axial compressive strength of rock (MPa): ");
        scanf("%f",&UCS);
        printf("Energy transmission output (0.6-0.8): ");
        scanf("%f",&R);
        if(R>=0.6&&R<=0.8){
           if(UCS>=10&&UCS<=220){
           printf("\nRate of Penetration for the given condition is %f cm/min.",
                  15.2789*(R*P)/(D*D*(0.0102998*UCS+1.53737)*8.437));
           }
           else if(UCS>220){
            printf("\nRate of Penetration for the given condition is %f cm/min.",
                   15.2789*(R*P)/(D*D*(0.0141173*UCS+2.122166)*8.437));
           }
           else{
            printf("\nWarning: Enter the legal value of UCS!");
           }
           }
        else{
            printf("\nWarning: Enter the energy transmission output in valid range!");
            }
      }
      else if(d==2){
        printf("\nNorway, 1979 -\n\n");
        printf("Brittleness index (S20 value) of the rock: ");
        scanf("%f",&S20);
        printf("Siever's J value (Sj): ");
        scanf("%f",&Sj);
        DRI=(1.036251*S20)+(0.142619*Sj)+1.14546;
        printf("\nDrilling rate index of the rock is close to %f", DRI);
        if(DRI<=30){
            printf(" and it has a low drillability.");
        }
        else if(DRI>30&&DRI<60){
            printf(" and it has a medium drillability.");
        }
        else{
            printf(" and it has a high drillability.");
        }
      }
      else if (d==3){
        printf("\nBenaola, 1985 -\n\n");
        printf("Brittleness index (S20 value) of the rock: ");
        scanf("%f",&S20);
        printf("Siever's J value (Sj): ");
        scanf("%f", &Sj);
        DRI=(1.036251*S20)+(0.142619*Sj)+1.14546;
        printf("Energy per blow (lbs.ft): ");
        scanf("%f",&Eg);
        printf("Number of blows per minute: ");
        scanf("%f",&ng);
        printf("Bit diameter (cm): ");
        scanf("%f",&Dbit);
        printf("Type of bit used for the purpose (1.Insert/2.Button/3.Bevel)? | Enter the corresponding number: ");
        scanf("%d",&bit);
        if(bit==1){
                Lf=1.7*Dbit-0.7;
            printf("\nFor the system using Insert bit, following results are obtained -\n\n");
            printf("Length of the cutting edge of the drill tool is %f cm.\n", Lf);
            printf("Drilling rate of the system is %f cm/min.", (Eg*ng)*(51*DRI+90)*pow(10,-6)/(Dbit*pow(Lf,0.5)));
        }
        else if (bit==2){
            printf("\nFor the system using Button bit, following results are obtained -\n\n");
            printf("Drilling rate of the system is %f cm/min.",pow((Eg*ng)*(51*DRI+90)*pow(10,-6)/(pow(1.15,0.5)*Dbit),0.6667));
        }
        else if (bit==3){
            printf("\nFor the system using Bevel bit, following results are obtained -\n\n");
            printf("Drilling rate of the system is %f cm/min.",pow((Eg*ng)*(51*DRI+90)*pow(10,-6)/(pow(0.85,0.5)*Dbit),0.6667));
        }
        else{
            printf("Check your input number!");
        }
      }
      else{printf("Check your input!");  }

   }
   else if(c=='b'){
    printf("\nDifferent methods for Rotary drilling:\n");
    printf("1 - Bauer and Calder, 1967\n");
    printf("2 - Bauer, 1971\n");
    printf("3 - Calder and Workman, 1994\n\n");
    printf("Your selected method for estimating ROP (Enter the corresponding number. For example, 2 for Bauer, 1971): ");
    scanf("%d",&d);
        if (d==1){
        printf("\nBauer and Calder, 1967 -\n\n");
        printf("Pull down force (pounds): ");
        scanf("%f",&Ep);
        printf("Bit diameter (inches): ");
        scanf("%f",&D);
        printf("Uni-axial compressive strength of the rock (MPa): ");
        scanf("%f",&UCS);
        printf("Enter the K -factor: ");
        scanf("%f",&K);
        printf("Penetration rate for this condition is %f ft/hr.",
               6*pow(10,K*log(12*(Ep/D)/(UCS*145.038))/log(10)));
    }
        else if (d==2){
        printf("\nBauer, 1971 -\n\n");
        printf("Pull down force (lbs): ");
        scanf("%f",&Ep);
        printf("Bit diameter (inches): ");
        scanf("%f",&D);
        printf("Uni-axial compressive strength of the rock (MPa): ");
        scanf("%f",&UCS);
        printf("Rotary speed of drill (rpm): ");
        scanf("%f",&Nr);
        printf("Penetration rate for this condition is %f ft/hr.",
               (61-28*(log(UCS*145.038/1000)/log(10)))*Ep*Nr/(D*1000*300));
    }
        else if (d==3){
        printf("\nCalder and Workman, 1994 -\n\n");
        printf("Pull down force (Kg): ");
        scanf("%f",&Ep);
        printf("Bit diameter (mm): ");
        scanf("%f",&D);
        printf("Uni-axial compressive strength of the rock (MPa): ");
        scanf("%f",&UCS);
        printf("Rotary speed of drill (rpm): ");
        scanf("%f",&Nr);
        Rf=7714.95-7312.3*pow(UCS,0.0086436);
        printf("Penetration rate for this condition is %f m/hr.",
               5.7*pow(10,-5)*(Rf-28*log(0.145*UCS)/log(10))*Ep*Nr/D );

    }
    else{printf("Check your input!");   }
   }
   else{
    printf("Input Error!");
   }
    return 0;
}
