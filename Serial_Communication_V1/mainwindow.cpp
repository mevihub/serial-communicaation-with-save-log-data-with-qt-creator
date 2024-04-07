#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QTimer>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Update the list of available serial ports when the application starts
    // Clear existing port list
    ui->ComPort->clear();


    // Get list of available serial ports
    QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();

    // Populate the ComboBox with port names
    for(const QSerialPortInfo &portInfo : availablePorts) {
        ui->ComPort->addItem(portInfo.portName());

    }
    // Connect the activated signal of the BaudRate ComboBox to checkCustomBaudRatePolicy slot
    connect(ui->BaurdRate, SIGNAL(currentIndexChanged(int)), this, SLOT(BaurdateUpdate(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Connect_clicked()
{
    serial = new QSerialPort(this);                                             //making object of class QSerialPort
    timer = new QTimer(this);
    serial->setPortName(ui->ComPort->currentText());
    serial->setBaudRate(ui->BaurdRate->currentText().toInt()); // Set baud rate based on current /*selection*/

    serial->setBaudRate(ui->BaurdRate->currentText().toInt());
    //    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);                                       //connecting the serial port

    if(serial->isOpen()){

        qDebug()<< "Serial Port is Connected.";
        ui->Connection->setText("Serial Port is Connected.");
    }
    else{
        ui->Connection->setText("Serial Port is not Connected.");
        qDebug()<< "Serial Port is not Connected.";
        qDebug()<< serial->error();
    }
    connect(timer,&QTimer::timeout,this,&MainWindow::Receive_Data);
    timer->start(1000);
}

void MainWindow::on_Disconnect_clicked()
{
    if(serial->isOpen())
    {
        serial->close();
        timer->stop(); // Stop timer when disconnected
        ui->Connection->setText("Disconnected");
    }
}




void MainWindow::on_Clear_clicked()
{
     ui->Received_RawData->clear();
}


void MainWindow::Receive_Data()
{
    if (serial->isOpen()) {
        QByteArray data = serial->readAll();
        QString receivedData = QString::fromLatin1(data);
        QString timestamp = QDateTime::currentDateTime().toString("[HH:mm:ss.zzz] "); // Change timestamp format as desired
        ui->Received_RawData->append(receivedData);
        logData.append(timestamp + receivedData); // Append to log data
    }
}




void MainWindow::BaurdateUpdate(int idx)
{
    const bool isCustomBaudRate = !ui->BaurdRate->itemData(idx).isValid();
    ui->BaurdRate->setEditable(isCustomBaudRate);
    if(isCustomBaudRate){
        ui->BaurdRate->clearEditText();
        QLineEdit *edit = ui->BaurdRate->lineEdit();
        QIntValidator *validator = new QIntValidator(0,400000, this);
        edit->setValidator(validator);
    }
}

void MainWindow::on_SaveButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt)"));
    if (filePath.isEmpty()) {
        return; // User canceled the dialog
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file for writing"));
        return;
    }

    // Write log data with timestamps to the file
    QTextStream out(&file);
    out << logData;

    file.close();

    QMessageBox::information(this, tr("Success"), tr("File saved successfully"));
}
