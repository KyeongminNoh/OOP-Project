/*

#include <QPaintEvent>
#include <QWidget>


class TriStateButton : public QWidget
{
    Q_OBJECT
public:
    TriStateButton(QWidget *parent = 0, const char *name = 0, WFlags f = Qt::WStyle_Customize | Qt::WStyle_NoBorder);

    enum ButtonState { NORMAL, PRESS, FOCUS };
    void setButtonImage();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *e);
    void focusInEvent(QFocusEvent *);
    void focusOutEvent(QFocusEvent *);
    void keyPressEvent(QKeyEvent *);

signals:
    void clicked();

private:
    int state;
    QString buttonName;
    QPixmap buttonBg[3];
};

*/