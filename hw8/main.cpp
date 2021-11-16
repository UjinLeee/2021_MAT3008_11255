#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void bilinear_interp(Mat& image1, Mat& image2, int rate) {

	for (int y = 0; y < image2.rows; y++) {
		for (int x = 0; x < image2.cols; x++) {

			int p1_x = (int)(x / rate);
			int p1_y = (int)(y / rate);

			double fx_1 = (double)x / (double)rate - (double)p1_x;
			double fx_2 = 1 - fx_1;
			double fy_1 = (double)y / (double)rate - (double)p1_y;

			double fy_2 = 1 - fy_1;

			Vec3b P1 = image1.at<Vec3b>(p1_y, p1_x);
			Vec3b P2 = image1.at<Vec3b>(p1_y, p1_x + 1);
			Vec3b P3 = image1.at<Vec3b>(p1_y + 1, p1_x);
			Vec3b P4 = image1.at<Vec3b>(p1_y + 1, p1_x + 1);

			image2.at<Vec3b>(y, x) = (fx_2 * fy_2) * P1 + (fx_1 * fy_2) * P2 + (fx_2 * fy_1) * P3 + (fx_1 * fy_1) * P4;
		}

	}

}


int main() {


	Mat image = imread("Young_cats.jpg", -1);

	if (image.empty()) {
		cout << "\nError: Cannot find image...\n" << endl;
	}

	namedWindow("First image", WINDOW_AUTOSIZE);
	imshow("First image", image);

	int height = image.rows;
	int width = image.cols;

	int color_state = (image.channels() == 1) ? CV_8UC1 : CV_8UC3;

	Mat result_image(height, width, color_state, Scalar(0));

	int rate = 4;

	bilinear_interp(image, result_image, rate);

	imshow("Result image", result_image);
	waitKey(0);
	destroyAllWindows();

	return 0;
}
