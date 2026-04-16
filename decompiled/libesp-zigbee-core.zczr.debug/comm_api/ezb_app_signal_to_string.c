/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> comm_api.o -> ezb_app_signal_to_string
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

char * ezb_app_signal_to_string(ezb_app_signal_type_t signal)

{
  undefined2 in_register_0000202a;
  uint uVar1;
  
  uVar1 = 0;
  while ((uVar1 < 0x16 &&
         ((uint)s_app_signal_table[uVar1].signal != CONCAT22(in_register_0000202a,signal)))) {
    uVar1 = uVar1 + 1 & 0xff;
  }
  return s_app_signal_table[uVar1].msg;
}

