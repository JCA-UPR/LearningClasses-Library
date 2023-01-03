# LearningClasses-Library
Defina una clase llamada BookInfo que sea un tipo de datos abstracto (ADT) para almacenar información sobre un libro. Su clase debe tener dos campos de tipo string, el primero para almacenar el nombre del autor y el segundo para almacenar el título del libro. Incluya las siguientes funciones miembro: un constructor para establecer el título del libro y el autor, un segundo constructor que establece el título del libro al pasarlo como un solo parámetro y el autor en "desconocido", y un método para obtener el autor y el título concatenados en una sola cadena C++. Escriba un programa cliente (driver program) para probar su clase creando algunos objetos de libro e imprimirlos usando sus funciones miembro.

Defina una nueva clase llamada UpdatedBook que herede la clase BookInfo creada antes. Esta nueva clase debe contener un campo entero para el número de edición del libro, un constructor para crear el objeto UpdatedBook aceptando como entrada el autor, el título y el número de edición del libro, y un método getter para devolver el número de edición.

Defina otra clase llamada BookLibrary. Esta clase debe contener un campo que almacene un vector (repasar este tópico de Prog. I en sección 8.3 del libro de la clase) de objetos UpdatedBook. Su clase BookLibrary debe tener los siguientes métodos: un constructor predeterminado; un constructor que acepte un vector ya existente de objetos tipo UpdatedBook; un método para agregar un libro a la biblioteca; un método para obtener el número de libros en la biblioteca; y un método para imprimir información sobre cada libro de la biblioteca. Escriba un programa de prueba que cree una biblioteca y unos cuantos libros. Su programa debe agregar y eliminar estos libros de la biblioteca e imprimir información sobre los libros en la biblioteca.

Observaciones: 

Subir su solución en un solo archivo cpp.
Usar encabezados con su información y descripción del archivo. Hacer una corta descripción de cada clase antes de declararla y documentar su forma de uso. 
Usar al menos 10 libros de ejemplo, si desea ejemplos reales, puede obtenerlos del siguiente "Dataset": https://www.kaggle.com/datasets/saurabhbagchi/books-dataset, extraer solo la información solicitada.
Se comparará su solución con la de sus compañeros y sitios de Internet. Se recomienda escribirla desde cero con su propio estilo.  
