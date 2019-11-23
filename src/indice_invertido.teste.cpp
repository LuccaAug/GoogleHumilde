#include "doctest.h"

#define endereco "../documentos/testes/"
#define arquivo  "text.txt"

class Teste{
	public:
		static Dataset* ds(const Indice_invertido &i){
			return i.ds_;
		}
		static string arq_coord(const Indice_invertido &i){
			return i.arq_coord_;
		}
}

TEST_SUITE("Indice_invertido"){
	TEST_CASE("Indice_invertido()"){
		Dataset ds_test(endereco);
		Indice_invertido i(&ds_test, arquivo);
		CHECK(Teste::ds(i) == &ds_test);
		CHECK(Teste::ds(i) == arquivo);
	}

	TEST_CASE("idf()"){
		Dataset ds_test(endereco);
		Indice_invertido i(&ds_test, arquivo);
		 
	}

	TEST_CASE("W()"){
		Dataset ds_test(endereco);
		Indice_invertido i(&ds_test, arquivo);
		
	}
	
	TEST_CASE("Arquivo_Indice_Invertido()"){
		Dataset ds_test(endereco);
		Indice_invertido i(&ds_test, arquivo);
		ofstream arquivo;
		arquivo.open(arquivo);
	}

	TEST_CASE("Calc_coordenadas_consulta()"){
		Dataset ds_test(endereco);
		Indice_invertido i(&ds_test, arquivo);
		
	}
}