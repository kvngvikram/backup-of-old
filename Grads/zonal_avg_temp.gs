'c'
'open fnl_060903_00_00.ctl'
'set lev 1000 10'
'set lat -90 90'
'set lon 90'
'set gxout shaded'
'd ave(tmpprs,lon=0,lon=360)'
'draw title Zonally averaged temperature'
'draw xlab latitude'
'draw ylab height_hPa'
'gxprint zonal_avg_temp.png'
