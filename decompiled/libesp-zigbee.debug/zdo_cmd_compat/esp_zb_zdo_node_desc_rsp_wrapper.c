/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_node_desc_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_node_desc_rsp_wrapper(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined1 *puVar3;
  uint local_20;
  uint uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  pcVar2 = (code *)*param_2;
  if (pcVar2 != (code *)0x0) {
    puVar1 = param_2;
    if (*param_1 == 0) {
      if (param_1[1] != 0) {
        puVar3 = (undefined1 *)param_1[1];
        local_20 = (uint)*(uint3 *)(puVar3 + 4);
        uStack_1c = (uint)*(uint3 *)(puVar3 + 8);
        uStack_18 = *(undefined4 *)(puVar3 + 0xc);
        uStack_14 = (uint)*(uint3 *)(puVar3 + 0x10);
        (*pcVar2)(*puVar3,*(undefined2 *)(puVar3 + 2),&local_20,param_2[1]);
        goto _L0;
      }
      puVar1 = (undefined4 *)
               __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                             ,0x111,"esp_zb_zdo_node_desc_rsp_wrapper","result->rsp");
    }
    (*pcVar2)(0x85,0xffff,0,puVar1[1]);
  }
_L0:
  free(param_2);
  return;
}

