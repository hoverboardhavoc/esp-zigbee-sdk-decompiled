/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_intrp.o -> nwk_intrp_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_intrp_data_indication(undefined2 *param_1)

{
  log_write(3,"INTRP_NWK",">>>>>>>>>>>>>>>>>>>>");
  log_write(3,"INTRP_NWK","NWK Rx Inter-PAN Frame: 0x%04x:%d->0x%04x:%d, lqi(%d), rssi(%d)",
            param_1[2],*param_1,param_1[8],param_1[6],*(undefined1 *)(param_1 + 0xe));
  log_write(3,"INTRP_NWK","<<<<<<<<<<<<<<<<<<<<");
  zmsg_dump(3,"INTRP_NWK",*(undefined4 *)(param_1 + 0xc));
  if (*(int *)(param_1 + 0xc) != 0) {
    zmsg_free();
  }
  return;
}

