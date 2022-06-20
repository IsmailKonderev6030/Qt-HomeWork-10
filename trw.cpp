#include "trw.h"

TRW::TRW()
{

}

void TRW::errorEnter(){
    QMessageBox messageError;
    messageError.setWindowTitle("Error");
    messageError.setText(tr("Enter error"));
    messageError.exec();
}

void TRW::readOfFile(){
    QFile file("Tasks.txt");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){

        QString strWithCount = file.readLine();

        if(strWithCount.isEmpty()) totalTasks = 0;
        else totalTasks = strWithCount.toInt();

        strTasks = file.readAll();
    }
}

void TRW::addToTasks(QString name,QString date,QString progres){

    // Empty check
    if(name.isEmpty() || (date.isEmpty() || date.size()<10) || progres.isEmpty()) {this->errorEnter(); return;}

    strTasks += "Name:\t\t" + name + "\nDate:\t\t" + date + "\nProgres:\t" + progres + "\n\n";
    totalTasks++;
    this->slotPrintTotalTasks();
}

void TRW::writeTasksToFile(){
    QFile file("Tasks.txt");

    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        file.write(QString::number(totalTasks).toUtf8()+"\n");
        file.write(strTasks.toUtf8());
    }
}


void TRW::slotPrintTotalTasks(){
    emit signalPrintTotalTasks(tr("  Total Tasks:= ")+QString::number(totalTasks));
}
