/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_zdo_start_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 touchlink_zdo_start_network(int param_1)

{
  if (param_1 != 0) {
    nwk_set_extended_panid(param_1 + 1);
    ezb_set_channel_mask(1 << (*(byte *)(param_1 + 0xc) & 0x1f));
    nwk_set_pan_channel(1 << (*(byte *)(param_1 + 0xc) & 0x1f) & 0x7ffffff);
    nwk_set_panid(*(undefined2 *)(param_1 + 10));
    nwk_set_short_address(*(undefined2 *)(param_1 + 0xe));
    aps_secur_set_distributed(1);
    zdo_initiate_commissioning(2);
    return 0;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",0x65,
                "touchlink_zdo_start_network","start_network");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

