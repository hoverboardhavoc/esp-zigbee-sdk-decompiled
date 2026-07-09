/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_bind_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_bind_rsp_wrapper(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  code *pcVar3;
  
  pcVar3 = (code *)*param_2;
  if (pcVar3 != (code *)0x0) {
    puVar2 = (undefined1 *)*param_1;
    puVar1 = param_2;
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = (undefined1 *)param_1[1];
      if (puVar2 != (undefined1 *)0x0) {
        (*pcVar3)(*puVar2,param_2[1]);
        goto _L0;
      }
      puVar1 = (undefined4 *)
               __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                             ,0x96,"esp_zb_zdo_bind_rsp_wrapper","result->rsp");
    }
    if (puVar2 == (undefined1 *)0x7) {
      (*pcVar3)(0x85,puVar1[1]);
    }
  }
_L0:
  free(param_2);
  return;
}

