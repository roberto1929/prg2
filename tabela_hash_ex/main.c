#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char *cpf;
    char *nome;
    char *email;
} pessoa_t;

typedef struct no {
    char *chave;
    pessoa_t *valor;
    struct no *prox;
} no_t;

typedef struct dicionario {
    int tamanho; //tamanho do vetor
    no_t **vetor;
} dicionario_t;

dicionario_t *criar_dicionario(int m) {
    dicionario_t *d = NULL;
    if (m < 1) {
        return NULL;
    }
    if ((d = (dicionario_t *) malloc(sizeof(dicionario_t))) == NULL) {
        return NULL;
    }
    d->tamanho = m;
    if ((d->vetor = calloc(m, sizeof(no_t))) == NULL) {
        return NULL;
    }

    for (int i = 0; i < m; ++i) {
        d->vetor[i] = NULL;
    }
    return d;
}

void destruir_pessoa(pessoa_t *pessoa) {
    if (pessoa->cpf != NULL) {
        free(pessoa->cpf);
    }
    if (pessoa->nome != NULL) {
        free(pessoa->nome);
    }
    if (pessoa->email != NULL) {
        free(pessoa->email);
    }
    free(pessoa);
}

void destruir_no(no_t *no) {
    if (no != NULL) {
        free(no->chave);
        destruir_pessoa(no->valor);
        free(no);
    }
}


void destruir_dicionario(dicionario_t *d) {
    if (d != NULL) {
        for (int i = 0; i < d->tamanho; ++i) {
            no_t *atual = d->vetor[i];
            while (atual != NULL) {
                no_t *proximo = atual->prox;
                destruir_no(atual);
                atual = proximo;
            }
        }
        free(d->vetor);
        free(d);
    }
}

int hash(const char *chave, int m) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; ++i) {
        soma += (i + 1) * chave[i];
    }
    return soma % m;
}

bool inserir(dicionario_t *d, char *chave, pessoa_t *valor) {
    int indice = hash(chave, d->tamanho);
    no_t *no = malloc(sizeof(no_t));

    if (no == NULL) {
        return false;
    }
    no->chave = strdup(chave);
    if (no->chave == NULL) {
        free(no);
        return false;
    }
    no->valor = valor;
    no->prox = d->vetor[indice];
    d->vetor[indice] = no;
    return true;
}

pessoa_t *buscar(dicionario_t *d, char *chave) {
    int indice = hash(chave, d->tamanho);
    no_t *atual = d->vetor[indice];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual->valor;
        }
        atual = atual->prox;
    }
    return NULL;
}

void imprimir_pessoa(dicionario_t *d, char *chave) {
    pessoa_t *p = buscar(d, chave);
    if (p != NULL) {
        printf("CPF: %s\tNome: %s\tEmail: %s\n", p->cpf, p->nome, p->email);
    } else {
        printf("Pessoa com CPF %s não encontrada\n", chave);
    }
}

bool remover(dicionario_t *d, char *chave) {
    int indice = hash(chave, d->tamanho);
    if(d->vetor[indice] == NULL){
        return false;
    }
    no_t *atual = d->vetor[indice];
    no_t *anterior = NULL;

    while(atual != NULL && strcmp(atual->chave,chave)!= 0){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        return false;
    }

    if(anterior == NULL){
        d->vetor[indice] = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    destruir_no(atual);

    return true;

}

void exibir_dicionario(dicionario_t *d){
    for (int i = 0; i < d->tamanho; ++i) {
        printf("%d [", i);

        no_t *atual = d->vetor[i];
        while (atual != NULL){
            printf("(%s,%s,%s)", atual->chave, atual->valor->nome, atual->valor->email);
            if(atual->prox != NULL){
                printf(", ");
            }
            atual = atual->prox;
        }
        printf("]\n");
    }
}




int main() {

   dicionario_t *dicionario = criar_dicionario(5);
    if (dicionario == NULL) {
        printf("Não foi possível reservar memória\n");
        exit(EXIT_FAILURE);
    }

    pessoa_t *p = malloc(sizeof(pessoa_t));
    p->cpf = strdup("123");
    p->nome = strdup("Juca");
    p->email = strdup("juca@example.org");
    inserir(dicionario, p->cpf, p);
    imprimir_pessoa(dicionario, "123");

    p = malloc(sizeof(pessoa_t));
    p->cpf = strdup("321");
    p->nome = strdup("Daniel");
    p->email = strdup("daniel@example.org");
    inserir(dicionario, p->cpf, p);
    imprimir_pessoa(dicionario, "321");

    p = malloc(sizeof(pessoa_t));
    p->cpf = strdup("456");
    p->nome = strdup("Roberto");
    p->email = strdup("roberto@example.org");
    inserir(dicionario, p->cpf, p);
    imprimir_pessoa(dicionario, "456");

    p = malloc(sizeof(pessoa_t));
    p->cpf = strdup("936");
    p->nome = strdup("Emerson");
    p->email = strdup("mello@example.org");
    inserir(dicionario, p->cpf, p);
    imprimir_pessoa(dicionario, "936");

    p = malloc(sizeof(pessoa_t));
    p->cpf = strdup("789");
    p->nome = strdup("Guerra");
    p->email = strdup("guerra@example.org");
    inserir(dicionario, p->cpf, p);
    imprimir_pessoa(dicionario, "789");

    printf("\n");

    exibir_dicionario(dicionario);

    printf("\n");
    bool item_removido = remover(dicionario, "123");

    if(item_removido){
        printf("Item removido com sucesso\n");
    } else{
        printf("Não foi encontrado, não foi possível remover\n");
    }
    printf("\n");

    exibir_dicionario(dicionario);

    destruir_dicionario(dicionario);


    return 0;
}
