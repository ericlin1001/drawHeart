#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <iostream>
using namespace std;
double f(double x,double y){
	// if f<=0, means (x,y) locates inside? really? Notice::this conclusion may not be correct.
	double x2=x*x;
	double y2=y*y;
	double t=(x2+y2-1);
	return t*t-x2*y2;
}
bool isInsideHeart(double x, double y){
	//the heart's size x:[-1.5,1.5] y:[0,1.5]
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
int testHeart() {
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
	int numR=35;
	int numC=numR*2;
	for(int r=0;r<numR;r++){
		for(int c=0;c<numC;c++){
			double x=c-numC/2;
			double y=numR/2-r;
			double r=2.4;
			x=x/(double)numC*r;
			y=y/(double)numR*r;
			if(isInsideHeart(x,y)){
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
	return 0;
}

