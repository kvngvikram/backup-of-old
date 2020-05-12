dset ^data_2016.grib
index ^data_2016.grib.idx
undef 9.999E+20
title data_2016.grib
*  produced by grib2ctl v0.9.13
* command line options: data_2016.grib
dtype grib 255
options yrev
ydef 73 linear -90.000000 2.5
xdef 144 linear 0.000000 2.500000
tdef 12 linear 00Z01jan2016 1mo
*  z has 37 levels, for prs
zdef 37 levels
1000 975 950 925 900 875 850 825 800 775 750 700 650 600 550 500 450 400 350 300 250 225 200 175 150 125 100 70 50 30 20 10 7 5 3 2 1
vars 4
Qprs 37 133,100,0 ** (profile) Specific humidity [kg kg**-1]
Tprs 37 130,100,0 ** (profile) Temperature [K]
Uprs 37 131,100,0 ** (profile) U velocity [m s**-1]
Vprs 37 132,100,0 ** (profile) V velocity [m s**-1]
ENDVARS
