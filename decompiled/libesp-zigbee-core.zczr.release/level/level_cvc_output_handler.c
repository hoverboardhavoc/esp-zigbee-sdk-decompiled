/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> level_cvc_output_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void level_cvc_output_handler(undefined4 param_1,undefined1 param_2,undefined2 param_3)

{
  int iVar1;
  
  zcl_message_level_set_attr_value_isra_0(param_2);
  iVar1 = level_srv_get_attr_desc(param_1,1);
  if (iVar1 != 0) {
    **(undefined2 **)(iVar1 + 8) = param_3;
  }
  return;
}

