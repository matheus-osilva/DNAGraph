#include "dna.h"

template<typename T>
T random(T range_from, T range_to) {
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<T>    distr(range_from, range_to);
    return distr(generator);
}

//takes a string which represents a dna sequence and break it in N pieces, the piece's size is in the interval [B,E]
std::vector<std::string> splitdna(std::string sequence, int N, int B, int E){
    std::vector<std::string> splited;
    int index;
    int psize;
    int minIndex;
    for (int i = 0; i < N; i++)
    {
        psize = random(B, E);
        minIndex = sequence.size() - psize;
        index = random(0, minIndex);
        std::cout << index << ", " << psize << std::endl;
        splited.push_back(sequence.substr(index, psize));
        std::cout << "tamanho do pedaco: " << (sequence.substr(index, psize)).size() << std::endl;
    }
    return splited;
}




/*int main(){
    std::vector<std::string> splited_sequence;
    std::string key = "testando a separacao de string";
    int B = 4;
    int E = 6;
    splited_sequence = splitdna(key, 100, B, E);
    for (int i = 0; i < splited_sequence.size(); i++){
        std::cout << splited_sequence[i] << std::endl;
    }
    return 0;
}*/
