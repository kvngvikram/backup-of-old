% Record your voice for 3 seconds.
recObj = audiorecorder;
disp('Start speaking.')
recordblocking(recObj,3)
disp('End of Recording.');

% Play back the recording.
play(recObj);

% Store data in double-precision array.
myRecording = getaudiodata(recObj);
% Plot the waveform.
plot(myRecording);
