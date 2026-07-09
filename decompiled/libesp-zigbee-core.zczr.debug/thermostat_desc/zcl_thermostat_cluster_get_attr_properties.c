/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat_desc.o -> zcl_thermostat_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_thermostat_cluster_get_attr_properties(int param_1,uint param_2,char *param_3,char *param_4)

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
    param_3 = "zcl_thermostat_cluster_get_attr_properties";
    param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/thermostat_desc.c"
                            ,0x19);
  }
  if (param_2 == 0x20) {
_L0:
    *param_4 = '\x01';
    *param_3 = '0';
    return 0;
  }
  if (param_2 < 0x21) {
    if (param_2 < 0x13) {
      if (0x10 < param_2) {
        *param_4 = '\x13';
        *param_3 = ')';
        return 0;
      }
      if (param_2 < 9) {
        if (6 < param_2) {
          *param_4 = '\x05';
          *param_3 = ' ';
          return 0;
        }
        if (param_2 == 0) {
          *param_4 = '\x05';
          *param_3 = ')';
          return 0;
        }
        if (param_2 != 2) {
          if (param_2 < 3) {
            if (param_2 != 1) {
              return 6;
            }
          }
          else if (3 < (param_2 - 3 & 0xffff)) {
            return 6;
          }
          goto _L0;
        }
      }
      else if (param_2 != 9) {
        if (param_2 == 0x10) {
          *param_4 = '\x03';
          *param_3 = '(';
          return 0;
        }
        return 6;
      }
    }
    else {
      if (param_2 == 0x1a) {
        *param_4 = '\x03';
        *param_3 = '\x18';
        return 0;
      }
      if (param_2 < 0x1b) {
        if (param_2 < 0x19) {
          if (0x12 < param_2) {
            *param_4 = '\x03';
            *param_3 = ')';
            return 0;
          }
          return 6;
        }
        if (param_2 == 0x19) {
          *param_4 = '\x01';
          *param_3 = '(';
          return 0;
        }
        return 6;
      }
      if (param_2 == 0x1c) {
        *param_4 = '\x13';
        *param_3 = '0';
        return 0;
      }
      if (param_2 < 0x1d) {
        if (param_2 != 0x1b) {
          return 6;
        }
        goto _L0;
      }
      if (param_2 != 0x1d) {
        if (param_2 != 0x1e) {
          return 6;
        }
        goto _L0;
      }
    }
    *param_4 = '\x01';
    *param_3 = '\x18';
    return 0;
  }
  if (param_2 != 0x34) {
    if (param_2 < 0x35) {
      if (param_2 == 0x29) {
        *param_4 = '\x01';
        *param_3 = '\x19';
        return 0;
      }
      if (0x29 < param_2) {
        if (param_2 == 0x32) {
          *param_4 = '\x01';
          *param_3 = -0x1e;
          return 0;
        }
        if (0x32 < param_2) {
          return 6;
        }
        if (param_2 == 0x30) goto _L0;
        if (param_2 != 0x31) {
          return 6;
        }
_L0:
        *param_4 = '\x01';
        *param_3 = ')';
        return 0;
      }
      if (param_2 == 0x25) {
        *param_4 = '\a';
        *param_3 = '\x18';
        return 0;
      }
      if (0x25 < param_2) {
        return 6;
      }
      if (param_2 == 0x24) {
_L0:
        *param_4 = '\x03';
        *param_3 = '!';
        return 0;
      }
      if (0x24 < param_2) {
        return 6;
      }
      if (param_2 < 0x23) {
        if (param_2 < 0x21) {
          return 6;
        }
_L0:
        *param_4 = '\x01';
        *param_3 = ' ';
        return 0;
      }
      if (param_2 != 0x23) {
        return 6;
      }
    }
    else {
      if (param_2 == 0x44) {
        *param_4 = '\x03';
        *param_3 = '\x1b';
        return 0;
      }
      if (param_2 < 0x45) {
        if (param_2 != 0x3a) {
          if (0x3a < param_2) {
            if (param_2 == 0x41) goto _L0;
            if (param_2 < 0x42) {
              if (param_2 != 0x40) {
                return 6;
              }
            }
            else if (1 < (param_2 - 0x42 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          if (param_2 != 0x37) {
            if (param_2 < 0x38) {
              if (1 < (param_2 - 0x35 & 0xffff)) {
                return 6;
              }
            }
            else if (1 < (param_2 - 0x38 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
        }
        goto _L0;
      }
      if (param_2 == 0xeff0) {
        *param_4 = '@';
        *param_3 = '\0';
        return 0;
      }
      if (0xeff0 < param_2) {
        return 6;
      }
      if (param_2 == 0x46) goto _L0;
      if ((param_2 != 0x47) && (param_2 != 0x45)) {
        return 6;
      }
    }
_L0:
    *param_4 = '\x03';
    *param_3 = '0';
    return 0;
  }
_L0:
  *param_4 = '\x03';
  *param_3 = ' ';
  return 0;
}

