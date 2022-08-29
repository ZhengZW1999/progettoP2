#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QSize>
#include <QMessageBox>

class view: public QWidget
{
    Q_OBJECT
public:
    explicit view(const QSize& s = QSize(),view* parent = nullptr);

    virtual ~view() {
        setParent(nullptr);
    }

    void setWindowSize(const QSize& );

    virtual void setViewTitle(const QString& title);
};

#endif // VIEW_H
