

from bs4 import BeautifulSoup as mbs
import requests
import numpy as np
import matplotlib.pyplot as plt 



webaddress ='https://www.timeanddate.com/worldclock/india'

page = requests.get(webaddress)
#print(page.status_code)

soup = mbs(page.text,'html.parser')
print(soup)

dat = soup.find('span id="ct"')
#print(dat)
print('\n\n\n\n\n\n\n\n\n')

# not mydat is a string
mydat = str(dat)
print(mydat)

