/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_indication_deliver_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void af_data_indication_deliver_ep(aps_apsde_data_ind_t *ind,uint8_t ep_id,uint32_t delay_ms)

{
  void *__dest;
  int iVar1;
  
  __dest = calloc(1,0x24);
  if (__dest != (void *)0x0) {
    memcpy(__dest,ind,0x14);
    iVar1 = zmsg_clone(ind->asdu);
    *(int *)((int)__dest + 0x10) = iVar1;
    if (iVar1 == 0) {
      mm_free(__dest);
    }
    else {
      *(uint8_t *)((int)__dest + 7) = ep_id;
      milli_timer_init((int)__dest + 0x14,af_data_indication_deliver_ep_handler,__dest);
      milli_timer_start((int)__dest + 0x14,delay_ms);
    }
  }
  return;
}

