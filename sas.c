#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct produits{
	char code[10];
	char nom[10];
	int quantiter;
	double prix ;
	
	
	
};



int C=0;
char test[10];
struct produits p[100];
	


// premier operation


void AjouterProduit(){
	

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
// deusieme operation
void AjouterPlusieursProduits (){
    int NombreProduits,i;
    printf(" Entrer le nombre de produit:\n");
    scanf("%d",&NombreProduits);
   
    for(i=0;i<NombreProduits;i++){
        AjouterProduit();
    }
    
}

// 3 operation


void ListeProduits(){
	int choixliste;
	printf("1-les produits selon l ordre alphabetique croissant du nom\n ");
	printf("2-les produits selon l ordre décroissant du prix \n ");
	printf("Entrer votre choix:");
	
	scanf("%d",&choixliste);
	if(choixliste==1){
		  	
		  	   OrdreAlphabetique();
	}
    else if (choixliste==2){
    	        OrdrePrix();
	}
	else{
		printf("Ce choix n existe pas .");
	}
	printf("\n Entrer returne pour retourner au menu ");
		     scanf("%s",test);
}
void OrdreAlphabetique(){
	int i,j, NombreProduits;
	struct produits z;
	
	for(i=0;i<C;i++){
		for(j=i+1;j<C;j++){
			if(strcmp(p[i].nom,p[j].nom)>0){
			z=p[i];
			p[i]=p[j];
			p[j]=z;
		}
			
		}
		
	}
	printf("**************************************\n");
    printf("nom        prix       prix TTC \n");
    for(i=0;i<C;i++){
    	printf("%s      %.2lf       %.2lf \n",p[i].nom,p[i].prix,p[i].prix*1.15);
	}
		
				
	}

	
	
	
	
	


void OrdrePrix(){
	int i,j;
	struct produits z;
	
	for(i=C;i>=0;i--){
		for(j=i;j>=0;j--){
			if(p[i].prix>p[j].prix){
			z=p[i];
			p[i]=p[j];
			p[j]=z;
		}
			
		}
		
	
		
		
		
		
	}
	printf("**************************************\n");
    printf("nom        prix       prix TTC       Quantiter\n");
    for(i=0;i<C;i++){
    	printf("%s      %.2lf       %.2lf      %d\n",p[i].nom,p[i].prix,p[i].prix*1.15,p[i].quantiter);
	}
	
}

// 4 operation
void AcheterProduit(){
	 
    char code[100];
    int quantiter;
    
   printf("entrer le code de produit que vous voulez achter:\n") ;
   scanf(" %s",code);
   printf("entrer la quantite de produit:\n");
   scanf("%d",&quantiter);
    int i , j=0;
	 
       
    for(i=0;i<C;i++){
        if(strcmp(p[i].code,code)==0){
            p[i].quantiter-=quantiter;
            printf("Achat reussite \n");
            j=1;
        }
    }
 
 if(j=0){
    printf("le produit n exist pas");
	
}
  

}

//operation 5

void ChercherProduit(){
	int chercheProduit,code,quantiter,i;
	printf("1-Chercher par code \n");
	printf("2-Chercher par quantiter\n");
	printf("1-Veuillez entrer votre choix :");
	scanf("%d",&chercheProduit);
	
	
	switch(chercheProduit){
		case 1 :
			printf("Entrer le code de produit :");
	        scanf("%s",code);
			for(i=0;i<C;i++){
            if(strcmp(p[i].code,code)==0){
                printf("---------------------------------\n");
                printf("nom        prix       prix TTC \n");
                printf("%s         %.2lf       %.2lf",p[i].nom,p[i].prix,p[i].prix*1.15);
                
            }
        }
        printf("\n\ntest :");
		  		scanf("%s",test);
			
		break;
        
        case 2 :
			printf("Entrer la quantite de produit :");
	        scanf("%d",&quantiter);
			for(i=0;i<C;i++){
            if(quantiter==p[i].quantiter){
                printf("---------------------------------\n");
                printf("nom        prix       prix TTC \n");
                printf("%s         %.2lf       %.2lf",p[i].nom,p[i].prix,p[i].prix*1.15);
                
            }
        }
        break;
        default :
        	printf("Ce choix n existe pas.");
        	
	}
	
	
	
	
}


 


//Menu

void Menu()
{
  int choix;
  while(true){
    system("cls");
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
    	switch(choix){
			
		    case 1:AjouterProduit();
		    
		    
		  
		    break;
		    case 2 :AjouterPlusieursProduits ();
		    
		    
		    break;
		  
		  
		    case 3:
			 ListeProduits();
		    
		  	break;
		  	
		  	case 4 :
		  		AcheterProduit();
		  	break;
		  	case 5 :
		  		ChercherProduit();
		  		
		  	break;
		  	
		  	
		
		  	
	
	 	    default :
			return Menu();
			
		  
		  }
}
}




int main(int argc, char *argv[]) {
	
	
	Menu();
	return 0;
		      
		  
			
	}
	
