# Ejercicio 17

Ejercicio 17:
Crear un proyecto Qt Widget Application con un QWidget que sea la clase Ventana
Crear una clase Boton que hereda de QWidget
Redefinir paintEvent en Boton y usar fillRect para dibujarlo de algún color
Definir el siguiente método en Boton:
Boton * boton = new Boton;
boton->colorear( Boton::Azul );

// Este método recibe como parámetro una enumeración que puede ser:
// Boton::Azul  Boton::Verde  Boton::Magenta
Usar QtDesigner para Ventana y Boton. Es decir, Designer Form Class
Definir la enumeración en Boton
Abrir el designer de Ventana y agregar 5 botones (objetos de la clase Boton). Promocionarlos

Usar para Ventana grid layout, usar espaciadores y usar todos los recursos posibles del QtDesigner
Dibujar un fondo agradable con paintEvent y drawImage
Que Boton tenga la señal signal_clic()

Contiene widgets personalizados en Qt. Incluye un botón que cambia de color y una ventana que maneja eventos de pintura, demostrando la creación de señales propias.
