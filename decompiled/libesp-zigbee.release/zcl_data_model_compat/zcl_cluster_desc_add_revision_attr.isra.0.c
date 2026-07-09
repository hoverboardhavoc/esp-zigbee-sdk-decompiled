/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_data_model_compat.o -> zcl_cluster_desc_add_revision_attr.isra.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_cluster_desc_add_revision_attr_isra_0(undefined2 param_1)

{
  undefined2 auStack_12 [7];
  
  auStack_12[0] = param_1;
  ezb_zcl_cluster_desc_add_manuf_attr(0xfffd,0x21,1,0,auStack_12);
  return;
}

