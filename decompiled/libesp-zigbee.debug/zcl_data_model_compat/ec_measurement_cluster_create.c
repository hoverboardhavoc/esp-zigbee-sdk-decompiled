/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_data_model_compat.o -> ec_measurement_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ec_measurement_cluster_create(void)

{
  int iVar1;
  
  iVar1 = ezb_zcl_ec_measurement_create_cluster_desc(1);
  if (iVar1 != 0) {
    iVar1 = iVar1 + 0xc;
  }
  return iVar1;
}

