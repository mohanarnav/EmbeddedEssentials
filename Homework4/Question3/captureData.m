load MBed_sampled_data;
x=MBed_sampled_data;


# conditioning the signal
if(x(1)==0)
while(x(1)==0)
x(1)=[];
end
end

x(800:end)=[];
while(x(end)==1)
x(end)=[];
end

length(x)
plot(x)
xlabel('samples (for 16 cycles)');
ylabel('sampled pwm output');
