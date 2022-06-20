#ifndef TASK_R_W_H
#define TASK_R_W_H

#include<QObject>
#include<QFile>


class Task_R_W : public QObject
{
    Q_OBJECT

public:
    Task_R_W(QObject* parent=nullptr);
    ~Task_R_W();

    void readOfFile();
    void writeToFile(const QString,const QString,const QString);
};

#endif // TASK_R_W_H
