/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> price_desc.o -> ezb_zcl_price_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_price_create_cluster_desc(uint param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = zcl_create_cluster_desc(0x700,0);
  if (iVar1 != 0) {
    if ((param_1 & 1) == 0) {
      puVar2 = &ezb_zcl_price_cluster_client_init;
    }
    else {
      puVar2 = &ezb_zcl_price_cluster_server_init;
    }
    *(undefined **)(iVar1 + 8) = puVar2;
  }
  return;
}

