
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: stereocrossdelay.dsp
// Name: StereoCrossDelay
// Author: Christopher Arndt
// Copyright: 
// License: MIT license
// Version: 
//------------------------------------------------------------------------------







#include "StereoCrossDelay.hpp"



#include <utility>
#include <cmath>

class StereoCrossDelay::BasicDsp {
public:
    virtual ~BasicDsp() {}
};

//------------------------------------------------------------------------------
// Begin the Faust code section

namespace {

template <class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template <class T> inline T max(T a, T b) { return (a > b) ? a : b; }

class Meta {
public:
    // dummy
    void declare(...) {}
};

class UI {
public:
    // dummy
    void openHorizontalBox(...) {}
    void openVerticalBox(...) {}
    void closeBox(...) {}
    void declare(...) {}
    void addButton(...) {}
    void addCheckButton(...) {}
    void addVerticalSlider(...) {}
    void addHorizontalSlider(...) {}
    void addVerticalBargraph(...) {}
    void addHorizontalBargraph(...) {}
};

typedef StereoCrossDelay::BasicDsp dsp;

} // namespace

#define FAUSTPP_VIRTUAL // do not declare any methods virtual
#define FAUSTPP_PRIVATE public // do not hide any members
#define FAUSTPP_PROTECTED public // do not hide any members

// define the DSP in the anonymous namespace
#define FAUSTPP_BEGIN_NAMESPACE namespace {
#define FAUSTPP_END_NAMESPACE }


#if defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifndef FAUSTPP_PRIVATE
#   define FAUSTPP_PRIVATE private
#endif
#ifndef FAUSTPP_PROTECTED
#   define FAUSTPP_PROTECTED protected
#endif
#ifndef FAUSTPP_VIRTUAL
#   define FAUSTPP_VIRTUAL virtual
#endif

#ifndef FAUSTPP_BEGIN_NAMESPACE
#   define FAUSTPP_BEGIN_NAMESPACE
#endif
#ifndef FAUSTPP_END_NAMESPACE
#   define FAUSTPP_END_NAMESPACE
#endif

FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

FAUSTPP_END_NAMESPACE
#include <algorithm>
#include <cmath>
#include <math.h>
FAUSTPP_BEGIN_NAMESPACE

static float mydsp_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fRec7[2];
	float fRec3[2];
	float fRec4[2];
	float fRec5[2];
	float fRec6[2];
	FAUSTFLOAT fHslider2;
	float fRec8[2];
	float fConst2;
	FAUSTFLOAT fHslider3;
	float fRec11[2];
	float fRec10[3];
	FAUSTFLOAT fHslider4;
	float fRec12[2];
	float fRec9[3];
	int IOTA;
	float fVec0[524288];
	float fConst3;
	FAUSTFLOAT fHslider5;
	float fRec13[2];
	FAUSTFLOAT fHslider6;
	float fRec14[2];
	float fRec15[2];
	float fRec16[2];
	float fRec17[2];
	float fRec19[3];
	float fRec18[3];
	float fVec1[1048576];
	float fConst4;
	float fRec1[2];
	float fRec2[2];
	FAUSTFLOAT fHslider7;
	float fRec20[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "Christopher Arndt");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.1");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.1");
		m->declare("description", "A stereo delay with feedback and cross-over mixing");
		m->declare("filename", "stereocrossdelay.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("license", "MIT license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.3");
		m->declare("name", "StereoCrossDelay");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.1");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 2;
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 2;
	}
	FAUSTPP_VIRTUAL int getInputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	FAUSTPP_VIRTUAL int getOutputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	
	static void classInit(int sample_rate) {
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (0.00100000005f * fConst0);
		fConst2 = (3.14159274f / fConst0);
		fConst3 = (2.0f * fConst0);
		fConst4 = (4.0f * fConst0);
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(500.0f);
		fHslider2 = FAUSTFLOAT(20.0f);
		fHslider3 = FAUSTFLOAT(60.0f);
		fHslider4 = FAUSTFLOAT(12000.0f);
		fHslider5 = FAUSTFLOAT(25.0f);
		fHslider6 = FAUSTFLOAT(0.75f);
		fHslider7 = FAUSTFLOAT(-6.0f);
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec7[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec4[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec6[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec8[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec11[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
			fRec10[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec12[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
		}
		IOTA = 0;
		for (int l11 = 0; (l11 < 524288); l11 = (l11 + 1)) {
			fVec0[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec13[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec14[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec15[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec16[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec17[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec19[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec18[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 1048576); l19 = (l19 + 1)) {
			fVec1[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec1[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec2[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec20[l22] = 0.0f;
		}
	}
	
	FAUSTPP_VIRTUAL void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	FAUSTPP_VIRTUAL void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FAUSTPP_VIRTUAL mydsp* clone() {
		return new mydsp();
	}
	
	FAUSTPP_VIRTUAL int getSampleRate() {
		return fSampleRate;
	}
	
	FAUSTPP_VIRTUAL void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("StereoCrossDelay");
		ui_interface->declare(&fHslider1, "0", "");
		ui_interface->declare(&fHslider1, "symbol", "delay_l");
		ui_interface->declare(&fHslider1, "unit", "ms");
		ui_interface->addHorizontalSlider("Delay L", &fHslider1, 500.0f, 0.0f, 2000.0f, 0.100000001f);
		ui_interface->declare(&fHslider6, "1", "");
		ui_interface->declare(&fHslider6, "style", "menu{'1:1':1;'1:2':2;'2:1':0.5;'}");
		ui_interface->declare(&fHslider6, "symbol", "delay_r");
		ui_interface->addHorizontalSlider("Delay R Ratio", &fHslider6, 0.75f, 0.00100000005f, 2.0f, 0.00999999978f);
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "symbol", "feedback");
		ui_interface->declare(&fHslider2, "unit", "%");
		ui_interface->addHorizontalSlider("Feedback", &fHslider2, 20.0f, 0.0f, 100.0f, 0.100000001f);
		ui_interface->declare(&fHslider4, "3", "");
		ui_interface->declare(&fHslider4, "scale", "log");
		ui_interface->declare(&fHslider4, "symbol", "lp_cutoff");
		ui_interface->declare(&fHslider4, "unit", "hz");
		ui_interface->addHorizontalSlider("Lowpass", &fHslider4, 12000.0f, 20.0f, 20000.0f, 0.100000001f);
		ui_interface->declare(&fHslider3, "4", "");
		ui_interface->declare(&fHslider3, "scale", "log");
		ui_interface->declare(&fHslider3, "symbol", "hp_cutoff");
		ui_interface->declare(&fHslider3, "unit", "hz");
		ui_interface->addHorizontalSlider("Highpass", &fHslider3, 60.0f, 20.0f, 20000.0f, 0.100000001f);
		ui_interface->declare(&fHslider5, "5", "");
		ui_interface->declare(&fHslider5, "symbol", "crossmix");
		ui_interface->declare(&fHslider5, "unit", "%");
		ui_interface->addHorizontalSlider("Crossmix", &fHslider5, 25.0f, 0.0f, 100.0f, 0.100000001f);
		ui_interface->declare(&fHslider7, "6", "");
		ui_interface->declare(&fHslider7, "symbol", "wet");
		ui_interface->declare(&fHslider7, "unit", "db");
		ui_interface->addHorizontalSlider("Wet", &fHslider7, -6.0f, -90.0f, 6.0f, 0.100000001f);
		ui_interface->declare(&fHslider0, "7", "");
		ui_interface->declare(&fHslider0, "symbol", "dry");
		ui_interface->declare(&fHslider0, "unit", "db");
		ui_interface->addHorizontalSlider("Dry", &fHslider0, 0.0f, -90.0f, 6.0f, 0.100000001f);
		ui_interface->closeBox();
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = (0.00100000005f * float(fHslider0));
		float fSlow1 = (0.00100000005f * float(fHslider1));
		float fSlow2 = (0.00100000005f * float(fHslider2));
		float fSlow3 = (0.00100000005f * float(fHslider3));
		float fSlow4 = (0.00100000005f * float(fHslider4));
		float fSlow5 = (0.00100000005f * float(fHslider5));
		float fSlow6 = (fConst1 * float(fHslider6));
		float fSlow7 = (0.00100000005f * float(fHslider7));
		for (int i = 0; (i < count); i = (i + 1)) {
			float fTemp0 = float(input0[i]);
			fRec0[0] = (fSlow0 + (0.999000013f * fRec0[1]));
			float fTemp1 = std::pow(10.0f, (0.0500000007f * fRec0[0]));
			fRec7[0] = (fSlow1 + (0.999000013f * fRec7[1]));
			float fTemp2 = (fConst1 * fRec7[0]);
			float fTemp3 = ((fRec3[1] != 0.0f) ? (((fRec4[1] > 0.0f) & (fRec4[1] < 1.0f)) ? fRec3[1] : 0.0f) : (((fRec4[1] == 0.0f) & (fTemp2 != fRec5[1])) ? 0.001953125f : (((fRec4[1] == 1.0f) & (fTemp2 != fRec6[1])) ? -0.001953125f : 0.0f)));
			fRec3[0] = fTemp3;
			fRec4[0] = std::max<float>(0.0f, std::min<float>(1.0f, (fRec4[1] + fTemp3)));
			fRec5[0] = (((fRec4[1] >= 1.0f) & (fRec6[1] != fTemp2)) ? fTemp2 : fRec5[1]);
			fRec6[0] = (((fRec4[1] <= 0.0f) & (fRec5[1] != fTemp2)) ? fTemp2 : fRec6[1]);
			fRec8[0] = (fSlow2 + (0.999000013f * fRec8[1]));
			fRec11[0] = (fSlow3 + (0.999000013f * fRec11[1]));
			float fTemp4 = std::tan((fConst2 * fRec11[0]));
			float fTemp5 = (1.0f / fTemp4);
			float fTemp6 = (((fTemp5 + -1.41421354f) / fTemp4) + 1.0f);
			float fTemp7 = mydsp_faustpower2_f(fTemp4);
			float fTemp8 = (1.0f - (1.0f / fTemp7));
			float fTemp9 = (((fTemp5 + 1.41421354f) / fTemp4) + 1.0f);
			fRec10[0] = (fRec1[1] - (((fRec10[2] * fTemp6) + (2.0f * (fRec10[1] * fTemp8))) / fTemp9));
			float fTemp10 = (0.0f - (2.0f / fTemp7));
			fRec12[0] = (fSlow4 + (0.999000013f * fRec12[1]));
			float fTemp11 = std::tan((fConst2 * fRec12[0]));
			float fTemp12 = (1.0f / fTemp11);
			float fTemp13 = (((fTemp12 + -1.41421354f) / fTemp11) + 1.0f);
			float fTemp14 = (1.0f - (1.0f / mydsp_faustpower2_f(fTemp11)));
			float fTemp15 = (((fTemp12 + 1.41421354f) / fTemp11) + 1.0f);
			fRec9[0] = (((((fRec10[1] * fTemp10) + (fRec10[0] / fTemp7)) + (fRec10[2] / fTemp7)) / fTemp9) - (((fRec9[2] * fTemp13) + (2.0f * (fRec9[1] * fTemp14))) / fTemp15));
			float fTemp16 = (fTemp0 + (0.00999999978f * ((fRec8[0] * (fRec9[2] + (fRec9[0] + (2.0f * fRec9[1])))) / fTemp15)));
			fVec0[(IOTA & 524287)] = fTemp16;
			float fTemp17 = (((1.0f - fRec4[0]) * fVec0[((IOTA - int(std::min<float>(fConst3, std::max<float>(0.0f, fRec5[0])))) & 524287)]) + (fRec4[0] * fVec0[((IOTA - int(std::min<float>(fConst3, std::max<float>(0.0f, fRec6[0])))) & 524287)]));
			fRec13[0] = (fSlow5 + (0.999000013f * fRec13[1]));
			float fTemp18 = (1.0f - (0.00999999978f * fRec13[0]));
			float fTemp19 = (fSlow6 * fRec7[0]);
			float fTemp20 = ((fRec14[1] != 0.0f) ? (((fRec15[1] > 0.0f) & (fRec15[1] < 1.0f)) ? fRec14[1] : 0.0f) : (((fRec15[1] == 0.0f) & (fTemp19 != fRec16[1])) ? 0.001953125f : (((fRec15[1] == 1.0f) & (fTemp19 != fRec17[1])) ? -0.001953125f : 0.0f)));
			fRec14[0] = fTemp20;
			fRec15[0] = std::max<float>(0.0f, std::min<float>(1.0f, (fRec15[1] + fTemp20)));
			fRec16[0] = (((fRec15[1] >= 1.0f) & (fRec17[1] != fTemp19)) ? fTemp19 : fRec16[1]);
			fRec17[0] = (((fRec15[1] <= 0.0f) & (fRec16[1] != fTemp19)) ? fTemp19 : fRec17[1]);
			float fTemp21 = float(input1[i]);
			fRec19[0] = (fRec2[1] - (((fTemp6 * fRec19[2]) + (2.0f * (fTemp8 * fRec19[1]))) / fTemp9));
			fRec18[0] = (((((fTemp10 * fRec19[1]) + (fRec19[0] / fTemp7)) + (fRec19[2] / fTemp7)) / fTemp9) - (((fTemp13 * fRec18[2]) + (2.0f * (fTemp14 * fRec18[1]))) / fTemp15));
			float fTemp22 = (fTemp21 + (0.00999999978f * ((fRec8[0] * (fRec18[2] + (fRec18[0] + (2.0f * fRec18[1])))) / fTemp15)));
			fVec1[(IOTA & 1048575)] = fTemp22;
			float fTemp23 = (((1.0f - fRec15[0]) * fVec1[((IOTA - int(std::min<float>(fConst4, std::max<float>(0.0f, fRec16[0])))) & 1048575)]) + (fRec15[0] * fVec1[((IOTA - int(std::min<float>(fConst4, std::max<float>(0.0f, fRec17[0])))) & 1048575)]));
			fRec1[0] = ((fTemp17 * fTemp18) + (0.00999999978f * (fRec13[0] * fTemp23)));
			fRec2[0] = ((fTemp18 * fTemp23) + (0.00999999978f * (fRec13[0] * fTemp17)));
			fRec20[0] = (fSlow7 + (0.999000013f * fRec20[1]));
			float fTemp24 = std::pow(10.0f, (0.0500000007f * fRec20[0]));
			output0[i] = FAUSTFLOAT(((fTemp0 * fTemp1) + (fRec1[0] * fTemp24)));
			output1[i] = FAUSTFLOAT(((fTemp21 * fTemp1) + (fRec2[0] * fTemp24)));
			fRec0[1] = fRec0[0];
			fRec7[1] = fRec7[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec8[1] = fRec8[0];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec12[1] = fRec12[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			IOTA = (IOTA + 1);
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec20[1] = fRec20[0];
		}
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif



//------------------------------------------------------------------------------
// End the Faust code section




StereoCrossDelay::StereoCrossDelay()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

StereoCrossDelay::~StereoCrossDelay()
{
}

void StereoCrossDelay::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void StereoCrossDelay::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void StereoCrossDelay::process(
    const float *in0,const float *in1,
    float *out0,float *out1,
    unsigned count) noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    float *inputs[] = {
        const_cast<float *>(in0),const_cast<float *>(in1),
    };
    float *outputs[] = {
        out0,out1,
    };
    dsp.compute(count, inputs, outputs);

}

const char *StereoCrossDelay::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "Delay L";
    
    case 1:
        return "Delay R Ratio";
    
    case 2:
        return "Feedback";
    
    case 3:
        return "Lowpass";
    
    case 4:
        return "Highpass";
    
    case 5:
        return "Crossmix";
    
    case 6:
        return "Wet";
    
    case 7:
        return "Dry";
    
    default:
        return 0;
    }
}

const char *StereoCrossDelay::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    case 3:
        return "";
    
    case 4:
        return "";
    
    case 5:
        return "";
    
    case 6:
        return "";
    
    case 7:
        return "";
    
    default:
        return 0;
    }
}

const char *StereoCrossDelay::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "delay_l";
    
    case 1:
        return "delay_r";
    
    case 2:
        return "feedback";
    
    case 3:
        return "lp_cutoff";
    
    case 4:
        return "hp_cutoff";
    
    case 5:
        return "crossmix";
    
    case 6:
        return "wet";
    
    case 7:
        return "dry";
    
    default:
        return 0;
    }
}

const char *StereoCrossDelay::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "ms";
    
    case 1:
        return "";
    
    case 2:
        return "%";
    
    case 3:
        return "hz";
    
    case 4:
        return "hz";
    
    case 5:
        return "%";
    
    case 6:
        return "db";
    
    case 7:
        return "db";
    
    default:
        return 0;
    }
}

const StereoCrossDelay::ParameterRange *StereoCrossDelay::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 500, 0, 2000 };
        return &range;
    }
    
    case 1: {
        static const ParameterRange range = { 0.75, 0.001, 2 };
        return &range;
    }
    
    case 2: {
        static const ParameterRange range = { 20, 0, 100 };
        return &range;
    }
    
    case 3: {
        static const ParameterRange range = { 12000, 20, 20000 };
        return &range;
    }
    
    case 4: {
        static const ParameterRange range = { 60, 20, 20000 };
        return &range;
    }
    
    case 5: {
        static const ParameterRange range = { 25, 0, 100 };
        return &range;
    }
    
    case 6: {
        static const ParameterRange range = { -6, -90, 6 };
        return &range;
    }
    
    case 7: {
        static const ParameterRange range = { 0, -90, 6 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool StereoCrossDelay::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool StereoCrossDelay::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool StereoCrossDelay::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool StereoCrossDelay::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    case 3:
        return true;
    
    case 4:
        return true;
    
    default:
        return false;
    }
}

float StereoCrossDelay::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        return dsp.fHslider1;
    
    case 1:
        return dsp.fHslider6;
    
    case 2:
        return dsp.fHslider2;
    
    case 3:
        return dsp.fHslider4;
    
    case 4:
        return dsp.fHslider3;
    
    case 5:
        return dsp.fHslider5;
    
    case 6:
        return dsp.fHslider7;
    
    case 7:
        return dsp.fHslider0;
    
    default:
        (void)dsp;
        return 0;
    }
}

void StereoCrossDelay::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        dsp.fHslider1 = value;
        break;
    
    case 1:
        dsp.fHslider6 = value;
        break;
    
    case 2:
        dsp.fHslider2 = value;
        break;
    
    case 3:
        dsp.fHslider4 = value;
        break;
    
    case 4:
        dsp.fHslider3 = value;
        break;
    
    case 5:
        dsp.fHslider5 = value;
        break;
    
    case 6:
        dsp.fHslider7 = value;
        break;
    
    case 7:
        dsp.fHslider0 = value;
        break;
    
    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float StereoCrossDelay::get_delay_l() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider1;
}

float StereoCrossDelay::get_delay_r() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider6;
}

float StereoCrossDelay::get_feedback() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider2;
}

float StereoCrossDelay::get_lp_cutoff() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider4;
}

float StereoCrossDelay::get_hp_cutoff() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider3;
}

float StereoCrossDelay::get_crossmix() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider5;
}

float StereoCrossDelay::get_wet() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider7;
}

float StereoCrossDelay::get_dry() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}


void StereoCrossDelay::set_delay_l(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider1 = value;
}

void StereoCrossDelay::set_delay_r(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider6 = value;
}

void StereoCrossDelay::set_feedback(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider2 = value;
}

void StereoCrossDelay::set_lp_cutoff(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider4 = value;
}

void StereoCrossDelay::set_hp_cutoff(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider3 = value;
}

void StereoCrossDelay::set_crossmix(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider5 = value;
}

void StereoCrossDelay::set_wet(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider7 = value;
}

void StereoCrossDelay::set_dry(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}




