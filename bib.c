#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> //declaration des bibliotheque C necessaire pour la fonction declare apres

int pe(char n[]){ //fontion qui calcule le nombre des chiffres avants la virgule (partie entiere)
  int i,a,e=0;
  for (i = 0; i<=strlen(n)-1 ; i++)
  {
   a=n[i];
   if ((a==46)) //sauvegarder la position de virgule
   {
    e=i;
   }
   else if ((i==(strlen(n)-1))&&(e==0))
   {
    e=i+1;
   }

  }
  return e;
}

int pf(char n[]){ //fontion qui calcule le nombre des chiffres apres la virgule (partie fractionnaire)
  int i,a,e=0,f;
  for (i=0 ; i<=(strlen(n)-1) ; i++)
  {
   a=n[i];
   if ((a==46))
   {
    e=i;
   }
   if ((i==(strlen(n)-1))&&(e==0))
   {
    e=i;
   } //meme choses comme la fonction pe

  }
  f=strlen(n)-1-e; //calculer le nombre en utilisant la taille et le nombre des chiffres de partie entiere
  return f;
}

float anytodec(char N[],int b){ // la fonction responsable de la conversion de n'importe quelle base vers decimale

    int j;
    float r=0,p;//declaration de variables

    j=pe(N)-1;
    for (int i=0; i<pe(N) ; i++) //boucle pour calculer le resultat de conversion de partie entiere
    {
        p=pow(b,j);
        if ((N[i]>='0') && (N[i]<='9')) //en utilisant le code ascii pour savoir traiter la chaine de caractere
        {
          r=r+(N[i]-48)*p;
          j=j-1;
        }
        if ((N[i]>='A') && (N[i]<='Z')) //en utilisant le code ascii pour savoir traiter la chaine de caractere
        {
          r=r+(N[i]-55)*p;
          j=j-1;
        }
    }
    j=pf(N);
    for (int i=0 ; i<pf(N) ; i++) //boucle pour calculer le resultat de conversion de partie fractionnaire
    {
        p=pow(b,(-j));
        if ((N[pe(N)+i+1]>='0') && (N[pe(N)+i+1]<='9'))//en utilisant le code ascii pour savoir traiter la chaine de caractere
        {
          r=r+(N[pe(N)+i+1]-48)*p;
          j=j-1;
        }
        if ((N[pe(N)+i+1]>='A') && (N[pe(N)+i+1]<='Z'))//en utilisant le code ascii pour savoir traiter la chaine de caractere
        {
          r=r+(N[pe(N)+i+1]-55)*p;
          j=j-1;
        }
    }


    return r ; // retourner le resultat
}


void dectoany(float ndec,int b,char R[]){// la fonction responsable de la conversion de decimale vers n'importe quelle base
    int i=0,j,k,nd,rfi;
    float p,re=0,r=0,rf;
    char R1[1],R2[20],t[20];
    nd=ndec;
    rf=ndec-(float)nd; //declaration de variables necessaire

    if (b<=10) //distinguer les cas pour mieux traiter la conversion et reserver le resultat dans une chaine de caractere
    {

         while (nd!=0) //boucles utiliser pour le calcul de le resultat de conversion de partie entiere
         {
           p=pow((float)10,(float)i);
           re=re+fmodf(floorf(nd),b)*p;
           nd=nd/b;
           i++;
        }


    for (int f=1 ; f<6 ; f++) //boucles utiliser pour le calcul de le resultat de conversion de partie fractionnaire
    {
      rf=rf*b;
      rfi=rf;
      re=re+(rfi*pow(10,-f));
      rf=rf-rfi;

    }
    sprintf(R,"%f",re); //fonction utiliser pour rendre un nombre une chaine de caractere
    }


    else{ //si la base est superieure a 10
      while (nd>0)
      {
        r=nd%b;
        if (r>=10)
        {
          r=r+55;
          R2[i]=(char)r;
          R[i+1]='\0';
        }
        else if ((r>=0)&&(r<=9))
        {
          sprintf(R1,"%d",r);
          R2[i]=R1[0];
          R[i+1]='\0';
        }
        i++;
        nd=nd/b;
      }

      k=i-1;
      for (j=0 ; j<=i-1 ; j++)
      {
        R[j]=R2[k];
        k--;
      }
      R[j+1]='\0';

    }
}

bool cntrls(char N[],int b){ // fontion pour controler le saisie
    bool v=true;
    int i=0;
    do{ //boucle pour verifier la chaine caractere par caractere
        if ((N[i]>='0') && (N[i]<='9'))
        {
          if (N[i]-48>=b){
          v=false; //retourner false si la condition est verifie c'est a dire le nombre est malle saisie
        }
        }
        else if (((N[i]>='A') && (N[i]<='Z'))||(N[i]=='.')||(N[i]==','))
        {
          if (N[i]-55>=b){
          v=false;//retourner false si la condition est verifie c'est a dire le nombre est malle saisie
        }
        }
        else {
            v=false;//retourner false si la condition est verifie c'est a dire le nombre est malle saisie
        }
       i++;
    } while ((v==true)&&(i<strlen(N))); // quitter la boucle s'il exist au moins un caractere malle saisie ou la chaine de caractere est verifie completement
    return v; //retourner le resultat
}
