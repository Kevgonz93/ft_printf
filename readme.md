# 📢 42 - ft_printf

## 📜 Descripción

**ft_printf** es un proyecto de 42 que consiste en una implementación personalizada de la función `printf` de C. El objetivo es replicar la funcionalidad de `printf` estándar, manejando varios tipos de datos y características.

## 📋 Requisitos

Antes de compilar y ejecutar el proyecto, asegúrate de tener:

- 🛠️ **`gcc`**: Compilador de C.
- 🛠️ **`make`**: Herramienta de construcción.
- 🖥️ **Sistema operativo**: Unix o Mac.

---

## 🛠️ Cómo Compilar y Ejecutar

1. Clona este repositorio:

   ```bash
   git clone https://github.com/Kevgonz93/printf.git
   ```

2. Navega al directorio del proyecto:

   ```bash
    cd printf
   ```

3. Compila el programa:

   ```bash
   make
   ```

4. Compila junto a el main facilitado u otro que tengas:

   ```bash
   cc printf_main.c libftprintf.a -o printf
   ```

5. Ejecuta para ver el resultado:

   ```bash
   ./printf
   ```

---

## 🚀 Características

- Especificadores de formato soportados:
  - %c - Carácter
  - %s - Cadena
  - %p - Puntero
  - %d, %i - Enteros
  - %u - Entero sin signo
  - %x, %X - Hexadecimales (minúsculas y mayúsculas)
- Extensiones adicionales:
  - Formateo personalizado para cadenas y punteros.

---

## 🧪 Pruebas

Primero tendrás que incluir el proyecto en tu código:

```bash
#include "ft_printf.h"
```

Ejemplo:

```bash
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hola, mundo! El número es: %d\n", 42);
    return 0;
}
```

Esto imprimirá:

```bash
Hola, mundo! El número es: 42
```

---

## 📂 Estructura del Proyecto

```
📦 printf
├── 📂 aux            # Funciones auxiliares (libft adaptado)
├── ft_printers.c     # Funciones impresoras
├── ft_printf.c       # Implementación principal
├── ft_printf.h       # Archivo de cabecera
├── ft_utils.c        # Funciones auxiliares
├── Make file         # Para compilar la librería
├── printf_main.c     # Archivo con main tester
├── README.md         # Este archivo
├── subject.md        # Enunciado en markdown
└── subject.pdf       # Enunciado del proyecto en pdf
```

---

## 🧑‍💻 Autor

[Kevin Gonzales](https://github.com/Kevgonz93)
