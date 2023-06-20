# SCCs

O seguinte trabalho aborda o problema de Manutenção de sistemas de comunicação entre agentes secretos, que foi abstraído para Grafos como o seguinte:
Qual o número mínimo de arestas necessárias para tornar um grafo direcionado fortemente conexo?

## Estrutura

No repositório, econtram-se as pastas `diagnostics`, `generated_output`, `input` e `output`. As pastas `input` e `output` são casos de teste 
retirados do banco de casos de teste das quetões da Maratona de Programação ICPC, sendo os arquivos de entrada e saída esperada, respectivamente.

Já as pastas `diagnostics` e `generated_output` são geradas ao rodar os testes (instruções mais abaixo). 

O padrão dos casos de teste em `input` é o seguinte:

```
n m
u_1 v_1
u_2 v_2
.
.
.
u_m v_m
```

Onde `n` e `m` são, respectivamente, o número de vértices e arestas do grafo. E `u_i, v_i` (1 <= i <= m; 1 <= `u_i, v_i` <= n) 
são pares de vértices que representam as arestas do grafo. Ou seja, `(u_i, v_i)` é uma aresta do vértice `u_i` para `v_i`. 

## Instruções:

O arquivo com o algoritmo `spy.cpp` pode ser rodado a parte, mas adicionamos o script `run_test.sh` para facilitar na execução.

É possível executar os testes com 

```
$ ./run_test.sh
```

Para rodar todos os testes (do 1 ao 37, presentes em `input`). Alternativamente, para rodar o teste de número X (de 1 a 37):

```
$ ./run_test.sh X
```

Os resultados, com tempo de execução, componentes fortemente conexas e resposta final se econtrarão na pasta `diagnostics`. Já as saídas geradas,
na pasta `generated_output` (que são comparadas com as de `output` no script).
