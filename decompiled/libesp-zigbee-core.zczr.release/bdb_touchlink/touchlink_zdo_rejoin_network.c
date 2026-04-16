/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> touchlink_zdo_rejoin_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_zdo_rejoin_network(void *arg)

{
  if (arg != (void *)0x0) {
    touchlink_commissioning_set_logic_channel(*(undefined1 *)((int)arg + 0xc));
    touchlink_zdo_set_rejoin_network_info((touchlink_event_rejoin_network_t *)arg);
  }
  zdo_initiate_rejoin();
  return;
}

