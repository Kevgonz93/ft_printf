# 📢 42 - ft_printf

## 📝 Descripción

**ft_printf** es una implementación personalizada de la función `printf` de C, creada como parte del proyecto de la escuela 42. El objetivo es replicar la funcionalidad de `printf` estándar, manejando varios tipos de datos y características como precisión, anchos de campo y más.

## 🛠️ Requisitos

- **Linux** o **macOS**
- **Make**
- **gcc** o cualquier compilador compatible con C
- **Norminette** (para verificar el estilo de código según la normativa de 42)

---

## ⚡ Instalación

Para compilar el proyecto, simplemente usa el comando `make` en el directorio raíz del repositorio:

```bash
make
```

Esto generará el archivo libftprintf.a, que podrás incluir en tu proyecto.

---

## 🚀 Uso

Incluir el proyecto en tu código:

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

## ✨ Funcionalidades

-	Especificadores de formato soportados:
    -   %c - Carácter
    -	%s - Cadena
    -	%p - Puntero
    -	%d, %i - Enteros
    -	%u - Entero sin signo
    -   %x, %X - Hexadecimales (minúsculas y mayúsculas)
-	Extensiones adicionales:
    -   Formateo personalizado para cadenas y punteros.

---

## 🔧 Norminette

Este proyecto sigue las pautas de estilo de Norminette, que aseguran que el código esté correctamente formateado según los estándares de la escuela 42.

---

## 📂 Estructura del Proyecto

```
📦 printf
├── 📂 aux            # Funciones auxiliares (libft adaptado)
├── ft_printers.c     # Funciones impresoras
├── ft_printf.c       # Implementación principal
├── ft_printf.h       # Archivo de cabecera
├── ft_utils.c        # Funciones auxiliares
├── Make file         # Para compilar el proyecto
├── printf_main.c     # Archivo con main tester
├── README.md         # Este archivo
├── subject.md       # Enunciado en markdown
└── subject.pdf      # Enunciado del proyecto en pdf
```

---

## 📜 Licencia

Este proyecto se distribuye bajo la licencia MIT.

---

## 🧑‍💻 Autor

[Kevin Gonzales](https://github.com/Kevgonz93)