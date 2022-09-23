#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//STRUCTURE PRODUITS
struct produits{
	int code;
	char nom[10];
	int quantiter;
	float prix ;
};
//TABLE PRODUITS
struct produits p[100];


//contour table

int C=0;


//STRUCTURE PRODUITSACHATS
struct ProduitAchat{
	int code;
	char nom[10];
	int quantiter;
	float prix ;
	float prixtotal ;
};

//TABLE ACHAT

struct ProduitAchat achat[100];

//CONTOUR ACHAT

int ContAchat=0;

//VARIABLE GLOBAL
int i;

char test[10];

int quantiterAchat;


//FONCTION D AJOUTE
void AjouterProduit(){
	

		printf("Entrer le nom du produit: \n");
		scanf("%s",p[C].nom);
		printf("Entrer le code du produit: \n");
		scanf("%d",&(p[C].code));
		printf("Entrer la quantite du produit: \n");
		scanf("%d",&(p[C].quantiter));
		printf("Entrer le prix du produit: \n");
		scanf("%f",&(p[C].prix));
		C++;
	
	
	
	
	
}
//FONCTION DE PLUSIEURS AJOUTE
void AjouterPlusieursProduits (){
    int NombreProduits,i;
    printf(" Entrer le nombre de produit:\n");
    scanf("%d",&NombreProduits);
   
    for(i=0;i<NombreProduits;i++){
        AjouterProduit();
    }
    
}

// FOCTION LISTE PRODUITS


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

//ORDRE ALPHABETOQUE
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
    printf("nom        prix       prix TTC       Quantiter\n");
    for(i=0;i<C;i++){
    	printf("%s      %.2f       %.2f     %d\n",p[i].nom,p[i].prix,p[i].prix*1.15,p[i].quantiter);
	}
		
				
	}

	
	
	
	
//ORDRE PRIX	


void OrdrePrix(){
	int i,j;
	struct produits z;
	
	for(i=C;i>=0;i--){
		for(j=i-1;j>=0;j--){
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
    	printf("%s      %.2f       %.2f      %d\n",p[i].nom,p[i].prix,p[i].prix*1.15,p[i].quantiter);
	}
	
}

// ACHETER PRODUIT
void AcheterProduit(){
	 
    int code;
    int i;
    
//    ListeProduits();
    
    
    
   printf("entrer le code de produit que vous voulez achter:\n") ;
   scanf(" %d",&code);
      
      
    for(i=0;i<C;i++){
        if(p[i].code==code){
         printf("entrer la quantite de produit:\n");
         scanf("%d",&quantiterAchat);
         if(quantiterAchat<=p[i].quantiter){
         	p[i].quantiter-=quantiterAchat;
            printf("Achat reussite \n");
               printf("la quantite disponible en stock maintenant : %d \n ",p[i].quantiter);
               achat[ContAchat].code=p[i].code;
               strcpy(achat[ContAchat].nom,p[i].nom);
               achat[ContAchat].quantiter=quantiterAchat;
               achat[ContAchat].prix=p[i].prix;
               
               achat[ContAchat].prixtotal=quantiterAchat*p[i].prix*1.15 ;
               
               ContAchat++;
               

			   
               
		 }else{
		 	printf("cette quantite n est pas disponible .");
		 }
            
        }else {
        	printf("\n ce produit n'existe pas....!!!");
		}break;
		
        
     
		}
		
   }



//CHERCHER PRODUIT

void ChercherProduit(){
	int chercheProduit,quantiter,i;
	int code;
	printf("1-Chercher par code \n");
	printf("2-Chercher par quantiter\n");
	printf("3-Chercher par etat de stock \n ");
	printf("-Veuillez entrer votre choix :");
	
	scanf("%d",&chercheProduit);
	
	
	switch(chercheProduit){
		case 1 :
			printf("Entrer le code de produit :");
	        scanf("%d",&code); 
			
			for(i=0;i<C;i++){
			printf("---------------------------------\n");
            printf("nom        prix       prix TTC \n");
            if(p[i].code==code){ 
                printf("%s         %.2f       %.2f",p[i].nom,p[i].prix,p[i].prix*1.15);
              
            }
            
   
              
        }
			
		break;
        
        case 2 :
			printf("Entrer la quantite de produit :");
	        scanf("%d",&quantiter);
			for(i=0;i<C;i++){
            if(quantiter==p[i].quantiter){
                printf("---------------------------------\n");
                printf("nom        prix       prix TTC \n");
                printf("%s         %.2f       %.2f",p[i].nom,p[i].prix,p[i].prix*1.15);
                
            }
           
            
        }
        break;
        case 3:

           for( i=0;i<C;i++){
           	printf("*************************************\n");
            printf("nom     prix       prix TTC     \n");
            if(p[i].quantiter<3){
            
            printf("%s      %.2f          %.2f     \n",p[i].nom,p[i].prix,p[i].prix*1.15);
            
            }
        
           }
        break;
		default :
        	printf("Ce choix n existe pas.");
        	
	}
	
	 printf("\n Entrer returne pour retourner au menu ");
		    scanf("%s",test);
	
	
}
//ALIMENTER STOCK

void AlimenterStock(){
	
    int code;
    int quantiter;
    printf("Veuillez entrer le code de produit:\n") ;
    scanf(" %d",&code);
    printf("entrer la quantite:\n");
    scanf("%d",&quantiter);
    
    int i,j=0;
    for(i=0;i<C;i++){
        if(p[i].code==code){
            p[i].quantiter+=quantiter;
            printf("stock alimente\n");
            j=1; 
			        
       }
    }
  
 if(j==0){
    printf("le stock non alimente\n");
}
printf("\n Entrer returne pour retourner au menu ");
		    scanf("%s",test);



}

//SUPPRIMER STOCK
void SupprimerStock(){
	int code;
	int i,j;
	
	printf("Entrer le code de produit que vous voulez supprimer :");
	scanf("%d",&code);
	for(i=0;i<C;i++){
		if(p[i].code==code){
			for(j=i;j<C;j++){
				
			 	p[j]=p[j+1];	
				
			}
			C--;
			printf("\n suppression reussite.	\n");
			break;
				
		}else{
			printf("\n Ce produit n est pas disponible.");
			break;
		}
		
	}
	
	
}


//STATISTIQUE VENTE

void StatistiqueVente(){
	float min ;
	float max ;
	float prixtotal ;
	float moyenne ;
	int totalquantite=0 ;
	min=achat[0].prix*1.15;
	max=achat[0].prix*1.15;
	prixtotal=0;
	moyenne=0;
	
	for(i=0;i<ContAchat;i++){
		prixtotal=prixtotal+achat[i].prixtotal;
		totalquantite=totalquantite+achat[ContAchat].quantiter;
		if(achat[i].prixtotal>max){
			achat[i].prixtotal=max;
			
		}
		if(achat[i].prixtotal<min){
			achat[i].prixtotal=min ;
		}
		moyenne=moyenne+(prixtotal/totalquantite) ;
	}
	

	printf("1-Afficher le total des prix des produits vendus en journée courante : %f \n",prixtotal);
	printf("2-Afficher la moyenne des prix des produits vendus en journée courante : %f \n",moyenne);
	printf("3-Afficher le Max des prix des produits vendus en journée courante  : %.2f\n",max);
	printf("4-Afficher le Min des prix des produits vendus en journée courante  : %.2f\n",min);
	
	
	
}



 


//Menu

void Menu()
{
  int choix;
  while(true){
  	
    
    printf("**************Menu*****************\n");
    printf("1-Ajouter un nouveau produit.\n");
    printf("2-Ajouter plusieurs nouveaux produits.\n");
    printf("3-Afficher la liste des produits.\n");
    printf("4-Acheter des produits.\n");
    printf("5-Chercher les produits.\n");;
    printf("6-Alimenter le stock.\n");
    printf("7-Supprimer les produits.\n");
    printf("8-Statistique de vente\n");
    
    printf("\nEntrer votre choix :\n");
    scanf("%d", &choix);
    system("cls");
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
		  	case 6 :
		  		
		  		AlimenterStock();
		  	break;
		  	case 7 :
		  		SupprimerStock();
		  	break ;
		  	case 8 :
		  		 	

				   StatistiqueVente();
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
	
