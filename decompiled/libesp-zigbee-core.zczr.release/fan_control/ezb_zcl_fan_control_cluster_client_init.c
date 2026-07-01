/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> fan_control.o -> ezb_zcl_fan_control_cluster_client_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_fan_control_cluster_client_init(uint8_t ep_id)

{
  int iVar1;
  undefined1 auStack_24 [4];
  zcl_cluster_template_t template;
  
  memcpy(auStack_24,&_L0,0x14);
  iVar1 = zcl_cluster_template_add(auStack_24);
  if (iVar1 != 0) {
    __assert_func(0,0,0,0);
  }
  return;
}

