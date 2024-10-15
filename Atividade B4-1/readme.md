# Melhoria para o código do Bubble Sort

Este documento explicará uma forma simples de tornar o clássico mecanismo de ordenação de elementos de um array, Bubble Sort, mais eficiênte.

## Funcionamento Original

O Bubble Sort originalmente passa por cada index do array verificando se o seu próximo index guarda um valor maior que o index atual, para que se a posição atual conter um valor maior, as posições serão trocadas, então ordenando posição por posição o array, ou qualquer outra lista que se deseja ser trabalhada.

Essas passagens pela lista são feitas, de forma fixa, **n** (quantidade de elementos na lista) vezes, para que independente do quao desordenado o array estiver, ao realizar essa passagem o número de vezes correspondente ao tamanho da lista, ele sempre ordenará, com certeza, todos os elementos do array.

![alt text]()

## Problema do Bubble Sort

Primeiramente, foi considerado a implementação de uma forma da função do Bubble Sort identificar se algum elemento ja havia sido posicionado no fim do array, significando que foi posicionado corretamente, e então diminuindo o tamanho do array conforme o programa executava.

Porém, essa pequena funcionalidade já é naturalmente implementada na lógica do Bubble Sort e esta primeira teoria foi apenas uma falta de noção mais profunda da lógica do Bubble Sort.

A cada passagem pelo array, o **for** mais interno do Bubble Sort utiliza o **i** para diminuir progressivamente a quantidade de elementos que se devem ser verificados. Isso é feito através da seção **"j < n-i-1"**.

```c
for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
```

Sempre que o loop interno é executado por completo, e uma passagem inteira é realizada pelo Array, a variável **i** é incrementada em +1. Dessa forma, o Bubble Sort é capaz de verificar elementos apenas ainda não corretamente posicionados.

### Verdadeiro Problema do Bubble Sort

Um outro problema na lógica do Bubble Sort é que ele realiza **n** (quantidade de elementos no Array) passagens pelo Array. Isso significa que se por exemplo o array possuir 10 elementos, porém apenas 3 elementos estão com a posição trocada, ele ainda realizará 10 passagens pelo array, verificando no array mesmo após o mesmo já ter sido organizado.

Considerando a utilização do Bubble Sort com Arrays numa escala maior, isso pode impactar na performance do programa.

### Solução de Melhora Encontrada

Como solução para este problema, é possivel criar uma variável boolean que indique se o Array já está completamente organizado.

#### int boolDone;

Esta variável boolean pode ser definida como done quando não tiver ocorrido nenhuma mudança no array:

```c
int boolDone;

    for (i = 0; boolDone != 1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                boolDone = 0;
            }
            else{
                boolDone = 1;
            }
        }
    }
```

- "boolDone = 0" Ocorre quando acontece alguma troca pelo array.
- "boolDone = 1" Ocorre quando não acontece nenhuma troca no array.

Por fim, a condição para finalização dos loops do Bubble Sort é transformada de **"i < n-1"**, a qual representava "n" passagens pelo array, para **"boolDone != 1"**, indicando que o programa deve ser executado até que a boolean esteja ativada, implicando que o array foi completamente ordenado.