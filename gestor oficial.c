#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct contacto
{
    char nom[35];
    char correo[100];
    char num[20];

    };
void menu();
void tr();
void inicio();
void atras();
void anadir();
void mostrar();
void modificar();
void borrar();
void buscar();
int main()
{
    system("color 6f");
    inicio();
    return 0;
}
void atras()
{
    inicio();
}
void inicio()
{
    menu();
}
void menu()
{
    system("cls");

printf("             GESTOR DE CONTACTOS");

printf("\n                  MENU\n");
printf("Anadir <1>    Mostrar <2>     Salir <3>  \nModificar <4>   Buscar <5>   Borrar <6>");

switch(getch())
{
    case '1':
	anadir();
    break;
   case '2': mostrar();
    break;
    case '3': exit(0);
    break;
    case '4': modificar();
    break;
    case '5': buscar();
    break;
    case '6': borrar();
    break;
    default:
                system("cls");
                printf("\n introduzca del 1 al 6 solamento");
                printf("\n precione cualquier tecla");
                getch();

menu();
}
}
        void anadir()
{
        system("cls");
        FILE *f;
        struct contacto c;
        f=fopen("gestor","ab+");
        printf("\nintrodusca nombre: ");
        tr(c.nom);
        printf("\nintrodusca e-Mail: ");
         tr(c.correo);
        printf("\n intrudusca numero : ");
        tr(c.num);
        fwrite(&c,sizeof(c),1,f);

      fflush(stdin);
        printf("\n añadido exitosamente !!");

fclose(f);

    printf("\n\n pulse cualquier tecla");

	 getch();
    system("cls");
    menu();
}
void mostrar()
{
    struct contacto c;
    FILE *f;
f=fopen("gestor","rb");
if(f==NULL)
{
printf("\n error al intentar abrir el archivo para el listado:");

exit(1);
}
while(fread(&c,sizeof(c),1,f)==1)
{
     printf("\n\n\n tus contactos son\n\n ");
        printf("\nNombre: %s\nE-Mail: %s\n Numero: %s",c.nom,c.correo,c.num);

	 getch();
	 system("cls");
}
fclose(f);
 printf("\n presiona cualquier tecla");
 getch();
    system("cls");
menu();
}
void buscar()
{
    struct contacto c;
FILE *f;
char nom[100];

f=fopen("gestor","rb");
if(f==NULL)
{
    printf("\n error al intentar abrir el archivo para el listado:");
    exit(1);

}
printf("\n introdusca el nombre de la persona \n");
tr(nom);
while(fread(&c,sizeof(c),1,f)==1)
{
    if(strcmp(c.nom,nom)==0)
    {
        printf("\n\tla in informacion de el contacto %s",nom);
        printf("\nNombre: %s\nE-Mail: %s\n Numero: %s",c.nom,c.correo,c.num);
    }
        else
        printf("contacto no se encuetra !!");

}
 fclose(f);
  printf("\nprecione alguna tecla");

	 getch();
    system("cls");
menu();
}
void borrar()
{
    struct contacto c;
    FILE *f,*ft;
	int ban;
	char nom[100];
	f=fopen("gestor","rb");
	if(f==NULL)
		{

			printf("\n el contacto no ha sido agregado aun.");

		}
	else
	{
		ft=fopen("gestor_temp","wb+");
		if(ft==NULL)

            printf("error al abrir archivo");
		else

        {


		printf("\n introdusca el nombre del contacto: ");
		tr(nom);

		fflush(stdin);
		while(fread(&c,sizeof(c),1,f)==1)
		{
			if(strcmp(c.nom,nom)!=0)
				fwrite(&c,sizeof(c),1,ft);
			if(strcmp(c.nom,nom)==0)
                ban=1;
		}
	fclose(f);
	fclose(ft);
	if(ban!=1)
	{
		printf("\n no existe el contacto para eliminarlo.");
		remove("gesto_temp");
	}
		else
		{
			remove("gestor");
			rename("gestor_temp","gestor");
			printf("\n contato eliminado .");

		}
	}
}
 printf("\n presiona alguna tecla");

	 getch();
    system("cls");
menu();
}

void modificar()
{
    int e;
    FILE *f;
    int ban=0;
    struct contacto c,s;
	char  nom[50];
	f=fopen("gestor","rb+");
	if(f==NULL)
		{

			printf("\ncontacto no ha sido anadido aun.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("introdusca el nombre del contacto a modificar:\n");
            tr(nom);
            while(fread(&c,sizeof(c),1,f)==1)
            {
                if(strcmp(nom,c.nom)==0)
                {



                    printf("\nintrodusca nombre: ");
                    tr(s.nom);
                    printf("\nintrodusca e-Mail: ");
                    tr(s.correo);
                    printf("\n intrudusca numero : ");
                    tr(s.num);
                    fseek(f,-sizeof(c),SEEK_CUR);
                    fwrite(&s,sizeof(c),1,f);
                    ban=1;
                    break;



                }
                fflush(stdin);


            }
            if(ban==1)
            {
                printf("\n contacto modificado");

            }
            else
            {
                    printf(" \n contacto no encontrado");

            }
            fclose(f);
	}
	 printf("\n presione alguna tecla");
	 getch();
    system("cls");
	menu();

}
void tr(char *nombre)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(nombre+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(nombre+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(nombre+i)='\0';
}
