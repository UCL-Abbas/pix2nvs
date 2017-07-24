
#ifndef ALL_DEFINES
#define ALL_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>

// Windows OS

#ifdef MSWIN

#include "dirent_win.h"
#include <windows.h>
#include <io.h>

#define access                  _access
#define INPUT_FOLDER      	".\\input\\"
#define TMP_FOLDER		".\\Frames\\"
#define EVENT_FOLDER            ".\\Events\\"
#define FFPROBE                 "ffprobe_win"
#define FFMPEG                  "ffmpeg_win"
#define F_OK               	0

// Unix OS

#else

#include <unistd.h>
#include "dirent_Linux.h"

#define INPUT_FOLDER		"./input/"
#define TMP_FOLDER		"./Frames/"
#define EVENT_FOLDER            "./Events/"
#define FFPROBE                 "ffprobe"
#define FFMPEG                  "ffmpeg"

#endif

#define TOT_MEDIA_TYPES	    5
#define TOT_PIC_TYPES       1
#define MAX_STRING_SIZE	    5000
#define MAX_FILES	    5000
#define MAX_EVENT_LENGTH    76800
#define DEFAULT_D           1
#define DEFAULT_THRESHOLD   0.4
#define DEFAULT_N_MAX       5
#define DEFAULT_BLOCKSIZE   1
#define BUFFERSIZE          30
#define IDSTRING            5
#define PREFRAME            1
#define UPWHENEVENT         2
#define MIN_D               0.9
#define MAX_D               5
#define MIN_N_MAX           1
#define Max_N_MAX           5
#define MIN_THRESHOLD       0.2
#define MAX_THRESHOLD       0.7
#define BLOCKSIZE1          1
#define BLOCKSIZE2          2
#define BLOCKSIZE3          4
#define SIZEOFWIDTH         6
#define SIZEOFHEIGHT        7
#define SIZEOFRATE          5
#define TIMESCALE           1000000
#define ON                  1
#define OFF                 0
#define RGB_R               0.299
#define RGB_G               0.587
#define RGB_B               0.114
#define DEFAULT_ADAPT_THRES_COEF_SHIFT  0.05
#define MIN__ADAPT_THRES_COEF_SHIFT 	0
#define MAX__ADAPT_THRES_COEF_SHIFT 	0.1

#endif

const char pic_type[TOT_PIC_TYPES][5] = { ".bmp" };
const char media_type[TOT_MEDIA_TYPES][5] = { ".mp4", ".mkv", ".m4v", ".avi", ".flv" };

typedef unsigned char BYTE ;

struct MEDIA_FILE
{
	char *filename;
	int extension;
} ;


struct VIDEO_PER {
	char *FrameRate;
	int ImageHeight;
	int ImageWidth;
	double TimeGap;
} ;


struct MEDIA_FILE *dir_media_parse(struct MEDIA_FILE *, char *) ;
struct MEDIA_FILE *dir_pic_parse(struct MEDIA_FILE *, char *) ;



float **readframe(char *, float **, int ImageWidth, int ImageHeight) ;
float **writeframe(char *filename, float **frame, int ImageWidth, int ImageHeight) ;
float **initialize_frame(int ImageWidth, int ImageHeight, float init_value) ;
void log_frame(float** frame, int ImageWidth, int ImageHeight) ;



float **compute_contrast(float **frame, int ImageWidth, int ImageHeight);
struct VIDEO_PER get_video_per(struct VIDEO_PER video_per);
int check_arguments(float d, int n_max, float fixed_thres, float adapt_thres_coef_shift, int  blocksize);
int print_event(FILE *event, float diff_frame, float threshold, int n_max, int i, int j, int id, double TimeGap, int ImageHeight, int p);

int generate_events(struct MEDIA_FILE *pic_file, double TimeGap, MEDIA_FILE *media_file, int ivid, int ImageWidth, int ImageHeight);

class Helper {
public:
static FILE *openFile(char *f) ;
static void openFolder(const char *f, bool clear) ;
static void parse_input(int argc, char *argv[], float *d, float *fixed_thres,   
                float *adapt_thres_coef_shift, int *n_max, int *block_size) ;

} ;

