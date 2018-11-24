#ifndef STREAMERWIND_H
#define STREAMERWIND_H

#include <QDialog>

namespace Ui {
class streamerwind;
}

class streamerwind : public QDialog
{
    Q_OBJECT

public:
    explicit streamerwind(QWidget *parent = nullptr);
    ~streamerwind();

private:
    Ui::streamerwind *ui;
};

#endif // STREAMERWIND_H
