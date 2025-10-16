// =============================================================
// Controlador PID para robot seguidor de línea (E-puck)
// Autor: Katherine Bejar
// Descripción: Implementa un control PID para que el robot
// siga una línea negra sobre fondo blanco utilizando sensores IR.
// =============================================================

#include <webots/robot.h>            // Librería principal de Webots
#include <webots/motor.h>            // Librería para el control de motores
#include <webots/distance_sensor.h>  // Librería para los sensores infrarrojos
#include <stdio.h>                   // Librería estándar de C para entrada/salida

#define TIME_STEP 64  // Intervalo de tiempo (ms) para cada paso de simulación

int main(int argc, char **argv) {
  wb_robot_init(); // Inicializa el robot

  // ----- Declaración de motores -----
  WbDeviceTag motor_derecho = wb_robot_get_device("right wheel motor");
  WbDeviceTag motor_izquierdo = wb_robot_get_device("left wheel motor");

  // Configuración de los motores para rotación continua
  wb_motor_set_position(motor_derecho, INFINITY);
  wb_motor_set_position(motor_izquierdo, INFINITY);

  // ----- Declaración de sensores -----
  WbDeviceTag sensor_derecho = wb_robot_get_device("right_sensor");
  WbDeviceTag sensor_izquierdo = wb_robot_get_device("left_sensor");

  wb_distance_sensor_enable(sensor_derecho, TIME_STEP);
  wb_distance_sensor_enable(sensor_izquierdo, TIME_STEP);

  // ----- Variables PID -----
  double Kp = 0.4;   // Ganancia proporcional
  double Ki = 0.01;  // Ganancia integral
  double Kd = 0.2;   // Ganancia derivativa

  double error = 0.0;
  double error_anterior = 0.0;
  double error_integral = 0.0;

  // Velocidad base del robot
  double v_base = 2.0;

  // ----- Bucle principal de simulación -----
  while (wb_robot_step(TIME_STEP) != -1) {
    // Lectura de los sensores infrarrojos
    double lectura_derecha = wb_distance_sensor_get_value(sensor_derecho);
    double lectura_izquierda = wb_distance_sensor_get_value(sensor_izquierdo);

    // Cálculo del error (diferencia entre sensores)
    error = lectura_izquierda - lectura_derecha;

    // Componentes PID
    error_integral += error;                     // Acumulación del error (parte integral)
    double derivada = error - error_anterior;    // Cambio del error (parte derivativa)
    double salida = Kp * error + Ki * error_integral + Kd * derivada;  // Salida PID

    // Cálculo de velocidades de cada motor
    double v_izq = v_base - salida;
    double v_der = v_base + salida;

    // Limitar velocidades máximas del E-puck (6.28 rad/s)
    if (v_izq > 6.28) v_izq = 6.28;
    if (v_der > 6.28) v_der = 6.28;
    if (v_izq < -6.28) v_izq = -6.28;
    if (v_der < -6.28) v_der = -6.28;

    // Asignar velocidades a los motores
    wb_motor_set_velocity(motor_izquierdo, v_izq);
    wb_motor_set_velocity(motor_derecho, v_der);

    // Imprimir valores para depuración
    printf("Sensor Izquierdo: %.2f | Sensor Derecho: %.2f | Error: %.2f | Salida PID: %.2f\n",
           lectura_izquierda, lectura_derecha, error, salida);

    // Actualizar error anterior
    error_anterior = error;
  }

  wb_robot_cleanup(); // Limpieza final del robot
  return 0;
}
