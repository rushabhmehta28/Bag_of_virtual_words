#include<iostream>
#include <array>
#include <string>
#include <tuple>
#include <vector>
#include <filesystem>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgproc.hpp>

#include"html_writer.hpp"
#include "image_browser.hpp"
using namespace cv;
using namespace std;
namespace fs = std::filesystem;

int main(int argc, char** argv) {

   // Importing the image
	if (argc != 3) {
		printf("usage: DisplayImage.out <Image_Path>\n");
		return -1;
	}
	Mat image;
	image = imread(argv[1], 1);
	if (!image.data) {
		printf("No image data \n");
		return -1;
	}
   
   const std::string dataset_location = argv[2]; // "/home/rushabh/working_dir/uni_bonn_cpp_tutorial/fifth_lecture/homework_3/web_app/data/";

	//Sharping the image. (Image preprossesing)
	Mat blurred; double sigma = 1, threshold = 5, amount = 1;
	GaussianBlur(image, blurred, Size(), sigma, sigma);
	Mat lowContrastMask = abs(image - blurred) < threshold;
	Mat sharpened = image*(1+amount) + blurred*(-amount);
	image.copyTo(sharpened, lowContrastMask);

   // Feature extraction of the input image.
   Ptr<SiftFeatureDetector> detector = SiftFeatureDetector::create();
   vector<KeyPoint> keypoints;
   detector->detect(image, keypoints);

   

   std::vector<std::string> path_vector;
   for (const auto & entry : fs::directory_iterator(dataset_location))
      {
         path_vector.push_back(entry.path());
      }



   // Output step
   //const std::string title = "Correlation Window";
   //using ScoredImage = std::tuple<std::string, float>;
   //using ImageRow = std::array<ScoredImage, 3>;
   //std::vector<ImageRow> imagevectors = {{std::make_tuple(dataset_location+"000000.png", 0.98f), std::make_tuple(dataset_location+"000100.png", 0.88f), std::make_tuple(dataset_location+"000200.png", 0.78f)},
   //                                     {std::make_tuple(dataset_location+"000300.png", 0.68f), std::make_tuple(dataset_location+"000400.png", 0.58f), std::make_tuple(dataset_location+"000500.png", 0.38f)}};
   //const std::string css_style_location = "/home/rushabh/working_dir/uni_bonn_cpp_tutorial/fifth_lecture/homework_3/web_app/style.css";
   //image_browser::CreateImageBrowser( title, css_style_location, imagevectors);
   return 0;
}   