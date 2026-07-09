/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_raise_mto_route_failure
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_raise_mto_route_failure(undefined4 param_1,undefined4 param_2)

{
  undefined4 uStack_14;
  
  uStack_14 = (uint)CONCAT12((char)((uint)param_1 >> 8),CONCAT11((char)param_1,0xc));
  nwk_send_status(param_2,&uStack_14);
  nwk_handle_network_status_local(&uStack_14);
  return;
}

