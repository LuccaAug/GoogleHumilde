#include "dataset.h"

map<string, pair<int,int> > Fazer_consulta(){
    string consulta;
    getline(cin, consulta);

    map<string, pair<int,int> > vocabulario_consulta;

    string palavra;

    while(getline(consulta, palavra, ' ')){
        if(vocabulario_consulta.find(palavra) != vocabulario_consulta.end()){
            vocabulario_consulta[palavra][0].second++;
        }else{
            vetor.push_back(make_pair(0, 1));
            vocabulario_consulta.insert(make_pair(palavra, vetor));
        }
    }

    return vocabulario_consulta;
}










