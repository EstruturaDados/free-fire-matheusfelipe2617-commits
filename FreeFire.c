''Nível Novato''

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// -------------------------
// STRUCT DO ITEM
// -------------------------
// Representa cada objeto dentro da mochila do jogador.
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// -------------------------
// DECLARAÇÃO DAS FUNÇÕES
// -------------------------
void inserirItem(Item mochila[], int *total);
void removerItem(Item mochila[], int *total);
void listarItens(Item mochila[], int total);
void buscarItem(Item mochila[], int total);

// -------------------------
// FUNÇÃO PRINCIPAL
// -------------------------
int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n========== SISTEMA DE INVENTÁRIO ==========\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer do Enter

        switch (opcao) {
            case 1:
                inserirItem(mochila, &total);
                break;
            case 2:
                removerItem(mochila, &total);
                break;
            case 3:
                listarItens(mochila, total);
                break;
            case 4:
                buscarItem(mochila, total);
                break;
            case 5:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}

// -------------------------
// FUNÇÃO: INSERIR ITEM
// -------------------------
void inserirItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("\nA mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("\nDigite o nome do item: ");
    fgets(novo.nome, 30, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Digite o tipo do item (arma, municao, cura, etc.): ");
    fgets(novo.tipo, 20, stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);
    getchar();

    mochila[*total] = novo;
    (*total)++;

    printf("\nItem adicionado com sucesso!\n");
    listarItens(mochila, *total);
}

// -------------------------
// FUNÇÃO: REMOVER ITEM
// -------------------------
void removerItem(Item mochila[], int *total) {
    if (*total == 0) {
        printf("\nA mochila está vazia! Nada para remover.\n");
        return;
    }

    char nomeRemover[30];
    printf("\nDigite o nome do item que deseja remover: ");
    fgets(nomeRemover, 30, stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

    int encontrado = -1;
    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("\nItem não encontrado!\n");
        return;
    }

    // Desloca os itens
    for (int i = encontrado; i < *total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }
    (*total)--;

    printf("\nItem removido com sucesso!\n");
    listarItens(mochila, *total);
}

// -------------------------
// FUNÇÃO: LISTAR ITENS
// -------------------------
void listarItens(Item mochila[], int total) {
    printf("\n======= ITENS NA MOCHILA =======\n");

    if (total == 0) {
        printf("Nenhum item cadastrado.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1,
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }
}

// -------------------------
// FUNÇÃO: BUSCAR ITEM
// -------------------------
void buscarItem(Item mochila[], int total) {
    if (total == 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\nTipo: %s\nQuantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("\nItem não encontrado!\n");
}


''Nível Aventureiro''

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// -----------------------------
// STRUCTS
// -----------------------------
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// -----------------------------
// VARIÁVEIS GLOBAIS DA MOCHILA (VETOR)
// -----------------------------
Item mochilaVetor[MAX];
int tamanhoVetor = 0;


// =====================================================
// ---------------------- FUNÇÕES DO VETOR -------------
// =====================================================

// Inserir no vetor
void inserirVetor() {
    if (tamanhoVetor >= MAX) {
        printf("Mochila cheia!\n");
        return;
    }

    Item novo;
    printf("Nome do item: ");
    scanf(" %[^\n]", novo.nome);
    printf("Tipo do item: ");
    scanf(" %[^\n]", novo.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochilaVetor[tamanhoVetor++] = novo;

    printf("Item inserido no vetor!\n");
}

// Remover no vetor
void removerVetor() {
    char nome[30];
    printf("Digite o nome do item para remover: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < tamanhoVetor; i++) {
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            for (int j = i; j < tamanhoVetor - 1; j++)
                mochilaVetor[j] = mochilaVetor[j + 1];
            tamanhoVetor--;
            printf("Item removido!\n");
            return;
        }
    }
    printf("Item nao encontrado!\n");
}

// Listar vetor
void listarVetor() {
    if (tamanhoVetor == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    printf("\n--- ITENS NO VETOR ---\n");
    for (int i = 0; i < tamanhoVetor; i++) {
        printf("%s | %s | Qtd: %d\n",
               mochilaVetor[i].nome,
               mochilaVetor[i].tipo,
               mochilaVetor[i].quantidade);
    }
}

// Busca sequencial no vetor
void buscaSequencialVetor() {
    char nome[30];
    int comparacoes = 0;

    printf("Nome do item para buscar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < tamanhoVetor; i++) {
        comparacoes++;
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            printf("Item encontrado!\n");
            printf("Comparacoes realizadas: %d\n", comparacoes);
            return;
        }
    }
    printf("Item NAO encontrado.\n");
    printf("Comparacoes realizadas: %d\n", comparacoes);
}

// Ordenação (Bubble Sort)
void ordenarVetor() {
    int i, j;
    for (i = 0; i < tamanhoVetor - 1; i++) {
        for (j = 0; j < tamanhoVetor - i - 1; j++) {
            if (strcmp(mochilaVetor[j].nome, mochilaVetor[j + 1].nome) > 0) {
                Item temp = mochilaVetor[j];
                mochilaVetor[j] = mochilaVetor[j + 1];
                mochilaVetor[j + 1] = temp;
            }
        }
    }
    printf("Itens ordenados por nome!\n");
}

// Busca Binária
void buscaBinaria() {
    char nome[30];
    printf("Nome para busca binaria: ");
    scanf(" %[^\n]", nome);

    int inicio = 0, fim = tamanhoVetor - 1, comparacoes = 0;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        comparacoes++;

        int cmp = strcmp(nome, mochilaVetor[meio].nome);

        if (cmp == 0) {
            printf("Item encontrado na posicao %d\n", meio);
            printf("Comparacoes: %d\n", comparacoes);
            return;
        }
        if (cmp > 0)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    printf("Item NAO encontrado.\n");
    printf("Comparacoes: %d\n", comparacoes);
}


// =====================================================
// ------------------ FUNÇÕES DA LISTA -----------------
// =====================================================

// Inserir na lista
No* inserirLista(No* lista) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) return lista;

    printf("Nome do item: ");
    scanf(" %[^\n]", novo->dados.nome);
    printf("Tipo do item: ");
    scanf(" %[^\n]", novo->dados.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo->dados.quantidade);

    novo->proximo = lista;

    printf("Item inserido na lista!\n");

    return novo;
}

// Remover da lista
No* removerLista(No* lista) {
    char nome[30];
    printf("Nome para remover: ");
    scanf(" %[^\n]", nome);

    No* atual = lista;
    No* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nome) == 0) {
            if (anterior == NULL)
                lista = atual->proximo;
            else
                anterior->proximo = atual->proximo;

            free(atual);
            printf("Item removido da lista!\n");
            return lista;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("Item nao encontrado!\n");
    return lista;
}

// Listar lista
void listarLista(No* lista) {
    if (!lista) {
        printf("Lista vazia.\n");
        return;
    }

    printf("\n--- ITENS NA LISTA ---\n");

    while (lista != NULL) {
        printf("%s | %s | Qtd: %d\n",
               lista->dados.nome,
               lista->dados.tipo,
               lista->dados.quantidade);
        lista = lista->proximo;
    }
}

// Busca sequencial na lista
void buscaSequencialLista(No* lista) {
    char nome[30];
    int comparacoes = 0;

    printf("Nome para buscar: ");
    scanf(" %[^\n]", nome);

    while (lista != NULL) {
        comparacoes++;
        if (strcmp(lista->dados.nome, nome) == 0) {
            printf("Item encontrado!\n");
            printf("Comparacoes: %d\n", comparacoes);
            return;
        }
        lista = lista->proximo;
    }

    printf("Item nao encontrado.\n");
    printf("Comparacoes: %d\n", comparacoes);
}


// =====================================================
// --------------------------- MENU ---------------------
// =====================================================

void menuVetor() {
    int op;
    do {
        printf("\n--- MOCHILA (VETOR) ---\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Listar\n");
        printf("4 - Busca sequencial\n");
        printf("5 - Ordenar\n");
        printf("6 - Busca binaria\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1: inserirVetor(); break;
            case 2: removerVetor(); break;
            case 3: listarVetor(); break;
            case 4: buscaSequencialVetor(); break;
            case 5: ordenarVetor(); break;
            case 6: buscaBinaria(); break;
        }
    } while (op != 0);
}

void menuLista() {
    No* lista = NULL;
    int op;

    do {
        printf("\n--- MOCHILA (LISTA ENCADEADA) ---\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Listar\n");
        printf("4 - Buscar sequencial\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1: lista = inserirLista(lista); break;
            case 2: lista = removerLista(lista); break;
            case 3: listarLista(lista); break;
            case 4: buscaSequencialLista(lista); break;
        }
    } while (op != 0);
}

int main() {
    int op;

    do {
        printf("\n===== SISTEMA DE MOCHILA =====\n");
        printf("1 - Usar mochila com VETOR\n");
        printf("2 - Usar mochila com LISTA ENCADEADA\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1: menuVetor(); break;
            case 2: menuLista(); break;
        }
    } while (op != 0);

    return 0;
}


''Nível Avançado''

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMPONENTES 20

// Estrutura que representa um componente da torre
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade; // 1..10
} Componente;

// Tipos para funções de ordenação usadas pelo medirTempo
typedef void (*SortFunc)(Componente[], int, long *comparacoes);

// ---------- Assinaturas de funções ----------
void bubbleSortNome(Componente arr[], int n, long *comparacoes);
void insertionSortTipo(Componente arr[], int n, long *comparacoes);
void selectionSortPrioridade(Componente arr[], int n, long *comparacoes);
int buscaBinariaPorNome(Componente arr[], int n, const char chave[], long *comparacoes);
void mostrarComponentes(Componente arr[], int n);
void medirTempo(SortFunc func, Componente arr[], int n, long *comparacoes, double *tempo);
void limparBuffer();

// ---------- Implementações ----------

// Limpa o buffer leftover do stdin
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Imprime o vetor de componentes formatado
void mostrarComponentes(Componente arr[], int n) {
    printf("\nLista de componentes (total: %d):\n", n);
    printf("%-3s | %-28s | %-16s | %-9s\n", "#", "NOME", "TIPO", "PRIORIDADE");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < n; ++i) {
        printf("%-3d | %-28s | %-16s | %-9d\n", i + 1, arr[i].nome, arr[i].tipo, arr[i].prioridade);
    }
    printf("\n");
}

// Bubble sort por nome (alfabético crescente)
// Conta comparações como número de chamadas a strcmp
void bubbleSortNome(Componente arr[], int n, long *comparacoes) {
    *comparacoes = 0;
    int trocou;
    for (int i = 0; i < n - 1; ++i) {
        trocou = 0;
        for (int j = 0; j < n - i - 1; ++j) {
            (*comparacoes)++;
            if (strcmp(arr[j].nome, arr[j + 1].nome) > 0) {
                Componente tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                trocou = 1;
            }
        }
        if (!trocou) break; // otimização
    }
}

// Insertion sort por tipo (alfabético crescente)
// Conta comparações como número de chamadas a strcmp
void insertionSortTipo(Componente arr[], int n, long *comparacoes) {
    *comparacoes = 0;
    for (int i = 1; i < n; ++i) {
        Componente chave = arr[i];
        int j = i - 1;
        // comparar tipo
        while (j >= 0) {
            (*comparacoes)++;
            if (strcmp(arr[j].tipo, chave.tipo) > 0) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = chave;
    }
}

// Selection sort por prioridade (crescente: menor prioridade primeiro)
// Conta comparações como comparações inteiras de prioridade
void selectionSortPrioridade(Componente arr[], int n, long *comparacoes) {
    *comparacoes = 0;
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            (*comparacoes)++;
            if (arr[j].prioridade < arr[minIdx].prioridade) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            Componente tmp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = tmp;
        }
    }
}

// Busca binária por nome (requer arr ordenado por nome)
// Retorna índice se encontrado, -1 caso contrário. Também conta comparações (strcmp calls)
int buscaBinariaPorNome(Componente arr[], int n, const char chave[], long *comparacoes) {
    int esquerda = 0, direita = n - 1;
    *comparacoes = 0;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        (*comparacoes)++;
        int cmp = strcmp(arr[meio].nome, chave);
        if (cmp == 0) return meio;
        else if (cmp < 0) esquerda = meio + 1;
        else direita = meio - 1;
    }
    return -1;
}

// Wrapper para medir tempo e repassar comparações
void medirTempo(SortFunc func, Componente arr[], int n, long *comparacoes, double *tempo) {
    // copiamos o array para não alterar o original fornecido pelo usuário (opcional)
    Componente copia[MAX_COMPONENTES];
    for (int i = 0; i < n; ++i) copia[i] = arr[i];

    clock_t inicio = clock();
    func(copia, n, comparacoes);
    clock_t fim = clock();
    *tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // Após medir, colocamos o resultado ordenado de volta no arr para visualização (útil ao escolher aplicar a ordenação)
    for (int i = 0; i < n; ++i) arr[i] = copia[i];
}

// ---------- Programa principal (menu interativo) ----------
int main() {
    Componente lista[MAX_COMPONENTES];
    int n = 0;

    printf("=== Módulo: Montagem da Torre de Resgate - Fase Final ===\n");

    // Entrada dos componentes
    printf("Quantos componentes deseja cadastrar? (1-%d): ", MAX_COMPONENTES);
    if (scanf("%d", &n) != 1) {
        printf("Entrada inválida. Saindo.\n");
        return 1;
    }
    if (n < 1) n = 1;
    if (n > MAX_COMPONENTES) n = MAX_COMPONENTES;
    limparBuffer();

    for (int i = 0; i < n; ++i) {
        printf("\nComponente %d:\n", i + 1);
        printf("Nome (ex: chip central): ");
        fgets(lista[i].nome, sizeof(lista[i].nome), stdin);
        // remove '\n' final
        lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0';

        printf("Tipo (controle/suporte/propulsao): ");
        fgets(lista[i].tipo, sizeof(lista[i].tipo), stdin);
        lista[i].tipo[strcspn(lista[i].tipo, "\n")] = '\0';

        printf("Prioridade (1-10): ");
        if (scanf("%d", &lista[i].prioridade) != 1) {
            lista[i].prioridade = 5; // default
            limparBuffer();
        } else {
            limparBuffer();
        }
        if (lista[i].prioridade < 1) lista[i].prioridade = 1;
        if (lista[i].prioridade > 10) lista[i].prioridade = 10;
    }

    int opcao;
    Componente copiaOriginal[MAX_COMPONENTES];
    for (int i = 0; i < n; ++i) copiaOriginal[i] = lista[i];

    do {
        printf("\n--- Menu ---\n");
        printf("1. Ordenar por NOME (Bubble Sort)\n");
        printf("2. Ordenar por TIPO (Insertion Sort)\n");
        printf("3. Ordenar por PRIORIDADE (Selection Sort)\n");
        printf("4. Buscar componente-chave por NOME (Busca Binária)\n");
        printf("5. Mostrar componentes atuais\n");
        printf("6. Resetar para entrada original\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida. Saindo.\n");
            break;
        }
        limparBuffer();

        if (opcao == 1) {
            long comparacoes = 0;
            double tempo = 0.0;
            // medir e aplicar
            medirTempo(bubbleSortNome, lista, n, &comparacoes, &tempo);
            printf("\n--- Resultado: Ordenação por NOME (Bubble Sort) ---\n");
            mostrarComponentes(lista, n);
            printf("Comparações (strcmp): %ld\n", comparacoes);
            printf("Tempo gasto: %.6f segundos\n", tempo);
        } else if (opcao == 2) {
            long comparacoes = 0;
            double tempo = 0.0;
            medirTempo(insertionSortTipo, lista, n, &comparacoes, &tempo);
            printf("\n--- Resultado: Ordenação por TIPO (Insertion Sort) ---\n");
            mostrarComponentes(lista, n);
            printf("Comparações (strcmp): %ld\n", comparacoes);
            printf("Tempo gasto: %.6f segundos\n", tempo);
        } else if (opcao == 3) {
            long comparacoes = 0;
            double tempo = 0.0;
            medirTempo(selectionSortPrioridade, lista, n, &comparacoes, &tempo);
            printf("\n--- Resultado: Ordenação por PRIORIDADE (Selection Sort) ---\n");
            mostrarComponentes(lista, n);
            printf("Comparações (int): %ld\n", comparacoes);
            printf("Tempo gasto: %.6f segundos\n", tempo);
        } else if (opcao == 4) {
            // Busca binária só faz sentido se a lista estiver ordenada por nome.
            // Avisamos o jogador e oferecemos ordenar automaticamente se necessário.
            char chave[30];
            printf("Digite o NOME do componente-chave a buscar: ");
            fgets(chave, sizeof(chave), stdin);
            chave[strcspn(chave, "\n")] = '\0';

            // Verificar se está ordenado por nome: simplificação -> vamos ordenar por nome antes da busca
            printf("(Para garantir busca correta, iremos ordenar por NOME usando Bubble Sort.)\n");
            long compSort = 0;
            double tempoSort = 0.0;
            medirTempo(bubbleSortNome, lista, n, &compSort, &tempoSort);
            printf("Ordenação por NOME aplicada. Comparações: %ld, Tempo: %.6f s\n", compSort, tempoSort);

            long compBusca = 0;
            int idx = buscaBinariaPorNome(lista, n, chave, &compBusca);
            if (idx >= 0) {
                printf("Componente-CHAVE encontrado na posição %d:\n", idx + 1);
                printf("Nome: %s | Tipo: %s | Prioridade: %d\n", lista[idx].nome, lista[idx].tipo, lista[idx].prioridade);
            } else {
                printf("Componente '%s' NÃO encontrado.\n", chave);
            }
            printf("Comparações na busca (strcmp): %ld\n", compBusca);
        } else if (opcao == 5) {
            mostrarComponentes(lista, n);
        } else if (opcao == 6) {
            for (int i = 0; i < n; ++i) lista[i] = copiaOriginal[i];
            printf("Lista restaurada à ordem original de entrada.\n");
        } else if (opcao == 0) {
            printf("Saindo... Boa sorte na fuga!\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
