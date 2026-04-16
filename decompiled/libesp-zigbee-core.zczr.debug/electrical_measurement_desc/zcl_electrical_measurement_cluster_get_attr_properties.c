/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> electrical_measurement_desc.o -> zcl_electrical_measurement_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_electrical_measurement_cluster_get_attr_properties
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
    pcVar1 = "zcl_electrical_measurement_cluster_get_attr_properties";
    uVar3 = __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/electrical_measurement_desc.c"
                          ,0x19);
    type = (uint8_t *)pcVar1;
    access = (uint8_t *)pcVar2;
  }
  if (0x517 < uVar3) {
    if (uVar3 < 0x80b) {
      if (0x806 < uVar3) {
        *access = '\x03';
        *type = ')';
        return 0;
      }
      if (uVar3 < 0x703) {
        if (uVar3 < 0x701) {
          if (0x605 < uVar3) {
            if (uVar3 == 0x700) {
              *access = '\x03';
              *type = '\x18';
              return 0;
            }
            return 6;
          }
          if (uVar3 < 0x600) {
            return 6;
          }
          goto _L0;
        }
      }
      else {
        if (uVar3 == 0x800) {
          *access = '\x03';
          *type = '\x19';
          return 0;
        }
        if (uVar3 < 0x800) {
          return 6;
        }
        if (5 < (uVar3 - 0x801 & 0xffff)) {
          return 6;
        }
      }
_L0:
      *access = '\x01';
      *type = ')';
      return 0;
    }
    if (uVar3 == 0xa01) goto _L0;
    if (uVar3 < 0xa02) {
      if (uVar3 != 0x90e) {
        if (uVar3 < 0x90f) {
          if (uVar3 != 0x908) {
            if (0x908 < uVar3) {
              if (uVar3 == 0x90b) goto _L0;
              if (0x90b < uVar3) {
                if (1 < (uVar3 - 0x90c & 0xffff)) {
                  return 6;
                }
                goto _L0;
              }
              if (1 < (uVar3 - 0x909 & 0xffff)) {
                return 6;
              }
              goto _L0;
            }
            if (uVar3 != 0x905) {
              if (0x905 < uVar3) {
                if (1 < (uVar3 - 0x906 & 0xffff)) {
                  return 6;
                }
                goto _L0;
              }
              if (uVar3 != 0x901) {
                if (uVar3 < 0x901) {
                  return 6;
                }
                if (1 < (uVar3 - 0x902 & 0xffff)) {
                  return 6;
                }
                goto _L0;
              }
            }
          }
        }
        else {
          if (uVar3 == 0x910) {
_L0:
            *access = '\x01';
            *type = '(';
            return 0;
          }
          if (0x910 < uVar3) {
            if (6 < (uVar3 - 0x911 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          if (uVar3 != 0x90f) {
            return 6;
          }
        }
        goto _L0;
      }
    }
    else if (uVar3 != 0xa0e) {
      if (0xa0e < uVar3) {
        if (uVar3 == 0xa10) goto _L0;
        if (0xa10 < uVar3) {
          if (6 < (uVar3 - 0xa11 & 0xffff)) {
            return 6;
          }
          goto _L0;
        }
        if (uVar3 != 0xa0f) {
          return 6;
        }
        goto _L0;
      }
      if (uVar3 < 0xa0b) {
        if (0xa08 < uVar3) goto _L0;
        if (uVar3 < 0xa08) {
          if (0xa05 < uVar3) goto _L0;
          if (uVar3 < 0xa04) {
            if (uVar3 < 0xa02) {
              return 6;
            }
            goto _L0;
          }
          if (uVar3 != 0xa05) {
            return 6;
          }
        }
        else if (uVar3 != 0xa08) {
          return 6;
        }
        goto _L0;
      }
      if (uVar3 != 0xa0b) {
        if (uVar3 < 0xa0b) {
          return 6;
        }
        if (1 < (uVar3 - 0xa0c & 0xffff)) {
          return 6;
        }
        goto _L0;
      }
    }
    goto _L0;
  }
  if (0x510 < uVar3) {
_L0:
    *access = '\x03';
    *type = '!';
    return 0;
  }
  if (uVar3 == 0x306) {
_L0:
    *access = '\x05';
    *type = '#';
    return 0;
  }
  if (uVar3 < 0x307) {
    if (0x108 < uVar3) {
      if (0x305 < uVar3) {
        return 6;
      }
      if (0x303 < uVar3) {
        *access = '\x05';
        *type = '+';
        return 0;
      }
      if (uVar3 < 0x303) {
        if (0x300 < uVar3) goto _L0;
        if (uVar3 < 0x206) {
          if (uVar3 < 0x200) {
            return 6;
          }
        }
        else if (uVar3 != 0x300) {
          return 6;
        }
      }
      else if (uVar3 != 0x303) {
        return 6;
      }
      goto _L0;
    }
    if (uVar3 < 0x100) {
      if (uVar3 == 0) {
        *access = '\x01';
        *type = '\x1b';
        return 0;
      }
      return 6;
    }
    uVar3 = 1 << (uVar3 - 0x100 & 0x1f);
    if ((uVar3 & 0x1b6) != 0) goto _L0;
    if ((uVar3 & 0x49) == 0) {
      return 6;
    }
  }
  else if (uVar3 < 0x406) {
    if (0x403 < uVar3) {
      *access = '\x05';
      *type = '(';
      return 0;
    }
    if (0x403 < uVar3) {
      return 6;
    }
    if (0x401 < uVar3) goto _L0;
    if (0x312 < uVar3) {
      if (1 < (uVar3 - 0x400 & 0xffff)) {
        return 6;
      }
      goto _L0;
    }
    if (uVar3 < 0x307) {
      return 6;
    }
  }
  else if (uVar3 != 0x50b) {
    if (uVar3 < 0x50c) {
      if (uVar3 < 0x508) {
        if (0x505 < uVar3) {
_L0:
          *access = '\x01';
          *type = '!';
          return 0;
        }
        if (uVar3 < 0x504) {
          if (0x501 < uVar3) goto _L0;
          if (uVar3 != 0x501) {
            return 6;
          }
        }
        else if (uVar3 != 0x505) {
          return 6;
        }
      }
      else if (uVar3 != 0x508) {
        if (uVar3 < 0x508) {
          return 6;
        }
        if (1 < (uVar3 - 0x509 & 0xffff)) {
          return 6;
        }
        goto _L0;
      }
_L0:
      *access = '\x05';
      *type = '!';
      return 0;
    }
    if (uVar3 == 0x510) goto _L0;
    if (0x510 < uVar3) {
      return 6;
    }
    if (uVar3 != 0x50e) {
      if (uVar3 < 0x50f) {
        if (1 < (uVar3 - 0x50c & 0xffff)) {
          return 6;
        }
        goto _L0;
      }
      if (uVar3 != 0x50f) {
        return 6;
      }
      goto _L0;
    }
  }
_L0:
  *access = '\x05';
  *type = ')';
  return 0;
}

