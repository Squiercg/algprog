Introdução à Bioinformática
Professor Said Sadique Adi
===================

<nome executavel> [-g,-l,-s] -u <arquivo 1a. sequencia> -v <arquivo 2a. sequencia> -i <w(a,a)> -d <w(a,b)> -e <w(-,b) ou w(a,-)>
Nas duas linhas acima, -g, -l e -s correspondem ao tipo de alinhamento desejado (global,local e semi-global, respectivamente). 
Ja sobre os parametros -i, -d e -e, eles correspondem aos valores atribuıdos pela funcao de pontuacao para colunas com caracteres iguais, diferentes e espaco, respectivamente.
  

O codigo está dividido em três arquivos. O trabalho.cpp possui uma função main com a execução da classe alinhamento e os arquivos Classes.h e Classes.cpp possuem as classes Sequencia e Alinhamento usados realizar o processamento.
