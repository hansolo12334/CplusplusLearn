#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include"libavformat/avformat.h"
#include"libavcodec/avcodec.h"
#include"libavdevice/avdevice.h"

char *input_name = "video4linux2";

char *file_name = "/dev/video0";

char *output_file = "test.jpg";


void captureOneFrame(void)
{
    AVFormatContext *fmtCtx = NULL;
    AVPacket *packet;
    const AVInputFormat *inputFmt;
    FILE *fp;
    int ret;


    inputFmt = av_find_input_format(input_name);

    if(inputFmt==NULL)
    {
        printf("can not find input format\n");
        return;
    }
    if(avformat_open_input( &fmtCtx, file_name,inputFmt,NULL ) <0 )
    {
        printf("can not open input file\n");
    }

    av_dump_format(fmtCtx, 0, file_name, 0);

    packet = (AVPacket *)av_malloc(sizeof(AVPacket));


    // while (1)
    // {
    //     av_read_frame(fmtCtx, packet);
    //     printf("data length=%d\n", packet->size);
    //     packet->data;
    //     // free(packet);
    // }

    av_read_frame(fmtCtx, packet);


    const AVCodec *jpegCodec = avcodec_find_encoder(AV_CODEC_ID_JPEG2000);

    AVCodecContext *jpegContext = avcodec_alloc_context3(jpegCodec);

    jpegContext->height = 480;
    jpegContext->width = 640;

    if(avcodec_open2(jpegContext,jpegCodec,NULL)<0)
    {
        return;
    }




    printf("data length=%d\n", packet->size);

    fp = fopen(output_file, "wb");
    if(fp<0)
    {
        printf("open frame data file failed\n");
        return;
    }

    fwrite(packet->data, 1, packet->size, fp);
    fclose(fp);

    // av_free_packet(packet);
    av_packet_free(&packet);

    free(packet);
    avformat_close_input(&fmtCtx);
}

int main()
{

    //avcodec_register_all();
    avdevice_register_all();
    captureOneFrame();
    return 0;
}


//ffmpeg -f video4linux2 -s 640x480 -i /dev/video0 ./test.avi
