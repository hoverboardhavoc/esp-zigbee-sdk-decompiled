/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> device_temp_config_desc.o -> ezb_zcl_device_temp_config_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
ezb_zcl_device_temp_config_cluster_desc_add_attr(short *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar3 = 2;
  if ((param_1 != (short *)0x0) && (*param_1 == 2)) {
    uVar2 = (uint)*(byte *)(param_1 + 1);
    uVar4 = 1;
    uVar1 = 2;
    if (1 < (uVar2 - 1 & 0xffff)) {
      uVar2 = 0;
      uVar1 = 0;
      param_2 = __assert_func(0,0,param_3);
    }
    uVar3 = 6;
    if (uVar2 == uVar4) {
      if (param_2 == 0x10) {
        uVar3 = 0x18;
      }
      else {
        if (param_2 < 0x11) {
          if (uVar1 < param_2) {
            if (param_2 != 3) {
              return 6;
            }
            uVar3 = 0x21;
            goto _L0;
          }
        }
        else if (0x12 < param_2) {
          if (uVar2 < (param_2 - 0x13 & 0xffff)) {
            return 6;
          }
          uVar3 = 0x22;
          goto _L0;
        }
        uVar3 = 0x29;
      }
_L0:
      uVar3 = ezb_zcl_cluster_desc_add_manuf_attr(uVar3,0);
      return uVar3;
    }
  }
  return uVar3;
}

