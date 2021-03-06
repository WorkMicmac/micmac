// File Automatically generated by eLiSe
#include "StdAfx.h"
#include "cEqAppui_PProjInc_M2CEbner.h"


cEqAppui_PProjInc_M2CEbner::cEqAppui_PProjInc_M2CEbner():
    cElCompiledFonc(2)
{
   AddIntRef (cIncIntervale("Intr",0,15));
   AddIntRef (cIncIntervale("Orient",15,21));
   AddIntRef (cIncIntervale("Tmp_PTer",21,24));
   Close(false);
}



void cEqAppui_PProjInc_M2CEbner::ComputeVal()
{
   double tmp0_ = mCompCoord[15];
   double tmp1_ = mCompCoord[16];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = mCompCoord[21];
   double tmp4_ = mCompCoord[22];
   double tmp5_ = mCompCoord[23];
   double tmp6_ = sin(tmp0_);
   double tmp7_ = cos(tmp0_);
   double tmp8_ = sin(tmp1_);
   double tmp9_ = mCompCoord[17];
   double tmp10_ = mLocProjI_x * tmp3_;
   double tmp11_ = mLocProjP0_x + tmp10_;
   double tmp12_ = mLocProjJ_x * tmp4_;
   double tmp13_ = tmp11_ + tmp12_;
   double tmp14_ = mLocProjK_x * tmp5_;
   double tmp15_ = tmp13_ + tmp14_;
   double tmp16_ = mCompCoord[18];
   double tmp17_ = (tmp15_) - tmp16_;
   double tmp18_ = sin(tmp9_);
   double tmp19_ = -(tmp18_);
   double tmp20_ = -(tmp8_);
   double tmp21_ = cos(tmp9_);
   double tmp22_ = mLocProjI_y * tmp3_;
   double tmp23_ = mLocProjP0_y + tmp22_;
   double tmp24_ = mLocProjJ_y * tmp4_;
   double tmp25_ = tmp23_ + tmp24_;
   double tmp26_ = mLocProjK_y * tmp5_;
   double tmp27_ = tmp25_ + tmp26_;
   double tmp28_ = mCompCoord[19];
   double tmp29_ = (tmp27_) - tmp28_;
   double tmp30_ = mLocProjI_z * tmp3_;
   double tmp31_ = mLocProjP0_z + tmp30_;
   double tmp32_ = mLocProjJ_z * tmp4_;
   double tmp33_ = tmp31_ + tmp32_;
   double tmp34_ = mLocProjK_z * tmp5_;
   double tmp35_ = tmp33_ + tmp34_;
   double tmp36_ = mCompCoord[20];
   double tmp37_ = (tmp35_) - tmp36_;
   double tmp38_ = -(tmp6_);
   double tmp39_ = tmp7_ * tmp20_;
   double tmp40_ = tmp6_ * tmp20_;
   double tmp41_ = mCompCoord[0];
   double tmp42_ = tmp38_ * tmp19_;
   double tmp43_ = tmp39_ * tmp21_;
   double tmp44_ = tmp42_ + tmp43_;
   double tmp45_ = (tmp44_) * (tmp17_);
   double tmp46_ = tmp7_ * tmp19_;
   double tmp47_ = tmp40_ * tmp21_;
   double tmp48_ = tmp46_ + tmp47_;
   double tmp49_ = (tmp48_) * (tmp29_);
   double tmp50_ = tmp45_ + tmp49_;
   double tmp51_ = tmp2_ * tmp21_;
   double tmp52_ = tmp51_ * (tmp37_);
   double tmp53_ = tmp50_ + tmp52_;
   double tmp54_ = tmp41_ / (tmp53_);
   double tmp55_ = tmp7_ * tmp2_;
   double tmp56_ = tmp55_ * (tmp17_);
   double tmp57_ = tmp6_ * tmp2_;
   double tmp58_ = tmp57_ * (tmp29_);
   double tmp59_ = tmp56_ + tmp58_;
   double tmp60_ = tmp8_ * (tmp37_);
   double tmp61_ = tmp59_ + tmp60_;
   double tmp62_ = (tmp61_) * (tmp54_);
   double tmp63_ = mCompCoord[1];
   double tmp64_ = tmp62_ + tmp63_;
   double tmp65_ = tmp38_ * tmp21_;
   double tmp66_ = tmp39_ * tmp18_;
   double tmp67_ = tmp65_ + tmp66_;
   double tmp68_ = (tmp67_) * (tmp17_);
   double tmp69_ = tmp7_ * tmp21_;
   double tmp70_ = tmp40_ * tmp18_;
   double tmp71_ = tmp69_ + tmp70_;
   double tmp72_ = (tmp71_) * (tmp29_);
   double tmp73_ = tmp68_ + tmp72_;
   double tmp74_ = tmp2_ * tmp18_;
   double tmp75_ = tmp74_ * (tmp37_);
   double tmp76_ = tmp73_ + tmp75_;
   double tmp77_ = (tmp76_) * (tmp54_);
   double tmp78_ = mCompCoord[2];
   double tmp79_ = tmp77_ + tmp78_;
   double tmp80_ = mLocEbner_State_0_0 * mLocEbner_State_0_0;
   double tmp81_ = tmp80_ * 0.666667;
   double tmp82_ = (tmp79_) * (tmp79_);
   double tmp83_ = tmp82_ - tmp81_;
   double tmp84_ = (tmp64_) * (tmp64_);
   double tmp85_ = tmp84_ - tmp81_;
   double tmp86_ = mCompCoord[3];
   double tmp87_ = mCompCoord[4];
   double tmp88_ = mCompCoord[5];
   double tmp89_ = (tmp64_) * (tmp79_);
   double tmp90_ = mCompCoord[6];

  mVal[0] = ((((1 + tmp86_) * (tmp64_) + tmp87_ * (tmp79_)) - tmp88_ * 2 * (tmp85_) + tmp90_ * tmp89_ + mCompCoord[7] * (tmp83_) + mCompCoord[9] * (tmp64_) * (tmp83_) + mCompCoord[11] * (tmp79_) * (tmp85_) + mCompCoord[13] * (tmp85_) * (tmp83_)) - mLocXIm) * mLocScNorm;

  mVal[1] = ((((1 - tmp86_) * (tmp79_) + tmp87_ * (tmp64_) + tmp88_ * tmp89_) - tmp90_ * 2 * (tmp83_) + mCompCoord[8] * (tmp85_) + mCompCoord[10] * (tmp79_) * (tmp85_) + mCompCoord[12] * (tmp64_) * (tmp83_) + mCompCoord[14] * (tmp85_) * (tmp83_)) - mLocYIm) * mLocScNorm;

}


void cEqAppui_PProjInc_M2CEbner::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[15];
   double tmp1_ = mCompCoord[16];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = mCompCoord[21];
   double tmp4_ = mCompCoord[22];
   double tmp5_ = mCompCoord[23];
   double tmp6_ = sin(tmp0_);
   double tmp7_ = cos(tmp0_);
   double tmp8_ = sin(tmp1_);
   double tmp9_ = mCompCoord[17];
   double tmp10_ = mLocProjI_x * tmp3_;
   double tmp11_ = mLocProjP0_x + tmp10_;
   double tmp12_ = mLocProjJ_x * tmp4_;
   double tmp13_ = tmp11_ + tmp12_;
   double tmp14_ = mLocProjK_x * tmp5_;
   double tmp15_ = tmp13_ + tmp14_;
   double tmp16_ = mCompCoord[18];
   double tmp17_ = (tmp15_) - tmp16_;
   double tmp18_ = sin(tmp9_);
   double tmp19_ = -(tmp18_);
   double tmp20_ = -(tmp8_);
   double tmp21_ = cos(tmp9_);
   double tmp22_ = mLocProjI_y * tmp3_;
   double tmp23_ = mLocProjP0_y + tmp22_;
   double tmp24_ = mLocProjJ_y * tmp4_;
   double tmp25_ = tmp23_ + tmp24_;
   double tmp26_ = mLocProjK_y * tmp5_;
   double tmp27_ = tmp25_ + tmp26_;
   double tmp28_ = mCompCoord[19];
   double tmp29_ = (tmp27_) - tmp28_;
   double tmp30_ = mLocProjI_z * tmp3_;
   double tmp31_ = mLocProjP0_z + tmp30_;
   double tmp32_ = mLocProjJ_z * tmp4_;
   double tmp33_ = tmp31_ + tmp32_;
   double tmp34_ = mLocProjK_z * tmp5_;
   double tmp35_ = tmp33_ + tmp34_;
   double tmp36_ = mCompCoord[20];
   double tmp37_ = (tmp35_) - tmp36_;
   double tmp38_ = -(tmp6_);
   double tmp39_ = tmp7_ * tmp20_;
   double tmp40_ = tmp6_ * tmp20_;
   double tmp41_ = mCompCoord[0];
   double tmp42_ = tmp38_ * tmp19_;
   double tmp43_ = tmp39_ * tmp21_;
   double tmp44_ = tmp42_ + tmp43_;
   double tmp45_ = (tmp44_) * (tmp17_);
   double tmp46_ = tmp7_ * tmp19_;
   double tmp47_ = tmp40_ * tmp21_;
   double tmp48_ = tmp46_ + tmp47_;
   double tmp49_ = (tmp48_) * (tmp29_);
   double tmp50_ = tmp45_ + tmp49_;
   double tmp51_ = tmp2_ * tmp21_;
   double tmp52_ = tmp51_ * (tmp37_);
   double tmp53_ = tmp50_ + tmp52_;
   double tmp54_ = tmp41_ / (tmp53_);
   double tmp55_ = tmp7_ * tmp2_;
   double tmp56_ = tmp55_ * (tmp17_);
   double tmp57_ = tmp6_ * tmp2_;
   double tmp58_ = tmp57_ * (tmp29_);
   double tmp59_ = tmp56_ + tmp58_;
   double tmp60_ = tmp8_ * (tmp37_);
   double tmp61_ = tmp59_ + tmp60_;
   double tmp62_ = (tmp61_) * (tmp54_);
   double tmp63_ = mCompCoord[1];
   double tmp64_ = tmp62_ + tmp63_;
   double tmp65_ = tmp38_ * tmp21_;
   double tmp66_ = tmp39_ * tmp18_;
   double tmp67_ = tmp65_ + tmp66_;
   double tmp68_ = (tmp67_) * (tmp17_);
   double tmp69_ = tmp7_ * tmp21_;
   double tmp70_ = tmp40_ * tmp18_;
   double tmp71_ = tmp69_ + tmp70_;
   double tmp72_ = (tmp71_) * (tmp29_);
   double tmp73_ = tmp68_ + tmp72_;
   double tmp74_ = tmp2_ * tmp18_;
   double tmp75_ = tmp74_ * (tmp37_);
   double tmp76_ = tmp73_ + tmp75_;
   double tmp77_ = (tmp76_) * (tmp54_);
   double tmp78_ = mCompCoord[2];
   double tmp79_ = tmp77_ + tmp78_;
   double tmp80_ = mLocEbner_State_0_0 * mLocEbner_State_0_0;
   double tmp81_ = tmp80_ * 0.666667;
   double tmp82_ = (tmp79_) * (tmp79_);
   double tmp83_ = tmp82_ - tmp81_;
   double tmp84_ = (tmp64_) * (tmp64_);
   double tmp85_ = tmp84_ - tmp81_;
   double tmp86_ = mCompCoord[3];
   double tmp87_ = 1 + tmp86_;
   double tmp88_ = ElSquare(tmp53_);
   double tmp89_ = (tmp53_) / tmp88_;
   double tmp90_ = mCompCoord[4];
   double tmp91_ = (tmp89_) * (tmp61_);
   double tmp92_ = tmp91_ * (tmp64_);
   double tmp93_ = mCompCoord[5];
   double tmp94_ = tmp93_ * 2;
   double tmp95_ = (tmp89_) * (tmp76_);
   double tmp96_ = mCompCoord[6];
   double tmp97_ = tmp95_ * (tmp79_);
   double tmp98_ = mCompCoord[7];
   double tmp99_ = mCompCoord[9];
   double tmp100_ = tmp97_ + tmp97_;
   double tmp101_ = tmp99_ * (tmp64_);
   double tmp102_ = mCompCoord[11];
   double tmp103_ = tmp92_ + tmp92_;
   double tmp104_ = tmp102_ * (tmp79_);
   double tmp105_ = mCompCoord[13];
   double tmp106_ = tmp105_ * (tmp85_);
   double tmp107_ = tmp64_ + tmp64_;
   double tmp108_ = tmp79_ + tmp79_;
   double tmp109_ = (tmp64_) * (tmp79_);
   double tmp110_ = -(1);
   double tmp111_ = tmp110_ * tmp6_;
   double tmp112_ = -(tmp7_);
   double tmp113_ = tmp111_ * tmp20_;
   double tmp114_ = tmp112_ * tmp19_;
   double tmp115_ = tmp113_ * tmp21_;
   double tmp116_ = tmp114_ + tmp115_;
   double tmp117_ = (tmp116_) * (tmp17_);
   double tmp118_ = tmp111_ * tmp19_;
   double tmp119_ = tmp118_ + tmp43_;
   double tmp120_ = (tmp119_) * (tmp29_);
   double tmp121_ = tmp117_ + tmp120_;
   double tmp122_ = tmp41_ * (tmp121_);
   double tmp123_ = -(tmp122_);
   double tmp124_ = tmp123_ / tmp88_;
   double tmp125_ = tmp111_ * tmp2_;
   double tmp126_ = tmp125_ * (tmp17_);
   double tmp127_ = tmp55_ * (tmp29_);
   double tmp128_ = tmp126_ + tmp127_;
   double tmp129_ = (tmp128_) * (tmp54_);
   double tmp130_ = (tmp124_) * (tmp61_);
   double tmp131_ = tmp129_ + tmp130_;
   double tmp132_ = (tmp131_) * (tmp64_);
   double tmp133_ = tmp112_ * tmp21_;
   double tmp134_ = tmp113_ * tmp18_;
   double tmp135_ = tmp133_ + tmp134_;
   double tmp136_ = (tmp135_) * (tmp17_);
   double tmp137_ = tmp111_ * tmp21_;
   double tmp138_ = tmp137_ + tmp66_;
   double tmp139_ = (tmp138_) * (tmp29_);
   double tmp140_ = tmp136_ + tmp139_;
   double tmp141_ = (tmp140_) * (tmp54_);
   double tmp142_ = (tmp124_) * (tmp76_);
   double tmp143_ = tmp141_ + tmp142_;
   double tmp144_ = (tmp143_) * (tmp79_);
   double tmp145_ = tmp144_ + tmp144_;
   double tmp146_ = tmp132_ + tmp132_;
   double tmp147_ = tmp110_ * tmp8_;
   double tmp148_ = -(tmp2_);
   double tmp149_ = tmp148_ * tmp7_;
   double tmp150_ = tmp148_ * tmp6_;
   double tmp151_ = tmp149_ * tmp21_;
   double tmp152_ = tmp151_ * (tmp17_);
   double tmp153_ = tmp150_ * tmp21_;
   double tmp154_ = tmp153_ * (tmp29_);
   double tmp155_ = tmp152_ + tmp154_;
   double tmp156_ = tmp147_ * tmp21_;
   double tmp157_ = tmp156_ * (tmp37_);
   double tmp158_ = tmp155_ + tmp157_;
   double tmp159_ = tmp41_ * (tmp158_);
   double tmp160_ = -(tmp159_);
   double tmp161_ = tmp160_ / tmp88_;
   double tmp162_ = tmp147_ * tmp7_;
   double tmp163_ = tmp162_ * (tmp17_);
   double tmp164_ = tmp147_ * tmp6_;
   double tmp165_ = tmp164_ * (tmp29_);
   double tmp166_ = tmp163_ + tmp165_;
   double tmp167_ = tmp2_ * (tmp37_);
   double tmp168_ = tmp166_ + tmp167_;
   double tmp169_ = (tmp168_) * (tmp54_);
   double tmp170_ = (tmp161_) * (tmp61_);
   double tmp171_ = tmp169_ + tmp170_;
   double tmp172_ = (tmp171_) * (tmp64_);
   double tmp173_ = tmp149_ * tmp18_;
   double tmp174_ = tmp173_ * (tmp17_);
   double tmp175_ = tmp150_ * tmp18_;
   double tmp176_ = tmp175_ * (tmp29_);
   double tmp177_ = tmp174_ + tmp176_;
   double tmp178_ = tmp147_ * tmp18_;
   double tmp179_ = tmp178_ * (tmp37_);
   double tmp180_ = tmp177_ + tmp179_;
   double tmp181_ = (tmp180_) * (tmp54_);
   double tmp182_ = (tmp161_) * (tmp76_);
   double tmp183_ = tmp181_ + tmp182_;
   double tmp184_ = (tmp183_) * (tmp79_);
   double tmp185_ = tmp184_ + tmp184_;
   double tmp186_ = tmp172_ + tmp172_;
   double tmp187_ = -(tmp21_);
   double tmp188_ = tmp110_ * tmp18_;
   double tmp189_ = tmp187_ * tmp38_;
   double tmp190_ = tmp188_ * tmp39_;
   double tmp191_ = tmp189_ + tmp190_;
   double tmp192_ = (tmp191_) * (tmp17_);
   double tmp193_ = tmp187_ * tmp7_;
   double tmp194_ = tmp188_ * tmp40_;
   double tmp195_ = tmp193_ + tmp194_;
   double tmp196_ = (tmp195_) * (tmp29_);
   double tmp197_ = tmp192_ + tmp196_;
   double tmp198_ = tmp188_ * tmp2_;
   double tmp199_ = tmp198_ * (tmp37_);
   double tmp200_ = tmp197_ + tmp199_;
   double tmp201_ = tmp41_ * (tmp200_);
   double tmp202_ = -(tmp201_);
   double tmp203_ = tmp202_ / tmp88_;
   double tmp204_ = (tmp203_) * (tmp61_);
   double tmp205_ = tmp204_ * (tmp64_);
   double tmp206_ = tmp188_ * tmp38_;
   double tmp207_ = tmp21_ * tmp39_;
   double tmp208_ = tmp206_ + tmp207_;
   double tmp209_ = (tmp208_) * (tmp17_);
   double tmp210_ = tmp188_ * tmp7_;
   double tmp211_ = tmp21_ * tmp40_;
   double tmp212_ = tmp210_ + tmp211_;
   double tmp213_ = (tmp212_) * (tmp29_);
   double tmp214_ = tmp209_ + tmp213_;
   double tmp215_ = tmp21_ * tmp2_;
   double tmp216_ = tmp215_ * (tmp37_);
   double tmp217_ = tmp214_ + tmp216_;
   double tmp218_ = (tmp217_) * (tmp54_);
   double tmp219_ = (tmp203_) * (tmp76_);
   double tmp220_ = tmp218_ + tmp219_;
   double tmp221_ = (tmp220_) * (tmp79_);
   double tmp222_ = tmp221_ + tmp221_;
   double tmp223_ = tmp205_ + tmp205_;
   double tmp224_ = tmp110_ * (tmp44_);
   double tmp225_ = tmp41_ * tmp224_;
   double tmp226_ = -(tmp225_);
   double tmp227_ = tmp226_ / tmp88_;
   double tmp228_ = tmp110_ * tmp55_;
   double tmp229_ = tmp228_ * (tmp54_);
   double tmp230_ = (tmp227_) * (tmp61_);
   double tmp231_ = tmp229_ + tmp230_;
   double tmp232_ = (tmp231_) * (tmp64_);
   double tmp233_ = tmp110_ * (tmp67_);
   double tmp234_ = tmp233_ * (tmp54_);
   double tmp235_ = (tmp227_) * (tmp76_);
   double tmp236_ = tmp234_ + tmp235_;
   double tmp237_ = (tmp236_) * (tmp79_);
   double tmp238_ = tmp237_ + tmp237_;
   double tmp239_ = tmp232_ + tmp232_;
   double tmp240_ = tmp110_ * (tmp48_);
   double tmp241_ = tmp41_ * tmp240_;
   double tmp242_ = -(tmp241_);
   double tmp243_ = tmp242_ / tmp88_;
   double tmp244_ = tmp110_ * tmp57_;
   double tmp245_ = tmp244_ * (tmp54_);
   double tmp246_ = (tmp243_) * (tmp61_);
   double tmp247_ = tmp245_ + tmp246_;
   double tmp248_ = (tmp247_) * (tmp64_);
   double tmp249_ = tmp110_ * (tmp71_);
   double tmp250_ = tmp249_ * (tmp54_);
   double tmp251_ = (tmp243_) * (tmp76_);
   double tmp252_ = tmp250_ + tmp251_;
   double tmp253_ = (tmp252_) * (tmp79_);
   double tmp254_ = tmp253_ + tmp253_;
   double tmp255_ = tmp248_ + tmp248_;
   double tmp256_ = tmp110_ * tmp51_;
   double tmp257_ = tmp41_ * tmp256_;
   double tmp258_ = -(tmp257_);
   double tmp259_ = tmp258_ / tmp88_;
   double tmp260_ = tmp147_ * (tmp54_);
   double tmp261_ = (tmp259_) * (tmp61_);
   double tmp262_ = tmp260_ + tmp261_;
   double tmp263_ = (tmp262_) * (tmp64_);
   double tmp264_ = tmp110_ * tmp74_;
   double tmp265_ = tmp264_ * (tmp54_);
   double tmp266_ = (tmp259_) * (tmp76_);
   double tmp267_ = tmp265_ + tmp266_;
   double tmp268_ = (tmp267_) * (tmp79_);
   double tmp269_ = tmp268_ + tmp268_;
   double tmp270_ = tmp263_ + tmp263_;
   double tmp271_ = mLocProjI_x * (tmp44_);
   double tmp272_ = mLocProjI_y * (tmp48_);
   double tmp273_ = tmp271_ + tmp272_;
   double tmp274_ = mLocProjI_z * tmp51_;
   double tmp275_ = tmp273_ + tmp274_;
   double tmp276_ = tmp41_ * (tmp275_);
   double tmp277_ = -(tmp276_);
   double tmp278_ = tmp277_ / tmp88_;
   double tmp279_ = mLocProjI_x * tmp55_;
   double tmp280_ = mLocProjI_y * tmp57_;
   double tmp281_ = tmp279_ + tmp280_;
   double tmp282_ = mLocProjI_z * tmp8_;
   double tmp283_ = tmp281_ + tmp282_;
   double tmp284_ = (tmp283_) * (tmp54_);
   double tmp285_ = (tmp278_) * (tmp61_);
   double tmp286_ = tmp284_ + tmp285_;
   double tmp287_ = (tmp286_) * (tmp64_);
   double tmp288_ = mLocProjI_x * (tmp67_);
   double tmp289_ = mLocProjI_y * (tmp71_);
   double tmp290_ = tmp288_ + tmp289_;
   double tmp291_ = mLocProjI_z * tmp74_;
   double tmp292_ = tmp290_ + tmp291_;
   double tmp293_ = (tmp292_) * (tmp54_);
   double tmp294_ = (tmp278_) * (tmp76_);
   double tmp295_ = tmp293_ + tmp294_;
   double tmp296_ = (tmp295_) * (tmp79_);
   double tmp297_ = tmp296_ + tmp296_;
   double tmp298_ = tmp287_ + tmp287_;
   double tmp299_ = mLocProjJ_x * (tmp44_);
   double tmp300_ = mLocProjJ_y * (tmp48_);
   double tmp301_ = tmp299_ + tmp300_;
   double tmp302_ = mLocProjJ_z * tmp51_;
   double tmp303_ = tmp301_ + tmp302_;
   double tmp304_ = tmp41_ * (tmp303_);
   double tmp305_ = -(tmp304_);
   double tmp306_ = tmp305_ / tmp88_;
   double tmp307_ = mLocProjJ_x * tmp55_;
   double tmp308_ = mLocProjJ_y * tmp57_;
   double tmp309_ = tmp307_ + tmp308_;
   double tmp310_ = mLocProjJ_z * tmp8_;
   double tmp311_ = tmp309_ + tmp310_;
   double tmp312_ = (tmp311_) * (tmp54_);
   double tmp313_ = (tmp306_) * (tmp61_);
   double tmp314_ = tmp312_ + tmp313_;
   double tmp315_ = (tmp314_) * (tmp64_);
   double tmp316_ = mLocProjJ_x * (tmp67_);
   double tmp317_ = mLocProjJ_y * (tmp71_);
   double tmp318_ = tmp316_ + tmp317_;
   double tmp319_ = mLocProjJ_z * tmp74_;
   double tmp320_ = tmp318_ + tmp319_;
   double tmp321_ = (tmp320_) * (tmp54_);
   double tmp322_ = (tmp306_) * (tmp76_);
   double tmp323_ = tmp321_ + tmp322_;
   double tmp324_ = (tmp323_) * (tmp79_);
   double tmp325_ = tmp324_ + tmp324_;
   double tmp326_ = tmp315_ + tmp315_;
   double tmp327_ = mLocProjK_x * (tmp44_);
   double tmp328_ = mLocProjK_y * (tmp48_);
   double tmp329_ = tmp327_ + tmp328_;
   double tmp330_ = mLocProjK_z * tmp51_;
   double tmp331_ = tmp329_ + tmp330_;
   double tmp332_ = tmp41_ * (tmp331_);
   double tmp333_ = -(tmp332_);
   double tmp334_ = tmp333_ / tmp88_;
   double tmp335_ = mLocProjK_x * tmp55_;
   double tmp336_ = mLocProjK_y * tmp57_;
   double tmp337_ = tmp335_ + tmp336_;
   double tmp338_ = mLocProjK_z * tmp8_;
   double tmp339_ = tmp337_ + tmp338_;
   double tmp340_ = (tmp339_) * (tmp54_);
   double tmp341_ = (tmp334_) * (tmp61_);
   double tmp342_ = tmp340_ + tmp341_;
   double tmp343_ = (tmp342_) * (tmp64_);
   double tmp344_ = mLocProjK_x * (tmp67_);
   double tmp345_ = mLocProjK_y * (tmp71_);
   double tmp346_ = tmp344_ + tmp345_;
   double tmp347_ = mLocProjK_z * tmp74_;
   double tmp348_ = tmp346_ + tmp347_;
   double tmp349_ = (tmp348_) * (tmp54_);
   double tmp350_ = (tmp334_) * (tmp76_);
   double tmp351_ = tmp349_ + tmp350_;
   double tmp352_ = (tmp351_) * (tmp79_);
   double tmp353_ = tmp352_ + tmp352_;
   double tmp354_ = tmp343_ + tmp343_;
   double tmp355_ = 1 - tmp86_;
   double tmp356_ = tmp91_ * (tmp79_);
   double tmp357_ = tmp95_ * (tmp64_);
   double tmp358_ = tmp356_ + tmp357_;
   double tmp359_ = tmp96_ * 2;
   double tmp360_ = mCompCoord[8];
   double tmp361_ = mCompCoord[10];
   double tmp362_ = tmp361_ * (tmp79_);
   double tmp363_ = mCompCoord[12];
   double tmp364_ = tmp363_ * (tmp64_);
   double tmp365_ = mCompCoord[14];
   double tmp366_ = tmp365_ * (tmp85_);
   double tmp367_ = (tmp64_) * mLocScNorm;
   double tmp368_ = tmp109_ * mLocScNorm;
   double tmp369_ = (tmp79_) * (tmp85_);
   double tmp370_ = tmp369_ * mLocScNorm;
   double tmp371_ = (tmp64_) * (tmp83_);
   double tmp372_ = tmp371_ * mLocScNorm;
   double tmp373_ = (tmp85_) * (tmp83_);
   double tmp374_ = tmp373_ * mLocScNorm;
   double tmp375_ = (tmp131_) * (tmp79_);
   double tmp376_ = (tmp143_) * (tmp64_);
   double tmp377_ = tmp375_ + tmp376_;
   double tmp378_ = (tmp171_) * (tmp79_);
   double tmp379_ = (tmp183_) * (tmp64_);
   double tmp380_ = tmp378_ + tmp379_;
   double tmp381_ = tmp204_ * (tmp79_);
   double tmp382_ = (tmp220_) * (tmp64_);
   double tmp383_ = tmp381_ + tmp382_;
   double tmp384_ = (tmp231_) * (tmp79_);
   double tmp385_ = (tmp236_) * (tmp64_);
   double tmp386_ = tmp384_ + tmp385_;
   double tmp387_ = (tmp247_) * (tmp79_);
   double tmp388_ = (tmp252_) * (tmp64_);
   double tmp389_ = tmp387_ + tmp388_;
   double tmp390_ = (tmp262_) * (tmp79_);
   double tmp391_ = (tmp267_) * (tmp64_);
   double tmp392_ = tmp390_ + tmp391_;
   double tmp393_ = (tmp286_) * (tmp79_);
   double tmp394_ = (tmp295_) * (tmp64_);
   double tmp395_ = tmp393_ + tmp394_;
   double tmp396_ = (tmp314_) * (tmp79_);
   double tmp397_ = (tmp323_) * (tmp64_);
   double tmp398_ = tmp396_ + tmp397_;
   double tmp399_ = (tmp342_) * (tmp79_);
   double tmp400_ = (tmp351_) * (tmp64_);
   double tmp401_ = tmp399_ + tmp400_;

  mVal[0] = ((((tmp87_) * (tmp64_) + tmp90_ * (tmp79_)) - tmp94_ * (tmp85_) + tmp96_ * tmp109_ + tmp98_ * (tmp83_) + tmp101_ * (tmp83_) + tmp104_ * (tmp85_) + tmp106_ * (tmp83_)) - mLocXIm) * mLocScNorm;

  mCompDer[0][0] = ((tmp91_ * (tmp87_) + tmp95_ * tmp90_) - (tmp103_) * tmp94_ + (tmp358_) * tmp96_ + (tmp100_) * tmp98_ + tmp91_ * tmp99_ * (tmp83_) + (tmp100_) * tmp101_ + tmp95_ * tmp102_ * (tmp85_) + (tmp103_) * tmp104_ + (tmp103_) * tmp105_ * (tmp83_) + (tmp100_) * tmp106_) * mLocScNorm;
  mCompDer[0][1] = ((tmp87_) - (tmp107_) * tmp94_ + (tmp79_) * tmp96_ + tmp99_ * (tmp83_) + (tmp107_) * tmp104_ + (tmp107_) * tmp105_ * (tmp83_)) * mLocScNorm;
  mCompDer[0][2] = (tmp90_ + (tmp64_) * tmp96_ + (tmp108_) * tmp98_ + (tmp108_) * tmp101_ + tmp102_ * (tmp85_) + (tmp108_) * tmp106_) * mLocScNorm;
  mCompDer[0][3] = tmp367_;
  mCompDer[0][4] = (tmp79_) * mLocScNorm;
  mCompDer[0][5] = -(2 * (tmp85_)) * mLocScNorm;
  mCompDer[0][6] = tmp368_;
  mCompDer[0][7] = (tmp83_) * mLocScNorm;
  mCompDer[0][8] = 0;
  mCompDer[0][9] = tmp372_;
  mCompDer[0][10] = 0;
  mCompDer[0][11] = tmp370_;
  mCompDer[0][12] = 0;
  mCompDer[0][13] = tmp374_;
  mCompDer[0][14] = 0;
  mCompDer[0][15] = (((tmp131_) * (tmp87_) + (tmp143_) * tmp90_) - (tmp146_) * tmp94_ + (tmp377_) * tmp96_ + (tmp145_) * tmp98_ + (tmp131_) * tmp99_ * (tmp83_) + (tmp145_) * tmp101_ + (tmp143_) * tmp102_ * (tmp85_) + (tmp146_) * tmp104_ + (tmp146_) * tmp105_ * (tmp83_) + (tmp145_) * tmp106_) * mLocScNorm;
  mCompDer[0][16] = (((tmp171_) * (tmp87_) + (tmp183_) * tmp90_) - (tmp186_) * tmp94_ + (tmp380_) * tmp96_ + (tmp185_) * tmp98_ + (tmp171_) * tmp99_ * (tmp83_) + (tmp185_) * tmp101_ + (tmp183_) * tmp102_ * (tmp85_) + (tmp186_) * tmp104_ + (tmp186_) * tmp105_ * (tmp83_) + (tmp185_) * tmp106_) * mLocScNorm;
  mCompDer[0][17] = ((tmp204_ * (tmp87_) + (tmp220_) * tmp90_) - (tmp223_) * tmp94_ + (tmp383_) * tmp96_ + (tmp222_) * tmp98_ + tmp204_ * tmp99_ * (tmp83_) + (tmp222_) * tmp101_ + (tmp220_) * tmp102_ * (tmp85_) + (tmp223_) * tmp104_ + (tmp223_) * tmp105_ * (tmp83_) + (tmp222_) * tmp106_) * mLocScNorm;
  mCompDer[0][18] = (((tmp231_) * (tmp87_) + (tmp236_) * tmp90_) - (tmp239_) * tmp94_ + (tmp386_) * tmp96_ + (tmp238_) * tmp98_ + (tmp231_) * tmp99_ * (tmp83_) + (tmp238_) * tmp101_ + (tmp236_) * tmp102_ * (tmp85_) + (tmp239_) * tmp104_ + (tmp239_) * tmp105_ * (tmp83_) + (tmp238_) * tmp106_) * mLocScNorm;
  mCompDer[0][19] = (((tmp247_) * (tmp87_) + (tmp252_) * tmp90_) - (tmp255_) * tmp94_ + (tmp389_) * tmp96_ + (tmp254_) * tmp98_ + (tmp247_) * tmp99_ * (tmp83_) + (tmp254_) * tmp101_ + (tmp252_) * tmp102_ * (tmp85_) + (tmp255_) * tmp104_ + (tmp255_) * tmp105_ * (tmp83_) + (tmp254_) * tmp106_) * mLocScNorm;
  mCompDer[0][20] = (((tmp262_) * (tmp87_) + (tmp267_) * tmp90_) - (tmp270_) * tmp94_ + (tmp392_) * tmp96_ + (tmp269_) * tmp98_ + (tmp262_) * tmp99_ * (tmp83_) + (tmp269_) * tmp101_ + (tmp267_) * tmp102_ * (tmp85_) + (tmp270_) * tmp104_ + (tmp270_) * tmp105_ * (tmp83_) + (tmp269_) * tmp106_) * mLocScNorm;
  mCompDer[0][21] = (((tmp286_) * (tmp87_) + (tmp295_) * tmp90_) - (tmp298_) * tmp94_ + (tmp395_) * tmp96_ + (tmp297_) * tmp98_ + (tmp286_) * tmp99_ * (tmp83_) + (tmp297_) * tmp101_ + (tmp295_) * tmp102_ * (tmp85_) + (tmp298_) * tmp104_ + (tmp298_) * tmp105_ * (tmp83_) + (tmp297_) * tmp106_) * mLocScNorm;
  mCompDer[0][22] = (((tmp314_) * (tmp87_) + (tmp323_) * tmp90_) - (tmp326_) * tmp94_ + (tmp398_) * tmp96_ + (tmp325_) * tmp98_ + (tmp314_) * tmp99_ * (tmp83_) + (tmp325_) * tmp101_ + (tmp323_) * tmp102_ * (tmp85_) + (tmp326_) * tmp104_ + (tmp326_) * tmp105_ * (tmp83_) + (tmp325_) * tmp106_) * mLocScNorm;
  mCompDer[0][23] = (((tmp342_) * (tmp87_) + (tmp351_) * tmp90_) - (tmp354_) * tmp94_ + (tmp401_) * tmp96_ + (tmp353_) * tmp98_ + (tmp342_) * tmp99_ * (tmp83_) + (tmp353_) * tmp101_ + (tmp351_) * tmp102_ * (tmp85_) + (tmp354_) * tmp104_ + (tmp354_) * tmp105_ * (tmp83_) + (tmp353_) * tmp106_) * mLocScNorm;
  mVal[1] = ((((tmp355_) * (tmp79_) + tmp90_ * (tmp64_) + tmp93_ * tmp109_) - tmp359_ * (tmp83_) + tmp360_ * (tmp85_) + tmp362_ * (tmp85_) + tmp364_ * (tmp83_) + tmp366_ * (tmp83_)) - mLocYIm) * mLocScNorm;

  mCompDer[1][0] = ((tmp95_ * (tmp355_) + tmp91_ * tmp90_ + (tmp358_) * tmp93_) - (tmp100_) * tmp359_ + (tmp103_) * tmp360_ + tmp95_ * tmp361_ * (tmp85_) + (tmp103_) * tmp362_ + tmp91_ * tmp363_ * (tmp83_) + (tmp100_) * tmp364_ + (tmp103_) * tmp365_ * (tmp83_) + (tmp100_) * tmp366_) * mLocScNorm;
  mCompDer[1][1] = (tmp90_ + (tmp79_) * tmp93_ + (tmp107_) * tmp360_ + (tmp107_) * tmp362_ + tmp363_ * (tmp83_) + (tmp107_) * tmp365_ * (tmp83_)) * mLocScNorm;
  mCompDer[1][2] = ((tmp355_ + (tmp64_) * tmp93_) - (tmp108_) * tmp359_ + tmp361_ * (tmp85_) + (tmp108_) * tmp364_ + (tmp108_) * tmp366_) * mLocScNorm;
  mCompDer[1][3] = tmp110_ * (tmp79_) * mLocScNorm;
  mCompDer[1][4] = tmp367_;
  mCompDer[1][5] = tmp368_;
  mCompDer[1][6] = -(2 * (tmp83_)) * mLocScNorm;
  mCompDer[1][7] = 0;
  mCompDer[1][8] = (tmp85_) * mLocScNorm;
  mCompDer[1][9] = 0;
  mCompDer[1][10] = tmp370_;
  mCompDer[1][11] = 0;
  mCompDer[1][12] = tmp372_;
  mCompDer[1][13] = 0;
  mCompDer[1][14] = tmp374_;
  mCompDer[1][15] = (((tmp143_) * (tmp355_) + (tmp131_) * tmp90_ + (tmp377_) * tmp93_) - (tmp145_) * tmp359_ + (tmp146_) * tmp360_ + (tmp143_) * tmp361_ * (tmp85_) + (tmp146_) * tmp362_ + (tmp131_) * tmp363_ * (tmp83_) + (tmp145_) * tmp364_ + (tmp146_) * tmp365_ * (tmp83_) + (tmp145_) * tmp366_) * mLocScNorm;
  mCompDer[1][16] = (((tmp183_) * (tmp355_) + (tmp171_) * tmp90_ + (tmp380_) * tmp93_) - (tmp185_) * tmp359_ + (tmp186_) * tmp360_ + (tmp183_) * tmp361_ * (tmp85_) + (tmp186_) * tmp362_ + (tmp171_) * tmp363_ * (tmp83_) + (tmp185_) * tmp364_ + (tmp186_) * tmp365_ * (tmp83_) + (tmp185_) * tmp366_) * mLocScNorm;
  mCompDer[1][17] = (((tmp220_) * (tmp355_) + tmp204_ * tmp90_ + (tmp383_) * tmp93_) - (tmp222_) * tmp359_ + (tmp223_) * tmp360_ + (tmp220_) * tmp361_ * (tmp85_) + (tmp223_) * tmp362_ + tmp204_ * tmp363_ * (tmp83_) + (tmp222_) * tmp364_ + (tmp223_) * tmp365_ * (tmp83_) + (tmp222_) * tmp366_) * mLocScNorm;
  mCompDer[1][18] = (((tmp236_) * (tmp355_) + (tmp231_) * tmp90_ + (tmp386_) * tmp93_) - (tmp238_) * tmp359_ + (tmp239_) * tmp360_ + (tmp236_) * tmp361_ * (tmp85_) + (tmp239_) * tmp362_ + (tmp231_) * tmp363_ * (tmp83_) + (tmp238_) * tmp364_ + (tmp239_) * tmp365_ * (tmp83_) + (tmp238_) * tmp366_) * mLocScNorm;
  mCompDer[1][19] = (((tmp252_) * (tmp355_) + (tmp247_) * tmp90_ + (tmp389_) * tmp93_) - (tmp254_) * tmp359_ + (tmp255_) * tmp360_ + (tmp252_) * tmp361_ * (tmp85_) + (tmp255_) * tmp362_ + (tmp247_) * tmp363_ * (tmp83_) + (tmp254_) * tmp364_ + (tmp255_) * tmp365_ * (tmp83_) + (tmp254_) * tmp366_) * mLocScNorm;
  mCompDer[1][20] = (((tmp267_) * (tmp355_) + (tmp262_) * tmp90_ + (tmp392_) * tmp93_) - (tmp269_) * tmp359_ + (tmp270_) * tmp360_ + (tmp267_) * tmp361_ * (tmp85_) + (tmp270_) * tmp362_ + (tmp262_) * tmp363_ * (tmp83_) + (tmp269_) * tmp364_ + (tmp270_) * tmp365_ * (tmp83_) + (tmp269_) * tmp366_) * mLocScNorm;
  mCompDer[1][21] = (((tmp295_) * (tmp355_) + (tmp286_) * tmp90_ + (tmp395_) * tmp93_) - (tmp297_) * tmp359_ + (tmp298_) * tmp360_ + (tmp295_) * tmp361_ * (tmp85_) + (tmp298_) * tmp362_ + (tmp286_) * tmp363_ * (tmp83_) + (tmp297_) * tmp364_ + (tmp298_) * tmp365_ * (tmp83_) + (tmp297_) * tmp366_) * mLocScNorm;
  mCompDer[1][22] = (((tmp323_) * (tmp355_) + (tmp314_) * tmp90_ + (tmp398_) * tmp93_) - (tmp325_) * tmp359_ + (tmp326_) * tmp360_ + (tmp323_) * tmp361_ * (tmp85_) + (tmp326_) * tmp362_ + (tmp314_) * tmp363_ * (tmp83_) + (tmp325_) * tmp364_ + (tmp326_) * tmp365_ * (tmp83_) + (tmp325_) * tmp366_) * mLocScNorm;
  mCompDer[1][23] = (((tmp351_) * (tmp355_) + (tmp342_) * tmp90_ + (tmp401_) * tmp93_) - (tmp353_) * tmp359_ + (tmp354_) * tmp360_ + (tmp351_) * tmp361_ * (tmp85_) + (tmp354_) * tmp362_ + (tmp342_) * tmp363_ * (tmp83_) + (tmp353_) * tmp364_ + (tmp354_) * tmp365_ * (tmp83_) + (tmp353_) * tmp366_) * mLocScNorm;
}


void cEqAppui_PProjInc_M2CEbner::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cEqAppui_PProjInc_M2CEbner Has no Der Sec");
}

void cEqAppui_PProjInc_M2CEbner::SetEbner_State_0_0(double aVal){ mLocEbner_State_0_0 = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetProjI_x(double aVal){ mLocProjI_x = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetProjI_y(double aVal){ mLocProjI_y = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetProjI_z(double aVal){ mLocProjI_z = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetProjJ_x(double aVal){ mLocProjJ_x = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetProjJ_y(double aVal){ mLocProjJ_y = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetProjJ_z(double aVal){ mLocProjJ_z = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetProjK_x(double aVal){ mLocProjK_x = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetProjK_y(double aVal){ mLocProjK_y = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetProjK_z(double aVal){ mLocProjK_z = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetProjP0_x(double aVal){ mLocProjP0_x = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetProjP0_y(double aVal){ mLocProjP0_y = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetProjP0_z(double aVal){ mLocProjP0_z = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetScNorm(double aVal){ mLocScNorm = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetXIm(double aVal){ mLocXIm = aVal;}
void cEqAppui_PProjInc_M2CEbner::SetYIm(double aVal){ mLocYIm = aVal;}



double * cEqAppui_PProjInc_M2CEbner::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "Ebner_State_0_0") return & mLocEbner_State_0_0;
   if (aName == "ProjI_x") return & mLocProjI_x;
   if (aName == "ProjI_y") return & mLocProjI_y;
   if (aName == "ProjI_z") return & mLocProjI_z;
   if (aName == "ProjJ_x") return & mLocProjJ_x;
   if (aName == "ProjJ_y") return & mLocProjJ_y;
   if (aName == "ProjJ_z") return & mLocProjJ_z;
   if (aName == "ProjK_x") return & mLocProjK_x;
   if (aName == "ProjK_y") return & mLocProjK_y;
   if (aName == "ProjK_z") return & mLocProjK_z;
   if (aName == "ProjP0_x") return & mLocProjP0_x;
   if (aName == "ProjP0_y") return & mLocProjP0_y;
   if (aName == "ProjP0_z") return & mLocProjP0_z;
   if (aName == "ScNorm") return & mLocScNorm;
   if (aName == "XIm") return & mLocXIm;
   if (aName == "YIm") return & mLocYIm;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cEqAppui_PProjInc_M2CEbner::mTheAuto("cEqAppui_PProjInc_M2CEbner",cEqAppui_PProjInc_M2CEbner::Alloc);


cElCompiledFonc *  cEqAppui_PProjInc_M2CEbner::Alloc()
{  return new cEqAppui_PProjInc_M2CEbner();
}


