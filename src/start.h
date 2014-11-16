#ifndef START_H
#define START_H

#include <QtWidgets/QMainWindow>
#include "ui_start.h"

class start : public QMainWindow
{
	Q_OBJECT

public:
	start(QWidget *parent = 0);
	~start();
public slots:
	void newstart();
private:
	Ui::startClass ui;

};

#endif // START_H
