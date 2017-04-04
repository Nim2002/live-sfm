#include "detectors.h"

using namespace cv;

/*
The class SphereDetector is the visual front end that provides the pixel locations
of spheres in the given frame. This can be replaced by any other class so long
as it generates information for the structureFromMotion object in a compatible
format.
*/

// perhaps this class is passed to the sfm object upon initialization
// I would need to look into the best way to do this, perhaps inheritance

SphereDetector::SphereDetector(int in_var)
{
  my_pri_val = in_var;
  my_pub_val = in_var;
  setValy(in_var);
}

int SphereDetector::getVal()
{
  return my_pri_val;
}

void SphereDetector::newFrame(Mat frame_in)
{
  // a new frame is passed in and circles need to be detected
  cvtColor(frame_in, frame, CV_BGR2GRAY);

  // blur (not sure if needed)
  //GaussianBlur(frame, frame, Size(9,9), 2,2);

  // perform HoughCircles on the grayscale image
  std::vector<Vec3f> circles;
  double dp = 1;
  double minDist = 1;
  double param1 = 150;
  double param2 = 100;
  int minRadius = 0;
  int maxRadius = 0;
  HoughCircles(frame, circles, CV_HOUGH_GRADIENT, dp, minDist, param1, param2, minRadius, maxRadius);



  drawCircles(frame_in, circles);
  //frame = frame_in;

  //frame = frame_in;

}

void SphereDetector::drawCircles(Mat img, std::vector<Vec3f>& circles)
{
  std::cout << "---" << std::endl;
  for (int i=0; i<circles.size(); i++)
  {
    std::cout << "worked" << std::endl;
    circle(img, Point2f(circles[i][0],circles[i][1]), circles[i][2],  Scalar(0, 255, 0), 2 );
  }
  //std::cout << "worked" << std::endl;
}
