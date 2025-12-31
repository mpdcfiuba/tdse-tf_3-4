#ifndef TASK_INC_TASK_SYSTEM_ATTRIBUTE_H_
#define TASK_INC_TASK_SYSTEM_ATTRIBUTE_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/

/********************** macros ***********************************************/

/********************** typedef **********************************************/

/* Events to excite Task System */
typedef enum task_system_ev {EV_SYS_IDLE,
							 EV_SYS_LOOP_DET,
							 EV_SYS_NOT_LOOP_DET,
							 EV_SYS_MANUAL_BTN,
							 EV_SYS_NOT_MANUAL_BTN,
							 EV_SYS_IR_PHO_CELL,
							 EV_SYS_NOT_IR_PHO_CELL} task_system_ev_t;

/* State of Task System */
typedef enum task_system_st {ST_SYS_IDLE,
							 ST_SYS_ACTIVE_01,
							 ST_SYS_ACTIVE_02,
							 ST_SYS_ACTIVE_03,
							 ST_SYS_ACTIVE_04,
							 ST_SYS_ACTIVE_05,
							 ST_SYS_ACTIVE_06} task_system_st_t;

typedef struct
{
	uint32_t			tick;
	task_system_st_t	state;
	task_system_ev_t	event;
	bool				flag;
} task_system_dta_t;

/********************** external data declaration ****************************/
extern task_system_dta_t task_system_dta;

/********************** external functions declaration ***********************/

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif

#endif /* TASK_INC_TASK_SYSTEM_ATTRIBUTE_H_ */

/********************** end of file ******************************************/
