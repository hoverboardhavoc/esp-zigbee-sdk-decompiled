/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_get_attr_value_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t zcl_get_attr_value_size(zcl_attr_type_t attr_type,void *attr_value)

{
  uint16_t uVar1;
  short sVar2;
  undefined3 in_register_00002029;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  
  uVar3 = CONCAT31(in_register_00002029,attr_type);
  if (uVar3 == 0x38) {
    return 2;
  }
  if (uVar3 < 0x39) {
    if (uVar3 == 0x1d) {
      return 6;
    }
    if (uVar3 < 0x1e) {
      if (uVar3 == 0xc) {
        return 5;
      }
      if (uVar3 < 0xd) {
        if (uVar3 == 0) {
          return 0;
        }
        if (uVar3 == 10) {
          return 3;
        }
        if (uVar3 == 0xb) {
          return 4;
        }
        if (uVar3 == 8) {
          return 1;
        }
        uVar6 = 9;
        goto _L0;
      }
      if (uVar3 == 0x18) {
        return 1;
      }
      if (0x18 < uVar3) {
        if (uVar3 == 0x1b) {
          return 4;
        }
        if (uVar3 != 0x1c) {
          return (uVar3 != 0x19) + 2;
        }
        return 5;
      }
      if (uVar3 == 0xe) {
        return 7;
      }
      if (uVar3 < 0xf) {
        return 6;
      }
      if (uVar3 == 0xf) {
        return 8;
      }
      uVar6 = 0x10;
      uVar1 = 1;
    }
    else {
      if (uVar3 == 0x27) {
        return 8;
      }
      if (uVar3 < 0x28) {
        if (uVar3 == 0x22) {
          return 3;
        }
        if (0x22 < uVar3) {
          if (uVar3 == 0x25) {
            return 6;
          }
          if (uVar3 == 0x26) {
            return 7;
          }
          iVar4 = uVar3 - 0x23;
_L99:
          return (iVar4 != 0) + 4;
        }
        if (uVar3 == 0x1f) {
          return 8;
        }
        if (uVar3 < 0x20) {
          return 7;
        }
        iVar4 = uVar3 - 0x20;
_L97:
        return (iVar4 != 0) + 1;
      }
      if (uVar3 == 0x2d) {
        return 6;
      }
      if (uVar3 < 0x2e) {
        if (uVar3 == 0x2a) {
          return 3;
        }
        iVar4 = uVar3 - 0x2b;
        if (0x2a < uVar3) goto _L99;
        iVar4 = uVar3 - 0x28;
        goto _L97;
      }
      if (uVar3 == 0x2f) {
        return 8;
      }
      if (uVar3 < 0x30) {
        return 7;
      }
      if (uVar3 == 0x30) {
        return 1;
      }
      uVar6 = 0x31;
_L0:
      uVar1 = 2;
    }
_L0:
    if (uVar3 == uVar6) {
      return uVar1;
    }
  }
  else {
    if (uVar3 == 0x4a) {
      if (attr_value == (void *)0x0) {
        return 0xffff;
      }
                    /* WARNING: Load size is inaccurate */
      sVar2 = *attr_value;
      if (sVar2 == -1) {
        sVar2 = 2;
      }
      return sVar2 * 4 + 2;
    }
    if (uVar3 < 0x4b) {
      if (uVar3 < 0x45) {
        if (0x42 < uVar3) {
          if (attr_value == (void *)0x0) {
            return 0xffff;
          }
                    /* WARNING: Load size is inaccurate */
          if (*attr_value != -1) {
            return *attr_value + 2;
          }
          return 2;
        }
        if (0x40 < uVar3) {
          if (attr_value == (void *)0x0) {
            return 0xffff;
          }
                    /* WARNING: Load size is inaccurate */
          if (*attr_value != 0xff) {
            return *attr_value + 1;
          }
          return 1;
        }
        if (uVar3 == 0x39) {
          return 4;
        }
        uVar6 = 0x3a;
_L0:
        uVar1 = 8;
        goto _L0;
      }
      if (uVar3 == 0x48) {
_L0:
        pcVar5 = "Unsupported data type (0x%x)!";
        goto _L89;
      }
      if (uVar3 == 0x49) {
        if (attr_value == (void *)0x0) {
          return 0xffff;
        }
                    /* WARNING: Load size is inaccurate */
        sVar2 = *attr_value;
        if (sVar2 == -1) {
          sVar2 = 2;
        }
        return (sVar2 + 1) * 2;
      }
    }
    else {
      if (uVar3 == 0xf1) {
        return 0x10;
      }
      if (uVar3 < 0xf2) {
        if (uVar3 < 0x52) {
          if ((0x4f < uVar3) || (uVar3 == 0x4c)) goto _L0;
        }
        else {
          if (uVar3 == 0xea) {
            return 4;
          }
          if (0xea < uVar3) {
            uVar6 = 0xf0;
            goto _L0;
          }
          if (uVar3 < 0xe3) {
            if (0xdf < uVar3) {
              return 4;
            }
          }
          else if ((uVar3 + 0x18 & 0xff) < 2) {
            return 2;
          }
        }
      }
      else if (uVar3 == 0xfe) {
        if (attr_value == (void *)0x0) {
          return 0xffff;
        }
                    /* WARNING: Load size is inaccurate */
        return *attr_value;
      }
    }
  }
  pcVar5 = "Unknown data type (0x%x)";
_L89:
  log_write(2,"ZCL_COMMON",pcVar5);
  return 0xffff;
}

