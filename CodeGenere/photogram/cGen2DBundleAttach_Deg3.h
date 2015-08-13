// File Automatically generated by eLiSe
#include "StdAfx.h"


class cGen2DBundleAttach_Deg3: public cElCompiledFonc
{
   public :

      cGen2DBundleAttach_Deg3();
      void ComputeVal();
      void ComputeValDeriv();
      void ComputeValDerivHessian();
      double * AdrVarLocFromString(const std::string &);
      void SetAmpl(double);
      void SetCentr_x(double);
      void SetCentr_y(double);
      void SetFixedV_x(double);
      void SetFixedV_y(double);
      void SetPFixV_x(double);
      void SetPFixV_y(double);


      static cAutoAddEntry  mTheAuto;
      static cElCompiledFonc *  Alloc();
   private :

      double mLocAmpl;
      double mLocCentr_x;
      double mLocCentr_y;
      double mLocFixedV_x;
      double mLocFixedV_y;
      double mLocPFixV_x;
      double mLocPFixV_y;
};
