# mavi-final

## Consigna
* Programación Orientada a Objetos (POO): 
	Utiliza este paradigma para estructurar tu videojuego de manera organizada y eficiente. Los objetos serán fundamentales para modelar personajes, escenarios y elementos interactivos. Esto significa usar clases determinadas por archivos de cabecera y los que contienen el código de dicha clase
- Implementación de física: 
	Da vida a tu mundo virtual aplicando conceptos como el MRU (Movimiento Rectilíneo Uniforme) y el MRUA (Movimiento Rectilíneo Uniformemente Acelerado) para generar movimientos realistas en los objetos del juego. Esto es obligatorio para poder aprobar el trabajo.
- Música y efectos de sonido: 
	Añade una banda sonora y efectos sonoros que enriquezcan la experiencia del jugador y aumenten la inmersión en la aventura.
* Compatibilidad y optimización: 
	Asegúrate de que tu videojuego funcione adecuadamente en cualquier computadora, garantizando un rendimiento estable y óptimo para una experiencia fluida.
* Función de reinicio: 
	Implementa la posibilidad de reiniciar el juego para permitir a los jugadores intentarlo nuevamente cuando lo necesiten.
* Menú y condición de fin: 
	El juego debe presentar menú de inicio donde explica cómo se juega, salir y comenzar. También debe presentar un menú de condición de ganador o perdedor mostrando el puntaje obtenido si es que lo amerita el juego. Cualquier cosa extra será bienvenida.
* HUD: 
	Debe presentarse un controlador de juego en tiempo real, por ejemplo, un reloj, un contador de enemigos abatidos, un registro de saltos, etc, la idea es mostrar algo en pantalla al jugador.

## Review

- [x] Programación Orientada a Objetos (POO): 
	* Clases bases:
		* GameObject => Todos los elementos visuales derivan de ella
		* Scene => Las tres escenas derivan de ella
		* Enemy => Los 5 enemigos derivan de ella. Ella misma deriva de GameObject
		* IDisposable => Es esencialmente una interfaz
	* Me hubiera gustado abordar una arquitectura que permita mayor composición, separando objetos updateables, drawables y colisionables. Pero se me re hubiera ido de scope.
		
- [x] Implementación de física: 
	* MRU => Todos los enemigos usan esta movimiento de alguna manera
		* EnemyRed => es su movimiento base en eje x
		* EnemyGreen => es su movimiento base en eje x
		* EnemyOrange => es su movimiento base en eje x, cando va, cuando vuelve y cuando vuelve a ir
		* EnemyBlue => es su movimiento base en eje x
		* EnemyPurple =>  => es su movimiento base en eje x en la acción inicial de posicionarse
	* MRUA (Movimiento Rectilíneo Uniformemente Acelerado) => En la nave del jugador
- [x] Música y efectos de sonido: 
	* Hay un tema de fondo de los Killers
	* Hay 4 SFX:
		* Disparo
		* Explosión
		* Choque
		* Recarga
		
- [x] Compatibilidad y optimización: 
	* Utilizo delta time en todo
	* Tenía un memory leak en los pool que fue solucionado
- [x] Función de reinicio
- [x] Menú y condición de fin
	* Nota: Se agregó navegación por teclas, el juego no admite uso de mouse
- [x] HUD: 
	* En el HUD podemos ver:
		* Puntaje
		* Salud de la nace
		* Barra de cooldown del cañón
