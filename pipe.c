
	int pipefd[2]; // Descriptores de archivo para la tubería

	// Crear la tubería
	if (pipe(pipefd) == -1) {
		perror("Error al crear la tubería");
		return 1;
	}

	// Crear un nuevo proceso
	pid = fork();

	if (pid == -1) {
		perror("Error al crear el proceso hijo");
		return 1;
	} else if (pid == 0) {
		// Código del proceso hijo

		// Cerrar el descriptor de escritura de la tubería en el proceso hijo
		close(pipefd[1]);

		// Realizar alguna operación en el proceso hijo

		// Cerrar el descriptor de lectura de la tubería en el proceso hijo
		close(pipefd[0]);

		// Terminar el proceso hijo
		return 0;
	} else {
		// Código del proceso padre

		// Cerrar el descriptor de lectura de la tubería en el proceso padre
		close(pipefd[0]);

		// Realizar alguna operación en el proceso padre

		// Cerrar el descriptor de escritura de la tubería en el proceso padre
		close(pipefd[1]);

		// Esperar a que el proceso hijo termine
		wait(NULL);

		// Terminar el proceso padre
		return 0;
	}
}