/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_write_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_write_attr_value(uint8_t *buffer,void *value,zcl_attr_type_t value_type)

{
  uint16_t uVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined3 in_register_00002031;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  ezb_zcl_int40_t in_fa1;
  uint8_t uStack_18;
  uint8_t uStack_17;
  uint8_t uStack_16;
  uint8_t uStack_15;
  uint8_t uStack_14;
  uint8_t uStack_13;
  uint8_t uStack_12;
  uint8_t uStack_11;
  
  uVar4 = CONCAT31(in_register_00002031,value_type);
  if (buffer == (uint8_t *)0x0) {
    return false;
  }
  if (value == (void *)0x0) {
    return false;
  }
  if (uVar4 == 0x2c) {
    zcl_write_s40(buffer,in_fa1);
    return true;
  }
  if (uVar4 < 0x2d) {
    if (uVar4 == 0x21) {
_L0:
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)buffer = *value;
      return true;
    }
    if (uVar4 < 0x22) {
      if (uVar4 == 0xf) {
_L0:
                    /* WARNING: Load size is inaccurate */
        uVar2 = *(undefined4 *)((int)value + 4);
        *(undefined4 *)buffer = *value;
        *(undefined4 *)(buffer + 4) = uVar2;
        return true;
      }
      if (uVar4 < 0x10) {
        if (uVar4 == 10) {
_L0:
                    /* WARNING: Load size is inaccurate */
          uVar2 = *value;
          uStack_18 = (uint8_t)uVar2;
          *buffer = uStack_18;
          uStack_17 = (uint8_t)((uint)uVar2 >> 8);
          buffer[1] = uStack_17;
          uStack_16 = (uint8_t)((uint)uVar2 >> 0x10);
          buffer[2] = uStack_16;
          return true;
        }
        if (uVar4 < 0xb) {
          if (uVar4 == 0) {
            return true;
          }
          if (uVar4 == 8) goto _L0;
          if (uVar4 == 9) goto _L0;
        }
        else {
          if (uVar4 == 0xd) {
_L0:
                    /* WARNING: Load size is inaccurate */
            uVar2 = *value;
            uStack_18 = (uint8_t)uVar2;
            uStack_17 = (uint8_t)((uint)uVar2 >> 8);
            uStack_16 = (uint8_t)((uint)uVar2 >> 0x10);
            uStack_15 = (uint8_t)((uint)uVar2 >> 0x18);
            uStack_14 = (uint8_t)*(undefined4 *)((int)value + 4);
            uStack_13 = (uint8_t)((uint)*(undefined4 *)((int)value + 4) >> 8);
            *buffer = uStack_18;
            buffer[1] = uStack_17;
            buffer[2] = uStack_16;
            buffer[3] = uStack_15;
            buffer[4] = uStack_14;
            buffer[5] = uStack_13;
            return true;
          }
          if (uVar4 < 0xe) {
            if (uVar4 == 0xb) {
_L0:
                    /* WARNING: Load size is inaccurate */
              *(undefined4 *)buffer = *value;
              return true;
            }
            if (uVar4 == 0xc) goto _L0;
          }
          else if (uVar4 == 0xe) goto _L0;
        }
      }
      else {
        if (uVar4 == 0x1c) {
_L0:
                    /* WARNING: Load size is inaccurate */
          uVar2 = *value;
          uStack_18 = (uint8_t)uVar2;
          uStack_17 = (uint8_t)((uint)uVar2 >> 8);
          uStack_16 = (uint8_t)((uint)uVar2 >> 0x10);
          uStack_15 = (uint8_t)((uint)uVar2 >> 0x18);
          uStack_14 = (uint8_t)*(undefined4 *)((int)value + 4);
          *buffer = uStack_18;
          buffer[1] = uStack_17;
          buffer[2] = uStack_16;
          buffer[3] = uStack_15;
          buffer[4] = uStack_14;
          return true;
        }
        if (uVar4 < 0x1d) {
          if (uVar4 == 0x1a) goto _L0;
          if (uVar4 < 0x1b) {
            if (uVar4 != 0x18) {
              if (uVar4 == 0x19) goto _L0;
              if (uVar4 != 0x10) goto _L0;
            }
_L0:
                    /* WARNING: Load size is inaccurate */
            *buffer = *value;
            return true;
          }
          if (uVar4 == 0x1b) goto _L0;
        }
        else {
          if (uVar4 == 0x1e) goto _L0;
          if (uVar4 < 0x1f) {
            if (uVar4 == 0x1d) goto _L0;
          }
          else {
            if (uVar4 == 0x1f) goto _L0;
            if (uVar4 == 0x20) goto _L0;
          }
        }
      }
    }
    else {
      if (uVar4 == 0x29) {
                    /* WARNING: Load size is inaccurate */
        *(undefined2 *)buffer = *value;
        return true;
      }
      if (uVar4 < 0x2a) {
        if (uVar4 == 0x26) {
_L0:
                    /* WARNING: Load size is inaccurate */
          uVar2 = *value;
          uVar3 = *(undefined4 *)((int)value + 4);
          uStack_18 = (uint8_t)uVar2;
          uStack_17 = (uint8_t)((uint)uVar2 >> 8);
          uStack_16 = (uint8_t)((uint)uVar2 >> 0x10);
          uStack_15 = (uint8_t)((uint)uVar2 >> 0x18);
          uStack_14 = (uint8_t)uVar3;
          uStack_13 = (uint8_t)((uint)uVar3 >> 8);
          uStack_12 = (uint8_t)((uint)uVar3 >> 0x10);
          *buffer = uStack_18;
          buffer[1] = uStack_17;
          buffer[2] = uStack_16;
          buffer[3] = uStack_15;
          buffer[4] = uStack_14;
          buffer[5] = uStack_13;
          buffer[6] = uStack_12;
          return true;
        }
        if (uVar4 < 0x27) {
          if (uVar4 == 0x24) goto _L0;
          if (uVar4 < 0x25) {
            if (uVar4 == 0x22) goto _L0;
            if (uVar4 == 0x23) goto _L0;
          }
          else if (uVar4 == 0x25) goto _L0;
        }
        else {
          if (uVar4 == 0x27) goto _L0;
          if (uVar4 == 0x28) {
                    /* WARNING: Load size is inaccurate */
            *buffer = *value;
            return true;
          }
        }
      }
      else {
        if (uVar4 == 0x2a) {
                    /* WARNING: Load size is inaccurate */
          zcl_write_s24(buffer,*value);
          return true;
        }
        if (uVar4 == 0x2b) {
                    /* WARNING: Load size is inaccurate */
          *(undefined4 *)buffer = *value;
          return true;
        }
      }
    }
  }
  else if (uVar4 < 0x45) {
    if (0x40 < uVar4) {
      uVar1 = zcl_get_attr_value_size(value_type,value);
      if (CONCAT22(extraout_var_03,uVar1) == 0xffff) {
        return false;
      }
      memcpy(buffer,value,CONCAT22(extraout_var_03,uVar1));
      return true;
    }
    if (uVar4 == 0x2f) {
                    /* WARNING: Load size is inaccurate */
      uVar2 = *(undefined4 *)((int)value + 4);
      *(undefined4 *)buffer = *value;
      *(undefined4 *)(buffer + 4) = uVar2;
      return true;
    }
    if (uVar4 < 0x30) {
      if (uVar4 == 0x2d) {
        zcl_write_s48(buffer,in_fa1);
        return true;
      }
      if (uVar4 == 0x2e) {
        zcl_write_s56(buffer,in_fa1);
        return true;
      }
    }
    else {
      if (uVar4 == 0x39) {
                    /* WARNING: Load size is inaccurate */
        uVar2 = *value;
        uStack_18 = (uint8_t)uVar2;
        uStack_17 = (uint8_t)((uint)uVar2 >> 8);
        uStack_16 = (uint8_t)((uint)uVar2 >> 0x10);
        uStack_15 = (uint8_t)((uint)uVar2 >> 0x18);
        *buffer = uStack_18;
        buffer[1] = uStack_17;
        buffer[2] = uStack_16;
        buffer[3] = uStack_15;
        return true;
      }
      if (uVar4 < 0x3a) {
        if ((uVar4 == 0x31) || (uVar4 == 0x38)) goto _L0;
        if (uVar4 == 0x30) goto _L0;
      }
      else if (uVar4 == 0x3a) {
                    /* WARNING: Load size is inaccurate */
        uVar2 = *value;
        uVar3 = *(undefined4 *)((int)value + 4);
        uStack_18 = (uint8_t)uVar2;
        uStack_17 = (uint8_t)((uint)uVar2 >> 8);
        uStack_16 = (uint8_t)((uint)uVar2 >> 0x10);
        uStack_15 = (uint8_t)((uint)uVar2 >> 0x18);
        uStack_14 = (uint8_t)uVar3;
        uStack_13 = (uint8_t)((uint)uVar3 >> 8);
        uStack_12 = (uint8_t)((uint)uVar3 >> 0x10);
        uStack_11 = (uint8_t)((uint)uVar3 >> 0x18);
        *buffer = uStack_18;
        buffer[1] = uStack_17;
        buffer[2] = uStack_16;
        buffer[3] = uStack_15;
        buffer[4] = uStack_14;
        buffer[5] = uStack_13;
        buffer[6] = uStack_12;
        buffer[7] = uStack_11;
        return true;
      }
    }
  }
  else if (uVar4 < 0xe3) {
    if (0xdf < uVar4) {
_L0:
      uVar1 = zcl_get_attr_value_size(value_type,value);
      memcpy(buffer,value,CONCAT22(extraout_var_01,uVar1));
      return true;
    }
    if (uVar4 == 0x4a) {
      uVar1 = zcl_get_attr_value_size(value_type,value);
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)buffer = *value;
      if (CONCAT22(extraout_var_04,uVar1) != 0xffff) {
        for (uVar4 = 2; uVar4 < CONCAT22(extraout_var_04,uVar1); uVar4 = uVar4 + 4 & 0xffff) {
                    /* WARNING: Load size is inaccurate */
          *(uint *)(buffer + uVar4) = *value + uVar4;
        }
        return true;
      }
      return false;
    }
    if (uVar4 < 0x4b) {
      if (uVar4 == 0x48) {
_L0:
        log_write(2,"ZCL_COMMON","Unsupported data type (0x%x)!",uVar4);
        return false;
      }
      if (uVar4 == 0x49) {
        uVar1 = zcl_get_attr_value_size(value_type,value);
        if (CONCAT22(extraout_var,uVar1) != 0xffff) {
          for (uVar4 = 0; uVar4 < CONCAT22(extraout_var,uVar1); uVar4 = uVar4 + 2 & 0xffff) {
                    /* WARNING: Load size is inaccurate */
            *(short *)(buffer + uVar4) = *value + (short)uVar4;
          }
          return true;
        }
        return false;
      }
    }
    else if ((uVar4 == 0x4c) || ((0x4b < uVar4 && ((uVar4 - 0x50 & 0xff) < 2)))) goto _L0;
  }
  else {
    if (uVar4 == 0xf0) {
      uVar1 = zcl_get_attr_value_size(value_type,value);
      memcpy(buffer,value,CONCAT22(extraout_var_02,uVar1));
      return true;
    }
    if (uVar4 < 0xf1) {
      if (uVar4 < 0xea) {
        if (0xe7 < uVar4) goto _L0;
      }
      else if (uVar4 == 0xea) goto _L0;
    }
    else if (uVar4 == 0xf1) {
      uVar1 = zcl_get_attr_value_size(value_type,value);
      memcpy(buffer,value,CONCAT22(extraout_var_00,uVar1));
      return true;
    }
  }
_L0:
  log_write(2,"ZCL_COMMON","Unknown data type (0x%x)!",uVar4);
  return false;
}

