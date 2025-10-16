# Robot Seguidor de Línea - E-puck en Webots

Este proyecto implementa un **robot seguidor de línea** usando el simulador **Webots R2025a** y el robot **E-puck**.  
El control del movimiento se basa en un **controlador PID** desarrollado en lenguaje **C**.

## 🧠 Objetivo
Diseñar un sistema de control que permita al robot seguir una línea negra sobre un fondo blanco utilizando sensores infrarrojos.

## ⚙️ Archivos principales
- `controller/my_controller_line_follower.c` → Código fuente en C del controlador PID.
- `protos/TrackOne.proto` → Pista modificada para evitar errores en Webots.
- `worlds/my_line_follower_world.wbt` → Mundo de simulación del proyecto.
- `informe/robot_line_follower.pdf` → Informe completo en LaTeX.

## 🧩 Requisitos
- Webots R2025a o superior.
- Sistema operativo: Windows 11.
- Compilador C integrado en Webots.

## 📸 Resultados
El robot logra seguir la línea negra en curvas y trayectorias rectas manteniendo la estabilidad del movimiento.

## 🎥 Referencia
Video base: [Cara Mudah Membuat Line Follower Robot dengan e-puck di Webots](https://www.youtube.com/watch?v=5BnS4dQL-Ww)
