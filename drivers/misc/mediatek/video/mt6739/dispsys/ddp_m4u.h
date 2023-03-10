/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
*/

#ifndef __DSI_M4U_H__
#define __DSI_M4U_H__

#include "m4u.h"
#include "m4u_port.h"
#include "ddp_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * display m4u port wrapper
 * -- by chip
 */
#define DISP_M4U_PORT_DISP_OVL0 M4U_PORT_DISP_OVL0
#define DISP_M4U_PORT_DISP_RDMA0 M4U_PORT_DISP_RDMA0
#define DISP_M4U_PORT_DISP_WDMA0 M4U_PORT_DISP_WDMA0

struct module_to_m4u_port_t {
	enum DISP_MODULE_ENUM module;
	int port;
};

int module_to_m4u_port(enum DISP_MODULE_ENUM module);
enum DISP_MODULE_ENUM m4u_port_to_module(int port);
int disp_m4u_callback(int port, unsigned long mva, void *data);
void disp_m4u_init(void);
int config_display_m4u_port(void);
int disp_allocate_mva(struct m4u_client_t *client, enum DISP_MODULE_ENUM module,
		      unsigned long va, struct sg_table *sg_table,
		      unsigned int size, unsigned int prot, unsigned int flags,
		      unsigned int *pMva);

#ifdef __cplusplus
}
#endif
#endif /* __DSI_M4U_H__ */
