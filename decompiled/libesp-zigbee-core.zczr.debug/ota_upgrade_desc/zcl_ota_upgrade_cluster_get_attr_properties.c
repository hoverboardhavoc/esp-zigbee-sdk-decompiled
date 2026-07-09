/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_desc.o -> zcl_ota_upgrade_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_ota_upgrade_cluster_get_attr_properties(int param_1,uint param_2,char *param_3,char *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_3 == (char *)0x0) {
    uVar1 = 2;
  }
  else if (param_4 == (char *)0x0) {
    uVar1 = 2;
  }
  else {
    if ((param_1 - 1U & 0xffff) < 2) {
      if (param_1 != 1) {
        if (0xc < param_2) {
          if (param_2 == 0xeff0) {
            *param_4 = '@';
            *param_3 = '\0';
            return 0;
          }
          return 6;
        }
        if ((short)param_2 == 0) {
          if (param_2 == 0) {
            *param_4 = '\x01';
            *param_3 = -0x10;
            return 0;
          }
          return 6;
        }
        uVar2 = 1 << (param_2 & 0x1f);
        if ((uVar2 & 0x3a8) != 0) {
          *param_4 = '\x01';
          *param_3 = '!';
          return 0;
        }
        if ((uVar2 & 0x416) == 0) {
          if ((uVar2 >> 6 & 0x61) == 0) {
            return 6;
          }
          *param_4 = '\x01';
          *param_3 = '0';
          return 0;
        }
        *param_4 = '\x01';
        *param_3 = '#';
        return 0;
      }
    }
    else {
      param_4 = "cluster_role == 0x01U || cluster_role == 0x02U";
      param_3 = "zcl_ota_upgrade_cluster_get_attr_properties";
      param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_desc.c"
                              ,0x19);
    }
    if (param_2 == 0xeff0) {
      *param_4 = '@';
      *param_3 = ' ';
      uVar1 = 0;
    }
    else if (param_2 == 0xeff1) {
      *param_4 = '@';
      *param_3 = '\0';
      uVar1 = 0;
    }
    else {
      uVar1 = 6;
    }
  }
  return uVar1;
}

