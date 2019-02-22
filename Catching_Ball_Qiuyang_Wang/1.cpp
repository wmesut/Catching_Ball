#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define	CMD_LEFT		1
#define	CMD_RIGHT		2
#define MAXSTAR 200	
#pragma comment (lib,"MSIMG32.lib")
int game(int high,int m,char name[100]);
void back();

int mouse1();
int menu2();

void menu(int high3,char name[],int score,int leftlife);
void boom();
void choose();
int areyoustillaliveornot(int position2,int leftlife2,int x3,int y3);
int areyouscoreornot(int position,int score2,int x2,int y2);
//函数声明
int highest(){
FILE *fp;
int max;
int history[10];
char name[10][10];
int i3=0,i5;
int num;
int temp;
char exchange[10];
	fp=fopen("design.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%d%s",&history[i3],name[i3]);
		i3++;
	}
	fclose(fp);
	num=i3;
for(i3=0;i3<num-1;i3++){
		for(i5=0;i5<num;i5++){
			if(history[i5]<history[i5+1]){
				temp=history[i5];
				strcpy(exchange,name[i5]);
				history[i5]=history[i5+1];
				strcpy(name[i5],name[i5+1]);
				history[i5+1]=temp;
			strcpy(name[i5+1],exchange);}
			}
		
}
max=history[0];
return max;
}





struct STAR
{
	double x;
	int y;
	double step;
	int color;
};
STAR star[MAXSTAR];


void InitStar(int i)
{
	star[i].x = 0;
	star[i].y = rand() % 480;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	
	star[i].color = RGB(star[i].color, star[i].color, star[i].color);
}


void MoveStar(int i){

	putpixel((int)star[i].x, star[i].y, 0);


	star[i].x += star[i].step;
	if (star[i].x > 640)	InitStar(i);

	putpixel((int)star[i].x, star[i].y, star[i].color);
}
//stars
int back2(){
	int i2,playcheck=10;
	int high,k;
	high=highest();
	cleardevice();
	srand((unsigned)time(NULL));	
	for(i2=0; i2<MAXSTAR; i2++)
	{
		InitStar(i2);
		star[i2].x = rand() % 640;
	}


while(true)

	{  
choose();
if(MouseHit()){
	playcheck=mouse1();}
	if(playcheck==0){
		break;}
	else{
		if(playcheck==1){
			cleardevice();
			while(true){
		for(k=0; k<MAXSTAR; k++)
			MoveStar(k);
	
         
				high=menu2();
				if(MouseHit()){
					playcheck=mouse1();}
			if(playcheck==3){
			  cleardevice();
				break;
		}
			
		
        }
		
	}


			else{
				if(playcheck==7){
				return 7;
				}
}		
}for(i2=0; i2<MAXSTAR; i2++)
			MoveStar(i2);
		Sleep(20);
}
return high;
}//开始界面

void back(){
	IMAGE	img;
	loadimage(&img,"background.jpg");
	putimage(0,0,&img);
}
void exitbutton(){
IMAGE exit;
loadimage(&exit,"exit.jpg");
HDC dstDC=GetImageHDC();
HDC srcDC=GetImageHDC(&exit);
TransparentBlt(dstDC,500,400,exit.getwidth(),exit.getheight(),srcDC,0,0,exit.getwidth(),exit.getheight(),RGB(0,0,0));




}

int	Time(int t1,int t){
	char strsec[10];
	int sec=t1-(GetTickCount()-t)/1000;//t游戏开始时间，gettickcount--当前时间两者相减得游戏运行时间,t1减去既是倒计时


	itoa(sec,strsec,10);
	outtextxy(565,300,strsec);
	return sec;
}

//for(i=0;i<10;i++)
// i++;

struct Ball{
	int x;
	int v;
	int y;
	int num;
	struct Ball *next;
};

//背景




void choose(){
	char startgame1[]="开始游戏";
	char record[]="  记录";
	char myname[]="created by 王秋扬";
	char load[]="读取游戏";
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	outtextxy(285,170,load);
	outtextxy(285,70,startgame1);
	outtextxy(400,400,myname);
	outtextxy(285,250,record);
}








int control(int m)
{   int h;

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)		
		{h |= CMD_LEFT;}
		else{
			if(GetAsyncKeyState(VK_RIGHT) & 0x8000)	
			{h |= CMD_RIGHT;}
		}
		
		if(h&CMD_LEFT){
			m-=8;}
		else
		{if(h&CMD_RIGHT){
			m+=8;}
		}
		if(m+70>620)
{m-=70;}
else{
if(m<10){
	m=30;}
	}
	
    setlinecolor(BLUE);
	setfillcolor(GREEN);
	fillrectangle(m,280,m+70,295);
  return m; 
	}/*键盘控制*/
void saveornot(int point,char name[10]){
FILE *fp3;

fp3=fopen("design.txt","a");
		fprintf(fp3,"   %d  %s     ",point, name);
		outtextxy(100,100,"saved");
   

}

void destory(int x){
IMAGE de;
loadimage(&de,"booming.jpg");
putimage(x,280,&de);
Sleep(10);
}

int areyouscoreornot(int position,int score2,int x2,int y2){
    if(x2>position&&x2<position+70&&y2>280){
	
		score2=score2+10;}

	else{if(x2<position&&y2>280||x2+70>position&&y2>280){
		score2=score2-10;
	}}
	
	
	return score2;

}
int areyoustillaliveornot(int position,int leftlife2,int x3,int y3){
	if(x3>position&&x3<position+70&&y3>280){
         destory(position);
		 
		leftlife2=leftlife2-1;
	}
return leftlife2;
}
//计算
int mouse(){
	MOUSEMSG msg;
	int gameend=12;
	int gamestart=12;
			while(MouseHit()){
			msg=GetMouseMsg();
		if(msg.uMsg==WM_LBUTTONDOWN)
		{
			if(msg.x>150&&msg.x<200&&msg.y>400&&msg.y<450)
			{gameend=0;//reset
             return gameend;}
			else{
				if(msg.x>50&&msg.x<100&&msg.y>400&&msg.y<450)
				{
                       gamestart=10;//start
					   return gamestart;	}
				else{
					if(msg.x>399&&msg.x<450&&msg.y>399&&msg.y<450){
					return 5;//pause
						
			}
else{
if(msg.x>499&&msg.x<550&&msg.y>399&&msg.y<450){
return 3;//exit
}
else{
	if(msg.x>319&&msg.x<370&&msg.y>399&&msg.y<450){
	return 4;//保存成绩
	}
	else{
		if(msg.x>249&&msg.x<300&&msg.y>399&&msg.y<450){
		return 6;//保存游戏
		}
	}
}
}

				}
		}
		}
		}

return 111;
}



int mouse1(){
	setcolor(WHITE);
	MOUSEMSG msg;
	while(MouseHit()){
msg=GetMouseMsg();
if(msg.uMsg==WM_LBUTTONDOWN){

if(msg.x>284&&msg.x<490&&msg.y>69&&msg.y<79){
	
	return 0;}//start
else{
	if(msg.x>284&&msg.x<360&&msg.y>249&&msg.y<261){
	
		return 1;}//record
	else{
		if(msg.x>99&&msg.x<142&&msg.y>299&&msg.y<310){
			
			return 3;}//return
		else{
			if(msg.x>284&&msg.x<320&&msg.y>169&&msg.y<200){
		
				return 7;//load
			}
		
		}
	}
	}
	
}return 11;
}
	return 100;
}



void  booming(int x,int y){

	IMAGE bo;
	loadimage(&bo,"boom.bmp");
	HDC dstDC=GetImageHDC();
	HDC srcDC=GetImageHDC(&bo);
	TransparentBlt(dstDC,x,y,bo.getwidth(),bo.getheight(),srcDC,0,0,bo.getwidth(),bo.getheight(),RGB(0,0,0));


}
void caking(int x,int y){
	IMAGE ca;
	loadimage(&ca,"cake2.bmp");
		HDC dstDC=GetImageHDC();
	HDC srcDC=GetImageHDC(&ca);
	TransparentBlt(dstDC,x,y,ca.getwidth(),ca.getheight(),srcDC,0,0,ca.getwidth(),ca.getheight(),RGB(0,0,0));
}//图片

void saveyourgame(int point,int pos,char name[10]){
FILE *fpp;
FILE *fpn;
FILE *fpm;

fpp=fopen("loadscore.txt","r+");
fprintf(fpp,"%d",point);
fclose(fpp);
fpn=fopen("loadname.txt","r+");
fprintf(fpn,"%s",name);
fclose(fpn);
fpm=fopen("loadposition.txt","r+");
fprintf(fpm,"%d",pos);
fclose(fpm);
outtextxy(100,200,"saved");
}
struct Ball *creat(int i){
	
struct Ball *s;
	s=(struct Ball*)malloc(sizeof(struct Ball));
	s->num=i;
		 s->x=rand()%605+10;
	   s->y=0;
		 s->v=rand()%4+2;
return s;

}
int levelyouchoose(char level[10]){
	int num;
if(strcmp(level,"1")==0){
		num=2;
		return num;
		}
		if(strcmp(level,"2")==0){
		num=3;
		return num;
		}
		if(strcmp(level,"3")==0){
		num=4;
		return num;
		}
		return 2;

}
int timetochange(int num){

switch(num){
case'1': return 500;
case'2': return 700;
case '3':return 800;


}

return 500;
}






int game(int score,int high,int m,char name[10],char level[10]){
	int score1;

   int leftlife=3;
	int second=0;
	int former;
	struct Ball *pree;
  		char string[10];
		struct Ball *p,*p3,*rear,*p2,*s2,*s3;
		struct Ball *s,*pre,*head2=NULL;
		struct Ball *p1,*end,*end2,*rear2,*pre2;
	struct Ball *head=NULL;
	int y=0;
	int limit1=0,limit2=0;
	int t1=30;
	int f=0;
	int endnow,startnow=0;
	int i=0,c=0,d=0;
	int num=2;
  int t;
  int backnow;
  int quit=0;
int num3=500;
  int k3=0,k4=4;
		back();
		menu(high,name,score,leftlife);
		FlushBatchDraw();
		num=levelyouchoose(level);
		num3=timetochange(num);
		
		
		
	for(i=0;i<num;i++){

		p3=(struct Ball*)malloc(sizeof(struct Ball));
		
		p3->num=1;
	   
		
			p3->x=rand()%605+10;
			
		
	   p3->y=0;
	   	 p3->v=rand()%4+2;
	   if(head==NULL){
		   head=p3;
		   rear=p3;
	   pree=head;}
	   else{
			   rear->next=p3;
				pree=rear;
			   rear=p3;}
	   }  
end=rear;
rear->next=NULL;
  p=head;
pre=p;
int num2=num*2;
if(num==4){
num2=6;
}
for(i=0;i<num2;i++){
	p3=(struct Ball*)malloc(sizeof(struct Ball));
		
		p3->num=2;
		
	  
			p3->x=rand()%605+10;
			
	   p3->y=0;
	  	 p3->v=rand()%4+2;
	   if(head2==NULL){
		   head2=p3;
		   rear2=p3;
	   pree=head;}
	   else{
			   rear2->next=p3;
			   pree=rear2;
			   rear2=p3;}

}
end2=rear2;
rear2->next=NULL;
  p2=head2;
pre2=p2;
			
		while(true){
			if(MouseHit()){
				startnow=mouse();}
		
		if(startnow==10){
			t=GetTickCount();
			break;}
		else{
			if(startnow==3){
			closegraph();
			}
			else{
				if(startnow==0)
				{return 11;}
			}
		}
		}
	
		while(Time(t1,t)>=0){
		
	
				endnow=mouse();



			if(endnow==0){
			
		return -1;
			
			}
			else{
				if(endnow==6){
				saveyourgame(score,m,name);
				}


			else{
				if(endnow==3){
				free(p);
				exit(0);}
				else{
					if(endnow==4){
					
					saveornot(score,name);}
					
					else{
						if(endnow==5){
							while(true){
							backnow=mouse();
							if(backnow==10){
							break;}
							else{
								if(backnow==3){
								free(p);
								free(p2);
								exit(0);
								}
								else{
									if(backnow==0){
										return -1;
									}
									else{
										if(backnow==6){
										saveyourgame(score,m,name);
											outtextxy(300,300,"saved");
										}
										else{
											if(backnow==4){
											saveornot(score,name);
											outtextxy(300,300,"saved");
											}
										}
									}
								}
							}
							}
						}
					}
				}
			}
			}
			if(((t1-(GetTickCount()-Time(t1,t)))/num3)%2==0){
			
			for(p=head;p!=NULL;p=p->next){
			
				p->num=1;
			
					}
			for(p2=head2;p2!=NULL;p2=p2->next){
		
				p2->num=2;
				
				
			}
			p=head;
		p2=head2;
        
		}
        

			else{

			for(p=head;p!=NULL;p=p->next){
			
				p->num=0;
			
					}
			for(p2=head2;p2!=NULL;p2=p2->next){
		
				p2->num=0;
				
				
			}
			
			p2=head2;
			p=head;
	
		}

				
		for(p=head;p!=NULL;p=p->next){

		if(p->num==1&&p->y>20)
		{   
				booming(p->x,p->y);
			former=leftlife;
		 	   leftlife=areyoustillaliveornot(m,leftlife,p->x,p->y);
			   p->y=p->y+p->v;  
               if(leftlife!=former){
				   score=score-100;
			   m=280;
					f=rand()%1;
					if(limit1==2){
					f=3;
					}
			if(f==0){
				limit1++;
			 s=creat(1);
				   s2=creat(1);
				   end->next=s;
				   s->next=s2;
				   s2->next=NULL;
				   end=s2;}
				   
				   else{
					   if(f==1){
					   limit1+=2;
						   s=creat(1);
				   s2=creat(1);
				   s3=creat(1);
				   end->next=s;
				   s->next=s2;
				   s2->next=s3;
				   s3->next=NULL;
				   end=s3;}
				   //添加
			
}
			   	if(p==head){
		head=head->next;
	
		
		
	s=creat(1);
	   end->next=s;
	   s->next=NULL;
	   end=s;

	   p1=p;
	   free(p1);
	     p=head;
	   pre=head;
		booming(head->x,head->y);
		
		}
		else{

	
	s=creat(1);
	   end->next=s;
	   s->next=NULL;
	   end=s;
	   pre->next=p->next;
	   p1=p;
	   free(p1);
	
	p=pre;
	
	}
	 
	
			   
			   }
			       
	if(p->y>290){
					 

		if(p==head){
		head=head->next;
	
		
		
	s=creat(1);
	   end->next=s;
	   s->next=NULL;
	   end=s;

	   p1=p;
	   free(p1);
	     p=head;
	   pre=head;
		booming(head->x,head->y);
		
		}
		else{

	
	s=creat(1);
	   end->next=s;
	   s->next=NULL;
	   end=s;
	   pre->next=p->next;
	   p1=p;
	   free(p1);
	
	p=pre;

	}
	
	}}
	else{	
      
	          setfillcolor(RGB(0,222,232));
					fillcircle(p->x,p->y,15);
            	        p->y=p->y+p->v; 
			if(p->y>290){
		if(p==head){
		head=head->next;
	
		s=creat(1);
	   end->next=s;
	   s->next=NULL;
	   end=s;

	   p1=p;
	   free(p1);
	    p=head;
	   pre=head;
	
					fillcircle(head->x,head->y,15);
		
		
		 
		
		}
		else{
	
	s=creat(1);
	   end->next=s;
	   s->next=NULL;
	   end=s;
	   pre->next=p->next;
	   p1=p;
	   free(p1);
	p=pre;

	}
	
	}
			else{	
		  pre=p;
			}   


                }
                                	
}	//炸弹
    
	  for(p2=head2;p2!=NULL;p2=p2->next){
	  
		   if(p2->num==2&&p2->y>20){
   				caking(p2->x,p2->y);
				score1=score;
				score=areyouscoreornot(m,score,p2->x,p2->y);
							p2->y=p2->y+p2->v;

							if(score1!=score){
f=rand()%1;
if(limit2==3){
f=3;}
	if(f==0){limit2++;
			 s=creat(2);
				   s2=creat(2);
				   end2->next=s;
				   s->next=s2;
				   s2->next=NULL;
				   end2=s2;}
				   
				   else{
					   if(f==1){
						   limit2+=2;
					   s=creat(2);
				   s2=creat(2);
				   s3=creat(2);
				   end2->next=s;
				   s->next=s2;
				   s2->next=s3;
				   s3->next=NULL;
				   end2=s3;}
				   //添加
			
}


							if(p2==head2){
		head2=head2->next;
	
		
		
	s=creat(2);
	   end2->next=s;
	   s->next=NULL;
	   end2=s;

	   p1=p2;
	   free(p1);
	     p2=head2;
	   pre2=head2;
	 caking(head2->x,head2->y);
		
		}
		else{

	
	s=creat(2);
	   end2->next=s;
	   s->next=NULL;
	   end2=s;
	   pre2->next=p2->next;
	   p1=p2;
	   free(p1);
	
	p2=pre2;
	
	}
							
							
							}
			



			if(p2->y>290){
				 


		if(p2==head2){
		head2=head2->next;
		s=(struct Ball*)malloc(sizeof(struct Ball));
		
	s=creat(2);
	   end2->next=s;
	   s->next=NULL;
	   end2=s;

	   p1=p2;
	   free(p1);
	    p2=head2;
	   pre2=head2;
		caking(head2->x,head2->y);
		}
		else{
	
			s=creat(2);
	   end2->next=s;
	   s->next=NULL;
	   end2=s;
	   pre2->next=p2->next;
	   p1=p2;
	   free(p1);
	
	p2=pre2;
	
		}
	
			}//落地
			else{
			pre2=p2;
		
			}			
		   }
	  
				else		
				{setfillcolor(RGB(0,222,232));
					fillcircle(p2->x,p2->y,15);
            	        p2->y=p2->y+p2->v; 
			if(p2->y>280){
		if(p2==head2){
		head2=head2->next;

	s=creat(2);
	   end2->next=s;
	   s->next=NULL;
	   end2=s;

	   p1=p2;
	   free(p1);
	    p2=head2;
	   pre2=head2;
		caking(head2->x,head2->y);
		
		
		}
		else{

	 s=creat(2);
	   end2->next=s;
	   s->next=NULL;
	   end2=s;
	   pre2->next=p2->next;
	   p1=p2;
	   free(p1);
	p2=pre2;

				
				
				}
							
		
	  
	  
	  }
			else{
			pre2=p2;
			}
	  }
	  
	  }



	  //
	    if(leftlife<=0){
			
			
           
			
		break;}
		  p=head;
	  pre=p;
		p2=head2;
		pre2=p2;
		m=control(m);
		FlushBatchDraw();
		back();
		menu(high,name,score,leftlife); 
	

	
}
back();
		menu(high,name,score,leftlife); 
		if(leftlife==0){
			InputBox(string,20,"死了！，输入yes保存,输入其他不保存");}
		else{
		InputBox(string,20,"时间到了！，输入yes保存,输入其他不保存");
		}
char yes[]="yes";
if(strcmp(string,yes)==0&&endnow!=0){
saveornot(score,name);
}
free(p);
free(p2);
cleardevice();
return score;		}





int menu2(){
	char strhistory[10];
	FILE *fp;
	int max;
	int history[10];
	int i3=0,i5;
	int num;
    char exit[]="返回";
	char name[10][10];
	char names[]="姓名";
	char grades[]="成绩";
   int temp;
   char allofrecords[]="排行榜";
   char exchange[10]="";
	fp=fopen("design.txt","r");
    settextcolor(WHITE);
		setbkmode(TRANSPARENT);
	while(!feof(fp)){
		fscanf(fp,"%d  %s\n",&history[i3],name[i3]);
		
		i3++;
	}
	fclose(fp);
	num=i3;
for(i3=0;i3<num-1;i3++){
		for(i5=0;i5<num;i5++){
			if(history[i5]<history[i5+1]){
				temp=history[i5];
				strcpy(exchange,name[i5]);
				history[i5]=history[i5+1];
				strcpy(name[i5],name[i5+1]);
				history[i5+1]=temp;
			strcpy(name[i5+1],exchange);}
			}
		
}
max=history[0];
outtextxy(200,5,allofrecords);
outtextxy(180,50,names);
outtextxy(300,50,grades);
outtextxy(100,300,exit);
for(i3=0;i3<4;i3++){  
outtextxy(180,50*(i3+2),name[i3]);
}
for(i3=0;i3<4;i3++){
	if(50*(i3+2)>640){
	break;
	}	 
	itoa(history[i3],strhistory,10);
		 outtextxy(300,50*(i3+2),strhistory);
		 
}
	return max;
	}




void restart(){
IMAGE re;
loadimage(&re,"reset.bmp");
HDC dstDC=GetImageHDC();
HDC srcDC=GetImageHDC(&re);
TransparentBlt(dstDC,150,400,re.getwidth(),re.getheight(),srcDC,0,0,re.getwidth(),re.getheight(),RGB(0,0,0));
}

void srart(){//开始
IMAGE st;
loadimage(&st,"start3.bmp");
HDC dstDC=GetImageHDC();
HDC srcDC=GetImageHDC(&st);
TransparentBlt(dstDC,50,400,st.getwidth(),st.getheight(),srcDC,0,0,st.getwidth(),st.getheight(),RGB(0,0,0));



}

void pause(){//暂停
IMAGE pa;
loadimage(&pa,"pause2.bmp");

HDC dstDC=GetImageHDC();
HDC srcDC=GetImageHDC(&pa);
TransparentBlt(dstDC,400,400,pa.getwidth(),pa.getheight(),srcDC,0,0,pa.getwidth(),pa.getheight(),RGB(255,255,255));

}

void save1(){//保存成绩
IMAGE s1;
loadimage(&s1,"save.bmp");

HDC dstDC=GetImageHDC();
HDC srcDC=GetImageHDC(&s1);
TransparentBlt(dstDC,320,400,s1.getwidth(),s1.getheight(),srcDC,0,0,s1.getwidth(),s1.getheight(),RGB(0,0,0));

}
void save2(){//保存游戏
IMAGE s2;
loadimage(&s2,"save3.bmp");

HDC dstDC=GetImageHDC();
HDC srcDC=GetImageHDC(&s2);
TransparentBlt(dstDC,250,400,s2.getwidth(),s2.getheight(),srcDC,0,0,s2.getwidth(),s2.getheight(),RGB(0,0,0));

}
void menu(int high,char name[],int score,int leftlife){
	char  highest[]="最高得分: ";
	char life[]="剩余碗数";
	char  points[]="得分 : ";
 	char	gametime[]="游戏时间 :     ";
    char yourname[]="用户名:  ";
    
   

 	exitbutton();
	
char strscore[10];
char strlife[10];
char strhigh[10];
save2();
itoa(score,strscore,10);
itoa(leftlife,strlife,10);
itoa(high,strhigh,10);
    setlinecolor(GREEN);
	settextcolor(BLACK);

    line(0,350,640,350);
	setbkmode(TRANSPARENT);
	outtextxy(390,300,strhigh);
	outtextxy(300,460,life);
	outtextxy(390,460,strlife);
	outtextxy(300,300,highest);
	outtextxy(500,300,gametime);
	outtextxy(200,300,points);
	outtextxy(50,300,yourname);
	outtextxy(110,300,name);
srart();
save1();
	restart();
	pause();
    
	
  outtextxy(240,300,strscore);
 

}/*菜单选项*/

int loadscore(){
FILE *fps;
int score;
fps=fopen("loadscore.txt","r");
fscanf(fps,"%d",&score);
fclose(fps);
return score;
}
int loadposition(){
FILE *fpp;
int pos;
fpp=fopen("loadposition.txt","r");
fscanf(fpp,"%d",&pos);
fclose(fpp);
return pos;



}


void main(){ 
char string[100];
char creater[]="按任意键结束";
int point=0;   
int m=280; 
char level[10];
int high=0;
int num=10;
FILE *fpn;
int quit=0;
    char gameover[]="游戏结束";
		srand((unsigned)time(NULL));
		initgraph(640,480);
	
		high=back2();
		if(back2()==7){
			high=highest();
		point=loadscore();
		m=loadposition();
		fpn=fopen("loadname.txt","r");
		fscanf(fpn,"%s",string);
		fclose(fpn);
	InputBox(level,20,"输入想玩的等级，最高3级，难度依次增加");
		}
		else{	
		InputBox(string,20,"输入用户名");	
		InputBox(level,20,"输入想玩的等级，最高3级，难度依次增加");
		}		BeginBatchDraw();
		FlushMouseMsgBuffer();
		while(true){
	    point=game(point,high,m,string,level);	
		cleardevice();

			point=0;
		}
	
		cleardevice();
	
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		EndBatchDraw();
		FlushMouseMsgBuffer();
		getch();
	  	closegraph();
  
}


//读取游戏，保存游戏，界面美观，按钮的切换。
