#include "doctest.h"

class Teste{
	public:
		static Dataset* ds(const indice_invertido &i){
			return i.ds_;
		}
		static string arq_coord(const indice_invertido &i){
			return i.arq_coord_;
		}
}

TEST_SUITE("Indice_invertido"){
	TEST_CASE("Indice_invertido()"){
		Dataset ds_test;
		Indice_invertido i(ds_test, "test.txt");
		CHECK(Teste::ds(i) == &ds_test);
		CHECK(Teste::ds(i) == "test.txt");
	}

	TEST_CASE("idf()"){
		 
	}

	TEST_CASE("W()"){
		
	}
	
	TEST_CASE("Arquivo_Indice_Invertido()"){
		Dataset ds_test;
		Indice_invertido i(ds_test, "test.txt");
		ofstream arquivo;
		arquivo.open("test.txt");
	}

	TEST_CASE("Calc_coordenadas_consulta()"){
		
	}
}