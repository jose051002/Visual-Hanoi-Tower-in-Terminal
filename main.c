/*
JJGoFo 31/01/2023

Description of functions:
    *push: stacks a given int data type on top of our chain
    *pop:  quits the data on top of the chain, turns its value into a 0 in the original chain, returns the data previously popped
    *llenarHanoi: initializes our matrix according to our input
    *imprimirHanoi: prints on screen our implementation 
    *torrehanoi: implementation of the algorithm to solve hanoi towers    
*/

#include<stdlib.h>
#include<stdio.h>
int pop(int cadena[],int size);
void push(int cadena[],int size, int in);
void llenarHanoi(int a[],int b[],int c[],int size);
void imprimirHanoi(int a[],int b[],int c[],int size);
void torrehanoi(int a[],int b[],int c[],int a2[],int b2[],int c2[],int size,int sizeaux);
int main(int argc, char const *argv[])
{
    //Undo next comment for changing terminal color
    //system("color 02");
    while(1){
    int size;
    printf("Input the number of disks: \n");
    scanf("%d",&size);
    int a[size],b[size],c[size];
    llenarHanoi(a,b,c,size);
    printf("Torre Inicial: \n");
    imprimirHanoi(a,b,c,size);
    printf("Secuencia: \n");
    torrehanoi(a,b,c,a,b,c,size,size);
    imprimirHanoi(a,b,c,size);
    system("pause");
    system("cls");
    }



    return 0;
}

int pop(int cadena[],int size){
    int out;
    for (int i = 0; i < size; i++)
    {
        if (cadena[i]!=0){
            out=cadena[i];
            cadena[i]=0;
            return out;
        }
    }
    
}

void push(int cadena[],int size, int in){
    for (int i = size-1; i >= 0; i--)
    {
        if (cadena[i]==0){ 
            cadena[i]=in;
            break;
        }
    }

    
}

void imprimirC(int cadena[],int size){
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",cadena[i]);
    }
}
void llenarHanoi(int a[],int b[],int c[],int size){
    for (int i =0;i <size; i++)
    {
        a[i]=i+1;
    }
    for (int i =0;i <=size; i++)
    {
        b[i]=0;
    }
    for (int i =0;i <=size; i++)
    {
        c[i]=0;
    }
}

void imprimirHanoi(int a[],int b[],int c[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("\t[%d]\t[%d]\t[%d]\n",a[i],b[i],c[i]);
    }
    printf("\t-------------------\n");
}

void torrehanoi(int a[],int b[],int c[],int a2[],int b2[],int c2[],int size,int sizeaux){
if (sizeaux == 1) {
    int aux=pop(a,size);
    push(c,size,aux);
    imprimirHanoi(a2,b2,c2,size);
    return;
  }
  else{
    torrehanoi(a, c, b,a2,b2,c2,size,sizeaux-1);
    int aux2=pop(a,size);
    push(c,size,aux2);
    imprimirHanoi(a2,b2,c2,size);
    torrehanoi(b, a, c,a2,b2,c2,size,sizeaux-1);
  }
}

