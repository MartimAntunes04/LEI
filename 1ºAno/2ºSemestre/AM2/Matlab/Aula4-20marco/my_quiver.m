
[t,y] = meshgrid(-2:0.1:2,-2:0.1:2);
%dy = -0.1*(y-30);
%dy = ones(size(y))
dy = -2.*t.*y;
dx=ones(size(dy));
dyu=dy./sqrt(dy.^2+dx.^2);
dxu=dx./sqrt(dy.^2+dx.^2);
quiver(t,y,dxu,dyu);
axis tight; xlabel('t'), ylabel('y')
title('Direction field for dy/dt = f(t,y)')