/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_read_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_read_attr_value(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  size_t sVar2;
  uint extraout_a1;
  uint extraout_a1_00;
  uint extraout_a1_01;
  uint extraout_a1_02;
  uint extraout_a1_03;
  uint extraout_a1_04;
  uint extraout_a1_05;
  uint uVar3;
  uint uStack_14;
  
  if (param_1 == (uint *)0x0) {
    return 0;
  }
  if (param_2 == (uint *)0x0) {
    return 0;
  }
  if (param_3 == 0x2c) {
    uVar1 = zcl_read_s40(param_2);
    *param_1 = uVar1;
    param_1[1] = extraout_a1_04;
    return 1;
  }
  if (param_3 < 0x2d) {
    if (param_3 == 0x21) {
_L0:
      *(short *)param_1 = (short)*param_2;
      return 1;
    }
    if (param_3 < 0x22) {
      if (param_3 == 0xf) {
_L0:
        uVar1 = param_2[1];
        *param_1 = *param_2;
        param_1[1] = uVar1;
        return 1;
      }
      if (param_3 < 0x10) {
        if (param_3 == 10) {
_L0:
          uStack_14 = (uint)(uint3)*param_2;
          *param_1 = uStack_14;
          return 1;
        }
        if (param_3 < 0xb) {
          if (param_3 == 0) {
            return 1;
          }
          if (param_3 == 8) goto _L0;
          if (param_3 == 9) goto _L0;
        }
        else {
          if (param_3 == 0xd) {
_L0:
            uVar1 = zcl_read_u48(param_2);
            *param_1 = uVar1;
            param_1[1] = extraout_a1_02;
            return 1;
          }
          if (param_3 < 0xe) {
            if (param_3 == 0xb) {
_L0:
              *param_1 = *param_2;
              return 1;
            }
            if (param_3 == 0xc) goto _L0;
          }
          else if (param_3 == 0xe) goto _L0;
        }
      }
      else {
        if (param_3 == 0x1c) {
_L0:
          uVar1 = zcl_read_u40(param_2);
          *param_1 = uVar1;
          param_1[1] = extraout_a1_00;
          return 1;
        }
        if (param_3 < 0x1d) {
          if (param_3 == 0x1a) goto _L0;
          if (param_3 < 0x1b) {
            if (param_3 != 0x18) {
              if (param_3 == 0x19) goto _L0;
              if (param_3 != 0x10) goto _L0;
            }
_L0:
            *(char *)param_1 = (char)*param_2;
            return 1;
          }
          if (param_3 == 0x1b) goto _L0;
        }
        else {
          if (param_3 == 0x1e) goto _L0;
          if (param_3 < 0x1f) {
            if (param_3 == 0x1d) goto _L0;
          }
          else {
            if (param_3 == 0x1f) goto _L0;
            if (param_3 == 0x20) goto _L0;
          }
        }
      }
    }
    else {
      if (param_3 == 0x29) {
        *(short *)param_1 = (short)*param_2;
        return 1;
      }
      if (param_3 < 0x2a) {
        if (param_3 == 0x26) {
_L0:
          uVar1 = zcl_read_u56(param_2);
          *param_1 = uVar1;
          param_1[1] = extraout_a1_01;
          return 1;
        }
        if (param_3 < 0x27) {
          if (param_3 == 0x24) goto _L0;
          if (param_3 < 0x25) {
            if (param_3 == 0x22) goto _L0;
            if (param_3 == 0x23) goto _L0;
          }
          else if (param_3 == 0x25) goto _L0;
        }
        else {
          if (param_3 == 0x27) goto _L0;
          if (param_3 == 0x28) {
            *(char *)param_1 = (char)*param_2;
            return 1;
          }
        }
      }
      else {
        if (param_3 == 0x2a) {
          uVar1 = zcl_read_s24(param_2);
          *param_1 = uVar1;
          return 1;
        }
        if (param_3 == 0x2b) {
          *param_1 = *param_2;
          return 1;
        }
      }
    }
  }
  else if (param_3 < 0x45) {
    if (0x40 < param_3) {
      sVar2 = zcl_get_attr_value_size(param_3);
      if (sVar2 == 0xffff) {
        return 0;
      }
      memcpy(param_1,param_2,sVar2);
      return 1;
    }
    if (param_3 == 0x2f) {
      uVar1 = param_2[1];
      *param_1 = *param_2;
      param_1[1] = uVar1;
      return 1;
    }
    if (param_3 < 0x30) {
      if (param_3 == 0x2d) {
        uVar1 = zcl_read_s48(param_2);
        *param_1 = uVar1;
        param_1[1] = extraout_a1_05;
        return 1;
      }
      if (param_3 == 0x2e) {
        uVar1 = zcl_read_s56(param_2);
        *param_1 = uVar1;
        param_1[1] = extraout_a1_03;
        return 1;
      }
    }
    else {
      if (param_3 == 0x39) {
        *param_1 = *param_2;
        return 1;
      }
      if (param_3 < 0x3a) {
        if ((param_3 == 0x31) || (param_3 == 0x38)) goto _L0;
        if (param_3 == 0x30) goto _L0;
      }
      else if (param_3 == 0x3a) {
        uVar1 = zcl_read_double(param_2);
        *param_1 = uVar1;
        param_1[1] = extraout_a1;
        return 1;
      }
    }
  }
  else if (param_3 < 0xe3) {
    if (0xdf < param_3) {
_L0:
      sVar2 = zcl_get_attr_value_size(param_3,param_2);
      memcpy(param_1,param_2,sVar2);
      return 1;
    }
    if (param_3 == 0x4a) {
      uVar1 = zcl_get_attr_value_size(0x4a);
      *(short *)param_1 = (short)*param_2;
      if (uVar1 != 0xffff) {
        for (uVar3 = 2; uVar3 < uVar1; uVar3 = uVar3 + 4 & 0xffff) {
          *(undefined4 *)((int)param_1 + uVar3) = *(undefined4 *)((int)param_2 + uVar3);
        }
        return 1;
      }
      return 0;
    }
    if (param_3 < 0x4b) {
      if (param_3 == 0x48) {
_L0:
        log_write(2,"ZCL_COMMON","Unsupported data type (0x%x)!",param_3);
        return 0;
      }
      if (param_3 == 0x49) {
        uVar1 = zcl_get_attr_value_size(0x49);
        if (uVar1 != 0xffff) {
          for (uVar3 = 0; uVar3 < uVar1; uVar3 = uVar3 + 2 & 0xffff) {
            *(undefined2 *)((int)param_1 + uVar3) = *(undefined2 *)((int)param_2 + uVar3);
          }
          return 1;
        }
        return 0;
      }
    }
    else if ((param_3 == 0x4c) || ((0x4b < param_3 && ((param_3 - 0x50 & 0xff) < 2)))) goto _L0;
  }
  else {
    if (param_3 == 0xf0) {
      sVar2 = zcl_get_attr_value_size(0xf0);
      memcpy(param_1,param_2,sVar2);
      return 1;
    }
    if (param_3 < 0xf1) {
      if (param_3 < 0xea) {
        if (0xe7 < param_3) goto _L0;
      }
      else if (param_3 == 0xea) goto _L0;
    }
    else if (param_3 == 0xf1) {
      sVar2 = zcl_get_attr_value_size(0xf1);
      memcpy(param_1,param_2,sVar2);
      return 1;
    }
  }
_L0:
  log_write(2,"ZCL_COMMON","Unknown data type (0x%x)!",param_3);
  return 0;
}

