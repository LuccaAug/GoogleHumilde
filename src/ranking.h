#ifndef RANKING_H
#define RANKING_H

#include <vector>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <sstream>
#include <algorithm>
#include "indice_invertido.h"

class Ranking{
	public:

		Ranking(Indice_invertido id_iv, Dataset* dts);

		//le as coordenadas de cada documento no arquivo
		double* Ler_coordenadas(int id_documento);

		//calcula a similaridade (Cosine Similarity) entre uma palavra e um documento
		double Similaridade(int id_documento);

		//ordena quais documentos devem ser apresentados a partir da similaridade
		vector<vector<int> > Ordenar_documentos();

		//exibe o ranking de documentos
		void Mostrar_ranking();

		~Ranking();

	private:
		//vetor com todas as coordenadas
		double* coordenadas_consulta;

		//somatorio do quadrado das coordenadas
		double sum_con_2;

		Dataset* ds;
};

#endif
