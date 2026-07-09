/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> level_desc.o -> zcl_level_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_level_cluster_get_attr_properties(int param_1,uint param_2,char *param_3,char *param_4)

{
  undefined4 uVar1;
  
  if (param_3 == (char *)0x0) {
    uVar1 = 2;
  }
  else if (param_4 == (char *)0x0) {
    uVar1 = 2;
  }
  else {
    if ((param_1 - 1U & 0xffff) < 2) {
      if (param_1 != 1) {
        return 6;
      }
    }
    else {
      param_4 = "cluster_role == 0x01U || cluster_role == 0x02U";
      param_3 = "zcl_level_cluster_get_attr_properties";
      param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/level_desc.c"
                              ,0x16);
    }
    if (param_2 == 0xf) {
      *param_4 = '\x03';
      *param_3 = '\x18';
      uVar1 = 0;
    }
    else if (param_2 < 0x10) {
      if (param_2 < 4) {
        if (1 < param_2) {
          *param_4 = '\x01';
          *param_3 = ' ';
          return 0;
        }
        if (param_2 == 0) {
          *param_4 = '\x15';
          *param_3 = ' ';
          return 0;
        }
        if (param_2 != 1) {
          return 6;
        }
      }
      else {
        if (param_2 == 4) {
          *param_4 = '\x15';
          *param_3 = '!';
          return 0;
        }
        if (param_2 < 4) {
          return 6;
        }
        if (1 < (param_2 - 5 & 0xffff)) {
          return 6;
        }
      }
      *param_4 = '\x01';
      *param_3 = '!';
      uVar1 = 0;
    }
    else {
      if (param_2 != 0x14) {
        if (param_2 < 0x15) {
          if (param_2 != 0x11) {
            if (param_2 < 0x12) {
              if (param_2 != 0x10) {
                return 6;
              }
            }
            else if (1 < (param_2 - 0x12 & 0xffff)) {
              return 6;
            }
            *param_4 = '\x03';
            *param_3 = '!';
            return 0;
          }
        }
        else if (param_2 != 0x4000) {
          if (param_2 == 0xeff0) {
            *param_4 = '@';
            *param_3 = '\0';
            return 0;
          }
          return 6;
        }
      }
      *param_4 = '\x03';
      *param_3 = ' ';
      uVar1 = 0;
    }
  }
  return uVar1;
}

