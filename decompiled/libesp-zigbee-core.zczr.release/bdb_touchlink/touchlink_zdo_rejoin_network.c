/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> touchlink_zdo_rejoin_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_zdo_rejoin_network(int param_1)

{
  if (param_1 != 0) {
    touchlink_commissioning_set_logic_channel(*(undefined1 *)(param_1 + 0xc));
    touchlink_zdo_set_rejoin_network_info(param_1);
  }
  zdo_initiate_rejoin();
  return;
}

