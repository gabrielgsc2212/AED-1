#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void freeList(struct ListNode* head) {
    struct ListNode* atual = head;
    struct ListNode* next;

    while (atual != NULL) {
        next = atual->next;
        free(atual);
        atual = next;
    }
}

bool isPalindrome(struct ListNode* head){
    int tamanho = 0;
    struct ListNode* atual = head;
    
    while ( atual != NULL ) {
        tamanho++;
        atual = atual->next;
    }

    char valores[tamanho];
    atual = head;
    for(int i = 0; i < tamanho; i++) {
        valores[i] = atual->val;
        atual = atual->next;
    }

    int i = 0, j = tamanho - 1;
    while(i < j) {
        if(valores[i] != valores[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    struct ListNode* head = NULL;
    struct ListNode* atual = NULL;

    printf( "Escreva a sequencia a ser analisada: " );
    char c;
    while( ( c = getchar() ) != '\n' ) {

        struct ListNode* node = ( struct ListNode* ) malloc( sizeof ( 100000 * ( 4 ) ) );
        node->val = c;
        node->next = NULL;

        if( head == NULL ) {
            head = node;
            atual = head;
        } else {
            atual -> next = node;
            atual = atual -> next;
        }
    }

    if ( isPalindrome(head) == true ){
        printf( "A sequencia acima e um palindromo!" );
    } else {
        printf( "A sequencia acima nao e um palindromo!" );
    }

    freeList(head);

    return 0;
}
