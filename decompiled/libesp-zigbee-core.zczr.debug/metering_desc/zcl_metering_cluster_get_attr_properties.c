/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> metering_desc.o -> zcl_metering_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_metering_cluster_get_attr_properties
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
      if (7 < uVar3) {
        return 6;
      }
      *access = '\x01';
      *type = '\x1b';
      return 0;
    }
  }
  else {
    pcVar2 = "cluster_role == 0x01U || cluster_role == 0x02U";
    pcVar1 = "zcl_metering_cluster_get_attr_properties";
    uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/metering_desc.c"
                          ,0x19);
    type = (uint8_t *)pcVar1;
    access = (uint8_t *)pcVar2;
  }
  if (uVar3 < 0x45c) {
    if (0x43f < uVar3) {
_L0:
      *access = '\x01';
      *type = '#';
      return 0;
    }
    if (uVar3 == 0x204) {
      *access = '\x01';
      *type = '\x1f';
      return 0;
    }
    if (0x204 < uVar3) {
      if (uVar3 < 0x315) {
        if (uVar3 < 0x303) {
          if (uVar3 == 0x206) {
_L0:
            *access = '\x01';
            *type = 'A';
            return 0;
          }
          if (uVar3 < 0x207) {
            if (uVar3 != 0x205) {
              return 6;
            }
            goto _L0;
          }
          if (uVar3 != 0x300) {
            if (0x300 < uVar3) {
              if (1 < (uVar3 - 0x301 & 0xffff)) {
                return 6;
              }
              goto _L0;
            }
            if (uVar3 != 0x207) {
              return 6;
            }
          }
        }
        else {
          uVar3 = 1 << (uVar3 - 0x303 & 0x1f);
          if ((uVar3 & 0x3058f) != 0) {
_L0:
            *access = '\x01';
            *type = '\x18';
            return 0;
          }
          if ((uVar3 >> 4 & 0x783) != 0) goto _L0;
          if ((uVar3 >> 6 & 0x209) == 0) {
            return 6;
          }
        }
        goto _L0;
      }
      if (uVar3 < 0x409) {
        if (uVar3 < 0x407) {
          if (uVar3 == 0x400) goto _L0;
          if (uVar3 < 0x400) {
            return 6;
          }
          if (0x404 < uVar3) {
            if (1 < (uVar3 - 0x405 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          if (uVar3 < 0x401) {
            return 6;
          }
        }
      }
      else {
        if (uVar3 < 0x417) {
          if (uVar3 < 0x40d) {
            if (3 < (uVar3 - 0x409 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
_L0:
          *access = '\x01';
          *type = '*';
          return 0;
        }
        if (uVar3 < 0x42e) {
          if (uVar3 < 0x420) {
            return 6;
          }
        }
        else if (0xb < (uVar3 - 0x430 & 0xffff)) {
          return 6;
        }
      }
_L0:
      *access = '\x01';
      *type = '\"';
      return 0;
    }
    if (uVar3 != 0xf) {
      if (uVar3 < 0x10) {
        if (uVar3 == 6) {
          *access = '\x01';
          *type = '(';
          return 0;
        }
        if (uVar3 < 7) {
          if (4 < uVar3) {
            if (uVar3 != 5) {
              return 6;
            }
            goto _L0;
          }
        }
        else {
          if (uVar3 < 0xc) {
            if (uVar3 < 10) {
              if (2 < (uVar3 - 7 & 0xffff)) {
                return 6;
              }
              goto _L0;
            }
            goto _L0;
          }
          if (uVar3 == 0xd) goto _L0;
          if (uVar3 == 0xe) goto _L0;
          if (uVar3 != 0xc) {
            return 6;
          }
        }
      }
      else if (uVar3 != 0x1f) {
        if (uVar3 < 0x20) {
          if (uVar3 < 0x17) {
            if (0x14 < uVar3) goto _L0;
            if (uVar3 == 0x13) goto _L0;
            if (uVar3 < 0x14) {
              if (1 < (uVar3 - 0x11 & 0xffff)) {
                return 6;
              }
              goto _L0;
            }
            if (uVar3 != 0x14) {
              return 6;
            }
          }
          else {
            if (uVar3 < 0x1c) {
              if (uVar3 < 0x17) {
                return 6;
              }
              goto _L0;
            }
            if (uVar3 < 0x1e) {
              if (uVar3 < 0x1c) {
                return 6;
              }
              goto _L0;
            }
            if (uVar3 != 0x1e) {
              return 6;
            }
          }
          goto _L0;
        }
        if (uVar3 != 0x1fe) {
          if (0x1fe < uVar3) {
            if (uVar3 != 0x201) {
              if (uVar3 < 0x202) {
                if (uVar3 != 0x200) {
                  return 6;
                }
                goto _L0;
              }
              if (1 < (uVar3 - 0x202 & 0xffff)) {
                return 6;
              }
              goto _L0;
            }
            goto _L0;
          }
          if (uVar3 == 0x22) goto _L0;
          if (uVar3 < 0x23) {
            if (1 < (uVar3 - 0x20 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          if (uVar3 < 0x160) {
            if (uVar3 < 0x100) {
              return 6;
            }
          }
          else if (uVar3 != 0x1fc) {
            return 6;
          }
        }
      }
    }
_L0:
    *access = '\x01';
    *type = '%';
    return 0;
  }
  if (uVar3 != 0x807) {
    if (uVar3 < 0x808) {
      if (uVar3 == 0x801) {
        *access = '\x03';
        *type = '\x1b';
        return 0;
      }
      if (0x801 < uVar3) {
        if (0x805 < uVar3) {
          if (uVar3 != 0x806) {
            return 6;
          }
          *access = '\x03';
          *type = '\x1d';
          return 0;
        }
        if (uVar3 < 0x802) {
          return 6;
        }
        goto _L0;
      }
      if (uVar3 != 0x605) {
        if (uVar3 < 0x606) {
          if (uVar3 < 0x602) {
            if (0x5ff < uVar3) goto _L0;
            if (uVar3 == 0x45c) goto _L0;
            if (uVar3 != 0x500) {
              return 6;
            }
          }
          else {
            if (0x603 < uVar3) {
              if (uVar3 != 0x604) {
                return 6;
              }
_L0:
              *access = '\x01';
              *type = '!';
              return 0;
            }
            if (uVar3 < 0x602) {
              return 6;
            }
          }
_L0:
          *access = '\x01';
          *type = ' ';
          return 0;
        }
        if (uVar3 == 0x800) goto _L0;
        if (0x800 < uVar3) {
          return 6;
        }
        if (0x609 < uVar3) {
          if (0xff < (uVar3 - 0x700 & 0xffff)) {
            return 6;
          }
          goto _L0;
        }
        if (uVar3 < 0x607) {
          if (uVar3 != 0x606) {
            return 6;
          }
          goto _L0;
        }
      }
    }
    else {
      if (0xb15 < uVar3) {
        if (uVar3 < 0xc0d) {
          if (0xc08 < uVar3) goto _L0;
          if (uVar3 < 0xc05) {
            if (uVar3 < 0xc01) {
              if (uVar3 != 0xc00) {
                return 6;
              }
              goto _L0;
            }
          }
          else {
            if (uVar3 < 0xc07) {
              if (uVar3 < 0xc05) {
                return 6;
              }
              goto _L0;
            }
            if (1 < (uVar3 - 0xc07 & 0xffff)) {
              return 6;
            }
          }
        }
        else if (uVar3 < 0xc2e) {
          if (uVar3 < 0xc20) {
            if (3 < (uVar3 - 0xc0d & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
        }
        else {
          if (0xc3b < uVar3) {
            if (0x1b < (uVar3 - 0xc40 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          if (uVar3 < 0xc30) {
            return 6;
          }
        }
        goto _L0;
      }
      if (uVar3 < 0xb01) {
        if (uVar3 < 0xa15) {
          if (uVar3 < 0xa00) {
            if (0xff < (uVar3 - 0x900 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          uVar3 = 1 << (uVar3 - 0xa00 & 0x1f);
          if ((uVar3 & 0x50005) != 0) goto _L0;
          if ((uVar3 & 0xa000a) == 0) {
            if ((uVar3 & 0x100010) == 0) {
              return 6;
            }
            goto _L0;
          }
        }
        else if (uVar3 != 0xb00) {
          return 6;
        }
_L0:
        *access = '\x01';
        *type = 0xe2;
        return 0;
      }
      uVar3 = 1 << (uVar3 - 0xb01 & 0x1f);
      if ((uVar3 >> 0xf & 0x2d) != 0) goto _L0;
      if ((uVar3 & 0x10001) == 0) {
        if (-1 < (int)(uVar3 << 0xc)) {
          return 6;
        }
        goto _L0;
      }
    }
_L0:
    *access = '\x01';
    *type = '0';
    return 0;
  }
_L0:
  *access = '\x03';
  *type = '\x19';
  return 0;
}

