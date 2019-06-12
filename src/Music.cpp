#include "Music.hpp"

Music::Music(string filename){
    if(!music.openFromFile(filename))
        cerr << "Erro ao ler música do arquivo: " << filename << endl;
    music.setLoop(true);
    music.setVolume(25.0);
}

Music::~Music(){}

void Music::play(){
    start();
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