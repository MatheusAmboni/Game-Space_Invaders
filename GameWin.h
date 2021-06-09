#ifndef GAMEWIN_H
#define GAMEWIN_H

#include <QDialog>

namespace Ui {
class GameWin;
}

class GameWin : public QDialog
{
    Q_OBJECT

public:
    explicit GameWin(QWidget *parent = nullptr);
    ~GameWin();

private:
    Ui::GameWin *ui;
};



#endif // GAMEWIN_H
