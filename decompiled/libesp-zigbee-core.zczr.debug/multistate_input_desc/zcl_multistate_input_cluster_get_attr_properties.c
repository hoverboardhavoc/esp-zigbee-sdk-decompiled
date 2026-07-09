/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> multistate_input_desc.o -> zcl_multistate_input_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_multistate_input_cluster_get_attr_properties
          (int param_1,uint param_2,char *param_3,char *param_4)

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
      param_3 = "zcl_multistate_input_cluster_get_attr_properties";
      param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/multistate_input_desc.c"
                              ,0x19);
    }
    if (param_2 == 0x55) {
      *param_4 = '\a';
      *param_3 = '!';
      uVar1 = 0;
    }
    else {
      if (param_2 < 0x56) {
        if (param_2 == 0x1c) {
          *param_4 = '\x03';
          *param_3 = 'B';
          return 0;
        }
        if (param_2 < 0x1d) {
          if (param_2 == 0xe) {
            *param_4 = '\x03';
            *param_3 = 'H';
            return 0;
          }
          return 6;
        }
        if (param_2 != 0x4a) {
          if (param_2 == 0x51) {
            *param_4 = '\x03';
            *param_3 = '\x10';
            return 0;
          }
          return 6;
        }
      }
      else {
        if (param_2 == 0x6f) {
          *param_4 = '\x05';
          *param_3 = '\x18';
          return 0;
        }
        if (0x6f < param_2) {
          if (param_2 == 0x100) {
            *param_4 = '\x01';
            *param_3 = '#';
            return 0;
          }
          return 6;
        }
        if (param_2 == 0x67) {
          *param_4 = '\x03';
          *param_3 = '0';
          return 0;
        }
        if (param_2 != 0x68) {
          return 6;
        }
      }
      *param_4 = '\x03';
      *param_3 = '!';
      uVar1 = 0;
    }
  }
  return uVar1;
}

