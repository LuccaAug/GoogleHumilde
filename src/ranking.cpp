#include "ranking.h"

Ranking::Ranking(Indice_invertido id_iv, Dataset* dts){
    double* coordenadas_consulta_ = id_iv.Calc_coordenadas_consulta();
    double sum_con_2_ = 0;
    Dataset* ds_ = dts; 
    int numero_de_palavras_ = ds_->Contar_palavras();

    for(int palavra = 0; palavra < numero_de_palavras_; ++palavra){
        sum_con_2_ += coordenadas_consulta_[palavra]*coordenadas_consulta_[palavra];
    }
}

double* Ranking::Ler_coordenadas(int id_documento) {
    ifstream linhas_coordenadas;
    linhas_coordenadas.open("indice_invertido.txt");

    int numero_de_palavras_ = ds_->Contar_palavras();
    double* coordenadas_documento = new double[numero_de_palavras_];
    double cood;

    stringstream lin;
    string linha, coordenada;

    for (int linen = 0; linen < id_documento; linen++){
        getline(linhas_coordenadas,linha);
    }

    lin << linha;

    for(int i=0; i<numero_de_palavras_; i++){
        getline(lin,coordenada, ' ');
        cood = stod(coordenada, nullptr);
        coordenadas_documento[i] = cood;
    }

    linhas_coordenadas.close();

    return coordenadas_documento;
}

double Ranking::Similaridade(int id_documento) {
    double numerador=0, sum_doc_2=0, denominador;
    double* coordenadas_documento;

    coordenadas_documento = Ler_coordenadas(id_documento);

    for(int palavra = 0; palavra < ds_->Contar_palavras(); ++palavra){
        numerador += coordenadas_documento[palavra]*coordenadas_consulta_[palavra];

        sum_doc_2 += coordenadas_documento[palavra]*coordenadas_documento[palavra];
    }

    delete [] coordenadas_documento;

    denominador = sqrt(sum_doc_2)*sqrt(sum_con_2_);

    return numerador/denominador;
}

vector<vector<int> > Ranking::Ordenar_documentos(){
    map<double, vector<int> >similaridades;
    vector<pair <double, vector<int> > >ordenar;
    vector<vector<int> > ordenado;
    double cos;

    for(int documento=1; documento <= ds_->Numero_de_documentos(); documento++) {
        cos = Similaridade(documento);
        if(similaridades.find(cos)!=similaridades.end()){
            similaridades[cos].push_back(documento);
        }
        else{
            vector<int> doc;
            doc.push_back(documento);
            similaridades.insert(make_pair(cos,doc));
        }
    }

    for(map<double, vector<int> >::iterator it = similaridades.begin(); it!=similaridades.end(); it++){
        ordenar.push_back(make_pair(it->first, it->second));
    }

    sort(ordenar.begin(), ordenar.end());

    for(vector<pair <double, vector<int> > >::iterator it = ordenar.begin(); it!=ordenar.end(); it++){
        ordenado.push_back(it->second);
    }

    return ordenado;
}

void Ranking::Mostrar_ranking() {
    vector<vector<int> > documentos_ordenados = Ordenar_documentos();
    int posicao = 1;

    cout<<"\tRanking:"<<endl;
    cout<<"Posicao : Documentos"<<endl;
    for(vector<vector<int> >::reverse_iterator it = documentos_ordenados.rbegin(); it!=documentos_ordenados.rend(); it++){
        printf("%7d : ", posicao);
        for(vector<int>::iterator document = it->begin(); document != it->end(); document++){
            cout<<"D"<<*document<<", ";
        }
        cout<<"D"<<*it->end()-1<<endl;
        posicao++;
    }
}

Ranking::~Ranking(){
    delete [] coordenadas_consulta_;
    double sum_con_2_ = 0;
}