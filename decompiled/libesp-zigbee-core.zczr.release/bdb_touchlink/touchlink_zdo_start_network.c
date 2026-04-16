/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> touchlink_zdo_start_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_zdo_start_network(touchlink_event_start_network_t *start_network)

{
  if (start_network == (touchlink_event_start_network_t *)0x0) {
    start_network = (touchlink_event_start_network_t *)__assert_func(0,0,0);
  }
  nwk_set_extended_panid(&start_network->ext_panid);
  ezb_set_channel_mask(1 << (start_network->channel & 0x1f));
  nwk_set_pan_channel(1 << (start_network->channel & 0x1f) & 0x7ffffff);
  nwk_set_panid(start_network->pan_id);
  nwk_set_short_address(start_network->new_short_addr);
  aps_secur_set_distributed(1);
  zdo_initiate_commissioning(2);
  return 0;
}

