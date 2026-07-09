/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_intrp.o -> nwk_intrp_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_intrp_data_confirm(int *param_1)

{
  log_write(3,"INTRP_NWK",">>>>>>>>>>>>>>>>>>>>");
  log_write(3,"INTRP_NWK","NWK Tx Inter-PAN Frame Done: status(0x%02x)",(char)param_1[1]);
  log_write(3,"INTRP_NWK","<<<<<<<<<<<<<<<<<<<<");
  zmsg_dump(3,"INTRP_NWK",*param_1);
  if (*param_1 != 0) {
    zmsg_free();
    return;
  }
  return;
}

