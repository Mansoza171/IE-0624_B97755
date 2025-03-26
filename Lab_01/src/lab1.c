#include <pic14/pic12f683.h>
#include <stdio.h>

// Configuración del microcontrolador (Oscilador interno, watchdog deshabilitado, sin reset externo, protección de código activada)
__code unsigned int __at (_CONFIG) configword = _INTOSCIO & _WDTE_OFF & _PWRTE_OFF & _MCLRE_OFF & _CP_ON & _CPD_ON;

void pausa(unsigned int duracion); // Declaración de función para retardos

void main(void)
{
    ANSEL = 0;              // Configura todos los pines como digitales
    TRISIO = 0b00000000;    // Establece todos los pines como salidas
    GPIO = 0b00001000;      // Inicializa los pines de salida apagados

    unsigned int retardo = 100;  // Variable para la duración de las pausas    

    while (1)
    {
        int estado = 0;  // Variable para controlar la secuencia de iluminación

        for (int i = 0; i < 7; i++) {
            estado++;

            switch (estado) 
            {
                case 1:
                    // Representación del número 1
                    GP0 = 0;
                    GP2 = 0;
                    GP4 = 0;
                    GP5 = 0;
                    GP1 = 1;
                    pausa(retardo);
                    pausa(retardo);
                    break;
                case 2:
                    // Representación del número 2
                    GP0 = 0;
                    GP1 = 0;
                    GP2 = 1;
                    GP4 = 0;
                    GP5 = 0;
                    pausa(retardo);
                    pausa(retardo);
                    break;
                case 3:
                    // Representación del número 3
                    GP0 = 0;
                    GP2 = 1;
                    GP4 = 0;
                    GP5 = 0;
                    GP1 = 1;
                    pausa(retardo);
                    pausa(retardo);
                    break;
                case 4:
                    // Representación del número 4
                    GP0 = 0;
                    GP1 = 0;
                    GP2 = 0;
                    GP4 = 1;
                    GP5 = 1;
                    pausa(retardo);
                    pausa(retardo);
                    break;
                case 5:
                    // Representación del número 5
                    GP0 = 0;
                    GP2 = 0;
                    GP4 = 1;
                    GP5 = 1;
                    GP1 = 1;
                    pausa(retardo);
                    pausa(retardo);
                    break;
                case 6:
                    // Representación del número 6
                    GP0 = 0;
                    GP1 = 1;
                    GP2 = 1;
                    GP4 = 1;
                    GP5 = 1;
                    pausa(retardo);
                    pausa(retardo);
                    break;
                default:
                    // En caso de error, apagar todos los LEDs
                    GP0 = 0;
                    GP1 = 0;
                    GP2 = 0;
                    GP4 = 0;
                    GP5 = 0;
                    pausa(retardo);
                    pausa(retardo);
                    break;            
            }
        }
    }
}

// Función para generar retardos mediante bucles anidados
void pausa(unsigned int duracion)
{
    unsigned int x, y;
    for(x = 0; x < duracion; x++)
        for(y = 0; y < 1275; y++);
}
