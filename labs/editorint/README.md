# Editor de texto interativo

- O editor de texto interativo utiliza uma uma lista ligada de linhas para armazenar o texto.
- Cada linha é uma lista ligada de caracteres.
- Iteradores são utilizados para apontar a linha corrente e o caractere corrente dentro da linha.
- O cursor é desenhado automaticamente a partir da posição do iterador.

## Auto avaliação

Para cada funcionalidade implementada, você receberá uma pontuação que vai de 0 a 10. Verifique sempre os limites de cada funcionalidade, tentando sair das linhas e verificando o comportamento do editor. Esse será o valor que você vai colocar na hora de avisar o quanto da atividade foi feita.

- [ ] 1 ponto - Left e Right em uma só linha.
- [ ] 1 ponto - Backspace e Delete em uma só linha.
- [ ] 1 ponto - Enter adiciona uma nova linha abaixo da atual e move o cursor para o início da nova linha.
- [ ] 1 ponto - Up e Down para navegar entre as linhas movendo o cursor para o início da linha.
- [ ] 1 ponto - Left no início da linha move o cursor para o final da linha anterior.
- [ ] 1 ponto - Right no final da linha move o cursor para o início da linha seguinte.
- [ ] 1 ponto - Enter no meio da linha divide a linha em duas e move o cursor para o início da nova linha.
- [ ] 1 ponto - Up e Down para navegar entre as linhas movendo o cursor para a posição correta.
- [ ] 1 ponto - Backspace no início da linha puxa a linha pra cima e move o cursor para a posição correta.
- [ ] 1 ponto - Delete no final da linha junta as linhas e move o cursor para a posição correta.

## Implementação

- Em cada arquivo `extra.md` você encontrará as orientações de como fazer a configuração do ambiente instalando a biblioteca `curses` ou equivalente, que lhe permitirá rodar o código interativo no terminal.
- Você pode utilizar a sua implementação de lista ligada ou a implementação nativa da linguagem.
- Toda parte de manipulação visual já está implementada, você só precisa implementar a lógica de manipulação do texto.
- A ação principal de escrever e movimentar para esquerda também já estão implementadas.
