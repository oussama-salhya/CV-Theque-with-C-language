#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define BIG_MAX 100
#define MAX 25
#include "TPAYS.h"
#include "TPERMIS.h"
#include "TETATCIVILE.h"
#include "TVILLES.h"
#include "TLANGUE.h"
#include "TCANDIDATS.h"
#include "TFORMATIONS.h"
#include "TTYPECONTRAT.h"
#include "TCV.h"
#include "TCOMPETENCES.h"
#include "TEXPERIENCES.h"

char * saisirChaine();
void MenuExperience();

struct TEXPERIENCES
{
  int IdExperience;
  char TitreExperience[50];
  char Organisation[50];
  char DateDebutExperience[15];
  char DateFinExperience[50];
  char MissionExperience[50];
  int IdCVE;
  int IdVilleE;
  int IdTypeContratExp;

};struct TEXPERIENCES E ;

void AjouterExperience()
{

	FILE *Fe;
	Fe=fopen("TEXPERIENCES.txt","a");
	test_file_opening(Fe);
  printf("\tSaisir le Titre de L'Experience ");
	scanf("%s",&E.TitreExperience);
  	getchar();
 	printf("\tSaisir l'Organisation de L'Experience ");
	scanf("%s",&E.Organisation);
  printf("\tSaisir la Date de Debut de L'Experience ");
  scanf("%s",&E.DateDebutExperience);
  printf("\tSaisir la Date de Fin de L'Experience ");
	scanf("%s",&E.DateFinExperience);
  printf("\tSaisir la Mission de L'Experience ");
	scanf("%s",&E.MissionExperience);
  printf("\tSaisir l'indice du Cv Parmis cette liste ");
 	E.IdCVE=SaisirCV();
 	printf("\tSaisir l'indice de la Ville Parmis cette liste ");
  E.IdVilleE=SaisirVille();
  printf("\tSaisir l'indice du Type de Contrat Parmis cette liste ");
  E.IdTypeContratExp=SaisirTypeContrat();

  fflush(stdin);
	E.IdExperience=getIdExperience("TEXPERIENCES.txt")+1;
	fflush(stdin);

	fprintf(Fe,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d  \n",E.IdExperience,E.TitreExperience,E.Organisation,E.DateDebutExperience,E.DateFinExperience,E.MissionExperience,E.IdCVE,E.IdVilleE,E.IdTypeContratExp);
	printf("\n\nL'Experience %d %s est ajoute au fichier TEXPERIENCES.txt avec success \n",E.IdExperience,E.TitreExperience);
	fclose(Fe);
}

void RechercheExperience()
{
	int NumR,j=0;
	printf("\n\tEntrez l'indice de L'Experience a rechercher :");
	scanf("%d",&NumR);
	FILE *Fe;
	Fe=fopen("TEXPERIENCES.txt","r");
	do
	{
	fscanf(Fe,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d  \n",&E.IdExperience,&E.TitreExperience,&E.Organisation,&E.DateDebutExperience,&E.DateFinExperience,&E.MissionExperience,&E.IdCVE,&E.IdVilleE,&E.IdTypeContratExp);
	if(NumR==E.IdExperience)
	{
	        printf("\n\t===============INFORMATION SUR L'EXPERIENCE : %d  ================\n\t ",E.IdExperience);
	        printf("\n\tLe Titre \t\t\t:%s",E.TitreExperience);
	        printf("\n\tL'Organisation \t\t\t:%s",E.Organisation);
	        printf("\n\tLa Date de Debut \t\t\t:%s",E.DateDebutExperience);
	        printf("\n\tLa Date de la Fin \t\t\t:%s",E.DateFinExperience);
	        printf("\n\tLa Mission \t\t\t:%s",E.MissionExperience);
	        AfficherCVComp(E.IdCVE);
	        AfficherVilleC(E.IdVilleE);
	        AfficherTCE(E.IdTypeContratExp);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fe));
	fclose(Fe);
	if(j==0){
	    printf("\n\tDesole! L'Experience n'existe pas\n");
	}
}

void SupprimerExperience()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez L'indice de L'Experience a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechExperience(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Fet,*Fe;
	        Fe=fopen("TEXPERIENCES.txt","r");
	        test_file_opening(Fe);
	        Fet=fopen("EXPERIENCES.txt","a");
	        test_file_opening(Fet);
	        do
	        {
          fscanf(Fe,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d  \n",&E.IdExperience,&E.TitreExperience,&E.Organisation,&E.DateDebutExperience,&E.DateFinExperience,&E.MissionExperience,&E.IdCVE,&E.IdVilleE,&E.IdTypeContratExp);
	         if(NumRech!=E.IdExperience)
	         {
             fprintf(Fet,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d  \n",E.IdExperience,E.TitreExperience,E.Organisation,E.DateDebutExperience,E.DateFinExperience,E.MissionExperience,E.IdCVE,E.IdVilleE,E.IdTypeContratExp);
	         }
	        }while(!feof(Fe));
	        fclose(Fet);
	        fclose(Fe);
	        remove("TEXPERIENCES.txt");
	        rename("EXPERIENCES.txt","TEXPERIENCES.txt");
	        printf("\n\tLa suppression Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tl'indice de L'Experience n'existe pas");
	}
}

void ModifierExperience(){

	FILE *Fe,*Fet;
	int num,i;
	char rep='n';
	printf("\n\tEntrez L'indice de L'Experience a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechExperience(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fe=fopen("TEXPERIENCES.txt","r");
	    test_file_opening(Fe);
	    Fet=fopen("EXPERIENCES.txt","a");
	    test_file_opening(Fet);

	 do
	{
    fscanf(Fe,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d  \n",&E.IdExperience,&E.TitreExperience,&E.Organisation,&E.DateDebutExperience,&E.DateFinExperience,&E.MissionExperience,&E.IdCVE,&E.IdVilleE,&E.IdTypeContratExp);
	   if(num==E.IdExperience)
	{
		E.IdExperience=num;
    printf("\tSaisir le Nouveau Titre de L'Experience ");
  	scanf("%s",&E.TitreExperience);
    	getchar();
   	printf("\tSaisir la nouvelle Organisation de L'Experience ");
  	scanf("%s",&E.Organisation);
    printf("\tSaisir la nouvelle Date de Debut de L'Experience ");
    scanf("%s",&E.DateDebutExperience);
    printf("\tSaisir la nouvelle Date de Fin de L'Experience ");
  	scanf("%s",&E.DateFinExperience);
    printf("\tSaisir la nouvelle Mission de L'Experience ");
  	scanf("%s",&E.MissionExperience);
    printf("\tSaisir le nouveau indice du Cv Parmis cette liste ");
   	E.IdCVE=SaisirCV();
   	printf("\tSaisir le nouveau indice de la Ville Parmis cette liste ");
    E.IdVilleE=SaisirVille();
    printf("\tSaisir le nouveau indice du Type de Contrat Parmis cette liste ");
    E.IdTypeContratExp=SaisirTypeContrat();
	}
  fprintf(Fet,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d  \n",E.IdExperience,E.TitreExperience,E.Organisation,E.DateDebutExperience,E.DateFinExperience,E.MissionExperience,E.IdCVE,E.IdVilleE,E.IdTypeContratExp);
	}while(!feof(Fe));
    fclose(Fet);
    fclose(Fe);
	remove("TEXPERIENCES.txt");
	rename("EXPERIENCES.txt","TEXPERIENCES.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annule\n");
	}
	}
	else
	{
	printf("\n\tL'indice de L'Experience N'existe pas\n");
	}
}

int RechercheExpParNom(char * TitreExperience)
{
	int  id;
    char TitreExperience_courant[MAX];
    char Organisation_courant[MAX];
    char DateDebutExperience[15];
    char DateFinExperience[15];
    char MissionExperience[50];
    int IdVille;
    int IdCV;
    int IdTypeContratExp;
    char  line[BIG_MAX];
    FILE * F=fopen("TEXPERIENCES.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
        fscanf(F,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d \n",&id,TitreExperience_courant,Organisation_courant,DateDebutExperience,DateFinExperience,MissionExperience,&IdCV,&IdVille,&IdTypeContratExp);
        if(!strcmp(TitreExperience_courant,TitreExperience))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechExperience(int Numrech)
{
	FILE *Fe;
	Fe=fopen("TEXPERIENCES.txt","r");
	test_file_opening(Fe);
	do
		{
    fscanf(Fe,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d  \n",&E.IdExperience,&E.TitreExperience,&E.Organisation,&E.DateDebutExperience,&E.DateFinExperience,&E.MissionExperience,&E.IdCVE,&E.IdVilleE,&E.IdTypeContratExp);
		fflush(stdin);
		if(E.IdExperience==Numrech)
			{
			fclose(Fe);
			return 1;
			}
		}while(!feof(Fe));
	fclose(Fe);
	return -1;
}

void AfficherExperiences()
{
	FILE *Fe;
	Fe=fopen("TEXPERIENCES.txt","r");
	do
	{
    fscanf(Fe,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d  \n",&E.IdExperience,&E.TitreExperience,&E.Organisation,&E.DateDebutExperience,&E.DateFinExperience,&E.MissionExperience,&E.IdCVE,&E.IdVilleE,&E.IdTypeContratExp);
    printf("\n\t===============INFORMATION SUR L'EXPERIENCE : %d  ================\n\t ",E.IdExperience);
    printf("\n\tLe Titre \t\t\t:%s",E.TitreExperience);
    printf("\n\tL'Organisation \t\t\t:%s",E.Organisation);
    printf("\n\tLa Date de Debut \t\t\t:%s",E.DateDebutExperience);
    printf("\n\tLa Date de la Fin \t\t\t:%s",E.DateFinExperience);
    printf("\n\tLa Mission \t\t\t:%s",E.MissionExperience);
    AfficherCVComp(E.IdCVE);
    AfficherVilleC(E.IdVilleE);
    AfficherTCE(E.IdTypeContratExp);
    printf("\n\t-----------------------------------------------------------------");
	}while(!feof(Fe));
	fclose(Fe);
}

int getIdExperience(char *File)
{
	  int id;
	  int j=(-1);
    char TitreExperience_courant[MAX];
    char Organisation_courant[MAX];
    char DateDebutExperience[15];
    char DateFinExperience[15];
    char MissionExperience[50];
    int IdVille;
    int IdCV;
    int IdTypeContratExp;
	char N[100];
    FILE *F;
    F=fopen("TEXPERIENCES.txt","r");
    test_file_opening(F);
    while(!feof(F))
	{
    fgets(N,100,F);
    j++;
	}
    if(j==0)
    {
    	fclose(F);
		return 0;
	}
	else
	{
		fclose(F);
		F=fopen(File,"r");
		test_file_opening(F);
		while(!feof(F))
		{
      fscanf(F,"%d ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d \n",&id,TitreExperience_courant,Organisation_courant,DateDebutExperience,DateFinExperience,MissionExperience,&IdCV,&IdVille,&IdTypeContratExp);
		}
	fclose(F);
	return id;
	}
}

int SaisirTypeContrat()
{
  int id;
  AfficherTC();
  printf("\n\tindice : ");
  do {
    scanf("%d",&id);
  } while (rechTC(id)!=1);
  return id;
}

void MenuExperience()
{
int Choix;char rep;
do
	{
	    system("cls");
	    printf("\n\t              ***********************                ");
	    printf("\n\t*************** MENU DES EXPERIENCES ********************");
	    printf("\n\t              ***********************                ");
	    printf("\n\t                                               \n ");
	    printf("\t*  (1) Ajouter une Experience                   *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (2) Rechercher une Experience                *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (3) Supprimer une Experience                 *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (4) Modifier une Experience                  *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (5) Afficher tous Les Experiences            *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (6) Quiter                                   *\n");
	    printf("\t*-----------------------------------------------*\n");

	    do
		    {
		     printf("\n\t>>> Etrez votre choix...");
		     scanf("%d",&Choix);
		    }while(Choix<1||Choix>6);
	    switch(Choix)
			{
		    case 1:AjouterExperience();
		        break;
		    case 2:RechercheExperience();
		        break;
		    case 3:SupprimerExperience();
		        break;
		    case 4:ModifierExperience();
		        break;
		    case 5:AfficherExperiences();
		        break;
		    case 6:break;
		    }
	    printf("\n\t>>> Voulez-vous continuez O/N?...");
	    scanf("%s",&rep);
	    fflush(stdin);
	}while(rep=='o'||rep=='O');
}
