
#include "Play_ffmpeg.hpp"
#include <iostream>
using namespace  std;


extern "C" {
    #include <libavformat/avformat.h>
}

int main (){
  
     Play_ffmpeg play_ffmpeg;

    
    std::cout<< "Selecione o video para ver a codificação:\n"; 

    std::string arq = play_ffmpeg.selectVideo();
    
    std::string s = "./data/"+arq;

    play_ffmpeg.codec_ffmpeg(s);

    std::cout<< "Selecione o video para exibição:\n"; 

    play_ffmpeg.playVideo();
    return 0;
}
