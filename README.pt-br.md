<h1 align="center">push_swap</h1>

<p align="center">
  <img src="https://img.shields.io/badge/linguagem-C-blue.svg" alt="Linguagem">
  <img src="https://img.shields.io/badge/42-School-black.svg" alt="42 School">
  <img src="https://img.shields.io/badge/status-completo-brightgreen.svg" alt="Status">
</p>

<p align="center">
  Um desafio de algoritmo de ordenação — ordenar uma pilha de números usando o mínimo possível de operações, com apenas duas pilhas e um conjunto restrito de movimentos.
</p>

<p align="center">
  <a href="README.md">🇺🇸 Read in English</a>
</p>

---

## Por que este projeto importa

> "Este projeto me ensinou a pensar algoritmicamente sob restrições — não apenas 'ordene isso', mas 'ordene isso com o menor número possível de movimentos, usando apenas essas operações específicas'. Aprendi como indexação simplifica comparações, quando aplicar estratégias de small-sort vs. radix-sort, e como medir e otimizar complexidade algorítmica. São exatamente as habilidades testadas em entrevistas técnicas e aplicadas em sistemas de alta performance."

Design de algoritmos e análise de complexidade são habilidades fundamentais para qualquer vaga de engenharia de software. Esse projeto vai além de implementar um algoritmo conhecido — exige selecionar e combinar estratégias para atingir metas de performance.

---

## Como funciona

Duas pilhas — **A** e **B** — e 11 operações permitidas:

| Operação | Descrição |
|---|---|
| `sa` | Troca os 2 primeiros elementos da pilha A |
| `sb` | Troca os 2 primeiros elementos da pilha B |
| `ss` | Executa `sa` e `sb` simultaneamente |
| `pa` | Empurra o topo de B para o topo de A |
| `pb` | Empurra o topo de A para o topo de B |
| `ra` | Rotaciona A — primeiro elemento vai para o fim |
| `rb` | Rotaciona B — primeiro elemento vai para o fim |
| `rr` | Executa `ra` e `rb` simultaneamente |
| `rra` | Rotação reversa de A — último elemento vai para o início |
| `rrb` | Rotação reversa de B — último elemento vai para o início |
| `rrr` | Executa `rra` e `rrb` simultaneamente |

**Objetivo:** Ordenar a pilha A em ordem crescente (menor no topo) com o menor número de operações. A pilha B deve estar vazia no final.

---

## O algoritmo

### 1. Validação de entrada
Verifica se todos os inputs são inteiros válidos dentro do range do `int` e sem números duplicados.

### 2. Indexação
Antes de ordenar, todos os números são substituídos por seu índice ordenado (0, 1, 2...). Isso elimina a necessidade de tratar números negativos e valores grandes durante a ordenação, simplificando todas as comparações.

### 3. Estratégia de ordenação

**Small sort (≤ 5 elementos)**
Uma árvore de decisão codificada manualmente, otimizada para o número mínimo de movimentos em cada caso possível.

**Radix sort (> 5 elementos)**
Os números são ordenados bit a bit usando radix sort binário sobre seus índices — empurrando elementos para B com base no bit atual, depois trazendo de volta. Isso garante complexidade O(n log n) com um número consistente e previsível de operações.

---

## Um detalhe técnico que se destaca

O uso de **indexação como etapa de pré-processamento** antes da ordenação é uma decisão de engenharia elegante. Ao converter inteiros arbitrários em uma sequência de índices contíguos, o radix sort pode operar diretamente nos bits sem se preocupar com bits de sinal, valores grandes ou casos extremos de comparação. Esse padrão — normalizar dados antes de processar — é uma técnica recorrente em pipelines de dados do mundo real e programação competitiva.

---

## Demo

![Demo de ordenação](https://github.com/GSousa101/pushswap_42/blob/main/sort.gif)

![Ordenação de 5 elementos](https://github.com/GSousa101/pushswap_42/blob/main/gifde5.gif)

![Ordenação de 100 elementos](https://github.com/GSousa101/pushswap_42/blob/main/gifde100.gif)

---

## Como usar

```bash
git clone https://github.com/gustavofsousa/pushswap_42.git
cd pushswap_42
make
```

### Executando

```bash
# Ordena uma lista de números
./push_swap 3 1 4 1 5 9 2 6

# Redireciona para contar operações
./push_swap 3 1 4 1 5 9 2 6 | wc -l

# Usa o checker para verificar a correção
./push_swap 3 1 4 1 5 9 2 6 | ./checker 3 1 4 1 5 9 2 6
```

---

## Estrutura do projeto

```
pushswap_42/
├── src/
│   ├── push_swap.c    # Ponto de entrada + validação de entrada
│   ├── sort_small.c   # Ordenação otimizada para ≤5 elementos
│   ├── sort_big.c     # Radix sort para grandes entradas
│   ├── push.c         # Operações pa / pb
│   ├── swap.c         # Operações sa / sb / ss
│   ├── rotate.c       # Operações ra / rb / rr
│   ├── reverse_rotate.c # Operações rra / rrb / rrr
│   ├── checker.c      # Valida a saída ordenada
│   └── ft_atol.c      # Parsing de inteiros
├── include/           # Headers
├── libft/             # Biblioteca C pessoal
└── Makefile
```

---

## Referências

- [15 Algoritmos de Ordenação Visualizados](https://youtu.be/kPRA0W1kECg)
- [Visualizador do Push Swap](https://github.com/o-reo/push_swap_visualizer)
- [Por que o Radix Sort é tão Rápido?](https://www.youtube.com/watch?v=ujb2CIWE8zY)

---

## Habilidades demonstradas

- Design e otimização de algoritmos sob restrições
- Análise de complexidade (alvo O(n log n))
- Indexação e normalização de dados
- Operações bitwise (radix sort binário)
- Implementação de pilha com lista ligada
- Tratamento de casos extremos no parsing de entrada

---

## Licença

Este projeto foi desenvolvido como parte do currículo da [42 School](https://42.fr).

---

<p align="center">Feito com ☕ na 42 Rio de Janeiro</p>
