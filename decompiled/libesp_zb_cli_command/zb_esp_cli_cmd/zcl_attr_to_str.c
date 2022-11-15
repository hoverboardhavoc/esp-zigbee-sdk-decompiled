/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd.o -> zcl_attr_to_str
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_attr_to_str(char *param_1,uint param_2,uint param_3,byte *param_4)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == (char *)0x0) {
    return -1;
  }
  if (param_4 == (byte *)0x0) {
    return -1;
  }
  if (param_3 == 0x29) {
    iVar1 = snprintf(param_1,param_2,"%hd");
    return iVar1;
  }
  if (param_3 < 0x2a) {
    if (param_3 < 0x24) {
      if (param_3 < 0x18) {
        if (param_3 == 0x10) {
          iVar1 = snprintf(param_1,param_2,"%s");
          return iVar1;
        }
        if (param_3 < 0x11) {
          if (param_3 == 9) {
_L0:
            iVar1 = snprintf(param_1,param_2,"%hu");
            return iVar1;
          }
          if (param_3 == 0xb) goto _L0;
          if (param_3 == 8) goto _L0;
        }
      }
      else {
        uVar2 = 1 << (param_3 - 0x18 & 0x1f);
        if ((uVar2 & 0x808) != 0) {
_L0:
          iVar1 = snprintf(param_1,param_2,"%u");
          return iVar1;
        }
        if ((uVar2 & 0x202) != 0) goto _L0;
        if ((uVar2 & 0x101) != 0) {
_L0:
          iVar1 = snprintf(param_1,param_2,"%hu");
          return iVar1;
        }
      }
    }
    else if (param_3 == 0x28) {
      iVar1 = snprintf(param_1,param_2,"%hd");
      return iVar1;
    }
  }
  else {
    if (param_3 == 0x42) {
      uVar2 = (uint)*param_4;
      if (uVar2 < param_2) {
        for (iVar1 = 0; iVar1 < (int)uVar2; iVar1 = iVar1 + 1) {
          param_1[iVar1] = param_4[iVar1 + 1];
        }
        param_1[iVar1] = '\0';
        return uVar2 + 1;
      }
      return -1;
    }
    if (param_3 < 0x43) {
      if (param_3 == 0x2b) {
        iVar1 = snprintf(param_1,param_2,"%d");
        return iVar1;
      }
      if (0x2a < param_3) {
        if (param_3 == 0x30) goto _L0;
        if (param_3 == 0x31) goto _L0;
      }
    }
    else if (param_3 == 0xf0) {
      iVar1 = to_hex_str(param_4,8,1);
      return iVar1;
    }
  }
  iVar1 = snprintf(param_1,param_2,"Value type 0x%x unsupported");
  return iVar1;
}

