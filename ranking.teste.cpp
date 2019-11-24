#include "doctest.h"

#define endereco "../documentos/testes/"
#define arquivo  "text.txt"

class Teste{
	public:
		static Dataset* ds(const Ranking &r){
			return r.ds_;
		}
		static double* arq_coord(const Ranking &r){
			return r.coordenadas_consulta_;
		}
		static double sum_com_2(const Ranking &r){
			return r.sum_com_2_;
		}
}

TEST_SUITE("Ranking"){
	TEST_CASE("Ranking()"){
		Dataset ds_test(endereco);		
		Indice_invertido id_iv_test(&ds_test, arquivo);
		Ranking r(id_iv_teste, &ds_test);
		CHECK(Teste::ds(r) == &ds_test);
		CHECK(Teste::sum_com_2(r) == 0);
	}

	TESTE_CASE("Ler_coordenadas()"){
		Dataset ds_test(endereco);		
		Indice_invertido id_iv_test(&ds_test, arquivo);
		Ranking r(id_iv_teste, &ds_test);
		CHECK(ds_test.Ler_coordenadas(1) == {0,0,0});
		CHECK(ds_test.Ler_coordenadas(2) == {0,0,0});
	}

	TESTE_CASE("Similaridade()"){
		Dataset ds_test(endereco);		
		Indice_invertido id_iv_test(&ds_test, arquivo);
		Ranking r(id_iv_teste, &ds_test);
		CHECK(ds_test.Similaridade(1) == 0);
		CHECK(ds_test.Similaridade(2) == 0);
	}

	TESTE_CASE("Ordenar_documentos()"){
		Dataset ds_test(endereco);		
		Indice_invertido id_iv_test(&ds_test, arquivo);
		Ranking r(id_iv_teste, &ds_test);
		vector<vector<int> > v_teste;
		v_teste[0].push_back(0);
		v_teste[0].push_back(1);
		CHECK(ds_test.Ordenar_documentos() == v_teste);
	}
}