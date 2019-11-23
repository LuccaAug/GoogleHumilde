#include "indice_invertido.h"

Indice_invertido::Indice_invertido(Dataset* dts, string arq){
    Dataset* ds_ = dts;
    string arq_coord_ = arq;

}

double Indice_invertido::idf(int idPx){
    cout << "Documentos no Id Iv: " << ds_->Quantos_documentos_possuem_essa_palavra(idPx);
    if(ds_->Quantos_documentos_possuem_essa_palavra(idPx) == 0)
        return 0.0;
	return(log(ds_->Numero_de_documentos()/ds_->Quantos_documentos_possuem_essa_palavra(idPx)));
}

double Indice_invertido::W(int dj, int idPx){
	return((ds_->Quantas_vezes_dj_possui_Px(dj, idPx))*(this->idf(idPx)));
}

void Indice_invertido::Arquivo_Indice_Invertido(){
    double coordenada;
    ofstream arquivo;
    arquivo.open(arq_coord_);
    if(arquivo.is_open()){
        //cout<<"arquivo aberto    " << ds_->Numero_de_documentos() << endl;
        for (long int docum = 1; docum <= 2 /*ds_->Numero_de_documentos()*/; docum++){
        	//cout << "\r Seus arquivos estam sendo processados:" << docum << "/" << ds_->Numero_de_documentos();
            cout << "No indice invertido: " << ds_->Contar_palavras() << endl;
            for (long unsigned int word = 0; word <= ds_->Contar_palavras(); word++){
        		coordenada = W(docum, word);
                cout << "coordenada: " << coordenada << endl;
                arquivo << coordenada <<" ";
        	}
        	arquivo << "\n";
        }
    }
    arquivo.close();
    
}
double* Indice_invertido::Calc_coordenadas_consulta(){
    int quant_palavras = ds_->Contar_palavras();
    double* coordenadas_consulta = new double[quant_palavras];

    for (int word = 0; word <= quant_palavras; word++){
        coordenadas_consulta[word] = W(0,word);
    }

    return coordenadas_consulta;
}

Indice_invertido::~Indice_invertido(){}