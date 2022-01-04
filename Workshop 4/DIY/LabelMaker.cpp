// Workshop 4: DIY
// Date: 2021/2/14
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include "cstring.h"
#include "LabelMaker.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace sdds 
{

    void LabelMaker::printLabels()
    {
        int x;
        for(x = 0; x < noOfLabels; x++)
        {
            labels[x].printLabel() << endl;
        }
    }


    void LabelMaker::readLabels()
    {
        cout << "Enter " << noOfLabels 
                << " labels:" << endl;
        int x;
        for(x = 0; x < noOfLabels; x++)
        {
            cout << "Enter label number " << x + 1 << endl;
            cout << "> ";
            labels[x].readLabel();
        }
    }


    LabelMaker::~LabelMaker()
    {
         delete[] labels;
	labels = nullptr;
    }


    LabelMaker::LabelMaker(int numLabels)
    {
        noOfLabels = numLabels;
        labels = new Label[numLabels];
    }
}