
#include "Play_ffmpeg.hpp"
#include <iostream>
using namespace  std;


extern "C" {
    #include <libavformat/avformat.h>
}

int main (){
  
     Play_ffmpeg play_ffmpeg;

    

    std::string arq = play_ffmpeg.selectVideo();
    
    std::string s = "./data/"+arq;

    play_ffmpeg.codec_ffmpeg(s);

    play_ffmpeg.playVideo();

    return 0;
}
