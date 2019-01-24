#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QDebug>

QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("COM3");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadOnly);
    connect(serial, SIGNAL(readyRead()),
            this, SLOT(serialReceived()));
}

MainWindow::~MainWindow()
{
    delete ui;
    serial->close();
}

void MainWindow::serialReceived()
{
    QByteArray data = serial->readAll();
    ui->label->setText(data);
    qDebug() << data;
}
