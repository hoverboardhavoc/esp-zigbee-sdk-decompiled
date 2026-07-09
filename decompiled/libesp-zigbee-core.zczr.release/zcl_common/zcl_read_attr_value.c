/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_read_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_read_attr_value(uint *param_1,uint *param_2,uint param_3)

{
  char *pcVar1;
  size_t sVar2;
  uint uVar3;
  uint uVar4;
  uint uStack_18;
  uint uStack_14;
  
  if (param_1 == (uint *)0x0) {
    return 0;
  }
  if (param_2 == (uint *)0x0) {
    return 0;
  }
  if (param_3 == 0x2c) {
    uStack_18 = 0;
    uStack_14 = 0;
    memcpy(&uStack_18,param_2,5);
    uVar3 = param_2[1];
    *param_1 = uStack_18;
    uVar3 = (~(int)(char)uVar3 >> 0x1f & 0x100U) - 0x100;
_L0:
    uStack_14 = uVar3 | uStack_14;
    goto _L0;
  }
  if (param_3 < 0x2d) {
    if (param_3 == 0x21) {
_L0:
      *(short *)param_1 = (short)*param_2;
      return 1;
    }
    if (0x21 < param_3) {
      if (param_3 == 0x29) goto _L0;
      if (param_3 < 0x2a) {
        if (param_3 == 0x26) goto _L0;
        if (0x26 < param_3) {
          uVar3 = 0x27;
_L267:
          if (param_3 != uVar3) {
_L0:
            *(char *)param_1 = (char)*param_2;
            return 1;
          }
          goto _L0;
        }
        if (param_3 == 0x24) goto _L0;
        if (param_3 == 0x25) goto _L0;
        if (param_3 == 0x22) goto _L0;
      }
      else if (param_3 == 0x2a) {
        uStack_18 = 0;
        memcpy(&uStack_18,param_2,3);
        uVar3 = 0;
        if (*(char *)((int)param_2 + 2) < '\0') {
          uVar3 = 0xff000000;
        }
        uStack_18 = uVar3 | uStack_18;
        goto _L0;
      }
_L0:
      uStack_18 = *param_2;
      goto _L0;
    }
    if (param_3 != 0xf) {
      if (param_3 < 0x10) {
        if (param_3 == 10) {
_L0:
          uStack_18 = 0;
          memcpy(&uStack_18,param_2,3);
_L0:
          *param_1 = uStack_18;
          return 1;
        }
        if (param_3 < 0xb) {
          if (param_3 == 0) {
            return 1;
          }
          if (param_3 == 8) goto _L0;
          if (param_3 == 9) goto _L0;
          goto _L0;
        }
        if (param_3 == 0xd) {
_L0:
          sVar2 = 6;
          goto _L0;
        }
        if (param_3 == 0xe) goto _L0;
        if (param_3 == 0xb) goto _L0;
_L0:
        sVar2 = 5;
      }
      else {
        if (param_3 == 0x1c) goto _L0;
        if (param_3 < 0x1d) {
          if (param_3 != 0x1a) {
            if (param_3 != 0x1b) {
              if (param_3 == 0x18) goto _L0;
              if (param_3 == 0x19) goto _L0;
              uVar3 = 0x10;
              goto _L264;
            }
            goto _L0;
          }
          goto _L0;
        }
        if (param_3 != 0x1e) {
          if (0x1e < param_3) {
            uVar3 = 0x1f;
            goto _L267;
          }
          goto _L0;
        }
_L0:
        sVar2 = 7;
      }
_L0:
      uStack_14 = 0;
      uStack_18 = 0;
      goto _L0;
    }
_L0:
    uStack_18 = *param_2;
    uStack_14 = param_2[1];
  }
  else {
    if (0x44 < param_3) {
      if (param_3 < 0xe3) {
        if (param_3 < 0xe0) {
          if (param_3 == 0x4a) {
            uVar3 = zcl_get_attr_value_size();
            *(short *)param_1 = (short)*param_2;
            uVar4 = 2;
            if (uVar3 != 0xffff) {
              for (; (uVar4 & 0xffff) < uVar3; uVar4 = uVar4 + 4) {
                *(undefined4 *)((int)param_1 + uVar4) = *(undefined4 *)((int)param_2 + uVar4);
              }
              return 1;
            }
            return 0;
          }
          if (param_3 < 0x4b) {
            if (param_3 == 0x48) {
_L0:
              pcVar1 = "Unsupported data type (0x%x)!";
              goto _L0;
            }
            if (param_3 == 0x49) {
              uVar3 = zcl_get_attr_value_size();
              uVar4 = 0;
              if (uVar3 != 0xffff) {
                for (; (uVar4 & 0xffff) < uVar3; uVar4 = uVar4 + 2) {
                  *(undefined2 *)((int)param_1 + uVar4) = *(undefined2 *)((int)param_2 + uVar4);
                }
                return 1;
              }
              return 0;
            }
          }
          else if ((param_3 == 0x4c) || ((param_3 - 0x50 & 0xff) < 2)) goto _L0;
          goto _L0;
        }
      }
      else if (param_3 != 0xf0) {
        if (param_3 < 0xf1) {
          if (param_3 < 0xea) {
            if (0xe7 < param_3) goto _L0;
          }
          else if (param_3 == 0xea) goto _L0;
        }
        else if (param_3 == 0xf1) goto _L0;
        goto _L0;
      }
_L0:
      sVar2 = zcl_get_attr_value_size(param_2);
_L0:
      memcpy(param_1,param_2,sVar2);
      return 1;
    }
    if (0x40 < param_3) {
      sVar2 = zcl_get_attr_value_size();
      if (sVar2 == 0xffff) {
        return 0;
      }
      goto _L0;
    }
    if (param_3 == 0x2f) goto _L0;
    if (param_3 < 0x30) {
      if (param_3 == 0x2d) {
        uStack_18 = 0;
        uStack_14 = 0;
        memcpy(&uStack_18,param_2,6);
        uVar3 = 0;
        if (*(char *)((int)param_2 + 5) < '\0') {
          uVar3 = 0xffff0000;
        }
      }
      else {
        uStack_18 = 0;
        uStack_14 = 0;
        memcpy(&uStack_18,param_2,7);
        uVar3 = 0;
        if (*(char *)((int)param_2 + 6) < '\0') {
          uVar3 = 0xff000000;
        }
      }
      *param_1 = uStack_18;
      goto _L0;
    }
    if (param_3 == 0x39) {
      memcpy(&uStack_18,param_2,4);
      *param_1 = uStack_18;
      return 1;
    }
    if (param_3 < 0x3a) {
      if ((param_3 == 0x31) || (param_3 == 0x38)) goto _L0;
      uVar3 = 0x30;
_L264:
      if (param_3 == uVar3) goto _L0;
_L0:
      pcVar1 = "Unknown data type (0x%x)!";
_L0:
      log_write(2,"ZCL_COMMON",pcVar1,param_3);
      return 0;
    }
    if (param_3 != 0x3a) goto _L0;
    sVar2 = 8;
_L0:
    memcpy(&uStack_18,param_2,sVar2);
  }
  *param_1 = uStack_18;
_L0:
  param_1[1] = uStack_14;
  return 1;
}

