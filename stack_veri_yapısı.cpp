#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
typedef struct islem_stack{
	int indis;
	int eleman[N];
}stack;
stack yeni; 

typedef struct geri_stack{
	char islem[10];
	struct geri_stack *sonraki;
}g_stack;

char* pop(g_stack *ilk);
void ekle(int sayi);
int sil();
int cikar();
int main(){
	int secim=1,sayi,silinen,yaz;
	g_stack *ilk=NULL,*iter,*gecici;
	char *top;
	yeni.indis=-1;
	while(secim){
		if(ilk==NULL){
			ilk=(g_stack*)malloc(sizeof(g_stack));
			printf("komut giriniz(buyuk harf kullanarak ve bosluksuz yaziniz {EKLE,SIL,GERIAL,YAZDIR}):"); scanf("%s",&ilk->islem);
			ilk->sonraki=NULL;
			gecici=ilk;
		}
		else{
			iter=ilk;
			while(iter->sonraki!=NULL){
				iter=iter->sonraki;
			}
			g_stack *temp=(g_stack*)malloc(sizeof(g_stack));
			printf("komut giriniz:"); scanf("%s",&temp->islem);
			temp->sonraki=NULL;
			iter->sonraki=temp;
			gecici=temp;
		}
		if(strcmp(gecici->islem,"EKLE")==0){
			printf("sayi giriniz:");
			scanf("%d",&sayi);
			ekle(sayi);
			printf("DEGER EKLENDI.\n");
		}
		else if(strcmp(gecici->islem,"SIL")==0){
			silinen=sil();
			printf("%d SILINDI.\n",silinen);
		}
		else if(strcmp(gecici->islem,"YAZDIR")==0){
			int p=yeni.indis;
			
			if(yeni.indis==-1){
	    	    printf("yigin bos..\n");
	    	    g_stack *ilk=NULL;
	    	

	        }
			else{
				printf("EKRANA YAZDIRILDI=");
			    while(yeni.indis!=-1){
				    yaz=cikar();
			        printf("%d-",yaz);
			    }
			}
			yeni.indis=p;
			printf("\n");
		}
		else if(strcmp(gecici->islem,"GERIAL")==0){
			top=pop(ilk);
			while(strcmp(top,"YAZDIR")==0 || strcmp(top,"GERIAL")==0){
				top=pop(ilk);
			}
			
			if(strcmp(top,"EKLE")==0){
				sayi=sil();
				printf("%d EKLEME ISLEMI GERI ALINDI.\n",sayi);
			}
			if(strcmp(top,"SIL")==0){
				ekle(silinen);
				printf("%d SILINME ISLEMI GERI ALINDI.\n",silinen);
			}
		}
		else{
			printf("hatali komut girisi..\n");
			top=pop(ilk);
		}
		printf("devam etmek icin 1'e basiniz.");scanf("%d",&secim);
	}
	

}

char* pop(g_stack *ilk){
	g_stack *iter=NULL;
	char *top;
	if(ilk->sonraki==NULL){
		strcpy(top,ilk->islem);
		free(ilk);
		return top;
	}	
	iter=ilk;
	while(iter->sonraki->sonraki!=NULL){
		iter=iter->sonraki;
    }
	g_stack *temp=iter->sonraki;
	strcpy(top,temp->islem);
	iter->sonraki=NULL;
	free(temp);
	return top;
	
}
void ekle(int sayi){
	yeni.indis++;
	if(yeni.indis>=100){
		printf("yigin dolu..\n");
	}
    else{
		yeni.eleman[yeni.indis]=sayi;

	}
	
}
int sil(){
	int a;
	a=yeni.eleman[yeni.indis];
	yeni.eleman[yeni.indis]=NULL;
	yeni.indis--;
	return a;
}

int cikar(){
	int son;
		son=yeni.eleman[yeni.indis];
		yeni.indis--;
		return son;
	
}
