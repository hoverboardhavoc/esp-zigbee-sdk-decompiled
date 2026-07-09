/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_price_publish_price_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_price_publish_price_handler(undefined1 *param_1,code *param_2)

{
  undefined1 uVar1;
  undefined1 local_50;
  undefined1 uStack_4f;
  undefined2 uStack_4e;
  undefined1 auStack_4c [64];
  
  memset(&local_50,0,0x40);
  local_50 = *param_1;
  uStack_4f = param_1[1];
  uStack_4e = *(undefined2 *)(param_1 + 2);
  memcpy(auStack_4c,param_1 + 0xc,0x3b);
  if (param_2 != (code *)0x0) {
    (*param_2)(0x4f,&local_50);
    uVar1 = esp_err_to_zcl_status();
    param_1[0x48] = uVar1;
  }
  return;
}

