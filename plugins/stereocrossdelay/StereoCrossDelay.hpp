
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






#pragma once
#ifndef StereoCrossDelay_Faust_pp_Gen_HPP_
#define StereoCrossDelay_Faust_pp_Gen_HPP_

#include <memory>

class StereoCrossDelay {
public:
    StereoCrossDelay();
    ~StereoCrossDelay();

    void init(float sample_rate);
    void clear() noexcept;

    void process(
        const float *in0,const float *in1,
        float *out0,float *out1,
        unsigned count) noexcept;

    enum { NumInputs = 2 };
    enum { NumOutputs = 2 };
    enum { NumActives = 8 };
    enum { NumPassives = 0 };
    enum { NumParameters = 8 };

    enum Parameter {
        p_delay_l,
        p_delay_r,
        p_feedback,
        p_lp_cutoff,
        p_hp_cutoff,
        p_crossmix,
        p_dry,
        p_wet,

    };

    struct ParameterRange {
        float init;
        float min;
        float max;
    };

    static const char *parameter_label(unsigned index) noexcept;
    static const char *parameter_short_label(unsigned index) noexcept;
    static const char *parameter_symbol(unsigned index) noexcept;
    static const char *parameter_unit(unsigned index) noexcept;
    static const ParameterRange *parameter_range(unsigned index) noexcept;
    static bool parameter_is_trigger(unsigned index) noexcept;
    static bool parameter_is_boolean(unsigned index) noexcept;
    static bool parameter_is_integer(unsigned index) noexcept;
    static bool parameter_is_logarithmic(unsigned index) noexcept;

    float get_parameter(unsigned index) const noexcept;
    void set_parameter(unsigned index, float value) noexcept;


    float get_delay_l() const noexcept;

    float get_delay_r() const noexcept;

    float get_feedback() const noexcept;

    float get_lp_cutoff() const noexcept;

    float get_hp_cutoff() const noexcept;

    float get_crossmix() const noexcept;

    float get_dry() const noexcept;

    float get_wet() const noexcept;


    void set_delay_l(float value) noexcept;

    void set_delay_r(float value) noexcept;

    void set_feedback(float value) noexcept;

    void set_lp_cutoff(float value) noexcept;

    void set_hp_cutoff(float value) noexcept;

    void set_crossmix(float value) noexcept;

    void set_dry(float value) noexcept;

    void set_wet(float value) noexcept;


public:
    class BasicDsp;

private:
    std::unique_ptr<BasicDsp> fDsp;



};




#endif // StereoCrossDelay_Faust_pp_Gen_HPP_
