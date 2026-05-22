/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> door_lock_desc.o -> zcl_door_lock_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_door_lock_cluster_get_attr_properties
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
    pcVar2 = "zcl_door_lock_cluster_get_attr_properties";
    uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/door_lock_desc.c"
                          ,0x19);
    type = (uint8_t *)pcVar2;
    access = (uint8_t *)pcVar3;
  }
  if (uVar1 == 0x21) {
    *access = '\a';
    *type = 'B';
    return 0;
  }
  if (uVar1 < 0x22) {
    if (5 < uVar1) {
      if (uVar1 < 0x14) {
        if (0xf < uVar1) {
          *access = '\x01';
          *type = '!';
          return 0;
        }
        if (uVar1 == 6) {
          *access = '\x03';
          *type = '!';
          return 0;
        }
        return 6;
      }
      if (uVar1 < 0x1b) {
        if (0x13 < uVar1) {
          *access = '\x01';
          *type = ' ';
          return 0;
        }
        return 6;
      }
      if (uVar1 != 0x20) {
        return 6;
      }
      goto _L0;
    }
    if (3 < uVar1) {
      *access = '\x03';
      *type = '#';
      return 0;
    }
    if (uVar1 == 2) {
      *access = '\x01';
      *type = '\x10';
      return 0;
    }
    if (uVar1 < 3) {
      if (uVar1 != 0) {
        if (uVar1 == 1) {
          *access = '\x01';
          *type = '0';
          return 0;
        }
        return 6;
      }
    }
    else if (uVar1 != 3) {
      return 6;
    }
  }
  else {
    if (uVar1 == 0x26) {
      *access = '\x01';
      *type = '\x19';
      return 0;
    }
    if (uVar1 < 0x27) {
      if (uVar1 != 0x24) {
        if (0x24 < uVar1) {
          if (uVar1 == 0x25) {
            *access = '\a';
            *type = '0';
            return 0;
          }
          return 6;
        }
        if (uVar1 != 0x22) {
          if (uVar1 == 0x23) {
            *access = '\a';
            *type = '#';
            return 0;
          }
          return 6;
        }
      }
_L0:
      *access = '\a';
      *type = ' ';
      return 0;
    }
    if (uVar1 < 0x34) {
      if (uVar1 < 0x32) {
        if (uVar1 == 0x27) {
          *access = '\x05';
          *type = '\x19';
          return 0;
        }
        if (uVar1 < 0x27) {
          return 6;
        }
        if (0x2b < uVar1) {
          if (1 < (uVar1 - 0x30 & 0xffff)) {
            return 6;
          }
          goto _L0;
        }
        if (uVar1 < 0x28) {
          return 6;
        }
      }
_L0:
      *access = '\a';
      *type = '\x10';
      return 0;
    }
    if (uVar1 != 0x34) {
      if (uVar1 < 0x34) {
        return 6;
      }
      if ((uVar1 - 0x40 & 0xffff) < 8) {
        *access = '\a';
        *type = '\x19';
        return 0;
      }
      return 6;
    }
  }
  *access = '\x05';
  *type = '0';
  return 0;
}

