#include "kmeans.h"

#include "Node.h"
#include <math.h>






Kmeans::Kmeans()
{

}


/*
  随机产生数据
*/

void Kmeans::randomGenerateNode()
{

    int i=0;
    //清空数据集
    dataSet.clear();
    //vector<T>(dataSet).swap(dataSet);  //防止内存泄露用法
    for(i=0;i<dataNum;i++)
    {
        double randmX=rand()%(xmax-xmin+1)+xmin;
        double randmY=rand()%(ymax-ymin+1)+ymin;
        NODE_INFO temp(randmX,randmY);
        dataSet.push_back(temp);
    }

}




void Kmeans::randomCentroids()
{

    int i =0;
    int randomI;
    centroids.clear();
    for(i=0;i<dataClust;i++)
    {
       randomI =  (int)rand()%dataClust;
       centroids.push_back( dataSet.at(i) );
       centroids[i].type = i+1;
       centroids[i].classification = 1;
    }

}


double Kmeans::getDistance(NODE_INFO& node1,NODE_INFO& node2)
{
    double distance;
    distance = pow((node1.x - node2.x),2) + pow((node1.y - node2.y),2);
    return sqrt(distance);
}


void Kmeans::runKmeans()
{
    int i = 100;

    while(i--)
    {
        int k = 0;
        int j = 0;

        int temp_type = 0;
        double min_distance,temp_distance;

        //初始化容器
        vector < vector<NODE_INFO> > tempdata;
        vector<NODE_INFO> tempdatatype;

        for(j=0;j<dataClust;j++)
        {
            tempdata.push_back(tempdatatype);
        }

//        cout<<tempdata.size()<<endl;

        // 计算每个样本与聚合中心的距离
        for(k=0;k<dataNum;k++)
        {
            min_distance = getDistance(dataSet[k],centroids[0]);
            temp_type = 0;
            dataSet[k].type = 1;
            for(j=1;j<dataClust;j++)
            {
                temp_distance = getDistance(dataSet[k],centroids[j]);
//                cout <<"temp_distance:" <<temp_distance<<endl;
                if(temp_distance < min_distance)
                {
                    min_distance = temp_distance;
                    temp_type = j;
                    dataSet[k].type = j+1;
                }
            }
//            cout <<"min_distance:" <<min_distance<<endl;
            tempdata[temp_type].push_back(dataSet[k]);
        }

//        cout <<"tempdata[0]:" <<tempdata[0].size()<<endl;



        //求新的聚合中心
        int equalnum = 0;

        for(j=0;j<dataClust;j++)
        {
            NODE_INFO sum(0,0,j+1);
            for(k=0;k<(int)(tempdata[j].size());k++)
            {
                sum = sum + tempdata[j][k];
            }
//            cout<<"sum 1:"<<sum;
            sum = sum/(tempdata[j].size());
            sum.type = j+1;
//            cout<<"sum 2:"<<sum<<endl;
            //判断新的聚合中心与原聚合中心
            if(centroids[j] == sum)
            {
                equalnum++;
            }
            else
            {
                centroids[j] = sum;
                centroids[j].classification = 1;
            }

        }
        //若全部聚合中心相等则算法结束
        if(equalnum == dataClust)
        {
            cout<<"equal end!";
            break;
        }

        //
        tempdata.clear();
        tempdatatype.clear();

    }

}



void Kmeans::showDataSet()
{
    unsigned int i=0;
    for(i=0;i<dataSet.size();i++)
    {
        cout<<dataSet[i];
    }
    cout<<endl;
}


void Kmeans::showCentroids()
{
    unsigned int i=0;
    for(i=0;i<centroids.size();i++)
    {
        cout<<centroids[i];
    }
    cout<<endl;
}

void Kmeans::clearData()
{
    dataSet.clear();
    centroids.clear();
}



