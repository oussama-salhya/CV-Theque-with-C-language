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
void MenuComp();

struct TCOMPETENCES
{
  int IdComp;
	char NomCompetence[50];
  char Secteur[50];
  char TypeCompetence[50];
  int IdCvComp;

};struct TCOMPETENCES C ;

void AjouterComp()
{

	FILE *Fc;
	Fc=fopen("TCOMPETENCES.txt","a");
	test_file_opening(Fc);
  printf("\tSaisir le Nom de la Competence ");
  scanf("%s",&C.NomCompetence);
  	getchar();

 	printf("\tSaisir le Secteur de la Competence ");
	scanf("%s",&C.Secteur);
  printf("\tSaisir Le Type de la Competence ");
	scanf("%s",&C.TypeCompetence);
  printf("\tSaisir l'indice du Cv où se trouve La Competence ");
  	C.IdCvComp=SaisirCV();
	C.IdComp=getIDComp("TCOMPETENCES.txt")+1;
	fflush(stdin);
	fprintf(Fc,"%d ;%s ;%s ;%s ;%d \n",C.IdComp,C.NomCompetence,C.Secteur,C.TypeCompetence,C.IdCvComp);
	printf("\n\nla Competence %u %s est ajoute au fichier TCOMPETENCES.txt avec success \n",C.IdComp,C.NomCompetence);
	fclose(Fc);
}

void RechercheComp()
{
	int NumR,j=0;
	printf("\n\tEntrez l'indice de la Competence a rechercher :");
	scanf("%d",&NumR);
	FILE *Fc;
	Fc=fopen("TCOMPETENCES.txt","r");
	do
	{
	fscanf(Fc,"%d ;%s ;%s ;%s ;%d \n",&C.IdComp,&C.NomCompetence,&C.Secteur,&C.TypeCompetence,&C.IdCvComp);
	if(NumR==C.IdComp)
	{
	        printf("\n\t===============INFORMATION SUR LA COMPETENCE : %d  ================\n\t ",C.IdComp);
	        printf("\n\tLe Nom \t\t\t:%s",C.NomCompetence);
	        printf("\n\tLe Secteur \t\t\t:%s",C.Secteur);
	        printf("\n\tLe Type \t\t\t:%s",C.TypeCompetence);
	        AfficherCVComp(C.IdCvComp);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fc));
	fclose(Fc);
	if(j==0){
	    printf("\n\tDesole! La Competence n'existe pas\n");
	}
}

void SupprimerComp()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez L'indice de la Competence a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechComp(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Fct,*Fc;
	        Fc=fopen("TCOMPETENCES.txt","r");
	        test_file_opening(Fc);
	        Fct=fopen("COMPETENCES.txt","a");
	        test_file_opening(Fct);
	        do
	        {
	         fscanf(Fc,"%d ;%s ;%s ;%s ;%d \n",&C.IdComp,&C.NomCompetence,&C.Secteur,&C.TypeCompetence,&C.IdCvComp);
	         if(NumRech!=C.IdComp)
	         {
			          fprintf(Fct,"%d ;%s ;%s ;%s ;%d \n",C.IdComp,C.NomCompetence,C.Secteur,C.TypeCompetence,C.IdCvComp);
	         }
	        }while(!feof(Fc));
	        fclose(Fct);
	        fclose(Fc);
	        remove("TCOMPETENCES.txt");
	        rename("COMPETENCES.txt","TCOMPETENCES.txt");
	        printf("\n\tLa suppression Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tl'indice de la Competence n'existe pas");
	}
}

void ModifierComp(){

	FILE *Fc,*Fct;
	int num,i;
	char rep='n';
	printf("\n\tEntrez L'indice de la Competence a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechComp(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fc=fopen("TCOMPETENCES.txt","r");
	    test_file_opening(Fc);
	    Fct=fopen("COMPETENCES.txt","a");
	    test_file_opening(Fct);

	 do
	{
    fscanf(Fc,"%d ;%s ;%s ;%s ;%d \n",&C.IdComp,&C.NomCompetence,&C.Secteur,&C.TypeCompetence,&C.IdCvComp);
	if(num==C.IdComp)
	{
		C.IdComp=num;
		printf("\tSaisir le nouveau Nom de la Competence ");
  	scanf("%s",&C.NomCompetence);
	  printf("\tSaisir le nouveau Secteur ");
		scanf("%s",&C.Secteur);
	  printf("\tSaisir le nouveau Type de la Competence ");
		scanf("%s",&C.TypeCompetence);
	  printf("\tSaisir le nouveau indice du Cv de la Competence Parmis cette liste ");
	  C.IdCvComp=SaisirCV();
	}
  fprintf(Fct,"%d ;%s ;%s ;%s ;%d \n",C.IdComp,C.NomCompetence,C.Secteur,C.TypeCompetence,C.IdCvComp);
	}while(!feof(Fc));
    fclose(Fct);
    fclose(Fc);
	remove("TCOMPETENCES.txt");
	rename("COMPETENCES.txt","TCOMPETENCES.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annule\n");
	}
	}
	else
	{
	printf("\n\tL'indice de la Competence N'existe pas\n");
	}
}

int RechercheCompParNom(char * NomCompetence)
{
	  int 	id;
    char  NomCompetence_courant[MAX];
    char  Secteur_courant[MAX];
    char  TypeCompetence_courant[MAX];
    int   idCv;
    char  line[BIG_MAX];
    FILE * F=fopen("TCOMPETENCES.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
        fscanf(F,"%d ;%s ;%s ;%s ;%d \n",&id,NomCompetence_courant,Secteur_courant,TypeCompetence_courant,&idCv);
        if(!strcmp(NomCompetence,NomCompetence_courant))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechComp(int Numrech)
{
	FILE *Fc;
	Fc=fopen("TCOMPETENCES.txt","r");
	test_file_opening(Fc);
	do
		{
		fscanf(Fc,"%d ;%s ;%s ;%s ;%d \n",&C.IdComp,&C.NomCompetence,&C.Secteur,&C.TypeCompetence,&C.IdCvComp);
		fflush(stdin);
		if(C.IdComp==Numrech)
			{
			fclose(Fc);
			return 1;
			}
		}while(!feof(Fc));
	fclose(Fc);
	return -1;
}

void AfficherComp()
{
	FILE *Fc;
	Fc=fopen("TCOMPETENCES.txt","r");
	do
	{
    fscanf(Fc,"%d ;%s ;%s ;%s ;%d \n",&C.IdComp,&C.NomCompetence,&C.Secteur,&C.TypeCompetence,&C.IdCvComp);
	        printf("\n\t===============INFORMATION SUR LE Candidat : %d  ================\n\t ",C.IdComp);
          printf("\n\tLe Nom \t\t\t:%s",C.NomCompetence);
	        printf("\n\tLe Secteur \t\t\t:%s",C.Secteur);
	        printf("\n\tLe Type \t\t\t:%s",C.TypeCompetence);
	        AfficherCVComp(C.IdCvComp);
	        printf("\n\t-----------------------------------------------------------------");
	}while(!feof(Fc));
	fclose(Fc);
}

int getIDComp(char *File)
{
	int j=(-1);
    int 	id;
    char  NomCompetence_courant[MAX];
    char  Secteur_courant[MAX];
    char  TypeCompetence_courant[MAX];
    int   idCv;
	char N[100];
    FILE *F;
    F=fopen("TCOMPETENCES.txt","r");
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
      fscanf(F,"%d ;%s ;%s ;%s ;%d \n",&id,NomCompetence_courant,Secteur_courant,TypeCompetence_courant,&idCv);
		}
	fclose(F);
	return id;
	}
}

int SaisirCV()
{
  int id;
  AfficherCV();
  printf("\n\tindice : ");
  do {
    scanf("%d",&id);
  } while (rechCV(id)!=1);
  return id;
}

void MenuComp()
{
int Choix;char rep;
do
	{
	    system("cls");
	    printf("\n\t              ***********************                ");
	    printf("\n\t*************** MENU DES COMPETENCES ********************");
	    printf("\n\t*             ***********************                ");
	    printf("\n\t*                                             *\n ");
	    printf("\t*  (1) Ajouter une Competence                   *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (2) Rechercher une Competence                *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (3) Supprimer une Competence                 *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (4) Modifier une Competence                  *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (5) Afficher toutes Les Competences          *\n");
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
		    case 1:AjouterComp();
		        break;
		    case 2:RechercheComp();
		        break;
		    case 3:SupprimerComp();
		        break;
		    case 4:ModifierComp();
		        break;
		    case 5:AfficherComp();
		        break;
		    case 6:break;
		    }
	    printf("\n\t>>> Voulez-vous continuez O/N?...");
	    scanf("%s",&rep);
	    fflush(stdin);
	}while(rep=='o'||rep=='O');
}

