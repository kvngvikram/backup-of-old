clc;

i = imread('C:\Users\VAMSHI\Desktop\Arnav\elon.jpg');

j = imread('C:\Users\VAMSHI\Desktop\Arnav\face.png');



ellip=rgb2gray(j);
nellip = 255-ellip; 
%figure(),imshow(nellip);


face=rgb2gray(i);
%figure(),imshow(face)



hy = fspecial('sobel');
hx = hy';
Iy = imfilter(double(face), hy, 'replicate');
Ix = imfilter(double(face), hx, 'replicate');
gradmag = sqrt(Ix.^2 + Iy.^2);
%{
figure()
nface=imshow(gradmag,[]), title('Gradient magnitude (gradmag)')
%}
max = 0; 
index = 1; 
for i=0.1:0.1:2
ne1=imresize(nellip,i);
%figure(),imshow(ne1)
check = xcorr2(ne1,gradmag);
[row ,column] = max(check);
trailmax = check(row,column);
if trailmax > max 
    max = trailmax; 
    index = i; 
end

end
for i = 1 : m
    for j = 1 : n
        MAX = check(i,j)
        if
            
ne1=imresize(nellip,index);

surf(xcorr2(ne1,gradmag))
shading interp

