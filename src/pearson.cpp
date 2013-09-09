/*
 * pearson.cc
 *
 * compute pearson's r (correlation coefficient) for a sample of
 * data points generated by the FDC landscape analysis tool
 *
 * Deon Garrett
 * deong@acm.org
 */

#include <iostream>
#include <fstream>
#include <utility>
#include "utilities.h"

using namespace std;

int main(int argc, char** argv)
{
	if(argc != 2) {
		cerr << "usage: pearson <datafile>" << endl;
		exit(1);
	}

	vector<pair<double,double> > points;

	ifstream in(argv[1]);
	while(!in.eof()) {
		double x, y, z;
		in >> x >> y >> z;
		points.push_back(make_pair<double,double>(x, z));
	}

	cout << compute_pearson_correlation(points) << endl;
	return 0;
}
