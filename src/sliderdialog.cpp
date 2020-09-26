#include "sliderdialog.h"
#include <QLabel>
#include <QVBoxLayout>

SliderDialog::SliderDialog(const QString &title, const QString &label, int value,
                           int minValue, int maxValue, int step, bool *ok, QWidget *parent)
    : QDialog(parent)
{
    ok_res = ok;
    QLabel *dialogLabel = new QLabel(label, this);
    slider = new QSlider(Qt::Horizontal, this);
    slider->setMinimumWidth(340);
    slider->setRange(minValue, maxValue);
    //slider->setTickInterval(step);
    slider->setSingleStep(step);
    slider->setValue(value);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &SliderDialog::acceptSD);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(dialogLabel);
    mainLayout->addWidget(slider);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(title);
}

void SliderDialog::acceptSD()
{
    if (ok_res != nullptr)
    {
        *ok_res = true;
    }
    this->done(slider->value());
}
