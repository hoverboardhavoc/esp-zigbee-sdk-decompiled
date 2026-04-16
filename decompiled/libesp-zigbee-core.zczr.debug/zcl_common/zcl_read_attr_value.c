/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_read_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_read_attr_value(void *value,uint8_t *buffer,zcl_attr_type_t value_type)

{
  uint16_t uVar1;
  undefined4 extraout_a0;
  undefined4 extraout_a0_00;
  undefined4 extraout_a0_01;
  undefined4 extraout_a0_02;
  undefined4 extraout_a0_03;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  ezb_zcl_int24_t eVar2;
  undefined4 extraout_a0_04;
  undefined4 extraout_a0_05;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined4 extraout_a1;
  undefined4 extraout_a1_00;
  undefined4 extraout_a1_01;
  undefined4 extraout_a1_02;
  undefined4 extraout_a1_03;
  undefined4 extraout_a1_04;
  undefined4 extraout_a1_05;
  undefined3 in_register_00002031;
  uint uVar3;
  undefined4 uVar4;
  uint uStack_14;
  ezb_zcl_uint24_t ret;
  
  uVar3 = CONCAT31(in_register_00002031,value_type);
  if (value == (void *)0x0) {
    return false;
  }
  if (buffer == (uint8_t *)0x0) {
    return false;
  }
  if (uVar3 == 0x2c) {
    zcl_read_s40(buffer);
    *(undefined4 *)value = extraout_a0_04;
    *(undefined4 *)((int)value + 4) = extraout_a1_04;
    return true;
  }
  if (uVar3 < 0x2d) {
    if (uVar3 == 0x21) {
_L0:
      *(undefined2 *)value = *(undefined2 *)buffer;
      return true;
    }
    if (uVar3 < 0x22) {
      if (uVar3 == 0xf) {
_L0:
        uVar4 = *(undefined4 *)(buffer + 4);
        *(undefined4 *)value = *(undefined4 *)buffer;
        *(undefined4 *)((int)value + 4) = uVar4;
        return true;
      }
      if (uVar3 < 0x10) {
        if (uVar3 == 10) {
_L0:
          uStack_14 = (uint)*(uint3 *)buffer;
          *(uint *)value = uStack_14;
          return true;
        }
        if (uVar3 < 0xb) {
          if (uVar3 == 0) {
            return true;
          }
          if (uVar3 == 8) goto _L0;
          if (uVar3 == 9) goto _L0;
        }
        else {
          if (uVar3 == 0xd) {
_L0:
            zcl_read_u48(buffer);
            *(undefined4 *)value = extraout_a0_02;
            *(undefined4 *)((int)value + 4) = extraout_a1_02;
            return true;
          }
          if (uVar3 < 0xe) {
            if (uVar3 == 0xb) {
_L0:
              *(undefined4 *)value = *(undefined4 *)buffer;
              return true;
            }
            if (uVar3 == 0xc) goto _L0;
          }
          else if (uVar3 == 0xe) goto _L0;
        }
      }
      else {
        if (uVar3 == 0x1c) {
_L0:
          zcl_read_u40(buffer);
          *(undefined4 *)value = extraout_a0_00;
          *(undefined4 *)((int)value + 4) = extraout_a1_00;
          return true;
        }
        if (uVar3 < 0x1d) {
          if (uVar3 == 0x1a) goto _L0;
          if (uVar3 < 0x1b) {
            if (uVar3 != 0x18) {
              if (uVar3 == 0x19) goto _L0;
              if (uVar3 != 0x10) goto _L0;
            }
_L0:
            *(uint8_t *)value = *buffer;
            return true;
          }
          if (uVar3 == 0x1b) goto _L0;
        }
        else {
          if (uVar3 == 0x1e) goto _L0;
          if (uVar3 < 0x1f) {
            if (uVar3 == 0x1d) goto _L0;
          }
          else {
            if (uVar3 == 0x1f) goto _L0;
            if (uVar3 == 0x20) goto _L0;
          }
        }
      }
    }
    else {
      if (uVar3 == 0x29) {
        *(undefined2 *)value = *(undefined2 *)buffer;
        return true;
      }
      if (uVar3 < 0x2a) {
        if (uVar3 == 0x26) {
_L0:
          zcl_read_u56(buffer);
          *(undefined4 *)value = extraout_a0_01;
          *(undefined4 *)((int)value + 4) = extraout_a1_01;
          return true;
        }
        if (uVar3 < 0x27) {
          if (uVar3 == 0x24) goto _L0;
          if (uVar3 < 0x25) {
            if (uVar3 == 0x22) goto _L0;
            if (uVar3 == 0x23) goto _L0;
          }
          else if (uVar3 == 0x25) goto _L0;
        }
        else {
          if (uVar3 == 0x27) goto _L0;
          if (uVar3 == 0x28) {
            *(uint8_t *)value = *buffer;
            return true;
          }
        }
      }
      else {
        if (uVar3 == 0x2a) {
          eVar2 = zcl_read_s24(buffer);
          *(ezb_zcl_int24_t *)value = eVar2;
          return true;
        }
        if (uVar3 == 0x2b) {
          *(undefined4 *)value = *(undefined4 *)buffer;
          return true;
        }
      }
    }
  }
  else if (uVar3 < 0x45) {
    if (0x40 < uVar3) {
      uVar1 = zcl_get_attr_value_size(value_type,buffer);
      if (CONCAT22(extraout_var_03,uVar1) == 0xffff) {
        return false;
      }
      memcpy(value,buffer,CONCAT22(extraout_var_03,uVar1));
      return true;
    }
    if (uVar3 == 0x2f) {
      uVar4 = *(undefined4 *)(buffer + 4);
      *(undefined4 *)value = *(undefined4 *)buffer;
      *(undefined4 *)((int)value + 4) = uVar4;
      return true;
    }
    if (uVar3 < 0x30) {
      if (uVar3 == 0x2d) {
        zcl_read_s48(buffer);
        *(undefined4 *)value = extraout_a0_05;
        *(undefined4 *)((int)value + 4) = extraout_a1_05;
        return true;
      }
      if (uVar3 == 0x2e) {
        zcl_read_s56(buffer);
        *(undefined4 *)value = extraout_a0_03;
        *(undefined4 *)((int)value + 4) = extraout_a1_03;
        return true;
      }
    }
    else {
      if (uVar3 == 0x39) {
        *(undefined4 *)value = *(undefined4 *)buffer;
        return true;
      }
      if (uVar3 < 0x3a) {
        if ((uVar3 == 0x31) || (uVar3 == 0x38)) goto _L0;
        if (uVar3 == 0x30) goto _L0;
      }
      else if (uVar3 == 0x3a) {
        zcl_read_double(buffer);
        *(undefined4 *)value = extraout_a0;
        *(undefined4 *)((int)value + 4) = extraout_a1;
        return true;
      }
    }
  }
  else if (uVar3 < 0xe3) {
    if (0xdf < uVar3) {
_L0:
      uVar1 = zcl_get_attr_value_size(value_type,buffer);
      memcpy(value,buffer,CONCAT22(extraout_var_01,uVar1));
      return true;
    }
    if (uVar3 == 0x4a) {
      uVar1 = zcl_get_attr_value_size(value_type,buffer);
      *(undefined2 *)value = *(undefined2 *)buffer;
      if (CONCAT22(extraout_var_04,uVar1) != 0xffff) {
        for (uVar3 = 2; uVar3 < CONCAT22(extraout_var_04,uVar1); uVar3 = uVar3 + 4 & 0xffff) {
          *(undefined4 *)((int)value + uVar3) = *(undefined4 *)(buffer + uVar3);
        }
        return true;
      }
      return false;
    }
    if (uVar3 < 0x4b) {
      if (uVar3 == 0x48) {
_L0:
        log_write(2,"ZCL_COMMON","Unsupported data type (0x%x)!",uVar3);
        return false;
      }
      if (uVar3 == 0x49) {
        uVar1 = zcl_get_attr_value_size(value_type,buffer);
        if (CONCAT22(extraout_var,uVar1) != 0xffff) {
          for (uVar3 = 0; uVar3 < CONCAT22(extraout_var,uVar1); uVar3 = uVar3 + 2 & 0xffff) {
            *(undefined2 *)((int)value + uVar3) = *(undefined2 *)(buffer + uVar3);
          }
          return true;
        }
        return false;
      }
    }
    else if ((uVar3 == 0x4c) || ((0x4b < uVar3 && ((uVar3 - 0x50 & 0xff) < 2)))) goto _L0;
  }
  else {
    if (uVar3 == 0xf0) {
      uVar1 = zcl_get_attr_value_size(value_type,buffer);
      memcpy(value,buffer,CONCAT22(extraout_var_02,uVar1));
      return true;
    }
    if (uVar3 < 0xf1) {
      if (uVar3 < 0xea) {
        if (0xe7 < uVar3) goto _L0;
      }
      else if (uVar3 == 0xea) goto _L0;
    }
    else if (uVar3 == 0xf1) {
      uVar1 = zcl_get_attr_value_size(value_type,buffer);
      memcpy(value,buffer,CONCAT22(extraout_var_00,uVar1));
      return true;
    }
  }
_L0:
  log_write(2,"ZCL_COMMON","Unknown data type (0x%x)!",uVar3);
  return false;
}

