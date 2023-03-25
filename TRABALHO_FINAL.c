#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node{
    char nome[10];
    int *idade;
    int *telefone;
    struct Node *prox;
    struct Node *anterior;
} Node;

void inserirPessoa ( Node **primeiro, Node **ultimo ){
      
      char novo_nome[10];
      if ( novo_nome == NULL ) {
            printf ( "Erro ao alocar memória para um novo nome.\n" );
            exit ( EXIT_FAILURE );
      }

      int *nova_idade = malloc ( sizeof ( int ) );
      if ( nova_idade == NULL ) {
            printf ( "Erro ao alocar memória para uma nova idade.\n" );
            exit ( EXIT_FAILURE );
      }

      int *novo_telefone = malloc ( sizeof ( int ) );
      if ( novo_telefone == NULL ) {
            printf ( "Erro ao alocar memória para um novo número de telefone.\n" );
            free ( nova_idade );
            exit ( EXIT_FAILURE );
      }

    printf ( "Nome: " );
    scanf ( "%9s", novo_nome );

    printf ( "Idade: " );
    scanf ( "%d", nova_idade );

    printf ( "Telefone: " );
    scanf ( "%d", novo_telefone );

    Node *novo_node = ( Node* ) malloc ( sizeof ( Node ) );

    strncpy ( novo_node -> nome, novo_nome, 10 );

    novo_node -> idade = nova_idade;
    novo_node -> telefone = novo_telefone;
    novo_node -> anterior = NULL;
    novo_node -> prox = NULL;

    if ( *primeiro == NULL ) {
            *primeiro = novo_node;
            *ultimo = novo_node;
      } else {
            Node* atual = *primeiro;
            while ( atual != NULL && strcmp ( novo_nome, atual -> nome ) > 0 ) {
            atual = atual -> prox;
            }
            if (atual == NULL) {
                  novo_node -> anterior = *ultimo;
                  ( *ultimo ) -> prox = novo_node;
                  *ultimo = novo_node;
            } else {
                  novo_node -> prox = atual;
                  novo_node -> anterior = atual -> anterior;
                  atual -> anterior = novo_node;
                  if ( novo_node -> anterior == NULL ) {
                        *primeiro = novo_node;
                  } else {
                        novo_node -> anterior -> prox = novo_node;
                  }
            }
      }
      printf("Pessoa cadastrada com sucesso!\n\n");
}

void removePessoa ( Node **primeiro, Node **ultimo, char *nome ){

    Node *atual = *primeiro;

    while ( atual != NULL ) {
        if ( strcmp ( atual -> nome, nome ) == 0) {
            if ( atual -> anterior != NULL ) {
                  atual -> anterior -> prox = atual -> prox;
            } else {
                  *primeiro = atual -> prox;
            }

            if ( atual -> prox != NULL ) {
                  atual -> prox -> anterior = atual -> anterior;
            } else {
                  *ultimo = atual -> anterior;
            }

            free ( atual -> idade );
            free ( atual -> telefone );
            free ( atual );
            printf ( "Pessoa removida com sucesso!\n\n " );
            return;
        }

        atual = atual -> prox;
    }
    printf ( "Pessoa não encontrada na agenda!\n\n" );
}

void buscarPessoa ( Node *primeiro, Node *ultimo, char *nome ){

    Node *atual = primeiro;

    while ( atual != NULL ) {
        if ( strcmp ( atual -> nome, nome ) == 0 ) {
            printf ( "%s, %d anos, Telefone: %d\n", atual -> nome, *(atual -> idade), *(atual -> telefone ) );
            return;
        }
        atual = atual -> prox;
    }
    printf ( "Pessoa não encontrada na agenda!\n\n" );
}

void listarPessoas ( Node *primeiro, Node *ultimo ){

    printf ( "Agenda:\n----------------------------------------------------------------\n" );
    Node *atual = primeiro;

    while ( atual != NULL ) {
        printf( "%s, %d anos, Telefone: %d\n", atual -> nome, *( atual -> idade ), *( atual -> telefone ) );
        atual = atual -> prox;
    }
    printf ( "----------------------------------------------------------------\n" );
}

void liberarMem ( Node *primeiro ){

      Node *atual = primeiro;
      while ( atual != NULL ) {
            Node *prox = atual->prox;
            free ( atual -> nome );
            free ( atual -> idade );
            free ( atual -> telefone );
            free ( atual );
            atual = prox;
    }
}

int main(){

      int *menu = malloc ( sizeof ( int ) );
      Node *primeiro = NULL;
      Node *ultimo = NULL;

      *menu = 1;

      while ( ( *menu >= 1 ) && ( *menu <= 5 ) ){
            printf("==========AGENDA==========\n");
            printf("(1)Inserir\n");
            printf("(2)Remover\n");
            printf("(3)Buscar\n");
            printf("(4)Listar\n");
            printf("(5)Encerrar\n");
            printf("===========================\n");
            printf("Escolha sua opcao do menu: ");
            scanf("%d", menu);

            while ( ( *menu < 1 ) || ( *menu > 5 ) ){
                  printf ( "Valor inválido, tente novamente: " );
                  scanf ( "%d", menu );
            }

            switch ( *menu ){

            case 1:

                  inserirPessoa ( &primeiro, &ultimo );
                  break;

            case 2:

                  printf ( "Nome da pessoa a ser removida: " );
                  char nome[10];
                  scanf ( "%9s", nome );

                  removePessoa ( &primeiro, &ultimo, nome );
                  break;

            case 3:

                  printf ( "Nome da pessoa a ser buscada: " );
                  char nome_busca[10];
                  scanf ( "%9s", nome_busca );

                  buscarPessoa ( primeiro, ultimo, nome_busca );
                  break;

            case 4:

                  listarPessoas ( primeiro, ultimo );
                  break;

            case 5:

                  printf ( "Ate a proxima!" );
                  liberarMem ( primeiro );
                  free ( menu );
                  return 0;
            }
      }
}