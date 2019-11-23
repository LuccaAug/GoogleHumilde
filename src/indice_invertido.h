#ifndef INDICE_INVERTIDO_H
#define INDICE_INVERTIDO_H

#include <iomanip>
#include <cmath>
#include "dataset.h"

using namespace std;

class Indice_invertido{
    public:

        Indice_invertido(Dataset* dts, string arq);

        // Desaloca toda a memória alocada para.
        ~Indice_invertido();

        double* Calc_coordenadas_consulta();

        // Cria um arquivo em que cada linha é um documento dj 
        // e cada coluna uma palavra Px, e na posição (dj, Px)
        // o W correspondente
        void Arquivo_Indice_Invertido();

    private:

        Dataset* ds_;

        string arq_coord_;

        // Calcula a importância de uma palavra em um documento
        double idf(int idPx);

        // Calcula a coordenada do documento dj no eixo Px
        double W(int dj, int idPx);

    friend class Teste;
};

#endif  // INDICE_INVERTIDO_H