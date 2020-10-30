declare name "StereoCrossDelay";
declare description "A stereo delay with feedback and cross-over mixing";
declare author "Christopher Arndt";
declare license "MIT license";

import("stdfaust.lib");


// constants
MAX_DELAY = 2.0;


// params
time_l = ba.sec2samp(hslider("[0]Delay L[symbol: delay_l][unit: ms]", 500.0, 0, MAX_DELAY * 1000, 0.1) : si.smoo);
ratio_r = hslider("[1]Delay R Ratio[symbol: delay_r][style:menu{'1:1':1;'1:2':2;'2:1':0.5;'}]", 0.75, 0.001, 2, 0.01);

feedback = hslider("[2]Feedback[symbol: feedback][unit: %]", 20, 0, 100, 0.1) : si.smoo;

lp_cutoff = hslider("[3]Lowpass[symbol: lp_cutoff][unit: hz][scale: log]", 12000, 20, 20000, 0.1) : si.smoo;
hp_cutoff = hslider("[4]Highpass[symbol: hp_cutoff][unit: hz][scale: log]", 60, 20, 20000, 0.1) : si.smoo;

crossfeed = hslider("[5]Crossmix[symbol: crossmix][unit: %]", 25, 0, 100, 0.1) : si.smoo;

wet = hslider("[6]Wet[symbol: wet][unit: db]", -6, -90, 6, 0.1) : si.smoo : ba.db2linear;
dry = hslider("[7]Dry[symbol: dry][unit: db]", 0, -90, 6, 0.1) : si.smoo : ba.db2linear;


// processing blocks
cross_mixer(l, r) =
    l * (1 - coef) + r * coef,
    r * (1 - coef) + l * coef
with {
    coef = crossfeed * 0.01;
};

fb_mixer(fb_l, fb_r, in_l, in_r) =
    in_l + (fb_l * feedback * 0.01), in_r + (fb_r * feedback * 0.01), in_l, in_r;

fb_filter =
    fi.highpass(2, hp_cutoff) :
    fi.lowpass(2, lp_cutoff);

delay_l =
    de.sdelay(ba.sec2samp(MAX_DELAY), 512, time_l * 0.001);
delay_r =
    de.sdelay(ba.sec2samp(MAX_DELAY * 2), 512, time_l * ratio_r * 0.001);

wetdry(wet_l, wet_r, in_l, in_r) =
    in_l * dry + wet_l * wet, in_r * dry + wet_r * wet;


// signal chain
process =
    (fb_mixer : delay_l, delay_r, _, _ : cross_mixer, _, _) ~
    (fb_filter, fb_filter) : wetdry;
