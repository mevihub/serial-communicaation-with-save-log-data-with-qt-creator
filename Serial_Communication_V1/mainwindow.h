#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Connect_clicked();

    void on_Disconnect_clicked();

    void on_Clear_clicked();
    void Receive_Data();
    void BaurdateUpdate(int idx);
    void on_SaveButton_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QTimer *timer;
    QString logData; // Declare logData variable
};
#endif // MAINWINDOW_H
