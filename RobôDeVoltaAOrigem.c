#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

    int vertical = 0, horizontal = 0;

bool judgeCircle(char * moves){
    
    bool t;
    
    for ( int i = 0; i < 20001 ; i++ ){
        
        if ( moves[i] == 85 ){
            vertical++;
        }
        if ( moves[i] == 68 ){
            vertical--;
        }
        if ( moves[i] == 76 ){
            horizontal--;
        }
        if ( moves[i] == 82 ){
            horizontal++;
        }
    }
    if ( ( horizontal == 0) && (vertical == 0 ) ){
        t = true;
        return t;
    }else{
        t = false;
        return t;
    }
}

int main(){
    char * moves = (char *) malloc(20001);
    bool check;

    printf( "movimentos (somente U, D, R ou L): " );
    scanf( "%s", moves );

    check = judgeCircle(moves);
    
    if ( check == 1 ){
        printf( "\nVerdadeiro! (%d , %d)", horizontal, vertical );
    }else{
        printf( "\nFalso! (%d , %d)", horizontal, vertical );
    }
    free(moves);
    return 0;
}