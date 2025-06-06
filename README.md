# 🎮 O Mais Honrado

**O Mais Honrado** é um jogo 2D desenvolvido em C++ utilizando a biblioteca [SFML](https://www.sfml-dev.org/). O projeto conta com sistema de menus, múltiplas fases e gerenciamento de entidades.

---

## 🚀 Como Rodar

### 📋 Pré-requisitos

Certifique-se de ter os seguintes pacotes instalados:

- `GCC/G++`
- `SFML`  
  _No Fedora:_

  ```bash
  sudo dnf install SFML SFML-devel
  ```
- `make`

---

### 🛠️ Compilação

No terminal, dentro da pasta do projeto, execute:

```bash
make all
```

---

### ▶️ Execução

Após a compilação, inicie o jogo com:

```bash
make run
```

ou diretamente:

```bash
./main
```

---

## 📁 Estrutura do Projeto

```plaintext
├── src/        # Código-fonte principal
├── include/    # Headers do projeto
├── Assets/     # Imagens e sprites do jogo
├── Fontes/     # Arquivos de fonte utilizados
└── Makefile    # Script de compilação
```
