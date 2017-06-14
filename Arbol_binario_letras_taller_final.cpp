/*TALLER FINAL
    ARBOLES LETRAS PUNTO B
PRESENTADO POR: JHON ANDERSON SANCHEZ
DOCENTE: CARLOS LONDOÑO
ESTRUCTURAS DE DATOS 2*/

#include <stdio.h>
#include <stdlib.h>
#define Reserva_Memoria (Nodo*)malloc(sizeof(Nodo))

//ESTRUCURA DEL ARBOL
struct Nodo{
    int dato;
    Nodo *Izquierda;
    Nodo *Derecha;
};
//PROTOTIPOS DE LAS FUNCIONES DEL ARBOL
void Menu(Nodo *&);
void insert_Nodo(Nodo *&,int);
bool Buscar_Nodo(Nodo *,int);
void Editar_Nodo(Nodo *&,int);
void imp_Arbol(Nodo *,int);
void impPos_Order(Nodo *);
void impPre_Order(Nodo *);
void impIn_Order(Nodo *);

int main(){
    Nodo *arbol=NULL;
    system("cls");
    //LLAMADO AL MENU PRINCIPAL
    Menu(arbol);
    return 0;
}

//CREAR NUEVO NODO
Nodo *crearNodo(int n){
    Nodo *Nuevo_Nodo=Reserva_Memoria;
    Nuevo_Nodo->dato=n;
    Nuevo_Nodo->Izquierda=NULL;
    Nuevo_Nodo->Derecha=NULL;
    return Nuevo_Nodo;
}

// FUNCION DEL MENU PRINCIPAL
void Menu(Nodo *&arbol){
    int opc, opc2,cont=0;
    char letra;
    system("cls");
    printf("\n\t\t********MENU ARBOL BINARIO********");
    printf("\n\t\t**********************************\n\n");
    printf("\n1- Insertar Elementos");
    printf("\n2- Editar Elemento de Arbol");
    printf("\n3- Buscar Elemento en Arbol");
    printf("\n4- Eliminar Elemento de Arbol");
    printf("\n5- Mostrar Arbol");
    printf("\n0. Salir");
    printf("\n\t\t**********************************\n\n");
    printf("Que desea hacer?: ");
    scanf("%d",&opc);

    switch(opc){
        case 0:
            system("cls");
            printf("\n\tPrograma finalizado!!!\n");
            system("pause");
            break;
        case 1:
            printf("\n\t**********INSERTAR ELEMTOS************\n");
            {do{
                printf("Ingrese el elemento: ");
                scanf("%s",&letra);
                int convertir_int=letra;
                if(convertir_int>=62 && convertir_int<=90 || convertir_int>=97 && convertir_int<=122){
                    if(convertir_int>90){
                        convertir_int=convertir_int-32;
                    }
                    insert_Nodo(arbol,convertir_int);
                }else{
                    printf("Elemento ingresado no valido\n");
                    printf("Por favor ingrese un caracter\n");
                }
                printf("Continuar Ingresando? (1)SI - (2)NO: ");
                scanf("%d",&opc2);
            }while(opc2!=2);
            system("pause");
            system("cls");
            Menu(arbol);}
            break;
        case 2:
            printf("\n\t\t**********MODIFICAR NODO DEL ARBOL*********\n");
            {printf("Ingrese el elemento a modificar: ");
            scanf("%s",&letra);
            int convertir_int=letra;
            if(convertir_int>=62 && convertir_int<=90 || convertir_int>=97 && convertir_int<=122){
                    if(convertir_int>90){
                        convertir_int=convertir_int-32;
                }
                Editar_Nodo(arbol,convertir_int);
            }else{
                printf("Elemento ingresado no valido\n");
            }
            }break;
        case 3:
            printf("\n\t********BUSCAR ARBOL*******\n");
            {printf("Ingre el elemento a buscar: ");
            scanf("%c",&letra);
            int convertir_int=letra;
            if(convertir_int>=62 && convertir_int<=90 || convertir_int>=97 && convertir_int<=122){
                    if(convertir_int>90){
                        convertir_int=convertir_int-32;
                }
                if(Buscar_Nodo(arbol,convertir_int)==true){
                    printf("Elemento %s encontrado en el Arbol!!\n",letra);
                }else{
                    printf("Elemento %s no encontrado en el Arbol!!\n",letra);
                }
            }else{
                printf("Elemento ingresado no valido\n");
            }
            system("pause");
            system("cls");
            Menu(arbol);
            }break;
        case 4:
            printf("\n\t************ELIMINAR NODO DE ARBOL******\n\n");
            system("pause");
            system("cls");
            Menu(arbol);
            break;
        case 5:
            printf("\n\t***********IMPRIMIR ARBOL***********\n\n");
            imp_Arbol(arbol,cont);
            printf("******************************************\n");
            printf("\n1. Arbol PreOrden");
            printf("\n2. Arbol PosOrden");
            printf("\n3. Arbol InOrder");
            printf("\n0. Volver al Menu\n");
            printf("Que desea hacer?: ");
            scanf("%d",&opc2);
            switch(opc2){
            case 0:
                printf("\nVolviendo al menu principal!!\n");
                system("pause");
                system("cls");
                Menu(arbol);
                break;
            case 1:
                printf("\n\t***********ARBOL PREORDEN***********\n\n");
                impIn_Order(arbol);
                break;
            case 2:
                printf("\n\t**************ARBOL POSORDEN**************\n\n");
                impPre_Order(arbol);
                break;
            case 3:
                printf("\n\t*****************ARBOL INORDEN**********\n\n");
                impIn_Order(arbol);
                break;
            default:
                printf("\n\nLa Opcion Ingresada no es Valida!!\n\n");
                break;
            }
            system("pause");
            system("cls");
            Menu(arbol);
            break;
    }
}

//Funcion Insertar nodo
void insert_Nodo(Nodo *&arbol, int n){
    int a;
    if(arbol==NULL){
        Nodo *nuevo=crearNodo(n);
        arbol=nuevo;
    }else{
        printf("Insertar a la (1)Izquierda o (2)Derecha: ");
        scanf("%d",&a);
        if(a==1){
            insert_Nodo(arbol->Izquierda,n);
        }else{
            insert_Nodo(arbol->Derecha,n);
        }
    }
}
//Funcion Buscar Nodo
bool Buscar_Nodo(Nodo *arbol, int n){
    int a;
    if(arbol==NULL){
        return false;
    }else{
        if(arbol->dato==n){
            return true;
        }else{
            printf("Buscar por la \n\t\t<1>Izquierda O <2>Derecha: ");
            scanf("%d",&a);
            if(a==1){
                Buscar_Nodo(arbol->Izquierda,n);
            }else{
                Buscar_Nodo(arbol->Derecha,n);
            }
        }
    }
}
//Funcion Editar Nodo
void Editar_Nodo(Nodo *&arbol, int n){
    int nuevoDato, ubicacion;
    if(arbol==NULL){
        return;
    }else{
        if(arbol->dato==n){
            printf("Ingrese el nuevo Elemnto: ");
            scanf("%d",&nuevoDato);
            arbol->dato=nuevoDato;
        }else{
            printf("Buscar 1.Izquierda  2.Derecha: ");
            scanf("%d",&ubicacion);
            if(ubicacion==1){
                Editar_Nodo(arbol->Izquierda,n);
            }else{
                Editar_Nodo(arbol->Derecha,n);
            }
        }
    }
}

void impPre_Order(Nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        char convertir_int=arbol->dato;
        printf("%c ",convertir_int);
        impPre_Order(arbol->Izquierda);
        impPre_Order(arbol->Derecha);
    }
}
void impIn_Order(Nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        impIn_Order(arbol->Izquierda);
        char convertir_int=arbol->dato;
        printf("%c ",convertir_int);
        impIn_Order(arbol->Derecha);
    }
}
void impPos_Order(Nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        impPos_Order(arbol->Izquierda);
        impPos_Order(arbol->Derecha);
        char convertir_int=arbol->dato;
        printf("%c ",convertir_int);
    }
}

void imp_Arbol(Nodo *arbol, int cont){
	int i;
	if(arbol == NULL){
		return;
	}else{
		imp_Arbol(arbol -> Derecha, cont += 1);
		for(i = 0; i < cont; i++){
			printf("   ");
		}
		char convertir_int=arbol->dato;
		printf("%c\n", convertir_int);
		imp_Arbol(arbol -> Izquierda, cont += 1);
	}
}

//Fin del programa
