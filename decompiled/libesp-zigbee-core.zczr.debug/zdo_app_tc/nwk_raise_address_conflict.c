/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_tc.o -> nwk_raise_address_conflict
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_raise_address_conflict(undefined4 param_1)

{
  undefined4 uStack_14;
  
  uStack_14 = (uint)CONCAT12((char)((uint)param_1 >> 8),CONCAT11((char)param_1,0xd));
  nwk_send_status(0xfffd,&uStack_14);
  nwk_handle_network_status_local(&uStack_14);
  return;
}

