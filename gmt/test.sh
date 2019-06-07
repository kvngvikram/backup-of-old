# refer : http://gmt-tutorials.org/en/making_first_map.html
#         http://www.matthewwherman.com/documents/tutorials/gmt_tutorial_1.pdf
#         http://gmt.soest.hawaii.edu/doc/5.3.2/makecpt.html
#         http://gmt.soest.hawaii.edu/doc/5.3.2/gmt.conf.html
PROJ="-JQ80c"
LIMS="-R60/110/0/50"
PSFILE="earthquakes.ps"
XOFFSET="-X10c"
YOFFSET="-Y5c"
ORIENTATION="-P"
additional_parameters="--PS_MEDIA=100cx50c"

gmt pscoast $PROJ $LIMS -W1p -Dh -N1/0.5p $XOFFSET $YOFFSET -K $ORIENTATION $additional_parameters > $PSFILE
gmt psbasemap $PROJ $LIMS -Bxa20g10 -Bya30g5 -BWeSn \
  -O -K $ORIENTATION $additional_parameters>> $PSFILE

gmt psxy eqs.xy $PROJ $LIMS -Sc0.5c -W0.25p -Ccolors.cpt -O $ORIENTATION $additional_parameters >> $PSFILE

open -a preview #PSFILE
