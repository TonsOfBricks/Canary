#ifndef CANARYGUI_H
#define CANARYGUI_H

#include <string>
#include <QMainWindow>
#include <QSqlDatabase>
#include "streamerwind.h"

using namespace std;

extern "C++" QString name_return;
extern "C++" QString status_return;

namespace Ui {
class CanaryGui;
}

class CanaryGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit CanaryGui(QWidget *parent = nullptr);
    ~CanaryGui();

private slots:
    void on_pushButton_clicked();

    void on_actionDisabled_in_Beta_triggered();

    void on_helpmenu_triggered();

    void on_pass_returnPressed();

    void on_username_returnPressed();

private:
    Ui::CanaryGui *ui;
    QSqlDatabase db;
};

#endif // CANARYGUI_H
