/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_zdo_set_rejoin_network_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_zdo_set_rejoin_network_info(int param_1)

{
  int iVar1;
  
  nwk_set_extended_panid(param_1 + 1);
  nwk_set_panid(*(undefined2 *)(param_1 + 10));
  nwk_set_short_address(*(undefined2 *)(param_1 + 0xe));
  iVar1 = touchlink_commissioning_get();
  if (*(char *)(iVar1 + 1) == '\x02') {
    nwk_secur_set_key(param_1 + 0x10,0);
  }
  nwk_secur_switch_key(0);
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xb18) = *(byte *)(iVar1 + 0xb18) & 0xfe;
  return;
}

