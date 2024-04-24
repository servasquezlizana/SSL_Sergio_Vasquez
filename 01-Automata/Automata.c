#include <stdio.h>

int tabla_estados[][25] = {
{1,2,2,2,2,2,2,2,2,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
{5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,3,3,6},
{2,2,2,2,2,2,2,2,2,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,6,6,6},
{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,6,6,6},
{5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6}
};

int estados_finales[] = {1,2,4,5,6};
int cant_finales = 5;
char alfabeto[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','a','b','c','d','e','f','x','X'};
int long_alfabeto = 24;

//Recorro la cadena alfabeto y devuelvo la poscion del caracter en la cadena
int posicion_alfabeto(char c){
    for(int i = 0; i < long_alfabeto; i++){
        if(alfabeto[i] == c){
            return i;}
    }
    return 25;
}

//me fijo si el valor de estado corresponde a un estado final
int es_final(int estado){
    int i;
    for (i = 0; i < cant_finales; i++){
        if(estado == estados_finales[i])
            return estado;
    }
    return 0;
}

//AUTOMATA, SE RECORRE LA TABLA DE ESTADOS Y SE DEVUELVE EL VALOR EN LA POSICION Aij, i=estado j=ordinal del caracter
int automata(FILE *prueba,FILE *salida){
    int estado = 0;
    char palabra;
    while((fscanf(prueba,",",palabra)) != EOF){ //getc(stdin) recorre la palabra ingresada (stdin) caracter a caracter hasta que reconoce un salto de linea
       char letra[] = palabra;
       for (int i = 0; i < strlen(letra); i++){
        estado = tabla_estados[estado][posicion_alfabeto(letra)];
       }
       switch (es_final(estado)){//reconosco si estado es un estado final
        case 1:
            fwrite(palabra + "      OCTAL\n",sizeof(int),1,salida);
            break;
        case 2:
            fwrite(palabra + "      DECIMAL\n",sizeof(int),1,salida);
            break;
        case 4:
            fwrite(palabra + "      HEXADECIMAL\n",sizeof(int),1,salida);
            break;
        case 5:
            fwrite(palabra + "      OCTAL\n",sizeof(int),1,salida);
            break;
        default:
            fwrite(palabra + "      NO RECONOCE LA CADENA\n",sizeof(int),1,salida);
            break;
        }
    }
    return -1; 
}


//MAIN
int main(int argc, char **args){
    FILE *prueba = fopen("prueba.txt","r");
    FILE *salida = fopen("salida.txt","wb");
    if(prueba == NULL){
        printf("Error al iniciar prueba, compruebe que exista el archivo\n");
        return 0;
    }
    if(salida == NULL){
        printf("Error al crear archivo salida.txt\n");
        return 0;
    }
    if (!automata(prueba,salida)){
        printf("Resultado exitoso\n");
    }else{
        printf("Error\n");
    }
    fclose(prueba);
    fclose(salida);   
    return 0;
}