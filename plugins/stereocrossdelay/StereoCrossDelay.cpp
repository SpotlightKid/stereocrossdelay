
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
#include <cstdint>
#include <math.h>
FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

static float mydsp_faustpower2_f(float value) {
	return value * value;
}

class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec3[2];
	float fConst3;
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	float fRec6[3];
	float fRec4[3];
	FAUSTFLOAT fHslider3;
	float fRec7[2];
	int IOTA0;
	float fVec0[1048576];
	float fConst4;
	FAUSTFLOAT fHslider4;
	float fRec12[2];
	FAUSTFLOAT fHslider5;
	float fConst5;
	float fRec8[2];
	float fRec9[2];
	float fRec10[2];
	float fRec11[2];
	FAUSTFLOAT fHslider6;
	float fRec13[2];
	float fRec15[3];
	float fRec14[3];
	float fVec1[524288];
	float fConst6;
	float fRec16[2];
	float fRec17[2];
	float fRec18[2];
	float fRec19[2];
	float fRec1[2];
	float fRec2[2];
	FAUSTFLOAT fHslider7;
	float fRec20[2];
	
 public:
	mydsp() {
	}
	
	void metadata(Meta* m) { 
		m->declare("author", "Christopher Arndt");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.19.1");
		m->declare("compile_options", "-a /home/chris/tmp/tmp9oto1ddl.cpp -lang cpp -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
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
		m->declare("filters.lib/version", "1.3.0");
		m->declare("license", "MIT license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "StereoCrossDelay");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 2;
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 3.1415927f / fConst0;
		fConst4 = 4.0f * fConst0;
		fConst5 = 0.001f * fConst0;
		fConst6 = 2.0f * fConst0;
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(-6.0f);
		fHslider1 = FAUSTFLOAT(1.2e+04f);
		fHslider2 = FAUSTFLOAT(6e+01f);
		fHslider3 = FAUSTFLOAT(2e+01f);
		fHslider4 = FAUSTFLOAT(5e+02f);
		fHslider5 = FAUSTFLOAT(0.75f);
		fHslider6 = FAUSTFLOAT(25.0f);
		fHslider7 = FAUSTFLOAT(0.0f);
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec3[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec5[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 3; l3 = l3 + 1) {
			fRec6[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 3; l4 = l4 + 1) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec7[l5] = 0.0f;
		}
		IOTA0 = 0;
		for (int l6 = 0; l6 < 1048576; l6 = l6 + 1) {
			fVec0[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec12[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec8[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec9[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec10[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec11[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec13[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = l13 + 1) {
			fRec15[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 3; l14 = l14 + 1) {
			fRec14[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 524288; l15 = l15 + 1) {
			fVec1[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec16[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec17[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec18[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec19[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec1[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec2[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
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
		ui_interface->declare(&fHslider4, "0", "");
		ui_interface->declare(&fHslider4, "symbol", "delay_l");
		ui_interface->declare(&fHslider4, "unit", "ms");
		ui_interface->addHorizontalSlider("Delay L", &fHslider4, FAUSTFLOAT(5e+02f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+03f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider5, "1", "");
		ui_interface->declare(&fHslider5, "style", "menu{'1:1':1;'1:2':2;'2:1':0.5;}");
		ui_interface->declare(&fHslider5, "symbol", "delay_r");
		ui_interface->addHorizontalSlider("Delay R Ratio", &fHslider5, FAUSTFLOAT(0.75f), FAUSTFLOAT(0.001f), FAUSTFLOAT(2.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->declare(&fHslider3, "symbol", "feedback");
		ui_interface->declare(&fHslider3, "unit", "%");
		ui_interface->addHorizontalSlider("Feedback", &fHslider3, FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->declare(&fHslider1, "scale", "log");
		ui_interface->declare(&fHslider1, "symbol", "lp_cutoff");
		ui_interface->declare(&fHslider1, "unit", "hz");
		ui_interface->addHorizontalSlider("Lowpass", &fHslider1, FAUSTFLOAT(1.2e+04f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider2, "4", "");
		ui_interface->declare(&fHslider2, "scale", "log");
		ui_interface->declare(&fHslider2, "symbol", "hp_cutoff");
		ui_interface->declare(&fHslider2, "unit", "hz");
		ui_interface->addHorizontalSlider("Highpass", &fHslider2, FAUSTFLOAT(6e+01f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider6, "5", "");
		ui_interface->declare(&fHslider6, "symbol", "crossmix");
		ui_interface->declare(&fHslider6, "unit", "%");
		ui_interface->addHorizontalSlider("Crossmix", &fHslider6, FAUSTFLOAT(25.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider7, "6", "");
		ui_interface->declare(&fHslider7, "symbol", "dry");
		ui_interface->declare(&fHslider7, "unit", "db");
		ui_interface->addHorizontalSlider("Dry", &fHslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(-9e+01f), FAUSTFLOAT(6.0f), FAUSTFLOAT(0.1f));
		ui_interface->declare(&fHslider0, "7", "");
		ui_interface->declare(&fHslider0, "symbol", "wet");
		ui_interface->declare(&fHslider0, "unit", "db");
		ui_interface->addHorizontalSlider("Wet", &fHslider0, FAUSTFLOAT(-6.0f), FAUSTFLOAT(-9e+01f), FAUSTFLOAT(6.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = fConst1 * float(fHslider0);
		float fSlow1 = fConst1 * float(fHslider1);
		float fSlow2 = fConst1 * float(fHslider2);
		float fSlow3 = fConst1 * float(fHslider3);
		float fSlow4 = fConst1 * float(fHslider4);
		float fSlow5 = fConst5 * float(fHslider5);
		float fSlow6 = fConst1 * float(fHslider6);
		float fSlow7 = fConst1 * float(fHslider7);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			float fTemp0 = std::pow(1e+01f, 0.05f * fRec0[0]);
			fRec3[0] = fSlow1 + fConst2 * fRec3[1];
			float fTemp1 = std::tan(fConst3 * fRec3[0]);
			float fTemp2 = 1.0f / fTemp1;
			float fTemp3 = (fTemp2 + 1.4142135f) / fTemp1 + 1.0f;
			float fTemp4 = 1.0f - 1.0f / mydsp_faustpower2_f(fTemp1);
			float fTemp5 = (fTemp2 + -1.4142135f) / fTemp1 + 1.0f;
			fRec5[0] = fSlow2 + fConst2 * fRec5[1];
			float fTemp6 = std::tan(fConst3 * fRec5[0]);
			float fTemp7 = 1.0f / fTemp6;
			float fTemp8 = (fTemp7 + 1.4142135f) / fTemp6 + 1.0f;
			float fTemp9 = mydsp_faustpower2_f(fTemp6);
			float fTemp10 = fTemp9 * fTemp8;
			float fTemp11 = 1.0f - 1.0f / fTemp9;
			float fTemp12 = (fTemp7 + -1.4142135f) / fTemp6 + 1.0f;
			fRec6[0] = fRec2[1] - (fTemp12 * fRec6[2] + 2.0f * fTemp11 * fRec6[1]) / fTemp8;
			fRec4[0] = (fRec6[2] + (fRec6[0] - 2.0f * fRec6[1])) / fTemp10 - (fTemp5 * fRec4[2] + 2.0f * fTemp4 * fRec4[1]) / fTemp3;
			fRec7[0] = fSlow3 + fConst2 * fRec7[1];
			float fTemp13 = float(input1[i0]);
			float fTemp14 = fTemp13 + 0.01f * (fRec7[0] * (fRec4[2] + fRec4[0] + 2.0f * fRec4[1]) / fTemp3);
			fVec0[IOTA0 & 1048575] = fTemp14;
			fRec12[0] = fSlow4 + fConst2 * fRec12[1];
			float fTemp15 = fSlow5 * fRec12[0];
			float fTemp16 = ((fRec8[1] != 0.0f) ? (((fRec9[1] > 0.0f) & (fRec9[1] < 1.0f)) ? fRec8[1] : 0.0f) : (((fRec9[1] == 0.0f) & (fTemp15 != fRec10[1])) ? 0.001953125f : (((fRec9[1] == 1.0f) & (fTemp15 != fRec11[1])) ? -0.001953125f : 0.0f)));
			fRec8[0] = fTemp16;
			fRec9[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec9[1] + fTemp16));
			fRec10[0] = (((fRec9[1] >= 1.0f) & (fRec11[1] != fTemp15)) ? fTemp15 : fRec10[1]);
			fRec11[0] = (((fRec9[1] <= 0.0f) & (fRec10[1] != fTemp15)) ? fTemp15 : fRec11[1]);
			float fTemp17 = fVec0[(IOTA0 - int(std::min<float>(fConst4, std::max<float>(0.0f, fRec10[0])))) & 1048575];
			float fTemp18 = fTemp17 + fRec9[0] * (fVec0[(IOTA0 - int(std::min<float>(fConst4, std::max<float>(0.0f, fRec11[0])))) & 1048575] - fTemp17);
			fRec13[0] = fSlow6 + fConst2 * fRec13[1];
			float fTemp19 = 1.0f - 0.01f * fRec13[0];
			fRec15[0] = fRec1[1] - (fRec15[2] * fTemp12 + 2.0f * fRec15[1] * fTemp11) / fTemp8;
			fRec14[0] = (fRec15[2] + (fRec15[0] - 2.0f * fRec15[1])) / fTemp10 - (fRec14[2] * fTemp5 + 2.0f * fRec14[1] * fTemp4) / fTemp3;
			float fTemp20 = float(input0[i0]);
			float fTemp21 = fTemp20 + 0.01f * (fRec7[0] * (fRec14[2] + fRec14[0] + 2.0f * fRec14[1]) / fTemp3);
			fVec1[IOTA0 & 524287] = fTemp21;
			float fTemp22 = fConst5 * fRec12[0];
			float fTemp23 = ((fRec16[1] != 0.0f) ? (((fRec17[1] > 0.0f) & (fRec17[1] < 1.0f)) ? fRec16[1] : 0.0f) : (((fRec17[1] == 0.0f) & (fTemp22 != fRec18[1])) ? 0.001953125f : (((fRec17[1] == 1.0f) & (fTemp22 != fRec19[1])) ? -0.001953125f : 0.0f)));
			fRec16[0] = fTemp23;
			fRec17[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec17[1] + fTemp23));
			fRec18[0] = (((fRec17[1] >= 1.0f) & (fRec19[1] != fTemp22)) ? fTemp22 : fRec18[1]);
			fRec19[0] = (((fRec17[1] <= 0.0f) & (fRec18[1] != fTemp22)) ? fTemp22 : fRec19[1]);
			float fTemp24 = fVec1[(IOTA0 - int(std::min<float>(fConst6, std::max<float>(0.0f, fRec18[0])))) & 524287];
			float fTemp25 = fTemp24 + fRec17[0] * (fVec1[(IOTA0 - int(std::min<float>(fConst6, std::max<float>(0.0f, fRec19[0])))) & 524287] - fTemp24);
			fRec1[0] = fTemp25 * fTemp19 + 0.01f * fRec13[0] * fTemp18;
			fRec2[0] = fTemp19 * fTemp18 + 0.01f * fRec13[0] * fTemp25;
			fRec20[0] = fSlow7 + fConst2 * fRec20[1];
			float fTemp26 = std::pow(1e+01f, 0.05f * fRec20[0]);
			output0[i0] = FAUSTFLOAT(fTemp20 * fTemp26 + fRec1[0] * fTemp0);
			output1[i0] = FAUSTFLOAT(fTemp13 * fTemp26 + fRec2[0] * fTemp0);
			fRec0[1] = fRec0[0];
			fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec7[1] = fRec7[0];
			IOTA0 = IOTA0 + 1;
			fRec12[1] = fRec12[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec13[1] = fRec13[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec18[1] = fRec18[0];
			fRec19[1] = fRec19[0];
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
        return "Dry";
    
    case 7:
        return "Wet";
    
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
        return "dry";
    
    case 7:
        return "wet";
    
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
        static const ParameterRange range = { 500.0, 0.0, 2000.0 };
        return &range;
    }
    
    case 1: {
        static const ParameterRange range = { 0.75, 0.001, 2.0 };
        return &range;
    }
    
    case 2: {
        static const ParameterRange range = { 20.0, 0.0, 100.0 };
        return &range;
    }
    
    case 3: {
        static const ParameterRange range = { 12000.0, 20.0, 20000.0 };
        return &range;
    }
    
    case 4: {
        static const ParameterRange range = { 60.0, 20.0, 20000.0 };
        return &range;
    }
    
    case 5: {
        static const ParameterRange range = { 25.0, 0.0, 100.0 };
        return &range;
    }
    
    case 6: {
        static const ParameterRange range = { 0.0, -90.0, 6.0 };
        return &range;
    }
    
    case 7: {
        static const ParameterRange range = { -6.0, -90.0, 6.0 };
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
        return dsp.fHslider4;
    
    case 1:
        return dsp.fHslider5;
    
    case 2:
        return dsp.fHslider3;
    
    case 3:
        return dsp.fHslider1;
    
    case 4:
        return dsp.fHslider2;
    
    case 5:
        return dsp.fHslider6;
    
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
        dsp.fHslider4 = value;
        break;
    
    case 1:
        dsp.fHslider5 = value;
        break;
    
    case 2:
        dsp.fHslider3 = value;
        break;
    
    case 3:
        dsp.fHslider1 = value;
        break;
    
    case 4:
        dsp.fHslider2 = value;
        break;
    
    case 5:
        dsp.fHslider6 = value;
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
    return dsp.fHslider4;
}

float StereoCrossDelay::get_delay_r() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider5;
}

float StereoCrossDelay::get_feedback() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider3;
}

float StereoCrossDelay::get_lp_cutoff() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider1;
}

float StereoCrossDelay::get_hp_cutoff() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider2;
}

float StereoCrossDelay::get_crossmix() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider6;
}

float StereoCrossDelay::get_dry() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider7;
}

float StereoCrossDelay::get_wet() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}


void StereoCrossDelay::set_delay_l(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider4 = value;
}

void StereoCrossDelay::set_delay_r(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider5 = value;
}

void StereoCrossDelay::set_feedback(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider3 = value;
}

void StereoCrossDelay::set_lp_cutoff(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider1 = value;
}

void StereoCrossDelay::set_hp_cutoff(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider2 = value;
}

void StereoCrossDelay::set_crossmix(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider6 = value;
}

void StereoCrossDelay::set_dry(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider7 = value;
}

void StereoCrossDelay::set_wet(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}



