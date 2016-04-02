#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>

const int N=9;
  
int pscore=0,bscore=0,tscore=0; 
  
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

//Функция рисования крестика
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

//Другие варианты хода бота
void casual_play(){
     
     }

void bvp(){
     int a[N],i,j,y=-68,x1=-64,y1=-64,prob=0,flag=0,sum,num=1,random,ncheck=0;
     for(i=1;i<=N;i++)
     a[i]=0;
    score();
     while(prob==0){
         setcolor(2);
         //проверка выигрыша крестика;
         if(prob==0){
         for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==3){
         if(j==3) y+=135;
         if(j==6) y+=270;                                 
         setlinestyle(1,1,5);         
         for(i=7;i<378;i+=7){
         delay(10);
         line(i,y+136,i+25,y+136);
         }
         bscore++;
         bgiout <<bscore;
         outstreamxy(605,180);
         setfillstyle(1,15);
         bar(406,275,705,330);
         moveto(495,280);
         outtext("Bot WIN!");                        
         prob=1;
         }
         }
         }
         if(prob==1) break;
         if(prob==0){
         for(j=0;j<3;j++){
         if((a[j+1]+a[j+4]+a[j+7])==3){
         if(j==1) y+=135;
         if(j==2) y+=270;
         setlinestyle(1,1,5);         
         for(i=7;i<378;i+=7){
         delay(10);
         line(y+136,i,y+136,i+25);
         }
         bscore++;
         bgiout <<bscore;
         outstreamxy(605,180);
         setfillstyle(1,15);
         bar(406,275,705,330);
         moveto(495,280);
         outtext("Bot WIN!");
         prob=1;                           
         }
         }
         }
         if(prob==1) break;
         if(prob==0&&(a[1]+a[5]+a[9]==3)){ 
         setlinestyle(1,1,5);
         for(i=7;i<378;i+=7){
         delay(10);
         line(i,i,i+25,i+25);
         }
         bscore++;
         bgiout <<bscore;
         outstreamxy(605,180);
         setfillstyle(1,15);
         bar(406,275,705,330);
         moveto(495,280);
         outtext("Bot WIN!");
         prob=1;                                           
         }
         if(prob==1) break;
         if(prob==0&&(a[3]+a[5]+a[7]==3)){ 
         setlinestyle(1,1,5);
         for(i=398,j=7;i>30;i-=7,j+=7){
         delay(10);
         line(i,j,i-25,j+25);
         }
         bscore++;
         bgiout <<bscore;
         outstreamxy(605,180);
         setfillstyle(1,15);
         bar(406,275,705,330);
         moveto(495,280);
         outtext("Bot WIN!");
         prob=1;                                           
         }
         if(prob==1) break;
         //проверка выигрыша нолика;
         if(prob==0){
         for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==12){
         if(j==3) y+=135;
         if(j==6) y+=270;                                 
         setlinestyle(1,1,5);         
         for(i=7;i<378;i+=7){
         delay(10);
         line(i,y+136,i+25,y+136);
         }
         pscore++;
         bgiout <<pscore;
         outstreamxy(600,130); 
         setfillstyle(1,15);
         bar(406,275,705,330);                       
         moveto(440,280);
         outtext("Player WIN!");
         prob=1;
         }
         }
         }
         if(prob==1) break;
         if(prob==0){
         for(j=0;j<3;j++){
         if((a[j+1]+a[j+4]+a[j+7])==12){
         if(j==1) y+=135;
         if(j==2) y+=270;
         setlinestyle(1,1,5);         
         for(i=7;i<378;i+=7){
         delay(10);
         line(y+136,i,y+136,i+25);
         }
         pscore++;
         bgiout <<pscore;
         outstreamxy(600,130);
         setfillstyle(1,15);
         bar(406,275,705,330);
         moveto(440,280);
         outtext("Player One WIN!");
         prob=1;                           
         }
         }
         }
         if(prob==1) break;
         if(prob==0&&(a[1]+a[5]+a[9]==12)){ 
         setlinestyle(1,1,5);
         for(i=7;i<378;i+=7){
         delay(10);
         line(i,i,i+25,i+25);
         }
         pscore++;
         bgiout <<pscore;
         outstreamxy(600,130);
         setfillstyle(1,15);
         bar(406,275,705,330);
         moveto(440,280);
         outtext("Player WIN!");
         prob=1;                                           
         }
         if(prob==1) break;
         if(prob==0&&(a[3]+a[5]+a[7]==12)){ 
         setlinestyle(1,1,5);
         for(i=398,j=7;i>30;i-=7,j+=7){
         delay(10);
         line(i,j,i-25,j+25);
         }
         pscore++;
         bgiout <<pscore;
         outstreamxy(600,130);
         setfillstyle(1,15);
         bar(406,275,705,330);
         moveto(440,280);
         outtext("Player WIN!");
         prob=1;                                           
         }
         if(prob==1) break;
         setcolor(12);
         //проверка ничьи;
         if(prob==0){
         sum=0;            
         for(i=1;i<10;i++)
          sum+=a[i];
         if(sum==21){
         tscore++;            
         bgiout <<tscore;
         outstreamxy(615,230);             
         setfillstyle(1,15);
         bar(406,275,705,330);            
         moveto(465,280);
         outtext("Nobody has won");
         prob=1;
         }           
         }
         if(prob==1) break;
         //переход на ход игрока;
         if(flag==1){
         goto Player;
         }
         
        //Ход Бота;
        ncheck=0;
        flag=1;
        setcolor(14);               
        outtextxy(420,280,"it's the bot's turn...");          
        setcolor(12);
        delay(800);
        //первый ход бота;
        if(num==1){
        random=rand()%9+1;
        if(random==1){
        a[1]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,6,133,133);
         line(133,6,6,133);
         continue;              
        }
        if(random==2){
        a[2]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(139,6,266,133);
         line(266,6,139,133);
         continue;            
        }
        if(random==3){
        a[3]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(272,6,399,133);
         line(399,6,272,133);             
        continue;
        }
        if(random==4){
        a[4]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,139,133,266);
         line(133,139,6,266);
         continue;             
        }
        if(random==5){
        a[5]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(139,139,266,266);
         line(266,139,139,266);
         continue;             
        }
        if(random==6){
        a[6]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(272,139,399,266);
         line(399,139,272,266); 
         continue;            
        }
        if(random==7){
         a[7]=1;
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,272,133,399);
         line(133,272,6,399);
         continue;             
        }
        if(random==8){
        a[8]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(139,272,266,399);
         line(266,272,139,399); 
         continue;            
        }
        if(random==9){
        a[9]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(272,272,399,399);
         line(272,399,399,272);
         continue;             
        }           
        }
        
        //второй ход бота;
        if(num==2){
        //тактика 1;
        if(a[8]==1){
        if(a[1]==0){
         a[1]=1;          
         line(6,6,133,133);
         line(133,6,6,133);
         continue;            
        }
        if(a[6]==0){
         a[6]=1;           
         line(272,139,399,266);
         line(399,139,272,266);
         continue;                                   
        }
        }
        if(a[4]==1){
        if(a[3]==0){
         a[3]=1;
         line(272,6,399,133);
         line(399,6,272,133); 
         continue;            
        }
        if(a[8]==0){         
         a[8]=1;                                                                                   
         line(139,272,266,399);
         line(266,272,139,399); 
         continue;     
        }            
        }
        if(a[2]==1){          
        if(a[7]==0){
         a[7]=1;                                                                                     
         line(6,272,133,399);
         line(133,272,6,399);
         continue;     
        }
        if(a[6]==0){
         a[6]=1;           
         line(272,139,399,266);
         line(399,139,272,266);
         continue;     
        }    
        }
        if(a[6]==1){
        if(a[1]==0){
         a[1]=1;          
         line(6,6,133,133);
         line(133,6,6,133);
         continue;     
        }
        if(a[8]==0){
         a[8]=1;                                                                                   
         line(139,272,266,399);
         line(266,272,139,399); 
         continue;           
        }     
        }
        
        //тактика 2;
        if(a[1]==1||a[9]==1){
        if(a[1]==0){
         a[1]=1;           
         line(6,6,133,133);
         line(133,6,6,133);
         continue;     
        }
        if(a[9]==0){
         a[9]=1;                                                                                     
         line(272,272,399,399);
         line(272,399,399,272);
         continue;      
        }
        if(a[3]==0){
         a[3]=1;           
         line(272,6,399,133);
         line(399,6,272,133); 
         continue;     
        }                    
        }
        if(a[3]==1||a[7]==1){
        if(a[3]==0){
         a[3]=1;           
         line(272,6,399,133);
         line(399,6,272,133); 
         continue;     
        }
        if(a[7]==0){
         a[7]=1;                                                                                     
         line(6,272,133,399);
         line(133,272,6,399);
         continue;      
        }
        if(a[1]==0){
         a[1]=1;           
         line(6,6,133,133);
         line(133,6,6,133);
         continue;     
        }          
        }
        //тактика 3;
        if((a[2]+a[6]+a[4]+a[8])==4){
        random=rand()%4+1;
        if(random==1){
        a[1]=1;           
         line(6,6,133,133);
         line(133,6,6,133);
         continue;     
        }
        if(random==2){
         a[3]=1;           
         line(272,6,399,133);
         line(399,6,272,133); 
         continue;              
        }
        if(random==3){
        a[7]=1;                                                                                     
        line(6,272,133,399);
        line(133,272,6,399);
         continue;              
        }
        if(random==4){
         a[9]=1;                                                                                     
         line(272,272,399,399);
         line(272,399,399,272);
         continue;              
        }                             
        }
        if(a[1]==0){
        a[1]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,6,133,133);
         line(133,6,6,133);
         continue;              
        }
        if(a[2]==0){
        a[2]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(139,6,266,133);
         line(266,6,139,133);
         continue;            
        }
        if(a[3]==0){
        a[3]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(272,6,399,133);
         line(399,6,272,133);             
        continue;
        }
        if(a[4]==0){
        a[4]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,139,133,266);
         line(133,139,6,266);
         continue;             
        }
        if(a[5]==0){
        a[5]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(139,139,266,266);
         line(266,139,139,266);
         continue;             
        }
        if(a[6]==0){
        a[6]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(272,139,399,266);
         line(399,139,272,266); 
         continue;            
        }
        if(a[7]==0){
         a[7]=1;
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,272,133,399);
         line(133,272,6,399); 
         continue;             
        }
        if(a[8]==0){
        a[8]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(139,272,266,399);
         line(266,272,139,399); 
         continue;            
        }
        if(a[9]==0){
        a[9]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(272,272,399,399);
         line(272,399,399,272);
         continue;             
        } 
        }
     
        //третий ход бота;
        if(num==3||num==4||num==5){                        
          //проверка парных крестиков в строке;                   
          for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==2){
         if(j==0){
         if(a[j+1]==0){
         a[1]=1;                                                                                     
         line(6,6,133,133);
         line(133,6,6,133);
         ncheck=1;
         continue;
         }        
        if(a[j+2]==0){
         a[2]=1;                                                                                                                                                                          
         line(139,6,266,133);
         line(266,6,139,133);
         ncheck=1;
         continue;             
        }
        if(a[j+3]==0){
        a[3]=1;                                                                                                                                                                           
         line(272,6,399,133);
         line(399,6,272,133); 
         ncheck=1;
         continue;
        }
        }
        if(j==3){
        if(a[j+1]==0){
         a[4]=1;                                                                                                                                                                          
         line(6,139,133,266);
         line(133,139,6,266);
         ncheck=1;
         continue;
        }
        if(a[j+2]==0){
         a[5]=1;                                                                                                                                                                         
         line(139,139,266,266);
         line(266,139,139,266);
         ncheck=1;
         continue;             
        }
        if(a[j+3]==0){
         a[6]=1;                                                                                                                                                                         
         line(272,139,399,266);
         line(399,139,272,266); 
         ncheck=1;
         continue;             
        }         
        }
        if(j==6){
        if(a[j+1]==0){
        a[7]=1;                                                                                                                                                                           
        line(6,272,133,399);
        line(133,272,6,399);
        ncheck=1;
        continue;             
        }
        if(a[j+2]==0){
        a[8]=1;                                                                                                                                                                          
        line(139,272,266,399);
        line(266,272,139,399);
        ncheck=1;
        continue;             
        }
        if(a[j+3]==0){
         a[9]=1;                                                                                                                                                                         
         line(272,272,399,399);
         line(272,399,399,272);
         ncheck=1;
         continue;              
        }         
        }                              
       }                              
      }
      if(ncheck==1)continue;
      //проверка парных кресников в столбце;
      for(j=0;j<3;j++){
         if((a[j+1]+a[j+4]+a[j+7])==2){
       if(j==0){
       if(a[j+1]==0){
       a[1]=1;                                                                                     
       line(6,6,133,133);
       line(133,6,6,133);
       ncheck=1;
       continue;             
       }
       if(a[j+4]==0){
       a[4]=1;                                                                                                                                                                          
       line(6,139,133,266);
       line(133,139,6,266);
       ncheck=1;
       continue;             
       }
       if(a[j+7]==0){
       a[7]=1;                                                                                                                                                                           
       line(6,272,133,399);
       line(133,272,6,399);
       ncheck=1;
       continue;             
       }         
       }
       if(j==1){
       if(a[j+1]==0){
       a[2]=1;                                                                                                                                                                          
       line(139,6,266,133);
       line(266,6,139,133);
       ncheck=1;
       continue;             
       }
       if(a[j+4]==0){
       a[5]=1;                                                                                                                                                                          
       line(139,139,266,266);
       line(266,139,139,266);
       ncheck=1;
       continue;             
       }
       if(a[j+7]==0){
       a[8]=1;                                                                                                                                                                          
       line(139,272,266,399);
       line(266,272,139,399);
       ncheck=1;
       continue;             
       }          
       }
       if(j==2){
       if(a[j+1]==0){
       a[3]=1;                                                                                                                                                                           
       line(272,6,399,133);
       line(399,6,272,133);
       ncheck=1;
       continue;     
       }
       if(a[j+4]==0){
       a[6]=1;                                                                                                                                                                         
       line(272,139,399,266);
       line(399,139,272,266);
       ncheck=1;
       continue;              
       }
       if(a[j+7]==0){
       a[9]=1;                                                                                                                                                                         
       line(272,272,399,399);
       line(272,399,399,272);
       ncheck=1;
       continue;              
       }         
       }                                
      }           
     }
     if(ncheck==1)continue;
     //проверка парных крестиков по диагонали;
     if((a[1]+a[5]+a[9])==2){
      if(a[1]==0){
      a[1]=1;                                                                                     
      line(6,6,133,133);
      line(133,6,6,133);
      continue;           
      }
      if(a[9]==0){
      a[9]=1;                                                                                                                                                                         
      line(272,272,399,399);
      line(272,399,399,272);
      continue;            
      }
      if(a[5]==0){
      a[5]=1;                                                                                                                                                                         
      line(139,139,266,266);
      line(266,139,139,266);
      continue;            
      }                        
     }
      if((a[3]+a[5]+a[7])==2){
      if(a[3]==0){
      a[3]=1;                                                                                                                                                                           
      line(272,6,399,133);
      line(399,6,272,133);
      continue;            
      }
      if(a[5]==0){
      a[5]=1;                                                                                                                                                                         
      line(139,139,266,266);
      line(266,139,139,266);
      continue;            
      }
      if(a[7]==0){
      a[7]=1;                                                                                                                                                                           
      line(6,272,133,399);
      line(133,272,6,399);
      continue;            
      }                        
     }
       //проверка парных ноликов в строке;                   
          for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==8){
         if(j==0){
         if(a[j+1]==0){
         a[1]=1;                                                                                     
         line(6,6,133,133);
         line(133,6,6,133);
         ncheck=1;
         continue;
         }        
        if(a[j+2]==0){
         a[2]=1;                                                                                                                                                                          
         line(139,6,266,133);
         line(266,6,139,133);
         ncheck=1;
         continue;             
        }
        if(a[j+3]==0){
        a[3]=1;                                                                                                                                                                           
        line(272,6,399,133);
        line(399,6,272,133);
         ncheck=1;
         continue;
        }
        }
        if(j==3){
        if(a[j+1]==0){
         a[4]=1;                                                                                                                                                                          
         line(6,139,133,266);
         line(133,139,6,266);
         ncheck=1;
         continue;
        }
        if(a[j+2]==0){
         a[5]=1;
         line(139,139,266,266);
         line(266,139,139,266);
         ncheck=1;
         continue;    
        }
        if(a[j+3]==0){
         a[6]=1;                                                                                                                                                                         
         line(272,139,399,266);
         line(399,139,272,266);
         ncheck=1;
         continue;             
        }         
        }
        if(j==6){
        if(a[j+1]==0){
        a[7]=1;                                                                                                                                                                           
        line(6,272,133,399);
        line(133,272,6,399);
        ncheck=1;
        continue;             
        }
        if(a[j+2]==0){
        a[8]=1;                                                                                                                                                                          
        line(139,272,266,399);
        line(266,272,139,399);
        ncheck=1;
        continue;             
        }
        if(a[j+3]==0){
        a[9]=1;                                                                                                                                                                         
        line(272,272,399,399);
        line(272,399,399,272);
        ncheck=1;
        continue;              
        }         
        }                              
       }                              
      }
      if(ncheck==1)continue;
      //проверка парных ноликов в столбце;
      for(j=0;j<3;j++){
       if((a[j+1]+a[j+4]+a[j+7])==8){
       if(j==0){
       if(a[j+1]==0){
       a[1]=1;                                                                                     
       line(6,6,133,133);
       line(133,6,6,133);
       ncheck=1;
       continue;             
       }
       if(a[j+4]==0){
       a[4]=1;                                                                                                                                                                          
       line(6,139,133,266);
       line(133,139,6,266);
       ncheck=1;
       continue;             
       }
       if(a[j+7]==0){
       a[7]=1;                                                                                                                                                                           
       line(6,272,133,399);
       line(133,272,6,399);
       ncheck=1;
       continue;             
       }         
       }
       if(j==1){
       if(a[j+1]==0){
       a[2]=1;                                                                                                                                                                          
       line(139,6,266,133);
       line(266,6,139,133);
       ncheck=1;
       continue;             
       }
       if(a[j+4]==0){
       a[5]=1;
       line(139,139,266,266);
       line(266,139,139,266);
       ncheck=1;
       continue;              
       }
       if(a[j+7]==0){
       a[8]=1;                                                                                                                                                                          
       line(139,272,266,399);
       line(266,272,139,399);
       ncheck=1;
       continue;             
       }         
       }
       if(j==2){
       if(a[j+1]==0){
       a[3]=1;                                                                                                                                                                           
       line(272,6,399,133);
       line(399,6,272,133);
       ncheck=1;
       continue;     
       }
       if(a[j+4]==0){
       a[6]=1;                                                                                                                                                                         
       line(272,139,399,266);
       line(399,139,272,266); 
       ncheck=1;
       continue;              
       }
       if(a[j+7]==0){
       a[9]=1;                                                                                                                                                                         
       line(272,272,399,399);
       line(272,399,399,272);
       ncheck=1;
       continue;              
       }         
       }                                
      }           
     }
     if(ncheck==1)continue;
     //проверка парных ноликов по диагонали;
     if((a[1]+a[5]+a[9])==8){
      if(a[1]==0){
      a[1]=1;                                                                                     
      line(6,6,133,133);
      line(133,6,6,133);
      continue;           
      }
      if(a[5]==0){
      a[5]=1;                                                                                                                                                                         
      line(139,139,266,266);
      line(266,139,139,266);
      continue;
      }
      if(a[9]==0){
      a[9]=1;                                                                                                                                                                         
      line(272,272,399,399);
      line(272,399,399,272);
      continue;            
      }                        
     }
      if((a[3]+a[5]+a[7])==8){
      if(a[3]==0){
      a[3]=1;                                                                                                                                                                           
      line(272,6,399,133);
      line(399,6,272,133);
      continue;            
      }
      if(a[5]==0){
      a[5]=1;                                                                                                                                                                         
      line(139,139,266,266);
      line(266,139,139,266);
      continue;
      }
      if(a[7]==0){
      a[7]=1;                                                                                                                                                                           
      line(6,272,133,399);
      line(133,272,6,399);
      continue;            
      }                        
     }
      
     //другие варианты;
     if(a[1]==0){
        a[1]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,6,133,133);
         line(133,6,6,133);
         continue;              
        }
        if(a[2]==0){
        a[2]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(139,6,266,133);
         line(266,6,139,133);
         continue;            
        }
        if(a[3]==0){
        a[3]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(272,6,399,133);
         line(399,6,272,133);             
        continue;
        }
        if(a[4]==0){
        a[4]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,139,133,266);
         line(133,139,6,266);
         continue;             
        }
        if(a[5]==0){
        a[5]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(139,139,266,266);
         line(266,139,139,266);
         continue;             
        }
        if(a[6]==0){
        a[6]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(272,139,399,266);
         line(399,139,272,266); 
         continue;            
        }
        if(a[7]==0){
         a[7]=1;
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,272,133,399);
         line(133,272,6,399); 
         continue;             
        }
        if(a[8]==0){
        a[8]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(139,272,266,399);
         line(266,272,139,399); 
         continue;            
        }
        if(a[9]==0){
        a[9]=1;
        setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(272,272,399,399);
         line(272,399,399,272);
         continue;             
        }   
        }
        continue;
         
        Player:
         setfillstyle(1,15);
         bar(406,275,705,330);
         setcolor(14);               
         outtextxy(440,280,"it's a your turn...");
         setcolor(9);      
        //ход игрока;
         if(ismouseclick(WM_LBUTTONDOWN)) 
         clearmouseclick(WM_LBUTTONDOWN);
         delay(30);
         if(a[1]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>6&&mousex()<133&&mousey()>6&&mousey()<133){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=0;
         a[1]=4;
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(69,69,64);
         continue;
         }
         if(a[2]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>139&&mousex()<266&&mousey()>6&&mousey()<133){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=0;
         a[2]=4;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(202,69,64);
         continue;
         }
         if(a[3]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>272&&mousex()<399&&mousey()>6&&mousey()<133){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=0;
         a[3]=4;                                                                                    
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(335,69,64);
         continue;
         }
         if(a[4]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>6&&mousex()<133&&mousey()>139&&mousey()<266){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=0;
         a[4]=4;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(69,202,64);
         continue;
         }
         if(a[5]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>139&&mousex()<266&&mousey()>139&&mousey()<266){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=0;
         a[5]=4;                                                                                     
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(202,202,64);
         continue;
         }
         if(a[6]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>277&&mousex()<399&&mousey()>139&&mousey()<266){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=0;
         a[6]=4;                                                                                     
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(335,202,64);
         continue;
         }
         if(a[7]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>6&&mousex()<133&&mousey()>272&&mousey()<399){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=0;
         a[7]=4;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(69,335,64);
         continue;
         }
         if(a[8]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>139&&mousex()<266&&mousey()>272&&mousey()<399){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=0;
         a[8]=4;                                                                                     
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(202,335,64);
         continue;
         }
         if(a[9]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>272&&mousex()<399&&mousey()>272&&mousey()<399){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=0;
         a[9]=4;                                                                                     
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(335,335,64);
         continue;
         }
         continue;       
       }  
     }
     
//игрок против бота;
void pvb(){
    int a[N],i,j,y=-68,x1=-64,y1=-64,prob=0,flag=0,sum,num=0,random,ncheck=0;
    for(i=1;i<=N;i++)
    a[i]=0;
    score();
    setlinestyle(SOLID_LINE,2,THICK_WIDTH); 
     while(prob==0){           
         setcolor(2);
         //проверка выигрыша крестика;
         if(prob==0){
         for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==3){
         if(j==3) y+=135;
         if(j==6) y+=270;                                 
         setlinestyle(1,1,5);         
         for(i=7;i<378;i+=7){
         delay(10);
         line(i,y+136,i+25,y+136);
         }
         pscore+=1;
         bgiout <<pscore;
         outstreamxy(600,130); 
         setfillstyle(1,15);
         bar(406,275,705,330);                       
         moveto(465,280);
         outtext("Player One WIN!");
         prob=1;
         }
         }
         }
         if(prob==1) break;
         if(prob==0){
         for(j=0;j<3;j++){
         if((a[j+1]+a[j+4]+a[j+7])==3){
         if(j==1) y+=135;
         if(j==2) y+=270;
         setlinestyle(1,1,5);         
         for(i=7;i<378;i+=7){
         delay(10);
         line(y+136,i,y+136,i+25);
         }
         pscore+=1;
         bgiout <<pscore;
         outstreamxy(600,130);
         setfillstyle(1,15);
         bar(406,275,705,330);
         moveto(465,280);
         outtext("Player One WIN!");
         prob=1;                           
         }
         }
         }
         if(prob==1) break;
         if(prob==0&&(a[1]+a[5]+a[9]==3)){ 
         setlinestyle(1,1,5);
         for(i=7;i<378;i+=7){
         delay(10);
         line(i,i,i+25,i+25);
         }
         pscore+=1;
         bgiout <<pscore;
         outstreamxy(600,130);
         setfillstyle(1,15);
         bar(406,275,705,330);
         moveto(465,280);
         outtext("Player One WIN!");
         prob=1;                                           
         }
         if(prob==1) break;
         if(prob==0&&(a[3]+a[5]+a[7]==3)){ 
         setlinestyle(1,1,5);
         for(i=398,j=7;i>30;i-=7,j+=7){
         delay(10);
         line(i,j,i-25,j+25);
         }
         pscore+=1;
         bgiout <<pscore;
         outstreamxy(600,130);
         setfillstyle(1,15);
         bar(406,275,705,330);
         moveto(465,280);
         outtext("Player One WIN!");
         prob=1;                                           
         }
         if(prob==1) break;
         //проверка выигрыша нолика;
         if(prob==0){
         for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==12){
         if(j==3) y+=135;
         if(j==6) y+=270;                                 
         setlinestyle(1,1,5);         
         for(i=7;i<378;i+=7){
         delay(10);
         line(i,y+136,i+25,y+136);
         }
         bscore+=1;
         bgiout <<bscore;
         outstreamxy(605,180);
         setfillstyle(1,15);
         bar(406,275,705,330);                        
         moveto(495,280);
         outtext("Bot WIN!");
         prob=1;
         }
         }
         }
         if(prob==1) break;
         if(prob==0){
         for(j=0;j<3;j++){
         if((a[j+1]+a[j+4]+a[j+7])==12){
         if(j==1) y+=135;
         if(j==2) y+=270;
         setlinestyle(1,1,5);         
         for(i=7;i<378;i+=7){
         delay(10);
         line(y+136,i,y+136,i+25);
         }
         bscore+=1;
         bgiout <<bscore;
         outstreamxy(605,180);
         setfillstyle(1,15);
         bar(406,275,705,330);
         moveto(495,280);
         outtext("Bot WIN!");
         prob=1;                           
         }
         }
         }
         if(prob==1) break;
         if(prob==0&&(a[1]+a[5]+a[9]==12)){ 
         setlinestyle(1,1,5);
         for(i=7;i<378;i+=7){
         delay(10);
         line(i,i,i+25,i+25);
         }
         bscore+=1;
         bgiout <<bscore;
         outstreamxy(605,180);
         setfillstyle(1,15);
         bar(406,275,705,330);
         moveto(495,280);
         outtext("Bot WIN!");
         prob=1;                                           
         }
         if(prob==1) break;
         if(prob==0&&(a[3]+a[5]+a[7]==12)){ 
         setlinestyle(1,1,5);
         for(i=398,j=7;i>30;i-=7,j+=7){
         delay(10);
         line(i,j,i-25,j+25);
         }
         bscore+=1;
         bgiout <<bscore;
         outstreamxy(605,180);
         setfillstyle(1,15);
         bar(406,275,705,330);
         moveto(495,280);
         outtext("Bot WIN!");
         prob=1;                                           
         }
         if(prob==1) break;
         setcolor(12);
         //проверка ничьи;
         if(prob==0){
         sum=0;            
         for(i=1;i<10;i++)
          sum+=a[i];
         if(sum==21){
         tscore+=1;
         bgiout <<tscore;
         outstreamxy(615,230);            
         setfillstyle(1,15);
         bar(406,275,705,330);            
         moveto(465,280);
         outtext("Nobody has won");
         prob=1;
         }           
         }
         if(prob==1) break;
         //переход на ход бота;
         if(flag==1){
         goto bot;
         }
         setfillstyle(1,15);
         bar(406,275,705,330);
         setcolor(14);               
         outtextxy(440,280,"it's a your turn...");
         setcolor(12);
         //ход игрока;
         if(ismouseclick(WM_LBUTTONDOWN)) 
         clearmouseclick(WM_LBUTTONDOWN);
         delay(30);
         if(a[1]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>6&&mousex()<133&&mousey()>6&&mousey()<133){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=1;
         a[1]=1;
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,6,133,133);
         line(133,6,6,133);
         continue;
         }
         if(a[2]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>139&&mousex()<266&&mousey()>6&&mousey()<133){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=1;
         a[2]=1;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(139,6,266,133);
         line(266,6,139,133);
         continue;
         }
         if(a[3]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>272&&mousex()<399&&mousey()>6&&mousey()<133){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=1;
         a[3]=1;                                                                                    
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(272,6,399,133);
         line(399,6,272,133);
         continue;
         }
         if(a[4]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>6&&mousex()<133&&mousey()>139&&mousey()<266){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=1;
         a[4]=1;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,139,133,266);
         line(133,139,6,266);
         continue;
         }
         if(a[5]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>139&&mousex()<266&&mousey()>139&&mousey()<266){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=1;
         a[5]=1;                                                                                     
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(139,139,266,266);
         line(266,139,139,266);
         continue;
         }
         if(a[6]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>277&&mousex()<399&&mousey()>139&&mousey()<266){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=1;
         a[6]=1;                                                                                     
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(272,139,399,266);
         line(399,139,272,266);
         continue;
         }
         if(a[7]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>6&&mousex()<133&&mousey()>272&&mousey()<399){
         clearmouseclick(WM_LBUTTONDOWN);
         num+=1;
         flag=1;
         a[7]=1;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,272,133,399);
         line(133,272,6,399);
         continue;
         }
         if(a[8]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>139&&mousex()<266&&mousey()>272&&mousey()<399){
         clearmouseclick(WM_LBUTTONDOWN); num+=1; flag=1; a[8]=1;                                                                                                                                                                        
         line(139,272,266,399);
         line(266,272,139,399);
         continue;
         }
         if(a[9]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>272&&mousex()<399&&mousey()>272&&mousey()<399){
         clearmouseclick(WM_LBUTTONDOWN); num+=1; flag=1; a[9]=1;                                                                                     
                                                                                             
         line(272,272,399,399);
         line(272,399,399,272);
         continue;
         }
         continue;
         
         //ход бота;
         bot:
         ncheck=0; flag=0; setcolor(14); outtextxy(420,280,"it's the bot's turn..."); setcolor(9); delay(800);
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
         if(j==0){
          if(a[j+1]==0){a[1]=4; circle(69,69,64); ncheck=1; break;}        
          if(a[j+2]==0){a[2]=4; circle(202,69,64); ncheck=1; break;}
          if(a[j+3]==0){a[3]=4; circle(335,69,64); ncheck=1; break;}
         }
         if(j==3){
          if(a[j+1]==0){a[4]=4; circle(69,202,64); ncheck=1; break;}
          if(a[j+3]==0){a[6]=4; circle(335,202,64); ncheck=1; break;}         
         }
         if(j==6){
          if(a[j+1]==0){a[7]=4; circle(69,335,64); ncheck=1; break;}
          if(a[j+2]==0){a[8]=4; circle(202,335,64); ncheck=1; break;}
          if(a[j+3]==0){a[9]=4; circle(335,335,64); ncheck=1; break;}         
         }                              
        }                              
       }
      if(ncheck==1)continue;
      //проверка парных кресников в столбце;
     for(j=0;j<3;j++){
      if((a[j+1]+a[j+4]+a[j+7])==2){
       if(j==0){
        if(a[j+1]==0){a[1]=4; circle(69,69,64); ncheck=1; break;}
        if(a[j+4]==0){a[4]=4; circle(69,202,64); ncheck=1; break;}
        if(a[j+7]==0){a[7]=4; circle(69,335,64); ncheck=1; break;}         
       }
       if(j==1){
        if(a[j+1]==0){a[2]=4; circle(202,69,64); ncheck=1; break;}
        if(a[j+7]==0){a[8]=4; circle(202,335,64); ncheck=1; break;}         
       }
       if(j==2){
        if(a[j+1]==0){a[3]=4; circle(335,69,64); ncheck=1; break;}
        if(a[j+4]==0){a[6]=4; circle(335,202,64); ncheck=1; break;}
        if(a[j+7]==0){a[9]=4; circle(335,335,64); ncheck=1; break;}         
       }                                
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
      random=((rand()%4)+1);
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
         if(j==0){
         if(a[j+1]==0){
         a[1]=4;                                                                                     
         circle(69,69,64);
         ncheck=1;
         continue;
         }        
        if(a[j+2]==0){
         a[2]=4;                                                                                                                                                                          
         circle(202,69,64);
         ncheck=1;
         continue;             
        }
        if(a[j+3]==0){
        a[3]=4;                                                                                                                                                                           
         circle(335,69,64);
         ncheck=1;
         continue;
        }
        }
        if(j==3){
        if(a[j+1]==0){
         a[4]=4;                                                                                                                                                                          
         circle(69,202,64);
         ncheck=1;
         continue;
        }
        if(a[j+3]==0){
         a[6]=4;                                                                                                                                                                         
         circle(335,202,64);
         ncheck=1;
         continue;             
        }         
        }
        if(j==6){
        if(a[j+1]==0){
        a[7]=4;                                                                                                                                                                           
        circle(69,335,64);
        ncheck=1;
        continue;             
        }
        if(a[j+2]==0){
        a[8]=4;                                                                                                                                                                          
        circle(202,335,64);
        ncheck=1;
        continue;             
        }
        if(a[j+3]==0){
        a[9]=4;                                                                                                                                                                         
         circle(335,335,64);
         ncheck=1;
         continue;              
        }         
        }                              
       }                              
      }
      if(ncheck==1)continue;
      //проверка парных ноликов в столбце;
      for(j=0;j<3;j++){
       if((a[j+1]+a[j+4]+a[j+7])==8){
       if(j==0){
       if(a[j+1]==0){
       a[1]=4;                                                                                     
       circle(69,69,64);
       ncheck=1;
       continue;             
       }
       if(a[j+4]==0){
       a[4]=4;                                                                                                                                                                          
       circle(69,202,64);
       ncheck=1;
       continue;             
       }
       if(a[j+7]==0){
       a[7]=4;                                                                                                                                                                           
       circle(69,335,64);
       ncheck=1;
       continue;             
       }         
       }
       if(j==1){
       if(a[j+1]==0){
       a[2]=4;                                                                                                                                                                          
       circle(202,69,64);
       ncheck=1;
       continue;             
       }
       if(a[j+7]==0){
       a[8]=4;                                                                                                                                                                          
       circle(202,335,64);
       ncheck=1;
       continue;             
       }         
       }
       if(j==2){
       if(a[j+1]==0){
       a[3]=4;                                                                                                                                                                           
       circle(335,69,64);
       ncheck=1;
       continue;     
       }
       if(a[j+4]==0){
       a[6]=4;                                                                                                                                                                         
       circle(335,202,64);
       ncheck=1;
       continue;              
       }
       if(a[j+7]==0){
       a[9]=4;                                                                                                                                                                         
       circle(335,335,64);
       ncheck=1;
       continue;              
       }         
       }                                
      }           
     }
     if(ncheck==1)continue;
     //проверка парных ноликов по диагонали;
     if((a[1]+a[5]+a[9])==8){
      if(a[1]==0){
      a[1]=4;                                                                                     
      circle(69,69,64);
      continue;           
      }
      if(a[9]==0){
      a[9]=4;                                                                                                                                                                         
      circle(335,335,64);
      continue;            
      }                        
     }
      if((a[3]+a[5]+a[7])==8){
      if(a[3]==0){
      a[3]=4;                                                                                                                                                                           
      circle(335,69,64);
      continue;            
      }
      if(a[7]==0){
      a[7]=4;                                                                                                                                                                           
      circle(69,335,64);
      continue;            
      }                        
     }
        //проверка парных крестиков в строке;                   
          for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==2){
         if(j==0){
         if(a[j+1]==0){
         a[1]=4;                                                                                     
         circle(69,69,64);
         ncheck=1;
         continue;
         }        
        if(a[j+2]==0){
         a[2]=4;                                                                                                                                                                          
         circle(202,69,64);
         ncheck=1;
         continue;             
        }
        if(a[j+3]==0){
        a[3]=4;                                                                                                                                                                           
         circle(335,69,64);
         ncheck=1;
         continue;
        }
        }
        if(j==3){
        if(a[j+1]==0){
         a[4]=4;                                                                                                                                                                          
         circle(69,202,64);
         ncheck=1;
         continue;
        }
        if(a[j+3]==0){
         a[6]=4;                                                                                                                                                                         
         circle(335,202,64);
         ncheck=1;
         continue;             
        }         
        }
        if(j==6){
        if(a[j+1]==0){
        a[7]=4;                                                                                                                                                                           
        circle(69,335,64);
        ncheck=1;
        continue;             
        }
        if(a[j+2]==0){
        a[8]=4;                                                                                                                                                                          
        circle(202,335,64);
        ncheck=1;
        continue;             
        }
        if(a[j+3]==0){
        a[9]=4;                                                                                                                                                                         
         circle(335,335,64);
         ncheck=1;
         continue;              
        }         
        }                              
       }                              
      }
      if(ncheck==1)continue;
      //проверка парных крестиков в столбце;
      for(j=0;j<3;j++){
       if((a[j+1]+a[j+4]+a[j+7])==2){
       if(j==0){
       if(a[j+1]==0){
       a[1]=4;                                                                                     
       circle(69,69,64);
       ncheck=1;
       continue;             
       }
       if(a[j+4]==0){
       a[4]=4;                                                                                                                                                                          
       circle(69,202,64);
       ncheck=1;
       continue;             
       }
       if(a[j+7]==0){
       a[7]=4;                                                                                                                                                                           
       circle(69,335,64);
       ncheck=1;
       continue;             
       }         
       }
       if(j==1){
       if(a[j+1]==0){
       a[2]=4;                                                                                                                                                                          
       circle(202,69,64);
       ncheck=1;
       continue;             
       }
       if(a[j+7]==0){
       a[8]=4;                                                                                                                                                                          
       circle(202,335,64);
       ncheck=1;
       continue;             
       }         
       }
       if(j==2){
       if(a[j+1]==0){
       a[3]=4;                                                                                                                                                                           
       circle(335,69,64);
       ncheck=1;
       continue;     
       }
       if(a[j+4]==0){
       a[6]=4;                                                                                                                                                                         
       circle(335,202,64);
       ncheck=1;
       continue;              
       }
       if(a[j+7]==0){
       a[9]=4;                                                                                                                                                                         
       circle(335,335,64);
       ncheck=1;
       continue;              
       }         
       }                                
      }           
     }
     if(ncheck==1)continue;
     //проверка парных крестиков по диагонали;
     if((a[1]+a[5]+a[9])==2){
      if(a[1]==0){
      a[1]=4;                                                                                     
      circle(69,69,64);
      continue;           
      }
      if(a[9]==0){
      a[9]=4;                                                                                                                                                                         
      circle(335,335,64);
      continue;            
      }                        
     }
      if((a[3]+a[5]+a[7])==2){
      if(a[3]==0){
      a[3]=4;                                                                                                                                                                           
      circle(335,69,64);
      continue;            
      }
      if(a[7]==0){
      a[7]=4;                                                                                                                                                                           
      circle(69,335,64);
      continue;            
      }                        
     }
     //проверка вероятного выигрышного хода нолика в строке;
      for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==4){
         if(j==0){
         if(a[j+1]==0){
         a[1]=4;                                                                                     
         circle(69,69,64);
         ncheck=1;
         continue;
         }        
        if(a[j+2]==0){
         a[2]=4;                                                                                                                                                                          
         circle(202,69,64);
         ncheck=1;
         continue;             
        }
        if(a[j+3]==0){
        a[3]=4;                                                                                                                                                                           
         circle(335,69,64);
         ncheck=1;
         continue;
        }
        }
        if(j==3){
        if(a[j+1]==0){
         a[4]=4;                                                                                                                                                                          
         circle(69,202,64);
         ncheck=1;
         continue;
        }
        if(a[j+3]==0){
         a[6]=4;                                                                                                                                                                         
         circle(335,202,64);
         ncheck=1;
         continue;             
        }         
        }
        if(j==6){
        if(a[j+1]==0){
        a[7]=4;                                                                                                                                                                           
        circle(69,335,64);
        ncheck=1;
        continue;             
        }
        if(a[j+2]==0){
        a[8]=4;                                                                                                                                                                          
        circle(202,335,64);
        ncheck=1;
        continue;             
        }
        if(a[j+3]==0){
        a[9]=4;                                                                                                                                                                         
         circle(335,335,64);
         ncheck=1;
         continue;              
        }         
        }                              
       }                              
      }
      if(ncheck==1)continue;
      //проверка вероятного выигрышного хода нолика в столбце;
      for(j=0;j<3;j++){
       if((a[j+1]+a[j+4]+a[j+7])==4){
       if(j==0){
       if(a[j+1]==0){
       a[1]=4;                                                                                     
       circle(69,69,64);
       ncheck=1;
       continue;             
       }
       if(a[j+4]==0){
       a[4]=4;                                                                                                                                                                          
       circle(69,202,64);
       ncheck=1;
       continue;             
       }
       if(a[j+7]==0){
       a[7]=4;                                                                                                                                                                           
       circle(69,335,64);
       ncheck=1;
       continue;             
       }         
       }
       if(j==1){
       if(a[j+1]==0){
       a[2]=4;                                                                                                                                                                          
       circle(202,69,64);
       ncheck=1;
       continue;             
       }
       if(a[j+7]==0){
       a[8]=4;                                                                                                                                                                          
       circle(202,335,64);
       ncheck=1;
       continue;             
       }         
       }
       if(j==2){
       if(a[j+1]==0){
       a[3]=4;                                                                                                                                                                           
       circle(335,69,64);
       ncheck=1;
       continue;     
       }
       if(a[j+4]==0){
       a[6]=4;                                                                                                                                                                         
       circle(335,202,64);
       ncheck=1;
       continue;              
       }
       if(a[j+7]==0){
       a[9]=4;                                                                                                                                                                         
       circle(335,335,64);
       ncheck=1;
       continue;              
       }         
       }                                
      }           
     }
     if(ncheck==1)continue;
     //проверка вероятного выигрышного хода нолика по диагонали;
     if((a[1]+a[5]+a[9])==4){
      if(a[1]==0){
      a[1]=4;                                                                                     
      circle(69,69,64);
      continue;           
      }
      if(a[9]==0){
      a[9]=4;                                                                                                                                                                         
      circle(335,335,64);
      continue;            
      }                        
     }
      if((a[3]+a[5]+a[7])==8){
      if(a[3]==0){
      a[3]=4;                                                                                                                                                                           
      circle(335,69,64);
      continue;            
      }
      if(a[7]==0){
      a[7]=4;                                                                                                                                                                           
      circle(69,335,64);
      continue;            
      }                        
     }
     //другие варианты;
     for(j=1;j<=N;j++){
     if(j==1||j==4||j==7){x1=-64; y1+=133;}
     x1+=133;                  
     if(a[j]==0){
     a[j]=4;
     circle(x1,y1,64);
     j=10;            
     }                  
     }           
   }     
  }
}
 
//игрок против игрока;
void pvp(){
    int a[N]={0},i,j,y=-68,prob=0,flag=0,sum;
    for(i=1;i<=N;i++)
    a[i]=0;
    score(1);
     while(prob==0){
         setcolor(2);
         //проверка выигрыша крестика;
         if(prob==0){
         for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==3){
         if(j==3) y+=135;
         if(j==6) y+=270;                                 
         setlinestyle(1,1,5);         
         for(i=7;i<378;i+=7){
         delay(10);
         line(i,y+136,i+25,y+136);
         }
         pscore++;
         bgiout <<pscore;
         outstreamxy(617,130);
         setfillstyle(1,15);
         bar(406,280,705,400);                        
         moveto(465,280);
         outtext("Player One WIN!");
         prob=1;
         }
         }
         }
         if(prob==1) break;
         if(prob==0){
         for(j=0;j<3;j++){
         if((a[j+1]+a[j+4]+a[j+7])==3){
         if(j==1) y+=135;
         if(j==2) y+=270;
         setlinestyle(1,1,5);         
         for(i=7;i<378;i+=7){
         delay(10);
         line(y+136,i,y+136,i+25);
         }
         pscore++;
         bgiout <<pscore;
         outstreamxy(617,130);
         setfillstyle(1,15);
         bar(406,280,705,400);                        
         moveto(465,280);
         outtext("Player One WIN!");
         prob=1;                           
         }
         }
         }
         if(prob==1) break;
         if(prob==0&&(a[1]+a[5]+a[9]==3)){ 
         setlinestyle(1,1,5);
         for(i=7;i<378;i+=7){
         delay(10);
         line(i,i,i+25,i+25);
         }
         pscore++;
         bgiout <<pscore;
         outstreamxy(617,130);
         setfillstyle(1,15);
         bar(406,280,705,400);                        
         moveto(465,280);
         outtext("Player One WIN!");
         prob=1;                                           
         }
         if(prob==1) break;
         if(prob==0&&(a[3]+a[5]+a[7]==3)){ 
         setlinestyle(1,1,5);
         for(i=398,j=7;i>30;i-=7,j+=7){
         delay(10);
         line(i,j,i-25,j+25);
         }
         pscore++;
         bgiout <<pscore;
         outstreamxy(617,130);
         setfillstyle(1,15);
         bar(406,280,705,400);                        
         moveto(465,280);
         outtext("Player One WIN!");
         prob=1;                                           
         }
         if(prob==1) break;
         //проверка выигрыша нолика;
         if(prob==0){
         for(j=0;j<7;j+=3){     
         if((a[j+1]+a[j+2]+a[j+3])==12){
         if(j==3) y+=135;
         if(j==6) y+=270;                                 
         setlinestyle(1,1,5);         
         for(i=7;i<378;i+=7){
         delay(10);
         line(i,y+136,i+25,y+136);
         }                        
         bscore++;
         bgiout <<bscore;
         outstreamxy(617,180);
         setfillstyle(1,15);
         bar(406,280,705,400);                        
         moveto(465,280);
         outtext("Player Two WIN!");
         prob=1;
         }
         }
         }
         if(prob==1) break;
         if(prob==0){
         for(j=0;j<3;j++){
         if((a[j+1]+a[j+4]+a[j+7])==12){
         if(j==1) y+=135;
         if(j==2) y+=270;
         setlinestyle(1,1,5);         
         for(i=7;i<378;i+=7){
         delay(10);
         line(y+136,i,y+136,i+25);
         }
         bscore++;
         bgiout <<bscore;
         outstreamxy(617,180);
         setfillstyle(1,15);
         bar(406,280,705,400);                        
         moveto(465,280);
         outtext("Player Two WIN!");
         prob=1;                           
         }
         }
         }
         if(prob==1) break;
         if(prob==0&&(a[1]+a[5]+a[9]==12)){ 
         setlinestyle(1,1,5);
         for(i=7;i<378;i+=7){
         delay(10);
         line(i,i,i+25,i+25);
         }
         bscore++;
         bgiout <<bscore;
         outstreamxy(617,180);
         setfillstyle(1,15);
         bar(406,280,705,400);                        
         moveto(465,280);
         outtext("Player Two WIN!");
         prob=1;                                           
         }
         if(prob==1) break;
         if(prob==0&&(a[3]+a[5]+a[7]==12)){ 
         setlinestyle(1,1,5);
         for(i=398,j=7;i>30;i-=7,j+=7){
         delay(10);
         line(i,j,i-25,j+25);
         }
         bscore++;
         bgiout <<bscore;
         outstreamxy(617,180);
         setfillstyle(1,15);
         bar(406,280,705,400);                        
         moveto(465,280);
         outtext("Player Two WIN!");
         prob=1;                                           
         }
         if(prob==1) break;
         setcolor(12);
         //проверка ничьи;
         if(prob==0){
         sum=0;            
         for(i=1;i<10;i++)
          sum+=a[i];
         if(sum==21){
         tscore++;            
         bgiout <<tscore;
         outstreamxy(615,230);
         setfillstyle(1,15);
         bar(406,280,705,400);                      
         moveto(465,280);
         outtext("Nobody has won");
         prob=1;
         }           
         }
         if(prob==1) break;
         //переход на ход второго игрока;
         if(flag==1){
         if(ismouseclick(WM_LBUTTONDOWN)) 
         clearmouseclick(WM_LBUTTONDOWN);
         delay(30);
         goto PlayerTwo;
         }
         setcolor(14);               
         outtextxy(455,280,"it's turn of the");
         outtextxy(470,305,"player one...");
         setcolor(12);
         //ход первого игрока;
         if(ismouseclick(WM_LBUTTONDOWN)) 
         clearmouseclick(WM_LBUTTONDOWN);
         delay(30);
         if(a[1]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>6&&mousex()<133&&mousey()>6&&mousey()<133){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=1;
         a[1]=1;
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,6,133,133);
         line(133,6,6,133);
         continue;
         }
         if(a[2]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>139&&mousex()<266&&mousey()>6&&mousey()<133){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=1;
         a[2]=1;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(139,6,266,133);
         line(266,6,139,133);
         continue;
         }
         if(a[3]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>272&&mousex()<399&&mousey()>6&&mousey()<133){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=1;
         a[3]=1;                                                                                    
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(272,6,399,133);
         line(399,6,272,133);
         continue;
         }
         if(a[4]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>6&&mousex()<133&&mousey()>139&&mousey()<266){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=1;
         a[4]=1;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,139,133,266);
         line(133,139,6,266);
         continue;
         }
         if(a[5]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>139&&mousex()<266&&mousey()>139&&mousey()<266){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=1;
         a[5]=1;                                                                                     
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(139,139,266,266);
         line(266,139,139,266);
         continue;
         }
         if(a[6]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>277&&mousex()<399&&mousey()>139&&mousey()<266){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=1;
         a[6]=1;                                                                                     
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(272,139,399,266);
         line(399,139,272,266);
         continue;
         }
         if(a[7]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>6&&mousex()<133&&mousey()>272&&mousey()<399){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=1;
         a[7]=1;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(6,272,133,399);
         line(133,272,6,399);
         continue;
         }
         if(a[8]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>139&&mousex()<266&&mousey()>272&&mousey()<399){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=1;
         a[8]=1;                                                                                     
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(139,272,266,399);
         line(266,272,139,399);
         continue;
         }
         if(a[9]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>272&&mousex()<399&&mousey()>272&&mousey()<399){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=1;
         a[9]=1;                                                                                     
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         line(272,272,399,399);
         line(272,399,399,272);
         continue;
         }
         continue;
         
         //ход второго игрока;
         PlayerTwo:
         setcolor(14);               
         outtextxy(455,280,"it's turn of the");
         outtextxy(470,305,"player two...");
         setcolor(9);                  
         if(a[1]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>6&&mousex()<133&&mousey()>6&&mousey()<133){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=0;
         a[1]=4; 
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(69,69,64);
         continue;
         }
         if(a[2]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>139&&mousex()<266&&mousey()>6&&mousey()<133){
         clearmouseclick(WM_LBUTTONDOWN); 
         flag=0;
         a[2]=4;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(202,69,64);
         continue;
         }
         if(a[3]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>272&&mousex()<399&&mousey()>6&&mousey()<133){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=0;
         a[3]=4;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(335,69,64);
         continue;
         }
         if(a[4]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>6&&mousex()<133&&mousey()>139&&mousey()<266){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=0;
         a[4]=4;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(69,202,64);
         continue;
         }
         if(a[5]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>139&&mousex()<266&&mousey()>139&&mousey()<266){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=0;
         a[5]=4;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(202,202,64);
         continue;
         }
         if(a[6]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>277&&mousex()<399&&mousey()>139&&mousey()<266){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=0;
         a[6]=4;                                                                                     
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(335,202,64);
         continue;
         }
         if(a[7]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>6&&mousex()<133&&mousey()>272&&mousey()<399){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=0;
         a[7]=4;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(69,335,64);
         continue;
         }
         if(a[8]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>139&&mousex()<266&&mousey()>272&&mousey()<399){
         clearmouseclick(WM_LBUTTONDOWN);
         flag=0;
         a[8]=4;                                                                                      
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(202,335,64);
         continue;
         }
         if(a[9]==0&&ismouseclick(WM_LBUTTONDOWN)&&mousex()>272&&mousex()<399&&mousey()>272&&mousey()<399){
         clearmouseclick(WM_LBUTTONDOWN); 
         flag=0;
         a[9]=4;                                                                                     
         setlinestyle(SOLID_LINE,2,THICK_WIDTH);                                                                                     
         circle(335,335,64);
         continue;
         }
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
play:   
if(pmenu==1){
closegraph();             
//игрок против игрока;                                               
grid();    
pvp();
delay(1300);
closegraph();
initwindow(405,405);
finmenu();
if(finmenu()==1){
closegraph();                                 
goto play;
}
if(finmenu()==2){                  
closegraph();
initwindow(405,405);
goto menu;
}
}
if(pmenu==2){
play_one:             
closegraph();             
//игрок против бота;                                               
grid();    
pvb();
delay(1300);
closegraph();
initwindow(405,405);
finmenu();
if(finmenu()==1){
closegraph();                                 
goto play_two;
}
if(finmenu()==2){                
closegraph();
initwindow(405,405);
goto menu;
}
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
if(finmenu()==1){
closegraph();                                 
goto play_one;
}
if(finmenu()==2){                
closegraph();
initwindow(405,405);
goto menu;
}
}
closegraph();     
}

