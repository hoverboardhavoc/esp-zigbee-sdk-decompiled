/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_cluster_srv_set_attr_val_post_proc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_zone_cluster_srv_set_attr_val_post_proc(int param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 0x10) {
    ias_zone_cie_address_attr_write_handler
              (*(undefined1 *)(param_1 + 0x15),*(undefined1 *)(param_1 + 0x14),
               *(undefined2 *)(param_1 + 2),param_3);
  }
  return;
}

