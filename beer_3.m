function varargout = beer_3(varargin)
% BEER_3 MATLAB code for beer_3.fig
%      BEER_3, by itself, creates a new BEER_3 or raises the existing
%      singleton*.
%
%      H = BEER_3 returns the handle to a new BEER_3 or the handle to
%      the existing singleton*.
%
%      BEER_3('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in BEER_3.M with the given input arguments.
%
%      BEER_3('Property','Value',...) creates a new BEER_3 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before beer_3_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to beer_3_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help beer_3

% Last Modified by GUIDE v2.5 26-May-2019 23:30:11

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @beer_3_OpeningFcn, ...
                   'gui_OutputFcn',  @beer_3_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before beer_3 is made visible.
function beer_3_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to beer_3 (see VARARGIN)

% Choose default command line output for beer_3
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes beer_3 wait for user response (see UIRESUME)
% uiwait(handles.figure1);
set(gcf,'Color',[0.19 0.19 0.18]) % Cambia el color del fondo actual
% Poner la imagen del tipo de cerveza
axes(handles.axes2)
background = imread('beer_1.jpg');
axis off;
imshow(background);

% Configuración del Axes para graficar la transmisión de los datos
%axes(handles.axes1)
%xlabel('Tiempo[s]') %,'FontSize',12,'FontWeight','bold','Color','m')
%ylabel('Temperatura[°C]')
%ylabel(['{\color[rgb]{0.5,0.5,0.5}Datos}'],'FontSize',12,'FontWeight','bold')
%title(['\fontsize{13}{\color[rgb]{0.5 0.5 0.5}Datos temperatura de Cerveza vs salida PID}'],'FontWeight','bold');
%grid on;
%hold on;
 % Protocolo de conexión bluetooth
 global dispositivo_bluetooth;

    disp('Buscando dispositivo Bluetooth.')
    disp('Momento por favor, este proceso puede durar varios segundos.')
    instrhwinfo('Bluetooth', 'HC-05' );%Información técnica del dispositivo
    dispositivo_bluetooth = Bluetooth('HC-05',1);
    disp('Enlazando con dispositivo Bluetooth.')

% This sets up the initial plot - only do when we are invisible
% so window can get raised using Control_beer.


% --- Outputs from this function are returned to the command line.
function varargout = beer_3_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close all

% --- Executes on button press in togglebutton2.


function sp1_Callback(hObject, eventdata, handles)
% hObject    handle to sp1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of sp1 as text
%        str2double(get(hObject,'String')) returns contents of sp1 as a double


% --- Executes during object creation, after setting all properties.
function sp1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to sp1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes3)
cla;


function edit1_Callback(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit1 as text
%        str2double(get(hObject,'String')) returns contents of edit1 as a double


% --- Executes during object creation, after setting all properties.
function edit1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in togglebutton1.
function togglebutton1_Callback(hObject, eventdata, handles)
% hObject    handle to togglebutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of togglebutton1
global dispositivo_bluetooth;

bluetooth_state = get(hObject,'Value')
if bluetooth_state == 1
   
    fopen(dispositivo_bluetooth);  % Abre comunicación Bluetooth entre MATLAB y Arduino, Queda habilitado para enviar y recibir datos 
    disp('Dispositivo Bluetooth conectado');
    set(handles.edit1, 'String', 'Enlazado');
  
else
    fclose(dispositivo_bluetooth);
    clear dispositivo_bluetooth;
    set(handles.edit1, 'String', 'Inhabilitado');
    %set(handles.sp1, 'String', 'No Detectado');
end    

% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global dispositivo_bluetooth;

%axes(handles.axes3);
%children = get(gca, 'children');
%delete(children(1));

axes(handles.axes3)
cla;
    
xlabel(''); ylabel('Temperatura[°C]'); title('\color[rgb]{.5 .5 .5}Adquisición datos de temperatura');
prop = line(nan,nan, 'Color', 'w', 'LineWidth',1);
trash = [1];
disp('Sincronizando comunicación...');
disp('Eliminando basura residual...');


while(isempty(trash)== false)
trash = fscanf(dispositivo_bluetooth,'%f %f',[2,1])
disp('Eliminando basura residual....');
end

disp('Basura residual eliminada...');
disp('Iniciando protocolo de sincronización con arduino...');

while(1)
    fwrite(dispositivo_bluetooth,95);
    informe = fscanf(dispositivo_bluetooth,'%f %f',[2,1])
    
    if(informe == 135.0000)
        break;
    end
    pause on
    pause(0.3)
    pause off
end
 % Setpoints y tiempos nuevos
s = str2double(get(handles.sp1,'String'))
t = str2double(get(handles.tiempo1,'String'))
u = str2double(get(handles.sp2,'String'))
v = str2double(get(handles.tiempo2,'String'))
w = str2double(get(handles.sp3,'String'))
x = str2double(get(handles.tiempo3,'String'))
y = str2double(get(handles.sp4,'String'))
z = str2double(get(handles.tiempo4,'String'))
q = str2double(get(handles.sp5,'String'))
r = str2double(get(handles.tiempo5,'String'))

disp('enviando array...')
fwrite(dispositivo_bluetooth,[s,t,u,v,w,x,y,z,q,r]);

disp('Adquisición de datos en proceso');
stop = get(handles.stop,'value');
pause(0.3);
i =1;
datos = zeros(3);
while(1)
    if stop == false
        datos = fscanf(dispositivo_bluetooth, '%f %f', [2,1]);
        Temperatura = datos(1,1); fprintf('\n \nTemperatura[°C]: %i',Temperatura);
        Tiempo_Restante_Ciclo = datos(2,1); fprintf('\nTiempo restante del ciclo[Minutos]: %i',Tiempo_Restante_Ciclo);
       % tiempo = datos(2,1); problemas con transmisión de datos
        temperatura(i) = datos(1,1); %Poner filtro luego de esta linea con if estableciendo una banda
        x =[1:i];
        axis([1 i+5 20 temperatura(i)+5])
        set(prop,'YData', temperatura(1:i),'Xdata',x);
        drawnow;
        set(handles.indicador_temp,'String',temperatura(i));
        set(handles.tiempo_restante,'String',Tiempo_Restante_Ciclo);
        i = i+1;
        
    elseif stop == true
        break;
    end
    stop = get(handles.stop,'value');
    pause(0.1)
end

%fwrite(dispositivo_bluetooth,1);

% --- Executes on button press in stop.
function stop_Callback(hObject, eventdata, handles)
% hObject    handle to stop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%global dispositivo_bluetooth;
%fwrite(dispositivo_bluetooth,0);



function sp2_Callback(hObject, eventdata, handles)
% hObject    handle to sp2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of sp2 as text
%        str2double(get(hObject,'String')) returns contents of sp2 as a double


% --- Executes during object creation, after setting all properties.
function sp2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to sp2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function sp3_Callback(hObject, eventdata, handles)
% hObject    handle to sp3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of sp3 as text
%        str2double(get(hObject,'String')) returns contents of sp3 as a double


% --- Executes during object creation, after setting all properties.
function sp3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to sp3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function sp4_Callback(hObject, eventdata, handles)
% hObject    handle to sp4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of sp4 as text
%        str2double(get(hObject,'String')) returns contents of sp4 as a double


% --- Executes during object creation, after setting all properties.
function sp4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to sp4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function tiempo1_Callback(hObject, eventdata, handles)
% hObject    handle to tiempo1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of tiempo1 as text
%        str2double(get(hObject,'String')) returns contents of tiempo1 as a double


% --- Executes during object creation, after setting all properties.
function tiempo1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to tiempo1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function tiempo2_Callback(hObject, eventdata, handles)
% hObject    handle to tiempo2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of tiempo2 as text
%        str2double(get(hObject,'String')) returns contents of tiempo2 as a double


% --- Executes during object creation, after setting all properties.
function tiempo2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to tiempo2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function tiempo3_Callback(hObject, eventdata, handles)
% hObject    handle to tiempo3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of tiempo3 as text
%        str2double(get(hObject,'String')) returns contents of tiempo3 as a double


% --- Executes during object creation, after setting all properties.
function tiempo3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to tiempo3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function tiempo4_Callback(hObject, eventdata, handles)
% hObject    handle to tiempo4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of tiempo4 as text
%        str2double(get(hObject,'String')) returns contents of tiempo4 as a double


% --- Executes during object creation, after setting all properties.
function tiempo4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to tiempo4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function timer_Callback(hObject, eventdata, handles)
% hObject    handle to timer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of timer as text
%        str2double(get(hObject,'String')) returns contents of timer as a double


% --- Executes during object creation, after setting all properties.
function timer_CreateFcn(hObject, eventdata, handles)
% hObject    handle to timer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function sp5_Callback(hObject, eventdata, handles)
% hObject    handle to sp5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of sp5 as text
%        str2double(get(hObject,'String')) returns contents of sp5 as a double


% --- Executes during object creation, after setting all properties.
function sp5_CreateFcn(hObject, eventdata, handles)
% hObject    handle to sp5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function tiempo5_Callback(hObject, eventdata, handles)
% hObject    handle to tiempo5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of tiempo5 as text
%        str2double(get(hObject,'String')) returns contents of tiempo5 as a double


% --- Executes during object creation, after setting all properties.
function tiempo5_CreateFcn(hObject, eventdata, handles)
% hObject    handle to tiempo5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton6.
function pushbutton6_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global dispositivo_bluetooth;

axes(handles.axes3)
%cla;
    
xlabel(''); ylabel('Temperatura[°C]'); title('\color[rgb]{.5 .5 .5}Adquisición datos de temperatura');
prop = line(nan,nan, 'Color', 'r', 'LineWidth',2);

trash = [1];
disp('Sincronizando comunicación...');
disp('Eliminando basura residual...');


while(isempty(trash)== false)
trash = fscanf(dispositivo_bluetooth,'%f %f',[2,1])
disp('Eliminando basura residual....');
end

disp('Basura residual eliminada...');
disp('Iniciando protocolo de sincronización con arduino...');

while(1)
    fwrite(dispositivo_bluetooth,96);
    informe = fscanf(dispositivo_bluetooth,'%f %f',[2,1])
    
    if(informe == 136.0000)
        break;
    end
    pause on
    pause(0.3)
    pause off
end
fprintf('\nComenzo ciclo de lupulado...\n');
disp('Adquisición de datos en proceso');
stop = get(handles.stop,'value');
pause(0.3);
i =1;
datos = zeros(3);
while(1)
    if stop == false
        datos = fscanf(dispositivo_bluetooth, '%f %f', [2,1]);
        Temperatura = datos(1,1); fprintf('\nTemperatura[°C]: %i',Temperatura);
        Tiempo_Restante_Ciclo = datos(2,1); fprintf('\nTiempo restante del ciclo[Minutos]: %i',Tiempo_Restante_Ciclo);
       % tiempo = datos(2,1); problemas con transmisión de datos
        temperatura(i) = datos(1,1); %Poner filtro luego de esta linea con if estableciendo una banda
        x =[1:i];
        axis([1 i+5 20 temperatura(i)+5])
        set(prop,'YData', temperatura(1:i),'Xdata',x);
        drawnow;
        set(handles.indicador_temp,'String',temperatura(i));
        set(handles.tiempo_restante,'String',Tiempo_Restante_Ciclo);
        i = i+1;
        
    elseif stop == true
        break;
    end
    stop = get(handles.stop,'value');
    pause(0.1)
end
