i = imread('C:\Users\VAMSHI\Desktop\test1.jpg');
imshow(i);
b=rgb2gray(i);
imshow(b); 
%y=imgaussfilt(b);
imshow(b);
hy = fspecial('sobel');
hx = hy';
Iy = imfilter(double(b), hy, 'replicate');
Ix = imfilter(double(b), hx, 'replicate');
gradmag = sqrt(Ix.^2 + Iy.^2);
figure
imshow(gradmag,[]), title('Gradient magnitude (gradmag)')