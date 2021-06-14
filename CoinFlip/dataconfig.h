#ifndef DATACONFIG_H
#define DATACONFIG_H
#include<QMap>
#include<QVector>
#include<string>

class DataConfig
{
public:
    DataConfig();
    const std::string dataAdress = ":/config.data";
    QMap<int,QVector<QVector<int>>> *map = new QMap<int,QVector<QVector<int>>>();
};

#endif // DATACONFIG_H
