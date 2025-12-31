#ifndef TASK_INC_TASK_ACTUATOR_ATTRIBUTE_H_
#define TASK_INC_TASK_ACTUATOR_ATTRIBUTE_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/

/********************** macros ***********************************************/

/********************** typedef **********************************************/


/* Events to excite Task Actuator */
typedef enum task_actuator_ev {EV_LED_XX_OFF,
							   EV_LED_XX_ON,
							   EV_LED_XX_NOT_BLINK,
							   EV_LED_XX_BLINK,
							   EV_LED_XX_PULSE} task_actuator_ev_t;

/* States of Task Actuator */
typedef enum task_actuator_st {ST_LED_XX_OFF,
							   ST_LED_XX_ON,
							   ST_LED_XX_BLINK_ON,
							   ST_LED_XX_BLINK_OFF,
							   ST_LED_XX_PULSE} task_actuator_st_t;

/* Identifier of Task Actuator */
typedef enum task_actuator_id {ID_LED_A} task_actuator_id_t;

typedef struct
{
	task_actuator_id_t	identifier;
	GPIO_TypeDef *		gpio_port;
	uint16_t			pin;
	GPIO_PinState		led_on;
	GPIO_PinState		led_off;
	uint32_t			tick_blink;
	uint32_t			tick_pulse;
} task_actuator_cfg_t;

typedef struct
{
	uint32_t			tick;
	task_actuator_st_t	state;
	task_actuator_ev_t	event;
	bool				flag;
} task_actuator_dta_t;

/********************** external data declaration ****************************/
extern task_actuator_dta_t task_actuator_dta_list[];

/********************** external functions declaration ***********************/

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif

#endif /* TASK_INC_TASK_ACTUATOR_ATTRIBUTE_H_ */

/********************** end of file ******************************************/
