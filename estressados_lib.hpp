#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
//
//
// library for the estressados programming exercises
// https://github.com/senapk/estressados
//
//
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
int procurar_a_partir(const std::vector<int>& fila, int x, int inicio){
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
int modulo_estresse(int pessoa) {
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
    for (int i = 0; i < (int) vect.size(); i++) {
        if (i == (int) (vect.size() - 1)) {
            ss << vect[i] << " ";
            break;
        }
        ss << vect[i] << ", ";
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

// retorna verdadeiro se for mulhere
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

// inverte os números
void swap (int& a, int& b) {
    int place_holder;
    place_holder = a;
    a = b;
    b = place_holder;
}

// inverte os valores do vetor de entrada sem uso de vetor auxiliar
void inverter_inplace(std::vector<int>& v) {
    for(int i = 0, j = (v.size() -1); i < (int) (v.size() / 2); i++, j--) {
        swap(v[i], v[j]);
    }
}

// sorteia um lugar do vetor
int sortear_indice (std::vector<int>& v) {
    unsigned seed = time(0);
    srand(seed);
    return rand() % v.size();
}


//retorna aleatoriamente um elemento do vetor
int sortear(std::vector<int>& v) {
    return v[sortear_indice(v)];
}


//embaralha o vetor original
void embaralhar(std::vector<int>& v) {
    for (int i = 0; i < (int) v.size(); i++){
        swap(v[i], v[sortear_indice(v)]);
    }
}

//ordena o vetor original
void ordenar(std::vector<int>& v) {
    for (int i = 0; i < (int) v.size(); i++) {
        for (int j = 0; j < (int) v.size(); j++) {
            if (v[i] < v[j]) {
                swap(v[i], v[j]);
            }
        }
    }
}

// Conjuntos: 3 funçõesda de um único representante de cada valor, ou seja, uma lista dos valores que aparecem na fila sem repetição. Que conjunto foi formado?
std::vector<int> exclusivos(const std::vector<int>& v) {
    std::vector<int> excl {};
    for (int i = 0; i < (int) v.size(); i++) {
        if(!existe(excl, v[i]))
            excl.push_back(v[i]);
    }
    return excl;
}

// diferentes: Qual a lista dos diferentes níveis de stress que aparecem?
std::vector<int> diferentes(const std::vector<int>& v) {
    std::vector<int> dife {};
    for (int i = 0; i < (int) v.size(); i++) {
        if (!existe(dife, modulo_estresse(v[i])))
            dife.push_back(modulo_estresse(v[i]));
    }
    return dife;
}

// abandonados: quais pessoas ficaram na fila após remover um exemplar de cada valor?
std::vector<int> abandonados(const std::vector<int>& v) {
    std::vector<int> excl {};
    std::vector<int> aban {};
    for (int i = 0; i < (int) v.size(); i++){
        if(!existe(excl, v[i])) {
            excl.push_back(v[i]);
        } else {
            aban.push_back(v[i]);
        }
    }
    return aban;
}

// ==================================================================================================================================
// ==================================================================================================================================
// ==================================================================================================================================
// Functions for estressados III =====================================================================================================
// ==================================================================================================================================
// ==================================================================================================================================
// ==================================================================================================================================



// retorna o vetor modularizado
std::vector<int> vetor_modular(const std::vector<int>& v) {
    std::vector<int> v_mod {};
    for (int i = 0; i < (int) v.size(); i++){
        v_mod.push_back(modulo_estresse(v[i]));
    }
    return v_mod;
}

// retorna verdadeiro se for o unico elemento presente no vetor
bool unico(const std::vector<int>& v, int x) {
    if (!existe(v, x))
        return false;
    int count { 0 };
    for (int i = 0; i < (int) v.size(); i++) {
        if (x == v[i])
            ++count;
    }
    if (count > 1)
        return false;
    return true;
}

// Map - Manipulação: 3 funções
// sozinhos: Quais PESSOAS eram as únicas representantes do seu nível de stress na fila? (abs)
std::vector<int> sozinhos(const std::vector<int>& v) {
    std::vector<int> v_unic {};
    for (int i = 0; i < (int) v.size(); i++) {
        if (unico(vetor_modular(v), modulo_estresse(v[i])))
            v_unic.push_back(v[i]);
    }
    return v_unic;
}

// mais_ocorrencias: Qual a maior quantidade de ocorrências do mesmo nível de stress. (abs)
int mais_ocorrencias(const std::vector<int>& v) {
    int maior { 0 };
    for (int i = 0; i < (int) v.size(); i++) {
        if (maior < contar(vetor_modular(v), modulo_estresse(v[i])))
            maior = contar(vetor_modular(v), modulo_estresse(v[i]));
    }
    return maior;
}

// mais_recorrentes: Quais os níveis de stress mais recorrentes. (abs)
std::vector<int> mais_recorrentes(const std::vector<int>& v) {
    int mais_recorrente { mais_ocorrencias(v) };
    std::vector<int> maiores { };
    for (int i = 0; i < (int) v.size(); i++) {
        if (contar(vetor_modular(v), modulo_estresse(v[i])) == mais_recorrente && !existe(maiores, modulo_estresse(v[i])))
            maiores.push_back(modulo_estresse(v[i]));
    }
    return maiores;
}

// retorna verdadeiro se a pessoa estiver super estressada >50
bool super_estressado(const int& pessoa) {
    if (modulo_estresse(pessoa) > 100)
        return false;
    return modulo_estresse(pessoa) > 50 ? true : false;
}

// retorna verdadeiro se a pessoa estiver estressada >30
bool estressado(const int& pessoa) {
    if (modulo_estresse(pessoa) > 100)
        return false;
    return modulo_estresse(pessoa) > 30 ? true : false;
}

// Proximidade: 2 funções
// briga Quando alguém super estressado(>50) está ao lado de duas pessoas muito estressadas(>30) pode dar briga. Quantas vezes essa situação acontece?
int briga(const std::vector<int>& v) {
    int briga { 0 };
    for (int i = 1; i < (int) (v.size() - 1); i++) {
        if (super_estressado(v[i]))
            if(estressado(v[i - 1]) && estressado(v[i + 1]))
                briga++;
    }
    return briga;
}

// retorna verdadeiro se for uma pessoa hiper estressada >80
bool hiper_estressado(const int& pessoa) {
    if (modulo_estresse(pessoa) > 100)
        return false;
    return modulo_estresse(pessoa) > 80 ? true : false;
}

// retorna verdadeiro se for uma pessoa bem tranquila <10
bool bem_tranquilo(const int& pessoa) {
    if (modulo_estresse(pessoa) > 100)
        return false;
    return modulo_estresse(pessoa) < 10 ? true : false;
}

// apaziguado Se alguém hiper estressado(>80) estiver ao lado de pelo menos uma pessoa bem tranquila (<10) ela vai ser apaziguada. Em que posições estão esses que serão apaziguados?
std::vector<int> apaziguados(const std::vector<int>& v) {
    std::vector<int> apzg {};
    for (int i = 0; i < (int) v.size(); i++) {
        if (hiper_estressado(v[i]))
            if (bem_tranquilo(v[i - 1]) || bem_tranquilo(v[i + 1]))
                apzg.push_back(i);
    }
    return apzg;
}

// retorna a quantidade de mulheres enfileirados sem interrupcao
// no vetor v, a partir da posicao pos
int range_mulheres(const std::vector<int>& v, const int& pos) {
    int range { 0 };
    for (int i = pos; i < (int) v.size(); i++) {
        if (eh_mulher(v[i])) {
            range++;
        } else {
            break;
        }
    }
    return range;
}

// retorna a quantidade de homens enfileirados sem interrupcao
// no vetor v, a partir da posicao pos
int range_homens(const std::vector<int>& v, const int& pos) {
    int range { 0 };
    for (int i = pos; i < (int) v.size(); i++) {
        if (!eh_mulher(v[i])) {
            range++;
        } else {
            break;
        }
    }
    return range;
}

// retorna o tamanho o tamanho de um time sem indicar se sao homens ou mulheres (eh considerado um time quando tem mais de uma pessoa)
// no vetor v, a partir da posicao pos
int range_pessoas(const std::vector<int>& v, const int& pos) {
    int range { 0 };
    if (eh_mulher(v[pos])) {
        range = range_mulheres(v, pos);
    } else {
        range = range_homens(v, pos);
    }
    return range;
}

// retorna se eh um time a partir
// do vetor v e o indice do elemento pos
bool eh_time(const std::vector<int>& v, int pos) {
    return range_pessoas(v, pos) > 1 ? true : false;
}

// Sequências: 3 funções
// quantos_times Duas ou mais pessoas do mesmo sexo seguidas podem formar um time. Quantos times existem na fila?
int quantos_times(const std::vector<int>& v) {
    int times { 0 };
    for (int i = 0; i < (int) v.size(); i++) {
        if (eh_time(v, i)){
            times++;
            i += (range_pessoas(v, i) - 1);
        }
    }
    return times;
}

// retorna a primeira posicao do maior time no vetor v
int indice_maior_time(const std::vector<int>& v) {
    int maior { 0 };
    for(int i = 0; i < (int) v.size(); i++) {
        if (range_pessoas(v, maior) < range_pessoas(v, i)){
            maior = i;
            i += (range_pessoas(v, i) - 1);
        }
    }
    return maior;
}

// retorna se ambos os elementos sao do mesmo time
// no vetor v, comparando os indices pos_1 com pos_2
bool mesmo_time(const std::vector<int>& v, int pos_1, int pos_2) {
    if ((eh_mulher(v[pos_1]) && eh_mulher(v[pos_2])) || (!eh_mulher(v[pos_1]) && !eh_mulher(v[pos_2])))
        return true;
    return false;
}

// maior_time Qual o maior time que apareceu na fila?
// retorna o primeiro maior time presente no vetor v
std::vector<int> maior_time(const std::vector<int>& v) {
    std::vector<int> maior { };
    for(int i = indice_maior_time(v); i < (int) v.size(); i++) {
        if (!mesmo_time(v, indice_maior_time(v), i) || range_pessoas(v, indice_maior_time(v)) < 2)
            break;
        maior.push_back(v[i]);
    }
    return maior;
}


// retorna a quantidade de pessoas em times
// do vetor v
int soma_pessoas_em_times(const std::vector<int>& v) {
    int soma { 0 };
    for(int i = 0; i < (int) v.size(); i++) {
        if (eh_time(v, i)){
            soma += range_pessoas(v, i);
            i += (range_pessoas(v, i) - 1);
        }
    }
    return soma;
} 


// sem_time Quantas pessoas não estavam em um time?
int sem_time(const std::vector<int>& v) {
    return v.size() - soma_pessoas_em_times(v);
}


//Grupos: 2 funcoes
//casais: Casais são formados quando quando um homem e uma mulher com o mesmo nível de stress são formados. O 3 e o -3 formam um casal. Os participantes fossem orientados a sair da fila e procurar seu par. Quantos casais poderiam ser formados?

// retorna a quantidade de mulheres no vetor v
int soma_mulheres_no_vetor(const std::vector<int>& v) {
    int soma { 0 };
    for(int i = 0; i < (int) v.size(); i++) {
        if (!eh_mulher(v[i]))
            continue;
        soma++;
    }
    return soma;
}

// retorna a quantidade de homens no vetor v
int soma_homens_no_vetor(const std::vector<int>& v) {
    return v.size() - soma_mulheres_no_vetor(v);
}

//retorna verdadeiro se existem homens
bool checar_homens_no_vetor(std::vector<int> v) {
    return soma_homens_no_vetor(v) <= 0 ? false : true;
}

// retorna verdadeiro ou falso,
// se h e m forem opostos, mas de mesmo valor
bool tem_match(int& h, int& m) {
    return h == (m * -1) ? true : false;
}

// trios: Pedimos pros participantes se organizassem em trios. Todos os 3 deveriam estar com o mesmo nível de stress.Quantos trios podem ser formados?

// exclui o casal do vetor v
// nas posicoes de indice pos_1 e pos_2
// atencao pois os indices devem estar na ordem pos_1 < pos_2
void exclui_casal(std::vector<int>& v, int& pos_1, int& pos_2) {
    v.erase(v.begin() + pos_1);
    v.erase(v.begin() + (pos_2 - 1));
}

// retorna os casais que podem ser criados dentro do vetor v
int casais_no_vetor(std::vector<int> v) {
    int soma_casais { 0 };
    ordenar(v);
    if(!checar_homens_no_vetor(v))
        return soma_casais;
    for(int i = 0; v[i] < 0; i++) {
        for(int j = ((int) v.size() - 1); v[j] > 0; j--) {
            if (tem_match(v[i], v[j])) {
                exclui_casal(v, i, j);
                i -= 1;
                soma_casais++;
                break;
            }
        }
   }
    return soma_casais;
}


// exclui o trio do vetor v
// nas posicoes de indice pos_1, pos_2 e pos_3
// atencao pois os indices devem estar na ordem pos_1 < pos_2 < pos_3
void exclui_trio(std::vector<int>& v, int& pos_1, int& pos_2, int& pos_3) {
    v.erase(v.begin() + pos_1);
    v.erase(v.begin() + (pos_2 - 1));
    v.erase(v.begin() + (pos_3 - 2));
}

int trios_no_vetor(std::vector<int> v) {
    int soma_trios { 0 };
    for(int i = 0; i < (int) v.size(); i++) {
        for(int j = (i + 1); j < (int) v.size(); j++) {
            if (modulo_estresse(v[i]) == modulo_estresse(v[j])) {
                for(int k = (j + 1); k < (int) v.size(); k++) {
                    if (modulo_estresse(v[j]) == modulo_estresse(v[k])) {
                        exclui_trio(v, i, j, k);
                        i -= 1;
                        soma_trios++;
                        break;
                    }
                }
            }
        }
    }
    return soma_trios;
}

// remove: Dado a pessoa X, como fica a fila após remover X?

// remove um elemento do vetor v
// na posicao de indice pos
void remove_do_vetor(std::vector<int>& v, int pos) {
    v.erase(v.begin() + pos);
}

// insert: Como fica a fila se eu inserir a pessoa X na posição Y.

// insere um elemento no vetor v
// na posicao de indice pos e valor add
void adiciona_ao_vetor(std::vector<int>& v, int pos, int add) {
    v.insert(v.begin() + pos, add);
}