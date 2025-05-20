# Editor de texto interativo utilizando o curses

- O editor de texto interativo utiliza uma uma lista ligada de linhas para armazenar o texto.
- Cada linha é uma lista ligada de caracteres.
- Iteradores são utilizados para apontar a linha corrente e o caractere corrente dentro da linha.
- O cursor é desenhado automaticamente a partir da posição do iterador.

## Implementação

- Em cada arquivo `extra.md` você encontrará as orientações de como fazer a configuração do ambiente instalando a biblioteca `curses` ou equivalente, que lhe permitirá rodar o código interativo no terminal.
- Você pode utilizar a sua implementação de lista ligada ou a implementação nativa da linguagem.
- Toda parte de manipulação visual já está implementada, você só precisa implementar a lógica de manipulação do texto.
- A ação principal de escrever e movimentar para esquerda também já estão implementadas.
