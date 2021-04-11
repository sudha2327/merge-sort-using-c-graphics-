#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void swap(int,int);
void draw(int,int,int);
void draw1(int,int,int);
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);
void main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
  int n;
  printf("enter the value for how many number you wants to store:\n");
  scanf("%d",&n);
  //ARRAY  declaration
  int a[200],i;
  printf("enter the array element:\n");
  for(i=0;i<n;i++){
   scanf("%d",&a[i]);

  }
  //just show the elements alredy stored in the array
  rectangle(100,150,500,200);
 for(i=0;i<n;i++){
   draw(110+i*100,140,a[i]);
   getch();
 }

	mergesort(a,0,n-1);
 rectangle(100,250,500,300);

 settextstyle(6,0,5);
 setcolor(GREEN);
 line(100,220,500,220);
 line(100,230,500,230);
 setcolor(WHITE);
 outtextxy(100,300,"Selection Sort");
 //print the array after done selection sorting
 for(i=0;i<n;i++){
//  printf("%d",a[i]);
draw1(110+i*100,240,a[i]);

 }


getch();
}

void draw(int x,int y,int a){
  char s[20];
  sprintf(s,"%d",a);
  settextstyle(6,0,5);
  setcolor(RED);
  outtextxy(x,y,s);
  setcolor(WHITE);
  line(60+x,150,60+x,200);


}
void draw1(int c,int v,int a){
  char s[20];
  sprintf(s,"%d",a);
  settextstyle(6,0,5);
  setcolor(BLUE);
  outtextxy(c,v,s);
  setcolor(WHITE);
  line(60+c,250,60+c,300);


}

void mergesort(int a[],int i,int j)
{
	int mid;
		
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);		//left recursion
		mergesort(a,mid+1,j);	//right recursion
		merge(a,i,mid,mid+1,j);	//merging of two sorted sub-arrays
	}
}

void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[50];	//array used for merging
	int i,j,k;
	i=i1;	
	j=i2;	
	
	k=0;
	
	while(i<=j1 && j<=j2)	
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	
	while(i<=j1)	
		temp[k++]=a[i++];
		
	while(j<=j2)	
		temp[k++]=a[j++];
		
	//Transfer elements from temp[] back to a[]
	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}