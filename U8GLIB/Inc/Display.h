#ifndef DISPLAY_H
#define DISPLAY_H

#include "main.h"

typedef enum
{
  PORTUGUES    = 0x00,
  INGLES    	= 0x01,
  ESPANHOL     = 0x02
} TELAS_Status;

typedef struct
{
		uint8_t 	Max_Itens;    				//BRILHO DA TELA E DO TECLADO
		uint8_t	Menu_Current;        	//TEMPO DE TELA
		uint8_t	Update_Menu;        		//TEMPO DE TELA
		char 		*Menu_Strings_PT[20];   //TEXTOS EM PORTUGUES
		char 		*Menu_Strings_EN[20];   //TEXTOS EM INGLES
		char 		*Menu_Strings_ES[20];   //TEXTOS EM ESPANHOL
}//
Type_TELAS;//



void Criar_tela(TELAS_Status LINGUA, char ** TEXTO);
/*--DEFINES--*/

/*telas importantes tem numero maior que 30*/
#define TELA_PRINCIPAL  				1
#define TELA_MENU  						11
#define TELA_MENU_AJUSTES 				21
#define TELA_AJUSTES_T_OPEN			22
#define TELA_AJUSTES_T_CLOSE			23
#define TELA_AJUSTES_T_ESTABIL		24
#define TELA_OCUPANTES  				20
#define TELA_NOVA_ALTURA  				2
#define TELA_CONFIRMA_NOVA_ALTURA  	3
#define TELA_AVISA_NOVA_ALTURA_OK	4
#define TELA_INTERFACE  				5
#define TELA_BRILHO  					6
#define TELA_TEMPO_DE_TELA				7
#define TELA_MODO_AUTO					8
#define TELA_BLUETOOTH			 		9
#define TELA_BLUETOOTH_DESVINCULAR	10
#define TELA_COMPRESSOR			 		12
#define TELA_COMPRESSOR_PRESSAO		13
#define TELA_COMPRESSOR_PRESSAO_E	15
#define TELA_COMPRESSOR_TEMPO	 		14
#define TELA_COMPRESSOR_TEMPO_E	 	16
#define TELA_MENU_SENSORES	 			17
#define TELA_CONFIRMA_TROCA_SENSOR 	18
#define TELA_RESTAURAR				 	19
#define TELAS_IMPORTANTES		 		30 //------SEPARADOR
#define TELA_ERRO_SENSOR				31
#define TELA_ERRO_SINC_N_AUTH			32
#define TELA_FALTA_CAL_MIN				33
#define TELA_FALTA_CAL_MAX				34

/*--DEFINES--*/

uint8_t Inicia_display(uint8_t Idioma);
void Tela_teste(void);
void Tela_Inicial_PRO(uint8_t bt_state, CARRO *Carro, Type_controle *Controle, DMA_BLE_Struct *Serial);
void Draw_menu_master(Type_controle *Controle, uint8_t Max_itens, char **mmenu_strings, uint8_t *Mmenu_Current, uint8_t *Aaux_Update_Menu);
void Draw_nova_altura(CARRO *Carro, Type_controle *Controle);
void Draw_nova_altura_temp(CARRO *Carro, Type_controle *Controle);
void Draw_caixa_dialogo_consulta(char *string1, char *string2, char *string3);
void Draw_caixa_dialogo_consulta_S_N(char *string1, char *string2, char *string3);
void Draw_caixa_dialogo_aviso(char *string1, char *string2, char *string3);
void Draw_caixa_dialogo_consulta_apenas_SIM(char *string1, char *string2, char *string3);
void Draw_caixa_dialogo_aviso_S_OK(char *string1, char *string2, char *string3);
void Draw_bluetooth(Type_controle *Controle, CRC_short *CRC_local);
void Draw_compressor_pressoes(uint8_t *Mmenu_Current, CARRO *Carro);
void Draw_caixa_dialogo_notifica2(Type_controle *Controle, CARRO *Carro, char *string1, char *string2, char *string3);
void Draw_compressor_tempos(uint8_t *Mmenu_Current, CARRO *Carro);
void Draw_compressor_tempos_2(uint8_t *Mmenu_Current, CARRO *Carro);
void Draw_compressor_pressoes_2(uint8_t *Mmenu_Current, CARRO *Carro);
void Draw_imprime_passo(char *string1);
void Draw_imprime_passo_GIGA(CARRO *Carro, uint8_t Maquina, uint8_t Erro);
void Draw_Ocupantes(TIPO_OCUPANTES ocupantes);
void 	u8g_My_SetaFonte(const uint8_t  *font);
#endif /* __DISPLAY_H__ */

/************************ (C) COPYRIGHT MRrider *****END OF FILE****/
