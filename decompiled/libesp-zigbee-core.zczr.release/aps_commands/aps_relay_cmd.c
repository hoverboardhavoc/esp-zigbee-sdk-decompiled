/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> aps_relay_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_relay_cmd(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  iVar1 = nwk_address_short_by_extended(param_2,&uStack_18);
  if (iVar1 == 0) {
    uStack_14 = uStack_14 & 0xfffcffff | 0x20000;
    uStack_1c = param_1;
    nwk_nlde_data_request(&uStack_1c);
  }
  return;
}

