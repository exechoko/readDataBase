#ifndef ANT_H
#define ANT_H

#include <QObject>

class ant : public QObject
{
    Q_OBJECT
public:
    explicit ant(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ANT_H
