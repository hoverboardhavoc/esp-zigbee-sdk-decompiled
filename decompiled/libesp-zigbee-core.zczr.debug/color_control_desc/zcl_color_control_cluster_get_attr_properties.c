/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control_desc.o -> zcl_color_control_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_color_control_cluster_get_attr_properties(int param_1,uint param_2,char *param_3,char *param_4)

{
  uint uVar1;
  
  if (param_3 == (char *)0x0) {
    return 2;
  }
  if (param_4 == (char *)0x0) {
    return 2;
  }
  if ((param_1 - 1U & 0xffff) < 2) {
    if (param_1 != 1) {
      return 6;
    }
  }
  else {
    param_4 = "cluster_role == 0x01U || cluster_role == 0x02U";
    param_3 = "zcl_color_control_cluster_get_attr_properties";
    param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control_desc.c"
                            ,0x19);
  }
  if (param_2 < 0x2a) {
    if (param_2 < 0xf) {
      if (4 < param_2) {
        if (param_2 == 6) {
          *param_4 = '\x01';
          *param_3 = 'B';
          return 0;
        }
        if (param_2 < 7) {
          if (param_2 != 5) {
            return 6;
          }
        }
        else {
          if (param_2 == 7) goto _L0;
          if (param_2 != 8) {
            return 6;
          }
        }
_L0:
        *param_4 = '\x01';
        *param_3 = '0';
        return 0;
      }
      if (2 < param_2) {
_L0:
        *param_4 = '\x15';
        *param_3 = '!';
        return 0;
      }
      if (param_2 == 1) {
        *param_4 = '\x15';
        *param_3 = ' ';
        return 0;
      }
      if (param_2 != 2) {
        if (param_2 == 0) {
          *param_4 = '\x05';
          *param_3 = ' ';
          return 0;
        }
        return 6;
      }
    }
    else {
      uVar1 = 1 << (param_2 - 0xf & 0x1f);
      if ((uVar1 & 0x6660ccc) == 0) {
        if ((uVar1 & 0x881112) == 0) {
          if ((uVar1 & 1) == 0) {
            return 6;
          }
          *param_4 = '\x03';
          *param_3 = '\x18';
          return 0;
        }
_L0:
        *param_4 = '\x01';
        *param_3 = ' ';
        return 0;
      }
    }
  }
  else {
    if (param_2 < 0x4004) {
      if (0x4001 < param_2) {
        *param_4 = '\x11';
        *param_3 = ' ';
        return 0;
      }
      if (0x3c < param_2) {
        if (param_2 != 0x4000) {
          if (param_2 != 0x4001) {
            return 6;
          }
          goto _L0;
        }
_L0:
        *param_4 = '\x11';
        *param_3 = '!';
        return 0;
      }
      if (param_2 < 0x2a) {
        return 6;
      }
      uVar1 = 1 << (param_2 - 0x2a & 0x1f);
      if ((uVar1 & 0x333c0) == 0) {
        if ((uVar1 >> 10 & 0x111) != 0) {
          *param_4 = '\x03';
          *param_3 = ' ';
          return 0;
        }
        if ((uVar1 & 1) == 0) {
          return 6;
        }
        goto _L0;
      }
_L0:
      *param_4 = '\x03';
      *param_3 = '!';
      return 0;
    }
    if (param_2 == 0x400a) {
      *param_4 = '\x01';
      *param_3 = '\x19';
      return 0;
    }
    if (param_2 < 0x400b) {
      if (param_2 == 0x4004) goto _L0;
      if (param_2 < 0x4004) {
        return 6;
      }
      if (1 < (param_2 - 0x4005 & 0xffff)) {
        return 6;
      }
    }
    else {
      if (param_2 == 0xeff0) {
        *param_4 = '@';
        *param_3 = '\0';
        return 0;
      }
      if (0xeff0 < param_2) {
        return 6;
      }
      if (0x400d < param_2) {
        if (param_2 != 0x4010) {
          return 6;
        }
        goto _L0;
      }
      if (param_2 < 0x400b) {
        return 6;
      }
    }
  }
  *param_4 = '\x01';
  *param_3 = '!';
  return 0;
}

