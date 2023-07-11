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
void MenuFormation();

struct TFORMATIONS
{
  int IdFormation;
  int IdCVF;
  int IdVilleF;
  char TypeDiplome[50];
  char Specialite[50];
  char DateDebutFormation[15];
  char DureeFormation[15];
  char EtablissementFormation[50];

};struct TFORMATIONS F ;

void AjouterFormation()
{

	FILE *Fe;
	Fe=fopen("TFORMATIONS.txt","a");
	test_file_opening(Fe);
  printf("\tSaisir l'indice du Cv Parmis cette liste ");
  F.IdCVF=SaisirCV();
  printf("\tSaisir l'indice de la Ville Parmis cette liste ");
  F.IdVilleF=SaisirVille();
  printf("\tSaisir le Type de Diplome de la Formation ");
	scanf("%s",&F.TypeDiplome);
  printf("\tSaisir la Specialite de la Formation ");
	scanf("%s",&F.Specialite);
  printf("\tSaisir la Date de Debut de La Formation ");
  scanf("%s",&F.DateDebutFormation);
  printf("\tSaisir la Duree de La Formation ");
	scanf("%s",&F.DureeFormation);
  printf("\tSaisir l'Etablissement de La Formation ");
  scanf("%s",&F.EtablissementFormation);


  fflush(stdin);

	F.IdFormation=getIdFormation("TFORMATIONS.txt")+1;
	fflush(stdin);

  fprintf(Fe,"%d ;%d ;%d ;%s ;%s ;%s ;%s ;%s  \n",F.IdFormation,F.IdCVF,F.IdVilleF,F.TypeDiplome,F.Specialite,F.DateDebutFormation,F.DureeFormation,F.EtablissementFormation);
	printf("\n\nLa Formation %d %s est ajoute au fichier TFORMATIONS.txt avec success \n",F.IdFormation,F.TypeDiplome);
	fclose(Fe);
}

void RechercheFormation()
{
	int NumR,j=0;
	printf("\n\tEntrez l'indice de La Formation a rechercher :");
	scanf("%d",&NumR);
	FILE *Fe;
	Fe=fopen("TFORMATIONS.txt","r");
	do
	{
    fscanf(Fe,"%d ;%d ;%d ;%s ;%s ;%s ;%s ;%s  \n",&F.IdFormation,&F.IdCVF,&F.IdVilleF,&F.TypeDiplome,&F.Specialite,&F.DateDebutFormation,&F.DureeFormation,&F.EtablissementFormation);
	if(NumR==F.IdFormation)
	{
	        printf("\n\t===============INFORMATION SUR LA FORMATION : %d  ================\n\t ",F.IdFormation);
	        printf("\n\tLe Type de Diplome \t\t\t:%s",F.TypeDiplome);
          printf("\n\tLa Mission \t\t\t:%s",F.Specialite);
	        printf("\n\tLa Date de Debut \t\t\t:%s",F.DateDebutFormation);
	        printf("\n\tLa Duree \t\t\t:%s",F.DureeFormation);
          printf("\n\tL'Etablissement \t\t\t:%s",F.Specialite);
	        AfficherCVComp(F.IdCVF);
	        AfficherVilleC(F.IdVilleF);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fe));
	fclose(Fe);
	if(j==0){
	    printf("\n\tDesole! La Formation n'existe pas\n");
	}
}

void SupprimerFormation()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez L'indice de La Formation a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechFormation(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Fet,*Fe;
	        Fe=fopen("TFORMATIONS.txt","r");
	        test_file_opening(Fe);
	        Fet=fopen("FORMATIONS.txt","a");
	        test_file_opening(Fet);
	        do
	        {
           fscanf(Fe,"%d ;%d ;%d ;%s ;%s ;%s ;%s ;%s  \n",&F.IdFormation,&F.IdCVF,&F.IdVilleF,&F.TypeDiplome,&F.Specialite,&F.DateDebutFormation,&F.DureeFormation,&F.EtablissementFormation);
	         if(NumRech!=F.IdFormation)
	         {
             fprintf(Fet,"%d ;%d ;%d ;%s ;%s ;%s ;%s ;%s  \n",F.IdFormation,F.IdCVF,F.IdVilleF,F.TypeDiplome,F.Specialite,F.DateDebutFormation,F.DureeFormation,F.EtablissementFormation);
	         }
	        }while(!feof(Fe));
	        fclose(Fet);
	        fclose(Fe);
	        remove("TFORMATIONS.txt");
	        rename("FORMATIONS.txt","TFORMATIONS.txt");
	        printf("\n\tLa suppression Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tl'indice de La Formation n'existe pas");
	}
}

void ModifierFormation(){

	FILE *Fe,*Fet;
	int num,i;
	char rep='n';
	printf("\n\tEntrez L'indice de La Formation a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechFormation(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fe=fopen("TFORMATIONS.txt","r");
	    test_file_opening(Fe);
	    Fet=fopen("FORMATIONS.txt","a");
	    test_file_opening(Fet);

	 do
	{
    fscanf(Fe,"%d ;%d ;%d ;%s ;%s ;%s ;%s ;%s  \n",&F.IdFormation,&F.IdCVF,&F.IdVilleF,&F.TypeDiplome,&F.Specialite,&F.DateDebutFormation,&F.DureeFormation,&F.EtablissementFormation);
	   if(num==F.IdFormation)
	{
		F.IdFormation=num;
    printf("\tSaisir le nouveau indice du Cv Parmis cette liste ");
    F.IdCVF=SaisirCV();
    printf("\tSaisir le nouveau indice de la Ville Parmis cette liste ");
    F.IdVilleF=SaisirVille();
    printf("\tSaisir le nouveau Type de Diplome de la Formation ");
    scanf("%s",&F.TypeDiplome);
    printf("\tSaisir la nouvelle Specialite de la Formation ");
    scanf("%s",&F.Specialite);
    printf("\tSaisir la nouvelle Date de Debut de La Formation ");
    scanf("%s",&F.DateDebutFormation);
    printf("\tSaisir la nouvelle Duree de La Formation ");
    scanf("%s",&F.DureeFormation);
    printf("\tSaisir le nouveau Etablissement de La Formation ");
    scanf("%s",&F.EtablissementFormation);
	}
  fprintf(Fet,"%d ;%d ;%d ;%s ;%s ;%s ;%s ;%s  \n",F.IdFormation,F.IdCVF,F.IdVilleF,F.TypeDiplome,F.Specialite,F.DateDebutFormation,F.DureeFormation,F.EtablissementFormation);
	}while(!feof(Fe));
    fclose(Fet);
    fclose(Fe);
	remove("TFORMATIONS.txt");
	rename("FORMATIONS.txt","TFORMATIONS.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annule\n");
	}
	}
	else
	{
	printf("\n\tL'indice de La Formation N'existe pas\n");
	}
}

int RechercheFormationParLigne(struct TFORMATIONS F1)
{
  	int  id;
    int IdCV;
    int IdVille;
    char TypeDiplome_courant[MAX];
    char Specialite[50];
    char DateDebutFormation[15];
    char DureeFormation[15];
    char EtablissementFormation[50];
    char  line[BIG_MAX];
    FILE * F=fopen("TFORMATIONS.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
        fscanf(F,"%d ;%d ;%d ;%s ;%s ;%s ;%s ;%s  \n",&id,&IdCV,&IdVille,TypeDiplome_courant,Specialite,DateDebutFormation,DureeFormation,EtablissementFormation);
        if((IdVille==F1.IdVilleF) && (IdCV==F1.IdCVF) && !strcmp(TypeDiplome_courant,F1.TypeDiplome) && !strcmp(Specialite,F1.Specialite) && !strcmp(DateDebutFormation,F1.DateDebutFormation) && !strcmp(DureeFormation,F1.DureeFormation) && !strcmp(EtablissementFormation,F1.EtablissementFormation))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechFormation(int Numrech)
{
	FILE *Fe;
	Fe=fopen("TFORMATIONS.txt","r");
	test_file_opening(Fe);
	do
		{
    fscanf(Fe,"%d ;%d ;%d ;%s ;%s ;%s ;%s ;%s  \n",&F.IdFormation,&F.IdCVF,&F.IdVilleF,&F.TypeDiplome,&F.Specialite,&F.DateDebutFormation,&F.DureeFormation,&F.EtablissementFormation);
		fflush(stdin);
		if(F.IdFormation==Numrech)
			{
			fclose(Fe);
			return 1;
			}
		}while(!feof(Fe));
	fclose(Fe);
	return -1;
}

void AfficherFormations()
{
	FILE *Fe;
	Fe=fopen("TFORMATIONS.txt","r");
	do
	{
    fscanf(Fe,"%d ;%d ;%d ;%s ;%s ;%s ;%s ;%s  \n",&F.IdFormation,&F.IdCVF,&F.IdVilleF,&F.TypeDiplome,&F.Specialite,&F.DateDebutFormation,&F.DureeFormation,&F.EtablissementFormation);
    printf("\n\t===============INFORMATION SUR LA FORMATION : %d  ================\n\t ",F.IdFormation);
    printf("\n\tLe Type de Diplome \t\t\t:%s",F.TypeDiplome);
    printf("\n\tLa Mission \t\t\t:%s",F.Specialite);
    printf("\n\tLa Date de Debut \t\t\t:%s",F.DateDebutFormation);
    printf("\n\tLa Duree \t\t\t:%s",F.DureeFormation);
    printf("\n\tL'Etablissement \t\t\t:%s",F.EtablissementFormation);
    AfficherCVComp(F.IdCVF);
    AfficherVilleC(F.IdVilleF);
    printf("\n\t-----------------------------------------------------------------");
	}while(!feof(Fe));
	fclose(Fe);
}

int getIdFormation(char *File)
{
	  int id;
	  int j=(-1);
    int IdCV;
    int IdVille;
    char TypeDiplome_courant[MAX];
    char Specialite[50];
    char DateDebutFormation[15];
    char DureeFormation[15];
    char EtablissementFormation[50];
	  char N[100];
    FILE *F;
    F=fopen("TFORMATIONS.txt","r");
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
      fscanf(F,"%d ;%d ;%d ;%s ;%s ;%s ;%s ;%s  \n",&id,&IdCV,&IdVille,TypeDiplome_courant,Specialite,DateDebutFormation,DureeFormation,EtablissementFormation);
		}
	fclose(F);
	return id;
	}
}

void MenuFormation()
{
int Choix;char rep;
do
	{
	    system("cls");
	    printf("\n\t              ***********************                ");
	    printf("\n\t*************** MENU DES FORMATIONS ********************");
	    printf("\n\t              ***********************                ");
	    printf("\n\t                                               \n ");
	    printf("\t*  (1) Ajouter une Formation                   *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (2) Rechercher une Formation                *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (3) Supprimer une Formation                 *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (4) Modifier une Formation                  *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (5) Afficher tous Les Formations            *\n");
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
		    case 1:AjouterFormation();
		        break;
		    case 2:RechercheFormation();
		        break;
		    case 3:SupprimerFormation();
		        break;
		    case 4:ModifierFormation();
		        break;
		    case 5:AfficherFormations();
		        break;
		    case 6:break;
		    }
	    printf("\n\t>>> Voulez-vous continuez O/N?...");
	    scanf("%s",&rep);
	    fflush(stdin);
	}while(rep=='o'||rep=='O');
}
