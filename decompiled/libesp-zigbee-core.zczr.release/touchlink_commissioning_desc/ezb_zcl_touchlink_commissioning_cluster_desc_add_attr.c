/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_commissioning_desc.o -> ezb_zcl_touchlink_commissioning_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zcl_touchlink_commissioning_cluster_desc_add_attr(short *param_1)

{
  if (param_1 != (short *)0x0) {
    if (*param_1 != 0x1000) {
      return 2;
    }
    if ((ushort)(*(byte *)(param_1 + 1) - 1) < 2) {
      return 6;
    }
    __assert_func(0,0,0,0);
  }
  return 2;
}

