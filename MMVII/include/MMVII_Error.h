#ifndef  _MMVII_MMError_H_
#define  _MMVII_MMError_H_

namespace MMVII
{


/** \file MMVII_Error.h
    \brief Error handling, basic for now

   Probably, sooner or later, I will have to change completely the error
  handling. However, waiting for that, we need to do something, and keep
  track in the file of the location of error detection.

*/


// Ce ne sont pas de petite erreurs, mais des erruer couteuse a checker
#define  The_MMVII_DebugLevel_InternalError_tiny     5  
#define  The_MMVII_DebugLevel_InternalError_medium   4
// Ce ne sont pas de petite erreurs, mais des erruer couteuse a checker
#define  The_MMVII_DebugLevel_InternalError_strong   3
#define  The_MMVII_DebugLevel_UserError              2
#define  The_MMVII_DebugLevel_BenchError             1
#define  The_MMVII_DebugLevel_NoError                0


// e xtern int  The_MMVII_DebugLevel = The_MMVII_DebugLevel_InternalError_medium;
#define The_MMVII_DebugLevel The_MMVII_DebugLevel_InternalError_tiny


void MMVVI_Error(const std::string & aType,const std::string &  aMes,const char * aFile,int aLine);

#define MMVII_INTERNAL_ASSERT_tiny(aTest,aMes)\
 if ((The_MMVII_DebugLevel>=The_MMVII_DebugLevel_InternalError_tiny ) && (!(aTest)))\
{ MMVVI_Error("Internal Error",aMes,__FILE__,__LINE__);}

#define MMVII_INTERNAL_ASSERT_medium(aTest,aMes)\
 if ((The_MMVII_DebugLevel>=The_MMVII_DebugLevel_InternalError_medium ) && (!(aTest)))\
{ MMVVI_Error("Internal Error",aMes,__FILE__,__LINE__);}

#define MMVII_INTERNAL_ASSERT_strong(aTest,aMes)\
 if ((The_MMVII_DebugLevel>=The_MMVII_DebugLevel_InternalError_strong ) && (!(aTest)))\
{ MMVVI_Error("Internal Error",aMes,__FILE__,__LINE__);}


#define MMVII_INTERNAL_ASSERT_bench(aTest,aMes)\
 if ((The_MMVII_DebugLevel>=The_MMVII_DebugLevel_BenchError ) && (!(aTest)))\
{ MMVVI_Error("Internal Error",aMes,__FILE__,__LINE__);}

#define MMVII_INTERNAL_ASSERT_user(aTest,aMes)\
 if ((The_MMVII_DebugLevel>=The_MMVII_DebugLevel_UserError ) && (!(aTest)))\
{ MMVVI_Error("User's Error",aMes,__FILE__,__LINE__);}


#define MMVII_INTERNAL_ASSERT_always(aTest,aMes)\
 if  (!(aTest))\
{ MMVVI_Error("Internal Error",aMes,__FILE__,__LINE__);}


template<class T> void IgnoreUnused( const T& ) { };

};

#endif  //  _MMVII_MMError_H_
