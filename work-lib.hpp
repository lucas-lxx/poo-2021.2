#pragma once
#include <iostream>
#include <vector>
#include <string>

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

// qual_metade_eh_mais_estressada: O nível de stress somado de todas as pessoas da primeira metade é maior que o nível de stress somado das pessoas da segunda metade da fila? (abs)
//retorna "primeira", "segunda" ou "empate"
std::string mais_homens_ou_mulheres(const vector<int>& fila) {

}
