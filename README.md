# Robot Seguidor de Línea - E-puck en Webots

Este proyecto implementa un **robot seguidor de línea autónomo** utilizando el simulador **Webots R2025a** y el robot educativo **E-puck**.  
El sistema emplea un **controlador PID** programado en **lenguaje C**, permitiendo que el robot siga una pista negra sobre un fondo blanco mediante sensores infrarrojos.

---

## 🎯 Objetivo del Proyecto
Desarrollar e implementar un **controlador PID** que ajuste dinámicamente las velocidades de las ruedas del robot E-puck  
para mantener una trayectoria estable sobre una línea, compensando desviaciones en tiempo real.

---

## 🧠 Descripción General

El robot utiliza **dos sensores infrarrojos** para detectar el contraste entre la línea negra y el fondo blanco.  
La diferencia entre las lecturas de ambos sensores se emplea como error de control, el cual es corregido mediante las componentes:

- 🟢 **Proporcional (P):** Corrige el error instantáneo.  
- 🔵 **Integral (I):** Compensa errores acumulados.  
- 🔴 **Derivativa (D):** Anticipa los cambios en la trayectoria.  

Este enfoque permite movimientos **más suaves, precisos y estables** en comparación con un control proporcional simple.

---

## ⚙️ Archivos principales
- `controller/my_controller_line_follower.c` → Código fuente en C del controlador PID.
- `protos/TrackOne.proto` → Pista modificada para evitar errores en Webots.
- `worlds/my_line_follower_world.wbt` → Mundo de simulación del proyecto.
- `informe/robot_line_follower.pdf` → Informe completo en LaTeX.

---

## 🧩 Requisitos
- Webots R2025a o superior.
- Sistema operativo: Windows 11.
- Compilador C integrado en Webots.

---

## 📸 Resultados
El robot logra seguir la línea negra en curvas y trayectorias rectas manteniendo la estabilidad del movimiento.

## 🎥 Referencia
Video base: [Cara Mudah Membuat Line Follower Robot dengan e-puck di Webots](https://www.youtube.com/watch?v=5BnS4dQL-Ww)
