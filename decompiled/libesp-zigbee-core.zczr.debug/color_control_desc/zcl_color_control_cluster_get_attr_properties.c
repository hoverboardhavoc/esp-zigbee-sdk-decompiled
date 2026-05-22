/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> color_control_desc.o -> zcl_color_control_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_color_control_cluster_get_attr_properties
                    (uint16_t cluster_role,uint16_t attr_id,uint8_t *type,uint8_t *access)

{
  undefined2 in_register_0000202a;
  undefined2 in_register_0000202e;
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = CONCAT22(in_register_0000202e,attr_id);
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
    pcVar2 = "cluster_role == 0x01U || cluster_role == 0x02U";
    pcVar1 = "zcl_color_control_cluster_get_attr_properties";
    uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control_desc.c"
                          ,0x19);
    type = (uint8_t *)pcVar1;
    access = (uint8_t *)pcVar2;
  }
  if (uVar3 < 0x2a) {
    if (uVar3 < 0xf) {
      if (4 < uVar3) {
        if (uVar3 == 6) {
          *access = '\x01';
          *type = 'B';
          return 0;
        }
        if (uVar3 < 7) {
          if (uVar3 != 5) {
            return 6;
          }
        }
        else {
          if (uVar3 == 7) goto _L0;
          if (uVar3 != 8) {
            return 6;
          }
        }
_L0:
        *access = '\x01';
        *type = '0';
        return 0;
      }
      if (2 < uVar3) {
_L0:
        *access = '\x15';
        *type = '!';
        return 0;
      }
      if (uVar3 == 1) {
        *access = '\x15';
        *type = ' ';
        return 0;
      }
      if (uVar3 != 2) {
        if (uVar3 == 0) {
          *access = '\x05';
          *type = ' ';
          return 0;
        }
        return 6;
      }
    }
    else {
      uVar3 = 1 << (uVar3 - 0xf & 0x1f);
      if ((uVar3 & 0x6660ccc) == 0) {
        if ((uVar3 & 0x881112) == 0) {
          if ((uVar3 & 1) == 0) {
            return 6;
          }
          *access = '\x03';
          *type = '\x18';
          return 0;
        }
_L0:
        *access = '\x01';
        *type = ' ';
        return 0;
      }
    }
  }
  else {
    if (uVar3 < 0x4004) {
      if (0x4001 < uVar3) {
        *access = '\x11';
        *type = ' ';
        return 0;
      }
      if (0x3c < uVar3) {
        if (uVar3 != 0x4000) {
          if (uVar3 != 0x4001) {
            return 6;
          }
          goto _L0;
        }
_L0:
        *access = '\x11';
        *type = '!';
        return 0;
      }
      if (uVar3 < 0x2a) {
        return 6;
      }
      uVar3 = 1 << (uVar3 - 0x2a & 0x1f);
      if ((uVar3 & 0x333c0) == 0) {
        if ((uVar3 >> 10 & 0x111) != 0) {
          *access = '\x03';
          *type = ' ';
          return 0;
        }
        if ((uVar3 & 1) == 0) {
          return 6;
        }
        goto _L0;
      }
_L0:
      *access = '\x03';
      *type = '!';
      return 0;
    }
    if (uVar3 == 0x400a) {
      *access = '\x01';
      *type = '\x19';
      return 0;
    }
    if (uVar3 < 0x400b) {
      if (uVar3 == 0x4004) goto _L0;
      if (uVar3 < 0x4004) {
        return 6;
      }
      if (1 < (uVar3 - 0x4005 & 0xffff)) {
        return 6;
      }
    }
    else {
      if (uVar3 == 0xeff0) {
        *access = '@';
        *type = '\0';
        return 0;
      }
      if (0xeff0 < uVar3) {
        return 6;
      }
      if (0x400d < uVar3) {
        if (uVar3 != 0x4010) {
          return 6;
        }
        goto _L0;
      }
      if (uVar3 < 0x400b) {
        return 6;
      }
    }
  }
  *access = '\x01';
  *type = '!';
  return 0;
}

