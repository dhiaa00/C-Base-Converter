#include <stdio.h>
#include <stdlib.h>  //declaration des bib de C qu'on a besoin pour effectuer les conversion
#include <math.h>
#include "bib.h" //declaration de la bibliotheque creer par nous pour utiliser les fonctions qui vont nous aider


int main()
{
    system("COLOR B0");

    int b1,b2;//declaration des bases
    float n;//declaration d'un reel pour effectuer les conversions avec les virgules
    char N[100],R[100],answer[2];  //declaration des chaines de caracteres N pour le nombre introduit ,R pour transformer les nombres a une chaine ,answer pour voir si l'utilisateur veux continuer

   printf("*** bienvenue dans notre application de conversion qui vous permetez de transferer entre les bases *** \n");
do{ //boucle de conversion
    printf("*************** veuillez entrez la base de nombre introduit entre base 2 et base 36 *************** \n");//introduiser le menu a l'utilisateur
    scanf("%d",&b1); // la lecture
    while(b1<=1){ // boucles de controle de saisie
        printf("| base invalide !\nentrez la base de nombre introduit | \n");
        scanf("%d",&b1);
    }


    printf("************************** veuillez entrez le nombre a convertir ************************** \n");
    scanf("%s",&N); // la lecture de nombre comme une chaine de caractere
    while(cntrls(N,b1)==false){ // controle de saisie
        printf("| erreur !\nentrez le nombre a convertir | \n");
        scanf("%s",&N);
    }


    printf("**************************** veuillez entrez la base a convertir entre base 2 et base 36 **************************** \n");
    scanf("%d",&b2); // la lecture de 2eme base
    while(b2<=1){ //controle de saisie
        printf("| base invalide !\nentrez la base de nombre introduit | \n");
        scanf("%d",&b2);
    }
    if (b1==10){ // on a distinguer les cas pour faciliter la conversion
        sscanf(N,"%f",&n); //fonction pour transformer une chaine de caractere a un nombre si la 1ere base est 10 on fait appelle a la fonction dectoany
        dectoany(n,b2,R); // utiliser directement la fonction dectoany
        printf("\n<<<                            le resultat de conversion est :%s                            >>> \n",R); // affichage de resultat
    }
    else if (b2==10){ // si la 2eme base est 10 on fait appelle a la fonction anytodec
      printf("\n<<<                            le resultat de conversion est :%f                            >>> \n",anytodec(N,b1)); //affichage de resultat
    }
    else { //si les 2 bases sont differentes de 10 on passe de 1ere vers 10 apres de 10 vers la 2eme donc anytodec apres dectoany
        dectoany(anytodec(N,b1),b2,R); //
        printf("\n<<<                            le resultat de conversion est :%s                            >>> \n",R); //affichage de resultat
    }
    printf("\n******************* si tu veux continuer tapez |oui| sinon tapez |non| *******************\n"); // donner le choix a l'utilisateur soit de continuer ou abbondoner
    scanf("%s",&answer); //lecture de la reponse de l'utilisateur

}while(strcmp(answer,"oui")==0); //verification de reponse
}
