#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "indice_invertido.h"
#include <string>
#include <iomanip>
#include <cmath>

class Teste{
	public:
		static Dataset* ds(const Indice_invertido &i){
			return i.ds_;
		}
		static string arq_coord(const Indice_invertido &i){
			return i.arq_coord_;
		}
		static double idf(const Indice_invertido &i, int idPx_){
			return i.idf(idPx_);
		}
		static double W(const Indice_invertido &i, int dj_, int idPx_){
			return i.W(dj_, idPx_);
		}
};

TEST_SUITE("Indice_invertido"){
	TEST_CASE("Indice_invertido()"){
		Dataset ds_test("../documentos/testes/");
		Indice_invertido i(&ds_test, "../documentos/testes/");
		CHECK(Teste::ds(i) == &ds_test);
		CHECK(Teste::arq_coord(i) == "../documentos/testes/");
	}

	TEST_CASE("idf()"){
		Dataset ds_test("../documentos/testes/");
		Indice_invertido i(&ds_test, "../documentos/testes/");
		CHECK(Teste::idf(i, 0) == 0);
		CHECK(Teste::idf(i, 1) == 0);
		CHECK(Teste::idf(i, 2) == log(2));
		CHECK(Teste::idf(i, 3) == log(2));
		CHECK(Teste::idf(i, 7) == 0);
	}

	TEST_CASE("W()"){
		Dataset ds_test("../documentos/testes/");
		Indice_invertido i(&ds_test, "../documentos/testes/");

		CHECK(Teste::W(i, 1, 0) == 0); // A.txt - documento
		CHECK(Teste::W(i, 1, 1) == 0); // A.txt - teste
		CHECK(Teste::W(i, 1, 2) == 2*log(2)); // A.txt - pds
		CHECK(Teste::W(i, 1, 3) == 0); // A.txt - 2
		CHECK(Teste::W(i, 2, 0) == 0); // B.txt - documento
		CHECK(Teste::W(i, 2, 1) == 0); // B.txt - teste
		CHECK(Teste::W(i, 2, 2) == 0); // B.txt - pds
		CHECK(Teste::W(i, 2, 3) == log(2)); // B.txt - 2
	}
	
	TEST_CASE("Arquivo_Indice_Invertido()"){
		Dataset ds_test("../documentos/testes/");
		Indice_invertido i(&ds_test, "../documentos/testes/");
		ofstream arq;
		arq.open("../documentos/testes/");
	}

	TEST_CASE("Calc_coordenadas_consulta()"){
		Dataset ds_test("../documentos/testes/");
		Indice_invertido i(&ds_test, "../documentos/testes/");
	}
}