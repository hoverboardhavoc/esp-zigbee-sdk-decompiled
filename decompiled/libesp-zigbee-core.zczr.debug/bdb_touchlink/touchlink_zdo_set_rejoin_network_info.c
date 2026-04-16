/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_zdo_set_rejoin_network_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_zdo_set_rejoin_network_info(touchlink_event_rejoin_network_t *rejoin_network)

{
  int iVar1;
  
  nwk_set_extended_panid(&rejoin_network->ext_panid);
  nwk_set_panid(rejoin_network->pan_id);
  nwk_set_short_address(rejoin_network->nwk_addr);
  iVar1 = touchlink_commissioning_get();
  if (*(char *)(iVar1 + 1) == '\x02') {
    nwk_secur_set_key(rejoin_network->nwk_key,0);
  }
  nwk_secur_switch_key(0);
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xb18) = *(byte *)(iVar1 + 0xb18) & 0xfe;
  return;
}

