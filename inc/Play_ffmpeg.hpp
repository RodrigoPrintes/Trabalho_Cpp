#ifndef CAST_HPP
#define CAST_HPP

#include <string>
using namespace  std;

class Play_ffmpeg {

    public:
        Play_ffmpeg();
        
        std::string selectVideo();
        void playVideo();
        void codec_ffmpeg(std::string data);
    private:
        void checkDir(std::string dir);
    
    
};

#endif