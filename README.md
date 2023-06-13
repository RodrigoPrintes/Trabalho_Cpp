# Reprodutor de vídeo MP4 com FFmpeg codificado em C++

Este é um reprodutor de vídeo MP4 desenvolvido em C++ utilizando a biblioteca FFmpeg.

## Autor
- Rodrigo Printes
- Engenharia da Computação - UFAM
- Data: 08/06/2023
- E-mail: rgp@icomp.ufam.edu.br

## Instruções de Execução

Siga as instruções abaixo para executar o reprodutor de vídeo:

1. Coloque seu arquivo de vídeo MP4 na pasta `/data` localizada na raiz do projeto.
2. Abra um terminal em um ambiente Linux.
3. Navegue até a pasta raiz do projeto, onde se encontra o arquivo `Makefile`.
4. Execute o comando `make` para compilar o projeto.
5. Após a compilação, será gerado um executável na pasta `/output`.
6. Execute o arquivo gerado, por exemplo, usando o comando `./output/main`.

### Exemplo

- Terminal@Rodrigo:/play_ffmpeg# make

- Terminal@Rodrigo:/play_ffmpeg# ./output/main

#### Obs : Certfique-se se você está usando um compilador c++ <= 17 