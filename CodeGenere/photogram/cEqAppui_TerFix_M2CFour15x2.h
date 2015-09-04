// File Automatically generated by eLiSe
#include "StdAfx.h"


class cEqAppui_TerFix_M2CFour15x2: public cElCompiledFonc
{
   public :

      cEqAppui_TerFix_M2CFour15x2();
      void ComputeVal();
      void ComputeValDeriv();
      void ComputeValDerivHessian();
      double * AdrVarLocFromString(const std::string &);
      void SetFour15x2_State_0_0(double);
      void SetFour15x2_State_1_0(double);
      void SetFour15x2_State_2_0(double);
      void SetScNorm(double);
      void SetXIm(double);
      void SetXTer(double);
      void SetYIm(double);
      void SetYTer(double);
      void SetZTer(double);


      static cAutoAddEntry  mTheAuto;
      static cElCompiledFonc *  Alloc();
   private :

      double mLocFour15x2_State_0_0;
      double mLocFour15x2_State_1_0;
      double mLocFour15x2_State_2_0;
      double mLocScNorm;
      double mLocXIm;
      double mLocXTer;
      double mLocYIm;
      double mLocYTer;
      double mLocZTer;
};
