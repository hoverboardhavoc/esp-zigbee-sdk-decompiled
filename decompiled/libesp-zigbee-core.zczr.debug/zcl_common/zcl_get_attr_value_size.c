/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_get_attr_value_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t zcl_get_attr_value_size(zcl_attr_type_t attr_type,void *attr_value)

{
  undefined3 in_register_00002029;
  short sVar1;
  uint uVar2;
  
  uVar2 = CONCAT31(in_register_00002029,attr_type);
  if (uVar2 == 0x3a) {
    return 8;
  }
  if (uVar2 < 0x3b) {
    if (uVar2 == 0x1e) {
      return 7;
    }
    if (uVar2 < 0x1f) {
      if (uVar2 == 0xd) {
        return 6;
      }
      if (uVar2 < 0xe) {
        if (uVar2 == 0) {
          return 0;
        }
        if (uVar2 == 10) {
          return 3;
        }
        if (uVar2 < 0xb) {
          if (uVar2 == 8) {
            return 1;
          }
          if (uVar2 == 9) {
            return 2;
          }
        }
        else {
          if (uVar2 == 0xb) {
            return 4;
          }
          if (uVar2 == 0xc) {
            return 5;
          }
        }
      }
      else {
        if (uVar2 == 0x19) {
          return 2;
        }
        if (uVar2 < 0x1a) {
          if (uVar2 == 0xf) {
            return 8;
          }
          if (uVar2 < 0x10) {
            if (uVar2 == 0xe) {
              return 7;
            }
          }
          else {
            if (uVar2 == 0x10) {
              return 1;
            }
            if (uVar2 == 0x18) {
              return 1;
            }
          }
        }
        else {
          if (uVar2 == 0x1c) {
            return 5;
          }
          if (uVar2 < 0x1d) {
            if (uVar2 == 0x1a) {
              return 3;
            }
            if (uVar2 == 0x1b) {
              return 4;
            }
          }
          else if (uVar2 == 0x1d) {
            return 6;
          }
        }
      }
    }
    else {
      if (uVar2 == 0x29) {
        return 2;
      }
      if (uVar2 < 0x2a) {
        if (uVar2 == 0x24) {
          return 5;
        }
        if (uVar2 < 0x25) {
          if (uVar2 == 0x21) {
            return 2;
          }
          if (uVar2 < 0x22) {
            if (uVar2 == 0x1f) {
              return 8;
            }
            if (uVar2 == 0x20) {
              return 1;
            }
          }
          else {
            if (uVar2 == 0x22) {
              return 3;
            }
            if (uVar2 == 0x23) {
              return 4;
            }
          }
        }
        else {
          if (uVar2 == 0x26) {
            return 7;
          }
          if (uVar2 < 0x27) {
            if (uVar2 == 0x25) {
              return 6;
            }
          }
          else {
            if (uVar2 == 0x27) {
              return 8;
            }
            if (uVar2 == 0x28) {
              return 1;
            }
          }
        }
      }
      else {
        if (uVar2 == 0x2e) {
          return 7;
        }
        if (uVar2 < 0x2f) {
          if (uVar2 == 0x2c) {
            return 5;
          }
          if (uVar2 < 0x2d) {
            if (uVar2 == 0x2a) {
              return 3;
            }
            if (uVar2 == 0x2b) {
              return 4;
            }
          }
          else if (uVar2 == 0x2d) {
            return 6;
          }
        }
        else {
          if (uVar2 == 0x31) {
            return 2;
          }
          if (uVar2 < 0x32) {
            if (uVar2 == 0x2f) {
              return 8;
            }
            if (uVar2 == 0x30) {
              return 1;
            }
          }
          else {
            if (uVar2 == 0x38) {
              return 2;
            }
            if (uVar2 == 0x39) {
              return 4;
            }
          }
        }
      }
    }
  }
  else {
    if (uVar2 == 0x4a) {
      if (attr_value != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
        uVar2 = (uint)*attr_value;
        if (uVar2 == 0xffff) {
          uVar2 = 2;
        }
        return (short)((uVar2 << 0x12) >> 0x10) + 2;
      }
      return 0xffff;
    }
    if (uVar2 < 0x4b) {
      if (uVar2 < 0x45) {
        if (0x42 < uVar2) {
          if (attr_value == (void *)0x0) {
            return 0xffff;
          }
                    /* WARNING: Load size is inaccurate */
          if (*attr_value != -1) {
            return *attr_value + 2;
          }
          return 2;
        }
        if ((uVar2 - 0x41 & 0xff) < 2) {
          if (attr_value == (void *)0x0) {
            return 0xffff;
          }
                    /* WARNING: Load size is inaccurate */
          if (*attr_value != 0xff) {
            return *attr_value + 1;
          }
          return 1;
        }
      }
      else {
        if (uVar2 == 0x48) {
_L0:
          log_write(2,"ZCL_COMMON","Unsupported data type (0x%x)!",uVar2);
          return 0xffff;
        }
        if (uVar2 == 0x49) {
          if (attr_value != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
            sVar1 = *attr_value;
            if (sVar1 == -1) {
              sVar1 = 2;
            }
            return (sVar1 + 1) * 2;
          }
          return 0xffff;
        }
      }
    }
    else {
      if (uVar2 == 0xf0) {
        return 8;
      }
      if (uVar2 < 0xf1) {
        if (uVar2 < 0x52) {
          if ((0x4f < uVar2) || (uVar2 == 0x4c)) goto _L0;
        }
        else if (uVar2 < 0xea) {
          if (0xe7 < uVar2) {
            return 2;
          }
          if ((uVar2 + 0x20 & 0xff) < 3) {
            return 4;
          }
        }
        else if (uVar2 == 0xea) {
          return 4;
        }
      }
      else {
        if (uVar2 == 0xf1) {
          return 0x10;
        }
        if (uVar2 == 0xfe) {
          if (attr_value != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
            return *attr_value;
          }
          return 0xffff;
        }
      }
    }
  }
  log_write(2,"ZCL_COMMON","Unknown data type (0x%x)",uVar2);
  return 0xffff;
}

