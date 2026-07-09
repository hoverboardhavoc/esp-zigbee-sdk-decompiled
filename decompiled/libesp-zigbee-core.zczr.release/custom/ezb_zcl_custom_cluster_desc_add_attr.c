/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> custom.o -> ezb_zcl_custom_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
ezb_zcl_custom_cluster_desc_add_attr
          (short *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 uVar1;
  
  if ((param_1 != (short *)0x0) && (*param_1 < 0)) {
    uVar1 = ezb_zcl_create_attr_desc(param_2,param_3,param_4,0,param_5);
    uVar1 = ezb_zcl_cluster_add_attr_desc(param_1,uVar1);
    return uVar1;
  }
  return 2;
}

