#!/usr/bin/python

import os
import glob

os.chdir('../documentos/documentos/')
lista = open('lista_de_documentos.txt', 'w')
for folder in os.listdir(os.getcwd()):
	if folder != "lista_de_documentos.txt":
		for doc in os.listdir(os.getcwd()+'/'+folder):
			lista.write(folder+'/'+doc+"\n");
lista.close()

os.chdir('../testes/')
lista = open('lista_de_documentos.txt', 'w')
for doc in glob.glob('*.txt'):
	if doc != "lista_de_documentos.txt":
		lista.write(doc+"\n")
lista.close()

quit()