/*
   For more information, please see: http://software.sci.utah.edu

   The MIT License

   Copyright (c) 2009 Scientific Computing and Imaging Institute,
   University of Utah.

   
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

#ifndef MODULES_LEGACY_FIELDS_CREATELATVOL_H__
#define MODULES_LEGACY_FIELDS_CREATELATVOL_H__

/*
 *  CreateLatVol.cc:  Make an ImageField that fits the source field.
 *
 *  Written by:
 *   Michael Callahan
 *   Department of Computer Science
 *   University of Utah
 *   March 2001
 *
 */

#include <Dataflow/Network/Module.h>
#include <Modules/Legacy/Fields/share.h>

namespace SCIRun {
  namespace Modules {
    namespace Fields {

      class SCISHARE CreateLatVol : public Dataflow::Networks::Module,
        public Has2InputPorts<FieldPortTag, MatrixPortTag>,
        public Has1OutputPort<FieldPortTag>
      {
      public:
        CreateLatVol();

        virtual void execute();
        virtual void setStateDefaults();

        INPUT_PORT(0, InputField, LegacyField);
        INPUT_PORT(1, LatVolSize, DenseMatrix);
        OUTPUT_PORT(0, OutputField, LegacyField);

        static Core::Algorithms::AlgorithmParameterName XSize;
        static Core::Algorithms::AlgorithmParameterName YSize;
        static Core::Algorithms::AlgorithmParameterName ZSize;
        static Core::Algorithms::AlgorithmParameterName PadPercent;
        static Core::Algorithms::AlgorithmParameterName DataAtLocation;
        static Core::Algorithms::AlgorithmParameterName ElementSizeNormalized;

      private:
        enum DataTypeEnum { SCALAR, VECTOR, TENSOR };
      };

    }
  }
}

#endif