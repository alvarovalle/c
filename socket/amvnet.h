#ifndef AMVNET_H
#define AMVNET_H

void error(const char *msg);
int enviar(char *servidor, char *porta, char *mensagem);
int receber(char *porta);

#endif
