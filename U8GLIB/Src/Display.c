#include "Display.h"
#include "main.h"

#include "u8g_com_arm_stm32.h" 	//---INCLUDES DISPLAY
#include "string.h"
#include <stdlib.h>
#include <stdio.h>
#include "fonts.h"							//---INCLUDES DISPLAY
#include "math.h"							//---INCLUDES DISPLAY


char *String_voltar;
char *String_altura;
char *String_salvar;
char *String_selecione;
char *String_sim;
char *String_nao;
char *String_ja_vinculado;
char *String_nao_vinculado;
char *String_desvincular;
char *String_buscar;
char *String_conexao;
char *String_modo_manual;
char *String_alterar;
char *String_temporizacao;
char *String_min_psi;
char *String_max_psi;
char *String_reservatorio;
char *String_min__psi;
char *String_max__psi;
char *String_pressoes;


extern char 		Buff_Display	[128]		;	//---- BUFF PARA IMPRESS�O 1
extern u8g_t 	u8g; 			// INSTANCIA PARA DISPLAY
const unsigned char bluetooth_8x14[] U8G_PROGMEM = {
		0x00, 0x10, 0x18, 0x14, 0x12, 0x54, 0x38, 0x18, 0x34, 0x52, 0x14, 0x18, 0x10, 0x00,
};

#define ZBYOWR_BMPWIDTH  51
#define ZBYOWR_BMPHEIGHT 31

const unsigned char bitmap_zbyowr[] PROGMEM = {
		0x00,0x00,0x0F,0xFE,0x00,0x00,0x00, // ....................###########.........................
		0x00,0x07,0xFF,0xFF,0xFC,0x00,0x00, // .............#########################..................
		0x00,0x7F,0x80,0x00,0x3F,0xC0,0x00, // .........########.................########..............
		0x03,0xF0,0x00,0x00,0x01,0xF8,0x00, // ......######...........................######...........
		0x07,0x80,0x00,0x00,0x00,0x3C,0x00, // .....####.................................####..........
		0x0E,0x00,0x1F,0xFF,0xC0,0x0E,0x00, // ....###............###############..........###.........
		0x1C,0x00,0x7F,0xFF,0xC0,0x07,0x00, // ...###...........#################...........###........
		0x38,0x01,0xFF,0xFF,0x80,0x03,0x80, // ..###..........##################.............###.......
		0x30,0x07,0xFF,0xFE,0x00,0x01,0x80, // ..##.........##################................##.......
		0x60,0x1F,0xFF,0xFF,0xFF,0xFE,0xC0, // .##........####################################.##......
		0x60,0x7F,0xFF,0xFF,0xFF,0xFE,0xC0, // .##......######################################.##......
		0x61,0xFF,0xFF,0xFF,0xFF,0xFE,0xC0, // .##....########################################.##......
		0x47,0xFF,0xFF,0xFF,0xFF,0xFE,0x40, // .#...##########################################..#......
		0xCF,0xFF,0xFF,0xFF,0xFF,0xFE,0x40, // ##..###########################################..#......
		0xCF,0xFF,0xFF,0xFF,0xFF,0xFC,0x60, // ##..##########################################...##.....
		0xC0,0x00,0x00,0x00,0x00,0x00,0x60, // ##...............................................##.....
		0xC7,0xFF,0xFF,0xFF,0xFF,0xFE,0x60, // ##...##########################################..##.....
		0xCF,0xFF,0xFF,0xFF,0xFF,0xFE,0x40, // ##..###########################################..#......
		0x4F,0xFF,0xFF,0xFF,0xFF,0xFC,0x40, // .#..##########################################...#......
		0x6F,0xFF,0xFF,0xFF,0xFF,0xF0,0xC0, // .##.########################################....##......
		0x6F,0xFF,0xFF,0xFF,0xFF,0x80,0xC0, // .##.#####################################.......##......
		0x60,0x00,0x03,0xFF,0xFE,0x00,0xC0, // .##...................#################.........##......
		0x30,0x00,0x0F,0xFF,0xF8,0x01,0x80, // ..##................#################..........##.......
		0x38,0x00,0x3F,0xFF,0xE0,0x03,0x80, // ..###.............#################...........###.......
		0x1C,0x00,0x7F,0xFF,0x80,0x07,0x00, // ...###...........################............###........
		0x0E,0x00,0x7F,0xFE,0x00,0x0E,0x00, // ....###..........##############.............###.........
		0x07,0x80,0x00,0x00,0x00,0x3C,0x00, // .....####.................................####..........
		0x03,0xF0,0x00,0x00,0x01,0xF8,0x00, // ......######...........................######...........
		0x00,0x7F,0x80,0x00,0x3F,0xC0,0x00, // .........########.................########..............
		0x00,0x07,0xFF,0xFF,0xFC,0x00,0x00, // .............#########################..................
		0x00,0x00,0x0F,0xFE,0x00,0x00,0x00  // ....................###########.........................
};




#define largura_display 128
#define altura_display 64

//--FUNÇÃO DE INICIALIZAÇÃO DE DISPLAY ------------------------
uint8_t Inicia_display(uint8_t Idioma)//INICIALIZACAO DO DISPLAY OLED
{

	uint8_t retorno;
	retorno = u8g_InitComFn(&u8g, &u8g_dev_ssd1306_128x64_i2c, u8g_com_arm_stm32_ssd_i2c_fn); //INICIA O DISPLAY EM I2C
	HAL_Delay(50);
	u8g_SetRot180(&u8g);					//INVERTE 180
	u8g_DisableCursor(&u8g);           		//DESABILITA O CURSOR
	u8g_SetColorIndex(&u8g,1);				//SETA O PIXEL COMO POSITIVO
	u8g_SetDefaultForegroundColor(&u8g);	//FUNDO PRETO   -   LETRA BRANCA

	if(Idioma == PT)
	{
		String_voltar 			= "Voltar";
		String_altura 			= "Altura";
		String_salvar 			= "Salvar";
		String_selecione 		= "Selecione";
		String_sim				= "Sim";
		String_nao				= "Nao";
		String_ja_vinculado 	= " Ja vinculado";
		String_nao_vinculado = " Nao vinculado";
		String_desvincular 	= " Desvincular? ";
		String_buscar			= "   Buscar? ";
		String_conexao			= "Conexao";
		String_modo_manual	= "Modo manual";
		String_alterar			= "Alterar";
		String_temporizacao	= "Temporizacao";
		String_min_psi			= "Minimo:%3.0d PSI";
		String_max_psi			= "Maximo:%3.0d PSI";
		String_reservatorio	= "Reservatorio";
		String_min__psi		= "Minimo:    PSI";
		String_max__psi		= "Maximo:    PSI";
		String_pressoes		= "Pressoes";
	}
	else
	{
		String_voltar 			= "  Back";
		String_altura 			= "Height";
		String_salvar 			= "Save";
		String_selecione 		= "Select";
		String_sim           = "Yes";
		String_nao           = " No";
		String_ja_vinculado  = " Already linked";
		String_nao_vinculado = " Not linked";
		String_desvincular   = "Unlink? ";
		String_buscar        = "   Search? ";
		String_conexao       = "Connection";
		String_modo_manual   = "Manual mode";
		String_alterar       = "Change";
		String_temporizacao  = "Timing";
		String_min__psi      = "Min:   PSI";
		String_max__psi      = "Max:   PSI";
		String_min_psi       = "Min:%3.0d PSI" ;
		String_max_psi       = "Max:%3.0d PSI" ;
		String_reservatorio  = "Reservoir" ;
		String_pressoes      = "Pressures" ;
	}

	return retorno;
}//																																																											//

//--TELA INICIAL ------------------------------------------
void Tela_Inicial_PRO(uint8_t bt_state, CARRO *Carro, Type_controle *Controle, DMA_BLE_Struct *Serial)
{

#ifndef DEFINICOES_TELA_INICIAL//////
	//executa uma unica vez
#define PosX_Bat 121
#define PosY_Bat 0

#define posX_tebao 40
#define posY_tebao 15

#define largura_linha 96
#define altura_linha  58

#define PERCENT_2_BAR( f1 ) ( f1 /3.6 ) //MACRO PARA REDIMENSIONAR AS BARRAS

#define DEFINICOES_TELA_INICIAL
#endif////////////////////////////////

#define Barra_SP_FL PERCENT_2_BAR ( SETPOINT.byte.FL )
#define Barra_RT_FL PERCENT_2_BAR ( REALTIME.byte.FL  )

#define Barra_SP_FR PERCENT_2_BAR ( SETPOINT.byte.FR )
#define Barra_RT_FR PERCENT_2_BAR ( REALTIME.byte.FR  )

#define Barra_SP_RL PERCENT_2_BAR ( SETPOINT.byte.RL )
#define Barra_RT_RL PERCENT_2_BAR ( REALTIME.byte.RL  )

#define Barra_SP_RR PERCENT_2_BAR ( SETPOINT.byte.RR )
#define Barra_RT_RR PERCENT_2_BAR ( REALTIME.byte.RR  )


	u8g_My_SetaFonte(u8g_font_fub17r);		// --- FUNCAO PARA DEFINICAO DE FONTE, ALTURA DE FONTE E POSICAO DE FONTE			//
	u8g_SetDefaultForegroundColor(&u8g);	// --- FUNDO PRETO   -   LETRA BRANCA

	/*---POSICOES DOS NUMEROS*/
	static int XFL=12,YFL=8;							// --- FL COORD. GR�FICA																											//
	static int XRL=12,YRL=38;							// --- RL COORD. GR�FICA																											//
	static int XFR=76,YFR=8;							// --- FR COORD. GR�FICA																											//
	static int XRR=76,YRR=38;							// --- RR COORD. GR�FICA

	/*---VARIAVEIS DE COMPRESSOR*/
	static int Pixel_cmprs 	= 0;
	static float fator		= 0;
	static int min, max, atual;
	min = (Carro->Min_Pressure_CMPRS);
	max = (Carro->Max_Pressure_CMPRS);
	atual = (Carro->Pressure_CMPRS);

	/*---VAR USADA PARA ATRIBUIR VALORES QUE SERAO FILTRADOS DEPENDENDO DO ESTADO DO SENSOR*/
	static TYPE_BOLSAS SETPOINT,REALTIME;

	/*---ICONE BATERIA _________________________________________________________________*/
	if(Controle->Cont_ligado>2)
	{

		u8g_DrawBox			(&u8g, (PosX_Bat+2)	, (PosY_Bat+0) 	,3	,1		);	// --- ponto em cima da bateria
		u8g_DrawRFrame		(&u8g, (PosX_Bat+0)	, (PosY_Bat+2) 	,7	,12	,2	);	// --- frame da bateria

		switch (Controle->State_bat) {
			case 0:
				//PISCA COM ELA VAZIA
				__NOP();

				//OU FAZ ISSO
				u8g_DrawLine(&u8g,(PosX_Bat+0), (PosY_Bat+0), (PosX_Bat+8), (PosY_Bat+17));		// --- bateria muito baixa
				break;

			case 1:
				u8g_DrawBox			(&u8g, (PosX_Bat+2)	, (PosY_Bat+10)	,3	,2);	// --- primeiro estagio da bateria
				break;

			case 2:
				u8g_DrawBox			(&u8g, (PosX_Bat+2)	, (PosY_Bat+10)	,3	,2);	// --- primeiro estagio da bateria
				u8g_DrawBox			(&u8g, (PosX_Bat+2)	, (PosY_Bat+7)	,3	,2);	// --- segundo estagio da bateria
				break;

			case 3:
				u8g_DrawBox			(&u8g, (PosX_Bat+2)	, (PosY_Bat+10)	,3	,2);	// --- primeiro estagio da bateria
				u8g_DrawBox			(&u8g, (PosX_Bat+2)	, (PosY_Bat+7)	,3	,2);	// --- segundo estagio da bateria
				u8g_DrawBox			(&u8g, (PosX_Bat+2)	, (PosY_Bat+4)	,3	,2);	// --- terceiro estagio da bateria
				break;

			case 5:
				u8g_DrawTriangle(	&u8g,	(PosX_Bat+6), (PosY_Bat+1),
						(PosX_Bat+0), (PosY_Bat+8),
						(PosX_Bat+3), (PosY_Bat+8));	// raio carga

				u8g_DrawTriangle(	&u8g,	(PosX_Bat+3), (PosY_Bat+8),
						(PosX_Bat+6), (PosY_Bat+8),
						(PosX_Bat+0), (PosY_Bat+15));	// raio carga
				break;

			default:
				break;
		}
	}


	/*---CONECTADO_________________________________________________________________*/
	if(bt_state == 1)
	{
		//DESENHO BARRA COMPRESSOR
		//u8g_DrawBitmap(&u8g,120,35,1,14,bluetooth_8x14); //BLUETOOTH
		fator = (float)60/(max - min);
		Pixel_cmprs = ceil(  fator*( ((atual - min)>0)?(atual - min):1)  );
		u8g_DrawFrame	(&u8g, 1, 1,  6, 62);							// --- FRAME PARA CMPRS

		if(Carro->State_CMPRS == 1) //caso compressor habilitado, ele pisca com mais e menos barra
		{
			(Controle->FLAG_Pisca_tela == DESABILITADO)?Controle->FLAG_Pisca_tela = ATIVO_ON:0; //HABILITADO O PISCA TELA

			if(Controle->FLAG_Pisca_tela == ATIVO_ON)// ATIVO_ON
			{
				u8g_DrawBox		(&u8g, 2, 62-Pixel_cmprs+7,5,Pixel_cmprs+7);	// --- IMPRIME BARRA BRANCA
			}
			else // ATIVO_OFF
			{
				u8g_DrawBox		(&u8g, 2, 62-Pixel_cmprs,5,Pixel_cmprs);	// --- IMPRIME BARRA BRANCA
			}
		}
		else
		{
			//Controle->FLAG_Pisca_tela = DESABILITADO;
			u8g_DrawBox		(&u8g, 2, 62-Pixel_cmprs,5,Pixel_cmprs);	// --- IMPRIME BARRA BRANCA
		}

		//ANALISE DOS NUMEROS PARA DAR FORMATO A TELA
		if(Carro->Sensores_state.bit.USO_SENSORES && !Carro->Sensores_state.bit.FLAG_ERRO)
		{//  COM SENSOR E SEM ERRO

			if(Carro->Altura_setada>STATE_ZERADO && Carro->Altura_setada<STATE_ALTURA_CUSTOM)
			{// ALTURA SETADA
				SETPOINT.tipo_32_bits = Carro->Altura_SetPoint.tipo_32_bits;
				REALTIME.tipo_32_bits = Carro->Bolsa_RealTime.tipo_32_bits;
			}
			else
			{// ALTURA NAO SETADA, fazer arredondamento
				SETPOINT.byte.FL = MACRO_ROUND_5(Carro->Bolsa_RealTime.byte.FL);
				SETPOINT.byte.FR = MACRO_ROUND_5(Carro->Bolsa_RealTime.byte.FR);
				SETPOINT.byte.RL = MACRO_ROUND_5(Carro->Bolsa_RealTime.byte.RL);
				SETPOINT.byte.RR = MACRO_ROUND_5(Carro->Bolsa_RealTime.byte.RR);

				REALTIME.tipo_32_bits = SETPOINT.tipo_32_bits;
			}

			/*IMPRESSAO BARRAS E TRIANGULOS */
			u8g_DrawBox			(&u8g, 	XFL+47, YFL+23-Barra_RT_FL	,1			,Barra_RT_FL+1);										// barra realtime
			u8g_DrawTriangle	(&u8g,	XFL+41, 27-Barra_SP_FL		,XFL+41	,33-Barra_SP_FL,XFL+48, 30-Barra_SP_FL);		// triangulo setpoint

			u8g_DrawBox			(&u8g, 	XFR-8, YFR+23-Barra_RT_FR		,1			,Barra_RT_FR+1);									// barra realtime
			u8g_DrawTriangle	(&u8g,	XFR-1, 27-Barra_SP_FR			,XFR-1	,33-Barra_SP_FR,XFR-8, 30-Barra_SP_FR);	// triangulo setpoint

			u8g_DrawBox			(&u8g, 	XRL+47, YRL+23-Barra_RT_RL	,1			,Barra_RT_RL+1);												// barra realtime
			u8g_DrawTriangle	(&u8g,	XRL+41, 32+27-Barra_SP_RL	,XRL+41	, 32+33-Barra_SP_RL	,XRL+48, 32+30-Barra_SP_RL);	// triangulo setpoint

			u8g_DrawBox			(&u8g, 	XRR-8	, YRR+23-Barra_RT_RR	,1			,Barra_RT_RR+1);												// barra realtime
			u8g_DrawTriangle	(&u8g,	XRR-1	, 32+27-Barra_SP_RR	,XRR-1	, 32+33-Barra_SP_RR	,XRR-8	,32+30-Barra_SP_RR);	// triangulo setpoint

		}
		else
		{//	SEM SENSOR OU COM ERRO
			SETPOINT.tipo_32_bits = Carro->Banco_pulsos.tipo_32_bits;//teste1
			REALTIME.tipo_32_bits	=SETPOINT.tipo_32_bits;

		}


		/*IMPRESSAO MODO */
		//ajuste fonte grande
		u8g_My_SetaFonte(u8g_font_8x13B);	//FUNCAO PARA DEFINI��O DE FONTE
		u8g_SetDefaultForegroundColor(&u8g);
		if(Carro->Sensores_state.bit.USO_SENSORES && !Carro->Sensores_state.bit.FLAG_ERRO)
		{//USANDO SENSOR E ESTÁ OK
			u8g_DrawStr(&u8g, 120, 26, "A");
		}
		else if(Carro->Sensores_state.bit.USO_SENSORES && Carro->Sensores_state.bit.FLAG_ERRO)
		{//USANDO SENSOR E ESTÁ ERRO
			if(Controle->FLAG_Pisca_tela == ATIVO_ON)			//ERRO SENSOR EM FRONT LEFT----|
			{//DESLIGA FONE

				u8g_SetDefaultBackgroundColor(&u8g);
				u8g_DrawStr(&u8g, 120, 26, "A");
			}
			else
			{
				u8g_SetDefaultForegroundColor(&u8g);
				u8g_DrawStr(&u8g, 120, 26, "A");
			}
		}
		else
		{//SEM SENSOR
			u8g_DrawStr(&u8g, 120, 40, "M");
		}


		//ajuste fonte grande
		u8g_My_SetaFonte(u8g_font_fub17r);		// --- FUNCAO PARA DEFINICAO DE FONTE, ALTURA DE FONTE E POSICAO DE FONTE			//
		u8g_SetDefaultForegroundColor(&u8g);	// --- FUNDO PRETO   -   LETRA BRANCA




		/*IMPRESSAO NUMEROS */
		if(Serial->MAQUINA_Recepcao == RX_PROTOCOLO_MRRIDER)
		{
			if(Controle->sel_FL)	//SELECAO FRONT - LEFT------------------------------------------------|
			{
				u8g_DrawRBox(&u8g, XFL-1, YFL-4, 42, 28, 5);
				u8g_SetDefaultBackgroundColor(&u8g);
				sprintf(Buff_Display,"%3.0d",SETPOINT.byte.FL);
				if(SETPOINT.byte.FL == 0)
					sprintf(Buff_Display,"  0");
				u8g_DrawStr(&u8g, XFL, YFL, Buff_Display);
				u8g_SetDefaultForegroundColor(&u8g);

			}
			else
			{
				u8g_SetDefaultForegroundColor(&u8g);
				sprintf(Buff_Display,"%3.0d",SETPOINT.byte.FL);
				if(SETPOINT.byte.FL == 0)
					sprintf(Buff_Display,"  0");
				u8g_DrawStr(&u8g, XFL, YFL, Buff_Display);
			}
			//_______________________________________________________________________________________|

			if(Controle->sel_FR)	//SELECAOO FRONT - RIGHT------------------------------------------------|
			{
				u8g_DrawRBox(&u8g, XFR-1, YFR-4, 42, 28, 5);
				u8g_SetDefaultBackgroundColor(&u8g);
				sprintf(Buff_Display,"%3.0d",SETPOINT.byte.FR);
				if(SETPOINT.byte.FR == 0)
					sprintf(Buff_Display,"  0");
				u8g_DrawStr(&u8g, XFR, YFR, Buff_Display);
				u8g_SetDefaultForegroundColor(&u8g);

			}
			else
			{
				u8g_SetDefaultForegroundColor(&u8g);
				sprintf(Buff_Display,"%3.0d",SETPOINT.byte.FR);
				if(SETPOINT.byte.FR == 0)
					sprintf(Buff_Display,"  0");
				u8g_DrawStr(&u8g, XFR, YFR, Buff_Display);
			}
			//_______________________________________________________________________________________|

			if(Controle->sel_RL)	//SELECAOO REAR - LEFT------------------------------------------------|
			{
				u8g_DrawRBox(&u8g, XRL-1, YRL-4, 42, 28, 5);
				u8g_SetDefaultBackgroundColor(&u8g);
				sprintf(Buff_Display,"%3.0d",SETPOINT.byte.RL);
				if(SETPOINT.byte.RL == 0)
					sprintf(Buff_Display,"  0");
				u8g_DrawStr(&u8g, XRL, YRL, Buff_Display);
				u8g_SetDefaultForegroundColor(&u8g);

			}
			else
			{
				u8g_SetDefaultForegroundColor(&u8g);
				sprintf(Buff_Display,"%3.0d",SETPOINT.byte.RL);
				if(SETPOINT.byte.RL == 0)
					sprintf(Buff_Display,"  0");
				u8g_DrawStr(&u8g, XRL, YRL, Buff_Display);
			}
			//_______________________________________________________________________________________|

			if(Controle->sel_RR)	//SELECAOO REAR - RIGHT------------------------------------------------|
			{
				u8g_DrawRBox(&u8g, XRR-1, YRR-4, 42, 28, 5);
				u8g_SetDefaultBackgroundColor(&u8g);
				sprintf(Buff_Display,"%3.0d",SETPOINT.byte.RR);
				if(SETPOINT.byte.RR == 0)
					sprintf(Buff_Display,"  0");
				u8g_DrawStr(&u8g, XRR, YRR, Buff_Display);
				u8g_SetDefaultForegroundColor(&u8g);

			}
			else
			{
				u8g_SetDefaultForegroundColor(&u8g);
				sprintf(Buff_Display,"%3.0d",SETPOINT.byte.RR);
				if(SETPOINT.byte.RR == 0)
					sprintf(Buff_Display,"  0");
				u8g_DrawStr(&u8g, XRR, YRR, Buff_Display);
			}
			//_______________________________________________________________________________________|
		}
		/*LEDS*/
		switch (Carro->Altura_setada) {
			case STATE_ALTURA_1:

				LED_H1_ON
				LED_H2_OFF
				LED_H3_OFF
				LED_H4_OFF

				break;
			case STATE_ALTURA_2:

				LED_H1_OFF
				LED_H2_ON
				LED_H3_OFF
				LED_H4_OFF

				break;
			case STATE_ALTURA_3:

				LED_H1_OFF
				LED_H2_OFF
				LED_H3_ON
				LED_H4_OFF

				break;
			case STATE_ALTURA_4:

				LED_H1_OFF
				LED_H2_OFF
				LED_H3_OFF
				LED_H4_ON

				break;

			default:
				LED_H1_OFF
				LED_H2_OFF
				LED_H3_OFF
				LED_H4_OFF

				break;
		}
	}
	else
	{
		u8g_DrawBitmap(&u8g,posX_tebao,20,(ZBYOWR_BMPWIDTH/8)+1,ZBYOWR_BMPHEIGHT,bitmap_zbyowr); //SIMBOLO TEBAO
		LED_H1_OFF
		LED_H2_OFF
		LED_H3_OFF
		LED_H4_OFF
	}




}//

//--DRAW MENU MASTER ------------------------------------------
void Draw_menu_master(Type_controle *Controle, uint8_t Max_itens, char **mmenu_strings, uint8_t *Mmenu_Current, uint8_t *Aaux_Update_Menu)
{
	LED_H1_OFF
	LED_H2_OFF
	LED_H3_OFF
	LED_H4_OFF

	u8g_My_SetaFonte(u8g_font_8x13B);
	u8g_DrawLine(&u8g,0, 0, 127, 0);		// --- LINHA HORIZONTAL SUPERIOR
	u8g_DrawLine(&u8g,0, 0, 0, 64);			// --- LINHA VERTICAL ESQUERDA
	u8g_DrawLine(&u8g,127, 0, 127, 64);		// --- LINHA VERTICAL DIREITA

	uint8_t i, h, g;
	u8g_uint_t w;
	h = u8g_GetFontAscent(&u8g)-u8g_GetFontDescent(&u8g)+1;	// --- DEFINA ESPAC. VERT. EM FUNCAO DA FONTE

	/*PARA IMPRIMIR MENU DE 1 OU 2 LINHAS*/
	if(Max_itens < 3)
		g = Max_itens;
	else
		g = 3;

	/*PARA IMPRIMIR MENU LONGO*/
	if(Max_itens > 3 )
	{
		w = u8g_GetWidth(&u8g)-20;
	}
	else
	{
		w = u8g_GetWidth(&u8g)-10;
	}


	for( i = 0; i < g; i++ )//imprime lista
	{
		u8g_SetDefaultForegroundColor(&u8g);				//FUNDO PRETO<->LETRA BRANCA
		if ( i+*Aaux_Update_Menu == *Mmenu_Current ) 	//ITEM SELECIONADO
		{
			u8g_DrawBox(&u8g, 5, i*h+7, w, h);  		//IMPRIME CAIXA BRANCA
			u8g_SetDefaultBackgroundColor(&u8g);	 	//PREPARA FUNDO BRANCA<->LETRA PRETA
		}
		u8g_DrawStr(&u8g, 7, (i)*h+7, mmenu_strings[i+*Aaux_Update_Menu]);	//IMPRIME O ITEN EM BRANCO OU PRETO
		u8g_SetDefaultForegroundColor(&u8g);								//RESETA O ESTADO DO BACKGROUND
	}

	if(Max_itens > 3 )
	{
		u8g_DrawFrame(&u8g,116,6,8,41);											//FRAME PARA INDIC. DE POS. DO MENU
		u8g_DrawBox(&u8g,116, 7 + ((36/(Max_itens-1))*(*Mmenu_Current)),8,5);	//INDICADOR DE POSI��O DO MENU
	}

	u8g_DrawBox(&u8g, 0, 51, 127, 64);			// --- IMPRIME CAIXA BRANCA NAVEGA��O INFERIOR
	u8g_SetDefaultBackgroundColor(&u8g);		// --- FUNDO BRANCO <-> LETRA PRETA
	u8g_DrawStr(&u8g, 1, 51, "Selec");			// --- BOT�O ESQUERDO
	u8g_DrawStr(&u8g, 80, 51, String_voltar);		// --- BOT�O DIREITO
	u8g_SetDefaultForegroundColor(&u8g);		// --- RESETA O ESTADO DO BACKGROUND
	//
}

//--DRAW NOVA ALTURA ------------------------------------------
void Draw_nova_altura(CARRO *Carro, Type_controle *Controle)
{
	u8g_My_SetaFonte(u8g_font_8x13B);		//FUNCAO PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);	//FUNDO PRETO   -   LETRA BRANCA
	static int XFL=5,YFL=18;				//VAR DE POSICIONAMENTO DE FL
	static int XRL=5,YRL=35;				//VAR DE POSICIONAMENTO DE RL
	static int XFR=36,YFR=18;				//VAR DE POSICIONAMENTO DE FR
	static int XRR=36,YRR=35;				//VAR DE POSICIONAMENTO DE RR

	u8g_DrawLine(&u8g,5, 32, 60, 32);	//LINHA HORIZONTAL
	u8g_DrawLine(&u8g,33, 18, 33, 47);	//LINHA VERTICAL


	/*---VAR USADA PARA ATRIBUIR VALORES QUE SERAO FILTRADOS DEPENDENDO DO ESTADO DO SENSOR*/
	static TYPE_BOLSAS SETPOINT,REALTIME;




	//ANALISE DOS NUMEROS PARA DAR FORMATO A TELA
	if(Carro->Sensores_state.bit.USO_SENSORES && !Carro->Sensores_state.bit.FLAG_ERRO)
	{//  COM SENSOR E SEM ERRO

		if(Carro->Altura_setada>STATE_ZERADO && Carro->Altura_setada<STATE_ALTURA_CUSTOM)
		{// ALTURA SETADA
			SETPOINT.tipo_32_bits = Carro->Altura_SetPoint.tipo_32_bits;
			REALTIME.tipo_32_bits = Carro->Bolsa_RealTime.tipo_32_bits;
		}
		else
		{// ALTURA NAO SETADA, fazer arredondamento
			SETPOINT.byte.FL = MACRO_ROUND_5(Carro->Bolsa_RealTime.byte.FL);
			SETPOINT.byte.FR = MACRO_ROUND_5(Carro->Bolsa_RealTime.byte.FR);
			SETPOINT.byte.RL = MACRO_ROUND_5(Carro->Bolsa_RealTime.byte.RL);
			SETPOINT.byte.RR = MACRO_ROUND_5(Carro->Bolsa_RealTime.byte.RR);

			REALTIME.tipo_32_bits = SETPOINT.tipo_32_bits;
		}


		sprintf(Buff_Display,"%3.0d",MACRO_ROUND_5((int)SETPOINT.byte.FL));
		u8g_DrawStr(&u8g, XFL, YFL, Buff_Display);			// --- FL

		sprintf(Buff_Display,"%3.0d",MACRO_ROUND_5((int)SETPOINT.byte.RL));
		u8g_DrawStr(&u8g, XRL, YRL, Buff_Display);			// --- RL

		sprintf(Buff_Display,"%3.0d",MACRO_ROUND_5((int)SETPOINT.byte.FR));
		u8g_DrawStr(&u8g, XFR, YFR, Buff_Display);			// --- FR

		sprintf(Buff_Display,"%3.0d",MACRO_ROUND_5((int)SETPOINT.byte.RR));
		u8g_DrawStr(&u8g, XRR, YRR, Buff_Display);			// --- RR
	}
	else
	{//	SEM SENSOR OU COM ERRO
		SETPOINT.tipo_32_bits = Carro->Banco_pulsos.tipo_32_bits;//teste1
		REALTIME.tipo_32_bits	=SETPOINT.tipo_32_bits;

		sprintf(Buff_Display,"%3.0d",(int)SETPOINT.byte.FL);
		u8g_DrawStr(&u8g, XFL, YFL, Buff_Display);			// --- FL

		sprintf(Buff_Display,"%3.0d",(int)SETPOINT.byte.RL);
		u8g_DrawStr(&u8g, XRL, YRL, Buff_Display);			// --- RL

		sprintf(Buff_Display,"%3.0d",(int)SETPOINT.byte.FR);
		u8g_DrawStr(&u8g, XFR, YFR, Buff_Display);			// --- FR

		sprintf(Buff_Display,"%3.0d",(int)SETPOINT.byte.RR);
		u8g_DrawStr(&u8g, XRR, YRR, Buff_Display);			// --- RR

	}








	u8g_DrawStr(&u8g, 70, 16, String_altura);
	u8g_SetFont(&u8g, u8g_font_9x18B);
	sprintf(Buff_Display,"%1.0d",Controle->FLAG_Altura_2_salve);
	u8g_DrawStr(&u8g, 88, 44, Buff_Display);				//MOSTRA ALTURA SELECIONADA

	switch(Controle->FLAG_Altura_2_salve) // --- INDICACAO VIA LEDS VERMELHOS DO QUAL ALTURA EST� SETADA
	{																																											//
		case 1:
			LED_H1_ON
			LED_H2_OFF
			LED_H3_OFF
			LED_H4_OFF
			break;
		case 2:
			LED_H1_OFF
			LED_H2_ON
			LED_H3_OFF
			LED_H4_OFF
			break;
		case 3:
			LED_H1_OFF
			LED_H2_OFF
			LED_H3_ON
			LED_H4_OFF
			break;
		case 4:
			LED_H1_OFF
			LED_H2_OFF
			LED_H3_OFF
			LED_H4_ON
			break;
		default :
			LED_H1_OFF
			LED_H2_OFF
			LED_H3_OFF
			LED_H4_OFF
			break;
	}

	u8g_SetColorIndex(&u8g,1);
	u8g_SetDefaultForegroundColor(&u8g);
	u8g_DrawFrame(&u8g,80,30,24,18);//FRAME PARA NUMERO

	u8g_DrawBox(&u8g, 0, 51, 127, 64);    	//BACKGROUND BARRA INFERIOR
	u8g_DrawBox(&u8g, 0, 0, 127, 14);     	//BACKGROUND BARRA SUPERIOR
	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_My_SetaFonte(u8g_font_8x13B);		//FUNCAO PARA DEFINI��O DE FONTE
	u8g_DrawStr(&u8g, 30, 1, String_selecione);	//LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 1, 51, String_salvar);		//LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 80, 51, String_voltar);	//LADO DIREITO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);

	u8g_DrawLine(&u8g,0, 0, 127, 0);		//LINHA HORIZONTAL SUPERIOR
	u8g_DrawLine(&u8g,0, 0, 0, 64);			//LINHA VERTICAL ESQUERDA
	u8g_DrawLine(&u8g,127, 0, 127, 64);		//LINHA VERTICAL DIREITA

}//

//--DRAW NOVA ALTURA ------------------------------------------
void Draw_nova_altura_temp(CARRO *Carro, Type_controle *Controle)
{
	u8g_My_SetaFonte(u8g_font_9x18B);		// --- FUNCAO PARA DEFINI��O DE FONTE, ALTURA DE FONTE E POSI��O DE FONTE			//
	u8g_SetDefaultForegroundColor(&u8g);	// --- FUNDO PRETO   -   LETRA BRANCA


	static int XFL=20,YFL=16;							// --- FL COORD. GR�FICA																											//
	static int XRL=20,YRL=33;							// --- RL COORD. GR�FICA																											//
	static int XFR=68,YFR=16;							// --- FR COORD. GR�FICA																											//
	static int XRR=68,YRR=33;							// --- RR COORD. GR�FICA

	if(Controle->sel_FL)	//SELECAOO FRONT - LEFT------------------------------------------------|
	{
		u8g_DrawRBox(&u8g, XFL-1, YFL-4, 42, 20, 5);
		u8g_SetDefaultBackgroundColor(&u8g);
		sprintf(Buff_Display,"%3.0d",Carro->Altura_SetPoint.byte.FL);
		if(Carro->Altura_SetPoint.byte.FL == 0)
			sprintf(Buff_Display,"  0");
		u8g_DrawStr(&u8g, XFL, YFL, Buff_Display);
		u8g_SetDefaultForegroundColor(&u8g);

	}
	else
	{
		u8g_SetDefaultForegroundColor(&u8g);
		sprintf(Buff_Display,"%3.0d",Carro->Altura_SetPoint.byte.FL);
		if(Carro->Altura_SetPoint.byte.FL == 0)
			sprintf(Buff_Display,"  0");
		u8g_DrawStr(&u8g, XFL, YFL, Buff_Display);
	}
	//_______________________________________________________________________________________|

	if(Controle->sel_FR)	//SELECAOO FRONT - RIGHT------------------------------------------------|
	{
		u8g_DrawRBox(&u8g, XFR-1, YFR-4, 35, 20, 5);
		u8g_SetDefaultBackgroundColor(&u8g);
		sprintf(Buff_Display,"%3.0d",Carro->Altura_SetPoint.byte.FR);
		if(Carro->Altura_SetPoint.byte.FR == 0)
			sprintf(Buff_Display,"  0");
		u8g_DrawStr(&u8g, XFR, YFR, Buff_Display);
		u8g_SetDefaultForegroundColor(&u8g);

	}
	else
	{
		u8g_SetDefaultForegroundColor(&u8g);
		sprintf(Buff_Display,"%3.0d",Carro->Altura_SetPoint.byte.FR);
		if(Carro->Altura_SetPoint.byte.FR == 0)
			sprintf(Buff_Display,"  0");
		u8g_DrawStr(&u8g, XFR, YFR, Buff_Display);
	}
	//_______________________________________________________________________________________|

	if(Controle->sel_RL)	//SELECAOO REAR - LEFT------------------------------------------------|
	{
		u8g_DrawRBox(&u8g, XRL-1, YRL-4, 42, 20, 5);
		u8g_SetDefaultBackgroundColor(&u8g);
		sprintf(Buff_Display,"%3.0d",Carro->Altura_SetPoint.byte.RL);
		if(Carro->Altura_SetPoint.byte.RL == 0)
			sprintf(Buff_Display,"  0");
		u8g_DrawStr(&u8g, XRL, YRL, Buff_Display);
		u8g_SetDefaultForegroundColor(&u8g);

	}
	else
	{
		u8g_SetDefaultForegroundColor(&u8g);
		sprintf(Buff_Display,"%3.0d",Carro->Altura_SetPoint.byte.RL);
		if(Carro->Altura_SetPoint.byte.RL == 0)
			sprintf(Buff_Display,"  0");
		u8g_DrawStr(&u8g, XRL, YRL, Buff_Display);
	}
	//_______________________________________________________________________________________|

	if(Controle->sel_RR)	//SELECAOO REAR - RIGHT------------------------------------------------|
	{
		u8g_DrawRBox(&u8g, XRR-1, YRR-4, 42, 20, 5);
		u8g_SetDefaultBackgroundColor(&u8g);
		sprintf(Buff_Display,"%3.0d",Carro->Altura_SetPoint.byte.RR);
		if(Carro->Altura_SetPoint.byte.RR == 0)
			sprintf(Buff_Display,"  0");
		u8g_DrawStr(&u8g, XRR, YRR, Buff_Display);
		u8g_SetDefaultForegroundColor(&u8g);

	}
	else
	{
		u8g_SetDefaultForegroundColor(&u8g);
		sprintf(Buff_Display,"%3.0d",Carro->Altura_SetPoint.byte.RR);
		if(Carro->Altura_SetPoint.byte.RR == 0)
			sprintf(Buff_Display,"  0");
		u8g_DrawStr(&u8g, XRR, YRR, Buff_Display);
	}
	//_______________________________________________________________________________________|






	u8g_DrawBox(&u8g, 0, 51, 127, 64);    	//BACKGROUND BARRA INFERIOR
	u8g_DrawBox(&u8g, 0, 0, 127, 14);     	//BACKGROUND BARRA SUPERIOR
	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_My_SetaFonte(u8g_font_8x13B);		//FUNCAO PARA DEFINI��O DE FONTE
	u8g_DrawStr(&u8g, 30, 1, String_selecione);	//LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 1, 51, String_salvar);		//LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 80, 51, String_voltar);	//LADO DIREITO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);

	u8g_DrawLine(&u8g,0, 0, 127, 0);		//LINHA HORIZONTAL SUPERIOR
	u8g_DrawLine(&u8g,0, 0, 0, 64);			//LINHA VERTICAL ESQUERDA
	u8g_DrawLine(&u8g,127, 0, 127, 64);		//LINHA VERTICAL DIREITA

}//

//--DRAW CAIXA DIALOGO CONSULTA	------------------------------------------------- //////
void Draw_caixa_dialogo_consulta(char *string1, char *string2, char *string3)
{
	uint8_t h;
	u8g_My_SetaFonte(u8g_font_8x13B);	// --- FUN��O PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);
	h = u8g_GetFontAscent(&u8g)-u8g_GetFontDescent(&u8g)+1;

	u8g_DrawBox(&u8g, 0, 51, 127, 64);  // --- BACKGROUND BARRA INFERIOR
	u8g_DrawLine(&u8g,0, 0, 127, 0);	// --- LINHA HORIZONTAL SUPERIOR
	u8g_DrawLine(&u8g,0, 0, 0, 64);		// --- LINHA VERTICAL ESQUERDA
	u8g_DrawLine(&u8g,127, 0, 127, 64);	// --- LINHA VERTICAL DIREITA

	u8g_DrawStr(&u8g, 5, 0*h+7,string1);// --- LINHA 1
	u8g_DrawStr(&u8g, 5, 1*h+7,string2);// --- LINHA 2
	u8g_DrawStr(&u8g, 5, 2*h+7,string3);// --- LINHA 3

	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_DrawStr(&u8g, 1, 51, String_salvar);	// --- LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 80, 51, String_voltar);// --- LADO DIREITO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);
}//

//--DRAW CAIXA DIALOGO CONSULTA	------------------------------------------------- //////
void Draw_caixa_dialogo_consulta_S_N(char *string1, char *string2, char *string3)
{
	uint8_t h;
	u8g_My_SetaFonte(u8g_font_8x13B);	// --- FUN��O PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);
	h = u8g_GetFontAscent(&u8g)-u8g_GetFontDescent(&u8g)+1;

	u8g_DrawBox(&u8g, 0, 51, 127, 64);  // --- BACKGROUND BARRA INFERIOR
	u8g_DrawLine(&u8g,0, 0, 127, 0);	// --- LINHA HORIZONTAL SUPERIOR
	u8g_DrawLine(&u8g,0, 0, 0, 64);		// --- LINHA VERTICAL ESQUERDA
	u8g_DrawLine(&u8g,127, 0, 127, 64);	// --- LINHA VERTICAL DIREITA

	u8g_DrawStr(&u8g, 5, 0*h+7,string1);// --- LINHA 1
	u8g_DrawStr(&u8g, 5, 1*h+7,string2);// --- LINHA 2
	u8g_DrawStr(&u8g, 5, 2*h+7,string3);// --- LINHA 3

	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_DrawStr(&u8g, 5, 51, String_sim);	// --- LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 96, 51, String_nao);// --- LADO DIREITO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);
}//

//--DRAW CAIXA DIALOGO AVISO ----------------------------------
void Draw_caixa_dialogo_aviso(char *string1, char *string2, char *string3)
{
	uint8_t h;
	u8g_My_SetaFonte(u8g_font_8x13B);	//FUNCAO PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);
	h = u8g_GetFontAscent(&u8g)-u8g_GetFontDescent(&u8g)+1;

	u8g_DrawBox(&u8g, 0, 51, 127, 64);  	//BACKGROUND BARRA INFERIOR
	u8g_DrawLine(&u8g,0, 0, 127, 0);		//LINHA HORIZONTAL SUPERIOR
	u8g_DrawLine(&u8g,0, 0, 0, 64);			//LINHA VERTICAL ESQUERDA
	u8g_DrawLine(&u8g,127, 0, 127, 64);		//LINHA VERTICAL DIREITA
	u8g_DrawStr(&u8g, 5, 0*h+7,string1);	//LINHA 1
	u8g_DrawStr(&u8g, 5, 1*h+7,string2);	//LINHA 2
	u8g_DrawStr(&u8g, 5, 2*h+7,string3);	//LINHA 3
	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_DrawStr(&u8g, 5, 51, "OK");			//LADO ESQUERDO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);
}//

//--DRAW CAIXA DIALOGO AVISO ----------------------------------
void Draw_caixa_dialogo_consulta_apenas_SIM(char *string1, char *string2, char *string3)
{
	uint8_t h;
	u8g_My_SetaFonte(u8g_font_8x13B);	//FUNCAO PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);
	h = u8g_GetFontAscent(&u8g)-u8g_GetFontDescent(&u8g)+1;

	u8g_DrawBox(&u8g, 0, 51, 127, 64);  	//BACKGROUND BARRA INFERIOR
	u8g_DrawLine(&u8g,0, 0, 127, 0);		//LINHA HORIZONTAL SUPERIOR
	u8g_DrawLine(&u8g,0, 0, 0, 64);			//LINHA VERTICAL ESQUERDA
	u8g_DrawLine(&u8g,127, 0, 127, 64);		//LINHA VERTICAL DIREITA
	u8g_DrawStr(&u8g, 5, 0*h+7,string1);	//LINHA 1
	u8g_DrawStr(&u8g, 5, 1*h+7,string2);	//LINHA 2
	u8g_DrawStr(&u8g, 5, 2*h+7,string3);	//LINHA 3
	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_DrawStr(&u8g, 5, 51, String_sim);			//LADO ESQUERDO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);
}//

//--DRAW BLUETOOTH -----------------------------------------------------------------	/////
void Draw_bluetooth(Type_controle *Controle, CRC_short *CRC_local)
{
	LED_H1_OFF
	LED_H2_OFF
	LED_H3_OFF
	LED_H4_OFF
	u8g_My_SetaFonte(u8g_font_8x13B);		//FUNCAO PARA DEFINICAO DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);	//FUNDO PRETO - LETRA BRANCA
	uint8_t h;
	h = u8g_GetFontAscent(&u8g)-u8g_GetFontDescent(&u8g)+1;	//DEFINA ESPAC. VERT.

	if(CRC_local->hilo != 0x0000)
	{
		sprintf(Buff_Display,String_ja_vinculado);
		u8g_DrawStr(&u8g, 7, 1*h+7, Buff_Display);// --- LINHA1
		sprintf(Buff_Display,String_desvincular);
		u8g_DrawStr(&u8g, 7, 2*h+7, Buff_Display);// --- LINHA2
	}
	else
	{
		sprintf(Buff_Display,String_nao_vinculado);
		u8g_DrawStr(&u8g, 7, 1*h+7, Buff_Display);// --- LINHA1
		sprintf(Buff_Display,String_buscar);
		u8g_DrawStr(&u8g, 7, 2*h+7, Buff_Display);// --- LINHA2
	}


	u8g_DrawBox(&u8g, 0, 51, 127, 64);    	// --- BACKGROUND BARRA INFERIOR
	u8g_DrawBox(&u8g, 0, 0, 127, 14);     	// --- BACKGROUND BARRA SUPERIOR
	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_DrawStr(&u8g, 30, 1, String_conexao);	// --- LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 5, 51, String_sim);		// --- LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 80, 51, String_voltar);	// --- LADO DIREITO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);

	u8g_DrawLine(&u8g,0, 0, 127, 0);		// --- LINHA HORIZONTAL SUPERIOR
	u8g_DrawLine(&u8g,0, 0, 0, 64);			// --- LINHA VERTICAL ESQUERDA
	u8g_DrawLine(&u8g,127, 0, 127, 64);		// --- LINHA VERTICAL DIREITA
}//

//	---	DRAW CAIXA DIALOGO NOTIFICA2------------------------------------------------- /////
void Draw_caixa_dialogo_notifica2(Type_controle *Controle, CARRO *Carro, char *string1, char *string2, char *string3)
{

	(Controle->FLAG_Pisca_tela == DESABILITADO)?Controle->FLAG_Pisca_tela = ATIVO_ON:0; //HABILITADO O PISCA TELA

	uint8_t h;
	u8g_My_SetaFonte(u8g_font_8x13B);		// --- FUN��O PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);
	h = u8g_GetFontAscent(&u8g)-u8g_GetFontDescent(&u8g)+1;
	u8g_DrawBox(&u8g, 0, 51, 127, 64);  	// --- BACKGROUND BARRA INFERIOR
	u8g_DrawStr(&u8g, 2, 0*h+3,string1);	// --- LINHA 1
	u8g_DrawStr(&u8g, 2, 1*h+3,string2);	// --- LINHA 2
	u8g_DrawStr(&u8g, 2, 2*h+3,string3);	// --- LINHA 3

	u8g_DrawRFrame(&u8g,91 ,35,22,11,0);	//DESENHO DA CENTRAL


	if(Controle->FLAG_Pisca_tela == ATIVO_ON && Carro->Sensores_state.bit.FL)			//ERRO SENSOR EM FRONT LEFT----|
	{
		u8g_SetDefaultBackgroundColor(&u8g);
		u8g_DrawRFrame(&u8g,84 ,1	,	6,11,2);	//RODA FL
		u8g_DrawRFrame(&u8g,98 ,6 ,2 ,30 ,0);		//MANGUEIRA FL
		u8g_DrawRFrame(&u8g,89 ,6 ,11,2  ,0);		//MANGUEIRA FL
		u8g_SetDefaultForegroundColor(&u8g);
	}
	else
	{
		u8g_SetColorIndex(&u8g,1);
		u8g_SetDefaultForegroundColor(&u8g);
		u8g_DrawRFrame(&u8g,84 ,1	,	6,11,2);	//RODA FL
		u8g_DrawRFrame(&u8g,98 ,6 ,2 ,30 ,0);		//MANGUEIRA FL
		u8g_DrawRFrame(&u8g,89 ,6 ,11,2  ,0);		//MANGUEIRA FL
	}

	if(Controle->FLAG_Pisca_tela == ATIVO_ON && Carro->Sensores_state.bit.FR)			//ERRO SENSOR EM FRONT RIGHT---|
	{
		u8g_SetDefaultBackgroundColor(&u8g);
		u8g_DrawRFrame(&u8g,114,1	,	6,11,2);	//RODA FR
		u8g_DrawRFrame(&u8g,104,6 ,2 ,30,0);		//MANGUEIRA FR
		u8g_DrawRFrame(&u8g,104,6 ,10,2 ,0);		//MANGUEIRA FR
		u8g_SetDefaultForegroundColor(&u8g);
	}
	else
	{
		u8g_SetColorIndex(&u8g,1);
		u8g_SetDefaultForegroundColor(&u8g);
		u8g_DrawRFrame(&u8g,114,1	,	6,11,2);	//RODA FR
		u8g_DrawRFrame(&u8g,104,6 ,2 ,30,0);		//MANGUEIRA FR
		u8g_DrawRFrame(&u8g,104,6 ,10,2 ,0);		//MANGUEIRA FR
	}

	if(Controle->FLAG_Pisca_tela == ATIVO_ON && Carro->Sensores_state.bit.RL)		//ERRO SENSOR EM REAR LEFT-----|
	{
		u8g_SetDefaultBackgroundColor(&u8g);
		u8g_DrawRFrame(&u8g,84 ,20,	6,11,2);	//RODA RL
		u8g_DrawRFrame(&u8g,92 ,25,2,10 ,0);	//MANGUEIRA RL
		u8g_DrawRFrame(&u8g,89 ,25,4,2  ,0);	//MANGUEIRA RL
		u8g_SetDefaultForegroundColor(&u8g);
	}
	else
	{
		u8g_SetColorIndex(&u8g,1);
		u8g_SetDefaultForegroundColor(&u8g);
		u8g_DrawRFrame(&u8g,84 ,20,	6,11,2);	//RODA RL
		u8g_DrawRFrame(&u8g,92 ,25,2,10 ,0);	//MANGUEIRA RL
		u8g_DrawRFrame(&u8g,89 ,25,4,2  ,0);	//MANGUEIRA RL
	}

	if(Controle->FLAG_Pisca_tela == ATIVO_ON && Carro->Sensores_state.bit.RR)		//ERRO SENSOR EM REAR RIGHT-----|
	{
		u8g_SetDefaultBackgroundColor(&u8g);
		u8g_DrawRFrame(&u8g,114,20,	6,11,2);	//RODA RR
		u8g_DrawRFrame(&u8g,110 ,25,2 ,10,0);	//MANGUEIRA RR
		u8g_DrawRFrame(&u8g,112 ,25,3 ,2 ,0);	//MANGUEIRA RR
		u8g_SetDefaultForegroundColor(&u8g);
	}
	else
	{
		u8g_SetColorIndex(&u8g,1);
		u8g_SetDefaultForegroundColor(&u8g);
		u8g_DrawRFrame(&u8g,114,20,	6,11,2);	//RODA RR
		u8g_DrawRFrame(&u8g,110 ,25,2 ,10,0);	//MANGUEIRA RR
		u8g_DrawRFrame(&u8g,112 ,25,3 ,2 ,0);	//MANGUEIRA RR
	}


	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_DrawStr(&u8g, 5, 51, String_modo_manual);		// --- LADO ESQUERDO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);
}

//	--- Draw_compressor_tempos-------------------------------------------------------- //////
void Draw_compressor_tempos(uint8_t *Mmenu_Current, CARRO *Carro)
{
	static int Box_INI, Box_FIM;
	uint8_t h;
	u8g_uint_t w;
	u8g_My_SetaFonte(u8g_font_8x13B);	// --- FUN��O PARA DEFINI��O DE FONTE
	h = u8g_GetFontAscent(&u8g)-u8g_GetFontDescent(&u8g)+1;
	w = u8g_GetWidth(&u8g)-10;
	Box_INI = 5;
	Box_FIM = w;

	if(*Mmenu_Current == 0 )
	{
		u8g_DrawBox(&u8g, Box_INI, 1*h+7, Box_FIM, h);		// --- IMPRIME CAIXA BRANCA
		u8g_SetDefaultBackgroundColor(&u8g);					// --- DEFINE BACKGROUND BRANCO LETRA PRETA
		sprintf(Buff_Display,"Delay ON:%3.0d s",Carro->CMPRS_Delay_PC);
		u8g_DrawStr(&u8g, 7, 1*h+7, Buff_Display);			// --- IMPRIME A LINHA 1 NORMAL
		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
		sprintf(Buff_Display,"Max ON:%3.0d min",Carro->CMPRS_Tempo_max_on);
		u8g_DrawStr(&u8g, 7, 2*h+7, Buff_Display);			// --- IMPRIME A LINHA 2 INVERTIDA

		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
	}
	if(*Mmenu_Current == 1)
	{
		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
		u8g_DrawBox(&u8g, Box_INI, 2*h+7, Box_FIM, h);		// --- IMPRIME CAIXA BRANCA
		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
		sprintf(Buff_Display,"Delay ON:%3.0d s",Carro->CMPRS_Delay_PC);
		u8g_DrawStr(&u8g, 7, 1*h+7, Buff_Display);			// --- IMPRIME A LINHA 1 INVERTIDA
		u8g_SetDefaultBackgroundColor(&u8g);					// --- DEFINE BACKGROUND BRANCO LETRA PRETA
		sprintf(Buff_Display,"Max ON:%3.0d min",Carro->CMPRS_Tempo_max_on);
		u8g_DrawStr(&u8g, 7, 2*h+7, Buff_Display);			// --- IMPRIME A LINHA 2 NORMAL

		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
	}

	u8g_DrawBox(&u8g, 0, 51, 127, 64);     				// --- BACKGROUND BARRA INFERIOR
	u8g_DrawBox(&u8g, 0, 0, 127, 14);     					// --- BACKGROUND BARRA SUPERIOR
	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_My_SetaFonte(u8g_font_8x13B);						// --- FUN��O PARA DEFINI��O DE FONTE
	u8g_DrawStr(&u8g, 17, 1, String_temporizacao);				// --- LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 1, 51, String_alterar);					// --- LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 80, 51, String_voltar);					// --- LADO DIREITO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);
}
////////////////////////////////////////////////////////////////////////////////////////////

//	--- Draw_compressor_pressoes_2---------------------------------------------------- //////
void Draw_compressor_tempos_2(uint8_t *Mmenu_Current, CARRO *Carro)
{
	static int Box_INI, Box_FIM;
	uint8_t h;
	u8g_My_SetaFonte(u8g_font_8x13B);	// --- FUN��O PARA DEFINI��O DE FONTE
	h = u8g_GetFontAscent(&u8g)-u8g_GetFontDescent(&u8g)+1;
	Box_INI = 62;
	Box_FIM = 29;

	if(*Mmenu_Current == 0 )
	{
		u8g_DrawBox(&u8g, Box_INI+16, 1*h+7, Box_FIM-2, h);		// --- IMPRIME CAIXA BRANCA
		u8g_SetDefaultBackgroundColor(&u8g);					// --- DEFINE BACKGROUND BRANCO LETRA PRETA

		sprintf(Buff_Display,"%3.0d",Carro->CMPRS_Delay_PC);
		u8g_DrawStr(&u8g, 76, 1*h+7, Buff_Display);			// --- IMPRIME A LINHA 1 INVERTIDA
		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
		u8g_DrawStr(&u8g, 7, 1*h+7, "Delay ON:    s");		// --- IMPRIME A LINHA 1 NORMAL

		sprintf(Buff_Display,"Max ON:%3.0d min",Carro->CMPRS_Tempo_max_on);
		u8g_DrawStr(&u8g, 7, 2*h+7, Buff_Display);			// --- IMPRIME A LINHA 2 NORMAL
	}
	if(*Mmenu_Current == 1)
	{
		u8g_DrawBox(&u8g, Box_INI, 2*h+7, Box_FIM, h);		// --- IMPRIME CAIXA BRANCA
		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
		sprintf(Buff_Display,"Delay ON:%3.0d s",Carro->CMPRS_Delay_PC);
		u8g_DrawStr(&u8g, 7, 1*h+7, Buff_Display);			// --- IMPRIME A LINHA 1 INVERTIDA

		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
		u8g_DrawStr(&u8g, 7, 2*h+7, "Max ON:    min");		// --- IMPRIME A LINHA 1 NORMAL

		u8g_SetDefaultBackgroundColor(&u8g);					// --- DEFINE BACKGROUND BRANCO LETRA PRETA
		sprintf(Buff_Display,"%3.0d",Carro->CMPRS_Tempo_max_on);
		u8g_DrawStr(&u8g, 62, 2*h+7, Buff_Display);			// --- IMPRIME A LINHA 2 NORMAL
		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
	}

	u8g_DrawBox(&u8g, 0, 51, 127, 64);     		// --- BACKGROUND BARRA INFERIOR
	u8g_DrawBox(&u8g, 0, 0, 127, 14);     		// --- BACKGROUND BARRA SUPERIOR
	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_My_SetaFonte(u8g_font_8x13B);					// --- FUN��O PARA DEFINI��O DE FONTE
	u8g_DrawStr(&u8g, 17, 1, String_temporizacao);	// --- LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 1, 51, String_salvar);				// --- LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 80, 51, "Cancel");			// --- LADO DIREITO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);

}
////////////////////////////////////////////////////////////////////////////////////////////

//	--- Draw_compressor_pressoes_1---------------------------------------------------- //////
void Draw_compressor_pressoes(uint8_t *Mmenu_Current, CARRO *Carro)
{
	static int Box_INI, Box_FIM;
	uint8_t h;
	u8g_uint_t w;
	u8g_My_SetaFonte(u8g_font_8x13B);	// --- FUN��O PARA DEFINI��O DE FONTE
	h = u8g_GetFontAscent(&u8g)-u8g_GetFontDescent(&u8g)+1;
	w = u8g_GetWidth(&u8g)-10;
	Box_INI = 5;
	Box_FIM = w;

	if(*Mmenu_Current == 0 )
	{
		u8g_DrawBox(&u8g, Box_INI, 1*h+7, Box_FIM, h);		// --- IMPRIME CAIXA BRANCA
		u8g_SetDefaultBackgroundColor(&u8g);					// --- DEFINE BACKGROUND BRANCO LETRA PRETA
		sprintf(Buff_Display,String_max_psi,Carro->Max_Pressure_CMPRS);
		u8g_DrawStr(&u8g, 7, 1*h+7, Buff_Display);			// --- IMPRIME A LINHA 1 NORMAL
		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
		sprintf(Buff_Display,String_min_psi,Carro->Min_Pressure_CMPRS);
		u8g_DrawStr(&u8g, 7, 2*h+7, Buff_Display);			// --- IMPRIME A LINHA 2 INVERTIDA

		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
	}
	if(*Mmenu_Current == 1)
	{
		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
		u8g_DrawBox(&u8g, Box_INI, 2*h+7, Box_FIM, h);		// --- IMPRIME CAIXA BRANCA
		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
		sprintf(Buff_Display,String_max_psi,Carro->Max_Pressure_CMPRS);
		u8g_DrawStr(&u8g, 7, 1*h+7, Buff_Display);			// --- IMPRIME A LINHA 1 INVERTIDA
		u8g_SetDefaultBackgroundColor(&u8g);					// --- DEFINE BACKGROUND BRANCO LETRA PRETA
		sprintf(Buff_Display,String_min_psi,Carro->Min_Pressure_CMPRS);
		u8g_DrawStr(&u8g, 7, 2*h+7, Buff_Display);			// --- IMPRIME A LINHA 2 NORMAL

		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
	}

	u8g_DrawBox(&u8g, 0, 51, 127, 64);     				// --- BACKGROUND BARRA INFERIOR
	u8g_DrawBox(&u8g, 0, 0, 127, 14);     					// --- BACKGROUND BARRA SUPERIOR
	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_My_SetaFonte(u8g_font_8x13B);						// --- FUN��O PARA DEFINI��O DE FONTE
	u8g_DrawStr(&u8g, 17, 1, String_reservatorio);				// --- LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 1, 51, String_alterar);					// --- LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 80, 51, String_voltar);					// --- LADO DIREITO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);
}
////////////////////////////////////////////////////////////////////////////////////////////

//	--- Draw_compressor_pressoes_2---------------------------------------------------- //////
void Draw_compressor_pressoes_2(uint8_t *Mmenu_Current, CARRO *Carro)
{
	static int Box_INI, Box_FIM;
	uint8_t h;
	u8g_My_SetaFonte(u8g_font_8x13B);	// --- FUN��O PARA DEFINI��O DE FONTE
	h = u8g_GetFontAscent(&u8g)-u8g_GetFontDescent(&u8g)+1;
	Box_INI = 62;
	Box_FIM = 29;

	if(*Mmenu_Current == 0 )
	{
		u8g_DrawBox(&u8g, Box_INI, 1*h+7, Box_FIM, h);		// --- IMPRIME CAIXA BRANCA
		u8g_SetDefaultBackgroundColor(&u8g);					// --- DEFINE BACKGROUND BRANCO LETRA PRETA

		sprintf(Buff_Display,"%3.0d",Carro->Max_Pressure_CMPRS);
		u8g_DrawStr(&u8g, 62, 1*h+7, Buff_Display);			// --- IMPRIME A LINHA 1 INVERTIDA
		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
		u8g_DrawStr(&u8g, 7, 1*h+7, String_max__psi);		// --- IMPRIME A LINHA 1 NORMAL

		sprintf(Buff_Display,String_min_psi,Carro->Min_Pressure_CMPRS);
		u8g_DrawStr(&u8g, 7, 2*h+7, Buff_Display);			// --- IMPRIME A LINHA 2 NORMAL
	}
	if(*Mmenu_Current == 1)
	{
		u8g_DrawBox(&u8g, Box_INI, 2*h+7, Box_FIM, h);		// --- IMPRIME CAIXA BRANCA
		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
		sprintf(Buff_Display,String_max_psi,Carro->Max_Pressure_CMPRS);
		u8g_DrawStr(&u8g, 7, 1*h+7, Buff_Display);			// --- IMPRIME A LINHA 1 INVERTIDA

		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
		u8g_DrawStr(&u8g, 7, 2*h+7, String_min__psi);		// --- IMPRIME A LINHA 1 NORMAL

		u8g_SetDefaultBackgroundColor(&u8g);					// --- DEFINE BACKGROUND BRANCO LETRA PRETA
		sprintf(Buff_Display,"%3.0d",Carro->Min_Pressure_CMPRS);
		u8g_DrawStr(&u8g, 62, 2*h+7, Buff_Display);			// --- IMPRIME A LINHA 2 NORMAL
		u8g_SetDefaultForegroundColor(&u8g);					// --- DEFINE BACKGROUND PRETO LETRA BRANCA
	}

	u8g_DrawBox(&u8g, 0, 51, 127, 64);     		// --- BACKGROUND BARRA INFERIOR
	u8g_DrawBox(&u8g, 0, 0, 127, 14);     		// --- BACKGROUND BARRA SUPERIOR
	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_My_SetaFonte(u8g_font_8x13B);					// --- FUN��O PARA DEFINI��O DE FONTE
	u8g_DrawStr(&u8g, 17, 1, String_pressoes);	// --- LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 1, 51, String_salvar);				// --- LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 80, 51, "Cancel");			// --- LADO DIREITO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);

}
////////////////////////////////////////////////////////////////////////////////////////////

//--DRAW PASSO TESTE BOTOES ----------------------------------
void Draw_imprime_passo(char *string1)
{
	uint8_t h;
	u8g_My_SetaFonte(u8g_font_8x13B);	//FUNCAO PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);
	h = u8g_GetFontAscent(&u8g)-u8g_GetFontDescent(&u8g)+1;

	u8g_DrawBox(&u8g, 0, 51, 127, 64);  	//BACKGROUND BARRA INFERIOR
	u8g_DrawLine(&u8g,0, 0, 127, 0);		//LINHA HORIZONTAL SUPERIOR
	u8g_DrawLine(&u8g,0, 0, 0, 64);			//LINHA VERTICAL ESQUERDA
	u8g_DrawLine(&u8g,127, 0, 127, 64);		//LINHA VERTICAL DIREITA
	u8g_DrawStr(&u8g, 5, 0*h+7,"  PRESSIONE");	//LINHA 1
	//	u8g_DrawStr(&u8g, 5, 1*h+7,string2);	//LINHA 2
	u8g_DrawStr(&u8g, 5, 2*h+7,string1);	//LINHA 3
	u8g_SetDefaultBackgroundColor(&u8g);
	//	u8g_DrawStr(&u8g, 5, 51, "OK");			//LADO ESQUERDO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);
}//

//--DRAW PASSO TESTE BOTOES ----------------------------------
void Draw_imprime_passo_GIGA(CARRO *Carro, uint8_t Maquina, uint8_t Erro)
{
	uint8_t h;
	u8g_My_SetaFonte(u8g_font_8x13B);	//FUNCAO PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);
	h = u8g_GetFontAscent(&u8g)-u8g_GetFontDescent(&u8g)+1;

	/*---SEM ERRO DETECTADO---*/
	if(Erro == 0 && Maquina != GIGA_ERRO)
	{
		//imprime tela inicial da giga
		if(Maquina == GIGA_EM_ESPERA)
		{
			u8g_DrawStr(&u8g, 5, 0*h+7," >MENU<  para  ");	//LINHA 1
			u8g_DrawStr(&u8g, 5, 1*h+7," comecar teste ");	//LINHA 2
			u8g_DrawStr(&u8g, 5, 2*h+7,"               ");	//LINHA 3
		}
		//imprime tela CONECTANDO
		else if(Maquina == GIGA_CONECTANDO)
		{
			u8g_DrawStr(&u8g, 5, 0*h+7," conectando... ");	//LINHA 1
			u8g_DrawStr(&u8g, 5, 1*h+7," >Press MENU < ");	//LINHA 2
			u8g_DrawStr(&u8g, 5, 2*h+7,"  p/ cancelar  ");	//LINHA 3
		}
		//Faz a impressão do passo
		else
		{



			sprintf(Buff_Display,"%3.0d",Carro->Bolsa_RealTime.byte.FL);
			if(Carro->Altura_SetPoint.byte.FL == 0)
				sprintf(Buff_Display,"  0");
			u8g_DrawStr(&u8g, 70, 10, Buff_Display);

			sprintf(Buff_Display,"%3.0d",Carro->Bolsa_RealTime.byte.FR);
			if(Carro->Altura_SetPoint.byte.FR == 0)
				sprintf(Buff_Display,"  0");
			u8g_DrawStr(&u8g, 90, 40, Buff_Display);

			sprintf(Buff_Display,"%3.0d",Carro->Bolsa_RealTime.byte.RL);
			if(Carro->Altura_SetPoint.byte.RL == 0)
				sprintf(Buff_Display,"  0");
			u8g_DrawStr(&u8g, 70, 40, Buff_Display);

			sprintf(Buff_Display,"%3.0d",Carro->Bolsa_RealTime.byte.RR);
			if(Carro->Altura_SetPoint.byte.RR == 0)
				sprintf(Buff_Display,"  0");
			u8g_DrawStr(&u8g, 90, 10, Buff_Display);




			u8g_DrawStr(&u8g, 5, 0*h+7,"    PASSO      ");	//LINHA 1
			sprintf(Buff_Display,"%3.0d",Maquina);
			u8g_DrawStr(&u8g, 10, 1*h+7, Buff_Display);
		}
	}
	/*---  E  R  R  O  ---*/
	else
	{
		u8g_DrawStr(&u8g, 5, 0*h+7,"   E R R O     ");	//LINHA 1

		switch (Erro) {
			case ERRO_FL_IN:
				u8g_DrawStr(&u8g, 5, 1*h+7,"   ERRO_FL_IN  ");	//LINHA 2
				break;
			case ERRO_FR_IN:
				u8g_DrawStr(&u8g, 5, 1*h+7,"   ERRO_FR_IN  ");	//LINHA 2
				break;
			case ERRO_RL_IN:
				u8g_DrawStr(&u8g, 5, 1*h+7,"   ERRO_RL_IN  ");	//LINHA 2
				break;
			case ERRO_RR_IN:
				u8g_DrawStr(&u8g, 5, 1*h+7,"   ERRO_RR_IN  ");	//LINHA 2
				break;
			case ERRO_FL_OUT:
				u8g_DrawStr(&u8g, 5, 1*h+7,"   ERRO_FL_OUT  ");	//LINHA 2
				break;
			case ERRO_FR_OUT:
				u8g_DrawStr(&u8g, 5, 1*h+7,"   ERRO_FR_OUT  ");	//LINHA 2
				break;
			case ERRO_RL_OUT:
				u8g_DrawStr(&u8g, 5, 1*h+7,"   ERRO_RL_OUT  ");	//LINHA 2
				break;
			case ERRO_RR_OUT:
				u8g_DrawStr(&u8g, 5, 1*h+7,"   ERRO_RR_OUT  ");	//LINHA 2
				break;
			case ERRO_CMPRS:
				u8g_DrawStr(&u8g, 5, 1*h+7," ERRO_CMPRSL_IN ");	//LINHA 2
				break;

			default:
				u8g_DrawStr(&u8g, 5, 1*h+7,"ué");	//LINHA 2
				break;
		}
	}
	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_SetDefaultForegroundColor(&u8g);
}//


//--DRAW NOVA ALTURA ------------------------------------------
void Draw_Ocupantes(TIPO_OCUPANTES ocupantes)
{

	void desenha_banco(int x, int y, int FLAG)
	{
		static int largura 	= 18;
		static int altura 	= 10;
		static int raio 		= 2;

		if(FLAG)
		{
			u8g_DrawRBox(&u8g, x, y, largura, altura, raio);
		}
		else
		{
			u8g_DrawRFrame(&u8g, x, y, largura, altura, raio);
		}

		u8g_DrawHLine(&u8g,x+2,y+altura,largura-4);
	}

	u8g_My_SetaFonte(u8g_font_8x13B);		//FUNCAO PARA DEFINI��O DE FONTE
	u8g_SetDefaultForegroundColor(&u8g);	//FUNDO PRETO   -   LETRA BRANCA

#define H1 5//offset
#define H2 15//distancia para proximo
#define V1 85//offset
#define V2 20//distancia para proximo

	static int XFL=V1,YFL=H1;				//VAR DE POSICIONAMENTO DE FL
	static int XRL=V1,YRL=H1+H2;				//VAR DE POSICIONAMENTO DE RL
	static int XFR=V1+V2,YFR=H1;				//VAR DE POSICIONAMENTO DE FR
	static int XRR=V1+V2,YRR=H1+H2;				//VAR DE POSICIONAMENTO DE RR

	if(ocupantes.bit.FL)
	{
		desenha_banco(XFL,YFL,1);
		LED_H1_ON
	}
	else
	{
		desenha_banco(XFL,YFL,0);
		LED_H1_OFF
	}

	if(ocupantes.bit.FR)
	{
		desenha_banco(XFR,YFR,1);
		LED_H2_ON
	}
	else
	{
		desenha_banco(XFR,YFR,0);
		LED_H2_OFF
	}
	if(ocupantes.bit.RL)
	{
		desenha_banco(XRL,YRL,1);
		LED_H3_ON
	}
	else
	{
		desenha_banco(XRL,YRL,0);
		LED_H3_OFF
	}
	if(ocupantes.bit.RR)
	{
		desenha_banco(XRR,YRR,1);
		LED_H4_ON
	}
	else
	{
		desenha_banco(XRR,YRR,0);
		LED_H4_OFF
	}


	if(ocupantes.bit.MALA>0)
	{


		u8g_DrawRBox(&u8g, 87, 34, 34, 12, 2);
		u8g_SetDefaultBackgroundColor(&u8g);
		u8g_My_SetaFonte(u8g_font_8x13B);		//FUNCAO PARA DEFINI��O DE FONTE
		sprintf(Buff_Display,"+%1.0d",ocupantes.bit.MALA);
		u8g_DrawStr(&u8g, 95, 34, Buff_Display);
		u8g_SetDefaultForegroundColor(&u8g);
	}
	else
	{
		u8g_DrawRFrame(&u8g, 87, 34, 34, 12, 2);
	}





	u8g_SetColorIndex(&u8g,1);
	u8g_SetDefaultForegroundColor(&u8g);

	u8g_DrawBox(&u8g, 0, 51, 127, 64);    	//BACKGROUND BARRA INFERIOR
	u8g_DrawBox(&u8g, 0, 0, 75, 14);     	//BACKGROUND BARRA SUPERIOR
	u8g_SetDefaultBackgroundColor(&u8g);
	u8g_My_SetaFonte(u8g_font_8x13B);		//FUNCAO PARA DEFINI��O DE FONTE
	u8g_DrawStr(&u8g, 1, 1, String_selecione);	//LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 1, 51, String_salvar);		//LADO ESQUERDO BARRA INFERIOR
	u8g_DrawStr(&u8g, 80, 51, String_voltar);	//LADO DIREITO BARRA INFERIOR
	u8g_SetDefaultForegroundColor(&u8g);

	u8g_DrawLine(&u8g,0, 0, 127, 0);		//LINHA HORIZONTAL SUPERIOR
	u8g_DrawLine(&u8g,0, 0, 0, 64);			//LINHA VERTICAL ESQUERDA
	u8g_DrawLine(&u8g,127, 0, 127, 64);		//LINHA VERTICAL DIREITA

}//

//--SETA FONTE ------------------------------------------
void u8g_My_SetaFonte(const u8g_fntpgm_uint8_t  *font)
{
	u8g_SetFont(&u8g, font);
	u8g_SetFontRefHeightText(&u8g);
	u8g_SetFontPosTop(&u8g);
}//


