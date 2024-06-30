# include "iGraphics.h"
#include<time.h>
int x = 100, y =100, r =80;
char level[100];
int chx = 1;
int rgb[3];
int rgb1[3];
int rgb2[3];
int rgb3[3];
double px[3] = {380+60,380+60,444+60};
double py[3] = {360+80,440+80,400+80};
int succes_no1 = 9,succes_no2 = 10,succes_no3 = 11;
int cur = 0,cug = 0,cub = 0;
int lvl = 0;
int cnt = 0;
int rx = 0;
int slide= 0;
int greet = 1;
int succes = 1;
int move = 1;
int position[4][2] = {200,590,590,410,590,590,200,410};
int succes_cnt = 0;
int lvl_state = 0;
int mainstate = 1;
int red1x =200 ,red1y = 590,red2x =590 ,red2y =410 ;
int blu1x =590 ,blu1y =590 ,blu2x =200 ,blu2y =410 ;
int gre1x =286,gre1y =549 ,gre2x = 481 ,gre2y =448;
int yel1x = 0,yel1y = 0,yel2x = 0,yel2y = 0;
int rectangledx = 130,rectangledy = 30;
int flag = 9;
int startx = -1,starty = -1;
int succescnt_change = 0;
char pc[1][20] = {"pic\\pc.bmp"};
int hitted = 0;
int somoy = 16;
int blackcnt = 0;
int tm = 1;
char minute[100];
char seconds[100];
typedef struct{
    int xco;
    int yco;
}point;
point redp[1000000];
point grep[1000000];
point blup[1000000];
point yelp[1000000];
int i = 1;
int lagging =20;
int tempx = 0;
int tempy = 0;
int lengthred = 0;
int lengthblu = 0;
int lengthgre = 0;
int lengthyel = 0;
int hitchng = 1;
int lngth = 0;

//srand(time(0));
/*
int chrd = 0;
int red1x = rand()%351 +310;
int red1y = rand()%351 +310;
int red2x = rand()%351 +310;
int red2y = rand()%351 +310;


int gre1x = rand()%351 +310;
int gre1y = rand()%351 +310;
int gre2x = rand()%351 +310;
int gre2y = rand()%351 +310;


int blu1x = rand()%351 +310;
int blu1y =rand()%351 +310 ;
int blu2x = rand()%351 +310;
int blu2y = rand()%351 +310
*/

/*
	function iDraw() is called again and again by the system.

	*/
void reset(){
    slide++;
}
void iDraw() {
	//place your drawing codes here

    if (slide <= 4 && slide > 0){
        iClear();
    }
    else{
        slide = 0;
        iPauseTimer(0);
    }
	if(lvl == 0){
        iClear();
        greet = 1;
        iShowBMP(0,0,pc[0]);
        iSetColor(255,153,51);
        iFilledCircle(400+60,480,r,1000);
        iSetColor(224,224,224);
        iFilledPolygon(px,py,3);
        //iSetColor(255,153,51);
        //iFilledRectangle(340,254,120,50);
        iSetColor(255,153,51);
        iText(345+60,270+80,"Play Game",GLUT_BITMAP_TIMES_ROMAN_24);
        mainstate = 1;
        succes_cnt = 0;
        succes = 1;

        //printf("Followimng");


	}
	else if(lvl == 1){
            greet = -1;
        //iSetColor(0,0,0);
        //iFilledRectangle(0, 0, 800, 800);

        // drawing level number
        iSetColor(156, 158, 141);
        iFilledRectangle(0,650,900,253);
        iFilledRectangle(0,0,900,350);
        iFilledRectangle(0,0,150,650);
        iFilledRectangle(650,0,250,650);
        iSetColor(75, 77, 63);
        iFilledRectangle(350,740,170,40);
	    iSetColor(234, 237, 216);
        sprintf(level, "%d", lvl);
	    iText(360,750,"LEVEL -->>",GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(500,750,level,GLUT_BITMAP_TIMES_ROMAN_24);

	    //drawing main menu return bar
	            sprintf(minute,"%d",tm/60);
        sprintf(seconds,"%d",tm%60);
        //iText(270,280,"Time Taken >>    : ",GLUT_BITMAP_TIMES_ROMAN_24);
        //iText(430,280,minute,GLUT_BITMAP_TIMES_ROMAN_24);
        //iText(460,280,seconds,GLUT_BITMAP_TIMES_ROMAN_24);
	    iSetColor(75, 77, 63);
	    iFilledRectangle(680,811,180,40);
	    iFilledRectangle(683,723,180,40);
	    iFilledRectangle(687,635,180,40);
	    iSetColor(255, 255, 255);
	    iText(700,648,"Level Passed",GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(690,820,"Main Menu",GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(743,735,minute,GLUT_BITMAP_TIMES_ROMAN_24);
	    //iText(700,725,seconds,GLUT_BITMAP_TIMES_ROMAN_24);
	    iSetColor(240, 242, 216);
	    iText(723,772,"Time",GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(764,738,":",GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(782,735,seconds,GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(730,735,"0",GLUT_BITMAP_TIMES_ROMAN_24);

        //drawing large rectangle

        iSetColor(255,255,255);
        iRectangle(150,350,500,300);//drawing large rectangle
        //iLine(280,370,280,630);
        //iLine(480,370,480,630);
        //iLine(170,550,630,550);
        //iLine(170,450,630,450);
        iSetColor(255,0,0);
        iFilledCircle(200,590,15);//drawing red dot
        iFilledCircle(590,410,15);
        iSetColor(cur,cug,cub);
        iFilledCircle(x,y,7,1000);
        //printf("%d %d %d",cur,cug,cub);
        //iFilledCircle(x,y,5,1000);
        //iSetColor(0,255,0);
        //iFilledCircle(220,410,15);
        iSetColor(0,0,255);
        iFilledCircle(590,590,15);//drawing blue dot
        iFilledCircle(200,410,15);

        iSetColor(0,255,0); //drawing green dot
        iFilledCircle(gre1x,gre1y,15);
        iFilledCircle(gre2x,gre2y,15);
        greet = 1;
        lvl_state = lvl;
        //if(succes_cnt == 2)
                            iSetColor(75, 77, 63);
        iFilledRectangle(660,210,130,40);
        //iFilledRectangle(256,266,300,60);
        iSetColor(234, 237, 216);
        iText(670,222,"Next Level",GLUT_BITMAP_TIMES_ROMAN_24);
        //iText(270,280,"Time Taken >>    : ",GLUT_BITMAP_TIMES_ROMAN_24);
        //iText(430,280,minute,GLUT_BITMAP_TIMES_ROMAN_24);
        //iText(460,280,seconds,GLUT_BITMAP_TIMES_ROMAN_24);

        if(succes_cnt <3){
            iSetColor(156, 158, 141);
            //iFilledRectangle(253,436,300,100);
            //iFilledRectangle(256,266,400,60);
            iFilledRectangle(687,635,180,40);
            iFilledRectangle(660,210,140,50);

        }
        else iPauseTimer(2);

        if(hitted && flag == -1){
                printf(" hitted in idraw \n");
                     iSetColor(0,0,0);
                    iFilledCircle(tempx,tempy,10);
                    //iFilledCircle(p[i+2].xco,p[i+2].yco,10);
                if(lagging>0 && i>0){
                        printf("value of length is %d \n",lngth);
                    //if( p[i].xco < startx || p[i].yco < starty) lagging = 0;
                    iSetColor(0,0,0);
                    iFilledCircle(redp[i].xco,redp[i].yco,10);
                    lagging--;
                    lngth--;
                    i--;
                    printf("value of i is %d /n",i);
                    //printf("value of p[i].x is %d \n  value of p[i].y is %d \n",p[i].xco,p[i].yco);
                }
                else {
                        if(i == 0) {
                            succes = 1;
                            printf("value of i is 0  extraaaaaaaaaa\n");
                        }
                    if((i-5)>=0){
                    x = redp[i-5].xco;
                    y = redp[i-5].yco;
                    }
                    else {
                        x = redp[i].xco;
                        y = redp[i].yco;
                    }
                    cur = 255;
                    cug = 0;
                    cub = 0;

                    hitted = 0;
                    hitchng = 1;
                }

        }
        if(hitted && flag == 1){
                printf(" hitted in idraw \n");
                     iSetColor(0,0,0);
                    iFilledCircle(tempx,tempy,10);
                    //iFilledCircle(p[i+2].xco,p[i+2].yco,10);
                if(lagging>0 && i>=0){
                        printf("value of length is %d \n",lngth);
                    //if( p[i].xco < startx || p[i].yco < starty) lagging = 0;
                    iSetColor(0,0,0);
                    iFilledCircle(blup[i].xco,blup[i].yco,10);
                    lagging--;
                    lngth--;
                    i--;
                    printf("value of i is %d /n",i);
                    //printf("value of p[i].x is %d \n  value of p[i].y is %d \n",p[i].xco,p[i].yco);
                }
                else {
                        if(i == 0) succes = 1;
                    if((i-5)>=0){
                    x = blup[i-5].xco;
                    y = blup[i-5].yco;}
                    else {
                        x = blup[i-1].xco;
                        y = blup[i-1].yco;
                    }
                    cur = 0;
                    cug = 0;
                    cub = 255;

                    hitted = 0;
                    hitchng = 1;
                }

        }
        if(hitted && flag == 0){
                printf(" hitted in idraw \n");
                     iSetColor(0,0,0);
                    iFilledCircle(tempx,tempy,10);
                    //iFilledCircle(p[i+2].xco,p[i+2].yco,10);
                if(lagging>0 && i>0){
                        printf("value of length is %d \n",lngth);
                    //if( p[i].xco < startx || p[i].yco < starty) lagging = 0;
                    iSetColor(0,0,0);
                    iFilledCircle(grep[i].xco,grep[i].yco,10);
                    lagging--;
                    lngth--;
                    i--;
                    printf("value of i is %d /n",i);
                    //printf("value of p[i].x is %d \n  value of p[i].y is %d \n",p[i].xco,p[i].yco);
                }
                else {
                    if(i == 0) succes = 1;
                    if((i-5)>=0){
                    x = grep[i-5].xco;
                    y = grep[i-5].yco;}
                    else {
                        x = grep[i-1].xco;
                        y = grep[i-1].yco;
                    }
                    cur = 0;
                    cug = 255;
                    cub = 0;

                    hitted = 0;
                    hitchng = 1;
                }

        }

	}

	else if(lvl == 2){


        red1x = 201;
        red1y = 435;
        red2x = 412;
        red2y = 600;
        yel1x =262 ;
        yel1y = 577;
        yel2x = 430;
        yel2y = 471;
        gre1x = 321;
        gre1y = 400;
        gre2x = 509;
        gre2y  = 596;
        blu2x = 523;
        blu2y = 404;
         iSetColor(156, 158, 141);
        iFilledRectangle(0,650,900,253);
        iFilledRectangle(0,0,900,350);
        iFilledRectangle(0,0,150,650);
        iFilledRectangle(650,0,250,650);
        iSetColor(75, 77, 63);
        iFilledRectangle(350,740,170,40);
	    iSetColor(234, 237, 216);
	    iText(700,648,"Level Passed",GLUT_BITMAP_TIMES_ROMAN_24);
        sprintf(level, "%d", lvl);
	    iText(360,750,"LEVEL -->>",GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(500,750,level,GLUT_BITMAP_TIMES_ROMAN_24);

        //drawing main menu button
        iSetColor(75, 77, 63);
        iFilledRectangle(687,635,180,40);
	    iFilledRectangle(680,811,180,40);
	    iFilledRectangle(683,723,180,40);
	    iSetColor(234, 237, 216);
	    iSetColor(234, 237, 216);
	    iText(700,648,"Level Passed",GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(690,820,"Main Menu",GLUT_BITMAP_TIMES_ROMAN_24);
	    	            sprintf(minute,"%d",tm/60);
        sprintf(seconds,"%d",tm%60);
        	    iSetColor(240, 242, 216);
	    iText(723,772,"Time",GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(743,735,minute,GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(764,738,":",GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(782,735,seconds,GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(730,735,"0",GLUT_BITMAP_TIMES_ROMAN_24);


        //drawing large rectangle
        iSetColor(255,255,255);
        iRectangle(150,350,500,300);//drawing large rectangle
        //iLine(280,370,280,630);
        //iLine(480,370,480,630);
        //iLine(170,550,630,550);
        //iLine(170,450,630,450);
        iSetColor(255,0,0);
        iFilledCircle(red1x,red1y,15);
        iSetColor(cur,cug,cub);
        iFilledCircle(x,y,7,1000);

        iSetColor(255,0,0);
        iFilledCircle(red2x,red2y,15);

        iSetColor(255,255,0);
        iFilledCircle(yel1x,yel1y,15);
        //iSetColor(0,0,255);
        iFilledCircle(yel2x,yel2y,15);
        iSetColor(0,255,0);
        iFilledCircle(gre1x,gre1y,15);
        iFilledCircle(gre2x,gre2y,15);
        iSetColor(0,0,255);
        iFilledCircle(blu1x,blu1y,15);
        iFilledCircle(blu2x,blu2y,15);
        //sprintf(times,"%d",tm);
        //iText(410,280,times,GLUT_BITMAP_TIMES_ROMAN_24);
                if(succes_cnt <4){
            iSetColor(156, 158, 141);
            iFilledRectangle(687,635,180,40);
            //iFilledRectangle(253,436,300,100);
            //iFilledRectangle(256,266,300,60);
            //iFilledRectangle(660,210,140,50);
        }
        else iPauseTimer(2);
                if(hitted && flag == -1){
                printf(" hitted in idraw \n");
                     iSetColor(0,0,0);
                    iFilledCircle(tempx,tempy,10);
                    //iFilledCircle(p[i+2].xco,p[i+2].yco,10);
                if(lagging>0 && i>0){
                        printf("value of length is %d \n",lngth);
                    //if( p[i].xco < startx || p[i].yco < starty) lagging = 0;
                    iSetColor(0,0,0);
                    iFilledCircle(redp[i].xco,redp[i].yco,10);
                    lagging--;
                    lngth--;
                    i--;
                    printf("value of i is %d /n",i);
                    //printf("value of p[i].x is %d \n  value of p[i].y is %d \n",p[i].xco,p[i].yco);
                }
                else {
                        if(i == 0) {
                            succes =1;
                            printf("i value is 0 \n");
                        }
                    if((i-5)>=0){
                    x = redp[i-5].xco;
                    y = redp[i-5].yco;
                    }
                    else {
                        x = redp[i].xco;
                        y = redp[i].yco;
                    }
                    cur = 255;
                    cug = 0;
                    cub = 0;

                    hitted = 0;
                    hitchng = 1;
                }

        }
                if(succes_cnt <3){
            iSetColor(156, 158, 141);
            //iFilledRectangle(253,436,300,100);
            //iFilledRectangle(256,266,400,60);
            iFilledRectangle(687,635,180,40);
            //iFilledRectangle(660,210,140,50);

        }
        if(hitted && flag == 1){
                printf(" hitted in idraw \n");
                     iSetColor(0,0,0);
                    iFilledCircle(tempx,tempy,10);
                    //iFilledCircle(p[i+2].xco,p[i+2].yco,10);
                if(lagging>0 && i>0){
                        printf("value of length is %d \n",lngth);
                    //if( p[i].xco < startx || p[i].yco < starty) lagging = 0;
                    iSetColor(0,0,0);
                    iFilledCircle(blup[i].xco,blup[i].yco,10);
                    lagging--;
                    lngth--;
                    i--;
                    printf("value of i is %d /n",i);
                    //printf("value of p[i].x is %d \n  value of p[i].y is %d \n",p[i].xco,p[i].yco);
                }
                else {
                        if(i == 0) succes = 1;
                    if((i-5)>=0){
                    x = blup[i-5].xco;
                    y = blup[i-5].yco;}
                    else {
                        x = blup[i-1].xco;
                        y = blup[i-1].yco;
                    }
                    cur = 0;
                    cug = 0;
                    cub = 255;

                    hitted = 0;
                    hitchng = 1;
                }

        }
        if(hitted && flag == 0){
                printf(" hitted in idraw \n");
                     iSetColor(0,0,0);
                    iFilledCircle(tempx,tempy,10);
                    //iFilledCircle(p[i+2].xco,p[i+2].yco,10);
                if(lagging>0 && i>0){
                        printf("value of length is %d \n",lngth);
                    //if( p[i].xco < startx || p[i].yco < starty) lagging = 0;
                    iSetColor(0,0,0);
                    iFilledCircle(grep[i].xco,grep[i].yco,10);
                    lagging--;
                    lngth--;
                    i--;
                    printf("value of i is %d /n",i);
                    //printf("value of p[i].x is %d \n  value of p[i].y is %d \n",p[i].xco,p[i].yco);
                }
                else {
                    if(i == 0) succes = 1;
                    if((i-5)>=0){
                    x = grep[i-5].xco;
                    y = grep[i-5].yco;}
                    else {
                        x = grep[i-1].xco;
                        y = grep[i-1].yco;
                    }
                    cur = 0;
                    cug = 255;
                    cub = 0;

                    hitted = 0;
                    hitchng = 1;
                }

        }
                if(hitted && flag == 2){
                printf(" hitted in idraw \n");
                     iSetColor(0,0,0);
                    iFilledCircle(tempx,tempy,10);
                    //iFilledCircle(p[i+2].xco,p[i+2].yco,10);
                if(lagging>0 && i>0){
                        printf("value of length is %d \n",lngth);
                    //if( p[i].xco < startx || p[i].yco < starty) lagging = 0;
                    iSetColor(0,0,0);
                    iFilledCircle(yelp[i].xco,yelp[i].yco,10);
                    lagging--;
                    lngth--;
                    i--;
                    printf("value of i is %d /n",i);
                    //printf("value of p[i].x is %d \n  value of p[i].y is %d \n",p[i].xco,p[i].yco);
                }
                else {
                    if(i == 0) succes = 1;
                    if((i-5)>=0){
                    x = yelp[i-5].xco;
                    y = yelp[i-5].yco;}
                    else {
                        x = yelp[i-1].xco;
                        y = yelp[i-1].yco;
                    }
                    cur = 0;
                    cug = 255;
                    cub = 0;

                    hitted = 0;
                    hitchng = 1;
                }

        }
/*
        if(hitted){
                printf(" hitted in idraw \n");
                     iSetColor(0,0,0);
                    iFilledCircle(tempx,tempy,10);
                    //iFilledCircle(p[i+2].xco,p[i+2].yco,10);
                if(lagging>0){
                        printf("value of length is %d \n",lngth);
                    //if( p[i].xco < startx || p[i].yco < starty) lagging = 0;
                    if(lagging >= lngth) {
                        lagging  = 3;
                        printf(" short length \n");
                    }
                    iSetColor(0,0,0);
                    iFilledCircle(redp[i].xco,redp[i].yco,10);
                    lagging--;
                    lngth--;
                    i--;
                    printf("value of i is %d /n",i);
                    //printf("value of p[i].x is %d \n  value of p[i].y is %d \n",p[i].xco,p[i].yco);
                }
                else {
                    x = p[i-5].xco;
                    y = p[i-5].yco;

                    hitted = 0;
                    hitchng = 1;
                }

        }
        */
	}

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
    printf("%d %d\n",mx,my);
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
    //iGetPixelColor(mx,my,rgb);
    //printf(" %d %d %d ",rgb[0],rgb[1],rgb[2]);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  &&succes &&(lvl == 1 )&& (!lngth) && succes_cnt <3 &&lvl_state && mx>151 && mx<651 && my<651 && my>351)  {
		//place your codes here
			//printf("x = %d, y= %d\n",mx,my);
		//x += 10;
		//y += 10;
		//stage = 1;
		redp[1].xco = -1;
        redp[1].yco = -1;
        grep[1].xco = -1;
        grep[1].yco = -1;
        blup[1].xco = -1;
        blup[1].yco = -1;
		x = mx;
		y = my;
		i = 1;
		//succes = 0;
		iGetPixelColor(mx,my,rgb);
		//printf("main state to level 1 \n");
		if(rgb[0] == 255 && rgb[1] == 0 && rgb[2] == 0) flag = -1;
		else if(rgb[0] == 0 && rgb[1] == 255 && rgb[2] == 0) flag = 0;
		else if (rgb[0] == 0 && rgb[1] == 0 && rgb[2] == 255) flag = 1;

		//printf(" value of flag is %d \n",flag);
		if(!(rgb[0]  == 0 && rgb[1] == 0 && rgb[2] == 0) && flag != succes_no1 && flag != succes_no2 && flag != succes_no3){
		cur = rgb[0];
		cug = rgb[1];
		cub = rgb[2];
		succes = 0;
		succescnt_change = 0;
		if(mx>(red1x-15) && mx <(red1x+15) && my >(red1y-15) && my< (red1y+15)) {
                //printf(" i am in red \n");
            x = red1x;
            y = red1y;
		}
		if(mx>(gre1x-15) && mx <(gre1x+15) && my >(gre1y-15) && my< (gre1y+15)) {
            x = gre1x;
            y = gre1y;
		}
		if(mx>(red2x-15) && mx <(red2x+15) && my >(red2y-15) && my< (red2y+15)) {
            x = red2x;
            y = red2y;
		}
		if(mx>(blu1x-15) && mx <(blu1x+15) && my >(blu1y-15) && my< (blu1y+15)) {
            x = blu1x;
            y = blu1y;
		}
		if(mx>(blu2x-15) && mx <(blu2x+15) && my >(blu2y-15) && my< (blu2y+15)) {
            x = blu2x;
            y = blu2y;
		}
		if(mx>(gre2x-15) && mx <(gre2x+15) && my >(gre2y-15) && my< (gre2y+15)) {
            x = gre2x;
            y = gre2y;
		}
		startx = mx;
		starty = my;
		move = 2;
		//printf("%d %d", startx,starty);
		}
		//printf("%d %d %d ",cur,cug,cub);
	}
	    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  &&succes &&(lvl == 2) &&succes_cnt <4 &&lvl_state && mx>151 && mx<651 && my<651 && my>351)  {
		//place your codes here
			//printf("x = %d, y= %d\n",mx,my);
		//x += 10;
		//y += 10;
		//stage = 1;
		i = 1;
		redp[1].xco = -1;
        redp[1].yco = -1;
        grep[1].xco = -1;
        grep[1].yco = -1;
        blup[1].xco = -1;
        blup[1].yco = -1;
        yelp[1].xco = -1;
        yelp[1].yco = -1;
		x = mx;
		y = my;
		//succes = 0;
		iGetPixelColor(mx,my,rgb);
		if(rgb[0] == 255 && rgb[1] == 0 && rgb[2] == 0) flag = -1;
		else if(rgb[0] == 0 && rgb[1] == 255 && rgb[2] == 0) flag = 0;
		else if (rgb[0] == 0 && rgb[1] == 0 && rgb[2] == 255) flag = 1;
		else if(rgb[0] == 255 && rgb[1]==255 && rgb[2] == 0) flag = 2;
		//printf(" value of flag is %d \n",flag);
		if(!(rgb[0]  == 0 && rgb[1] == 0 && rgb[2] == 0)){
		cur = rgb[0];
		cug = rgb[1];
		cub = rgb[2];
		succes = 0;
		succescnt_change = 0;
		startx = mx;
		starty = my;
		move = 2;
		//printf("%d %d", startx,starty);
		}
		//printf("%d %d %d ",cur,cug,cub);
	}
	// main page to levle page
			//printf(" value of greet is %d",greet);
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && (!lvl) && mx>310 && mx<491 && my>399 && my<567) {
		//place your codes here
		greet = -1;
		x = 0;
		y = 0;
        lvl++;
        slide++;
        lvl_state = 1;
        succes_cnt = 0;
        succes = 1;
        //succes_cnt = 0;

        iResumeTimer(0);
        tm = 0;
        iResumeTimer(2);

	}
	// back to main menu


	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && mainstate&& mx>680 && mx<859  && my>823 && my<857){
        lvl = 0;
        slide++;
        iResumeTimer(0);
        mainstate = 0;
        lvl_state = 0;
        cur = 0;
        cug = 0;
        cub = 0;
        succes = 1;
        tm = 0;
        iPauseTimer(2);
        printf("value if success is %d \n",succes);
	}
	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && succes_cnt >2 && mx >659 && mx< 787 && my>212 && my<251){
        lvl++;
        slide++;

        succes_cnt = 0;
        cur = 0;
        cug = 0;
        cub = 0;
        iResumeTimer(0);
        tm = 1;
        iResumeTimer(2);
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}


	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {
    //printf("value of succes is %d",succes);


	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//printf("Succes count is %d",succes_cnt);
   //printf("Succes count is %d\n",succes_cnt);

	if(flag == -1){
        if(startx>(red1x-15) && startx <(red1x+15) && starty >(red1y-15) && starty <(red1y+15))
            {
                 if(x>(red2x-15) && x<(red2x+15) && y>(red2y -15) && y< (red2y+15))
                 {
                       succes = 1;
                       if(!succescnt_change){
                       succes_cnt ++;
                       succescnt_change = 1;
                       }
        //printf("RED is SUCCESS FUL");
        //printf(" succes count is %d\n", succes_cnt);
                       if(succes){
                          move = 0;
                          lngth = 0;
                          succes_no1 = -1;
                          //printf("I am here\n");
                          if(key == GLUT_KEY_RIGHT) x+=move;
                          else if(key == GLUT_KEY_DOWN) y-=move;
                          else if(key == GLUT_KEY_UP) y+=move;
	                      else if(key == GLUT_KEY_LEFT) x-=move;

                         }
                 }
         }
        else if(startx>(red2x-15) && startx <(red2x+15) && starty >(red2y-15) && starty <(red2y+15))
        {
            if(x>(red1x-15) && x <(red1x+15) && y >(red1y-15) && y <(red1y+15))
                {
                succes = 1;
                if(!succescnt_change){
                       succes_cnt ++;
                       succescnt_change = 1;
                    }
                if(succes){
                            move = 0;
                            lngth = 0;
                            succes_no1 = -1;
                            //succes_cnt =1;
                            if(key == GLUT_KEY_RIGHT) x+=move;
	                        else if(key == GLUT_KEY_DOWN) y-=move;
                            else if(key == GLUT_KEY_UP) y+=move;
	                        else if(key == GLUT_KEY_LEFT) x-=move;

                            }
                }
        }
	}
		if(flag == 2){
        if(startx>(yel1x-15) && startx <(yel1x+15) && starty >(yel1y-15) && starty <(yel1y+15))
            {
                 if(x>(yel2x-15) && x<(yel2x+15) && y>(yel2y -15) && y< (yel2y+15))
                 {
                       succes = 1;
                       if(!succescnt_change){
                       succes_cnt ++;
                       succescnt_change = 1;
                       }
        //printf("RED is SUCCESS FUL");
        //printf(" succes count is %d\n", succes_cnt);
                       if(succes){

                          move = 0;
                          lngth = 0;
                          //printf("I am here\n");
                          if(key == GLUT_KEY_RIGHT) x+=move;
                          else if(key == GLUT_KEY_DOWN) y-=move;
                          else if(key == GLUT_KEY_UP) y+=move;
	                      else if(key == GLUT_KEY_LEFT) x-=move;

                         }
                 }
         }
        else if(startx>(yel2x-15) && startx <(yel2x+15) && starty >(yel2y-15) && starty <(yel2y+15))
        {
            if(x>(yel1x-15) && x <(yel1x+15) && y >(yel1y-15) && y <(yel1y+15))
                {
                succes = 1;
                if(!succescnt_change){
                       succes_cnt ++;
                       succescnt_change = 1;
                    }
                if(succes){
                            move = 0;
                            lngth = 0;
                            //succes_cnt =1;
                            if(key == GLUT_KEY_RIGHT) x+=move;
	                        else if(key == GLUT_KEY_DOWN) y-=move;
                            else if(key == GLUT_KEY_UP) y+=move;
	                        else if(key == GLUT_KEY_LEFT) x-=move;

                            }
                }
        }
	}
    else if(flag == 0){
        if(startx>(gre1x-15) && startx <(gre1x+15) && starty >(gre1y-15) && starty <(gre1y+15))
            {
                   if(x>(gre2x-15) && x<(gre2x+15) && y>(gre2y-15) && y<(gre2y+15))
                   {
                         succes = 1;
                    if(!succescnt_change){
                       succes_cnt ++;
                       succescnt_change = 1;
                       }
                         //printf("RED is SUCCESS FUL");
                        //printf(" succes count is %d\n", succes_cnt);
                          if(succes){
                                    move = 0;
                                    lngth = 0;
                                    succes_no2 = 0;
                                    //printf("I am here\n");
                                    if(key == GLUT_KEY_RIGHT) x+=move;
                                    else if(key == GLUT_KEY_DOWN) y-=move;
                                    else if(key == GLUT_KEY_UP) y+=move;
	                                else if(key == GLUT_KEY_LEFT) x-=move;

                                   }

                    }
         }
        else if(startx>(gre2x-15) && startx <(gre2x+15) && starty >(gre2y-15) && starty <(gre2y+15)){
            if(x>(gre1x-15) && x <(gre1x+15) && y >(gre1y-15) && y <(gre1y+15)){
                succes = 1;
             if(!succescnt_change){

                       succes_cnt ++;
                       succescnt_change = 1;
                    }
                if(succes){
                              move = 0;
                              lngth = 0;
                              succes_no2 = 0;

                            if(key == GLUT_KEY_RIGHT) x+=move;
	                        else if(key == GLUT_KEY_DOWN) {
                                       y-=move;
                                          //printf("NO CHANGE OF Y CO ORDINATE");
                                    }
	                          else if(key == GLUT_KEY_UP) y+=move;
	                       else if(key == GLUT_KEY_LEFT) x-=move;

                              }
            }
        }
	}
    else if(flag == 1){
        if(startx>(blu1x-15) && startx <(blu1x+15) && starty >(blu1y-15) && starty <(blu1y+15)){
        if(x>(blu2x-15) && x<(blu2x+15) && y>(blu2y-15) && y<(blu2y+15)){
        succes = 1;
                               if(!succescnt_change){
                       succes_cnt++;
                       succescnt_change = 1;
                       }
        //printf("RED is SUCCESS FUL");
        //printf(" succes count is %d\n", succes_cnt);
                 if(succes){
                        succes_no3 = 1;
                          move = 0;
                          lngth = 0;
                          //printf("I am here\n");
                          if(key == GLUT_KEY_RIGHT) x+=move;
                          else if(key == GLUT_KEY_DOWN) y-=move;
                          else if(key == GLUT_KEY_UP) y+=move;
	                      else if(key == GLUT_KEY_LEFT) x-=move;

                         }

	                                  }
         }
        else if(startx>(blu2x-15) && startx <(blu2x+15) && starty >(blu2y-15) && starty <(blu2y+15)){
            if(x>(blu1x-15) && x <(blu1x+15) && y >(blu1y-15) && y <(blu1y+15)){
                succes = 1;
            if(!succescnt_change){
                       succes_cnt ++;
                       succescnt_change = 1;
                       }
                if(succes){
                              move = 0;
                              lngth = 0;

                            if(key == GLUT_KEY_RIGHT) x+=move;
	                        else if(key == GLUT_KEY_DOWN) {
                                       y-=move;
                                          //printf("NO CHANGE OF Y CO ORDINATE");
                                    }
	                          else if(key == GLUT_KEY_UP) y+=move;
	                       else if(key == GLUT_KEY_LEFT) x-=move;

                          }
            }
        }
	}
	 if(x<645 && x>155 && y<645 && y>355){

	         if(key == GLUT_KEY_RIGHT && hitchng){
                    if(!succes){ move = 2;

                    lngth++;}
                    printf("value of length is %d \n" ,lngth);
                    iGetPixelColor(x+17,y,rgb2);
                    iGetPixelColor(x,y+15,rgb1);
                    iGetPixelColor(x,y-15,rgb3);
                   // printf("%d %d %d \n",rgb2[0],rgb2[1],rgb2[2]);
                    if(!((rgb2[0] == 0 && rgb2[1] == 0 && rgb2[2] == 0) || (rgb2[0] == cur && rgb2[1] == cug && rgb2[2] == cub)) && hitchng){
                        move = 0;
                        hitted = 1;
                        hitchng = 0;
                        tempx = x;
                        tempy = y;
                        lagging = 20;
                    }
                     if(!((rgb1[0] == 0 && rgb1[1] == 0 && rgb1[2] == 0) || (rgb1[0] == cur && rgb1[1] == cug && rgb1[2] == cub)) && hitchng){
                        hitted = 1;
                        hitchng = 0;
                        move = 0;
                        tempx = x;
                        tempy = y;
                        lagging  = 20;
                    }
                     if(!((rgb3[0] == 0 && rgb3[1] == 0 && rgb3[2] == 0) || (rgb3[0] == cur && rgb3[1] == cug && rgb3[2] == cub)) && hitchng){
                        hitted = 1;
                        hitchng = 0;
                        tempx = x;
                        move = 0;
                        tempy = y;
                        lagging  = 20;
                    }
                    x+=move;
                    //if(rgb[0] != cur && rgb[1] != cur)

        }
	else if(key == GLUT_KEY_DOWN && hitchng) {
        if(!succes){
                move = 2;
                lngth++;
        }
        printf("value of length is %d \n" ,lngth);
        iGetPixelColor(x,y-17,rgb2);
        iGetPixelColor(x+15,y,rgb1);
        iGetPixelColor(x-15,y,rgb3);
        if(!((rgb2[0] == 0 && rgb2[1] == 0 && rgb2[2] == 0) || (rgb2[0] == cur && rgb2[1] == cug && rgb2[2] == cub)) && hitchng){
                        move = 0;
                        hitted = 1;
                        hitchng = 0;
                        tempx = x;
                        tempy = y;
                        lagging = 20;
                        //printf("no movement \n");
        }
                            if(!((rgb1[0] == 0 && rgb1[1] == 0 && rgb1[2] == 0) || (rgb1[0] == cur && rgb1[1] == cug && rgb1[2] == cub)) && hitchng){
                                    move = 0;
                        hitted = 1;
                        hitchng = 0;
                        tempx = x;
                        tempy = y;
                        lagging  = 20;
                    }
                    if(!((rgb3[0] == 0 && rgb3[1] == 0 && rgb3[2] == 0) || (rgb3[0] == cur && rgb3[1] == cug && rgb3[2] == cub)) && hitchng){
                        hitted = 1;
                        hitchng = 0;
                        move = 0;
                        tempx = x;
                        tempy = y;
                        lagging  = 20;
                    }
    y-=move;
	}
	else if(key == GLUT_KEY_UP && hitchng){
        if(!succes){
            move = 2;
            lngth++;}
            printf("value of length is %d \n" ,lngth);

        iGetPixelColor(x,y+17,rgb2);
        iGetPixelColor(x+15,y,rgb1);
        iGetPixelColor(x-15,y,rgb3);
        if(!((rgb2[0] == 0 && rgb2[1] == 0 && rgb2[2] == 0) || (rgb2[0] == cur && rgb2[1] == cug && rgb2[2] == cub)) && hitchng ){
                        move = 0;
                        hitted = 1;
                        hitchng = 0;
                        tempx = x;
                        tempy = y;
                        lagging = 20;
                        //printf("no movement \n");
        }
                             if(!((rgb1[0] == 0 && rgb1[1] == 0 && rgb1[2] == 0) || (rgb1[0] == cur && rgb1[1] == cug && rgb1[2] == cub)) && hitchng){
                        hitted = 1;
                        hitchng = 0;
                        move = 0;
                        tempx = x;
                        tempy = y;
                        lagging  = 20;
                    }
                     if(!((rgb3[0] == 0 && rgb3[1] == 0 && rgb3[2] == 0) || (rgb3[0] == cur && rgb3[1] == cug && rgb3[2] == cub)) && hitchng){
                        hitted = 1;
                        hitchng = 0;
                        tempx = x;
                        move = 0;
                        tempy = y;
                        lagging  = 20;
                    }
    y+=move;
	}

	else if(key == GLUT_KEY_LEFT && hitchng) {
        if(!succes){
            move = 2;
            lngth++;}
            printf("value of length is %d \n" ,lngth);
        iGetPixelColor(x-17,y,rgb2);
                                    iGetPixelColor(x,y+15,rgb1);
                    iGetPixelColor(x,y-15,rgb3);
         if(!((rgb2[0] == 0 && rgb2[1] == 0 && rgb2[2] == 0) || (rgb2[0] == cur && rgb2[1] == cug && rgb2[2] == cub)) && hitchng)
            {
                        move = 0;
                        //printf("no movement \n");
                        hitted = 1;
                        hitchng = 0;
                        tempx = x;
                        tempy = y;
                        lagging = 20;

            }
                                 if(!((rgb1[0] == 0 && rgb1[1] == 0 && rgb1[2] == 0) || (rgb1[0] == cur && rgb1[1] == cug && rgb1[2] == cub)) && hitchng){
                        hitted = 1;
                        hitchng = 0;
                        tempx = x;
                        move = 0;
                        tempy = y;
                        lagging  = 20;
                    }
                     if(!((rgb3[0] == 0 && rgb3[1] == 0 && rgb3[2] == 0) || (rgb3[0] == cur && rgb3[1] == cug && rgb3[2] == cub)) && hitchng){
                        hitted = 1;
                        hitchng = 0;
                        move = 0;
                        tempx = x;
                        tempy = y;
                        lagging  = 20;
                    }
        x-=move;
	}

	}

	else if(x>645){
        //cur = 0;
        //y+=3;
    if(key == GLUT_KEY_DOWN) y-=move;
	else if(key == GLUT_KEY_UP) y+=move;
	else if(key == GLUT_KEY_LEFT) x-=move;
	}
	else if(x<=155){
        //cur = 0;
        //y-=3;
    if(key == GLUT_KEY_RIGHT) {
        //cur = 0;
        x+=move;
    }
	else if(key == GLUT_KEY_DOWN) y-=move;
	else if(key == GLUT_KEY_UP) y+=move;
	}
	else if(y>645){
        //cur = 0;

        if(key == GLUT_KEY_DOWN) y-=move;
        else if(key == GLUT_KEY_RIGHT) x+=move;
        else if(key == GLUT_KEY_LEFT) x-=move;
	}
	else if(y<355){
        //cur = 0;
        //x-=3;
    if(key == GLUT_KEY_RIGHT) x+=move;
	else if(key == GLUT_KEY_UP) y+=move;
	else if(key == GLUT_KEY_LEFT) x-=move;
	}


        if(move != 0){
        i++;
        if(flag == -1){
        redp[i].xco = x;
        redp[i].yco = y;
        }
        else if(flag == 0){
            grep[i].xco = x;
            grep[i].yco = y;
        }
        else if(flag == 1){
            blup[i].xco = x;
            blup[i].yco = y;
        }
        else if(flag == 2){
            yelp[i].xco = x;
            yelp[i].yco = y;
        }
        //printf("value of p[i].y is %d \n value of p[i].y is %d \n i value is %d \n",p[i].xco,p[i].yco ,i);
	}

	//printf("value of x and y is %d %d \n",x,y);
	printf("value of i is %d \n",i);
	//printf("%d %d\n" ,x,y);
	//printf("%d %d %d",cur,cug,cub);


}
void change(){
    r = r+chx;
    if (r >=90) {
            chx *=-1;
    }
    else if(r <= 60) chx = chx*-1;
}
void timetaken(){
    tm++;
}

int main() {
	//place your own initialization codes here.
	iSetTimer(100,reset);
	iSetTimer(30,change);
	iSetTimer(1000,timetaken);
	//iSetTimer(30,next);
	srand(time(0));
	iInitialize(900,900, "Color Matching Game");
	return 0;
}
