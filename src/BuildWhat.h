#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>


class BuildWhat : public QWidget{

	Q_OBJECT

public:
	BuildWhat(QWidget *parent=0);
	QPushButton *gym;
	QPushButton *lib;
	QPushButton *logH;
	QPushButton *stu;
	QPushButton *lab;
	QPushButton *mar;

private:
	QVBoxLayout *Menu;
	
};