#include "Music.hpp"

Music::Music(const std::string filename){
    if(!music.openFromFile(filename))
        std::cerr << "Erro ao ler música do arquivo: " << filename << std::endl;
    music.setLoop(true);
    music.setVolume(10.0);
}

Music::~Music(){ }

void Music::play(){
    start(); // Chama a função Music::run() via polimorfismo
}

void Music::run(){
    music.play();
}

void Music::pause(){
    music.pause();
}

void Music::stop(){
    music.stop();
}
