/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_active_ep_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_active_ep_rsp_wrapper(int *param_1,undefined4 *param_2)

{
  byte bVar1;
  void *__dest;
  undefined4 *puVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  
  pcVar4 = (code *)*param_2;
  if (pcVar4 != (code *)0x0) {
    iVar3 = *param_1;
    puVar2 = param_2;
    if (iVar3 == 0) {
      iVar5 = param_1[1];
      if (iVar5 != 0) {
        bVar1 = *(byte *)(iVar5 + 4);
        __dest = calloc((uint)bVar1,1);
        if (__dest != (void *)0x0) {
          memcpy(__dest,*(void **)(iVar5 + 8),(uint)bVar1);
        }
        (*pcVar4)(*(undefined1 *)param_1[1],((undefined1 *)param_1[1])[4],__dest,param_2[1]);
        if (__dest != (void *)0x0) {
          free(__dest);
        }
        goto _L0;
      }
      puVar2 = (undefined4 *)
               __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                             ,0x162,"esp_zb_zdo_active_ep_rsp_wrapper","result->rsp");
    }
    if (iVar3 == 7) {
      (*pcVar4)(0x85,0xff,0,puVar2[1]);
    }
  }
_L0:
  free(param_2);
  return;
}

