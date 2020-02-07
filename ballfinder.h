#pragma once
#ifndef _BALLFINDER_H_INCLUDED
#define _BALLFINDER_H_INCLUDED


#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <chrono>
#include <math.h>

namespace bf
{
    struct CFoundBalls
    {
        CFoundBalls():
            angle(0.f), distance(0.f){}

        double angle;
        double distance;
    };

    typedef std::vector<CFoundBalls> ballList_t;

    class CBallFinder
    {
        public:
            CBallFinder();
            void work(cv::Mat & f_imgIn, ballList_t & f_listOfBalls);

        private:
            std::vector< std::vector<cv::Point> > grab_contours(std::vector< std::vector<cv::Point> > f_cnts);
            cv::Mat m_hsvImage;
            cv::Mat m_maskImage;
            cv::Mat m_blurredImage;    


    };

}

#endif