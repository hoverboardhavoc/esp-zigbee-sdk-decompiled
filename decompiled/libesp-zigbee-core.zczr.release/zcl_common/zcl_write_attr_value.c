/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_write_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_write_attr_value(int *param_1,int *param_2,uint param_3)

{
  byte bVar1;
  char *pcVar2;
  size_t __n;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iStack_18;
  int iStack_14;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if (param_3 == 0x2c) {
    iVar4 = param_2[1];
    iStack_18 = *param_2;
    iStack_14 = iVar4;
    memcpy(param_1,&iStack_18,5);
    *(byte *)(param_1 + 1) = (byte)((uint)iVar4 >> 0x18) & 0x80 | (byte)iVar4;
    return 1;
  }
  if (param_3 < 0x2d) {
    if (param_3 == 0x21) {
_L0:
      *(short *)param_1 = (short)*param_2;
      return 1;
    }
    if (param_3 < 0x22) {
      if (param_3 == 0xf) goto _L0;
      if (param_3 < 0x10) {
        if (param_3 == 10) {
_L0:
          iStack_18 = *param_2;
          __n = 3;
          goto _L0;
        }
        if (param_3 < 0xb) {
          if (param_3 == 0) {
            return 1;
          }
          if (param_3 == 8) goto _L0;
          if (param_3 == 9) goto _L0;
          goto _L0;
        }
        if (param_3 == 0xd) goto _L0;
        if (param_3 == 0xe) goto _L0;
        if (param_3 == 0xb) goto _L0;
      }
      else if (param_3 != 0x1c) {
        if (0x1c < param_3) {
          if (param_3 == 0x1e) goto _L0;
          if (0x1e < param_3) {
            uVar3 = 0x1f;
            goto _L182;
          }
_L0:
          iStack_18 = *param_2;
          iStack_14 = param_2[1];
          __n = 6;
          goto _L0;
        }
        if (param_3 != 0x1a) {
          if (param_3 == 0x1b) {
_L0:
            *param_1 = *param_2;
            return 1;
          }
          if (param_3 == 0x18) goto _L0;
          if (param_3 == 0x19) goto _L0;
          uVar3 = 0x10;
          goto _L179;
        }
        goto _L0;
      }
_L0:
      iStack_18 = *param_2;
      iStack_14 = param_2[1];
      __n = 5;
    }
    else {
      if (param_3 == 0x29) goto _L0;
      if (0x29 < param_3) {
        iVar4 = *param_2;
        if (param_3 == 0x2a) {
          iStack_18 = iVar4;
          memcpy(param_1,&iStack_18,3);
          *(byte *)((int)param_1 + 2) =
               (byte)((uint)iVar4 >> 0x18) & 0x80 | *(byte *)((int)param_1 + 2);
          return 1;
        }
        *param_1 = iVar4;
        return 1;
      }
      if (param_3 != 0x26) {
        if (0x26 < param_3) {
          uVar3 = 0x27;
_L182:
          if (param_3 == uVar3) {
_L0:
            iVar4 = param_2[1];
            *param_1 = *param_2;
            param_1[1] = iVar4;
            return 1;
          }
_L0:
          *(char *)param_1 = (char)*param_2;
          return 1;
        }
        if (param_3 != 0x24) {
          if (param_3 == 0x25) goto _L0;
          if (param_3 != 0x22) goto _L0;
          goto _L0;
        }
        goto _L0;
      }
_L0:
      iStack_18 = *param_2;
      iStack_14 = param_2[1];
      __n = 7;
    }
_L0:
    param_2 = &iStack_18;
    goto _L0;
  }
  if (param_3 < 0x45) {
    if (0x40 < param_3) {
      __n = zcl_get_attr_value_size(param_3);
      if (__n == 0xffff) {
        return 0;
      }
      goto _L0;
    }
    if (param_3 == 0x2f) goto _L0;
    if (param_3 < 0x30) {
      iStack_18 = *param_2;
      iVar4 = param_2[1];
      bVar1 = (byte)((uint)iVar4 >> 0x18);
      iStack_14 = iVar4;
      if (param_3 == 0x2d) {
        memcpy(param_1,&iStack_18,6);
        *(byte *)((int)param_1 + 5) = bVar1 & 0x80 | (byte)((uint)iVar4 >> 8);
        return 1;
      }
      memcpy(param_1,&iStack_18,7);
      *(byte *)((int)param_1 + 6) = bVar1 & 0x80 | (byte)((uint)iVar4 >> 0x10);
      return 1;
    }
    if (param_3 == 0x39) {
      iStack_18 = *param_2;
      __n = 4;
      param_2 = &iStack_18;
      goto _L0;
    }
    if (param_3 < 0x3a) {
      if ((param_3 == 0x31) || (param_3 == 0x38)) goto _L0;
      uVar3 = 0x30;
_L179:
      if (param_3 == uVar3) goto _L0;
    }
    else if (param_3 == 0x3a) {
      iStack_18 = *param_2;
      iStack_14 = param_2[1];
      __n = 8;
      param_2 = &iStack_18;
      goto _L0;
    }
    goto _L0;
  }
  if (param_3 < 0xe3) {
    if (param_3 < 0xe0) {
      if (param_3 == 0x4a) {
        uVar3 = zcl_get_attr_value_size(0x4a);
        *(short *)param_1 = (short)*param_2;
        uVar5 = 2;
        if (uVar3 != 0xffff) {
          for (; (uVar5 & 0xffff) < uVar3; uVar5 = uVar5 + 4) {
            *(uint *)((int)param_1 + uVar5) = *param_2 + uVar5;
          }
          return 1;
        }
        return 0;
      }
      if (param_3 < 0x4b) {
        if (param_3 == 0x48) {
_L0:
          pcVar2 = "Unsupported data type (0x%x)!";
          goto _L0;
        }
        if (param_3 == 0x49) {
          uVar3 = zcl_get_attr_value_size(0x49);
          if (uVar3 != 0xffff) {
            for (uVar5 = 0; uVar5 < uVar3; uVar5 = uVar5 + 2 & 0xffff) {
              *(short *)param_1 = (short)*param_2 + (short)uVar5;
              param_1 = (int *)((int)param_1 + 2);
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
_L0:
    pcVar2 = "Unknown data type (0x%x)!";
_L0:
    log_write(2,"ZCL_COMMON",pcVar2);
    return 0;
  }
_L0:
  __n = zcl_get_attr_value_size(param_3,param_2);
_L0:
  memcpy(param_1,param_2,__n);
  return 1;
}

