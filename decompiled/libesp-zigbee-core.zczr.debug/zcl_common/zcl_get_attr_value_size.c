/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_get_attr_value_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_get_attr_value_size(uint param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  
  if (param_1 == 0x3a) {
    return 8;
  }
  if (param_1 < 0x3b) {
    if (param_1 == 0x1e) {
      return 7;
    }
    if (param_1 < 0x1f) {
      if (param_1 == 0xd) {
        return 6;
      }
      if (param_1 < 0xe) {
        if (param_1 == 0) {
          return 0;
        }
        if (param_1 == 10) {
          return 3;
        }
        if (param_1 < 0xb) {
          if (param_1 == 8) {
            return 1;
          }
          if (param_1 == 9) {
            return 2;
          }
        }
        else {
          if (param_1 == 0xb) {
            return 4;
          }
          if (param_1 == 0xc) {
            return 5;
          }
        }
      }
      else {
        if (param_1 == 0x19) {
          return 2;
        }
        if (param_1 < 0x1a) {
          if (param_1 == 0xf) {
            return 8;
          }
          if (param_1 < 0x10) {
            if (param_1 == 0xe) {
              return 7;
            }
          }
          else {
            if (param_1 == 0x10) {
              return 1;
            }
            if (param_1 == 0x18) {
              return 1;
            }
          }
        }
        else {
          if (param_1 == 0x1c) {
            return 5;
          }
          if (param_1 < 0x1d) {
            if (param_1 == 0x1a) {
              return 3;
            }
            if (param_1 == 0x1b) {
              return 4;
            }
          }
          else if (param_1 == 0x1d) {
            return 6;
          }
        }
      }
    }
    else {
      if (param_1 == 0x29) {
        return 2;
      }
      if (param_1 < 0x2a) {
        if (param_1 == 0x24) {
          return 5;
        }
        if (param_1 < 0x25) {
          if (param_1 == 0x21) {
            return 2;
          }
          if (param_1 < 0x22) {
            if (param_1 == 0x1f) {
              return 8;
            }
            if (param_1 == 0x20) {
              return 1;
            }
          }
          else {
            if (param_1 == 0x22) {
              return 3;
            }
            if (param_1 == 0x23) {
              return 4;
            }
          }
        }
        else {
          if (param_1 == 0x26) {
            return 7;
          }
          if (param_1 < 0x27) {
            if (param_1 == 0x25) {
              return 6;
            }
          }
          else {
            if (param_1 == 0x27) {
              return 8;
            }
            if (param_1 == 0x28) {
              return 1;
            }
          }
        }
      }
      else {
        if (param_1 == 0x2e) {
          return 7;
        }
        if (param_1 < 0x2f) {
          if (param_1 == 0x2c) {
            return 5;
          }
          if (param_1 < 0x2d) {
            if (param_1 == 0x2a) {
              return 3;
            }
            if (param_1 == 0x2b) {
              return 4;
            }
          }
          else if (param_1 == 0x2d) {
            return 6;
          }
        }
        else {
          if (param_1 == 0x31) {
            return 2;
          }
          if (param_1 < 0x32) {
            if (param_1 == 0x2f) {
              return 8;
            }
            if (param_1 == 0x30) {
              return 1;
            }
          }
          else {
            if (param_1 == 0x38) {
              return 2;
            }
            if (param_1 == 0x39) {
              return 4;
            }
          }
        }
      }
    }
  }
  else {
    if (param_1 == 0x4a) {
      if (param_2 != (ushort *)0x0) {
        uVar2 = (uint)*param_2;
        if (uVar2 == 0xffff) {
          uVar2 = 2;
        }
        return ((uVar2 << 0x12) >> 0x10) + 2 & 0xffff;
      }
      return 0xffff;
    }
    if (param_1 < 0x4b) {
      if (param_1 < 0x45) {
        if (0x42 < param_1) {
          if (param_2 == (ushort *)0x0) {
            return 0xffff;
          }
          if (*param_2 != 0xffff) {
            return (uint)(ushort)(*param_2 + 2);
          }
          return 2;
        }
        if ((param_1 - 0x41 & 0xff) < 2) {
          if (param_2 == (ushort *)0x0) {
            return 0xffff;
          }
          if ((byte)*param_2 != 0xff) {
            return (byte)*param_2 + 1;
          }
          return 1;
        }
      }
      else {
        if (param_1 == 0x48) {
_L0:
          log_write(2,"ZCL_COMMON","Unsupported data type (0x%x)!",param_1);
          return 0xffff;
        }
        if (param_1 == 0x49) {
          if (param_2 != (ushort *)0x0) {
            uVar1 = *param_2;
            if (uVar1 == 0xffff) {
              uVar1 = 2;
            }
            return (uint)(ushort)((uVar1 + 1) * 2);
          }
          return 0xffff;
        }
      }
    }
    else {
      if (param_1 == 0xf0) {
        return 8;
      }
      if (param_1 < 0xf1) {
        if (param_1 < 0x52) {
          if ((0x4f < param_1) || (param_1 == 0x4c)) goto _L0;
        }
        else if (param_1 < 0xea) {
          if (0xe7 < param_1) {
            return 2;
          }
          if ((param_1 + 0x20 & 0xff) < 3) {
            return 4;
          }
        }
        else if (param_1 == 0xea) {
          return 4;
        }
      }
      else {
        if (param_1 == 0xf1) {
          return 0x10;
        }
        if (param_1 == 0xfe) {
          if (param_2 != (ushort *)0x0) {
            return (uint)*param_2;
          }
          return 0xffff;
        }
      }
    }
  }
  log_write(2,"ZCL_COMMON","Unknown data type (0x%x)",param_1);
  return 0xffff;
}

