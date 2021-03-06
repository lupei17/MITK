/*===================================================================

BlueBerry Platform

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/


#ifndef BERRYQTCONTROLWIDGET_H_
#define BERRYQTCONTROLWIDGET_H_

#include <QFrame>

#include "berryQtWidgetController.h"

#include <org_blueberry_ui_qt_Export.h>

namespace berry {

class BERRY_UI_QT QtControlWidget : public QFrame
{

public:

  QtControlWidget(QWidget* parent, Shell* shell, Qt::WindowFlags f = nullptr);

  ~QtControlWidget();

  void FireActivateEvent();

protected:

  // used for shell listeners
  void changeEvent(QEvent* event) override;
  void closeEvent(QCloseEvent* closeEvent) override;

  // used for control listeners
  void moveEvent(QMoveEvent* event) override;
  void resizeEvent(QResizeEvent* event) override;


private:

  QtWidgetController::Pointer controller;
};

}

#endif /* BERRYQTCONTROLWIDGET_H_ */
