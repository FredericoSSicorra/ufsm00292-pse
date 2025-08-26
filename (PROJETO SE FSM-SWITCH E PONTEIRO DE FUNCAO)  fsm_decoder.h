#ifndef FSM_DECODER_H
#define FSM_DECODER_H

// Definições do protocolo
#define STX 0x02
#define ETX 0x03
#define MAX_BUFFER 256

// Protótipos dos callbacks
typedef void (*packet_handler_t)(unsigned char *data, int len);
typedef void (*error_handler_t)(void);

/**
 * @brief Inicializa a máquina de estados do decodificador.
 *
 * @param on_packet_ok Callback para pacotes recebidos com sucesso.
 * @param on_error Callback para erros de protocolo.
 */
void fsm_init(packet_handler_t on_packet_ok, error_handler_t on_error);

/**
 * @brief Processa um bloco de dados de entrada.
 *
 * @param data Ponteiro para o buffer de dados.
 * @param len Tamanho do buffer de dados.
 */
void fsm_process_data(unsigned char *data, int len);

#endif // FSM_DECODER_H
