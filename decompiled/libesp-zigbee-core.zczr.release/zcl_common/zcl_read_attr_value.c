/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_read_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_read_attr_value(void *value,uint8_t *buffer,zcl_attr_type_t value_type)

{
  uint8_t uVar1;
  uint16_t uVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined3 in_register_00002031;
  char *pcVar3;
  size_t sVar4;
  uint uVar5;
  uint uVar6;
  uint uStack_18;
  ezb_zcl_uint24_t ret;
  
  uVar6 = CONCAT31(in_register_00002031,value_type);
  if (value == (void *)0x0) {
    return false;
  }
  if (buffer == (uint8_t *)0x0) {
    return false;
  }
  if (uVar6 == 0x2c) {
    uStack_18 = 0;
    ret = 0;
    memcpy(&uStack_18,buffer,5);
    uVar1 = buffer[4];
    *(uint *)value = uStack_18;
    uVar6 = (~(int)(char)uVar1 >> 0x1f & 0x100U) - 0x100;
_L0:
    ret = uVar6 | ret;
    goto _L0;
  }
  if (uVar6 < 0x2d) {
    if (uVar6 == 0x21) {
_L0:
      *(undefined2 *)value = *(undefined2 *)buffer;
      return true;
    }
    if (0x21 < uVar6) {
      if (uVar6 == 0x29) goto _L0;
      if (uVar6 < 0x2a) {
        if (uVar6 == 0x26) goto _L0;
        if (0x26 < uVar6) {
          uVar5 = 0x27;
_L267:
          if (uVar6 != uVar5) {
_L0:
            *(uint8_t *)value = *buffer;
            return true;
          }
          goto _L0;
        }
        if (uVar6 == 0x24) goto _L0;
        if (uVar6 == 0x25) goto _L0;
        if (uVar6 == 0x22) goto _L0;
      }
      else if (uVar6 == 0x2a) {
        uStack_18 = 0;
        memcpy(&uStack_18,buffer,3);
        uVar6 = 0;
        if ((char)buffer[2] < '\0') {
          uVar6 = 0xff000000;
        }
        uStack_18 = uVar6 | uStack_18;
        goto _L0;
      }
_L0:
      uStack_18 = *(uint *)buffer;
      goto _L0;
    }
    if (uVar6 != 0xf) {
      if (uVar6 < 0x10) {
        if (uVar6 == 10) {
_L0:
          uStack_18 = 0;
          memcpy(&uStack_18,buffer,3);
_L0:
          *(uint *)value = uStack_18;
          return true;
        }
        if (uVar6 < 0xb) {
          if (uVar6 == 0) {
            return true;
          }
          if (uVar6 == 8) goto _L0;
          if (uVar6 == 9) goto _L0;
          goto _L0;
        }
        if (uVar6 == 0xd) {
_L0:
          sVar4 = 6;
          goto _L0;
        }
        if (uVar6 == 0xe) goto _L0;
        if (uVar6 == 0xb) goto _L0;
_L0:
        sVar4 = 5;
      }
      else {
        if (uVar6 == 0x1c) goto _L0;
        if (uVar6 < 0x1d) {
          if (uVar6 != 0x1a) {
            if (uVar6 != 0x1b) {
              if (uVar6 == 0x18) goto _L0;
              if (uVar6 == 0x19) goto _L0;
              uVar5 = 0x10;
              goto _L264;
            }
            goto _L0;
          }
          goto _L0;
        }
        if (uVar6 != 0x1e) {
          if (0x1e < uVar6) {
            uVar5 = 0x1f;
            goto _L267;
          }
          goto _L0;
        }
_L0:
        sVar4 = 7;
      }
_L0:
      ret = 0;
      uStack_18 = 0;
      goto _L0;
    }
_L0:
    uStack_18 = *(uint *)buffer;
    ret = *(ezb_zcl_uint24_t *)(buffer + 4);
  }
  else {
    if (0x44 < uVar6) {
      if (uVar6 < 0xe3) {
        if (uVar6 < 0xe0) {
          if (uVar6 == 0x4a) {
            uVar2 = zcl_get_attr_value_size(value_type,buffer);
            *(undefined2 *)value = *(undefined2 *)buffer;
            uVar6 = 2;
            if (CONCAT22(extraout_var_02,uVar2) != 0xffff) {
              for (; (uVar6 & 0xffff) < CONCAT22(extraout_var_02,uVar2); uVar6 = uVar6 + 4) {
                *(undefined4 *)((int)value + uVar6) = *(undefined4 *)(buffer + uVar6);
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
              uVar2 = zcl_get_attr_value_size(value_type,buffer);
              uVar6 = 0;
              if (CONCAT22(extraout_var,uVar2) != 0xffff) {
                for (; (uVar6 & 0xffff) < CONCAT22(extraout_var,uVar2); uVar6 = uVar6 + 2) {
                  *(undefined2 *)((int)value + uVar6) = *(undefined2 *)(buffer + uVar6);
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
        goto _L0;
      }
_L0:
      uVar2 = zcl_get_attr_value_size(value_type,buffer);
      sVar4 = CONCAT22(extraout_var_00,uVar2);
_L0:
      memcpy(value,buffer,sVar4);
      return true;
    }
    if (0x40 < uVar6) {
      uVar2 = zcl_get_attr_value_size(value_type,buffer);
      sVar4 = CONCAT22(extraout_var_01,uVar2);
      if (sVar4 == 0xffff) {
        return false;
      }
      goto _L0;
    }
    if (uVar6 == 0x2f) goto _L0;
    if (uVar6 < 0x30) {
      if (uVar6 == 0x2d) {
        uStack_18 = 0;
        ret = 0;
        memcpy(&uStack_18,buffer,6);
        uVar6 = 0;
        if ((char)buffer[5] < '\0') {
          uVar6 = 0xffff0000;
        }
      }
      else {
        uStack_18 = 0;
        ret = 0;
        memcpy(&uStack_18,buffer,7);
        uVar6 = 0;
        if ((char)buffer[6] < '\0') {
          uVar6 = 0xff000000;
        }
      }
      *(uint *)value = uStack_18;
      goto _L0;
    }
    if (uVar6 == 0x39) {
      memcpy(&uStack_18,buffer,4);
      *(uint *)value = uStack_18;
      return true;
    }
    if (uVar6 < 0x3a) {
      if ((uVar6 == 0x31) || (uVar6 == 0x38)) goto _L0;
      uVar5 = 0x30;
_L264:
      if (uVar6 == uVar5) goto _L0;
_L0:
      pcVar3 = "Unknown data type (0x%x)!";
_L0:
      log_write(2,"ZCL_COMMON",pcVar3,uVar6);
      return false;
    }
    if (uVar6 != 0x3a) goto _L0;
    sVar4 = 8;
_L0:
    memcpy(&uStack_18,buffer,sVar4);
  }
  *(uint *)value = uStack_18;
_L0:
  *(ezb_zcl_uint24_t *)((int)value + 4) = ret;
  return true;
}

