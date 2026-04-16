/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  
  __dest = calloc(1,0x20);
  if (__dest != (void *)0x0) {
    memcpy(__dest,ind,0x10);
    iVar1 = zmsg_clone(ind->asdu);
    *(int *)((int)__dest + 0xc) = iVar1;
    if (iVar1 == 0) {
      mm_free(__dest);
    }
    else {
      *(uint8_t *)((int)__dest + 7) = ep_id;
      milli_timer_init((int)__dest + 0x10,af_data_indication_deliver_ep_handler,__dest);
      milli_timer_start((int)__dest + 0x10,delay_ms);
    }
  }
  return;
}

