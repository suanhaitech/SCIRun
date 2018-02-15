/*
   For more information, please see: http://software.sci.utah.edu

   The MIT License

   Copyright (c) 2015 Scientific Computing and Imaging Institute,
   University of Utah.

   License for the specific language governing rights and limitations under
   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
   */

#ifndef INTERFACE_MODULES_MATH_BASICPLOTTER_H
#define INTERFACE_MODULES_MATH_BASICPLOTTER_H

#include "Interface/Modules/Math/ui_BasicPlotter.h"
#include <Interface/Modules/Base/ModuleDialogGeneric.h>
#include <qwt_plot.h>
#include <Interface/Modules/Math/share.h>

class QwtPlotMarker;
class QwtPlotCurve;

namespace SCIRun
{
  namespace Gui
  {
    class SCISHARE BasicPlotterDialog : public ModuleDialogGeneric,
      public Ui::BasicPlotter
    {
      Q_OBJECT

    public:
      BasicPlotterDialog(const std::string& name,
        SCIRun::Dataflow::Networks::ModuleStateHandle state,
        QWidget* parent = nullptr);
      ~BasicPlotterDialog();
    protected:
      virtual void pullSpecial() override;
    private Q_SLOTS:
      void showPlot();
      void updatePlot();
      void exportPlot();
      void assignDataColor();
    private:
      QDialog* plotDialog_ {nullptr};
      class Plot* plot_{nullptr};
      std::vector<QColor> dataColors_;
    };

    class Plot : public QwtPlot
    {
      Q_OBJECT
    public:
      explicit Plot( QWidget *parent = nullptr );
      void makeVerticalAxis(bool show, double position);
      void makeHorizontalAxis(bool show, double position);
      void addCurve(Core::Datatypes::DenseMatrixHandle data, const QString& title, const QColor& color);
      template <typename Column>
      void addCurve(const Column& x, const Column& y, const QString& title, const QColor& color);
      void clearCurves();
    private Q_SLOTS:
      void showItem(const QVariant&, bool on);
    private:
      QwtPlotMarker* verticalAxis_ {nullptr};
      QwtPlotMarker* horizontalAxis_ {nullptr};
      std::vector<QwtPlotCurve*> curves_;
    };
  }
}
#endif
