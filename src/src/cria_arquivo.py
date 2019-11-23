#!/usr/bin/python

import os
import glob

os.chdir('../documentos/')
lista = open('lista_de_documentos.txt', 'w')
for doc in glob.glob('*.txt'):
	if doc != "lista_de_documentos.txt":
		lista.write(doc+"\n")
lista.close()
print(os.getcwd())

quit()