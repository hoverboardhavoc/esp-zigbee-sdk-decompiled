/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_node_desc_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_node_desc_rsp_wrapper(int *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  code *pcVar6;
  undefined2 local_20;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined2 uStack_1c;
  undefined1 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined1 uStack_12;
  
  puVar4 = &local_20;
  pcVar6 = (code *)*param_2;
  if (pcVar6 != (code *)0x0) {
    if (*param_1 == 0) {
      puVar1 = (undefined1 *)param_1[1];
      if (puVar1 == (undefined1 *)0x0) {
        __assert_func(0,0,0,0);
      }
      memset(&uStack_1d,0,0xd);
      local_20 = *(undefined2 *)(puVar1 + 4);
      uVar5 = param_2[1];
      uStack_1e = puVar1[6];
      uStack_1c = *(undefined2 *)(puVar1 + 8);
      uStack_1a = puVar1[10];
      uStack_18 = *(undefined2 *)(puVar1 + 0xc);
      uStack_16 = *(undefined2 *)(puVar1 + 0xe);
      uStack_14 = *(undefined2 *)(puVar1 + 0x10);
      uStack_12 = puVar1[0x12];
      uVar3 = *(undefined2 *)(puVar1 + 2);
      uVar2 = *puVar1;
    }
    else {
      uVar5 = param_2[1];
      puVar4 = (undefined2 *)0x0;
      uVar3 = 0xffff;
      uVar2 = 0x85;
    }
    (*pcVar6)(uVar2,uVar3,puVar4,uVar5);
  }
  free(param_2);
  return;
}

