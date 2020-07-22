clear
clc

% initialization
R = input('R = ');
X = input('X = ');
Z = input('Z = ');
THETA = input('THETA = ');
disp(' ')

% execution
if Z == 0 & THETA == 0
    Z = sqrt((R)^2 + (X)^2);
    THETA = radtodeg(atan(X/R));
    
    fprintf('Z = [(R)^2 + (X)^2]\n')
    fprintf('Z = [(%.2f)^2 + (%.2f)^2]\n', R, X)
    fprintf('Z = %.2f\n', Z)
    disp(' ')
    fprintf('THETA = arc.tan(X / R)\n')
    fprintf('THETA = arc.tan(%.2f / %.2f)\n', X, R)
    fprintf('THETA = %.2f\n', THETA)
    disp(' ')
    disp('rectangular to polar')
    if X < 0
        fprintf('%.2f - j%.2f = %.2f <%.2f', R, -X, Z, THETA)
    else
        fprintf('%.2f + j%.2f = %.2f <%.2f', R, X, Z, THETA)
    end
    
elseif R == 0 & X == 0
    R = Z*cos(degtorad(THETA));
    X = Z*sin(degtorad(THETA));
 
    fprintf('R = Z*cos(THETA)\n')
    fprintf('R = %.2f*cos(%.2f)\n', Z, THETA)
    fprintf('R = %.2f\n', R)
    disp(' ')
    fprintf('X = Z*sin(THETA)\n')
    fprintf('X = %.2f*sin(%.2f)\n', Z, THETA)           
    fprintf('X = %.2f\n', X)
    disp(' ')
    disp('polar to rectangular')
    if X < 0
        fprintf('%.2f <%.2f = %.2f - j%.2f', Z, THETA, R, -X)
    else
        fprintf('%.2f <%.2f = %.2f + j%.2f', Z, THETA, R, X)
    end
    
end

disp(' ')
disp('        ______')
disp('-------|______|--------')
fprintf('\t%.2f <%.2f\n', Z, THETA)
if X < 0
    fprintf('\t%.2f - j%.2f\n', R, -X)
else
    fprintf('\t%.2f + j%.2f\n', R, X)
end











