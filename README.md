# GoogleHumildao

Faz um arquivo txt com a lista dos documentos na pasta, com python

Le cada linha desse arquivo
cria um objeto struct Documento com um id e o nome
Adiciono as palavras do documento no map

Cria um vetor para cada documento com as coordenadas respectivas a cada palavra
Guarda o vetor num txt

Le a consulta
Armazena como um vector de string
Adiciona as palavras da consulta em outro map (só as palavras que ja estao em algum documento)

Cria um vetor com as coordenadas de cada palavra

Le cada vetor das coordenadas do documento
Faz o cosine ranking entre o vetor da consulta e esse vetor do documento
Exibe o ranking
