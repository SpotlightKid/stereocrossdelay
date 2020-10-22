declare name "StereoCrossDelay";
declare description "A stereo delay with cross feedback";
declare author "Christopher Arndt";
declare license "MIT license";

import("stdfaust.lib");

gain = hslider("[0]Gain [symbol: gain][abbrev: gain][unit: dB]", -6.0, -90.0, 30.0, 0.1):si.smoo;

process = _ * ba.db2linear(gain);
