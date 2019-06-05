# refer : http://gmt-tutorials.org/en/making_first_map.html
gmt pscoast -R19.42/22.95/59.71/60.56 \
  -JM15c \
  -W0.1p,black \
  -Dh \
  -Scornflowerblue \
  -Gdarkseagreen2 \
  -P \
  -Ba2f0.5g1 \
  -BWSne+t"Archipelago Sea" \
  -A0.2 \
  > temp.ps
open -a preview temp.ps
