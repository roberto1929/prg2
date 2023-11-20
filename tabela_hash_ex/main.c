#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
    char *cpf;
    char *nome;
    char *email;
} pessoa_t;

typedef  struct no{
    char *chave;
    pessoa_t *valor;
    struct no *prox;
} no_t;

typedef struct dicionario{
    int tamanho; //tamanho do vetor
    no_t **vetor;
} dicionario_t;

dicionario_t *criar_dicionario(int m){
    dicionario_t *d = NULL;
    if (m < 1){
        return  NULL;
    }
    if((d = (dicionario_t *) malloc(sizeof (dicionario_t))) == NULL){
        return NULL;
    }
    d->tamanho = m;
    if((d->vetor = calloc(m, sizeof (no_t))) == NULL){
        return NULL;
    }

    for (int i = 0; i < m; ++i) {
        d->vetor[i] = NULL;
    }
    return d;
}

void destruir_pessoa(pessoa_t *pessoa){
    if(pessoa->cpf != NULL){
        free(pessoa->cpf);
    }
    if(pessoa->nome != NULL){
        free(pessoa->nome);
    }
    if(pessoa->email != NULL){
        free(pessoa->email);
    }
    free(pessoa);
}

void destruir_no(no_t *no){
    if (no != NULL){
        free(no->chave);
        destruir_pessoa(no->valor);
        free(no);
    }
}


void destruir_dicionario(dicionario_t *d){
    if(d !=NULL){
        for (int i = 0; i < d->tamanho; ++i) {
            //TODO destruir lista encadeada
            no_t *atual = d->vetor[i];
            while(atual != NULL){
                no_t *proximo = atual->prox;
                destruir_no(atual);
                atual = proximo;
            }
        }
        free(d->vetor);
        free(d);
    }
}

int hash(const char *chave, int m){
    int soma = 0;
    for (int i = 0; chave[i] != '\0' ; ++i) {
        soma += (i + 1) * chave[i];
    }
    return soma % m;
}

bool inserir(dicionario_t *d, char *chave, pessoa_t *valor){
    int indice = hash(chave, d->tamanho);
    no_t *no = malloc(sizeof(no_t));
    if(no == NULL){
        return false;
    }
    no->chave = strdup(chave);
    if (no->chave == NULL){
        free(no);
        return false;
    }
    no->valor = valor;
    no->valor = valor;
    no->prox = (struct no *) d->vetor[indice];
    d->vetor[indice] = no;
    return true;
}

pessoa_t *buscar(dicionario_t *d, char *chave){
    int indice = hash(chave, d->tamanho);
    no_t *atual = d->vetor[indice];
    while (atual != NULL) {
        if(strcmp(atual->chave, chave) == 0){
            return atual->valor;
        }
        atual = (no_t *) atual->prox;
    }
    return NULL;
}

void imprimir_pessoa(dicionario_t *d, char *chave){
    pessoa_t *p = buscar(d, chave);
    if(p != NULL){
        printf("CPF: %s\tNome: %s\tEmail: %s\n", p->cpf,p->nome,p->email);
    } else{
        printf("Pessoa com CPF %s não encontrada\n", chave);
    }
}



int main() {

    dicionario_t *dicionario = criar_dicionario(5);
    if(dicionario == NULL){
        printf("Não foi possível reservar memória\n");
        exit(EXIT_FAILURE);
    }

    pessoa_t *p = malloc(sizeof(pessoa_t));
    p->cpf = strdup("123");
    p->nome = strdup("Juca");
    p->email = strdup("juca@example.ogr");
    inserir(dicionario, p->cpf,p);

    imprimir_pessoa(dicionario, "123");

    destruir_dicionario(dicionario);

    return 0;
}
