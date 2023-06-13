#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include "Play_ffmpeg.hpp"

#include <filesystem>

using namespace  std;
namespace fs = std::filesystem;

extern "C" {
    #include <libavformat/avformat.h>
}

Play_ffmpeg::Play_ffmpeg(){}

void Play_ffmpeg::checkDir(std::string dir){
    std::string path = dir; // Diretório atual
    std::cout <<"Pasta /data:\n";
    int i = 1;
    for (const auto& entry : fs::directory_iterator(path)) {
        if (fs::is_regular_file(entry.status())) {
            std::cout <<i<<": "<< entry.path().filename().string() << std::endl;
            i++;
        }
    }

}

std::string Play_ffmpeg::selectVideo(){
    checkDir("./data");
    int index = 0, i=1;
    std::cout <<"Selecione o número do seu vídeo:\n";
    std::cin >> index;
    
    for (const auto& entry : fs::directory_iterator("./data")) {
        if (fs::is_regular_file(entry.status())) {
            if( index == i){
                return entry.path().filename().string();
            }
            
            i++;
        }
    }
    return "not found";
}

void Play_ffmpeg::playVideo(){

    

    std::string arq = selectVideo();
    

    std::string s = "./data/"+arq;

    codec_ffmpeg(s);

    std::string c_char = "ffplay -autoexit ./data/"+arq;
    int result = -1;

    //const char* arquivo = const_cast<char*>(arq.c_str());
    const char* comando = const_cast<char*>(c_char.c_str());
    try
    {
       
        result = system(comando);

        std::cout <<"Result :"<< result <<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "Error ao reproduzir video: \n";
    }

 
}

void Play_ffmpeg::codec_ffmpeg(std::string data){
    try
    {
        
        avformat_network_init();
        
        AVFormatContext* formatContext = nullptr;
       
        const char* data_2char = const_cast<char*>(data.c_str());

        int result = avformat_open_input(&formatContext, data_2char, nullptr, nullptr);
        if (result  != 0){
            throw -1;
        }
       
        AVCodec* codec = nullptr;
        int videoStreamIndex = av_find_best_stream(formatContext, AVMEDIA_TYPE_VIDEO, -1, -1, &codec, 0);

        if (videoStreamIndex < 0){
            throw -2;
        }

        std::string codecName = avcodec_get_name(codec->id);
        std::cout << "Codec de vídeo: " << codecName << std::endl;

        avformat_close_input(&formatContext);
        avformat_network_deinit();

    }
    catch(int error){
        if (error == 0) {
            std::cout << "Erro ao abrir o arquivo MP4." << std::endl;
        
        }
        if (error == -2) {
            std::cout << "Nenhum stream de vídeo encontrado." << std::endl;
        }  
        //const std::exception& e
        //std::cerr << e.what() << '\n';
    }
    
}
