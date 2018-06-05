#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>

const int N=9;

//Переменные для записи счёта;  
int pscore=0,bscore=0,tscore=0; 
 
//Функция рисующая поле счёта игры;  
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
     
//поле игры;
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

//Функция рисования крестика;
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

//Функция рисования нолика;
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

//Вычисление хода игроков;
int play(int player, char* txt, int* m,int f,int &w){
         if(w){setfillstyle(1,15); bar(406,275,705,330);
         setcolor(14); outtextxy(440,280,txt);}
         if(w&&player==3)outtextxy(470,305,"player one...");
         if(w&&player==4)outtextxy(470,305,"player two...");
         w=0;
         if(m[((mousex()/136)+1)+(3*((mousey()/136)))]==0&&ismouseclick(WM_LBUTTONDOWN)){ 
         if(player==2||player==4){w=1; setcolor(9); m[((mousex()/136)+1)+(3*((mousey()/136)))]=4; 
         zero(((mousex()/136)+1)+(3*((mousey()/136)))); f=0;}
         else{w=1; setcolor(12); m[((mousex()/136)+1)+(3*((mousey()/136)))]=1; 
         cross(((mousex()/136)+1)+(3*((mousey()/136)))); f=1;}
         }
         return f;
}

//Другие варианты хода;
void casual_play(int* a,int flag){
int i;    
 if(flag==0){    
  for(i=1;i<=N;i++){                
   if(a[i]==0){a[i]=4; zero(i); break;}                  
  }
 } 
 else
  for(i=1;i<=N;i++){
   if(a[i]==0){a[i]=1; cross(i); break;}                      
 }
}
int win(int* a, int sum,char* txt,int &scr,int kx,int ky){
    int prob=0,s,y=-68,j,i;
    setcolor(2);
        //проверка выигрыша по горизонтали;
         if(prob==0){
          for(j=0;j<7;j+=3){     
           if((a[j+1]+a[j+2]+a[j+3])==sum){
            if(j==3) y+=135; if(j==6) y+=270;                                 
            setlinestyle(1,1,5);         
            for(i=7;i<378;i+=7){delay(10); line(i,y+136,i+25,y+136);}
            scr++; bgiout <<scr; outstreamxy(kx,ky); setfillstyle(1,15);
            bar(406,280,705,400); moveto(465,280); outtext(txt); prob=1;
           }
          }
         }
         if(prob==1) return 1;
          
         //проверка выигрыша по вертикали;
         if(prob==0){
          for(j=0;j<3;j++){
           if((a[j+1]+a[j+4]+a[j+7])==sum){
            if(j==1) y+=135; if(j==2) y+=270;
            setlinestyle(1,1,5);         
            for(i=7;i<378;i+=7){delay(10); line(y+136,i,y+136,i+25);}
            scr++; bgiout <<scr; outstreamxy(kx,ky); setfillstyle(1,15);
            bar(406,280,705,400); moveto(465,280); outtext(txt); prob=1;                           
           }
          }
         }
         if(prob==1) return 1;
                  
         //проверка выигрыша по первой диагонали;
         if(prob==0&&(a[1]+a[5]+a[9]==sum)){ 
          setlinestyle(1,1,5);
          for(i=7;i<378;i+=7){delay(10); line(i,i,i+25,i+25);}
          scr++; bgiout <<scr; outstreamxy(kx,ky); setfillstyle(1,15); 
          bar(406,280,705,400); moveto(465,280); outtext(txt); prob=1;                                           
         }
         if(prob==1) return 1;
         
         //проверка выигрыша по второй диагонали;
         if(prob==0&&(a[3]+a[5]+a[7]==sum)){ 
          setlinestyle(1,1,5);
          for(i=398,j=7;i>30;i-=7,j+=7){delay(10); line(i,j,i-25,j+25);}
          scr++; bgiout <<scr; outstreamxy(kx,ky); setfillstyle(1,15);
          bar(406,280,705,400); moveto(465,280); outtext(txt); prob=1;
          }
         if(prob==1) return 1;
         
         //проверка ничьи;
         setcolor(12);
         if(prob==0){
          s=0;            
          for(i=1;i<10;i++) s+=a[i];
          if(s==21){
           tscore++; bgiout <<tscore; outstreamxy(615,230); setfillstyle(1,15);
           bar(406,280,705,400); moveto(465,280); outtext("Nobody has won"); prob=1;
          }           
         }
         if(prob==1)return 1;
         return 0;
}

void bvp(){
     int a[N],i,j,y=-68,prob=0,flag=0,sum,num=1,random,ncheck=0,wrt=1;
     for(i=1;i<=N;i++) a[i]=0;
    score();
    setlinestyle(SOLID_LINE,2,THICK_WIDTH);
     while(prob==0){
          //проверка выигрыша крестика;
          prob=win(a,3,"Bot WIN!",bscore,605,180);
          if(prob==1) break;
          //проверка выигрыша нолика;
          prob=win(a,12,"Player WIN!",pscore,600,130);
          if(prob==1) break;
         
     //переход на ход игрока;
     if(flag==1) goto Player;
         
     //Ход Бота;
     ncheck=0; flag=1; setcolor(14); outtextxy(420,280,"it's the bot's turn...");
     setcolor(12); delay(800);
        
     //первый ход бота;
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
        
     //второй ход бота;
     if(num==2){
        //тактика 1;
        if((a[2]+a[6]+a[4]+a[8])==4){
         if(a[5]==0){a[5]=1; cross(5); continue;}                           
         random=rand()%4+1;
         if(random==1){a[1]=1; cross(1); continue;}
         if(random==2){a[3]=1; cross(3); continue;}
         if(random==3){a[7]=1; cross(7); continue;}
         if(random==4){a[9]=1; cross(9); continue;}                             
        }           
        //тактика 2;
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
        
        //тактика 3;
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
        
        //Обход проигрыша;
        if(a[1]+a[5]+a[9]==5){
        if(a[1]==0){a[1]=1; cross(1); continue;}                      
        if(a[9]==0){a[9]=1; cross(9); continue;}
        }
        if(a[3]+a[5]+a[7]==5){
        if(a[3]==0){a[3]=1; cross(3); continue;}                      
        if(a[7]==0){a[7]=1; cross(7); continue;}
        }
        
        //Другие варианты;
        casual_play(a,1); 
     }
     
     //третий, четвёртый и пятый ход бота;
     if(num==3||num==4||num==5){                        
        //проверка парных крестиков в строке;                   
        for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==2){
          if(a[j+1]==0){a[j+1]=1; cross(j+1); ncheck=1; break;}        
          if(a[j+2]==0){a[j+2]=1; cross(j+2); ncheck=1; break;}
          if(a[j+3]==0){a[j+3]=1; cross(j+3); ncheck=1; break;}                              
         }                              
        }
        if(ncheck==1)continue;
        
      //проверка парных кресников в столбце;
        for(j=0;j<3;j++){
         if((a[j+1]+a[j+4]+a[j+7])==2){
          if(a[j+1]==0){a[j+1]=1; cross(j+1); ncheck=1; break;}
          if(a[j+4]==0){a[j+4]=1; cross(j+4); ncheck=1; break;}
          if(a[j+7]==0){a[j+7]=1; cross(j+7); ncheck=1; break;}                                         
         }           
        }
        if(ncheck==1)continue;
        
        //проверка парных крестиков по диагонали;
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
        
        //проверка парных ноликов в строке;                   
        for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==8){
          if(a[j+1]==0){a[j+1]=1; cross(j+1); ncheck=1; break;}        
          if(a[j+2]==0){a[j+2]=1; cross(j+2); ncheck=1; break;}
          if(a[j+3]==0){a[j+3]=1; cross(j+3); ncheck=1; break;}                             
         }                              
        }
        if(ncheck==1)continue;
      
        //проверка парных ноликов в столбце;
        for(j=0;j<3;j++){
         if((a[j+1]+a[j+4]+a[j+7])==8){
          if(a[j+1]==0){a[j+1]=1; cross(j+1); ncheck=1; break;}
          if(a[j+4]==0){a[j+4]=1; cross(j+4); ncheck=1; break;}
          if(a[j+7]==0){a[j+7]=1; cross(j+7); ncheck=1; break;}                                        
         }           
        }
        if(ncheck==1)continue;
        
        //проверка парных ноликов по диагонали;
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
       
       //Тактика 1;
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
       
       //Тактика 2;
       if(a[8]+a[1]+a[4]+a[7]==2||a[4]+a[9]+a[8]+a[7]==2){a[7]=1; cross(7); continue;}
       if(a[8]+a[3]+a[6]+a[9]==2||a[6]+a[7]+a[8]+a[9]==2){a[9]=1; cross(9); continue;}
       if(a[2]+a[7]+a[4]+a[1]==2||a[4]+a[3]+a[2]+a[1]==2){a[1]=1; cross(1); continue;}
       if(a[2]+a[9]+a[6]+a[3]==2||a[6]+a[1]+a[2]+a[3]==2){a[3]=1; cross(3); continue;}
       
       //другие варианты хода;
       if(a[5]==0){a[5]=1; cross(5); continue;}
       casual_play(a,1);   
     }
     continue;
        
        //ход игрока;
        Player:     
         flag=play(2,"it's a your turn...",a,flag,wrt);
         if(!flag) num++;
         if(ismouseclick(WM_LBUTTONDOWN)){clearmouseclick(WM_LBUTTONDOWN); delay(20);continue;}     
       }  
     }
     
//игрок против бота;
void pvb(){
    int a[N],i,j,y=-68,prob=0,flag=0,sum,num=0,random,ncheck=0,wrt=1;
    for(i=1;i<=N;i++) a[i]=0;
    score();
    setlinestyle(SOLID_LINE,2,THICK_WIDTH); 
     while(prob==0){           
         //проверка выигрыша крестика;
          prob=win(a,3,"Player WIN!",pscore,600,130);
          if(prob==1) break;
          //проверка выигрыша нолика;
          prob=win(a,12,"Bot WIN!",bscore,605,180);
          if(prob==1) break;
         
         //переход на ход бота;
         if(flag==1) goto bot;
         
         //ход игрока;
         
         flag=play(1,"it's a your turn...",a,flag,wrt);
         if(flag) num++;
         if(ismouseclick(WM_LBUTTONDOWN)){clearmouseclick(WM_LBUTTONDOWN); delay(20);}
         continue;
         
     //ход бота;
     bot:
     ncheck=0; flag=0; setcolor(14); outtextxy(420,280,"it's the bot's turn..."); 
     setcolor(9); delay(800);
         
     //первый ход;
     if(num==1){
          if(a[5]==0){a[5]=4; circle(202,202,64); continue;}
          random=(rand()%4)+1;
          if(random==1){a[1]=4; circle(69,69,64); continue;}
          if(random==2){a[3]=4; circle(335,69,64); continue;}
          if(random==3){a[7]=4; circle(69,335,64); continue;}
          if(random==4){a[9]=4; circle(335,335,64); continue;}
     }
         
     //второй ход;
     if(num==2){ 
       //проверка парных крестиков в строке;                   
       for(j=0;j<7;j+=3){     
        if((a[j+1]+a[j+2]+a[j+3])==2){
         if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1; break;}        
         if(a[j+2]==0){a[j+2]=4; zero(j+2); ncheck=1; break;}
         if(a[j+3]==0){a[j+3]=4; zero(j+3); ncheck=1; break;}                              
        }                              
       }
       if(ncheck==1)continue;
       
      //проверка парных кресников в столбце;
      for(j=0;j<3;j++){
       if((a[j+1]+a[j+4]+a[j+7])==2){
        if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1; break;}
        if(a[j+4]==0){a[j+4]=4; zero(j+4); ncheck=1; break;}
        if(a[j+7]==0){a[j+7]=4; zero(j+7); ncheck=1; break;}                                         
       }           
      }
     if(ncheck==1)continue;
     
     //проверка парных крестиков по диагонали;
     if((a[1]+a[5]+a[9])==2){
      if(a[1]==0){a[1]=4; circle(69,69,64); continue;}
      if(a[9]==0){a[9]=4; circle(335,335,64); continue;}                        
     }
     if((a[3]+a[5]+a[7])==2){
      if(a[3]==0){a[3]=4; circle(335,69,64); continue;}
      if(a[7]==0){a[7]=4; circle(69,335,64); continue;}                        
     }
     
     //проверка на тактические ходы1;
     if((a[1]+a[9])==2||(a[3]+a[7])==2){                 
      random=rand()%4+1;
      if(random==1){a[2]=4; circle(202,69,64); continue;}
      if(random==2){a[6]=4; circle(335,202,64); continue;}
      if(random==3){a[8]=4; circle(202,335,64); continue;}
      if(random==4){a[4]=4; circle(69,202,64); continue;}           
     }
     
     //проверка на тактический ход2;
     if((a[1]+a[8])==2||(a[9]+a[4])==2){a[7]=4; circle(69,335,64); continue;}
     if((a[1]+a[6])==2||(a[9]+a[2])==2){a[3]=4; circle(335,69,64); continue;}
     if((a[3]+a[8])==2||(a[7]+a[6])==2){a[9]=4; circle(335,335,64); continue;}
     if((a[3]+a[4])==2||(a[7]+a[2])==2){a[1]=4; circle(69,69,64); continue;}
     
     //проверка на тактический ход3;
     if(a[2]+a[4]==2){a[1]=4; circle(69,69,64); continue;}
     if(a[2]+a[6]==2){a[3]=4; circle(335,69,64); continue;}
     if(a[6]+a[8]==2){a[9]=4; circle(335,335,64); continue;}
     if(a[4]+a[8]==2){a[7]=4; circle(69,335,64); continue;}
     
     //другие варианты 
    if(a[1]==0){a[1]=4; circle(69,69,64); continue;}
    if(a[3]==0){a[3]=4; circle(335,69,64); continue;}
    if(a[7]==0){a[7]=4; circle(69,335,64); continue;}
    if(a[9]==0){a[9]=4; circle(335,335,64); continue;}       
   }
   
   //третий и четвёртый ходы;
   if(num==3||num==4){
                      
   //проверка парных ноликов в строке;                   
        for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==8){
          if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1; break;}        
          if(a[j+2]==0){a[j+2]=4; zero(j+2); ncheck=1; break;}
          if(a[j+3]==0){a[j+3]=4; zero(j+3); ncheck=1; break;}                              
         }                              
        }
        if(ncheck==1)continue;
      
        //проверка парных ноликов в столбце;
        for(j=0;j<3;j++){
         if((a[j+1]+a[j+4]+a[j+7])==8){
          if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1; break;}
          if(a[j+4]==0){a[j+4]=4; zero(j+4); ncheck=1; break;}
          if(a[j+7]==0){a[j+7]=4; zero(j+7); ncheck=1; break;}                                         
         }           
        }
        if(ncheck==1)continue;
        
        //проверка парных ноликов по диагонали;
        if((a[1]+a[5]+a[9])==8){
          if(a[1]==0){a[1]=4; circle(69,69,64); continue;}
          if(a[9]==0){a[9]=4; circle(335,335,64); continue;}                        
        }
        
         if((a[3]+a[5]+a[7])==8){
          if(a[3]==0){a[3]=4; circle(335,69,64); continue;}
          if(a[7]==0){a[7]=4; circle(69,335,64); continue;}                        
        }
        
        //проверка парных крестиков в строке;                   
          for(j=0;j<7;j+=3){     
           if((a[j+1]+a[j+2]+a[j+3])==2){
            if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1; break;}        
            if(a[j+2]==0){a[j+2]=4; zero(j+2); ncheck=1; break;}
            if(a[j+3]==0){a[j+3]=4; zero(j+3); ncheck=1; break;}                              
           }                              
          }
          if(ncheck==1)continue;
      
      //проверка парных крестиков в столбце;
      for(j=0;j<3;j++){
       if((a[j+1]+a[j+4]+a[j+7])==2){
       if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1;  break;}
       if(a[j+4]==0){a[j+4]=4; zero(j+4); ncheck=1;  break;}
       if(a[j+7]==0){a[j+7]=4; zero(j+7); ncheck=1;  break;}                                         
      }           
     }
     if(ncheck==1)continue;
     
     //проверка парных крестиков по диагонали;
     if((a[1]+a[5]+a[9])==2){
      if(a[1]==0){a[1]=4; circle(69,69,64); continue;}
      if(a[9]==0){a[9]=4; circle(335,335,64); continue;}                        
     }
     
      if((a[3]+a[5]+a[7])==2){
      if(a[3]==0){a[3]=4; circle(335,69,64); continue;}
      if(a[7]==0){a[7]=4; circle(69,335,64); continue;}                        
     }
     
     //проверка вероятного выигрышного хода нолика в строке;
      for(j=0;j<7;j+=3){     
       if((a[j+1]+a[j+2]+a[j+3])==4){
        if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1; break;}        
        if(a[j+2]==0){a[j+2]=4; zero(j+2); ncheck=1; break;}
        if(a[j+3]==0){a[j+3]=4; zero(j+3); ncheck=1; break;}                             
       }                              
      }
      if(ncheck==1)continue;
      
      //проверка вероятного выигрышного хода нолика в столбце;
      for(j=0;j<3;j++){
       if((a[j+1]+a[j+4]+a[j+7])==4){
        if(a[j+1]==0){a[j+1]=4; zero(j+1); ncheck=1; break;}
        if(a[j+4]==0){a[j+4]=4; zero(j+4); ncheck=1; break;}
        if(a[j+7]==0){a[j+7]=4; zero(j+7); ncheck=1; break;}                                        
       }           
      }
      if(ncheck==1)continue;
     
     //проверка вероятного выигрышного хода нолика по диагонали;
     if((a[1]+a[5]+a[9])==4){
      if(a[1]==0){a[1]=4; circle(69,69,64); continue;}
      if(a[9]==0){a[9]=4; circle(335,335,64); continue;}                        
     }
     
      if((a[3]+a[5]+a[7])==8){
      if(a[3]==0){a[3]=4; circle(335,69,64); continue;}
      if(a[7]==0){a[7]=4; circle(69,335,64); continue;}                        
     }
     
     //другие варианты;
     casual_play(a,0);          
   }     
  }
}
 
//игрок против игрока;
void pvp(){
    int a[N],i,j,y=-68,prob=0,flag=0,sum,wrt=1;
    for(i=1;i<=N;i++) a[i]=0;
    setlinestyle(SOLID_LINE,2,THICK_WIDTH); 
    score(1);
     while(prob==0){
         //проверка выигрыша крестика;
          prob=win(a,3,"Player One WIN!",pscore,617,130);
          if(prob==1) break;
          //проверка выигрыша нолика;
          prob=win(a,12,"Player One WIN!",bscore,617,180);
          if(prob==1) break;
         
         //переход на ход второго игрока;
         if(flag==1){            
         if(ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN); delay(30);
         goto PlayerTwo;
         }
         
         //ход первого игрока; 
         flag=play(3,"it's turn of the",a,flag,wrt);
         if(ismouseclick(WM_LBUTTONDOWN)){clearmouseclick(WM_LBUTTONDOWN); delay(20);}
         continue;
         //ход второго игрока;
         PlayerTwo:
         
         flag=play(4,"it's turn of the",a,flag,wrt);
         if(ismouseclick(WM_LBUTTONDOWN)){clearmouseclick(WM_LBUTTONDOWN); delay(20);}
         continue;          
        }
     }
     
//меню после игры;
int finmenu(){
     int flag=1;
     setcolor(15);
     settextstyle(4,0,1);
     outtextxy(15,70,"YOU WANT TO CONTINUE");
     outtextxy(150,100,"GAME?");
     setcolor(2);
     outtextxy(100,160,"YES!");
     setcolor(4);
     outtextxy(250,160,"NO!");
     setcolor(14);
     outtextxy(60,270,"EXIT TO MAIN MENU");
     while(flag){                      
      if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>95&&mousex()<160&&mousey()>150&&mousey()<185){
       return(1);
      }
      if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>245&&mousex()<300&&mousey()>150&&mousey()<185){
       return(0);
      } 
      if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>55&&mousex()<370&&mousey()>265&&mousey()<300){                                                                                        
       return(2);
      } 
     }
    }
     
int main(){
    srand(time(NULL));    
//старновое меню;
int smenu,pmenu,flag,check=1;
menu:
pscore=0; bscore=0; tscore=0; pmenu=0; smenu=0;      
if(check==1) initwindow(405,405);           
flag=1;
check=0;
clearmouseclick(WM_LBUTTONDOWN);     
settextstyle(4,0,4);
    outtextxy(100,120,"Play Game");
    outtextxy(100,220,"Exit Game");
    while(flag){
    clearmouseclick(WM_LBUTTONDOWN);
    delay(30);              
    if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>95&&mousex()<310&&mousey()>115&&mousey()<165){
    flag=0;
    smenu=1;                                            
    }
    if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>95&&mousex()<310&&mousey()>215&&mousey()<265){                                                
    flag=0;
    smenu=2;
    }
    }    
if(smenu==1){
 clearmouseclick(WM_LBUTTONDOWN);
 cleardevice();
    outtextxy(35,65,"Player vs Player");
    outtextxy(65,145,"Player vs Bot");
    outtextxy(65,225,"Bot vs Player");
    outtextxy(150,305,"Back");
    while(flag==0){
    clearmouseclick(WM_LBUTTONDOWN);
    delay(30);               
    if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>145&&mousex()<250&&mousey()>300&&mousey()<350){
    flag=1;
    cleardevice();                                                                                     
    goto menu;                                                                                        
    }
    if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>30&&mousex()<375&&mousey()>60&&mousey()<110){                                                                                       
    flag=1;
    pmenu=1; 
    }
    if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>60&&mousex()<380&&mousey()>140&&mousey()<190){
    flag=1;
    pmenu=2;
    }
    if(ismouseclick(WM_LBUTTONDOWN)&&mousex()>60&&mousex()<380&&mousey()>220&&mousey()<270){
    flag=1;
    pmenu=3;     
    }
    }
}
//игрок против игрока;     
if(pmenu==1){
play:             
closegraph();                                                          
grid();    
pvp();
delay(1300);
closegraph();
initwindow(405,405);
finmenu();
if(finmenu()==1){closegraph(); goto play;}
if(finmenu()==2){closegraph(); initwindow(405,405); goto menu;}
}

//игрок против бота; 
if(pmenu == 2){
play_one:             
closegraph();                                                           
grid();    
pvb();
delay(1300);
closegraph();
initwindow(405,405);
finmenu();
if(finmenu() == 1){closegraph(); goto play_two;}
if(finmenu() == 2){closegraph(); initwindow(405,405); goto menu;}
}

//Бот против игрока;
if(pmenu==3){
play_two:             
closegraph();             
grid();
bvp();
delay(1300);
closegraph();
initwindow(405,405);
finmenu();
if(finmenu()==1){closegraph(); goto play_one;}
if(finmenu()==2){closegraph(); initwindow(405,405); goto menu;}
}
closegraph();     
}

