#include<iostream>
#include<stdio.h>
#include</home/animesh/opencv/modules/highgui/include/opencv2/highgui.hpp>
#include</home/animesh/opencv/modules/core/include/opencv2/core.hpp>
using namespace cv;
using namespace std;

int main(int argc, char * argv[])
{
    if (argc!=2)
    {
        cout<<"usage: DisplayImage.out "<<*argv[1]<<endl;
        return -1;
    }
    
    Mat image;
    image = imread(argv[1], 1) // second argument 1 for loading the image in BGR format
    
    if (!image.data)
    {
        printf("No Image data found\n");
        return -1;
    }

    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Display window", image);

    waitkey(0);
    return 0;

}
