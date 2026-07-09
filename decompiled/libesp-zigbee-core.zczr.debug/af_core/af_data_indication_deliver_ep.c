/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_indication_deliver_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void af_data_indication_deliver_ep(void *param_1,undefined1 param_2,undefined4 param_3)

{
  void *__dest;
  int iVar1;
  
  __dest = calloc(1,0x24);
  if (__dest != (void *)0x0) {
    memcpy(__dest,param_1,0x14);
    iVar1 = zmsg_clone(*(undefined4 *)((int)param_1 + 0x10));
    *(int *)((int)__dest + 0x10) = iVar1;
    if (iVar1 == 0) {
      mm_free(__dest);
    }
    else {
      *(undefined1 *)((int)__dest + 7) = param_2;
      milli_timer_init((int)__dest + 0x14,af_data_indication_deliver_ep_handler,__dest);
      milli_timer_start((int)__dest + 0x14,param_3);
    }
  }
  return;
}

