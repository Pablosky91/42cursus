El archivo se llama Makefile.
Los comentarios son de una línea y comienzan con #
Se pueden partir las líneas con un \

Al comienzo del archivo se escriben variables.
Variables automáticas: https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
Las variables se escriben en mayúsculas, un = y el valor.
	MY_VAR = value
Se pueden asignar otras variables con la sintaxis $()
	OTHER_VAR = copy of $(MY_VAR)
Las variables utilizan el último valor que han recibido.
Para evitarlo, utilizar :=f

Después de las variables se escriben las reglas.
Si se ejecuta simplemente make sin especificar regla, se ejecuta la primera.
Las reglas se escriben en minúsculas, un : y las dependencias. En consecutivas líneas se puede escribir comandos.
	my_rule : sub_rule
		echo Hello
	sub_rule:
		echo sub_rule
Por defecto, los comandos se escriben en la terminal.
Para evitarlo, empezar e comando con @
Reglas implícitas: https://www.gnu.org/software/make/manual/html_node/Catalogue-of-Rules.html
