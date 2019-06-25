#include "Music.hpp"

System::Music::Music(const std::string filename){
    if(!music.openFromFile(filename))
        std::cerr << "Erro ao ler música do arquivo: " << filename << std::endl;
    music.setLoop(true);
    music.setVolume(10.0);
}

System::Music::~Music(){ }

void System::Music::play(){
    start(); // Chama a função System::Music::run() via polimorfismo
}

void System::Music::run(){
    music.play();
}

void System::Music::pause(){
    music.pause();
}

void System::Music::stop(){
    music.stop();
}
