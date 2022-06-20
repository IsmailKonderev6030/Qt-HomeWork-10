#ifndef TRW_H
#define TRW_H

#include <QObject>
#include <QFile>
#include <QString>
#include <QtWidgets/QMessageBox>

class TRW : public QObject
{
    Q_OBJECT

private:
    quint32 totalTasks;
    QString strTasks;
public:
    TRW();

    void readOfFile();

    void errorEnter();

signals:
    void signalPrintTotalTasks(QString text);

public slots:
    void addToTasks(QString,QString,QString);
    void writeTasksToFile();
    void slotPrintTotalTasks();

};

#endif // TRW_H
