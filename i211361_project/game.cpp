//============================================================================
// Name        : AHMED MUJTABA.cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<fstream>//enables to read/write to a file 
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
 int time1=1800;//time in millisecond
 int p2=0, p1=0;
 int car=0;
 /*
 void taxi_selector(){
 	glClearColor(0.3/*Red Component/, 0.6,	//148.0/255/*Green Component/,
			0.4/*Blue Component/, 0 /*Alpha component/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); 
 	DrawString( 50, 500, "PRESS 3 FOR YELLOW TAXI", colors[DARK_MAGENTA]);
 	DrawSquare(200, 400, 70, colors[YELLOW]);
	DrawString( 600, 500, "PRESS 4 FOR RED TAXI", colors[DARK_MAGENTA]);
	DrawSquare(750, 400, 70, colors[RED]);
	if(p2 == 3){
	car=1;
	GameDisplay();}
	if(p2 == 4){
	car=2;
	GameDisplay();}
	glutSwapBuffers(); 
 	glutPostRedisplay();
 }
// DrawSquare( /*x/90 , /*y/510 ,30,colors[THISTLE]);



//int p1=0;
 void score33(){
 glClearColor(0.3/*Red Component/, 0.6,	//148.0/255/*Green Component/,
			0.4/*Blue Component/, 0 /*Alpha component/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update t
 	DrawString( 300, 700, "WELCOME TO RUSH HOUR", colors[DARK_MAGENTA]);
 	DrawString( 300, 510, "", colors[DARK_MAGENTA]);
 //CIN>>NAME
 	
 	DrawString( 300, 310, "PRESS 1 TO PLAY THE GAME", colors[DARK_MAGENTA]);
 	taxi_selector();
 	//if(p1){
 	DrawString( 300, 210, "PRESS 2 TO SEE LEADERBOARD", colors[DARK_MAGENTA]);
 	
 	glutSwapBuffers(); 
 	glutPostRedisplay();
 	
 	//}
//if(p1 == 1){ 
 //taxi_selector();
 //if(p1 == 2)
 //file handling
 //}
 }*/
 
 
 
 
 
 
 int score_array[100];
 int total_score=0;//score variable for 1 turn
 
void SetCanvasSize(int width=900, int height=900) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}





int passenger_dropped;//number of passengers dropped in 1 turn
int xI = 50, yI = 60; //coordinates of the taxi

void drawCar() {
	if(car == 1)
	//DrawSquare(xI+10, yI+10, 40, colors[RED]);
	DrawRoundRect(xI, yI,5,10,colors[OLIVE],37);
	if(car == 2)
	DrawRoundRect(xI, yI,5,10,colors[RED],37);
	glutPostRedisplay();
}
int x3=55, y3=700;//first line car
void drawCar2(){
	if(passenger_dropped>=0){
	DrawRoundRect(x3, y3,5,10,colors[ROSY_BROWN],37);
	glutPostRedisplay();
}}
int x4=275, y4=700;// second line car
void drawCar3(){
	if(passenger_dropped>=2){
	DrawRoundRect(x4, y4,5,10,colors[ORCHID],37);
	glutPostRedisplay();
}}
int x5=620, y5=700;// third line car
void drawCar4(){//will appear when we drop 2 passengers
	if(passenger_dropped>=4){
	DrawRoundRect(x5, y5,5,10,colors[INDIGO],37);
	glutPostRedisplay();
}}
int x6=45, y6=375;// horizontally moving car
void drawCar5(){//will appear when we drop 4 passengers
	if(passenger_dropped>=6){
	DrawRoundRect(x6, y6,5,10,colors[NAVY],37);
	glutPostRedisplay();
}}
int x7= 500, y7=225;
void drawCar6(){//will appear when we drop 4 passengers
	if(passenger_dropped>=8){
	DrawRoundRect(x7, y7,5,10,colors[CHOCOLATE],37);
	glutPostRedisplay();
}}

//int car=1;//variable to select red or yellow taxi
void scoring_cars(int x2, int y2)
{
//for(int i=0; i<90 ; i++){
if ( (xI> x2-40 && xI<x2+40) && (yI> y2-40 && yI < y2+40)){	//a function for the detection of collision of cars with the taxi
total_score -= 1;
}}
//cout<<total_score<<endl;





bool flag = true;// a boolean for the movement of cars 
// logic of the sample code applied that was provided to us
void moveCar() // random cars movement function
{
	if (y3 > 10 && flag) {	
		y3 -= 10;
		scoring_cars(x3, y3);
	//call to function that detects car and taxi collision 
		if(y3 < 100)
			
			flag = false;
//first 3 cars will move vertically
	}
	else if (y3 < 700 && !flag) {
		
		y3 += 10;
		scoring_cars(x3, y3);
		
		if (y3 > 700)
			flag = true;
			
	}
	//scoring_cars(xI, x3, yI, y3);
	//end
	if (y4 > 10 && flag) {
		y4 -= 10;
		if(passenger_dropped>=2)
		scoring_cars(x4, y4);
		if(y4 < 100)
			
			flag = false;

	}
	else if (y4 < 700 && !flag) {
		y4 += 10;
		if(passenger_dropped>=2)
		scoring_cars(x4, y4);
		if (y4 > 700)
			flag = true;
			
	}
	
	if (y5 > 10 && flag) {
		y5 -= 10;
		if(passenger_dropped>=4)
		scoring_cars(x5, y5);
		if(y5 < 100)
			
			flag = false;

	}
	else if (y5 < 700 && !flag) {
		y5 += 10;
		if(passenger_dropped>=4)//when passengers dropped are greater or equal tok 2 this cars axis will also be compared otherwise not
		scoring_cars(x5, y5);
		
		if (y5 > 700)
			flag = true;
	}
	//end
	
//this car will move horizontally when passengers will be more than 6
	if (x6 > 10 && flag) {
		x6 -= 15;
		if(passenger_dropped>=6)
		scoring_cars(x6, y6);
		if(x6 < 100)
			
			flag = false;

	}
	else if (x6 < 1010 && !flag) {
		x6 += 15;
		if(passenger_dropped>=6)
		scoring_cars(x6, y6);
		if (x6 > 900)
			flag = true;
	}
	//end
	//scoring_cars(xI, x6, yI, y6);
	bool flag2=true; bool flag3=false;
	if (x7 > 50 && flag2) {	//x7= 500, y7=225;
		x7 -= 7;
		if(passenger_dropped>=8){
		scoring_cars(x7, y7);}
		if(x7 < 50){
			
			flag2 = false;}

	}
	
	else {if (x7 < 500 && !flag3) {
		x7 = 500;
		if(passenger_dropped>=8){
		scoring_cars(x7, y7);}
		if (x7 > 400){
			flag3 = true;}
	}
}}

/*
 * Main Canvas drawing function.
 * */
int r1=180, r2=35, r4=675, r5=617, r10=160, r11=517,r8=970, r9=517,r6=670, r7=247, r12=5000, r13=5000, r14=5000, r15=5000, r16=5000, r17=5000;
int d13=4000, d14=4000, d15=4000, d16=4000, d17=4000, d18=4000, d19=4000, d20=4000, d21=4000, d22=4000, d23=4000, d24=4000, d25=4000, d26=4000;
//130 to 230 && 0 100
//625 to 725 && 580 680
//110 to 210 && 480 680
//920 to 1020 && 470 580
//620 to 720 && 190 300
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0.3/*Red Component*/, 0.6,	//148.0/255/*Green Component*/,
			0.4/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	//DrawSquare(400, 20, 40, colors[KHAKI]);
	
	//Green Square
	//for(int i=0;i<1;i++){
	//score33(1);}
	//Display Score
	
	DrawString( 50, 810, "Score= ", colors[DARK_MAGENTA]);
	DrawString( 150, 810, Num2Str(total_score), colors[DARK_MAGENTA]);
	DrawString( 250, 810, "Time= ", colors[DARK_MAGENTA]);
	DrawString( 350, 810, Num2Str((time1/10)), colors[DARK_MAGENTA]);
	DrawString( 400, 810, " seconds ", colors[DARK_MAGENTA]);
	DrawString( 600, 810, "Passengers dropped=", colors[DARK_MAGENTA]);
	DrawString( 900, 810, Num2Str(passenger_dropped), colors[DARK_MAGENTA]);
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawTriangle(300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE]); 
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)	//x=(10,1010) y=(30,800)
	DrawLine( 10 , 30,  10 , 800 , 1 , colors[MISTY_ROSE] );	
	DrawLine(1010, 30, 1010, 800, 1, colors[MISTY_ROSE]);
	DrawLine(100, 30, 100, 800, 1, colors[MISTY_ROSE]);
	DrawLine(170, 30, 170, 800, 1, colors[MISTY_ROSE]); 
	DrawLine(240, 30, 240, 800, 1, colors[MISTY_ROSE]);
	DrawLine(310, 30, 310, 800, 1, colors[MISTY_ROSE]);
	DrawLine(380, 30, 380, 800, 1, colors[MISTY_ROSE]);
	DrawLine(450, 30, 450, 800, 1, colors[MISTY_ROSE]);
	DrawLine(520, 30, 520, 800, 1, colors[MISTY_ROSE]);
	DrawLine(590, 30, 590, 800, 1, colors[MISTY_ROSE]);
	DrawLine(660, 30, 660, 800, 1, colors[MISTY_ROSE]);
	DrawLine(730, 30, 730, 800, 1, colors[MISTY_ROSE]);
	DrawLine(800, 30, 800, 800, 1, colors[MISTY_ROSE]);
	DrawLine(870, 30, 870, 800, 1, colors[MISTY_ROSE]);
	DrawLine(940, 30, 940, 800, 1, colors[MISTY_ROSE]);
	DrawLine(1010, 30, 1010, 800, 1, colors[MISTY_ROSE]);
	DrawLine(10, 30, 1010, 30, 1, colors[MISTY_ROSE]);
	DrawLine(10, 800, 1010, 800, 1, colors[MISTY_ROSE]);
	
	//DrawRectangle(int sx, int sy, int mx, int my, float *color)
	
	DrawSquare( /*x*/90 , /*y*/510 ,30,colors[THISTLE]);
	DrawSquare( 500 , 512 ,30,colors[THISTLE]); 
	DrawSquare( 750 , 615 ,30,colors[THISTLE]); 
	DrawSquare( 900 , 165 ,30,colors[THISTLE]); 
	DrawSquare( 500 , 165 ,30,colors[THISTLE]); 
	DrawSquare( 130 , 675 ,30,colors[THISTLE]); 
	DrawSquare( 930 , 675 ,30,colors[THISTLE]); 
	
	DrawTriangle(200, 510 , 240, 510 , 220 , 550, colors[DARK_GREEN]); 
	DrawTriangle(850, 510 , 890, 510 , 870 , 550, colors[DARK_GREEN]); 
	DrawTriangle(90, 166 , 130, 166 , 110 , 206, colors[DARK_GREEN]); 
	DrawTriangle(420, 670 , 460, 670 , 440 , 710, colors[DARK_GREEN]); 
	DrawTriangle(730, 240 , 770, 240 , 750 , 280, colors[DARK_GREEN]); 
	DrawTriangle(300, 33 , 340, 33 , 320 , 70, colors[DARK_GREEN]); 
	DrawTriangle(940, 33 , 980, 33 , 960 , 70, colors[DARK_GREEN]); 
	
	
	DrawRectangle( 90, 500, 150, 15, colors[BLACK]);
	DrawRectangle( /*x*/400, /*y*/500, 150, 15, colors[BLACK]);
	DrawRectangle( 850, 500, 150, 15, colors[BLACK]);//y max 850
	DrawRectangle( 90, 660, 150, 15, colors[BLACK]);
	DrawRectangle( 400, 660, 150, 15, colors[BLACK]);
	DrawRectangle( 850, 660, 150, 15, colors[BLACK]);
	DrawRectangle( 90, 150, 150, 15, colors[BLACK]);
	DrawRectangle( 400, 150, 150, 15, colors[BLACK]);
	DrawRectangle( 850, 150, 150, 15, colors[BLACK]);
	DrawRectangle( 90, 330, 150, 15, colors[BLACK]);
	DrawRectangle( 400, 330, 150, 15, colors[BLACK]);
	DrawRectangle( 850, 330, 150, 15, colors[BLACK]);
	DrawRectangle(660, 600, 150, 15, colors[BLACK]);
	DrawRectangle(660, 230, 150, 15, colors[BLACK]);
	//END OF OBSTACLES
	DrawRectangle(r10, r11, 10, 50, colors[BROWN]);
	DrawRectangle(r8, r9, 10, 50, colors[BROWN]);
	DrawRectangle(r6, r7, 10, 50, colors[BROWN]);
	DrawRectangle(r1, r2, 10, 50, colors[BROWN]);
	DrawRectangle(r4, r5, 10, 50, colors[BROWN]);
	DrawRectangle(r12, r13, 10, 50, colors[BROWN]);
	//drop point location
	DrawRectangle(d13, d14, 20,20, colors[SIENNA]);
	DrawRectangle(d15, d16, 20,20, colors[SIENNA]);
	DrawRectangle(d17, d18, 20,20, colors[SIENNA]);
	DrawRectangle(d19, d20, 20,20, colors[SIENNA]);
	DrawRectangle(d21, d22, 20,20, colors[SIENNA]);	
	
	//drawing random cars
	drawCar();
	drawCar2();
	drawCar3();
	drawCar4();
	drawCar5();
	drawCar6();
	//Draw lines between two points P1(x1,y1) and P2(x2,y2)
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color);

	glutSwapBuffers(); // do not modify this line..

}


/*void leaderboard(){
	glClearColor(0.3/*Red Component/, 0.6,	//148.0/255/*Green Component/,
			0.4/*Blue Component/, 0 /*Alpha component/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT);
	int line;
	ifstream myfile("leaderboard.txt");
	//myfile.open("leaderboard.txt",ios::out|ios::in|ios::app);
	for(int i=0;i<10;i++){
	getline(myfile,line);
	DrawString( 50,(810-(i*20)), line, colors[DARK_MAGENTA]);
	}
	myfile.close();
	glutSwapBuffers(); 
 	glutPostRedisplay();
}
*/
void instructions(){
	glClearColor(0.3/*Red Component*/, 0.4,	//148.0/255/*Green Component*/,
			0.2/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); 
	DrawString( 400, 800, "INSTRUCTIONS FOR THE GAME", colors[MAROON]);
	DrawString( 30, 700, "RED TAXI IS FASTER THAN YELLOW", colors[BLACK]);
	DrawString( 30, 640, "USE ARROW KEYS TO MOVE THE TAXI", colors[BLACK]);
	DrawString( 30, 580, "PRESS SPACE WHEN CAR IS ON THE PASSENGER TO HAVE THE LOCATION OF THE PASSENGER", colors[BLACK]);
	DrawString( 30, 520, "DROP LOCATION WILL APPEAR", colors[BLACK]);
	DrawString( 30, 460, "PRESS ENTER WHEN CAR IS ON THE LOCATION TO GET 10 POINTS", colors[BLACK]);
	DrawString( 30, 400, "YOU WILL GET", colors[BLACK]);
	DrawString( 30, 340, "AFTER DROPPING 2 PASSENGERS ENEMY CARS INCEMENT", colors[BLACK]);
	DrawString( 30, 280, "GAME WILL END AFTER 180 SECONDS", colors[BLACK]);
	DrawString( 30, 220, "DROP AS MUCH PASSENGERS AS YOU CAN TO GET HIGH SCORE", colors[BLACK]);
	DrawString( 30, 160, "BEST OF LUCK", colors[BLACK]);
	DrawString( 30, 100, "PRESS 1 TO GO BACK", colors[BLACK]);
	glutSwapBuffers(); 
 	glutPostRedisplay();
 	}
 	
 	
void taxi_selector(){//taxi color detecting function
 	glClearColor(0.4/*Red Component*/, 0.7,	//148.0/255/*Green Component*/,
			0.9/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); 
 	DrawString( 50, 500, "PRESS 3 FOR YELLOW TAXI", colors[YELLOW]);
 	DrawSquare(200, 400, 70, colors[YELLOW]);
	DrawString( 600, 500, "PRESS 4 FOR RED TAXI", colors[RED]);
	DrawSquare(750, 400, 70, colors[RED]);
	
	
	DrawString( 400, 200, "Best of luck!", colors[PEACH_PUFF]);
	glutSwapBuffers(); 
 	glutPostRedisplay();
 }
// DrawSquare( /*x/90 , /*y/510 ,30,colors[THISTLE]);



//int p1=0;
 void menu_display1(){
 glClearColor(0.2/*Red Component*/, 0.9,	//148.0/255/*Green Component*/,
			0.5/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update t
 	DrawString( 300, 700, "LET'S PLAY RUSH HOUR", colors[BLACK]);
 	
 	//DrawString( 300, 510, "", colors[DARK_MAGENTA]);
 	
 	DrawString( 280, 550, "PRESS 1 TO PLAY THE GAME", colors[DARK_MAGENTA]);

 	DrawString( 270, 400, "PRESS 2 TO SEE LEADERBOARD", colors[DARK_MAGENTA]);
 	
 	DrawString( 270, 250, "PRESS 5 TO SEE INSTRUCTIONS", colors[DARK_MAGENTA]);
 	
 	glutSwapBuffers(); 
 	glutPostRedisplay();

 }


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */
void score(int x, int y){
	if(((x<180 && x>280) && (y<490 && y>580)) || ((x<70 && x>150) && (y<490 && y>570)) || ((x<480 && x>560) && (y<490 && y>570)) || ((x<730 && x>810) && (y<590 && y>670)) || ((x<880 && x>960) && (y<140 && y>220)) || ((x<480 && x>560) && (y<140 && y>220)) || ((x<110 && x>190) && (y<650 && y>730)) || ((x<910 && x>990) && (y<650 && y>730)) || ((x<820 && x>920) && (y<490 && y>580)) || ((x<50 && x>170) && (y<130 && y>240)) || ((x<390 && x>500) && (y<640 && y>740)) || ((x<700 && x>810) && (y<210 && y>310)) || ((x<270 && x>370) && (y<3 && y>103)) || ((x<910 && x>1010) && (y<3 && y>103)) || ((x<170 && x>270) && (y<480 && y>520)) || ((x<370 && x>570) && (y<480 && y>520)) || ((x<820 && x>1010) && (y<480 && y>520)) || ((x<60 && x>260) && (y<640 && y>680)) || ((x<370 && x>570) && (y<640 && y>680)) || ((x<820 && x>1010) && (y<640 && y>680)) || ((x<60 && x>260) && (y<130 && y>170)) || ((x<370 && x>570) && (y<130 && y>170)) || ((x<820 && x>1020) && (y<130 && y>170)) || ((x<60 && x>260) && (y<310 && y>350)) || ((x<370 && x>570) && (y<310 && y>350)) || ((x<820 && x>1020) && (y<310 && y>350)) || ((x<630 && x>830) && (y<580 && y>620)) || ((x<630 && x>830) && (y<210 && y>250))){
	total_score-=2;
	}
	if((((d13<950 && d13>10) &&  (d14<750  && d14>50)) || ((d15<950 && d15>10)&&(d16<750  && d16>50)) || ((d17<950 && d17>10)&&(d18<750  && d18>50)) || ((d19<950 && d19>10)&&(d20<750  && d20>50)) || ((d21<950 && d21>10)&&(d22<750  && d22>50)))){
	if(((x<130 && x>230) && (y<0 && y>100)) || ((x<625 && x>725) && (y<580 && y>680)) || ((x<110 && x>210) && (y<480 && y>580)) || ((x<920 && x>1020) && (y<470 && y>580)) || ((x<620 && x>720) && (y<190 && y>300))){
	
	total_score-=5;
	}
}}
void NonPrintableKeys(int key, int x, int y) {//x=(10,1010) y=(30,800)
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {score(xI,yI);
		// what to do when left key is pressed...
		if(xI>30 && xI<980 ){//to make the car stay in the frame
		if(car == 1){
		xI -= 5;
		score(xI,yI);}
		if(car == 2){
		xI -= 10;
		score(xI,yI);}
		}
		else if(xI<=30 || xI>980){
		xI += (2*5);
		score(xI,yI);
		}

	} /*else*/ if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {score(xI,yI);
		if(xI>30 && xI<980){
		if(car == 1){
		xI += 5;
		score(xI,yI);
		}
		if(car == 2){
		xI += 10;
		score(xI,yI);
		}
		}
		else if(xI<30 || xI>=980){
		xI -= (2*5);
		score(xI,yI);
		}
	} /*else*/ if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {score(xI,yI);
		if(yI<760 && yI>=60 /*&& (yI<510 && yI<520)*/){
		if( car == 1){
		yI += 5;
		score(xI,yI);}
		if( car == 2){
		yI += 10;
		score(xI,yI);}
		}
		else if(yI>760 || yI<=60){
		yI -= (2*5);
		score(xI,yI);
		}
	}

	/*else*/ if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {score(xI,yI);
		if(yI<=760 && yI>60){
		if( car == 1){
		yI -= 5;
		score(xI,yI);}
		if( car == 2){
		yI -= 10;
		score(xI,yI);}
		}
		else if(yI>=760 || yI<60){
		yI += (2*5);
		score(xI,yI);
		}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
	

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
 
void PrintableKeys(unsigned char key, int x, int y) 
{	

		srand(unsigned(time(0)));//random number generator
		
		if(key == 49){//second display of the game
		glutDisplayFunc(taxi_selector);}
		
		if(key == 53){//GAME INSTUCTIONS
		glutDisplayFunc(instructions);}
		
		if(key == 51){//choosing car colors
		car=1;
		time1=1800;
		glutDisplayFunc(GameDisplay);}
		
		if(key == 52){//red car
		car=2;
		time1=1800;
		glutDisplayFunc(GameDisplay);}
		
		if(key == 50)//{//function for
		//glutDisplayFunc(leaderboard);}
		
	if (key == 'b'/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
		}
	if (key == 32){ //for picking up the passenger
	if((xI>170 && xI<270)&&(yI>35 && yI<95)){
		r1=10000, r2=10000;//passengers pixel out of display
		d13=(rand()%850 + 50), d14=(rand()%700 + 50);/*random location*/
		if(((d13<180 && d13>280) && (d14<490 && d14>580)) || ((d13<70 && d13>150) && (d14<490 && d14>570)) || ((d13<480 && d13>560) && (d14<490 && d14>570)) || ((d13<730 && d13>810) && (d14<590 && d14>670)) || ((d13<880 && d13>960) && (d14<140 && d14>220)) || ((d13<480 && d13>560) && (d14<140 && d14>220)) || ((d13<110 && d13>190) && (d14<650 && d14>730)) || ((d13<910 && d13>990) && (d14<650 && d14>730)) || ((d13<820 && d13>920) && (d14<490 && d14>580)) || ((d13<50 && d13>170) && (d14<130 && d14>240)) || ((d13<390 && d13>500) && (d14<640 && d14>740)) || ((d13<700 && d13>810) && (d14<210 && d14>310)) || ((d13<270 && d13>370) && (d14<3 && d14>103)) || ((d13<910 && d13>1010) && (d14<3 && d14>103)) || ((d13<170 && d13>270) && (d14<480 && d14>520)) || ((d13<370 && d13>570) && (d14<480 && d14>520)) || ((d13<820 && d13>1010) && (d14<480 && d14>520)) || ((d13<60 && d13>260) && (d14<640 && d14>680)) || ((d13<370 && d13>570) && (d14<640 && d14>680)) || ((d13<820 && d13>1010) && (d14<640 && d14>680)) || ((d13<60 && d13>260) && (d14<130 && d14>170)) || ((d13<370 && d13>570) && (d14<130 && d14>170)) || ((d13<820 && d13>1020) && (d14<130 && d14>170)) || ((d13<60 && d13>260) && (d14<310 && d14>350)) || ((d13<370 && d13>570) && (d14<310 && d14>350)) || ((d13<820 && d13>1020) && (d14<310 && d14>350)) || ((d13<630 && d13>830) && (d14<580 && d14>620)) || ((d13<630 && d13>830) && (d14<210 && d14>250)) || ((d13<130 && d13>230) && (d14<0 && d14>100)) || ((d13<625 && d13>725) && (d14<580 && d14>680)) || ((d13<110 && d13>210) && (d14<480 && d14>580)) || ((d13<920 && d13>1020) && (d14<470 && d14>580)) || ((d13<620 && d13>720) && (d14<190 && d14>300))){
		
		d13+=20	,	d14+=60;
		
		}}}	 
	if (key == 32){
	if((xI>645 && xI<700)&&(yI>580 && yI<650)){
		r4=12675, r5=12617;
		d15=(rand()%850 + 50), d16=(rand()%700 + 50);
		if(((d15<180 && d15>280) && (d16<490 && d16>580)) || ((d15<70 && d15>150) && (d16<490 && d16>570)) || ((d15<480 && d15>560) && (d16<490 && d16>570)) || ((d15<730 && d15>810) && (d16<590 && d16>670)) || ((d15<880 && d15>960) && (d16<140 && d16>220)) || ((d15<480 && d15>560) && (d16<140 && d16>220)) || ((d15<110 && d15>190) && (d16<650 && d16>730)) || ((d15<910 && d15>990) && (d16<650 && d16>730)) || ((d15<820 && d15>920) && (d16<490 && d16>580)) || ((d15<50 && d15>170) && (d16<130 && d16>240)) || ((d15<390 && d15>500) && (d16<640 && d16>740)) || ((d15<700 && d15>810) && (d16<210 && d16>310)) || ((d15<270 && d15>370) && (d16<3 && d16>103)) || ((d15<910 && d15>1010) && (d16<3 && d16>103)) || ((d15<170 && d15>270) && (d16<480 && d16>520)) || ((d15<370 && d15>570) && (d16<480 && d16>520)) || ((d15<820 && d15>1010) && (d16<480 && d16>520)) || ((d15<60 && d15>260) && (d16<640 && d16>680)) || ((d15<370 && d15>570) && (d16<640 && d16>680)) || ((d15<820 && d15>1010) && (d16<640 && d16>680)) || ((d15<60 && d15>260) && (d16<130 && d16>170)) || ((d15<370 && d15>570) && (d16<130 && d16>170)) || ((d15<820 && d15>1020) && (d16<130 && d16>170)) || ((d15<60 && d15>260) && (d16<310 && d16>350)) || ((d15<370 && d15>570) && (d16<310 && d16>350)) || ((d15<820 && d15>1020) && (d16<310 && d16>350)) || ((d15<630 && d15>830) && (d16<580 && d16>620)) || ((d15<630 && d15>830) && (d16<210 && d16>250)) || ((d15<130 && d15>230) && (d16<0 && d16>100)) || ((d15<625 && d15>725) && (d16<580 && d16>680)) || ((d15<110 && d15>210) && (d16<480 && d16>580)) || ((d15<920 && d15>1020) && (d16<470 && d16>580)) || ((d15<620 && d15>720) && (d16<190 && d16>300))){//condition if dropoff is on obstacle
		
		d15+=10	,	d16+=60;
		
		}}}//if this is the case change the coordinates
	if (key == 32){
	if((xI>130 && xI<190)&&(yI>480 && yI<550)){
		r10=12160,r11=12517;
		d17=(rand()%850 + 50), d18=(rand()%700 + 50);
		
		if(((d17<180 && d17>280) && (d18<490 && d18>580)) || ((d17<70 && d17>150) && (d18<490 && d18>570)) || ((d17<480 && d17>560) && (d18<490 && d18>570)) || ((d17<730 && d17>810) && (d18<590 && d18>670)) || ((d17<880 && d17>960) && (d18<140 && d18>220)) || ((d17<480 && d17>560) && (d18<140 && d18>220)) || ((d17<110 && d17>190) && (d18<650 && d18>730)) || ((d17<910 && d17>990) && (d18<650 && d18>730)) || ((d17<820 && d17>920) && (d18<490 && d18>580)) || ((d17<50 && d17>170) && (d18<130 && d18>240)) || ((d17<390 && d17>500) && (d18<640 && d18>740)) || ((d17<700 && d17>810) && (d18<210 && d18>310)) || ((d17<270 && d17>370) && (d18<3 && d18>103)) || ((d17<910 && d17>1010) && (d18<3 && d18>103)) || ((d17<170 && d17>270) && (d18<480 && d18>520)) || ((d17<370 && d17>570) && (d18<480 && d18>520)) || ((d17<820 && d17>1010) && (d18<480 && d18>520)) || ((d17<60 && d17>260) && (d18<640 && d18>680)) || ((d17<370 && d17>570) && (d18<640 && d18>680)) || ((d17<820 && d17>1010) && (d18<640 && d18>680)) || ((d17<60 && d17>260) && (d18<130 && d18>170)) || ((d17<370 && d17>570) && (d18<130 && d18>170)) || ((d17<820 && d17>1020) && (d18<130 && d18>170)) || ((d17<60 && d17>260) && (d18<310 && d18>350)) || ((d17<370 && d17>570) && (d18<310 && d18>350)) || ((d17<820 && d17>1020) && (d18<310 && d18>350)) || ((d17<630 && d17>830) && (d18<580 && d18>620)) || ((d17<630 && d17>830) && (d18<210 && d18>250)) || ((d17<130 && d17>230) && (d18<0 && d18>100)) || ((d17<625 && d17>725) && (d18<580 && d18>680)) || ((d17<110 && d17>210) && (d18<480 && d18>580)) || ((d17<920 && d17>1020) && (d18<470 && d18>580)) || ((d17<620 && d17>720) && (d18<190 && d18>300))){
		
		d17+=20	,	d18+=60;
		
		}}}
	if (key == 32){
	if((xI>940 && xI<1000)&&(yI>480 && yI<550)){
		r8=12675, r9=12617;
		d19=(rand()%850 + 50), d20=(rand()%700 + 50);
		
		if(((d19<180 && d19>280) && (d20<490 && d20>580)) || ((d19<70 && d19>150) && (d20<490 && d20>570)) || ((d19<480 && d19>560) && (d20<490 && d20>570)) || ((d19<730 && d19>810) && (d20<590 && d20>670)) || ((d19<880 && d19>960) && (d20<140 && d20>220)) || ((d19<480 && d19>560) && (d20<140 && d20>220)) || ((d19<110 && d19>190) && (d20<650 && d20>730)) || ((d19<910 && d19>990) && (d20<650 && d20>730)) || ((d19<820 && d19>920) && (d20<490 && d20>580)) || ((d19<50 && d19>170) && (d20<130 && d20>240)) || ((d19<390 && d19>500) && (d20<640 && d20>740)) || ((d19<700 && d19>810) && (d20<210 && d20>310)) || ((d19<270 && d19>370) && (d20<3 && d20>103)) || ((d19<910 && d19>1010) && (d20<3 && d20>103)) || ((d19<170 && d19>270) && (d20<480 && d20>520)) || ((d19<370 && d19>570) && (d20<480 && d20>520)) || ((d19<820 && d19>1010) && (d20<480 && d20>520)) || ((d19<60 && d19>260) && (d20<640 && d20>680)) || ((d19<370 && d19>570) && (d20<640 && d20>680)) || ((d19<820 && d19>1010) && (d20<640 && d20>680)) || ((d19<60 && d19>260) && (d20<130 && d20>170)) || ((d19<370 && d19>570) && (d20<130 && d20>170)) || ((d19<820 && d19>1020) && (d20<130 && d20>170)) || ((d19<60 && d19>260) && (d20<310 && d20>350)) || ((d19<370 && d19>570) && (d20<310 && d20>350)) || ((d19<820 && d19>1020) && (d20<310 && d20>350)) || ((d19<630 && d19>830) && (d20<580 && d20>620)) || ((d19<630 && d19>830) && (d20<210 && d20>250)) || ((d19<130 && d19>230) && (d20<0 && d20>100)) || ((d19<625 && d19>725) && (d20<580 && d20>680)) || ((d19<110 && d19>210) && (d20<480 && d20>580)) || ((d19<920 && d19>1020) && (d20<470 && d20>580)) || ((d19<620 && d19>720) && (d20<190 && d20>300))){
		
		d19+=20	,	d20+=60;}}}
		
		
	if (key == 32){
	if((xI>640 && xI<700)&&(yI>190 && yI<285)){
		r6=12675, r7=12617;
		d21=(rand()%850 + 50), d22=(rand()%700 + 50);
		if(((d21<180 && d21>280) && (d22<490 && d22>580)) || ((d21<70 && d21>150) && (d22<490 && d22>570)) || ((d21<480 && d21>560) && (d22<490 && d22>570)) || ((d21<730 && d21>810) && (d22<590 && d22>670)) || ((d21<880 && d21>960) && (d22<140 && d22>220)) || ((d21<480 && d21>560) && (d22<140 && d22>220)) || ((d21<110 && d21>190) && (d22<650 && d22>730)) || ((d21<910 && d21>990) && (d22<650 && d22>730)) || ((d21<820 && d21>920) && (d22<490 && d22>580)) || ((d21<50 && d21>170) && (d22<130 && d22>240)) || ((d21<390 && d21>500) && (d22<640 && d22>740)) || ((d21<700 && d21>810) && (d22<210 && d22>310)) || ((d21<270 && d21>370) && (d22<3 && d22>103)) || ((d21<910 && d21>1010) && (d22<3 && d22>103)) || ((d21<170 && d21>270) && (d22<480 && d22>520)) || ((d21<370 && d21>570) && (d22<480 && d22>520)) || ((d21<820 && d21>1010) && (d22<480 && d22>520)) || ((d21<60 && d21>260) && (d22<640 && d22>680)) || ((d21<370 && d21>570) && (d22<640 && d22>680)) || ((d21<820 && d21>1010) && (d22<640 && d22>680)) || ((d21<60 && d21>260) && (d22<130 && d22>170)) || ((d21<370 && d21>570) && (d22<130 && d22>170)) || ((d21<820 && d21>1020) && (d22<130 && d22>170)) || ((d21<60 && d21>260) && (d22<310 && d22>350)) || ((d21<370 && d21>570) && (d22<310 && d22>350)) || ((d21<820 && d21>1020) && (d22<310 && d22>350)) || ((d21<630 && d21>830) && (d22<580 && d22>620)) || ((d21<630 && d21>830) && (d22<210 && d22>250)) || ((d21<130 && d21>230) && (d22<0 && d22>100)) || ((d21<625 && d22>725) && (d22<580 && d22>680)) || ((d21<110 && d21>210) && (d22<480 && d22>580)) || ((d21<920 && d21>1020) && (d22<470 && d22>580)) || ((d21<620 && d21>720) && (d22<190 && d22>300))){
		
		d21+=20	,	d22+=60;
		
		}}}
		
	glutPostRedisplay();
	
	if(key == 13 || key == 13){
	if((xI>(d13-40) && xI<(d13+40)) && (yI>(d14-40) && yI<(d14+40))){
	d13=6000, d14=6000;
	passenger_dropped+=1;
	total_score+=10;
	r1=180; r2=35;}}
	
	if(key == 13 || key == 13){
	if((xI>(d15-40) && xI<(d15+40)) && (yI>(d16-40) && yI<(d16+40))){
	d15=6000, d16=6000;
	passenger_dropped+=1;
	total_score+=10;
	r4=675	,r5=617;}}
	
	if(key == 13 || key == 13){
	if((xI>(d17-40) && xI<(d17+40)) && (yI>(d18-40) && yI<(d18+40))){
	d17=6000, d18=6000;
	passenger_dropped+=1;
	total_score+=10;
	r10=160	,r11=517;}}
	
	if(key == 13 || key == 13){
	if((xI>(d19-40) && xI<(d19+40)) && (yI>(d20-40) && yI<(d20+40))){
	d19=6000, d20=6000;
	passenger_dropped+=1;
	total_score+=10;
	r8=970	,r9=517;}}
	
	if(key == 13 || key == 13){
	if((xI>(d21-40) && xI<(d21+40)) && (yI>(d22-40) && yI<(d22+40))){
	d21=6000, d22=6000;
	passenger_dropped+=1;
	total_score+=10;
	r6=670	,r7=247;}}
	
	glutPostRedisplay();
}
/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
 //time1=180
 //time detection function
void Timer(int m) {
	time1--;
	// implement your functionality here
	if(time1==0){
	ofstream myfile;
	myfile.open("leaderboard.txt",ios::out|ios::in|ios::app);
	myfile<<score_array[total_score];
	myfile.close();
	//ofstream<<
	exit(1);
	}
	moveCar();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
 
 
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Ahmed Mujtaba"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(menu_display1); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	cout<<total_score;
	return 1;
}
#endif /* RushHour_CPP_ */		// greater than && less than
