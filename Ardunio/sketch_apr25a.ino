int btn1, btn2,btn3,btn4,btn5,btn6;
int beslik=8,onluk=6,yirmilik=4,ellilik=2,yuzluk=1,toplamAtilanPara=0,atilanBeslik=0,atilanOnluk=0,atilanYirmilik=0,atilanEllilik=0,atilanYuzluk=0,toplamTutar=0;
int verilecekBeslik=0,verilecekOnluk=0,verilecekYirmilik=0,verilecekEllilik=0,verilecekYuzluk=0,paraUstu=0;
bool paraYuklendimi=false;
bool secenekleriYaz=true;
struct hizmet{
  char hizmetID;
  String hizmetAdi;
  int kalanHizmetAdet;
  int hizmetFiyat;
  int hizmetSecimAdet;
  };

struct hizmet hizmet1,hizmet2,hizmet3,hizmet4;

void reset(){
      digitalWrite(9,HIGH);
      hizmet1.hizmetSecimAdet=0;
      hizmet2.hizmetSecimAdet=0;
      hizmet3.hizmetSecimAdet=0;
      hizmet4.hizmetSecimAdet=0;
      delay(1000);
      Serial.println("Resetlendi.");
      delay(100);
      Serial.println("Para iade ediliyor.");
      Serial.print("Iade edilen beslik sayisi: ");
      Serial.println(atilanBeslik);
      Serial.print("Iade edilen onluk sayisi: ");
      Serial.println(atilanOnluk);
      Serial.print("Iade edilen yirmilik sayisi: ");
      Serial.println(atilanYirmilik);
      Serial.print("Iade edilen ellilik sayisi: ");
      Serial.println(atilanEllilik);
      Serial.print("Iade edilen yuzluk sayisi: ");
      Serial.println(atilanYuzluk);
      beslik-=atilanBeslik;
      onluk-=atilanOnluk;
      yirmilik-=atilanYirmilik;
      ellilik-=atilanEllilik;
      yuzluk-=atilanYuzluk;
      atilanBeslik=0;
      atilanOnluk=0;
      atilanYirmilik=0;
      atilanEllilik=0;
      atilanYuzluk=0;
      paraYuklendimi=false;
      secenekleriYaz=true;
      toplamAtilanPara=0;
      toplamTutar=0;
      digitalWrite(9,LOW);
      delay(1000);
  }
  
void setup() {
  hizmet1.hizmetID='1';
  hizmet1.hizmetAdi="Kopukleme";
  hizmet1.kalanHizmetAdet=15;
  hizmet1.hizmetFiyat=30;
  hizmet1.hizmetSecimAdet=0;

  hizmet2.hizmetID='2';
  hizmet2.hizmetAdi="Yikama";
  hizmet2.kalanHizmetAdet=10;
  hizmet2.hizmetFiyat=50;
  hizmet2.hizmetSecimAdet=0;

  hizmet3.hizmetID='3';
  hizmet3.hizmetAdi="Kurulama";
  hizmet3.kalanHizmetAdet=5;
  hizmet3.hizmetFiyat=100;
  hizmet3.hizmetSecimAdet=0;

  hizmet4.hizmetID='4';
  hizmet4.hizmetAdi="Cilalama";
  hizmet4.kalanHizmetAdet=50;
  hizmet4.hizmetFiyat=20;
  hizmet4.hizmetSecimAdet=0;
  
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  if(!paraYuklendimi)
  {
    if(secenekleriYaz)
    {
        Serial.println("1.Buton: 5 TL");
        Serial.println("2.Buton: 10 TL");
        Serial.println("3.Buton: 20 TL");
        Serial.println("4.Buton: 50 TL");
        Serial.println("5.Buton: 100 TL");
        Serial.println("6.Buton: Bitis");
        Serial.println();
        secenekleriYaz=false;
    }
    
    btn1=digitalRead(2);
    if(btn1==HIGH){
      atilanBeslik=atilanBeslik+1;
      Serial.println("5 tl eklendi.");
      toplamAtilanPara+=5;
      delay(1000);
    }
  
    btn2=digitalRead(3);
    if(btn2==HIGH){
      atilanOnluk=atilanOnluk+1;
      Serial.println("10 tl eklendi.");
      toplamAtilanPara+=10;
      delay(1000);
    }
     
    btn3=digitalRead(4);
    if(btn3==HIGH){
      atilanYirmilik=atilanYirmilik+1;
      Serial.println("20 tl eklendi.");
      toplamAtilanPara+=20;
      delay(1000);
    }
  
    btn4=digitalRead(5);
    if(btn4==HIGH){
      atilanEllilik=atilanEllilik+1;
      Serial.println("50 tl eklendi.");
      toplamAtilanPara+=50;
      delay(1000);
    }
  
    btn5=digitalRead(6);
    if(btn5==HIGH){
      atilanYuzluk=atilanYuzluk+1;
      Serial.println("100 tl eklendi.");
      toplamAtilanPara+=100;
      delay(1000);
    }
    btn6=digitalRead(7);
    if(btn6 == HIGH and toplamAtilanPara>0)
    {
      beslik = beslik + atilanBeslik;
      onluk = onluk + atilanOnluk;
      yirmilik = yirmilik + atilanYirmilik;
      ellilik = ellilik + atilanEllilik;
      yuzluk = yuzluk + atilanYuzluk;
      Serial.print("Kasadaki Beslik: ");
      Serial.println(beslik);
      Serial.print("Kasadaki Onluk: ");
      Serial.println(onluk);
      Serial.print("Kasadaki Yirmilik: ");
      Serial.println(yirmilik);
      Serial.print("Kasadaki Ellilik: ");
      Serial.println(ellilik);
      Serial.print("Kasadaki Yuzluk: ");
      Serial.println(yuzluk);
      paraYuklendimi=true;
      secenekleriYaz=true;
      delay(2000);
      Serial.println();
      Serial.println();
    }
  }
  else
  {
    if(secenekleriYaz){
      Serial.println("1."+hizmet1.hizmetAdi);
      Serial.println("2."+hizmet2.hizmetAdi);
      Serial.println("3."+hizmet3.hizmetAdi);
      Serial.println("4."+hizmet4.hizmetAdi);
      Serial.println("5.Bitis");
      Serial.println("6.Reset");
      secenekleriYaz=false;
      }

     btn1=digitalRead(2);
     if(btn1==HIGH and hizmet1.hizmetSecimAdet<hizmet1.kalanHizmetAdet and toplamTutar<toplamAtilanPara){
      if(toplamTutar+hizmet1.hizmetFiyat<=toplamAtilanPara){
        toplamTutar+=hizmet1.hizmetFiyat;
        hizmet1.hizmetSecimAdet+=1;
        Serial.println("Kopukleme secildi.");
        Serial.print("Toplam: ");
        Serial.println(toplamTutar);
      }
      delay(1000);
    }
  
    btn2=digitalRead(3);
    if(btn2==HIGH and hizmet2.hizmetSecimAdet<hizmet2.kalanHizmetAdet and toplamTutar<toplamAtilanPara){
      if(toplamTutar+hizmet2.hizmetFiyat<=toplamAtilanPara){
        toplamTutar+=hizmet2.hizmetFiyat;
        hizmet2.hizmetSecimAdet+=1;
        Serial.println("Yikanma secildi.");
        Serial.print("Toplam: ");
        Serial.println(toplamTutar);
      }
      delay(1000);
    }
     
    btn3=digitalRead(4);
    if(btn3==HIGH and hizmet3.hizmetSecimAdet<hizmet3.kalanHizmetAdet and toplamTutar<toplamAtilanPara){
      if(toplamTutar+hizmet3.hizmetFiyat<=toplamAtilanPara){
        toplamTutar+=hizmet3.hizmetFiyat;
        hizmet3.hizmetSecimAdet+=1;
        Serial.println("Kurulama secildi.");
        Serial.print("Toplam: ");
        Serial.println(toplamTutar);
      }
      delay(1000);
    }
  
    btn4=digitalRead(5);
    if(btn4==HIGH and hizmet4.hizmetSecimAdet<hizmet4.kalanHizmetAdet and toplamTutar<toplamAtilanPara){
      if(toplamTutar+hizmet4.hizmetFiyat<=toplamAtilanPara){
        toplamTutar+=hizmet4.hizmetFiyat;
        hizmet4.hizmetSecimAdet+=1;
        Serial.println("Cilalama secildi.");
        Serial.print("Toplam: ");
        Serial.println(toplamTutar);
      }
      delay(1000);
    }
  
    btn5=digitalRead(6);
    if(btn5==HIGH){
      if(random(1,5)==2){
        Serial.println("Para sikisti.");
        reset();
        }
        else
        {
          digitalWrite(8,HIGH);
          delay(1000);
          Serial.println("Tum islemler uygulandi.");
          hizmet1.kalanHizmetAdet-=hizmet1.hizmetSecimAdet;
          hizmet2.kalanHizmetAdet-=hizmet2.hizmetSecimAdet;
          hizmet3.kalanHizmetAdet-=hizmet3.hizmetSecimAdet;
          hizmet4.kalanHizmetAdet-=hizmet4.hizmetSecimAdet;
          hizmet1.hizmetSecimAdet=0;
          hizmet2.hizmetSecimAdet=0;
          hizmet3.hizmetSecimAdet=0;
          hizmet4.hizmetSecimAdet=0;
          Serial.print("Hizmet 1 Adet: ");
          Serial.println(hizmet1.kalanHizmetAdet);
          Serial.print("Hizmet 2 Adet: ");
          Serial.println(hizmet2.kalanHizmetAdet);
          Serial.print("Hizmet 3 Adet: ");
          Serial.println(hizmet3.kalanHizmetAdet);
          Serial.print("Hizmet 4 Adet: ");
          Serial.println(hizmet4.kalanHizmetAdet);
          paraUstu=toplamAtilanPara-toplamTutar;
          Serial.print("Para ustu: ");
          Serial.println(paraUstu);
          
          if(paraUstu/100<=yuzluk)
          {
            verilecekYuzluk=int(paraUstu/100);
            yuzluk-=verilecekYuzluk;
            paraUstu-=verilecekYuzluk*100;
          }
          else{
              verilecekYuzluk=yuzluk;
              paraUstu-=yuzluk*100;
              yuzluk=0;
          }
          if(paraUstu/50<=ellilik)
          {
            verilecekEllilik=int(paraUstu/50);
            ellilik-=verilecekEllilik;
            paraUstu-=verilecekEllilik*50;
          }
          else{
              verilecekEllilik=ellilik;
              paraUstu-=ellilik*50;
              ellilik=0;
          }
          if(paraUstu/20<=yirmilik)
          {
             verilecekYirmilik=int(paraUstu/20);
             yirmilik-=verilecekYirmilik;
             paraUstu-=verilecekYirmilik*20;
          }
          else{
                verilecekYirmilik=yirmilik;
                paraUstu-=yirmilik*20;
                yirmilik=0;
          }
          if(paraUstu/10<=onluk)
          {
              verilecekOnluk=int(paraUstu/10);
              onluk-=verilecekOnluk;
              paraUstu-=verilecekOnluk*10;
          }
          else{
              verilecekOnluk=onluk;
              paraUstu-=onluk*10;
              onluk=0;
          }
          if(paraUstu/5<=beslik){
              verilecekBeslik=int(paraUstu/5);
              beslik-=verilecekBeslik;
              paraUstu-=verilecekBeslik*5;
          }
          else{
              verilecekBeslik=beslik;
              paraUstu-=beslik*5;
              beslik=0;
          }
          if(paraUstu>0)
            {
                beslik+=verilecekBeslik-atilanBeslik;
                onluk+=verilecekOnluk-atilanOnluk;
                yirmilik+=verilecekYirmilik-atilanYirmilik;
                ellilik+=verilecekEllilik-atilanEllilik;
                yuzluk+=verilecekYuzluk-atilanYuzluk;
                verilecekBeslik=atilanBeslik;
                verilecekOnluk=atilanOnluk;
                verilecekYirmilik=atilanYirmilik;
                verilecekEllilik=atilanEllilik;
                verilecekYuzluk=atilanYuzluk;
                Serial.println("Para iadesi yapiliyor..");
            }
              atilanBeslik=0;
              atilanOnluk=0;
              atilanYirmilik=0;
              atilanEllilik=0;
              atilanYuzluk=0;
              Serial.print("Verilecek beslik sayisi: ");
              Serial.println(verilecekBeslik);
              Serial.print("Verilecek onluk sayisi: ");
              Serial.println(verilecekOnluk);
              Serial.print("Verilecek yirmilik sayisi: ");
              Serial.println(verilecekYirmilik);
              Serial.print("Verilecek ellilik sayisi: ");
              Serial.println(verilecekEllilik);
              Serial.print("Verilecek yuzluk sayisi: ");
              Serial.println(verilecekYuzluk);
              digitalWrite(8,LOW);
          }          
          verilecekBeslik=0;
          verilecekOnluk=0;
          verilecekYirmilik=0;
          verilecekEllilik=0;
          verilecekYuzluk=0;
          delay(1000);
          toplamAtilanPara=0;
          toplamTutar=0;
          paraYuklendimi=false;
          secenekleriYaz=true;
          Serial.println();
          Serial.println();
    }  
    
    btn6=digitalRead(7);
    if(btn6==HIGH){
      reset();
      Serial.println();
      Serial.println();
    }  
  }
}
