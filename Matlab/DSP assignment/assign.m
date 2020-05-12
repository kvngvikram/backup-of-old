%% DIT

t=100000;
a=0:10:t;
x=cos(a);
%%
disp('Using the DIT algorithem')
tic
dit(x);
toc


%% DFT computation regular method
disp('By calculating manually')
N=numel(x);
tic
for k=0:N-1
X(k+1)=0;
for n=0:N-1
X(k+1)=x(n+1).*exp(-j*(2*pi/N)*n*k)+X(k+1); %DFT of input signal.
end
end
toc

%% DFT computation using fft function
disp('Using built in function fft()')
tic
X=fft(x);
toc
