/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_write_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_write_attr_value(uint8_t *buffer,void *value,zcl_attr_type_t value_type)

{
  byte bVar1;
  uint16_t uVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined3 in_register_00002031;
  char *pcVar3;
  size_t __n;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uVar6 = CONCAT31(in_register_00002031,value_type);
  if (buffer == (uint8_t *)0x0) {
    return false;
  }
  if (value == (void *)0x0) {
    return false;
  }
  if (uVar6 == 0x2c) {
    uVar5 = *(undefined4 *)((int)value + 4);
                    /* WARNING: Load size is inaccurate */
    uStack_18 = *value;
    uStack_14 = uVar5;
    memcpy(buffer,&uStack_18,5);
    buffer[4] = (byte)((uint)uVar5 >> 0x18) & 0x80 | (byte)uVar5;
    return true;
  }
  if (uVar6 < 0x2d) {
    if (uVar6 == 0x21) {
_L0:
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)buffer = *value;
      return true;
    }
    if (uVar6 < 0x22) {
      if (uVar6 == 0xf) goto _L0;
      if (uVar6 < 0x10) {
        if (uVar6 == 10) {
_L0:
                    /* WARNING: Load size is inaccurate */
          uStack_18 = *value;
          __n = 3;
          goto _L0;
        }
        if (uVar6 < 0xb) {
          if (uVar6 == 0) {
            return true;
          }
          if (uVar6 == 8) goto _L0;
          if (uVar6 == 9) goto _L0;
          goto _L0;
        }
        if (uVar6 == 0xd) goto _L0;
        if (uVar6 == 0xe) goto _L0;
        if (uVar6 == 0xb) goto _L0;
      }
      else if (uVar6 != 0x1c) {
        if (0x1c < uVar6) {
          if (uVar6 == 0x1e) goto _L0;
          if (0x1e < uVar6) {
            uVar4 = 0x1f;
            goto _L182;
          }
_L0:
                    /* WARNING: Load size is inaccurate */
          uStack_18 = *value;
          uStack_14 = *(undefined4 *)((int)value + 4);
          __n = 6;
          goto _L0;
        }
        if (uVar6 != 0x1a) {
          if (uVar6 == 0x1b) {
_L0:
                    /* WARNING: Load size is inaccurate */
            *(undefined4 *)buffer = *value;
            return true;
          }
          if (uVar6 == 0x18) goto _L0;
          if (uVar6 == 0x19) goto _L0;
          uVar4 = 0x10;
          goto _L179;
        }
        goto _L0;
      }
_L0:
                    /* WARNING: Load size is inaccurate */
      uStack_18 = *value;
      uStack_14 = *(undefined4 *)((int)value + 4);
      __n = 5;
    }
    else {
      if (uVar6 == 0x29) goto _L0;
      if (0x29 < uVar6) {
                    /* WARNING: Load size is inaccurate */
        uVar5 = *value;
        if (uVar6 == 0x2a) {
          uStack_18 = uVar5;
          memcpy(buffer,&uStack_18,3);
          buffer[2] = (byte)((uint)uVar5 >> 0x18) & 0x80 | buffer[2];
          return true;
        }
        *(undefined4 *)buffer = uVar5;
        return true;
      }
      if (uVar6 != 0x26) {
        if (0x26 < uVar6) {
          uVar4 = 0x27;
_L182:
          if (uVar6 == uVar4) {
_L0:
                    /* WARNING: Load size is inaccurate */
            uVar5 = *(undefined4 *)((int)value + 4);
            *(undefined4 *)buffer = *value;
            *(undefined4 *)(buffer + 4) = uVar5;
            return true;
          }
_L0:
                    /* WARNING: Load size is inaccurate */
          *buffer = *value;
          return true;
        }
        if (uVar6 != 0x24) {
          if (uVar6 == 0x25) goto _L0;
          if (uVar6 != 0x22) goto _L0;
          goto _L0;
        }
        goto _L0;
      }
_L0:
                    /* WARNING: Load size is inaccurate */
      uStack_18 = *value;
      uStack_14 = *(undefined4 *)((int)value + 4);
      __n = 7;
    }
_L0:
    value = &uStack_18;
    goto _L0;
  }
  if (uVar6 < 0x45) {
    if (0x40 < uVar6) {
      uVar2 = zcl_get_attr_value_size(value_type,value);
      __n = CONCAT22(extraout_var_01,uVar2);
      if (__n == 0xffff) {
        return false;
      }
      goto _L0;
    }
    if (uVar6 == 0x2f) goto _L0;
    if (uVar6 < 0x30) {
                    /* WARNING: Load size is inaccurate */
      uStack_18 = *value;
      uVar5 = *(undefined4 *)((int)value + 4);
      bVar1 = (byte)((uint)uVar5 >> 0x18);
      uStack_14 = uVar5;
      if (uVar6 == 0x2d) {
        memcpy(buffer,&uStack_18,6);
        buffer[5] = bVar1 & 0x80 | (byte)((uint)uVar5 >> 8);
        return true;
      }
      memcpy(buffer,&uStack_18,7);
      buffer[6] = bVar1 & 0x80 | (byte)((uint)uVar5 >> 0x10);
      return true;
    }
    if (uVar6 == 0x39) {
                    /* WARNING: Load size is inaccurate */
      uStack_18 = *value;
      __n = 4;
      value = &uStack_18;
      goto _L0;
    }
    if (uVar6 < 0x3a) {
      if ((uVar6 == 0x31) || (uVar6 == 0x38)) goto _L0;
      uVar4 = 0x30;
_L179:
      if (uVar6 == uVar4) goto _L0;
    }
    else if (uVar6 == 0x3a) {
                    /* WARNING: Load size is inaccurate */
      uStack_18 = *value;
      uStack_14 = *(undefined4 *)((int)value + 4);
      __n = 8;
      value = &uStack_18;
      goto _L0;
    }
    goto _L0;
  }
  if (uVar6 < 0xe3) {
    if (uVar6 < 0xe0) {
      if (uVar6 == 0x4a) {
        uVar2 = zcl_get_attr_value_size(value_type,value);
                    /* WARNING: Load size is inaccurate */
        *(undefined2 *)buffer = *value;
        uVar6 = 2;
        if (CONCAT22(extraout_var_02,uVar2) != 0xffff) {
          for (; (uVar6 & 0xffff) < CONCAT22(extraout_var_02,uVar2); uVar6 = uVar6 + 4) {
                    /* WARNING: Load size is inaccurate */
            *(uint *)(buffer + uVar6) = *value + uVar6;
          }
          return true;
        }
        return false;
      }
      if (uVar6 < 0x4b) {
        if (uVar6 == 0x48) {
_L0:
          pcVar3 = "Unsupported data type (0x%x)!";
          goto _L0;
        }
        if (uVar6 == 0x49) {
          uVar2 = zcl_get_attr_value_size(value_type,value);
          if (CONCAT22(extraout_var,uVar2) != 0xffff) {
            for (uVar6 = 0; uVar6 < CONCAT22(extraout_var,uVar2); uVar6 = uVar6 + 2 & 0xffff) {
                    /* WARNING: Load size is inaccurate */
              *(short *)buffer = *value + (short)uVar6;
              buffer = (uint8_t *)((int)buffer + 2);
            }
            return true;
          }
          return false;
        }
      }
      else if ((uVar6 == 0x4c) || ((uVar6 - 0x50 & 0xff) < 2)) goto _L0;
      goto _L0;
    }
  }
  else if (uVar6 != 0xf0) {
    if (uVar6 < 0xf1) {
      if (uVar6 < 0xea) {
        if (0xe7 < uVar6) goto _L0;
      }
      else if (uVar6 == 0xea) goto _L0;
    }
    else if (uVar6 == 0xf1) goto _L0;
_L0:
    pcVar3 = "Unknown data type (0x%x)!";
_L0:
    log_write(2,"ZCL_COMMON",pcVar3);
    return false;
  }
_L0:
  uVar2 = zcl_get_attr_value_size(value_type,value);
  __n = CONCAT22(extraout_var_00,uVar2);
_L0:
  memcpy(buffer,value,__n);
  return true;
}

