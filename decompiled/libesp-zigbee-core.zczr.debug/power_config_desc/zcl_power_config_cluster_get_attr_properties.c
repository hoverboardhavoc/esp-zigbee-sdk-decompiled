/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> power_config_desc.o -> zcl_power_config_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_power_config_cluster_get_attr_properties(int param_1,uint param_2,char *param_3,char *param_4)

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
    param_3 = "zcl_power_config_cluster_get_attr_properties";
    param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/power_config_desc.c"
                            ,0x19);
  }
  if (param_2 != 0x40) {
    if (param_2 < 0x41) {
      if (param_2 == 0x21) {
_L0:
        *param_4 = '\x05';
        *param_3 = ' ';
        return 0;
      }
      if (0x21 < param_2) {
        if (param_2 != 0x35) {
          if (param_2 < 0x36) {
            if (param_2 == 0x31) goto _L0;
            if (param_2 < 0x32) {
              if (param_2 != 0x30) {
                return 6;
              }
              goto _L0;
            }
            if (param_2 == 0x32) goto _L0;
            if (param_2 < 0x32) {
              return 6;
            }
            if (1 < (param_2 - 0x33 & 0xffff)) {
              return 6;
            }
          }
          else {
            if (param_2 == 0x3e) goto _L0;
            if (0x3e < param_2) {
              return 6;
            }
            if (param_2 != 0x36) {
              if (param_2 < 0x36) {
                return 6;
              }
              if (6 < (param_2 - 0x37 & 0xffff)) {
                return 6;
              }
              goto _L0;
            }
          }
          goto _L0;
        }
_L0:
        *param_4 = '\x03';
        *param_3 = '\x18';
        return 0;
      }
      if (param_2 != 1) {
        if (param_2 < 2) {
          if (param_2 == 0) {
            *param_4 = '\x01';
            *param_3 = '!';
            return 0;
          }
          return 6;
        }
        if (param_2 == 0x10) goto _L0;
        if (param_2 < 0x10) {
          return 6;
        }
        if (param_2 < 0x14) {
          if (param_2 < 0x11) {
            return 6;
          }
          goto _L0;
        }
        if (param_2 != 0x20) {
          return 6;
        }
      }
    }
    else if (param_2 != 0x60) {
      if (param_2 < 0x61) {
        if (param_2 != 0x52) {
          if (0x52 < param_2) {
            if (param_2 != 0x56) {
              if (0x56 < param_2) {
                if (0x5d < param_2) {
                  if (param_2 != 0x5e) {
                    return 6;
                  }
                  goto _L0;
                }
                if (param_2 < 0x57) {
                  return 6;
                }
                goto _L0;
              }
              if (0x54 < param_2) {
                if (param_2 != 0x55) {
                  return 6;
                }
                goto _L0;
              }
              if (param_2 < 0x53) {
                return 6;
              }
            }
            goto _L0;
          }
          if (param_2 == 0x50) goto _L0;
          if (param_2 != 0x51) {
            if (param_2 != 0x41) {
              return 6;
            }
            goto _L0;
          }
          goto _L0;
        }
      }
      else if (param_2 != 0x72) {
        if (0x72 < param_2) {
          if (param_2 != 0x76) {
            if (0x76 < param_2) {
              if (0x7d < param_2) {
                if (param_2 != 0x7e) {
                  return 6;
                }
_L0:
                *param_4 = '\x05';
                *param_3 = '\x1b';
                return 0;
              }
              if (param_2 < 0x77) {
                return 6;
              }
              goto _L0;
            }
            if (0x74 < param_2) {
              if (param_2 != 0x75) {
                return 6;
              }
              goto _L0;
            }
            if (param_2 < 0x73) {
              return 6;
            }
          }
_L0:
          *param_4 = '\x03';
          *param_3 = ' ';
          return 0;
        }
        if (param_2 == 0x70) {
_L0:
          *param_4 = '\x03';
          *param_3 = 'B';
          return 0;
        }
        if (param_2 != 0x71) {
          if (param_2 != 0x61) {
            return 6;
          }
          goto _L0;
        }
_L0:
        *param_4 = '\x03';
        *param_3 = '0';
        return 0;
      }
_L0:
      *param_4 = '\x03';
      *param_3 = '!';
      return 0;
    }
  }
_L0:
  *param_4 = '\x01';
  *param_3 = ' ';
  return 0;
}

