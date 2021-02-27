#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>
struct node2{
      int komsu_plaka;
      char *komsu;
      struct node2 *next;
};
struct node2 *start2=NULL;
struct node2 *q2=NULL;
struct node2 *temp2=NULL;

struct node2 *NewNode2(int plakaveri){
      struct node2 *yeni_dugum=(struct node2 *)malloc(sizeof(struct node2));
      yeni_dugum->komsu_plaka=plakaveri;
      yeni_dugum->next=NULL;
      return yeni_dugum;
};
struct node{
      int plakaveri;
      char *sehir;
      char *bolge;
      int komsu_sayisi;
      struct node *prev;
      struct node *next;
      struct node2 *next2;
};
struct node* NewNode(int plakakod,char *sehirad,char *sehirbolge,int komsu_sayi){
      struct node *Yenidugum=(struct node*)malloc(sizeof(struct node));
      Yenidugum->plakaveri=plakakod;
      Yenidugum->sehir=sehirad;
      Yenidugum->bolge=sehirbolge;
      Yenidugum->komsu_sayisi=komsu_sayi;
      Yenidugum->next=NULL;
      Yenidugum->prev=NULL;
      return Yenidugum;
};
struct node *start=NULL;//Baþlangýc dugumu
struct node *q=NULL;// baslangýc karsýlastýrma dugumu
struct node *temp=NULL;// gecýcý dugum
struct node *current=NULL;
/*struct node *AnaListedeAra(int satir_num){
       temp=start;
       if(start!=NULL){
             if(start->plakaveri==satir_num){
                return start;
             }
       }else{
           while(temp->next!=NULL){
              if(temp->next->plakaveri==satir_num){
                return temp;
              }
            temp=temp->next;
           }

       }


};*/
void satir_ayirma(char *dosyayolu){
     FILE *dosya=fopen(dosyayolu,"r");
     char *satir;
     char *kelime;
    // kelime=(char *)calloc(20,sizeof(char));
     char *pr;

     int sayac=0;
     int komsular=-1;

     int suanki_plaka;
     char * suanki_kent;

     char *suanki_bolge;

     int suanki_kom_sayisi;
     pr=(char *)malloc(100*sizeof(char));
    kelime=(char *)malloc(20*sizeof(char));
     if(!feof(dosya)){
            satir=(char *)malloc(100*sizeof(char));
        while(fgets(satir,"%s",dosya)!=NULL){

           pr=strtok(satir,"\n");
          // printf("%s\n",pr);

           if(sayac==0){
           kelime=strtok(pr,",");
           //printf("%s\n",kelime);
           sayac++;
           suanki_plaka=atoi(kelime);
           }
           if(sayac==1){
            kelime=strtok(NULL,",");
            //printf("%s\n",kelime);
            sayac++;
            suanki_kent=(char *)malloc(20*sizeof(char));
            strcpy(suanki_kent, kelime);
           }
           if(sayac==2){
            kelime=strtok(NULL,",");
           // printf("%s\n",kelime);
            sayac++;
            suanki_bolge=(char *)malloc(3*sizeof(char));
            strcpy(suanki_bolge,kelime);
           }
           while(kelime!=NULL){
            kelime=strtok(NULL,",");
            //printf("%s\n",kelime);
            komsular++;
           }
           if(kelime==NULL){
            suanki_kom_sayisi=komsular;
           // printf("%d\n",komsular);
           }
           q=NewNode(suanki_plaka,suanki_kent,suanki_bolge,suanki_kom_sayisi);

           komsular=-1;
           sayac=0;
           sonaEkle(q);
        }
     }
     fclose(dosya);
}
/*void komsu_bulma(char *dosyayolu){
     FILE *dosya=fopen(dosyayolu,"r");
     char *line;
     char *word;
     char *pr;
     char *sonraki;
     int ilgili_satir;
     int sayac=0;
     word=(char *)malloc(sizeof(char)*20);
     pr=(char *)malloc(sizeof(char)*20);

    if(!feof(dosya)){
         line=(char *)malloc(sizeof(char)*100);
        while(fgets(line,"%s",dosya)!=NULL){

            pr=strtok(line,"\n");
            //printf("%s\n",pr);

            word=strtok(pr,",");
            sayac++;
            //printf("%s\n",word);
            ilgili_satir=atoi(word);
            //printf("%d\n",ilgili_satir);

            for(int i=0;i<2;i++){
                word=strtok(NULL,",");
                sayac++;
            }


            struct node2 * ilkKomsu = malloc(sizeof(struct node2));
            struct node * suankidugum=AnaListedeAra(ilgili_satir);
            printf("%d\n",suankidugum->plakaveri);
            suankidugum->next2=ilkKomsu;

            //Burada da analistendeki o satırdaki ana şehirin
            //next2 -> ilkKomsuyu göstercek
            if(sayac==3){
                word=strtok(NULL,",");
               // printf("%s\n",word);
               ilkKomsu->komsu=(char *)malloc(sizeof(char)*15);
               strcpy(ilkKomsu->komsu,word);
              // printf("%s\n",ilkKomsu->komsu);
                 temp=NULL;
                 temp=start;
                while(temp!=NULL){
                    if(strcmp(ilkKomsu->komsu,suankidugum->sehir)==0){
                        ilkKomsu->komsu_plaka=suankidugum->plakaveri;
                       // printf("%d\n",ilkKomsu->komsu_plaka);
                    }
                   temp=temp->next;
                }

            }

            while(word!=NULL){
                word=strtok(NULL,",");

                //Burada her okunan komsuyu ilkKomsuya tek yönlü liste gibi ekleyecelsin.

            }




            sayac=0;
            }
        }
          fclose(dosya);
    }*/


void sonaEkle(struct node *n){
     if(start==NULL){
        start=n;
     }else{
        temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }

        n->prev=temp;
        temp->next=n;
     }
}
int SehirEkle(int plaka,char *ad,char *bolge,int kmsu_sayi){

    struct node * eklenecek_sehir = NewNode(plaka,ad,bolge,kmsu_sayi);
    if (start == NULL)
    {
        start = eklenecek_sehir;
    }
    else
    {
        temp=NULL;
        temp=start;

        while (temp->next != NULL)
        {
            if(strcmp(temp->sehir,eklenecek_sehir->sehir)==0 || temp->plakaveri==eklenecek_sehir->plakaveri){
                return 0;
                exit(1);
            }else
            temp = temp->next;

        }
        eklenecek_sehir->prev = temp;
        temp->next = eklenecek_sehir;
        return 1;
    }
}

void yazdir(){

      temp=start;
      while(temp!=NULL){
        printf("--------------------\n");
        printf("- Plaka KODU: %d ---\n",temp->plakaveri);
        printf("- Kent Isim: %s ----\n",temp->sehir);
        printf("- Kent Bolge: %s ---\n",temp->bolge);
        printf("- Komsu Sayisi: %d -\n",temp->komsu_sayisi);
        printf("--------------------\n");

        temp=temp->next;
      }
}
int ListedeARA(){
    char *aranan_kent;
    aranan_kent=(char *)malloc(15*sizeof(char));
    printf("Aranan sehri giriniz:\n");
    scanf("%s",aranan_kent);
    int kont;
    current=NULL;
    current=start;
    if(current!=NULL){
        while(current->next!=NULL){
            if(strcmp(current->sehir,aranan_kent)==0){
                kont=1;

        printf("Aranan sehir %s bulundu.\n",current->sehir);
        printf("Bilgileri:\n");
        printf("Sehir plaka kodu:%d\n",current->plakaveri);
        printf("Sehir adi:%s\n",current->sehir);
        printf("Sehir bolgesi:%s\n",current->bolge);
        printf("Sehrin Komsu Sayisi:%d\n",current->komsu_sayisi);


            }else{
                kont=0;
            }
            current=current->next;
        }
    }

          if(kont==1){
            return 1;
           }else{
            return 0;
           }



}
int ListedePlakaARA(){
    int kod;
    int kont;
    printf("Aranan plakayı giriniz:\n");
    scanf("%d",&kod);
    current=start;
    if(current!=NULL){
        while(current->next!=NULL){
            if(current->plakaveri==kod){
                kont=1;
        printf("Aranan plaka %d bulundu.\n",current->plakaveri);
        printf("Bilgileri:\n");
        printf("Sehir plaka kodu:%d\n",current->plakaveri);
        printf("Sehir adi:%s\n",current->sehir);
        printf("Sehir bolgesi:%s\n",current->bolge);
        printf("Sehrin Komsu Sayisi:%d\n",current->komsu_sayisi);
            }else{
                kont=0;
            }
            current=current->next;
        }
    }

           if(kont==1){
            return 1;
           }else{
            return 0;
           }


}
void BolgedeAra(){
     char *aranan_bolge;
     aranan_bolge=(char*)malloc(2*sizeof(char));
     printf("Hangi Bolgeyi gormek istersiniz:\n");
     printf("Lutfen MA-AK-DA-GA-KA-EG-IA Bolgelerinden birini giriniz!\n");
     scanf("%s",aranan_bolge);


     current=NULL;
     current=start;
     printf("Sehirler\n");
      if(current!=NULL){
        while(current->next!=NULL){
            if(strcmp(current->bolge,aranan_bolge)==0){

        printf("Bilgileri:\n");
        printf("Sehir plaka kodu:%d\n",current->plakaveri);
        printf("Sehir adi:%s\n",current->sehir);
        printf("Sehir bolgesi:%s\n",current->bolge);
        printf("Sehrin Komsu Sayisi:%d\n",current->komsu_sayisi);


            }
            current=current->next;
    }

            }



}
void KomsuSayisiAra(){

    int kom;

     printf("Lutfen komsu sayisi giriniz:/n");
     scanf("%d",&kom);


     current=NULL;
     current=start;
     printf("Sehirler\n");
      if(current!=NULL){
        while(current->next!=NULL){
            if(current->komsu_sayisi==kom){



        printf("Bilgileri:\n");
        printf("Sehir plaka kodu:%d\n",current->plakaveri);
        printf("Sehir adi:%s\n",current->sehir);
        printf("Sehir bolgesi:%s\n",current->bolge);
        printf("Sehrin Komsu Sayisi:%d\n",current->komsu_sayisi);


            }
               current=current->next;
    }

            }



}
void CiktiOlustur(char *dosyayolu2){
    FILE *dosya=fopen(dosyayolu2,"w");
     current=NULL;
     current=start;
      while(current!=NULL){
        fprintf(dosya,"--------------------\n");
        fprintf(dosya,"- Plaka KODU: %d ---\n",current->plakaveri);
        fprintf(dosya,"- Kent Isim: %s ----\n",current->sehir);
        fprintf(dosya,"- Kent Bolge: %s ---\n",current->bolge);
        fprintf(dosya,"- Komsu Sayisi: %d -\n",current->komsu_sayisi);
        fprintf(dosya,"--------------------\n");

        current=current->next;
      }
      fclose(dosya);
}
void AradanSehirSil(int silinen){
   current=NULL;
   current= start;
    int varmi = 0;

    while (current->next != NULL)
    {
        if (current->plakaveri == silinen)
        {
            varmi = 1;
            break;
        }

        current=current->next;
    }

    if(varmi == 0)
    {
        printf("Aradiginiz dugum listede bulunmuyor ... \n");

    }

    struct node* sonraki = current->next;
    struct node* onceki = current->prev;
    free(current);
    onceki->next = sonraki;
    sonraki->prev = onceki;

}
void BastanSehirSil()
{
    if (start==NULL)
    {
        printf("Liste bosalmıs!\n");

    }

    if (start->next == NULL)
    {
        free(start);
        start = NULL;

    }

    struct node* ikinci = start->next;
    free(start);
    ikinci->prev = NULL;
    start = ikinci;
}
void SondanSehirSil()
{
    if (start == NULL)
    {
        printf("\n Liste zaten bos ....");

    }

    if (start->next == NULL)
    {
       BastanSehirSil();

    }
    current=NULL;
    current= start;
    while (current->next != NULL)
    {
        current= current->next;
    }

    struct node* onceki1= current->prev;
    free(current);
    onceki1->next = NULL;
}
int main()
{
   char dosya_yolu[100]="sehirler.txt.txt";
   char dosya_yolu2[100]="cikti.txt";
   satir_ayirma(dosya_yolu);
   //komsu_bulma(dosya_yolu);
   char *eklenensehir,*eklenenbolge,*aranan_kent;

   aranan_kent=(char *)malloc(15*sizeof(char));
   eklenensehir=(char *)malloc(20*sizeof(char));
   eklenenbolge=(char *)malloc(2*sizeof(char));
   int silinecek;
   int eklenenplaka,eklenenkomsusayisi;
   int res,res1,res2;
   int kod;
    int choose,choose2;
    int secim;
    while(1){
        printf("Bir islem seciniz:\n");
        printf("1- Dosyadan okunan bilgileri goster\n");
        printf("2- Sehir ekleyin\n");
        printf("3- Sehir veya Plaka Kodu ile arama\n");
        printf("4- Sehir silme\n");
        printf("5- Bolgeye gore arama\n");
        printf("6- Komsu Sayisina gore arama\n");
        printf("7- Cikti olusturma\n");
        printf("Seciminiz:");
        scanf("%d",&secim);
        switch(secim){
           case 1:
            printf("Okunan bilgiler yazdiriliyor...\n");
            yazdir();
                break;

           case 2:
            printf("Eklenecek sehirin plaka kodu:\n");
            scanf("%d",&eklenenplaka);
            printf("Eklemek istediğiniz sehrin adı:\n");
            scanf("%s",eklenensehir);
            printf("Eklemek istediginiz sehrin bolgesi:\n");
            scanf("%s",eklenenbolge);
            printf("Eklenecek istediğiniz sehrin komsu sayisi:\n");
            scanf("%d",&eklenenkomsusayisi);


           res=SehirEkle(eklenenplaka,eklenensehir,eklenenbolge,eklenenkomsusayisi);
            if(res==0){
                printf("Sehir eklenemedi.\n");
            }else{
                printf("Sehir eklendi.\n");
            }
                  break;

           case 3:

                printf("1-Sehir ile arama\n");
                printf("2-Plaka kodu ile arama\n");
                printf("Seciminiz:");
                scanf("%d",&choose);
                switch(choose){
                 case 1:
                    res1=ListedeARA();
                    if(res1==1){
                        printf("Gösterildi.\n");
                    }
                    else if(res1==0){
                        int kosul;
                        printf("Aradiginiz sehir yok, eklemek ister misiniz? \n");
                        printf("Evet ise - 1 e basin.\n");
                        printf("Hayir ise - 2 e basin.\n");
                        printf("Seciminiz:");
                        scanf("%d",&kosul);

                    if(kosul==1){

            printf("Eklenecek sehirin plaka kodu:\n");
            scanf("%d",&eklenenplaka);
            printf("Eklemek istediğiniz sehrin adı:\n");
            scanf("%s",eklenensehir);
            printf("Eklemek istediginiz sehrin bolgesi:\n");
            scanf("%s",eklenenbolge);
            printf("Eklenecek istediğiniz sehrin komsu sayisi:\n");
            scanf("%d",&eklenenkomsusayisi);


           res=SehirEkle(eklenenplaka,eklenensehir,eklenenbolge,eklenenkomsusayisi);
            if(res==0){
                printf("Sehir eklenemedi.\n");
            }else{
                printf("Sehir eklendi.\n");
            }
                        }else if(kosul==2){
                            break;
                        }
                    }

                 case 2:
                     res2=ListedePlakaARA();
                      if(res2==1){
                        printf("Gösterildi.\n");
                    }
                    else if(res2==0){
                        int kosul1;
                        printf("Aradiginiz sehir yok, eklemek ister misiniz? \n");
                        printf("Evet ise - 1 e basin.\n");
                        printf("Hayir ise - 2 e basin.\n");
                        printf("Seciminiz:");
                        scanf("%d",&kosul1);

                    if(kosul1==1){

            printf("Eklenecek sehirin plaka kodu:\n");
            scanf("%d",&eklenenplaka);
            printf("Eklemek istediğiniz sehrin adı:\n");
            scanf("%s",eklenensehir);
            printf("Eklemek istediginiz sehrin bolgesi:\n");
            scanf("%s",eklenenbolge);
            printf("Eklenecek istediğiniz sehrin komsu sayisi:\n");
            scanf("%d",&eklenenkomsusayisi);


           res=SehirEkle(eklenenplaka,eklenensehir,eklenenbolge,eklenenkomsusayisi);
            if(res==0){
                printf("Sehir eklenemedi.\n");
            }else{
                printf("Sehir eklendi.\n");
            }
                        }else if(kosul1==2){
                            break;
                        }
                    }

                }
               break;
                 case 4:
                     printf("Bir silme islemi secin");
                     printf("1-Bastan sil\n");
                     printf("2-Sondan sil\n");
                     printf("3-Aradan sil\n");
                     scanf("%d",&choose2);
                     switch(choose2){
                     case 1:
                        BastanSehirSil();
                        break;
                     case 2:
                        SondanSehirSil();
                        break;
                     case 3:
                     printf("Silinecek sehrin plaka kodunu giriniz:\n");
                     scanf("%d",&silinecek);
                     AradanSehirSil(silinecek);
                     break;
                     }
                    break;
                 case 5:
                     BolgedeAra();
                    break;
                 case 6:
                     KomsuSayisiAra();
                     break;
                 case 7:
                      CiktiOlustur(dosya_yolu2);
                      printf("Cikti olusturuldu.Lutfen klasoru kontrol edin.\n");
                     break;
        }


    }
    return 0;
}

