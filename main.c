// Codigo en bitBucket:
//https://bitbucket.org/eduardoveras94/proyectos-isc-105/src/a7ad298e8fc577e53c7640f0ac8771dc2cda4c8b/Compromiso%202?at=master
#include <stdio.h>
#include <stdlib.h>
#include <conio.c>

int revisarfila(int arr[4][300],int y,int ind, int lugares);

int entredos(int arr[4][300],int k, int longitud);

typedef struct
{
    int indice;
    int longi;
} hw;

typedef struct
{
    hw tarea[11];
    int no_proceso;
    int cant_tareas;
} ID;

int main()
{
    ID procesos[11];
    system("color f0");

    int n,i,j,k,arr[4][300],copyarr[4][300],cont=0,suma=0;
    for(i=0; i<11; i++)
        for(j=0; j<11; j++)
        {
            procesos[i].tarea[j].longi=0;
            procesos[i].cant_tareas=0;
        }

    for(i=0; i<4; i++)
    {
        for(j=0; j<300; j++)
        {
            arr[i][j]=-1;
            copyarr[i][j]=-1;
        }
    }

    printf("\n\n\t\tASIGNACION AUTOMATICA DE PROCESOS\n\n");
    printf("Cuantos procesos desea simular?");
    scanf("%d",&n);

    while(n>10||n<1)
    {
        printf("Digite un numero valido");
        scanf("%d",&n);
    }
    for(i=0; i<n; i++)
    {
        textbackground(i+1);
        textcolor(WHITE);
        printf("\nProceso no.%d:",i+1);
        textbackground(WHITE);
        textcolor(BLACK);
        scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&procesos[i].tarea[0].longi,
              &procesos[i].tarea[1].longi,
              &procesos[i].tarea[2].longi,
              &procesos[i].tarea[3].longi,
              &procesos[i].tarea[4].longi,
              &procesos[i].tarea[5].longi,
              &procesos[i].tarea[6].longi,
              &procesos[i].tarea[7].longi,
              &procesos[i].tarea[8].longi,
              &procesos[i].tarea[9].longi);

        procesos[i].no_proceso=i+1;

        suma+=(procesos[i].tarea[0].longi+
               procesos[i].tarea[1].longi+
               procesos[i].tarea[2].longi+
               procesos[i].tarea[3].longi+
               procesos[i].tarea[4].longi+
               procesos[i].tarea[5].longi+
               procesos[i].tarea[6].longi+
               procesos[i].tarea[7].longi+
               procesos[i].tarea[8].longi+
               procesos[i].tarea[9].longi);

        for(j=0; j<11; j++)
            procesos[i].tarea[j].indice=j;

        if(suma>59)
        {
            printf("Error, maximo de 60 seg.");
            suma=0;
            i--;
            continue;
        }
        for(j=0; j<10; j++)
            if(procesos[i].tarea[j].longi!=0)
                procesos[i].cant_tareas++;
        suma=0;

    }
    textbackground(WHITE);
    textcolor(BLACK);
    int maximo_lineas=0;
    printf("\n\n");

    printf("Grafica de las cargas de procesamiento de cada nucleo del procesador:\n");
    printf("N.\tCargas de procesamiento\n");
    printf("==\t========================\n");


    int l,m,procesador=0,test=0;
    for(i=0; i<n; i++)
    {
        k=0;
        for(j=0; j<procesos[i].cant_tareas; j++)
        {

            if(procesos[i].tarea[j].longi!=0&&procesos[i].tarea[j].longi<6)
            {
                m=k;
                for(procesador=0; procesador<4; procesador++)
                {

                    test=0;
                    for(; k<procesos[i].tarea[j].longi+m; k++)
                    {
                        if(revisarfila(arr,procesador,k,procesos[i].tarea[j].longi+k)==0&&test==0)
                        {
                            break;
                        }
                        arr[procesador][k]=procesos[i].tarea[j].indice;
                        copyarr[procesador][k]=procesos[i].no_proceso;
                        test=1;
                        if(k>=maximo_lineas)
                        maximo_lineas=k;
                    }
                    if(procesador==4&&test==0)
                    {
                        k=entrecuatro(arr,k,procesos[i].tarea[j].longi);
                        m=k;
                        procesador=0;
                    }
                    if(test==1)
                        procesador=5;
                }
            }
            else
            {
                if(procesos[i].tarea[j].longi!=0)
                {
                    m=k;
                    for(procesador=2; procesador<4; procesador++)
                    {
                        test=0;
                        for(; k<procesos[i].tarea[j].longi+m; k++)
                        {
                            if(revisarfila(arr,procesador,k,procesos[i].tarea[j].longi+k)==0&&test==0)
                                break;
                            arr[procesador][k]=procesos[i].tarea[j].indice;
                            copyarr[procesador][k]=procesos[i].no_proceso;
                            test=1;
                            if(k>=maximo_lineas)
                                maximo_lineas=k;
                        }
                        if(procesador==3&&test==0)
                        {
                            k=entredos(arr,k,procesos[i].tarea[j].longi);
                            m=k;
                            procesador=1;
                            continue;
                        }
                        if(test==1)
                            procesador=5;
                    }
                }
            }
        }
    }

    for(i=0; i<4; i++)
    {
        printf("%d:\t",i+1);
        for(j=0; j<maximo_lineas+1; j++)
        {
            if(copyarr[i][j]==-1)
            {
                textbackground(WHITE);
                printf("x ");
                continue;
            }
            else
            {
                if(copyarr[i][j]==0)
                textbackground(0);
                if(copyarr[i][j]==1)
                textbackground(1);
                if(copyarr[i][j]==2)
                textbackground(2);
                if(copyarr[i][j]==3)
                textbackground(3);
                if(copyarr[i][j]==4)
                textbackground(4);
                if(copyarr[i][j]==5)
                textbackground(5);
                if(copyarr[i][j]==6)
                textbackground(6);
                if(copyarr[i][j]==7)
                textbackground(7);
                if(copyarr[i][j]==8)
                textbackground(8);
                if(copyarr[i][j]==9)
                textbackground(9);
                if(copyarr[i][j]==10)
                textbackground(10);
            }
            printf("%d ",arr[i][j]);

        }
        printf("\n");
        textbackground(WHITE);

    }


    getch();
    return 0;
}

int revisarfila(int arr[4][300],int y,int ind, int lugares)
{
    for(; ind<lugares; ind++)
    {
        if(arr[y][ind]>=0)
            return 0;
    }
    return 1;
}

int entredos(int arr[4][300],int k, int longitud)
{
    int x1,x2;
    for(x1=k+1;x1<300;x1++)
    {
        if(revisarfila(arr,2,x1,x1+longitud)==1)
            break;
    }
    for(x2=k+1;x2<300;x2++)
    {
        if(revisarfila(arr,3,x2,x2+longitud)==1)
            break;
    }
    if(x1<=x2)
        return x1;

    return x2;
}

int entrecuatro(int arr[4][300],int k, int longitud)
{
    int x1,x2,x3,x4, menor;
    for(x1=k;x1<300;x1++)
    {
        if(revisarfila(arr,0,x1,x1+longitud)==1)
            break;
    }
    for(x2=k;x2<300;x2++)
    {
        if(revisarfila(arr,1,x2,x2+longitud)==1)
            break;
    }
    for(x3=k;x3<300;x3++)
    {
        if(revisarfila(arr,2,x3,x3+longitud)==1)
            break;
    }
    for(x4=k;x4<300;x4++)
    {
        if(revisarfila(arr,3,x4,x4+longitud)==1)
            break;
    }
    menor=x1;
    if(menor<x2)
    menor=x2;
    if(menor<x3)
    menor=x3;
    if(menor<x4)
    menor=x4;
    return menor;
}
