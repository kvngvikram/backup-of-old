# This code is to give the location (lat lon) of GPS receiver station from a webpage

from bs4 import BeautifulSoup as mbs
import requests

webaddress = 'http://geodesy.unr.edu/NGLStationPages/stations/0ARK.sta'

page = requests.get(webaddress)
print('connection successful' if page.status_code == 200 else 'connection failed')

a = str(page.text)
print(type(a))

lati = a.find('Latitude')
loni = a.find('Longitude')

print(a[lati-6:lati+25])
print(a[loni-6:loni+25])

