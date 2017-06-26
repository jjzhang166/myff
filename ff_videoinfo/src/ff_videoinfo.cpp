//============================================================================
// Name        : ffmpeg.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//这个程序用来查看视频文件的信息，是一个基本的ffmepg的程序

#include <iostream>
using namespace std;

extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
}

#include <stdio.h>
int main(int argc, char *argv[]) {
   AVFormatContext   *pFormatCtx = NULL;
   if(argc < 2) {
        printf("Please provide a movie file\n");
        return -1;
  }
   av_register_all();
   if(avformat_open_input(&pFormatCtx, argv[1], NULL, NULL)!=0)
        return -1; // Couldn't open file
   if(avformat_find_stream_info(pFormatCtx, NULL)<0)
        return -1; // Couldn't find stream information

   av_dump_format(pFormatCtx, 0, argv[1], 0);
   avformat_close_input(&pFormatCtx);
   return 0;

}
