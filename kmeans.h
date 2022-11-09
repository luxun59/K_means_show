#ifndef KMEANS_H
#define KMEANS_H




#include <QObject>



#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <vector>


#include "Node.h"

using namespace std;


class Kmeans
{
//    Q_OBJECT
public:
    Kmeans();
public:
    int dataNum = 5;       //data number
    int dataClust = 2;     //the clust

    vector< NODE_INFO > dataSet; //the data set
    vector< double > mmin;

    int xmin=0,xmax=100;
    int ymin=0,ymax=100;

    vector< NODE_INFO > centroids;  //聚合中心



    void randomGenerateNode();
    void randomCentroids();

    double getDistance(NODE_INFO& node1,NODE_INFO& node2);

    void runKmeans();

    void showDataSet();
    void showCentroids();

    void clearData();

};

#endif // KMEANS_H
