#include "dataconfig.h"
#include<QFile>
#include<QDebug>
#include<QTextStream>

DataConfig::DataConfig()
{
    QFile file(":/config.data");
    file.open(QFileDevice::ReadOnly);
    QTextStream stream(&file);
    int c=0;
    int key = 0;
    while(!stream.atEnd()){
        QVector<QVector<int>> * level_data = new QVector<QVector<int>>(4,QVector<int>(4,0));
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                stream>>c;
                level_data[0][i][j] = c;
            }
        }
        key++;
        this->map->insert(key,*level_data);
    }

}
