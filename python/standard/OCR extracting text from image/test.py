from PIL import Image 
import pytesseract as pt 

image = Image.open('test.png')

print('\n\n##################################################\n Trail one with default settings\n##################################################\n\n')
text = pt.image_to_string(image)
print(text)

print('\n\n##################################################\n Trail one with settings as english language\n##################################################\n\n')
text = pt.image_to_string(image,lang = 'eng')
print(text)
