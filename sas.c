#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Menu()
{
    int choix;

    printf("**************Menu*****************\n");
    printf("1-Ajouter un nouveau produit.\n");
    printf("2-Ajouter plusieurs nouveaux produits.\n");
    printf("3-Afficher la liste des produits.\n");
    printf("4-Acheter des produits.\n");
    printf("5-Chercher les produits.\n");
    printf("6-Etat de stock.\n");
    printf("7-Alimenter le stock.\n");
    printf("8-Supprimer les produits.\n");
    printf("9-Statistique de vente\n");
    
    printf("\nEntrer votre choix :\n");
    scanf("%d", &choix);
    return choix;
}
struct produits{
	char code[10];
	char nom[10];
	int quantiter;
	double prix ;
	
	
	
};




struct produits p[100];
	


// premier operation


void AjouterProduit(){
	int C;

		printf("Entrer le nom du produit: \n");
		scanf("%s",p[C].nom);
		printf("Entrer le code du produit: \n");
		scanf("%s",p[C].code);
		printf("Entrer la quantite du produit: \n");
		scanf("%d",&p[C].quantiter);
		printf("Entrer le prix du produit: \n");
		scanf("%lf",&p[C].prix);
		C++;
	
	
	
	
	
	
}
void AjouterPlusieursProduits (){
    int NombreProduit,i;
    printf(" Entrer le nombre de produit:\n");
    scanf("%d",&NombreProduit);
   
    for(i=0;i<NombreProduit;i++){
        AjouterProduit();
    }
    
}


void ListeProduit(){
	int choixliste;
	printf("1-produits selon l ordre alphabetique croissant du nom\n2-les produits selon l ordre décroissant du prix \n Entrer votre choix :");
	scanf("%d",&choixliste);
	
}
void OrdreAlphabetique(){
	int i,j, NombreProduit;
	struct produits z;
	
	for(i=0;i<NombreProduit;i++){
		for(j=i+1;j<NombreProduit;j++){
			if(strcmp(p[i].nom,p[j].nom)>0){
			z=p[i];
			p[i]=p[j];
			p[j]=z;
		}
			
		}
		
	
		
		
		
		
	}
	printf("---------------------------------\n");
    printf("nom        prix       prix TTC \n");
    for(i=0;i<NP;i++){
    	printf("%s      %.2lf       %.2lf",p[i].nom,p[i].prix,p[i].prix*1.15);
	}
	menu();
	
	
	
	
}


 










int main(int argc, char *argv[]) {
	int choix,choixliste ;
	
	
		menu();
		switch(choix){
		case 1:AjouterProduit();
		  
		  break;
		  
		  
		case 2:ListeProduit();
		  
		  if(choixliste==1){
		  	 OrdreAlphabetique();
		  	
		  }else{
		  	 OrdrePrix();
		  	
		  }
		  break;
		
		
		  
		      
		  
			
	}
	

	
	return 0;
}
