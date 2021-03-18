#include <QtCore>

class MyTimer : public QObject
{
	Q_OBJECT

public:
	MyTimer(int refresh);
	QTimer* timer;

public slots:
	void MySlot();
};