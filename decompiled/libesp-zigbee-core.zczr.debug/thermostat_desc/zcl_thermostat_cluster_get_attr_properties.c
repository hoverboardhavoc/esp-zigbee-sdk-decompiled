/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat_desc.o -> zcl_thermostat_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_thermostat_cluster_get_attr_properties
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
    pcVar2 = "zcl_thermostat_cluster_get_attr_properties";
    uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/thermostat_desc.c"
                          ,0x19);
    type = (uint8_t *)pcVar2;
    access = (uint8_t *)pcVar3;
  }
  if (uVar1 == 0x20) {
_L0:
    *access = '\x01';
    *type = '0';
    return 0;
  }
  if (uVar1 < 0x21) {
    if (uVar1 < 0x13) {
      if (0x10 < uVar1) {
        *access = '\x13';
        *type = ')';
        return 0;
      }
      if (uVar1 < 9) {
        if (6 < uVar1) {
          *access = '\x05';
          *type = ' ';
          return 0;
        }
        if (uVar1 == 0) {
          *access = '\x05';
          *type = ')';
          return 0;
        }
        if (uVar1 != 2) {
          if (uVar1 < 3) {
            if (uVar1 != 1) {
              return 6;
            }
          }
          else if (3 < (uVar1 - 3 & 0xffff)) {
            return 6;
          }
          goto _L0;
        }
      }
      else if (uVar1 != 9) {
        if (uVar1 == 0x10) {
          *access = '\x03';
          *type = '(';
          return 0;
        }
        return 6;
      }
    }
    else {
      if (uVar1 == 0x1a) {
        *access = '\x03';
        *type = '\x18';
        return 0;
      }
      if (uVar1 < 0x1b) {
        if (uVar1 < 0x19) {
          if (0x12 < uVar1) {
            *access = '\x03';
            *type = ')';
            return 0;
          }
          return 6;
        }
        if (uVar1 == 0x19) {
          *access = '\x01';
          *type = '(';
          return 0;
        }
        return 6;
      }
      if (uVar1 == 0x1c) {
        *access = '\x13';
        *type = '0';
        return 0;
      }
      if (uVar1 < 0x1d) {
        if (uVar1 != 0x1b) {
          return 6;
        }
        goto _L0;
      }
      if (uVar1 != 0x1d) {
        if (uVar1 != 0x1e) {
          return 6;
        }
        goto _L0;
      }
    }
    *access = '\x01';
    *type = '\x18';
    return 0;
  }
  if (uVar1 != 0x34) {
    if (uVar1 < 0x35) {
      if (uVar1 == 0x29) {
        *access = '\x01';
        *type = '\x19';
        return 0;
      }
      if (0x29 < uVar1) {
        if (uVar1 == 0x32) {
          *access = '\x01';
          *type = 0xe2;
          return 0;
        }
        if (0x32 < uVar1) {
          return 6;
        }
        if (uVar1 == 0x30) goto _L0;
        if (uVar1 != 0x31) {
          return 6;
        }
_L0:
        *access = '\x01';
        *type = ')';
        return 0;
      }
      if (uVar1 == 0x25) {
        *access = '\a';
        *type = '\x18';
        return 0;
      }
      if (0x25 < uVar1) {
        return 6;
      }
      if (uVar1 == 0x24) {
_L0:
        *access = '\x03';
        *type = '!';
        return 0;
      }
      if (0x24 < uVar1) {
        return 6;
      }
      if (uVar1 < 0x23) {
        if (uVar1 < 0x21) {
          return 6;
        }
_L0:
        *access = '\x01';
        *type = ' ';
        return 0;
      }
      if (uVar1 != 0x23) {
        return 6;
      }
    }
    else {
      if (uVar1 == 0x44) {
        *access = '\x03';
        *type = '\x1b';
        return 0;
      }
      if (uVar1 < 0x45) {
        if (uVar1 != 0x3a) {
          if (0x3a < uVar1) {
            if (uVar1 == 0x41) goto _L0;
            if (uVar1 < 0x42) {
              if (uVar1 != 0x40) {
                return 6;
              }
            }
            else if (1 < (uVar1 - 0x42 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          if (uVar1 != 0x37) {
            if (uVar1 < 0x38) {
              if (1 < (uVar1 - 0x35 & 0xffff)) {
                return 6;
              }
            }
            else if (1 < (uVar1 - 0x38 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
        }
        goto _L0;
      }
      if (uVar1 == 0xeff0) {
        *access = '@';
        *type = '\0';
        return 0;
      }
      if (0xeff0 < uVar1) {
        return 6;
      }
      if (uVar1 == 0x46) goto _L0;
      if ((uVar1 != 0x47) && (uVar1 != 0x45)) {
        return 6;
      }
    }
_L0:
    *access = '\x03';
    *type = '0';
    return 0;
  }
_L0:
  *access = '\x03';
  *type = ' ';
  return 0;
}

