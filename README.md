# exam-generator

Para compilar:
gcc EGMain.c -I include/ src/csvparser.c

El programa tiene dos modalidades. El primero es para el uso de los profesores en el cual el profesor puede decidir la cantidad de preguntas que desea para su examen, además de ponerle el nombre del examen. La segunda modalidad es para aplicar el examen que creo el profesor, calificarlo y guardar los datos(cuenta del alumno, calificación ,respuestas correctas, numero de preguntas totales y el tiempo) en un archivo.

 

Pasos para usar la modalidad generador:

    Ejecutar ./generador.exe
    Ingresar el nombre del archivo del cual se desea obtener las preguntas
    Ingresar el nombre del examen que se va a crear
    Ingresar el número de preguntas deseadas

 

Pasos para usar la modalidad examinador:

1. Ejecutar ./examinador.exe

2. Ingresar el número de cuenta del alumno que va a realizar el examen

3.Leer las preguntas y seleccionar la respuestas correctas(no importa si se usan mayúsculas o minúsculas )

4.Al terminar el examen se informara sobre la calificación del alumno

5. Preguntara si se desea volver a realizar el examen

-Si se desea volver a realizar ingresar “s “

-Si no se desea realizar otra evaluación ingresar “n” 
