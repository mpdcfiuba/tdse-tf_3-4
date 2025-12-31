#ifndef CYCLIC_INC_CYCLIC_EXECUTIVE_H_
#define CYCLIC_INC_CYCLIC_EXECUTIVE_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/

/********************** macros ***********************************************/

/********************** typedef **********************************************/

/********************** external data declaration ****************************/
extern uint32_t g_app_cnt;
extern uint32_t g_app_runtime_us;

extern volatile uint32_t g_app_tick_cnt;

/********************** external functions declaration ***********************/
extern void app_init(void);
extern void app_update(void);

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif

#endif /* CYCLIC_INC_CYCLIC_EXECUTIVE_H_ */

/********************** end of file ******************************************/
