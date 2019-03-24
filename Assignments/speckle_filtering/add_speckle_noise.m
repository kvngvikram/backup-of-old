img = imread('original.png') ;
nimg = imnoise(img,'speckle',0.02);
imwrite(nimg,'noise_image.png');
    