/*
 * defines.h
 *
 *  Created on: Sep 30, 2022
 *      Author: LucasLaurindo
 */

#ifndef INC_DEFINES_H_
#define INC_DEFINES_H_


/*---------   SEM CATEGORIA	------------------------------------------------*/
#define PRESSAO 0
#define POSICAO 1
/*---------   SEM CATEGORIA	------------------------------------------------*/


/*---------   FIXOS	---------------------------------------------------------*/

/*---MASTER GIGA---*/
enum 		STATE_Giga{
	GIGA_EM_ESPERA	,
	GIGA_CONECTANDO,
	SETA_VAR			,
	PRE_DESCE		,
	AVALIA_DESCIDA	,
	AVALIA_SUBIDA	,
	DESCE_TUDO		,
	AVALIA_DESCIDA2,
	AVALIA_CMPRS	,
	LIGA_CMPRS		,
	GIGA_DESCON		,
	GIGA_ERRO	=	99
};
enum 		ID_Erro{
	ERRO_FL_IN		,
	ERRO_FR_IN		,
	ERRO_RL_IN		,
	ERRO_RR_IN		,
	ERRO_FL_OUT		,
	ERRO_FR_OUT		,
	ERRO_RL_OUT		,
	ERRO_RR_OUT		,
	ERRO_CMPRS

};

//ENDERECO DE VARIAVEIS DE MEMORIA
//ATUALIZAR SEMPRE O NUMERO DE VARIAVEIS NA EEPROM.H
#define DEF_VERSAO_CONTROLE				0x0201
#define MEM_FLAG_FORMAT						0x0034//-- FLAG FORMATACAO
#define MEM_FLAG_FORMAT_VALUE				0x0032//-- FLAG FORMATACAO
#define MEM_BRILHO_TELA				 		0x0036//-- BRILHO DE TELA
#define MEM_TEMPO_TELA				 		0x0040//-- TEMPO DE TELA LIGADA
#define MEM_MODO_PAINEL				 		0x0042//-- TEMPO DE TELA LIGADA
#define MEM_CHAVE_VALOR			 			0x0043//-- VALOR DA CHAVE SALVA NA MEMORIA
#define MEM_RESTAURA_HM10		 			0x0044//-- VALOR DA CHAVE SALVA NA MEMORIA
#define MEM_T_OPEN				 			0x0046//-- TEMPO DE VALVULA ABERTA
#define MEM_T_CLOSE				 			0x0048//-- TEMPO DE VALVULA FECHADA
#define MEM_T_ESTABIL			 			0x0050//-- TEMPO DE ESTABILIZACAO
#define MEM_CHAVE_FLAG					 	0x0060//-- FLAG QUE INDICA SE TEM UMA CHAVE SALVA NA MEMORIA OU NAO


//ESTRUTURA VARIAVEIS VINDAS DO CARRO
enum 		STATE_Altura{
	STATE_ZERADO			,
	STATE_ALTURA_1 		,
	STATE_ALTURA_2  		,
	STATE_ALTURA_3  		,
	STATE_ALTURA_4  		,
	STATE_ALTURA_CUSTOM	,
	STATE_BUSCANDO_VAZ
};

//ESTRUTURA VARIAVEIS DE SENSORES-----------------
enum 		Modo_SetPoint{
	SETPOINT_PRESSAO,
	SETPOINT_POSICAO,
	MANUAL_POSICAO,
	SEM_SENSOR
};

//STATES IDIOMAS
#define EN 0
#define PT 1
#define ES 2

//STATE_PRINCIPAL
#define CENTRAL_NORMAL			0x00
#define CENTRAL_DESCALIBRADA	0x01
#define CENTRAL_ERRO_SENSOR	0x02

//ESTADO UNIVERSAL DE STATES COMPRESSOR
#define LIGADO			1
#define DESLIGADO		0
#define COOLDOWN		2

//STATES BATERIA
#define BAT_OFF					0xff
#define BAT_NIVEL0				0x00
#define BAT_NIVEL1				0x01
#define BAT_NIVEL2				0x02
#define BAT_NIVEL3				0x03
#define CARREGADO					0x04
#define CARREGANDO				0x05
#define BAT_WEAK					0x06
#define BAT_UVLO					0x07
#define DEF_AD_OFF_BATTERY		2724	//VALOR MINIMO PARA LOW BATTERY
#define DEF_AD_0_BATTERY		2871	//VALOR MINIMO PARA 30% BATTERY
#define DEF_AD_1_BATTERY		3018	//VALOR MINIMO PARA 60% BATTERY
#define DEF_AD_2_BATTERY		3165	//VALOR MINIMO PARA 30% BATTERY
#define DEF_AD_3_BATTERY		4095	//VALOR MINIMO PARA 60% BATTERY
#define HISTERESE_BAT			50		//VALOR MAXIMO PARA 100% BATTERY

//MAQUINA BATERIA
#define Q_BATERIA_MUITO_BAIXA	0x01
#define Q_EM_CARGA				0x02

//MAQUINA MAIN
#define MAIN_AGUARDANDO					0x00
#define MAIN_DESCOBERTA_NEW			0x01
#define MAIN_CONECTA_NEW				0x02
#define MAIN_PEDE_CHAVE					0x03
#define MAIN_ENVIA_CHAVE				0x07
#define MAIN_CONECTA_PASSADO			0x06
#define MAIN_PEDE_SINC					0x08
#define MAIN_SALVA_CHAVE				0x09
#define MAIN_CHAVE_ERRO					0x05
#define MAIN_CALIBRACAO_MAX			0x10
#define MAIN_CALIBRACAO_MIN			0x11
#define MAIN_DESCONECTA					0xaa
#define MAIN_DESLIGA						0xcc
#define MAIN_ACORDA						0xee
#define MAIN_ENVIA_TX					0x21
#define MAIN_ESPERA_RESPOSTA			0x22

//MAQUINA RECEPCAO
#define RX_AGUARDA_INDICE_CON			1
#define RX_AGUARDA_DISCE				2
#define RX_AGUARDA_CON_OK_DISC		3
#define RX_AGUARDA_CHAVE				4
#define RX_PROTOCOLO_MRRIDER			5
#define RX_AGUARDA_RESPOSTA_CHAVE	6
#define RX_AGUARDA_CON_OK_NRML		7
#define RX_AGUARDA_SINC					8

//DEFINES COMUNICAÇÃO UART_DMA
#define TX_DESCOBERTA					1
#define TX_CONECTA_INDICE				2
#define TX_PEDE_CHAVE					3
#define TX_ENVIA_CHAVE					4
#define TX_BT_RESET						5
#define TX_BT_DESCOBERTA_NEW			6
#define TX_BT_CONECTA_NEW				7
#define TX_BT_CONECTA_PASSADO			8
#define TX_SOLICITA_REALTIME			9
#define TX_NOVOS_SETPOINTS				10
#define TX_SOLICITA_SINCRONIA			11
#define TX_SETPOINT_EXECUCAO			12
#define TX_SALVA_NOVA_ALTURA			13
#define TX_NORMALIZADOR					14
#define TX_ZERAMENTO						15
#define TX_BURST_VALVULA				16
#define TX_CAL_MAX						17
#define TX_CAL_MIN						18
#define TX_MODO_AUTO						19
#define TX_CMPRS_PRESSURES				20
#define TX_CMPRS_TEMPOS					23
#define TX_CMPRS_BURST					21
#define TX_CMPRS_CANCEL_COOLDOWN		24
#define TX_ALTERA_S_SENSOR				22
#define TX_ALTERA_C_SENSOR				26
#define TX_VAR_GIGA						65

//ESTADOS BLUETOOTH
#define CONECTADO	 				1
#define DESCONECTADO				0
#define CONECTANDO				2
#define DMA_RX_BUFFER_SIZE    128
#define DMA_ADC_SIZE          6
#define MY_ADDRESS            0x01

//DEFINE STATE UNIVERSAL
#define UNIVERSAL_ENVIA_IDLE				1
#define UNIVERSAL_DISC_NEW					2
#define UNIVERSAL_AGUARDA_INDICE			3
#define UNIVERSAL_AGUARDA_DISCE			4
#define UNIVERSAL_CON_NEW					5
#define UNIVERSAL_AGUARDA_CONOK_DISC	6
#define UNIVERSAL_PEDE_CHAVE				7
#define UNIVERSAL_ESPERA_CHAVE			8
#define UNIVERSAL_ENVIA_CHAVE				9
#define UNIVERSAL_RECEBE_RESULT_CHAVE	10
#define UNIVERSAL_SOLICITA_REALTIME 	11
/*---------   FIXOS	------------------------------------------------------*/

/*---------   AJUSTÁVEIS	------------------------------------------------*/

//CALCULO DE MEDIAS
#define TAM_MEDIA_BAT			10			//	numero de amostras para calcular media de bateria
#define DELAY_READ_AD_BAT		2			//	delay em segundos para começar a mostrar os valor lido da bateria

//TEMPOS DE CLIQUE DE BOTAO
#define DEF_CLICK_CURTO			2			// multiplicado por 10ms    -> ex 2 	== 20 ms
#define DEF_CLICK_LONGO			100		// multiplicado por 10ms    -> ex 100 	== 1 s
#define DEF_CLICK_MUITO_LONGO	300		// multiplicado por 10ms    -> ex 100 	== 1 s
#define DEF_CLICK_ZERAR			300		// multiplicado por 10ms    -> ex 100 	== 1 s
#define DEF_TEMPO_MAX_MENU		12 		// 10 SEGUNDOS	- tempo máximo no menu
#define DEF_TEMPO_BURST			20 		// multiplicado por 10ms    -> ex 20 	== 200 ms
#define DEF_TEMPO_INCREMENTO	50 		// multiplicado por 10ms    -> ex 20 	== 200 ms
//incrementos de botoes
#define DEF_INCREMENTO_CMPRS_TEMPO_POSCHAVE	5

//MAXIMOS ADMITIDOS//REVISAR CLASSIFICAR UNIDADE DE TEMPO EM CADA COMENTARIO
/*AUTOAJUSTE*/
#define MAX_VALOR_SETPOINT						100	//%
/*COMPRESSOR*/
#define LIMITE_SUPERIOR_MAX_SP_CMPRS		180	//PSI
#define LIMITE_INFERIOR_MAX_SP_CMPRS		90		//PSI
#define LIMITE_SUPERIOR_MIN_SP_CMPRS		150	//PSI
#define LIMITE_INFERIOR_MIN_SP_CMPRS		50		//PSI
#define HISTERESE_MAX_MIN_CMPRS				30		//PSI
#define DEF_PASSO_SP_CMPRS						10		//PSI
#define LIMITE_SUPERIOR_TEMPO_CMPRS			40		//MINUTOS
#define LIMITE_INFERIOR_TEMPO_CMPRS			5		//MINUTOS
#define LIMITE_MAX_DELAY_CMPRS				60		//SEGUNDOS
#define LIMITE_MIN_DELAY_CMPRS				0		//SEGUNDOS
#define DEF_PASSO_DELAY_CMPRS					5		//SEGUNDOS
/*INTERFACE*/
#define LIMITE_MIN_BRILHO				0		//%
#define LIMITE_MAX_BRILHO				100	//%
#define DEF_PASSO_BRILHO				10		//%
#define LIMITE_MIN_TEMPO_TELA			0		//SEGUNDOS
#define LIMITE_MAX_TEMPO_TELA			200	//SEGUNDOS
#define DEF_PASSO_TEMPO_TELA			15		//SEGUNDOS
/*AJUSTES*/
#define LIMITE_MIN_T_OPEN				5		//ms
#define LIMITE_MAX_T_OPEN				250	//ms
#define LIMITE_MIN_T_CLOSE				5		//ms
#define LIMITE_MAX_T_CLOSE				250	//ms
#define LIMITE_MIN_T_ESTABIL			5		//x10 ms
#define LIMITE_MAX_T_ESTABIL			250	//x10 ms
//ESTADOS BLUETOOTH
#define DEF_LIMITE_TENTATIVAS			3		// tentativas de reenvio da mensagem e esperando aknoladge
#define TIMEOUT_MAQUINA_TX				500	// TIMEOUT DE 500ms, DEPOIS DISSO ZERA O ULTIMO ENVIO E "PERDE CONEXÃO"
#define TIMEOUT_RX_OCIOSO				60		// TIMEOUT DE 60s, DEPOIS DISSO ENTRA EM SLEEP + CONDIÇÃO DE POSCHAVE OFF
#define LIMITE_TEMPO_SEM_MENSAGEM	8		// x100 -> 3 = 300ms - TEMPO MAXIMO ADIMITIDO SEM MENSAGEM
//timouts de autoconexao e reconexao
#define DEF_TIMEOUT_RX_AGUARDA_INDICE_CON			4 	//segundos - esperando revisar completar texto segundo fluxograma
#define DEF_TIMEOUT_RX_AGUARDA_DISCE				5 	//segundos - esperando revisar completar texto segundo fluxograma
#define DEF_TIMEOUT_RX_AGUARDA_CON_OK_NRML		2 	//segundos - esperando revisar completar texto segundo fluxograma
#define DEF_TIMEOUT_RX_AGUARDA_RESPOSTA_CHAVE	2 	//segundos - esperando revisar completar texto segundo fluxograma
#define DEF_TIMEOUT_RX_AGUARDA_CHAVE				2 	//segundos - esperando revisar completar texto segundo fluxograma
#define DEF_TIMEOUT_RX_AGUARDA_CON_OK_DISC		10	//segundos - esperando revisar completar texto segundo fluxograma
#define DEF_TIMEOUT_RX_AGUARDA_SINC					2	//segundos - esperando revisar completar texto segundo fluxograma

//DEFINES MAQUINA CONEXAO //REVISAR CLASSIFICAR UNIDADE DE TEMPO NOS COMENTARIOS
#define TENTATIVAS_NEW_ADDRESS	5
#define ANALISE_DE_CONEXAO 		1
#define TENTA_CONECTAR				2
#define AGUARDA_CONEXAO 			3
#define NOVA_CONEXAO			 		4
#define ANALISA_NOVA_CONEXAO		5

/*---------   AJUSTÁVEIS	------------------------------------------------*/


/*---------- M A C R O S --------------------------------------------------*///REVISAR, COMENTAR E ORGANIZAR TODAS AS MACROS
//LEITURA DE BOTOES
#define READ_UP			HAL_GPIO_ReadPin 	(PB_UP_GPIO_Port,	PB_UP_Pin)
#define READ_DOWN			HAL_GPIO_ReadPin 	(PB_DOWN_GPIO_Port,	PB_DOWN_Pin)
#define READ_MENU			HAL_GPIO_ReadPin 	(PB_MENU_GPIO_Port,	PB_MENU_Pin)
#define READ_BACK			HAL_GPIO_ReadPin 	(PB_BACK_GPIO_Port,	PB_BACK_Pin)
#define READ_H1			HAL_GPIO_ReadPin 	(PB_H1_GPIO_Port,	PB_H1_Pin)
#define READ_H2			HAL_GPIO_ReadPin 	(PB_H2_GPIO_Port,	PB_H2_Pin)
#define READ_H3			HAL_GPIO_ReadPin 	(PB_H3_GPIO_Port,	PB_H3_Pin)
#define READ_H4			HAL_GPIO_ReadPin 	(PB_H4_GPIO_Port,	PB_H4_Pin)

//MANIPULACAO E LEITURA DO CIRCUITO DE BATERIA
#define M_BAT_OUT_ON		HAL_GPIO_WritePin	(SW_Vbat_GPIO_Port,		SW_Vbat_Pin,GPIO_PIN_SET);	//
#define M_BAT_OUT_OFF	HAL_GPIO_WritePin	(SW_Vbat_GPIO_Port,		SW_Vbat_Pin,GPIO_PIN_RESET);	//
#define M_BAT_IN			HAL_GPIO_ReadPin 	(SIG_CHRG_GPIO_Port,	SIG_CHRG_Pin)
#define ON_AD_BATERIA   	HAL_GPIO_WritePin(SW_VBAT_GPIO_Port,SW_VBAT_Pin,GPIO_PIN_SET);	//LIGA LEITURA AD BATERIA
#define OFF_AD_BATERIA    	HAL_GPIO_WritePin(SW_VBAT_GPIO_Port,SW_VBAT_Pin,GPIO_PIN_RESET);	//DESLIGA LEITURA AD BATERIA

//CONTROLE DO TPL5111
#define ON_TPL5111   		HAL_GPIO_WritePin(ON_OFF_GPIO_Port,ON_OFF_Pin,GPIO_PIN_SET);	//LIGA ON NO TPL5111
#define OFF_TPL5111    		HAL_GPIO_WritePin(ON_OFF_GPIO_Port,ON_OFF_Pin,GPIO_PIN_RESET);	//DESLIGA ON NO TPL5111

//CONTROLE DOS LEDS 1 2 3 4
#define LED_H1_ON			HAL_GPIO_WritePin(PULSE_H1_GPIO_Port,PULSE_H1_Pin,GPIO_PIN_SET);
#define LED_H1_OFF			HAL_GPIO_WritePin(PULSE_H1_GPIO_Port,PULSE_H1_Pin,GPIO_PIN_RESET);

#define LED_H2_ON			HAL_GPIO_WritePin(PULSE_H2_GPIO_Port,PULSE_H2_Pin,GPIO_PIN_SET);
#define LED_H2_OFF			HAL_GPIO_WritePin(PULSE_H2_GPIO_Port,PULSE_H2_Pin,GPIO_PIN_RESET);

#define LED_H3_ON			HAL_GPIO_WritePin(PULSE_H3_GPIO_Port,PULSE_H3_Pin,GPIO_PIN_SET);
#define LED_H3_OFF			HAL_GPIO_WritePin(PULSE_H3_GPIO_Port,PULSE_H3_Pin,GPIO_PIN_RESET);

#define LED_H4_ON			HAL_GPIO_WritePin(PULSE_H4_GPIO_Port,PULSE_H4_Pin,GPIO_PIN_SET);
#define LED_H4_OFF			HAL_GPIO_WritePin(PULSE_H4_GPIO_Port,PULSE_H4_Pin,GPIO_PIN_RESET);

//LEITURA STATUS DO BLUETOOTH
#define MACRO_LE_BT_STATUS	HAL_GPIO_ReadPin 	(BT_STATUS_GPIO_Port,	BT_STATUS_Pin)

//ALGUMAS FUNCOES UART RESUMIDAS
#define MACRO_ENVIA_AKNOLADGE 		Serial.TX_Buffer[0] = 0x01;\
		Serial.TX_Buffer[1] = 0xFF;\
		Serial.TX_Buffer[2] = 0xFF;\
		HAL_UART_Transmit(&huart1,TX_Buffer,3,100);	//---- ENVIO DE AKNOLADGE

#define MACRO_ENVIA_ERRO_CRC 		Serial.TX_Buffer[0] = 0x01;\
		Serial.TX_Buffer[1] = 0xEE;\
		Serial.TX_Buffer[2] = 0xEE;\
		HAL_UART_Transmit(&huart1,TX_Buffer,3,100);	//---- ENVIO DE AKNOLADGE

#define MACRO_ENVIA_NORMALIZADOR	Serial.TX_Buffer[0] = 0x01;\
		Serial.TX_Buffer[1] = 0xDD;\
		Serial.TX_Buffer[2] = 0xDD;\
		HAL_UART_Transmit(&huart1,TX_Buffer,3,100);	//---- ENVIO DE AKNOLADGE


#define MACRO_AGUARDA_DISCE		MAQUINA_Recepcao 	= RX_AGUARDA_DISCE;

#define MACRO_AGUARDA_CONOK_DISC	MAQUINA_Recepcao 	= RX_AGUARDA_CON_OK_DISC;

#define MACRO_AGUARDA_CONOK_NRML	MAQUINA_Recepcao 	= RX_AGUARDA_CON_OK_NRML;

#define MACRO_AGUARDA_INDICE	MAQUINA_Recepcao 	= RX_AGUARDA_INDICE_CON;

#define MACRO_AGUARDA_CHAVE		MAQUINA_Recepcao 	= RX_AGUARDA_CHAVE;

#define MACRO_PROTOCOLO_RX		MAQUINA_Recepcao 	= RX_PROTOCOLO_MRRIDER;

#define MACRO_ENVIA_TX		\
		FLAG_ENVIA_TX 	= 1;	\
		Serial.Last_TX = Serial.Envia_TX;

#define ENVIA_TX(CODE) 		\
		Serial.Envia_TX = CODE;\
		FLAG_ENVIA_TX 	= 1;	\
		Serial.Last_TX = Serial.Envia_TX;


//ARREDONDADOR ((n + denominator -1) / denominator )* denominator
#define MACRO_ROUND_5(x)	((x+4)/5)*5

//FUNCOES PARA MANIPULACAO DE COTROLE_ALTO NIVEL
#define MACRO_DESLIGA				\
		debugPrintln(&huart1,"AT");\
		HAL_Delay(100);				\
		debugPrintln(&huart1,"AT");\
		HAL_Delay(100);				\
		u8g_SleepOn(&u8g);			\
		HAL_TIM_Base_Stop_IT	(&htim2) ;	\
		htim2.Instance->CCR3 = 0	;\
		HAL_Delay(300);				\
		ON_TPL5111						\
		HAL_Delay(10);					\
		OFF_TPL5111						\
		HAL_Delay(10);					\
		ON_TPL5111

#define MACRO_RESET_BLE			HAL_GPIO_WritePin		(BT_RESET_GPIO_Port,		BT_RESET_Pin	,GPIO_PIN_RESET);\
	HAL_Delay(200);\
	HAL_GPIO_WritePin		(BT_RESET_GPIO_Port,		BT_RESET_Pin	,GPIO_PIN_SET);

#define SetaBrilho(x) 	u8g_SetContrast(&u8g, ceil(x*2.5));\
		htim2.Instance->CCR3 = (ceil(x/10)+1);

#define Zera_Click	(Percent_bat != BAT_OFF && Controle.Aviso.Bateria_baixa == SEM_NOTIFICACAO)?Cont_sem_click = 0:0;

#define MACRO_IMPRIME_TESTE_BOTAO(x) u8g_FirstPage(&u8g);\
		do {\
			Draw_imprime_passo(x);\
		} while( u8g_NextPage(&u8g));


#define MACRO_VERSAO_P5 Carro.Versao.byte.lo == 0x01

#define MACRO_RETORNA_MENU			Menu_Current_Principal 			= 0; \
											Aux_Update_Menu_Principal 		= 0; \
											Menu_Current_Principal_p5  	= 0; \
											Aux_Update_Menu_Principal_p5 	= 0; \
											Menu_Current_Interface 			= 0; \
											Aux_Update_Menu_Principal 		= 0; \
											Menu_Current_Interface			= 0; \
											Aux_Update_Menu_Interface		= 0; \
											Menu_Current_Compressor			= 0; \
											Aux_Update_Menu_Compressor		= 0; \
											Menu_Current_Sensor				= 0; \
											Aux_Update_Menu_Sensor			= 0; \
											Menu_Current_Pressao				= 0; \
											Aux_Update_Menu_Pressao			= 0; \
											Menu_Current_Ajustes				= 0; \
											Aux_Update_Menu_Ajustes			= 0; \
											Menu_Current_Pressao_Tempos	= 0; \
											Aux_Update_Menu_Pressao_Tempos=0;



#endif /* INC_DEFINES_H_ */
