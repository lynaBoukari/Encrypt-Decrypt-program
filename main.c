#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Fonction.h"



/***************************  ***** *** MAIN ***  *****  ****************************************/
  int main(void)
{

    FILE *f,*h,*g;
    int cle,j,fin;
    char fich1[30],fich2[30],fich3[30];

/*************************************** BIENVENUE *****************************************/
    Color(12, 0);
    printf("\n\n\n\n\n\n\n\n\n"
           "\t\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n"
           "\t\t\t ________________________________________________________________\n"
           "\t\t\t ----------------------------------------------------------------\n"
           "\t\t\t ________________________________________________________________\n\n"
           "\t\t\t    |****** BIENVENUE DANS LE PROGRAMME DE CRYPTAGE *******|\n\n"
           "\t\t\t ________________________________________________________________\n"
            "\t\t\t ----------------------------------------------------------------\n"
            "\n\t  TP02: SFSD \t Realise par : BOUKARI Lyna et LAOUICI Safa \t Groupe 02\t 2019\2020 \t\n"
            "\t\t\t ________________________________________________________________\n"
            "\t\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n\n");

     system("PAUSE");
/****************************************//********* ouverture des fichiers*************//*****************************/
     system("cls");
     Color(7,0);
    printf( "\t\t\t ________________________________________________________________\n");
    printf("\n\t Veuillez entrer les noms de vos fichiers (xxx.txt) dans l'ordre suivant :          \n \n");

    printf("\t\t\t Entrer le nom du fichier original\n ");
    scanf(" %s",&fich1);
    printf("\t\t\t Entrer le nom du fichier crypte\n ");
    scanf("  %s",&fich2);
    printf("\t\t\t Entrer le nom du fichier decrypte\n ");
    scanf(" %s",&fich3);

    //***********************************//
    /*********** LA CLE DE CRYPTAGE *************/

    printf(" Veuillez entrer la cle de cryptage qui un chiffre entre 0 et 20 \n");
    scanf("%d",&cle);

    //************************************************/

    f=fopen(fich1,"r");
    g=fopen(fich2,"a+");
    h=fopen(fich3,"w");


    if ((f==NULL)||(g==NULL)||(h==NULL))
    {
        printf(" le fichier n'existe pas ! \n");
    }


    else{
       system("cls");
     while (fin!=1){

      switch(menu())
      {
     case 1:           // cas de fonctionnement
           system("cls");
          printf("\t\t  <><><><><><><>\n"
                 "\t\t Le fonctionnement :   \n\n");
         printf(" \t\t\t\t L'idee du programme :\n"
                    " \t\t ce programme consiste a crypter le fichier de facon a ce que on inverse les caracteres \n "
                    "\t\t du fichier de la fin vers le debut en rajoutant la cle a chaque caractere.\n\n ");

       break ;

     case 2:              // cas de cryptage
            system("cls");
            printf("\t\t <><><><><><><>\n"
                   "\t\t Le cryptage : \n\n");
            cryptage(f,g,cle);
            printf(" le fichier %s a bien etait crypte dans %s \n\n",fich1,fich2);


            break;

         case 3:            // cas de decryptage
            system("cls");
            printf("\t\t<><><><><><><>\n"
                   " \t\t Le decryptage : \n\n");

            decryptage(f,g,h,cle);
            printf(" le fichier %s a bien etait decrypte dans %s\n\n",fich2,fich3);

            break;

         case 4:           // cas de comparaison
          system("cls");
          printf("\t\t  <><><><><><><>\n"
                 "\t\t   La comparaison :\n\n");
          h=fopen(fich3,"r");
          j=comparaison(f,h);

            if (j==0){ printf(" Les fichiers  %s  et  %s  sont identiques.\n\n ",fich1,fich3);}
            else {printf(" Les deux fichier sont different !\n\n");}

            break;


             case 5:

                    fin=1;

                break;

              default:
                system("cls");
              printf("     \t\t<><><><><><><>\n"
                     "\t\t Vous n'avez pas choisi le bon numero\n");
                menu();

              break;

      }
      }
    }

   return 0;
}



