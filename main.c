#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include "TPAYS.h"
#include "TPERMIS.h"
#include "TETATCIVILE.h"
#include "TVILLES.h"
#include "TLANGUE.h"
#include "TCANDIDATS.h"
#include "TEXPERIENCES.h"
#include "TTYPECONTRAT.h"
#include "TCV.h"
#include "TCOMPETENCES.h"
#include "TPROJET.h"
#include "TBENEVOLAT.h"
#include <windows.h>

void Menu(){
int Choix;
char rep;
do
{
    system("cls");
    ShowWindow( GetConsoleWindow() , SW_MAXIMIZE);
    printf("\n\t                ******************************************                 ");
    printf("\n\t***************       MENU PRINCIPALE DE LA CVTHEQUE       *******************");
    printf("\n\t*************** CHADI MESLEK/ OUSSAMA SALHYA / DRISS JABRI ******************");
	printf("\n\t                *******************************************                 ");
    printf("\n\t                                              \n ");
    printf("\t*   (1)  Menu du Cv                             *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (2)  Menu du Candidats                      *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (3)  Menu du Competence                     *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (4)  Menu du Permis                         *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (5)  Menu du Pays                           *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (6)  Menu du Langue                         *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (7)  Menu du L'Etat Civile                  *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (8)  Menu du Type de contrat                *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (9)  Menu du Ville                          *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (10)  Menu d'Experience                     *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (11)  Menu de formation                     *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (12)  Menu de benevolat                     *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (13)  Menu de projet  	                *\n");
    printf("\t*-----------------------------------------------*\n");
    printf("\t*   (14)  Quitter                               *\n");
    printf("\t*-----------------------------------------------*\n");

    do
    {
     printf("\n\t>>> Etrez votre choix...");
     scanf("%d",&Choix);
     fflush(stdin);
    }while(Choix<1||Choix>14);
    switch(Choix){
    case 1:MenuCV();
        break;
    case 2:MenuCandidat();
        break;
    case 3:MenuComp();
        break;
    case 4:MenuPermis();
        break;
    case 5:MenuPays();
        break;
	case 6:MenuLng();
        break;
    case 7:MenuEtatC();
        break;
    case 8:MenuTypeContrat();
        break;
    case 9:MenuVille();
        break;
    case 10:MenuExperience();
    	break;
    case 11:MenuFormation();
        break;
    case 12:Menubenevolat();
        break;
    case 13:Menuprojet();
        break;
    case 14:return;
    }
    printf("\n\t>>> Voulez-vous revenir au Menu principale O/N?...");
    scanf("%s",&rep);
    fflush(stdin);
}while(rep=='o'||rep=='O');
printf("\n\n\t*********************************************");
printf("\n\t*                                           *");
printf("\n\t* FIN DE PROGRAMME! MERCI POUR VOTRE VISITE *");
printf("\n\t*                                           *");
printf("\n\t*********************************************\n\n\n");
}

int main()
	{
  		Menu();
	}


