#include <stdio.h>

size_t tabla_estados[][25] = {
{1,2,2,2,2,2,2,2,2,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
{5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,3,3,6},
{2,2,2,2,2,2,2,2,2,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,6,6,6},
{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,6,6,6},
{5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6}
};

size_t estados_finales[] = {1,2,4,5};
size_t cant_finales = 4;
size_t alfabeto[] = {0,1,2,3,4,5,6,7,8,9,'A','B','C','D','E','F','a','b','c','d','e','f','x','X'};
size_t long_alfabeto = 24;

size_t posicion_alfabeto(char c){
    size_t i;
    for(i = 0; i < long_alfabeto; i++){
        if(alfabeto[i] == c)
            return 1; 
    return 0;
    }
}

int es_final(size_t estado){
    size_t i;
    for (i = 0; i < cant_finales; i++){
        if(estado == estados_finales[i]){
            return 1;}
    return 0;
    }
}

int automata(){
    size_t estado = 0;
    char c;
    while((c = getc(stdin)) != '\n'){
        estado = tabla_estados[estado][posicion_alfabeto(c)];
    }
    return es_final(estado);
}

int main(int argc, char **args){
    char c;
    while (c = getc(stdin) != EOF){
        ungetc(c, stdin);
        if(automata()){
            printf("cadena valida\n");
        }else{
            printf("cadena NO valida\n");
        }
    }
    return 0;
}