#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// ==================================================================================================================================
// ==================================================================================================================================
// ==================================================================================================================================
// Functions for estressados I ======================================================================================================
// ==================================================================================================================================
// ==================================================================================================================================
// ==================================================================================================================================



// transforma funções booleanas de 0 e 1 para true ou false
std::string to_alpha(bool x) {
    return x ? "true" : "false";
}

// existe: Alguém com o valor X está na fila?
bool existe (const std::vector<int>& fila, int x) {
    for (int i : fila) {
        if (x == i) 
            return true;
    }
    return false;
}

// contar: Quantas vezes o valor X apareceu na fila?
int contar(const std::vector<int>& fila, int x) {
    int count = 0;
    for (int i : fila) {
        if (i == x) 
            count++;
    }
    return count;
}

// procurar: Em que posição da fila aparece X pela primeira vez?
// retorna -1 se não encontrar
int procurar(const std::vector<int>& fila, int x){
    for (int i : fila) {
        if (i == x) 
            return 1;
    }
    return -1;
}

// procurar_apartir: Dada a posição para iniciar a busca, qual a próxima posição em que aparece X?
// retorna -1 se não encontrar
int procurar_apartir(const std::vector<int> fila, int x, int inicio){
    for (int i = inicio; i < (int) fila.size(); i++) {
        if(fila[i] == x) 
            return i;
    }
    return -1;
}

// Melhor caso: 4 funções
// procurar_menor: qual o menor valor da lista?
int procurar_menor(const std::vector<int>& fila){
    int menor { fila[0] };
    for (int i : fila) {
        if (i < menor) 
            menor = i;
    }
    return menor;
}

// procurar_pos_menor: qual a posição do menor valor da lista?
int procurar_pos_menor(const std::vector<int>& fila) {
    int menor { fila[0] };
    int pos_menor { 0 };
    for (int i = 0; i < (int) fila.size(); i++) {
        if (fila[i] < menor){ 
            menor = fila[i];
            pos_menor = i;
        }
    }
    return pos_menor;
}

// procurar_pos_menor_apartir: Dada a posição para iniciar a busca, qual a posição do menor valor da lista?
int procurar_pos_menor_apartir(const std::vector<int>& fila, int inicio) {
    int menor { fila[0] };
    int pos_menor { 0 };
    for (int i = inicio; i < (int) fila.size(); i++) {
        if(fila[i] < menor) {
            menor = fila[i];
            pos_menor = i;
        }
    }
    return pos_menor;
}

// procurar_pos_melhor_se: qual a posição do HOMEM mais calmo? (menor valor maior que 0)
int procurar_pos_melhor_se(const std::vector<int>& fila) {
    int mais_calmo { fila[0] };
    for (int i : fila) {
        if (i > 0 && i < mais_calmo)
            mais_calmo = i;
    }
    if (mais_calmo <= 0)
        return -1;
    return mais_calmo;
}

// Contagem: 4 funções
// calcular_stress_medio: qual a média de stress da fila? (abs)
//retorna -1 se não encontrar
float calcular_stress_medio(const std::vector<int>& fila) {
    int soma { 0 };
    int tamanho_vetor { (int) fila.size() };
    for (int i : fila) {
        i > 0 ? soma += i : soma += (i * -1);
    }
    return (float) soma / tamanho_vetor;
}

// mais_homens_ou_mulheres: Na fila existem mais homens ou mulheres?
//retorna "homens", "mulheres" ou "empate"
std::string mais_homens_ou_mulheres(const std::vector<int>& fila) {
    int homens { 0 };
    int mulheres { 0 };
    for (int i : fila) {
        if (i == 0) 
            continue;
        i > 0 ? homens++ : mulheres++;
    }
    if (mulheres == homens) {
        return "empate";
    } else if (mulheres > homens) {
        return "mulheres";
    } else {
        return "homens";
    }  
}

// Modulo conversor de estresse homens e mulheres
int modulo_estresse (int pessoa) {
    return pessoa > 0 ? pessoa : (pessoa * -1);
}

// qual_metade_eh_mais_estressada: O nível de stress somado de todas as pessoas da primeira metade é maior que o nível de stress somado das pessoas da segunda metade da fila? (abs)
//retorna "primeira", "segunda" ou "empate"
std::string qual_metade_eh_mais_estressada(const std::vector<int>& fila) {
    int soma_primeira_parte { 0 };
    int soma_segunda_parte { 0 };
    for (int i = 0; i < (int) fila.size(); i++) {
        if (i < (int) (fila.size() / 2)) {
            soma_primeira_parte += modulo_estresse(fila[i]);
        } else {
            soma_segunda_parte += modulo_estresse(fila[i]);
        }
    }
    if (soma_primeira_parte == soma_segunda_parte) {
        return "empate";
    } else if (soma_primeira_parte > soma_segunda_parte) {
        return "primeira";
    } else {
        return "segunda";
    }
}

// homens_sao_mais_estressados_que_mulheres: a média do stress dos homens é maior que a das mulheres?
std::string homens_sao_mais_estressados_que_mulheres(const std::vector<int>& fila){
    int estresse_homens { 0 };
    int estresse_mulheres { 0 };
    for (int i : fila) {
        if (i == 0)
            continue;
        if (i > 0){
            estresse_homens += i;
        } else {
            estresse_mulheres += i;
        }
    }
    estresse_mulheres = (estresse_mulheres * -1);
    std::cout << "Estresse mulheres: " << estresse_mulheres << " " << "Estresse homens: " << estresse_homens << '\n';
    
    if (estresse_mulheres == estresse_homens) {
        return "empate";
    } else if (estresse_mulheres > estresse_homens) {
        return "não";
    } else {
        return "sim";
    }
}

// ==================================================================================================================================
// ==================================================================================================================================
// ==================================================================================================================================
// Functions for estressados II =====================================================================================================
// ==================================================================================================================================
// ==================================================================================================================================
// ==================================================================================================================================



// clonar: retorna um novo vetor copiando os valores do vetor de entrada
std::vector<int> clonar(const std::vector<int>& v) {
    std::vector<int> vect { };
    for (int i : v) {
        vect.push_back(i);
    }
    return vect;
}

// printar vetor na tela
std::string vet_print(const std::vector<int>& vect) {
    std::stringstream ss;
    ss << "[ ";
    for (int i : vect) {
        if (i == vect.back()) {
            ss << i << " ";
            break;
        }
        ss << i << ", ";
    }
    ss << "]";
    return ss.str();
}

// pegar_homens: retorne uma lista com os homens (valores positivos)
std::vector<int> pegar_homens(const std::vector<int>& v) {
    std::vector<int> vect { };
    for (int i : v) {
        if (i > 0) 
            vect.push_back(i);
    }
    return vect;
}

// pegar_calmos: retorne uma lista com as pessoas com stress menor que 10 (abs)
std::vector<int> pegar_calmos(const std::vector<int>& v) {
    std::vector<int> vect_calmos { };
    for (int i : v) {
        if ((i > 0 && i < 10) || (i < 0 && i > -10))
            vect_calmos.push_back(i);
    }
    return vect_calmos;
}

// retorna verdadeiro se for mulheres
bool eh_mulher(int pessoa) {
    return pessoa < 0 ? true : false;
}

// pegar_mulheres_calmas: retorne uma lista com as mulheres com nível de stress menor que 10.(negativos menor que 10)

std::vector<int> pegar_mulheres_calmas(std::vector<int> v) {
    std::vector<int> vect_calmas = pegar_calmos(v);
    for (int i = 0; i < (int) vect_calmas.size(); i++) {
        if (!eh_mulher(vect_calmas[i]))
            vect_calmas.erase(vect_calmas.begin() + i);
    }
    return vect_calmas;
}


// Retorna um novo vetor com os dados invertidos
std::vector<int> inverter_com_copia(const std::vector<int>& vet) {
    std::vector<int> v { vet };
    int place_holder;
    for(int i = 0, j = (v.size() -1); i < (int) (v.size() / 2); i++, j--) {
        place_holder = v[i];
        v[i] = v[j];
        v[j] = place_holder;
    }
    return v;
}

// inverte os valores do vetor de entrada sem uso de vetor auxiliar
void inverter_inplace(std::vector<int>& v) {
    int place_holder;
    for(int i = 0, j = (v.size() -1); i < (int) (v.size() / 2); i++, j--) {
        place_holder = v[i];
        v[i] = v[j];
        v[j] = place_holder;
    }
}

//retorna aleatoriamente um elemento do vetor
int sortear(const std::vector<int>& v) {
    return v[rand() % v.size()];
}