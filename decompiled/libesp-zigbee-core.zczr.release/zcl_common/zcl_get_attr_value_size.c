/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_get_attr_value_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short zcl_get_attr_value_size(uint param_1,byte *param_2)

{
  short sVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  
  if (param_1 == 0x38) {
    return 2;
  }
  if (param_1 < 0x39) {
    if (param_1 == 0x1d) {
      return 6;
    }
    if (param_1 < 0x1e) {
      if (param_1 == 0xc) {
        return 5;
      }
      if (param_1 < 0xd) {
        if (param_1 == 0) {
          return 0;
        }
        if (param_1 == 10) {
          return 3;
        }
        if (param_1 == 0xb) {
          return 4;
        }
        if (param_1 == 8) {
          return 1;
        }
        uVar4 = 9;
        goto _L0;
      }
      if (param_1 == 0x18) {
        return 1;
      }
      if (0x18 < param_1) {
        if (param_1 == 0x1b) {
          return 4;
        }
        if (param_1 != 0x1c) {
          return (param_1 != 0x19) + 2;
        }
        return 5;
      }
      if (param_1 == 0xe) {
        return 7;
      }
      if (param_1 < 0xf) {
        return 6;
      }
      if (param_1 == 0xf) {
        return 8;
      }
      uVar4 = 0x10;
      sVar1 = 1;
    }
    else {
      if (param_1 == 0x27) {
        return 8;
      }
      if (param_1 < 0x28) {
        if (param_1 == 0x22) {
          return 3;
        }
        if (0x22 < param_1) {
          if (param_1 == 0x25) {
            return 6;
          }
          if (param_1 == 0x26) {
            return 7;
          }
          iVar2 = param_1 - 0x23;
_L99:
          return (iVar2 != 0) + 4;
        }
        if (param_1 == 0x1f) {
          return 8;
        }
        if (param_1 < 0x20) {
          return 7;
        }
        iVar2 = param_1 - 0x20;
_L97:
        return (iVar2 != 0) + 1;
      }
      if (param_1 == 0x2d) {
        return 6;
      }
      if (param_1 < 0x2e) {
        if (param_1 == 0x2a) {
          return 3;
        }
        iVar2 = param_1 - 0x2b;
        if (0x2a < param_1) goto _L99;
        iVar2 = param_1 - 0x28;
        goto _L97;
      }
      if (param_1 == 0x2f) {
        return 8;
      }
      if (param_1 < 0x30) {
        return 7;
      }
      if (param_1 == 0x30) {
        return 1;
      }
      uVar4 = 0x31;
_L0:
      sVar1 = 2;
    }
_L0:
    if (param_1 == uVar4) {
      return sVar1;
    }
  }
  else {
    if (param_1 == 0x4a) {
      if (param_2 == (byte *)0x0) {
        return -1;
      }
      sVar1 = *(short *)param_2;
      if (sVar1 == -1) {
        sVar1 = 2;
      }
      return sVar1 * 4 + 2;
    }
    if (param_1 < 0x4b) {
      if (param_1 < 0x45) {
        if (0x42 < param_1) {
          if (param_2 == (byte *)0x0) {
            return -1;
          }
          if (*(short *)param_2 != -1) {
            return *(short *)param_2 + 2;
          }
          return 2;
        }
        if (0x40 < param_1) {
          if (param_2 == (byte *)0x0) {
            return -1;
          }
          if (*param_2 != 0xff) {
            return *param_2 + 1;
          }
          return 1;
        }
        if (param_1 == 0x39) {
          return 4;
        }
        uVar4 = 0x3a;
_L0:
        sVar1 = 8;
        goto _L0;
      }
      if (param_1 == 0x48) {
_L0:
        pcVar3 = "Unsupported data type (0x%x)!";
        goto _L89;
      }
      if (param_1 == 0x49) {
        if (param_2 == (byte *)0x0) {
          return -1;
        }
        sVar1 = *(short *)param_2;
        if (sVar1 == -1) {
          sVar1 = 2;
        }
        return (sVar1 + 1) * 2;
      }
    }
    else {
      if (param_1 == 0xf1) {
        return 0x10;
      }
      if (param_1 < 0xf2) {
        if (param_1 < 0x52) {
          if ((0x4f < param_1) || (param_1 == 0x4c)) goto _L0;
        }
        else {
          if (param_1 == 0xea) {
            return 4;
          }
          if (0xea < param_1) {
            uVar4 = 0xf0;
            goto _L0;
          }
          if (param_1 < 0xe3) {
            if (0xdf < param_1) {
              return 4;
            }
          }
          else if ((param_1 + 0x18 & 0xff) < 2) {
            return 2;
          }
        }
      }
      else if (param_1 == 0xfe) {
        if (param_2 == (byte *)0x0) {
          return -1;
        }
        return *(short *)param_2;
      }
    }
  }
  pcVar3 = "Unknown data type (0x%x)";
_L89:
  log_write(2,"ZCL_COMMON",pcVar3);
  return -1;
}

