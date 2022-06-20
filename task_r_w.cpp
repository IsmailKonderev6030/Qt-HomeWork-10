#include "task_r_w.h"

Task_R_W::Task_R_W(QObject* parent) : QObject(parent){}

Task_R_W::~Task_R_W(){}

void Task_R_W::readOfFile(){
    // зачем читать если мы ничего не выводим ?
}

void Task_R_W::writeToFile(const QString name,const QString date,const QString progres){
    QFile file("Tasks.txt");
    QDataStream writeFile(&file);

    if(file.open(QIODevice::Append)){
        writeFile<<name<<'\n'<<date<<'\n'<<progres<<"\nend";
    }
}
