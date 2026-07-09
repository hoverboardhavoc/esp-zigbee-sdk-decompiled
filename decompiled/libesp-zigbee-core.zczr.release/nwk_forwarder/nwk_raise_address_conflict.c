/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_raise_address_conflict
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_raise_address_conflict(undefined4 param_1)

{
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  uStack_13 = (undefined1)param_1;
  uStack_12 = (undefined1)((uint)param_1 >> 8);
  uStack_14 = 0xd;
  uStack_11 = 0;
  nwk_send_status(0xfffd,&uStack_14);
  nwk_handle_network_status_local(&uStack_14);
  return;
}

