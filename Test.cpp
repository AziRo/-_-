#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std; 

const int N=10;

void indocp(int a){
     ofstream out("����.txt",ios::app);
     out << "\n" << a;
     out.close();
     }
     
void indocm(int* a){
     ofstream out("����.txt",ios::app);
     out << a;
     out.close();
     }

//���������� ��� ������ �����;  
int pscore=0,bscore=0,tscore=0; 
 
//������� �������� ���� ����� ����;  
void score(int n=0){
if(n==1){
setcolor(14);
settextstyle(8,0,2);
outtextxy(520,80,"score:");
outtextxy(482,130,"Player One: ");
bgiout <<pscore;
outstreamxy(617,130);
outtextxy(482,180,"Player Two: ");
bgiout <<bscore;
outstreamxy(617,180);
outtextxy(480,230,"Drawn Game: ");
bgiout <<tscore;
outstreamxy(615,230);         
} 
else{    
setcolor(14);
settextstyle(8,0,2);
outtextxy(520,80,"score:");
outtextxy(492,130,"Game Won: ");
bgiout <<pscore;
outstreamxy(600,130);
outtextxy(485,180,"Game Lose: ");
bgiout <<bscore;
outstreamxy(605,180);
outtextxy(480,230,"Drawn Game: ");
bgiout <<tscore;
outstreamxy(615,230);      
}  
}
     
//���� ����;
void grid(){
   initwindow(705,405);
   setfillstyle(1,15);
   floodfill(0,0,1);
   setcolor(0);
   setfillstyle(1,0);
   bar(133,6,139,399);
   bar(266,6,272,399);
   bar(6,133,399,139);
   bar(6,266,399,272);
   bar(0,0,405,6);
   bar(399,0,405,405);
   bar(405,399,0,405);
   bar(0,0,6,405);
}

//������� ��������� ��������;
void  cross(int a){
        if(a==1){line(6,6,133,133); line(133,6,6,133); return;}
        if(a==2){line(139,6,266,133); line(266,6,139,133); return;}
        if(a==3){line(272,6,399,133); line(399,6,272,133); return;}
        if(a==4){line(6,139,133,266); line(133,139,6,266); return;}
        if(a==5){line(139,139,266,266); line(266,139,139,266); return;}
        if(a==6){line(272,139,399,266); line(399,139,272,266); return;}
        if(a==7){line(6,272,133,399); line(133,272,6,399); return;}
        if(a==8){line(139,272,266,399); line(266,272,139,399); return;}
        if(a==9){line(272,272,399,399); line(272,399,399,272); return;}     
}

//������� ��������� ������;
void zero(int a){               
         if(a==1){circle(69,69,64); return;}
         if(a==2){circle(202,69,64); return;}
         if(a==3){circle(335,69,64); return;}
         if(a==4){circle(69,202,64); return;}
         if(a==5){circle(202,202,64); return;}
         if(a==6){circle(335,202,64); return;}
         if(a==7){circle(69,335,64); return;}
         if(a==8){circle(202,335,64); return;}
         if(a==9){circle(335,335,64); return;}
}

//������ �������� ����;
void casual_play(int* a,int flag){
int i;    
 if(flag==0){    
  for(i=1;i<N;i++){                
   if(a[i]==0){a[i]=4; zero(i); break;}                  
  }
 } 
 else
  for(i=1;i<N;i++){
   if(a[i]==0){a[i]=1; cross(i); break;}                      
 }
}

//��� ������ ����! ���� ����!
void bvb(){
    int a[N],i,j,y=-68,prob=0,flag=0,sum,num=0,random,ncheck=0;
    for(i=1;i<N;i++) a[i]=0;
    score();
    setlinestyle(SOLID_LINE,2,THICK_WIDTH); 
     while(prob==0){           
         //�������� �������� �������� �� �����������;
         setcolor(2);
         if(prob==0){
          for(j=0;j<7;j+=3){     
           if((a[j+1]+a[j+2]+a[j+3])==3){
            if(j==3) y+=135; if(j==6) y+=270;                                 
            setlinestyle(1,1,5);         
            for(i=7;i<378;i+=7){delay(10); line(i,y+136,i+25,y+136);}
            bscore++; bgiout <<bscore; outstreamxy(605,180); setfillstyle(1,15);
            bar(406,275,705,330); moveto(495,280); outtext("Bot One WIN!"); prob=1;
           }
          }
         }
         if(prob==1) break;
         
         //�������� �������� �������� �� ���������;
         if(prob==0){
          for(j=0;j<3;j++){
           if((a[j+1]+a[j+4]+a[j+7])==3){
            if(j==1) y+=135; if(j==2) y+=270;
            setlinestyle(1,1,5);         
            for(i=7;i<378;i+=7){delay(10); line(y+136,i,y+136,i+25);}
            bscore++; bgiout <<bscore; outstreamxy(605,180); setfillstyle(1,15);
            bar(406,275,705,330); moveto(495,280); outtext("Bot One WIN!"); prob=1;                           
           }
          }
         }
         if(prob==1) break;
         
         //�������� �������� �������� �� ������ ���������;
         if(prob==0&&(a[1]+a[5]+a[9]==3)){ 
          setlinestyle(1,1,5);
          for(i=7;i<378;i+=7){delay(10); line(i,i,i+25,i+25);}
          bscore++; bgiout <<bscore; outstreamxy(605,180); setfillstyle(1,15);
          bar(406,275,705,330); moveto(495,280); outtext("Bot One WIN!"); prob=1;                                           
         }
         if(prob==1) break;
         
         //�������� �������� �������� �� ������ ���������;
         if(prob==0&&(a[3]+a[5]+a[7]==3)){ 
          setlinestyle(1,1,5);
          for(i=398,j=7;i>30;i-=7,j+=7){delay(10); line(i,j,i-25,j+25);}
          bscore++; bgiout <<bscore; outstreamxy(605,180); setfillstyle(1,15);
          bar(406,275,705,330); moveto(495,280); outtext("Bot One WIN!"); prob=1;                                           
         }
         if(prob==1) break;
         
         //�������� �������� ������ �� �����������;
         if(prob==0){
          for(j=0;j<7;j+=3){     
           if((a[j+1]+a[j+2]+a[j+3])==12){
            if(j==3) y+=135; if(j==6) y+=270;                                 
            setlinestyle(1,1,5);         
            for(i=7;i<378;i+=7){delay(10); line(i,y+136,i+25,y+136);}
            bscore+=1; bgiout <<bscore; outstreamxy(605,180); setfillstyle(1,15);
            bar(406,275,705,330); moveto(495,280); outtext("Bot Two WIN!"); prob=1;
           }
          }
         }
         if(prob==1) break;
         
         //�������� �������� ������ �� ���������;
         if(prob==0){
          for(j=0;j<3;j++){
           if((a[j+1]+a[j+4]+a[j+7])==12){                           
            if(j==1) y+=135; if(j==2) y+=270;
            setlinestyle(1,1,5);         
            for(i=7;i<378;i+=7){delay(10); line(y+136,i,y+136,i+25);}
            bscore+=1; bgiout <<bscore; outstreamxy(605,180);setfillstyle(1,15);
            bar(406,275,705,330); moveto(495,280); outtext("Bot Two WIN!"); prob=1;                           
           }
          }
         }
         if(prob==1) break;
         
         //�������� �������� ������ �� ������ ���������; 
         if(prob==0&&(a[1]+a[5]+a[9]==12)){ 
          setlinestyle(1,1,5);
          for(i=7;i<378;i+=7){delay(10); line(i,i,i+25,i+25);}
          bscore+=1; bgiout <<bscore; outstreamxy(605,180); setfillstyle(1,15);
          bar(406,275,705,330); moveto(495,280); outtext("Bot Two WIN!"); prob=1;                                           
         }
         if(prob==1) break;
         
         //�������� �������� ������ �� ������ ���������;
         if(prob==0&&(a[3]+a[5]+a[7]==12)){ 
          setlinestyle(1,1,5);
          for(i=398,j=7;i>30;i-=7,j+=7){delay(10); line(i,j,i-25,j+25);}
          bscore+=1; bgiout <<bscore; outstreamxy(605,180); setfillstyle(1,15);
          bar(406,275,705,330); moveto(495,280); outtext("Bot Two WIN!"); prob=1;                                           
         }
         if(prob==1) break;
         
         //�������� �����;
         setcolor(12);
         if(prob==0){ 
          sum=0;            
          for(i=1;i<N;i++) sum+=a[i];
          if(sum==21){  
           tscore+=1; bgiout <<tscore; outstreamxy(615,230); setfillstyle(1,15); 
           bar(406,275,705,330); moveto(465,280); outtext("Nobody has won");  prob=1;
          }           
         }
         if(prob==1) break;
         
         //������� �� ��� ������� ����;
         if(flag==1) goto bot;
         
        //��� ����;
     ncheck=0; flag=1; setcolor(14); outtextxy(420,280,"it's the bot's turn1...");
     setcolor(12); num++; //delay(800);
        
     //������ ��� ����;
     if(num==1){
         random=rand()%9+1;
         if(random==1){a[1]=1; cross(1); continue;}
         if(random==2){a[2]=1; cross(2); continue;}
         if(random==3){a[3]=1; cross(3); continue;}
         if(random==4){a[4]=1; cross(4); continue;}
         if(random==5){a[5]=1; cross(5); continue;}
         if(random==6){a[6]=1; cross(6); continue;}
         if(random==7){a[7]=1; cross(7); continue;}
         if(random==8){a[8]=1; cross(8); continue;}
         if(random==9){a[9]=1; cross(9); continue;}           
     }
        
     //������ ��� ����;
     if(num==3){
        //������� 1;
        if((a[2]+a[6]+a[4]+a[8])==4){
         if(a[5]==0){a[5]=1; cross(5); continue;}                           
         random=rand()%4+1;
         if(random==1){a[1]=1; cross(1); continue;}
         if(random==2){a[3]=1; cross(3); continue;}
         if(random==3){a[7]=1; cross(7); continue;}
         if(random==4){a[9]=1; cross(9); continue;}                             
        }           
        //������� 2;
        if(a[8]==1){
         if(a[1]==0&&a[4]==0&&a[7]==0){a[1]=1; cross(1); continue;}
         else{a[3]=1; cross(3); continue;}
        }
        if(a[4]==1){
         if(a[3]==0&&a[1]==0&&a[2]==0){a[3]=1; cross(3); continue;}
         else{a[9]=1; cross(9); continue;}            
        }
        if(a[2]==1){          
         if(a[7]==0&&a[1]==0&&a[4]==0){a[7]=1; cross(7); continue;}
         else{a[9]=1; cross(9); continue;}    
        }
        if(a[6]==1){
        if(a[1]==0&&a[2]==0&&a[3]==0){a[1]=1; cross(1); continue;}
        else {a[7]=1; cross(7); continue;}     
        }
        
        //������� 3;
        if(a[1]==1||a[9]==1){
         if(a[1]==0){a[1]=1; cross(1); continue;}
         if(a[9]==0){a[9]=1; cross(9); continue;}
         else{a[3]=1; cross(3); continue;}                    
        }
        if(a[3]==1||a[7]==1){
         if(a[3]==0){a[3]=1; cross(3); continue;}
         if(a[7]==0){a[7]=1; cross(7); continue;}
         else{a[1]=1; cross(1); continue;}          
        }
        
        //����� ���������;
        if(a[1]+a[5]+a[9]==5){
        if(a[1]==0){a[1]=1; cross(1); continue;}                      
        if(a[9]==0){a[9]=1; cross(9); continue;}
        }
        if(a[3]+a[5]+a[7]==5){
        if(a[3]==0){a[3]=1; cross(3); continue;}                      
        if(a[7]==0){a[7]=1; cross(7); continue;}
        }
        
        //������ ��������;
        casual_play(a,1); 
     }
     
     //������, �������� � ����� ��� ����;
     if(num==5||num==7||num==9){                        
        //�������� ������ ��������� � ������;                   
        for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==2){
          if(a[j+1]==0){a[j+1]=1; cross(j+1); ncheck=1; break;}        
          if(a[j+2]==0){a[j+2]=1; cross(j+2); ncheck=1; break;}
          if(a[j+3]==0){a[j+3]=1; cross(j+3); ncheck=1; break;}                              
         }                              
        }
        if(ncheck==1)continue;
        
      //�������� ������ ��������� � �������;
        for(j=0;j<3;j++){
         if((a[j+1]+a[j+4]+a[j+7])==2){
          if(a[j+1]==0){a[j+1]=1; cross(j+1); ncheck=1; break;}
          if(a[j+4]==0){a[j+4]=1; cross(j+4); ncheck=1; break;}
          if(a[j+7]==0){a[j+7]=1; cross(j+7); ncheck=1; break;}                                         
         }           
        }
        if(ncheck==1)continue;
        
        //�������� ������ ��������� �� ���������;
        if((a[1]+a[5]+a[9])==2){
          if(a[1]==0){a[1]=1; cross(1); continue;}
          if(a[9]==0){a[9]=1; cross(9); continue;}
          if(a[5]==0){a[5]=1; cross(5); continue;}                        
        }
        if((a[3]+a[5]+a[7])==2){
         if(a[3]==0){a[3]=1; cross(3); continue;}
         if(a[5]==0){a[5]=1; cross(5); continue;}
         if(a[7]==0){a[7]=1; cross(7); continue;}                        
        }
        
        //�������� ������ ������� � ������;                   
        for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==8){
          if(a[j+1]==0){a[j+1]=1; cross(j+1); ncheck=1; break;}        
          if(a[j+2]==0){a[j+2]=1; cross(j+2); ncheck=1; break;}
          if(a[j+3]==0){a[j+3]=1; cross(j+3); ncheck=1; break;}                             
         }                              
        }
        if(ncheck==1)continue;
      
        //�������� ������ ������� � �������;
        for(j=0;j<3;j++){
         if((a[j+1]+a[j+4]+a[j+7])==8){
          if(a[j+1]==0){a[j+1]=1; cross(j+1); ncheck=1; break;}
          if(a[j+4]==0){a[j+4]=1; cross(j+4); ncheck=1; break;}
          if(a[j+7]==0){a[j+7]=1; cross(j+7); ncheck=1; break;}                                        
         }           
        }
        if(ncheck==1)continue;
        
        //�������� ������ ������� �� ���������;
        if((a[1]+a[5]+a[9])==8){
          if(a[1]==0){a[1]=1; cross(1); continue;}
          if(a[5]==0){a[5]=1; cross(5); continue;}
          if(a[9]==0){a[9]=1; cross(9); continue;}                        
        }
        if((a[3]+a[5]+a[7])==8){
         if(a[3]==0){a[3]=1; cross(3); continue;}
         if(a[5]==0){a[5]=1; cross(5); continue;}
         if(a[7]==0){a[7]=1; cross(7); continue;}                        
       }
       
       //������� 1;
       if(a[1]+a[3]+a[5]==2){
        if(a[1]==0){a[1]=1; cross(1); continue;}
        if(a[3]==0){a[3]=1; cross(3); continue;}                      
       }
       if(a[1]+a[5]+a[7]==2){
        if(a[1]==0){a[1]=1; cross(1); continue;}
        if(a[7]==0){a[7]=1; cross(7); continue;}                      
       }
       if(a[3]+a[5]+a[9]==2){
        if(a[9]==0){a[9]=1; cross(9); continue;}
        if(a[3]==0){a[3]=1; cross(3); continue;}                      
       }
       if(a[7]+a[5]+a[9]==2){
        if(a[9]==0){a[9]=1; cross(9); continue;}
        if(a[7]==0){a[7]=1; cross(7); continue;}                      
       }
       
       //������� 2;
       if(a[8]+a[1]+a[4]+a[7]==2||a[4]+a[9]+a[8]+a[7]==2){a[7]=1; cross(7); continue;}
       if(a[8]+a[3]+a[6]+a[9]==2||a[6]+a[7]+a[8]+a[9]==2){a[9]=1; cross(9); continue;}
       if(a[2]+a[7]+a[4]+a[1]==2||a[4]+a[3]+a[2]+a[1]==2){a[1]=1; cross(1); continue;}
       if(a[2]+a[9]+a[6]+a[3]==2||a[6]+a[1]+a[2]+a[3]==2){a[3]=1; cross(3); continue;}
       
       //������ �������� ����;
       if(a[5]==0){a[5]=1; cross(5); continue;}
       casual_play(a,1);   
     }
     continue;
         
     //��� ����;
     bot:
     ncheck=0; flag=0; setcolor(14); outtextxy(420,280,"it's the bot's turn2..."); 
     setcolor(9); num++;  //delay(800);
         
     //������ ���;
     if(num==2){
          if(a[5]==0){a[5]=4; circle(202,202,64); continue;}
          random=(rand()%4)+1;
          if(random==1){a[1]=4; circle(69,69,64); continue;}
          if(random==2){a[3]=4; circle(335,69,64); continue;}
          if(random==3){a[7]=4; circle(69,335,64); continue;}
          if(random==4){a[9]=4; circle(335,335,64); continue;}
     }
         
     //������ ���;
     if(num==4){ 
       //�������� ������ ��������� � ������;                   
       for(j=0;j<7;j+=3){     
        if((a[j+1]+a[j+2]+a[j+3])==2){
         if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1; break;}        
         if(a[j+2]==0){a[j+2]=4; zero(j+2); ncheck=1; break;}
         if(a[j+3]==0){a[j+3]=4; zero(j+3); ncheck=1; break;}                              
        }                              
       }
       if(ncheck==1)continue;
       
      //�������� ������ ��������� � �������;
      for(j=0;j<3;j++){
       if((a[j+1]+a[j+4]+a[j+7])==2){
        if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1; break;}
        if(a[j+4]==0){a[j+4]=4; zero(j+4); ncheck=1; break;}
        if(a[j+7]==0){a[j+7]=4; zero(j+7); ncheck=1; break;}                                         
       }           
      }
     if(ncheck==1)continue;
     
     //�������� ������ ��������� �� ���������;
     if((a[1]+a[5]+a[9])==2){
      if(a[1]==0){a[1]=4; circle(69,69,64); continue;}
      if(a[9]==0){a[9]=4; circle(335,335,64); continue;}                        
     }
     if((a[3]+a[5]+a[7])==2){
      if(a[3]==0){a[3]=4; circle(335,69,64); continue;}
      if(a[7]==0){a[7]=4; circle(69,335,64); continue;}                        
     }
     
     //�������� �� ����������� ����1;
     if((a[1]+a[9])==2||(a[3]+a[7])==2){                 
      random=rand()%4+1;
      if(random==1){a[2]=4; circle(202,69,64); continue;}
      if(random==2){a[6]=4; circle(335,202,64); continue;}
      if(random==3){a[8]=4; circle(202,335,64); continue;}
      if(random==4){a[4]=4; circle(69,202,64); continue;}           
     }
     
     //�������� �� ����������� ���2;
     if((a[1]+a[8])==2||(a[9]+a[4])==2){a[7]=4; circle(69,335,64); continue;}
     if((a[1]+a[6])==2||(a[9]+a[2])==2){a[3]=4; circle(335,69,64); continue;}
     if((a[3]+a[8])==2||(a[7]+a[6])==2){a[9]=4; circle(335,335,64); continue;}
     if((a[3]+a[4])==2||(a[7]+a[2])==2){a[1]=4; circle(69,69,64); continue;}
     
     //�������� �� ����������� ���3;
     if(a[2]+a[4]==2){a[1]=4; circle(69,69,64); continue;}
     if(a[2]+a[6]==2){a[3]=4; circle(335,69,64); continue;}
     if(a[6]+a[8]==2){a[9]=4; circle(335,335,64); continue;}
     if(a[4]+a[8]==2){a[7]=4; circle(69,335,64); continue;}
     
     //������ �������� 
    if(a[1]==0){a[1]=4; circle(69,69,64); continue;}
    if(a[3]==0){a[3]=4; circle(335,69,64); continue;}
    if(a[7]==0){a[7]=4; circle(69,335,64); continue;}
    if(a[9]==0){a[9]=4; circle(335,335,64); continue;}       
   }
   
   //������ � �������� ����;
   if(num==6||num==8){
                      
   //�������� ������ ������� � ������;                   
        for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==8){
          if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1; break;}        
          if(a[j+2]==0){a[j+2]=4; zero(j+2); ncheck=1; break;}
          if(a[j+3]==0){a[j+3]=4; zero(j+3); ncheck=1; break;}                              
         }                              
        }
        if(ncheck==1)continue;
      
        //�������� ������ ������� � �������;
        for(j=0;j<3;j++){
         if((a[j+1]+a[j+4]+a[j+7])==8){
          if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1; break;}
          if(a[j+4]==0){a[j+4]=4; zero(j+4); ncheck=1; break;}
          if(a[j+7]==0){a[j+7]=4; zero(j+7); ncheck=1; break;}                                         
         }           
        }
        if(ncheck==1)continue;
        
        //�������� ������ ������� �� ���������;
        if((a[1]+a[5]+a[9])==8){
          if(a[1]==0){a[1]=4; circle(69,69,64); continue;}
          if(a[9]==0){a[9]=4; circle(335,335,64); continue;}                        
        }
        
         if((a[3]+a[5]+a[7])==8){
          if(a[3]==0){a[3]=4; circle(335,69,64); continue;}
          if(a[7]==0){a[7]=4; circle(69,335,64); continue;}                        
        }
        
        //�������� ������ ��������� � ������;                   
          for(j=0;j<7;j+=3){     
           if((a[j+1]+a[j+2]+a[j+3])==2){
            if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1; break;}        
            if(a[j+2]==0){a[j+2]=4; zero(j+2); ncheck=1; break;}
            if(a[j+3]==0){a[j+3]=4; zero(j+3); ncheck=1; break;}                              
           }                              
          }
          if(ncheck==1)continue;
      
      //�������� ������ ��������� � �������;
      for(j=0;j<3;j++){
       if((a[j+1]+a[j+4]+a[j+7])==2){
       if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1;  break;}
       if(a[j+4]==0){a[j+4]=4; zero(j+4); ncheck=1;  break;}
       if(a[j+7]==0){a[j+7]=4; zero(j+7); ncheck=1;  break;}                                         
      }           
     }
     if(ncheck==1)continue;
     
     //�������� ������ ��������� �� ���������;
     if((a[1]+a[5]+a[9])==2){
      if(a[1]==0){a[1]=4; circle(69,69,64); continue;}
      if(a[9]==0){a[9]=4; circle(335,335,64); continue;}                        
     }
     
      if((a[3]+a[5]+a[7])==2){
      if(a[3]==0){a[3]=4; circle(335,69,64); continue;}
      if(a[7]==0){a[7]=4; circle(69,335,64); continue;}                        
     }
     
     //�������� ���������� ����������� ���� ������ � ������;
      for(j=0;j<7;j+=3){     
       if((a[j+1]+a[j+2]+a[j+3])==4){
        if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1; break;}        
        if(a[j+2]==0){a[j+2]=4; zero(j+2); ncheck=1; break;}
        if(a[j+3]==0){a[j+3]=4; zero(j+3); ncheck=1; break;}                             
       }                              
      }
      if(ncheck==1)continue;
      
      //�������� ���������� ����������� ���� ������ � �������;
      for(j=0;j<3;j++){
       if((a[j+1]+a[j+4]+a[j+7])==4){
        if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1; break;}
        if(a[j+4]==0){a[j+4]=4; zero(j+4); ncheck=1; break;}
        if(a[j+7]==0){a[j+7]=4; zero(j+7); ncheck=1; break;}                                        
       }           
      }
      if(ncheck==1)continue;
     
     //�������� ���������� ����������� ���� ������ �� ���������;
     if((a[1]+a[5]+a[9])==4){
      if(a[1]==0){a[1]=4; circle(69,69,64); continue;}
      if(a[9]==0){a[9]=4; circle(335,335,64); continue;}                        
     }
     
      if((a[3]+a[5]+a[7])==8){
      if(a[3]==0){a[3]=4; circle(335,69,64); continue;}
      if(a[7]==0){a[7]=4; circle(69,335,64); continue;}                        
     }
     
     //������ ��������;
     casual_play(a,0);          
   }     
  }
}

int main(){
    int sum=0;
    while(1){
      grid();
      bvb();
      closegraph();
      sum++;
     }
    }
