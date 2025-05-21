# Go

- Navegue pelo terminal até a pasta do projeto.
- Você encontrará os arquivos `lista.go`, `main.go` e `mod.go`.

```bash
# Apague o arquivo `mod.go` para evitar conflitos de versão
rm -f mod.go
# Crie um novo módulo Go baseado na sua versão do Go
go mod init editor
# Instale a biblioteca `tcell` para poder manipular o terminal
go get github.com/gdamore/tcell/v2
# Estando dentro da pasta do projeto, rode o projeto usando
go run .
# ou usando
tko run .
```

- Caso entre em loop infinito ou dê algum erro de execução, você pode interromper o programa com `Ctrl + C`.
- Caso seu terminal fique estranho, você pode tentar restaurá-lo com o comando `reset` ou digitando `Ctrl + D` pra matar o terminal.
