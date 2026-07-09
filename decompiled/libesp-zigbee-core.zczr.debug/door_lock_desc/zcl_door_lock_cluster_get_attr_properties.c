/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> door_lock_desc.o -> zcl_door_lock_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_door_lock_cluster_get_attr_properties(int param_1,uint param_2,char *param_3,char *param_4)

{
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
    param_3 = "zcl_door_lock_cluster_get_attr_properties";
    param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/door_lock_desc.c"
                            ,0x19);
  }
  if (param_2 == 0x21) {
    *param_4 = '\a';
    *param_3 = 'B';
    return 0;
  }
  if (param_2 < 0x22) {
    if (5 < param_2) {
      if (param_2 < 0x14) {
        if (0xf < param_2) {
          *param_4 = '\x01';
          *param_3 = '!';
          return 0;
        }
        if (param_2 == 6) {
          *param_4 = '\x03';
          *param_3 = '!';
          return 0;
        }
        return 6;
      }
      if (param_2 < 0x1b) {
        if (0x13 < param_2) {
          *param_4 = '\x01';
          *param_3 = ' ';
          return 0;
        }
        return 6;
      }
      if (param_2 != 0x20) {
        return 6;
      }
      goto _L0;
    }
    if (3 < param_2) {
      *param_4 = '\x03';
      *param_3 = '#';
      return 0;
    }
    if (param_2 == 2) {
      *param_4 = '\x01';
      *param_3 = '\x10';
      return 0;
    }
    if (param_2 < 3) {
      if (param_2 != 0) {
        if (param_2 == 1) {
          *param_4 = '\x01';
          *param_3 = '0';
          return 0;
        }
        return 6;
      }
    }
    else if (param_2 != 3) {
      return 6;
    }
  }
  else {
    if (param_2 == 0x26) {
      *param_4 = '\x01';
      *param_3 = '\x19';
      return 0;
    }
    if (param_2 < 0x27) {
      if (param_2 != 0x24) {
        if (0x24 < param_2) {
          if (param_2 == 0x25) {
            *param_4 = '\a';
            *param_3 = '0';
            return 0;
          }
          return 6;
        }
        if (param_2 != 0x22) {
          if (param_2 == 0x23) {
            *param_4 = '\a';
            *param_3 = '#';
            return 0;
          }
          return 6;
        }
      }
_L0:
      *param_4 = '\a';
      *param_3 = ' ';
      return 0;
    }
    if (param_2 < 0x34) {
      if (param_2 < 0x32) {
        if (param_2 == 0x27) {
          *param_4 = '\x05';
          *param_3 = '\x19';
          return 0;
        }
        if (param_2 < 0x27) {
          return 6;
        }
        if (0x2b < param_2) {
          if (1 < (param_2 - 0x30 & 0xffff)) {
            return 6;
          }
          goto _L0;
        }
        if (param_2 < 0x28) {
          return 6;
        }
      }
_L0:
      *param_4 = '\a';
      *param_3 = '\x10';
      return 0;
    }
    if (param_2 != 0x34) {
      if (param_2 < 0x34) {
        return 6;
      }
      if ((param_2 - 0x40 & 0xffff) < 8) {
        *param_4 = '\a';
        *param_3 = '\x19';
        return 0;
      }
      return 6;
    }
  }
  *param_4 = '\x05';
  *param_3 = '0';
  return 0;
}

