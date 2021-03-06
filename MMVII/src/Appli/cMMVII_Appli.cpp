#include "include/MMVII_all.h"


namespace MMVII
{

/*  ============================================== */
/*                                                 */
/*                cColStrAObl                      */
/*                                                 */
/*  ============================================== */


const  cColStrAObl::tCont & cColStrAObl::V() const {return mV;}
cColStrAObl &  cColStrAObl::operator << (const std::string & aVal) {mV.push_back(aVal); return *this;}
void cColStrAObl::clear() {mV.clear();}
cColStrAObl::cColStrAObl() {}


/*  ============================================== */
/*                                                 */
/*                cColStrAOpt                      */
/*                                                 */
/*  ============================================== */


const  cColStrAOpt::tCont & cColStrAOpt::V() const {return mV;}
cColStrAOpt &  cColStrAOpt::operator << (const t2S & aVal) {mV.push_back(aVal); return *this;}
void cColStrAOpt::clear() {mV.clear();}
cColStrAOpt::cColStrAOpt() {}


/*  ============================================== */
/*                                                 */
/*                cMMVII_Appli                     */
/*                                                 */
/*  ============================================== */

// May be used again for testing value inside initialization
/*
template <class Type> Type PrintArg(const Type & aVal,const std::string & aName)
{
    std::cout << " For " << aName << " V=" << aVal << "\n";
    return aVal;
}
*/

// ========================= 3 Main function :
// 
//        cMMVII_Appli::~cMMVII_Appli()
//        cMMVII_Appli::cMMVII_Appli ( int argc, char ** argv, const cSpecMMVII_Appli & aSpec) 
//        void cMMVII_Appli::InitParam() => main initialisation must be done after Cstrctor as call virtual methods


cMMVII_Appli::~cMMVII_Appli()
{
   AssertInitParam();
   // ======= delete mSetInit;
   mArgObl.clear();
   mArgFac.clear();
   // Verifie que tout ce qui a ete alloue a ete desalloue 
   // cMemManager::CheckRestoration(mMemStateBegin);
   mMemStateBegin.SetCheckAtDestroy();
}

cMMVII_Appli::cMMVII_Appli
(
      int argc,
      char ** argv,
      const cSpecMMVII_Appli & aSpec
)  :
   mMemStateBegin (cMemManager::CurState()),
   mArgc          (argc),
   mArgv          (argv),
   mSpecs         (aSpec),
   mDirBinMMVII   (DirBin2007),
   mTopDirMMVII   (UpDir(mDirBinMMVII,1)),
   mFullBin       (mDirBinMMVII + Bin2007),
   // mFullBin       (AbsoluteName(mArgv[0])),
   // mFullBin       (PrintArg(AbsoluteName(mArgv[0]),"ABS")),
   mBinMMVII      (Bin2007),
   mDirMicMacv1   (UpDir(mTopDirMMVII,1)),
   mDirMicMacv2   (mTopDirMMVII),
   mDirProject    (DirCur()),
   mDirTestMMVII  (mDirMicMacv2 + MMVIITestDir),
   mTmpDirTestMMVII   (mDirTestMMVII + "Tmp/"),
   mInputDirTestMMVII (mDirTestMMVII + "Input/"),
   mModeHelp      (false),
   mDoGlobHelp    (false),
   mDoInternalHelp(false),
   mShowAll       (false),
   mLevelCall     (0),
   mDoInitProj    (false),
   mSetInit       (cExtSet<void *>(eTySC::US)),
   mInitParamDone (false),
   mVMainSets     (NbMaxMainSets,tNameSet(eTySC::NonInit)),
   mNumOutPut     (0),
   mOutPutV1      (false),
   mOutPutV2      (false),
   mHasInputV1    (false),
   mHasInputV2    (false)
{
}


void cMMVII_Appli::InitParam()
{
  cCollecSpecArg2007 & anArgObl = ArgObl(mArgObl);
  cCollecSpecArg2007 & anArgFac = ArgOpt(mArgFac);

  mInitParamDone = true;
  MMVII_INTERNAL_ASSERT_always(msTheAppli==0,"cMMVII_Appli only one by process");
  msTheAppli = this;

  // Check that  cCollecSpecArg2007 were used with the good values
  MMVII_INTERNAL_ASSERT_always((&anArgObl)==&mArgObl,"cMMVII_Appli dont respect cCollecSpecArg2007");
  MMVII_INTERNAL_ASSERT_always((&anArgFac)==&mArgFac,"cMMVII_Appli dont respect cCollecSpecArg2007");

  std::string aDP; // mDirProject is handled specially so dont put mDirProject in AOpt2007
                   // becauser  InitParam, it may change the correct value 

  // Add common optional parameters
  cSpecOneArg2007::tVSem aIntCom{eTA2007::Internal,eTA2007::Common}; // just to make shorter lines
  cSpecOneArg2007::tVSem aCom{eTA2007::Common}; // just to make shorter lines
  mArgFac
      <<  AOpt2007(mIntervFilterMS[0],"FFI0","File Filter Interval, Main Set",aCom)
      <<  AOpt2007(mIntervFilterMS[1],"FFI1","File Filter Interval, Second Set",aCom)
      <<  AOpt2007(mNumOutPut,"NumVOut","Num version for output format (1 or 2)",aCom)
      <<  AOpt2007(aDP ,NameDirProj,"Project Directory",{eTA2007::DirProject,eTA2007::Common})
      <<  AOpt2007(mLevelCall,"LevCall","Internal : Don't Use !!",aIntCom)
      <<  AOpt2007(mShowAll,"ShowAll","Internal : Don't Use !!",aIntCom)
  ;

  // Check that names of optionnal parameters begin with alphabetic caracters
  for (const auto & aSpec : mArgFac.Vec())
  {
      if (!std::isalpha(aSpec->Name()[0]))
      {
         MMVII_INTERNAL_ASSERT_always
         (
             false,
             "Name of optional param must begin with alphabetic => ["+aSpec->Name()+"]"
         );
      }
  }

  // Test if we are in help mode
  for (int aKArg=0 ; aKArg<mArgc ; aKArg++)
  {
      char * aArgK = mArgv[aKArg];
      if (UCaseBegin("help",aArgK) || UCaseBegin("-help",aArgK)|| UCaseBegin("--help",aArgK))
      {
         mModeHelp = true;
         while (*aArgK=='-') aArgK++;
         mDoGlobHelp = (*aArgK=='H');
         mDoInternalHelp = CaseSBegin("HE",aArgK);

         std::string aName; 
         SplitStringArround(aName,mPatHelp,aArgK,'=',true,false);
      }
  }
  if (mModeHelp)
  {
      GenerateHelp();
      return;
  }


  // std::cout << "MMV1 "  << mDirMicMacv1  << "\n";

  int aNbObl = mArgObl.size(); //  Number of mandatory argument expected
  int aNbArgGot = 0; // Number of  Arg received untill now
  bool Optional=false; // Are we in the optional phase of argument parsing

  // To be abble to process in  the same loop mandatory and optional
  std::vector<std::string> aVValues;
  tVecArg2007              aVSpec;

  for (int aKArg=0 ; aKArg<mArgc ; aKArg++)
  {
      Optional = (aNbArgGot>=aNbObl);
      // If --Name replace by Name, maybe usefull for completion
      if (Optional && (mArgv[aKArg][0]=='-') && (mArgv[aKArg][1]=='-'))
         mArgv[aKArg] += 2;
      char * aArgK = mArgv[aKArg];
      if (aKArg<2)
      {
          //  mArgv[0] => MMVII
          //  mArgv[1] => the name of commmand
      }
      else
      {
          if (Optional)
          {
             // while '
             std::string aName,aValue;
             SplitStringArround(aName,aValue,aArgK,'=',true,false);
             int aNbSpecGot=0;
             // Look for spec corresponding to name
             for (const auto  & aSpec : mArgFac.Vec())
             {
                 if (aSpec->Name() == aName)
                 {
                    aNbSpecGot++;
                    aVSpec.push_back(aSpec);
                    // Several space have the same name
                    if (aNbSpecGot==2)
                    {
                        MMVII_INTERNAL_ASSERT_always(false,"\""+ aName +"\" is multiple in specification");
                    }
                    // Same name was used several time
                    if (aSpec->NbMatch() !=0)
                    {
                        MMVII_INTERNAL_ASSERT_user(false,"\""+aName +"\" was used multiple time");
                    }
                    aSpec->IncrNbMatch();
                 }
             }
             // Name does not correspond to spec
             if (aNbSpecGot==0)
             {
                MMVII_INTERNAL_ASSERT_user(false,"\""+aName +"\" is not a valide optionnal value");
             }
             aVValues.push_back(aValue);
          }
          else
          {
             aVValues.push_back(aArgK);
             aVSpec.push_back(mArgObl[aNbArgGot]);
          }
          aNbArgGot ++;
      }
  }

  size_t aNbArgTot = aVValues.size();

  if (aNbArgGot < aNbObl)
  {
      // Tolerance, like in mmv1, no arg generate helps
      if (aNbArgGot==0)
      {
         mModeHelp = true;  // else Exe() will be executed !!
         GenerateHelp();
         return;
      }
      MMVII_INTERNAL_ASSERT_user
      (
          false,
          "Not enough Arg, expecting " + ToS(aNbObl)  + " , Got only " +  ToS(aNbArgGot)
      );
  }
  MMVII_INTERNAL_ASSERT_always(aNbArgTot==aVSpec.size(),"Interncl check size Value/Spec");


  // First compute the directory of project that may influence all other computation
  for (size_t aK=0 ; aK<aNbArgTot; aK++)
  {
     if (aVSpec[aK]->HasType(eTA2007::DirProject))
        mDirProject = aVValues[aK];
     else if (aVSpec[aK]->HasType(eTA2007::FileDirProj))
        mDirProject = DirOfPath(aVValues[aK],false);
  }
  MakeNameDir(mDirProject);

  //  Initialize the paramaters
  for (size_t aK=0 ; aK<aNbArgTot; aK++)
  {
       aVSpec[aK]->InitParam(aVValues[aK]);
       mSetInit.Add(aVSpec[aK]->AdrParam()); ///< Memorize this value was initialized
  }

  // If mNumOutPut was set, fix the output version
  if (IsInit(&mNumOutPut))
  {
     if (mNumOutPut==1)
        mOutPutV1 = true;
     else if (mNumOutPut==2)
        mOutPutV2 = true;
     else
     {
         MMVII_INTERNAL_ASSERT_always(false,"Output version must be in {1,2}, got: "+ToStr(mNumOutPut));
     }
  }


  // Analyse the possible main patterns
  for (size_t aK=0 ; aK<aNbArgTot; aK++)
  {
      std::string aNumPat;
      // Test the semantic
      if (aVSpec[aK]->HasType(eTA2007::MPatIm,&aNumPat))
      {
         int aNum =   cStrIO<int>::FromStr(aNumPat);
         // Check range
         CheckRangeMainSet(aNum);

         // don't accept multiple initialisation
         if (!mVMainSets.at(aNum).IsInit())
         {
            mVMainSets.at(aNum)= SetNameFromString(mDirProject+aVValues[aK],true);
         }
         else
         {
            MMVII_INTERNAL_ASSERT_always(false,"Multiple main set im for num:"+ToStr(aNum));
         }
         std::string & aNameInterval = mIntervFilterMS[aNum];
         if (IsInit(&aNameInterval))
         {
             mVMainSets.at(aNum).Filter(Str2Interv<std::string>(aNameInterval));
         }
      }
  }
  // Check validity of main set initialization
  for (int aNum=0 ; aNum<NbMaxMainSets ; aNum++)
  {
      // Why should user init interval if there no set ?
      if (IsInit(&mIntervFilterMS[aNum]) && (!  mVMainSets.at(aNum).IsInit()))
      {
         MMVII_INTERNAL_ASSERT_user(false,"Interval without filter for num:"+ToStr(aNum));
      }
      if (aNum>0)
      {
         // would be strange to have Mainset2 without MainSet1; probably if this occurs
         // the fault would be from programer's side (not sure)
         if ((! mVMainSets.at(aNum-1).IsInit() ) && ( mVMainSets.at(aNum).IsInit()))
         {
            MMVII_INTERNAL_ASSERT_always(false,"Main set, init for :"+ToStr(aNum) + " and non init for " + ToStr(aNum-1));
         }
      }
  }


  // MakeNameDir(mDirProject);
  
  // Print the info, debugging
  if (mShowAll)
  {
     // Print the value of all parameter
     for (size_t aK=0 ; aK<aNbArgTot; aK++)
     {
         std::cout << aVSpec[aK]->Name()  << " => [" << aVValues[aK] << "]" << std::endl;
     }
     std::cout << "---------------------------------------" << std::endl;
     std::cout << "IS INIT  DP: " << IsInit(&aDP) << std::endl;

     std::cout << "DIRPROJ=[" << mDirProject << "]" << std::endl;
  }

  // By default, if calls is done at top level, assure that everything is init
  if (!IsInit(&mDoInitProj))
     mDoInitProj = (mLevelCall==0);

  if (mDoInitProj)
  {
     InitProject();
  }

  // mLevelCall++; // So that is incremented if a new call is made

  for (int aK=0 ; aK<100 ; aK++)
  {
      // std::cout << "Lettre SFPT a diffuser \n";
  }

}

void cMMVII_Appli::InitProject()
{
   CreateDirectories(mDirProject+TmpMMVIIDir,true);
}


    // ========== Help ============

void cMMVII_Appli::GenerateHelp()
{
   std::cout << "\n";

   std::cout << "**********************************\n";
   std::cout << "*   Help project 2007/MMVII      *\n";
   std::cout << "**********************************\n";

   std::cout << "\n";
   std::cout << "  For command : " << mSpecs.Name() << " \n";
   std::cout << "   => " << mSpecs.Comment() << "\n";
   std::cout << "\n";

   std::cout << " == Mandatory unnamed args : ==\n";

   for (const auto & Arg : mArgObl.Vec())
   {
       std::cout << "  * " << Arg->NameType() << " :: " << Arg->Com() << "\n";
   }

   tNameSelector  aSelName =  BoostAllocRegex(mPatHelp);

   std::cout << "\n";
   std::cout << " == Optional named args : ==\n";
   for (const auto & Arg : mArgFac.Vec())
   {
       const std::string & aNameA = Arg->Name();
       if (aSelName.Match(aNameA))
       {
          bool IsIinternal = Arg->HasType(eTA2007::Internal);
          if ((! IsIinternal) || mDoInternalHelp)
          {
             bool isGlobHelp = Arg->HasType(eTA2007::Common);
             if ((!isGlobHelp) || mDoGlobHelp)
             {
                std::cout << "  * [Name=" <<  Arg->Name()   << "] " << Arg->NameType() << " :: " << Arg->Com();
                if (IsIinternal) 
                   std::cout << "   ### INTERNAL " ; 
                else if (isGlobHelp) 
                   std::cout << "   ### COMMON " ; 
                std::cout  << "\n";
             }
          }
       }
   }
   std::cout << "\n";
}

bool cMMVII_Appli::ModeHelp() const
{
   return mModeHelp;
}

    // ========== Handling of Mains Sets

const tNameSet &  cMMVII_Appli::MainSet0() const { return MainSet(0); }
const tNameSet &  cMMVII_Appli::MainSet1() const { return MainSet(1); }
const tNameSet &  cMMVII_Appli::MainSet(int aK) const 
{
   CheckRangeMainSet(aK);
   if (! mVMainSets.at(aK).IsInit())
   {
      MMVII_INTERNAL_ASSERT_always(false,"No mMainSet created for K="+ ToStr(aK));
   }
   return  mVMainSets.at(aK);
}

void cMMVII_Appli::CheckRangeMainSet(int aK) const
{
   if ((aK<0) || (aK>=NbMaxMainSets))
   {
      MMVII_INTERNAL_ASSERT_always(false,"CheckRangeMainSet, out for :" + ToStr(aK));
   }
}

    // ========== Handling of V1/V2 format for output =================

void cMMVII_Appli::SignalInputFormat(int aNumV)
{
   cMMVII_Appli & TheAp = TheAppli();
   if (aNumV==0)
   {
   }
   else if (aNumV==1)
   {
      TheAp.mHasInputV1 = true;
   }
   else if (aNumV==2)
   {
      TheAp.mHasInputV2 = true;
   }
   else 
   {
      MMVII_INTERNAL_ASSERT_always(false,"Input version must be in {0,1,2}, got: "+ToStr(aNumV));
   }
}

// Necessary for forward use of cMMVII_Appli::OutV2Forma
bool GlobOutV2Format() { return cMMVII_Appli::OutV2Format(); }
bool   cMMVII_Appli::OutV2Format() 
{
   const cMMVII_Appli & TheAp = TheAppli();
   // Priority to specified output if exist
   if (TheAp.mOutPutV2) return true;
   if (TheAp.mOutPutV1) return false;
   //  In input, set it, priority to V2
   if (TheAp.mHasInputV2) return true;
   if (TheAp.mHasInputV1) return false;
   // by default V2
   return true;
}

    // ========== Handling of global Appli =================

cMMVII_Appli *  cMMVII_Appli::msTheAppli = 0;
cMMVII_Appli & cMMVII_Appli::TheAppli()
{
  MMVII_INTERNAL_ASSERT_medium(msTheAppli!=0,"cMMVII_Appli not created");
  return *msTheAppli;
}
bool cMMVII_Appli::ExistAppli()
{
  return msTheAppli != 0;
}

    // ========== Miscelaneous functions =================

void cMMVII_Appli::AssertInitParam() const
{
  MMVII_INTERNAL_ASSERT_always(mInitParamDone,"Init Param was forgotten");
}
bool  cMMVII_Appli::IsInit(void * aPtr)
{
    return  mSetInit.In(aPtr);
}
              // Accessors
const std::string & cMMVII_Appli::TmpDirTestMMVII()   const {return mTmpDirTestMMVII;}
const std::string & cMMVII_Appli::InputDirTestMMVII() const {return mInputDirTestMMVII;}


    // ==========  MMVII  Call MMVII =================

cColStrAObl& cMMVII_Appli::StrObl() {return mColStrAObl;}
cColStrAOpt& cMMVII_Appli::StrOpt() {return mColStrAOpt;}


std::string  cMMVII_Appli::StrCallMMVII(const std::string & aCom2007,const cColStrAObl& anAObl,const cColStrAOpt& anAOpt)
{
  MMVII_INTERNAL_ASSERT_always(&anAObl==&mColStrAObl,"StrCallMMVII use StrObl() !!");
  MMVII_INTERNAL_ASSERT_always(&anAOpt==&mColStrAOpt,"StrCallMMVII use StrOpt() !!");

   std::string aComGlob = mFullBin + " ";
   cSpecMMVII_Appli*  aSpec = cSpecMMVII_Appli::SpecOfName(aCom2007,false); // false => dont accept no match
   if (! aSpec)  // Will see if we can di better, however SpecOfNam has generated error
      return "";

   // Theoretically we can create the command  (dealing with unik msTheAppli before !) and check
   // the parameters, but it will be done in the call so maybe it's not worth the price ?
  
   aComGlob += aCom2007 + " ";

   // Add mandatory args
   for (const auto & aStr : anAObl.V())
   {
       aComGlob +=  Quote(aStr) + " ";
   }

   // Add optionnal args
   for (const auto & aP : anAOpt.V())
   {
       aComGlob +=  aP.first + "=" + Quote(aP.second) + " ";
   }

   // Take into account the call level which must increase
   aComGlob += "LevCall=" + ToStr(mLevelCall+1);

   mColStrAObl.clear();
   mColStrAOpt.clear();
   return aComGlob;
}

int  cMMVII_Appli::ExeCallMMVII(const std::string & aCom2007,const cColStrAObl& anAObl,const cColStrAOpt& anAOpt)
{
    std::string   aComGlob = StrCallMMVII(aCom2007,anAObl,anAOpt);
if (0)
{
    std::cout <<  "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    std::cout << aComGlob << "\n";
    getchar();
}
    return  SysCall(aComGlob,false);
}


};

