#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <iostream>
using namespace std;


//This's a basic gaussRand found in internet.
double gaussrand(){
	static double V1, V2, S;
	static int phase = 0;
	double X;
	if (phase == 0 ) {
		do {
			double U1 = (double)rand() / RAND_MAX;
			double U2 = (double)rand() / RAND_MAX;
			V1 = 2.0 * U1 - 1.0;
			V2 = 2.0 * U2 - 1.0;
			S = V1 * V1 + V2 * V2;
		} while(S >= 1 || S == 0);
		X = V1 * sqrt(-2 * log(S) / S);
	} else
		X = V2 * sqrt(-2 * log(S) / S);
	phase = 1 - phase;
	return X;
}
inline double NormD(double u,double t){
	return gaussrand()*t+u;
}
double f(double x,double y){
	// if f<=0, means (x,y) locates inside? really? Notice::this conclusion may not be correct.
	double x2=x*x;
	double y2=y*y;
	double t=(x2+y2-1);
	return t*t-x2*y2;
}
bool isInsideHeart(double x, double y){
	//heart's size x:[-1.2,1.2] y:[-1,1.2]
	//1. y>=0, part1+part2
		//part1. f<0
		//or part2.  |x|<1 && |y|<1
	double fx=f(x,y);
	double ax=fabs(x);
	double ay=fabs(y);
	if(y>=0){
		if(fx<0)return true;
		if(ax<1&&ay<1)return true;
		return false;
	}else{
	//2. y<0
		//unwanted part3: f<=0
		//unwanted part4: |x|>=1
		//unwanted part5: |y|>=1
		if(fx<=0)return false;
		if(ax>=1)return false;
		if(ay>=1)return false;
		return true;
	}
		
}
bool isInsideNormalHeart(double x, double y){
	//input x:[-1,1],y:[-1,1]
	return isInsideHeart(x*1.2,y*1.2);
}
/** 请完成下面这个函数，实现题目要求的功能 **/
/** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
double leartCurve(double u1, double t1, double u2, double t2) {
	//x~N(u1,t1)   y~N(u2,t2)
	//(x^2+y^2-1)^2=x^2*y^2
	double x,y;
	int maxCount=100000;
	int count=0;
	for(int i=0;i<maxCount;i++){
		x=NormD(u1,t1);
		y=NormD(u2,t2);
		if(isInsideHeart(x,y)){
			count++;
		}
	}
	return (double)count/maxCount;
}
int testHeart() {
	//for python to plot data.
	double x,y;
	double step=0.01;
	double lim=2;
	double es=0.0000001;
	for(x=-lim;x<lim;x+=step){
		for(y=-lim;y<lim;y+=step){
			if(isInsideHeart(x,y)){
				cout<<x<<"\t"<<y<<endl;
			}
		}
	}
	return 0;

}
void printHeart(){
	int numR=30;
	int numC=numR;
	for(int r=0;r<numR;r++){
		for(int c=0;c<numC;c++){
			double x=c-numC/2;
			double y=numR/2-r;
			x=x/(double)(numR/2);
			y=y/(double)(numR/2);
			if(isInsideNormalHeart(x,y)){
				cout<<"#";
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}
int main(){
	printHeart();
	//testHeart();
	return 0;
}

