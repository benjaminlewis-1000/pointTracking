#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include <stdlib.h>

using namespace cv;

volatile int quit_signal=0;
#ifdef __unix__
#include <signal.h>
extern "C" void quit_signal_handler(int signum) {
 if (quit_signal!=0) exit(0); // just exit already
 quit_signal=1;
// printf("Will quit at next camera frame (repeat to kill now)\n");
}
#endif

int main(int argc, char** argv){
	namedWindow("Video",WINDOW_NORMAL);
	
	VideoCapture cap(argv[1]); // open the default camera
	if(!cap.isOpened()){ // check if we succeeded
		return -1;
	}
	#ifdef __unix__
	   signal(SIGINT,quit_signal_handler); // listen for ctrl-C
	#endif

}
