/*
 * estruturas.h
 *
 *  Created on: Sep 29, 2022
 *      Author: LucasLaurindo
 */

#ifndef INC_ESTRUTURAS_H_
#define INC_ESTRUTURAS_H_

#include "main.h"

//AGRUPAMENTO CRC 2 BYTES EM 1 SHORT-------------------------------------------
typedef union CRC_short
{
		struct
		{
				unsigned char hi;
				unsigned char lo;
		}byte;
		short hilo;
}CRC_short;

//STRUTURA AGRUPAMENTO VARIAVEIS DE BOLSAS-------------------------------------
typedef union TYPE_BOLSAS
{
		struct
		{
				uint8_t	FL;
				uint8_t	FR;
				uint8_t	RL;
				uint8_t	RR;
		}byte;
		uint32_t tipo_32_bits;
}TYPE_BOLSAS;

//STRUTURA AGRUPAMENTO DE 8 BITS EM 1 BYTE-------------------------------------
typedef union BIT_TO_BYTE_SENSOR
{
		struct
		{
				unsigned char FL 					: 1;
				unsigned char FR 					: 1;
				unsigned char RL 					: 1;
				unsigned char RR 					: 1;
				unsigned char USO_SENSORES 	: 1;
				unsigned char FLAG_ERRO			: 1;
				unsigned char AUX1				: 1;
				unsigned char AUX2				: 1;

		}bit;
		unsigned char byte;
}BIT_TO_BYTE_SENSOR;

//STRUTURA PARA TRANSMISSAO DE OCUPANTES
typedef union TIPO_OCUPANTES
{
		struct
		{
				unsigned char FL 					: 1;
				unsigned char FR 					: 1;
				unsigned char RL 					: 1;
				unsigned char RR 					: 1;
				uint8_t		 MALA;

		}bit;
		uint32_t tipo_32_bits;
}TIPO_OCUPANTES;

//STRUTURA AGRUPAMENTO DE 8 BITS EM 1 BYTE ----------------------------------
typedef union BIT_TO_BYTE_BURST
{
		struct
		{
				unsigned char IN_FL 	: 1;
				unsigned char IN_FR 	: 1;
				unsigned char IN_RL 	: 1;
				unsigned char IN_RR 	: 1;
				unsigned char OUT_FL : 1;
				unsigned char OUT_FR : 1;
				unsigned char OUT_RL : 1;
				unsigned char OUT_RR : 1;
		}bit;
		unsigned char byte;
}BIT_TO_BYTE_BURST;

//ESTRUTURA VARIAVEIS DE BOTAO -----------------------------------------
typedef struct {
		bool 	FLAG;
		bool 	LAST_FLAG;
		uint16_t 	ContPress;
		uint16_t 	Cont_N_Press;
}Type_Botao;

//ESTRUTURA VARIAVEIS DE VAZAMENTO -----------------------------------------
struct VAZAMENTO {
		bool			FLAG_vaz		;	// ao final do auto ajuste, verifica-se essa flag para direcionar a maquina main
		uint32_t		Tempo_busca		;	// é setado no momento em que ativa a busca
		uint32_t		Recorrencia		;	// Numero de recorrencias de vazamento
		BIT_TO_BYTE_SENSOR Conexoes		;	// array que identifica qual ponto esta em vazamento
		BIT_TO_BYTE_SENSOR Conexoes_LAST	;	// array que identifica qual ponto esta em vazamento
		BIT_TO_BYTE_SENSOR Vaz_detectado	;	// vazamento que fo detectado da ultima vez para envio
};

//ESTRUTURA VALORES DE BOLSAS ---------------------------------------------
struct BOLSAS{
		uint8_t	FL;
		uint8_t	FR;
		uint8_t	RL;
		uint8_t	RR;
};

//ESTRUTURA VARIAVEIS VINDAS DO CARRO ------------------------------------
typedef struct {
		uint8_t		Altura_setada; 					//ALTURA SETADA NA CENTRAL, RECEBIDO PELO SINCRONIA
		uint8_t		State_CMPRS;						//ESTADO ATUAL DO COMPRESSOR REVISAR:NAO IMPLEMENTADO
		uint8_t 		Pressure_CMPRS; 					//PRESSAO ATUAL DO COMPRESSOR REVISAR:NAO IMPLEMENTADO
		uint8_t		CMPRS_Tempo_max_on;				//TEMPO MAXIMO DE COMPRESSOR ATIVO REVISAR:NAO IMPLEMENTADO
		uint8_t		CMPRS_Delay_PC;					//TEMPO MAXIMO DE COMPRESSOR ATIVO REVISAR:NAO IMPLEMENTADO
		uint8_t 		Min_Pressure_CMPRS;				//PRESSAO MINIMA SALVA NA MEMORIA
		uint8_t		Max_Pressure_CMPRS;				//PRESSAO MAXIMA SALVA NA MEMORIA
		uint8_t		State_PosChave;					//ESTADO DO POSCHAVE NA CENTRAL REVISAR:NAO IMPLEMENTADO
		uint8_t		MAQUINA_Main_Central;			//ESTADO DA MAQUINA PRINCIPAL NA CENTRAL REVISAR:NAO IMPLEMENTADO
		uint8_t 		Delay_2_Rise	;					//Delay para executar o subir ao ligar
		uint8_t 		Delay_2_Drop	;					//Delay para executar o descer ao desligar
		uint8_t 		Modo_auto		;					//Flag para executar o descer ao desligar
		CRC_short 	Versao			;					//Versao do firmware instalado na central
		TYPE_BOLSAS 			Bolsa_RealTime	;
		TYPE_BOLSAS 			Altura_SetPoint;
		TYPE_BOLSAS 			Banco_pulsos;
		TYPE_BOLSAS 			Tempo_IN			;	//	tempo de valvula aberta - milisegundos
		TYPE_BOLSAS 			Tempo_OUT		;	//	tempo de valvula fechada - milisegundos
		uint8_t					Tempo_FECHADA;		// milisegundos
		uint8_t					Tempo_ZERAMENTO;	// milisegundos
		uint16_t					Tempo_ESTABIL; 	// milisegundos * 10
		BIT_TO_BYTE_SENSOR 	Sensores_state;
		uint8_t					FLAG_notify_erro_sensor;
		BIT_TO_BYTE_BURST		Burst;
}//
CARRO;//

//ESTRUTURA VARIAVEIS DE AVISO ------------------------------------------
enum 		Aviso{
	SEM_NOTIFICACAO,
	PENDENTE,
	EM_FOCO,
	VISUALIZADO
};
typedef struct {

		uint8_t	Compressor;
		uint8_t	Bateria_baixa;
		uint8_t	Conexao_negada;
		uint8_t	Calibrando;
		uint8_t	Sens_erro;
		uint8_t	Sens_descal;
		uint8_t	Sens_calibrados;
		uint8_t	Sens_cal_invaliada;
		uint8_t	Conectando;
		uint8_t	Desconectado;
		uint8_t	Versao;
}//
Aviso_Struct;//

//ESTRUTURA VARIAVEIS FORMANDO O CONTROLE -----------------------------
enum 		PiscaTela{
	DESABILITADO,
	ATIVO_ON,
	ATIVO_OFF
};
typedef struct
{
		uint8_t 	Brilho;    				//BRILHO DA TELA E DO TECLADO
		uint32_t	Tempo_tela;        	//TEMPO DE TELA
		uint16_t	T_open;        		//TEMPO DE VALVULA ABERTA
		uint16_t	T_close;        		//TEMPO DE VALVULA FECHADA
		uint16_t	T_estabil;        	//TEMPO DE ESTABILIZACAO
		uint8_t 	Modo_painel;       	//FLAG MODO PAINEL SETADO OU NAO
		uint8_t 	FLAG_Altura_2_salve; //Altura selecionada para salvar, precisa inicializar
		uint8_t	State_bat;				//Estados de bateria, podendo ser 1,2,3,4 ou 5 revisar
		bool	FLAG_Pisca_tela;		//enum definindo quais estados possiveis  ,precisa inicializar
		uint8_t	Modo_SetPoint;			//Fica no modo manual ou no modo SETPOINT
		uint16_t Cont_sem_click;		//cont sem click algum
		uint16_t Cont_ligado;			//cont desde que ligou
		uint8_t	Sleep_conectado;
		CRC_short 	Versao;					//Versao do firmware instalado no controle
		bool 		sel_FL;					//Selecao FRONT LEFT
		bool 		sel_FR;					//Selecao FRONT RIGHT
		bool 		sel_RL;					//Selecao REAR LEFT
		bool 		sel_RR;					//Selecao REAR RIGHT
		bool 		LED_1;
		bool 		LED_2;
		bool 		LED_3;
		bool 		LED_4;
		bool 		LED_5;
		Aviso_Struct Aviso;
		uint8_t Idioma;
}//
Type_controle;//

//ESTRUTURA VARIAVEIS DE USO DO BLUETOOTH ------------
struct BLE_HM10{
		uint8_t 	Indice_conexao;			//INDICE POR CONEXAO VIA VETOR
		uint8_t 	Status_conexao_BT;		//VARIAVEL QUE INDICA SE TEM ALGUÉM CONECTADO OU NAO
};

//ESTRUTURA VARIAVEIS DE USO DO BLUETOOTH ----------------------------
#define DMA_RX_BUFFER_SIZE       128
#define TX_BUFFER_SIZE          	128
#define UART_BUFFER_SIZE         256
typedef struct{
		uint8_t			DMA_RX_Buffer	[DMA_RX_BUFFER_SIZE]	;	//BUFFER Endereco_central VIA UART
		unsigned char	TX_Buffer		[TX_BUFFER_SIZE]		;	//BUFFER AUXILIAR DO "DMA_CIRCULAR.C" de uint8 -> uchar
		char 				Buff_send		[20];
		char				String_recebida[64];
		uint8_t			indice;
		char				ADDR1[64];
		char				ADDR2[64];
		char				ADDR3[64];
		char				ADDR4[64];
		char				ADDR5[64];
		__IO long 		Ponto_exato;
		__IO char 		*ss;
		__IO char 		*tt;
		__IO uint8_t		DMA_RX_size						;	//TAMANHO DA INFORMACAO RECEBIDA
		__IO uint32_t		BLE_T_Conectado__10ms		;	//CONTADOR CONECTADO
		__IO uint32_t		BLE_T_Desconectado__10ms	;	//CONTADOR DESCONECTADO
		__IO uint32_t		BLE_T_Try_connect__10ms		;	//CONTADOR Tentativa conexao
		__IO uint32_t		BLE_T_Timeout_disc__10ms	;	//DECREMENTADOR para disconexao
		__IO uint16_t		BLE_T_sem_msg__100ms			;	//CONTADOR TEMPO SEM MENSAGEM
		__IO uint8_t		BLE_Indice_conexao			;	//INDICE DE DESCOBERTA
		__IO uint8_t		Maquina_DMA_RX					;	//MAQUINA DE ESTADOS RECEBIMENTO VIA DMA
		__IO uint8_t		MAQUINA_Recepcao				;	// maquina copiada da v4
		__IO uint8_t		MAQUINA_Recepcao_old			;	// maquina copiada da v4
		__IO uint16_t		CONT_Recepcao_static			;
		__IO uint8_t		CONT_tentativas				;	//quantas vezes repitiu comandos até chegar em protocolo_rx(zera essa var)
		__IO uint8_t		MAQUINA_Main					;	// maquina copiada da v4
		__IO uint8_t		Envia_TX							;	//MAQUINA PARA ENVIO NON-BLOCK DE MENSAGENS
		__IO uint8_t		Last_TX							;	//ultimo valor enviado
		bool		flag_envia							;
		bool		flag_conectando					;
		bool		BLE_Reiniciar						;	//FLAG QUE REINICIA O BLUETOOTH
		bool 		BLE_chave_OK						;	//FLAG QUE ARMAZENA VALIDACAO DE CHAVE DE ACESSO
		bool 		BT_STATUS							;	//FLAG QUE SINALIZA SE ESTA FISICAMENTE CONECTADO
		bool		DMA_Recieve_DATA					;	//FLAG QUE SINALIZA RECEBIMENTO DE DATA EM DMA_CICRULAR

		uint16_t Delay_envio;
}//
DMA_BLE_Struct;//
#endif /* INC_ESTRUTURAS_H_ */
