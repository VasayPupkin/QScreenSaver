#ifndef QBASEDTIMER_H
#define QBASEDTIMER_H

#include <QObject>
#include <QTimer>

class QBasedTimer : public QObject
{
    Q_OBJECT
public:
    explicit QBasedTimer(QObject *parent = nullptr);

signals:

public slots:

private:
    QTimer _timer;
};

#endif // QBASEDTIMER_H
