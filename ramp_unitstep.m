function y=ramp(t,m,ad)

N=length(h);
y=zeros(1,N);
    for i=1:N,
        if t(i)>=-ad,
           y(i)=m*(t(i)+ad);
        end
    end
end

function y=unitstep(t,ad)
N=length(t);
y=zeros(1,N);
    for i=1:N,
        if t(i)>=-ad,
           y(i)=1;
        end
    end
end
