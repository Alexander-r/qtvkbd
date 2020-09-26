#ifndef SLIDERDIALOG_H
#define SLIDERDIALOG_H

#include <QDialog>
#include <QSlider>
#include <QDialogButtonBox>

class SliderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SliderDialog(const QString &title, const QString &label, int value = 0,
                          int minValue = -2147483647, int maxValue = 2147483647,
                          int step = 1, bool *ok = nullptr, QWidget *parent = nullptr);

private:
    QSlider *slider;
    QDialogButtonBox *buttonBox;
    bool *ok_res;

private slots:
    void acceptSD();
};

#endif // SLIDERDIALOG_H
