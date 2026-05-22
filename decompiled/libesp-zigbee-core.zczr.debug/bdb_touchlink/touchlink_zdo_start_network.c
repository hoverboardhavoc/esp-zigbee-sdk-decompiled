/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_zdo_start_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

ezb_err_t touchlink_zdo_start_network(touchlink_event_start_network_t *start_network)

{
  if (start_network != (touchlink_event_start_network_t *)0x0) {
    nwk_set_extended_panid(&start_network->ext_panid);
    ezb_set_channel_mask(1 << (start_network->channel & 0x1f));
    nwk_set_pan_channel(1 << (start_network->channel & 0x1f) & 0x7ffffff);
    nwk_set_panid(start_network->pan_id);
    nwk_set_short_address(start_network->new_short_addr);
    aps_secur_set_distributed(1);
    zdo_initiate_commissioning(2);
    return 0;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",0x65,
                "touchlink_zdo_start_network","start_network");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

