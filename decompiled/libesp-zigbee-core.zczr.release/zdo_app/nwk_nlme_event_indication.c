/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app.o -> nwk_nlme_event_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_nlme_event_indication(nwk_nlme_event_ind_t *ind)

{
  nwk_nlme_event_ind_t *pnVar1;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  zdo_app_signal_t signal;
  
  uStack_24 = 0;
  signal.signal = 0;
  signal.parameters[0] = '\0';
  signal.parameters[1] = '\0';
  signal.parameters[2] = '\0';
  signal.parameters[3] = '\0';
  signal.parameters[4] = '\0';
  signal.parameters[5] = '\0';
  signal.parameters[6] = '\0';
  signal.parameters[7] = '\0';
  signal.parameters[8] = '\0';
  signal.parameters[9] = '\0';
  signal.parameters[10] = '\0';
  signal.parameters[0xb] = '\0';
  pnVar1 = ind;
  if (ind->event != '\0') {
    if (ind->event == '\x01') {
      uStack_24 = (uint)CONCAT12((ind->field_1).network_status.status,0x204);
      goto _L0;
    }
    pnVar1 = (nwk_nlme_event_ind_t *)__assert_func(0,0,0,0);
  }
  uStack_24 = CONCAT22(uStack_24._2_2_,0x203);
  memcpy((void *)((int)&uStack_24 + 2),&pnVar1->field_1,6);
  if ((ind->field_1).network_status.status == '\x10') {
    uStack_2c = 0;
    uStack_28 = 0;
    zdo_device_annce_req(&uStack_2c);
  }
_L0:
  zdo_app_put_signal(&uStack_24);
  return;
}

