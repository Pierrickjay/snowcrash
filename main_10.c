#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 6969
#define MAX_MSG_SIZE 1024

int main() {
	int sockfd, newsockfd, clilen;
	struct sockaddr_in serv_addr, cli_addr;
	char buffer[MAX_MSG_SIZE];
	int n;

	// Création du socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("Erreur lors de la création du socket");
		exit(1);
	}

	// Initialisation de la structure serv_addr
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);

	// Attachement du socket à l'adresse et au port spécifiés
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		perror("Erreur lors de l'attachement du socket");
		exit(1);
	}

	// Écoute sur le socket
	listen(sockfd, 5);
	printf("Serveur en attente de connexion sur le port %d...\n", PORT);

	clilen = sizeof(cli_addr);

	// Accepte la connexion entrante
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0) {
		perror("Erreur lors de l'acceptation de la connexion");
		exit(1);
	}
	printf("Connexion acceptée avec un client.\n");

	// Boucle de lecture des messages du client
	while (1) {
		bzero(buffer, MAX_MSG_SIZE);
		n = read(newsockfd, buffer, MAX_MSG_SIZE - 1);
		if (n < 0) {
			perror("Erreur lors de la lecture du socket");
			exit(1);
		}
		if (n == 0) {
			printf("Le client a fermé la connexion.\n");
			break;
		}
		printf("Message reçu du client : %s", buffer);
	}

	// Fermeture des sockets
	close(newsockfd);
	close(sockfd);
	return 0;
}
