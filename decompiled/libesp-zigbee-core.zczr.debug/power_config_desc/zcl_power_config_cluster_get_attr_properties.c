/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> power_config_desc.o -> zcl_power_config_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_power_config_cluster_get_attr_properties
                    (uint16_t cluster_role,uint16_t attr_id,uint8_t *type,uint8_t *access)

{
  undefined2 in_register_0000202a;
  undefined2 in_register_0000202e;
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  
  uVar1 = CONCAT22(in_register_0000202e,attr_id);
  if (type == (uint8_t *)0x0) {
    return 2;
  }
  if (access == (uint8_t *)0x0) {
    return 2;
  }
  if ((CONCAT22(in_register_0000202a,cluster_role) - 1U & 0xffff) < 2) {
    if (CONCAT22(in_register_0000202a,cluster_role) != 1) {
      return 6;
    }
  }
  else {
    pcVar3 = "cluster_role == 0x01U || cluster_role == 0x02U";
    pcVar2 = "zcl_power_config_cluster_get_attr_properties";
    uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/power_config_desc.c"
                          ,0x19);
    type = (uint8_t *)pcVar2;
    access = (uint8_t *)pcVar3;
  }
  if (uVar1 != 0x40) {
    if (uVar1 < 0x41) {
      if (uVar1 == 0x21) {
_L0:
        *access = '\x05';
        *type = ' ';
        return 0;
      }
      if (0x21 < uVar1) {
        if (uVar1 != 0x35) {
          if (uVar1 < 0x36) {
            if (uVar1 == 0x31) goto _L0;
            if (uVar1 < 0x32) {
              if (uVar1 != 0x30) {
                return 6;
              }
              goto _L0;
            }
            if (uVar1 == 0x32) goto _L0;
            if (uVar1 < 0x32) {
              return 6;
            }
            if (1 < (uVar1 - 0x33 & 0xffff)) {
              return 6;
            }
          }
          else {
            if (uVar1 == 0x3e) goto _L0;
            if (0x3e < uVar1) {
              return 6;
            }
            if (uVar1 != 0x36) {
              if (uVar1 < 0x36) {
                return 6;
              }
              if (6 < (uVar1 - 0x37 & 0xffff)) {
                return 6;
              }
              goto _L0;
            }
          }
          goto _L0;
        }
_L0:
        *access = '\x03';
        *type = '\x18';
        return 0;
      }
      if (uVar1 != 1) {
        if (uVar1 < 2) {
          if (uVar1 == 0) {
            *access = '\x01';
            *type = '!';
            return 0;
          }
          return 6;
        }
        if (uVar1 == 0x10) goto _L0;
        if (uVar1 < 0x10) {
          return 6;
        }
        if (uVar1 < 0x14) {
          if (uVar1 < 0x11) {
            return 6;
          }
          goto _L0;
        }
        if (uVar1 != 0x20) {
          return 6;
        }
      }
    }
    else if (uVar1 != 0x60) {
      if (uVar1 < 0x61) {
        if (uVar1 != 0x52) {
          if (0x52 < uVar1) {
            if (uVar1 != 0x56) {
              if (0x56 < uVar1) {
                if (0x5d < uVar1) {
                  if (uVar1 != 0x5e) {
                    return 6;
                  }
                  goto _L0;
                }
                if (uVar1 < 0x57) {
                  return 6;
                }
                goto _L0;
              }
              if (0x54 < uVar1) {
                if (uVar1 != 0x55) {
                  return 6;
                }
                goto _L0;
              }
              if (uVar1 < 0x53) {
                return 6;
              }
            }
            goto _L0;
          }
          if (uVar1 == 0x50) goto _L0;
          if (uVar1 != 0x51) {
            if (uVar1 != 0x41) {
              return 6;
            }
            goto _L0;
          }
          goto _L0;
        }
      }
      else if (uVar1 != 0x72) {
        if (0x72 < uVar1) {
          if (uVar1 != 0x76) {
            if (0x76 < uVar1) {
              if (0x7d < uVar1) {
                if (uVar1 != 0x7e) {
                  return 6;
                }
_L0:
                *access = '\x05';
                *type = '\x1b';
                return 0;
              }
              if (uVar1 < 0x77) {
                return 6;
              }
              goto _L0;
            }
            if (0x74 < uVar1) {
              if (uVar1 != 0x75) {
                return 6;
              }
              goto _L0;
            }
            if (uVar1 < 0x73) {
              return 6;
            }
          }
_L0:
          *access = '\x03';
          *type = ' ';
          return 0;
        }
        if (uVar1 == 0x70) {
_L0:
          *access = '\x03';
          *type = 'B';
          return 0;
        }
        if (uVar1 != 0x71) {
          if (uVar1 != 0x61) {
            return 6;
          }
          goto _L0;
        }
_L0:
        *access = '\x03';
        *type = '0';
        return 0;
      }
_L0:
      *access = '\x03';
      *type = '!';
      return 0;
    }
  }
_L0:
  *access = '\x01';
  *type = ' ';
  return 0;
}

