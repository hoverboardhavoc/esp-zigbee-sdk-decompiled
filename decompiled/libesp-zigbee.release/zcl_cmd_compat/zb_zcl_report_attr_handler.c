/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_report_attr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_report_attr_handler(undefined1 *param_1,code *param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  undefined1 local_30 [4];
  undefined1 uStack_2c;
  undefined1 auStack_28 [8];
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  undefined1 uStack_18;
  undefined2 uStack_16;
  undefined4 uStack_14;
  
  memset(local_30,0,0x20);
  local_30[0] = *param_1;
  puVar3 = *(undefined1 **)(param_1 + 8);
  uStack_2c = *puVar3;
  memcpy(auStack_28,puVar3 + 2,8);
  uStack_1e = *(undefined2 *)(puVar3 + 0x16);
  uStack_20 = *(undefined2 *)(puVar3 + 0x14);
  puVar2 = *(undefined2 **)(param_1 + 0xc);
  if (puVar2 != (undefined2 *)0x0) {
    uStack_1c = *puVar2;
    uStack_18 = *(undefined1 *)(puVar2 + 1);
    uStack_14 = *(undefined4 *)(puVar2 + 2);
    uStack_16 = ezb_zcl_get_attr_value_size();
  }
  if (param_2 != (code *)0x0) {
    (*param_2)(5,local_30);
    uVar1 = esp_err_to_zcl_status();
    param_1[0x10] = uVar1;
  }
  return;
}

