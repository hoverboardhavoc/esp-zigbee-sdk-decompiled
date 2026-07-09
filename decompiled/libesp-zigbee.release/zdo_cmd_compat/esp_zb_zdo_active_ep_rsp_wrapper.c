/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_active_ep_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_active_ep_rsp_wrapper(int *param_1,undefined4 *param_2)

{
  byte bVar1;
  void *__dest;
  undefined1 *puVar2;
  code *pcVar3;
  
  pcVar3 = (code *)*param_2;
  if (pcVar3 != (code *)0x0) {
    if (*param_1 == 0) {
      puVar2 = (undefined1 *)param_1[1];
      if (puVar2 == (undefined1 *)0x0) {
        __assert_func(0,0,0,0);
      }
      bVar1 = puVar2[4];
      __dest = calloc((uint)bVar1,1);
      if (__dest != (void *)0x0) {
        memcpy(__dest,*(void **)(puVar2 + 8),(uint)bVar1);
      }
      (*pcVar3)(*puVar2,puVar2[4],__dest,param_2[1]);
      if (__dest != (void *)0x0) {
        free(__dest);
      }
    }
    else if (*param_1 == 7) {
      (*pcVar3)(0x85,0xff,0,param_2[1]);
    }
  }
  free(param_2);
  return;
}

