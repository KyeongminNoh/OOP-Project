#ifndef POSTECHGRADUATE_H
#define POSTECHGRADUATE_H

#include <QtWidgets/QMainWindow>
#include "ui_postechgraduate.h"

class postechgraduate : public QMainWindow
{
	Q_OBJECT

public:
	postechgraduate(QWidget *parent = 0);
	~postechgraduate();

private:
	Ui::postechgraduateClass ui;
};

#endif // POSTECHGRADUATE_H
