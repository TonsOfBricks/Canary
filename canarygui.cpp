#include "canarygui.h"
#include "ui_canarygui.h"
#include "mysql_connection.h"
#include "mysql_driver.h"
#include "streamerwind.h"

#include <streamerwind.h>
#include <iostream>
#include <QString>
#include <QSqlRecord>
#include <mysql_connection.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QSqlError>

using namespace std;
using namespace sql;

QString name_return;
QString status_return;

CanaryGui::CanaryGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CanaryGui)
{
    ui->setupUi(this);
    this->setWindowTitle("Canary");
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("CanaryDB");
    db.setUserName("root");
    db.setPassword("Jaguar1");
    bool connected = db.open();
    if (connected==false)
        ui -> statuslabel -> setText("Failed to connect to Database");
    else
        ui -> statuslabel -> setText("Connected to Databse");

}

CanaryGui::~CanaryGui()
{
    delete ui;
}

void CanaryGui::on_pushButton_clicked(){
    QString user, password;
    user = ui->username->text();
    password = ui->pass->text();

    QSqlQuery qry;
    qry.prepare("SELECT status, name from UserInfo WHERE username = :username AND password = :password");
    qry.bindValue(":username", user);
    qry.bindValue(":password", password);
    qry.exec();
    qDebug()<<qry.lastError().text();

    while (qry.next()){
        int index = qry.record().indexOf("name");
        int index2 = qry.record().indexOf("status");
        QString name = qry.record().value(index).toString();
        QString status = qry.record().value(index2).toString();
        qDebug()<<name;
        qDebug()<<status;
        ::name_return = name;
        ::status_return = status;
    }

    if(qry.size() > 0){
        ui -> statuslabel -> setText("Sign in successful");
        this ->hide();
        streamerwind newwindow;
        newwindow.setModal(true);
        newwindow.exec();
    }
    else{
        ui -> statuslabel -> setText("Sign in unsuccessful");
    }
}

void CanaryGui::on_helpmenu_triggered()
{
    QString github = "https://github.com/TonsOfBricks";
    QDesktopServices::openUrl(QUrl(github));
}

void CanaryGui::on_actionDisabled_in_Beta_triggered()
{
    cout<<"Action is disabled"<<endl;
}

void CanaryGui::on_pass_returnPressed()
{
    QString user, password;
    user = ui->username->text();
    password = ui->pass->text();

    QSqlQuery qry;
    qry.prepare("SELECT status, name from UserInfo WHERE username = :username AND password = :password");
    qry.bindValue(":username", user);
    qry.bindValue(":password", password);
    qry.exec();
    qDebug()<<qry.lastError().text();

    while (qry.next()){
        int index = qry.record().indexOf("name");
        int index2 = qry.record().indexOf("status");
        QString name = qry.record().value(index).toString();
        QString status = qry.record().value(index2).toString();
        qDebug()<<name;
        qDebug()<<status;
        ::name_return = name;
        ::status_return = status;
    }

    if(qry.size() > 0){
        ui -> statuslabel -> setText("Sign in successful");
        this ->hide();
        streamerwind newwindow;
        newwindow.setModal(true);
        newwindow.exec();
    }
    else{
        ui -> statuslabel -> setText("Sign in unsuccessful");
    }
}

void CanaryGui::on_username_returnPressed()
{
    QString user, password;
    user = ui->username->text();
    password = ui->pass->text();

    QSqlQuery qry;
    qry.prepare("SELECT status, name from UserInfo WHERE username = :username AND password = :password");
    qry.bindValue(":username", user);
    qry.bindValue(":password", password);
    qry.exec();
    qDebug()<<qry.lastError().text();

    while (qry.next()){
        int index = qry.record().indexOf("name");
        int index2 = qry.record().indexOf("status");
        QString name = qry.record().value(index).toString();
        QString status = qry.record().value(index2).toString();
        qDebug()<<name;
        qDebug()<<status;
        ::name_return = name;
        ::status_return = status;
    }

    if(qry.size() > 0){
        ui -> statuslabel -> setText("Sign in successful");
        this ->hide();
        streamerwind newwindow;
        newwindow.setModal(true);
        newwindow.exec();
    }
    else{
        ui -> statuslabel -> setText("Sign in unsuccessful");
    }
}
