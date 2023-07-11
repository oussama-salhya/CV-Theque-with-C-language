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


struct TCANDIDATS
{
  int IdCandidat;
	char NomCandidat[50];
  char PrenomCandidat[50];
  char GenreCandidat[15];
  char EmailCandidat[50];
  char AdresseCandidat[50];
  char TelephoneCandidat[50];
  char CINCandidat[30];
  char DateNaissance[30];
  int IdEtatCivilC;
  int IdVilleC;
  char Disponible[50];
  int IdNationaliteCandidat;
  int IdPermisC;

};struct TCANDIDATS C ;

void AjouterCandidat()
{

	FILE *Fc;
	Fc=fopen("TCANDIDATS.txt","a");
	test_file_opening(Fc);
  	printf("\tSaisir le CIN du Candidat ");
  	scanf("%s",&C.CINCandidat);
  	getchar();
  	if(RechercheCandidatParCIN(C.CINCandidat)==1)
    {
        printf("CIN deja existe\n");
        return;
    }
	printf("\tSaisir le Nom du Candidat ");
	scanf("%s",&C.NomCandidat);
 	printf("\tSaisir le Prenom du Candidat ");
	scanf("%s",&C.PrenomCandidat);
	printf("\tSaisir le Genre du Candidat (H ou F) ");
		{
		    char b;
		  	do {
		      scanf("%c",&b);
		    }while(b!='h' && b!='f' && b!='H' && b!='f' );
		    if(b == 'h' || b == 'H')
		    {
		      strcpy(C.GenreCandidat,"Homme");
		    }
		    else
		    {
		      strcpy(C.GenreCandidat,"Femme");
		    }
	  	}
  	printf("\tSaisir l'Email du Candidat ");
	scanf("%s",&C.EmailCandidat);
  	printf("\tSaisir l'Adresse du Candidat ");
	scanf("%s",&C.AdresseCandidat);
  	printf("\tSaisir le Telephone du Candidat ");
	scanf("%s",&C.TelephoneCandidat);
  	printf("\tSaisir la Date de Naissance du Candidat ");
	scanf("%s",&C.DateNaissance);
  	printf("\tSaisir l'indice du Pays Origine du Candidat Parmis cette liste ");
  	C.IdNationaliteCandidat=SaisirPays();
  	printf("\tSaisir l'indice du l'Etat Civil Parmis cette liste ");
 	C.IdEtatCivilC=SaisirEtat();
 	printf("\tSaisir l'indice de la Ville du Candidat ");
  	C.IdVilleC=SaisirVille();
  	printf("\tSaisir l'indice du Permis du Candidat ");
  	C.IdPermisC=SasirPermis();
  	printf("\tSaisir la Disponibilite du Candidat (O ou N) ");
	  {
	    char a;
	  	do {
	      scanf("%c",&a);
	    }while(a!='o' && a!='n' && a!='O' && a!='N' );
	    if(a == 'o' || a == 'O')
	    {
	      strcpy(C.Disponible,"Oui");
	    }
	    else
	    {
	      strcpy(C.Disponible,"Non");
	    }
	  }
    fflush(stdin);
	C.IdCandidat=getIDCandidat("TCANDIDATS.txt")+1;
	fflush(stdin);

	fprintf(Fc,"%d ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d ;%s  \n",C.IdCandidat,C.CINCandidat,C.NomCandidat,C.PrenomCandidat,C.GenreCandidat,C.EmailCandidat,C.AdresseCandidat,C.TelephoneCandidat,C.DateNaissance,C.IdNationaliteCandidat,C.IdEtatCivilC,C.IdVilleC,C.IdPermisC,C.Disponible);
	printf("\n\nle Candidat %u %s est ajoute au fichier TCANDIDATS.txt avec success \n",C.IdCandidat,C.NomCandidat);
	fclose(Fc);
}

void RechercheCandidat()
{
	int NumR,j=0;
	printf("\n\tEntrez l'indice du Candidat a rechercher :");
	scanf("%d",&NumR);
	FILE *Fc;
	Fc=fopen("TCANDIDATS.txt","r");
	do
	{
	fscanf(Fc,"%d ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d ;%s  \n",&C.IdCandidat,&C.CINCandidat,&C.NomCandidat,&C.PrenomCandidat,&C.GenreCandidat,&C.EmailCandidat,&C.AdresseCandidat,&C.TelephoneCandidat,&C.DateNaissance,&C.IdNationaliteCandidat,&C.IdEtatCivilC,&C.IdVilleC,&C.IdPermisC,&C.Disponible);
	if(NumR==C.IdCandidat)
	{
	        printf("\n\t===============INFORMATION SUR LE Candidat : %d  ================\n\t ",C.IdCandidat);
	        printf("\n\tCIN \t\t\t:%s",C.CINCandidat);
	        printf("\n\tLe Nom \t\t\t:%s",C.NomCandidat);
	        printf("\n\tLe Prenom \t\t\t:%s",C.PrenomCandidat);
	        printf("\n\tLe Genre \t\t\t:%s",C.GenreCandidat);
	        printf("\n\tL'Email \t\t\t:%s",C.EmailCandidat);
	        printf("\n\tL'Adresse \t\t\t:%s",C.AdresseCandidat);
	        printf("\n\tL'Telephone \t\t\t:%s",C.TelephoneCandidat);
	        printf("\n\tLa Date de Naissance \t\t\t:%s",C.DateNaissance);
	        AfficherPaysC(C.IdNationaliteCandidat);
	        AfficherEtatCC(C.IdEtatCivilC);
	        AfficherVilleC(C.IdVilleC);
	        AfficherPermisC(C.IdPermisC);
	        printf("\n\tLa Disponibilite \t\t\t:%s",C.Disponible);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fc));
	fclose(Fc);
	if(j==0){
	    printf("\n\tDesole! Le Candidat n'existe pas\n");
	}
}

void SupprimerCandidat()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez L'indice du Candidat a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechCandidat(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Fct,*Fc;
	        Fc=fopen("TCANDIDATS.txt","r");
	        test_file_opening(Fc);
	        Fct=fopen("CANDIDATS.txt","a");
	        test_file_opening(Fct);
	        do
	        {
	        fscanf(Fc,"%d ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d ;%s  \n",&C.IdCandidat,&C.CINCandidat,&C.NomCandidat,&C.PrenomCandidat,&C.GenreCandidat,&C.EmailCandidat,&C.AdresseCandidat,&C.TelephoneCandidat,&C.DateNaissance,&C.IdNationaliteCandidat,&C.IdEtatCivilC,&C.IdVilleC,&C.IdPermisC,&C.Disponible);
	         if(NumRech!=C.IdCandidat)
	         {
			fprintf(Fct,"%d ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d ;%s  \n",C.IdCandidat,C.CINCandidat,C.NomCandidat,C.PrenomCandidat,C.GenreCandidat,C.EmailCandidat,C.AdresseCandidat,C.TelephoneCandidat,C.DateNaissance,C.IdNationaliteCandidat,C.IdEtatCivilC,C.IdVilleC,C.IdPermisC,C.Disponible);
	         }
	        }while(!feof(Fc));
	        fclose(Fct);
	        fclose(Fc);
	        remove("TCANDIDATS.txt");
	        rename("CANDIDATS.txt","TCANDIDATS.txt");
	        printf("\n\tLa suppression Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tl'indice du Candidat n'existe pas");
	}
}

void ModifierCandidat(){

	FILE *Fc,*Fct;
	int num,i;
	char rep='n';
	printf("\n\tEntrez L'indice du Candidat a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechCandidat(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fc=fopen("TCANDIDATS.txt","r");
	    test_file_opening(Fc);
	    Fct=fopen("CANDIDATS.txt","a");
	    test_file_opening(Fct);

	 do
	{
	fscanf(Fc,"%d ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d ;%s  \n",&C.IdCandidat,&C.CINCandidat,&C.NomCandidat,&C.PrenomCandidat,&C.GenreCandidat,&C.EmailCandidat,&C.AdresseCandidat,&C.TelephoneCandidat,&C.DateNaissance,&C.IdNationaliteCandidat,&C.IdEtatCivilC,&C.IdVilleC,&C.IdPermisC,&C.Disponible);
	if(num==C.IdCandidat)
	{
		C.IdCandidat=num;
		printf("\tSaisir le nouveau CIN du Candidat ");
  		scanf("%s",&C.CINCandidat);
  		if(RechercheCandidatParCIN(C.CINCandidat)==1)
	    {
	        printf("CIN deja existe\n");
	        return;
	    }
	    printf("\tSaisir le nouveau Nom du Candidat ");
		scanf("%s",&C.NomCandidat);
	  	printf("\tSaisir le nouveau Prenom du Candidat ");
		scanf("%s",&C.PrenomCandidat);
	  	printf("\tSaisir le nouveau Genre du Candidat (H ou F) ");
		{
		    char b;
		  	do {
		      scanf("%c",&b);
		    }while(b!='h' && b!='f' && b!='H' && b!='f' );
		    if(b == 'h' || b == 'H')
		    {
		      strcpy(C.Disponible,"Homme");
		    }
		    else
		    {
		      strcpy(C.Disponible,"Femme");
		    }
	  	}
	  	printf("\tSaisir le nouveau Email du Candidat ");
		scanf("%s",&C.EmailCandidat);
	  	printf("\tSaisir le nouveau Adresse du Candidat ");
		scanf("%s",&C.AdresseCandidat);
	  	printf("\tSaisir le nouveau Telephone du Candidat ");
		scanf("%s",&C.TelephoneCandidat);
	  	printf("\tSaisir la nouvelle Date de Naissance du Candidat ");
		scanf("%s",&C.DateNaissance);
	  	printf("\tSaisir le nouveau indice du Pays Origine du Candidat Parmis cette liste ");
	  	C.IdNationaliteCandidat=SaisirPays();
	  	printf("\tSaisir le nouveau indice du l'Etat Civil Parmis cette liste ");
	  	C.IdEtatCivilC=SaisirEtat();
	  	printf("\tSaisir le nouveau indice de la Ville du Candidat ");
	  	C.IdVilleC=SaisirVille();
	  	printf("\tSaisir le nouveau indice du Permis du Candidat ");
	  	C.IdPermisC=SasirPermis();
	  	printf("\tSaisir la Disponibilite nouvelle du Candidat (O ou N) ");
	  	{
		    char a;
		  	do {
		      scanf("%c",&a);
		    }while(a!='o' && a!='n' && a!='O' && a!='N' );
		    if(a == 'o' || a == 'O')
		    {
		      strcpy(C.Disponible,"Oui");
		    }
		    else
		    {
		      strcpy(C.Disponible,"Non");
		    }
	  	}
	}
	fprintf(Fct,"%d ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d ;%s  \n",C.IdCandidat,C.CINCandidat,C.NomCandidat,C.PrenomCandidat,C.GenreCandidat,C.EmailCandidat,C.AdresseCandidat,C.TelephoneCandidat,C.DateNaissance,C.IdNationaliteCandidat,C.IdEtatCivilC,C.IdVilleC,C.IdPermisC,C.Disponible);
	}while(!feof(Fc));
    fclose(Fct);
    fclose(Fc);
	remove("TCANDIDATS.txt");
	rename("CANDIDATS.txt","TCANDIDATS.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annule\n");
	}
	}
	else
	{
	printf("\n\tL'indice du Candidat N'existe pas\n");
	}
}

int RechercheCandidatParCIN(char * CINCandidat)
{
	unsigned int id;
    char  NomCandidat[MAX];
    char  PrenomCandidat[MAX];
    char GenreCandidat[15];
    char EmailCandidat[50];
    char AdresseCandidat[50];
    char TelephoneCandidat[50];
    char cin[30];
    char DateNaissance[30];
    int IdEtatCv;
    int IdVille;
    char Disponible[15];
    int IdNationaliteCandidat;
    int IdPermis;
    char  line[BIG_MAX];
    FILE * F=fopen("TCANDIDATS.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
        fscanf(F,"%d ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d ;%s\n",&id,cin,NomCandidat,PrenomCandidat,GenreCandidat,EmailCandidat,AdresseCandidat,TelephoneCandidat,DateNaissance,&IdNationaliteCandidat,&IdEtatCv,&IdVille,&IdPermis,Disponible);
        if(!strcmp(cin,CINCandidat))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechCandidat(int Numrech)
{
	FILE *Fc;
	Fc=fopen("TCANDIDATS.txt","r");
	test_file_opening(Fc);
	do
		{
		fscanf(Fc,"%d ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d ;%s  \n",&C.IdCandidat,&C.CINCandidat,&C.NomCandidat,&C.PrenomCandidat,&C.GenreCandidat,&C.EmailCandidat,&C.AdresseCandidat,&C.TelephoneCandidat,&C.DateNaissance,&C.IdNationaliteCandidat,&C.IdEtatCivilC,&C.IdVilleC,&C.IdPermisC,&C.Disponible);
		fflush(stdin);
		if(C.IdCandidat==Numrech)
			{
			fclose(Fc);
			return 1;
			}
		}while(!feof(Fc));
	fclose(Fc);
	return -1;
}

void AfficherCandidats()
{
	FILE *Fc;
	Fc=fopen("TCANDIDATS.txt","r");
	do
	{
	fscanf(Fc,"%d ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d ;%s  \n",&C.IdCandidat,&C.CINCandidat,&C.NomCandidat,&C.PrenomCandidat,&C.GenreCandidat,&C.EmailCandidat,&C.AdresseCandidat,&C.TelephoneCandidat,&C.DateNaissance,&C.IdNationaliteCandidat,&C.IdEtatCivilC,&C.IdVilleC,&C.IdPermisC,&C.Disponible);
	        printf("\n\t===============INFORMATION SUR LE Candidat : %d  ================\n\t ",C.IdCandidat);
	        printf("\n\tCIN \t\t\t:%s",C.CINCandidat);
	        printf("\n\tLe Nom \t\t\t:%s",C.NomCandidat);
	        printf("\n\tLe Prenom \t\t\t:%s",C.PrenomCandidat);
	        printf("\n\tLe Genre \t\t\t:%s",C.GenreCandidat);
	        printf("\n\tL'Email \t\t\t:%s",C.EmailCandidat);
	        printf("\n\tL'Adresse \t\t\t:%s",C.AdresseCandidat);
	        printf("\n\tL'Telephone \t\t\t:%s",C.TelephoneCandidat);
	        printf("\n\tLa Date de Naissance \t\t\t:%s",C.DateNaissance);
	        AfficherPaysC(C.IdNationaliteCandidat);
	        AfficherEtatCC(C.IdEtatCivilC);
	        AfficherVilleC(C.IdVilleC);
	        AfficherPermisC(C.IdPermisC);
	        printf("\n\tLa Disponibilite \t\t\t:%s",C.Disponible);
	        printf("\n\t-----------------------------------------------------------------");
	}while(!feof(Fc));
	fclose(Fc);
}

int getIDCandidat(char *File)
{
	int id;
	int j=(-1);
    char  NomCandidat[MAX];
    char  PrenomCandidat[MAX];
    char GenreCandidat[15];
    char EmailCandidat[50];
    char AdresseCandidat[50];
    char TelephoneCandidat[50];
    char cin[30];
    char DateNaissance[30];
    int IdEtatCv;
    int IdVille;
    char Disponible[15];
    int IdNationaliteCandidat;
    int IdPermis;
	char N[100];
    FILE *F;
    F=fopen("TCANDIDATS.txt","r");
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
			fscanf(F,"%d ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d ;%s\n",&id,cin,NomCandidat,PrenomCandidat,GenreCandidat,EmailCandidat,AdresseCandidat,TelephoneCandidat,DateNaissance,&IdNationaliteCandidat,&IdEtatCv,&IdVille,&IdPermis,Disponible);
		}
	fclose(F);
	return id;
	}
}

int SaisirPays()
{
  int id;
  AfficherPays();
  do {
  	printf("\n\tid : ");
    scanf("%d",&id);
  } while (rechPays(id)!=1);
  return id;
}
int SaisirEtat()
{
  int id;
  AfficherEtatC();
  do {
  	printf("\n\tid : ");
    scanf("%d",&id);
  } while(rechEtatC(id)!=1);
  return id;
}

int SaisirVille()
{
  int id;
  AfficherVille();
  do {
  	printf("\n\tid : ");
    scanf("%d",&id);
  } while(rechVille(id)!=1);
  return id;
}

int SasirPermis()
{
  int id;
  AfficherPermis();
  do {
  	printf("\n\tid : ");
    scanf("%d",&id);
  } while(rechPermis(id)!=1);
  return id;
}

void MenuCandidat()
{
int Choix;char rep;
do
	{
	    system("cls");
	    printf("\n\t              **********************                  ");
	    printf("\n\t*************** MENU DES CANDIDATS ********************");
	    printf("\n\t              **********************                ");
	    printf("\n\t                                               \n ");
	    printf("\t*  (1) Ajouter un Candidat                      *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (2) Rechercher Un Candidat                   *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (3) Supprimer Un Candidat                    *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (4) Modifier Un Candidat                     *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (5) Afficher tous Les Candidats              *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (6) Quiter                                   *\n");
	    printf("\t*-----------------------------------------------*\n");

	    do
		    {
		     printf("\n\t>>> Etrez votre choix...");
		     scanf("%d",&Choix);
		     fflush(stdin);
		    }while(Choix<1||Choix>6);
	    switch(Choix)
			{
		    case 1:AjouterCandidat();
		        break;
		    case 2:RechercheCandidat();
		        break;
		    case 3:SupprimerCandidat();
		        break;
		    case 4:ModifierCandidat();
		        break;
		    case 5:AfficherCandidats();
		        break;
		    case 6:break;
		    }
	    printf("\n\t>>> Voulez-vous continuez O/N?...");
	    scanf("%s",&rep);
	    fflush(stdin);
	}while(rep=='o'||rep=='O');
}
