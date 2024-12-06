/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_thermostat_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_thermostat_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0x1c) {
    uVar2 = 0x13;
    uVar1 = 0x30;
  }
  else if (param_1 < 0x1d) {
    if (param_1 == 0x10) {
      uVar2 = 3;
      uVar1 = 0x28;
    }
    else if (param_1 < 0x11) {
      if (param_1 < 9) {
        if (param_1 < 7) {
          if (param_1 == 1) {
            uVar2 = 1;
            uVar1 = 0x29;
          }
          else if (param_1 < 2) {
            if (param_1 != 0) goto _L0;
            uVar2 = 5;
            uVar1 = 0x29;
          }
          else if (param_1 == 2) {
            uVar2 = 1;
            uVar1 = 0x18;
          }
          else {
            if ((param_1 < 2) || (3 < (param_1 - 3 & 0xffff))) goto _L0;
            uVar2 = 1;
            uVar1 = 0x29;
          }
        }
        else {
          uVar2 = 5;
          uVar1 = 0x20;
        }
      }
      else {
        if (param_1 != 9) goto _L0;
        uVar2 = 1;
        uVar1 = 0x18;
      }
    }
    else if (param_1 == 0x19) {
      uVar2 = 1;
      uVar1 = 0x28;
    }
    else if (param_1 < 0x1a) {
      if (param_1 < 0x13) {
        if (param_1 < 0x11) goto _L0;
        uVar2 = 0x13;
        uVar1 = 0x29;
      }
      else {
        if (5 < (param_1 - 0x13 & 0xffff)) {
_L0:
          uVar1 = esp_log_timestamp(param_2);
          esp_log_write(1,0x10000,&_LC11,uVar1,0x10000);
          return 0x102;
        }
        uVar2 = 3;
        uVar1 = 0x29;
      }
    }
    else if (param_1 == 0x1a) {
      uVar2 = 3;
      uVar1 = 0x18;
    }
    else {
      if (param_1 != 0x1b) goto _L0;
      uVar2 = 3;
      uVar1 = 0x30;
    }
  }
  else if (param_1 == 0x32) {
    uVar2 = 1;
    uVar1 = 0xe2;
  }
  else if (param_1 < 0x33) {
    if (param_1 == 0x25) {
      uVar2 = 7;
      uVar1 = 0x18;
    }
    else if (param_1 < 0x26) {
      if (param_1 == 0x20) {
        uVar2 = 1;
        uVar1 = 0x30;
      }
      else if (param_1 < 0x21) {
        if (param_1 == 0x1d) {
          uVar2 = 1;
          uVar1 = 0x18;
        }
        else {
          if (param_1 != 0x1e) goto _L0;
          uVar2 = 1;
          uVar1 = 0x30;
        }
      }
      else if (param_1 == 0x24) {
        uVar2 = 3;
        uVar1 = 0x21;
      }
      else {
        if (0x24 < param_1) goto _L0;
        if (param_1 < 0x23) {
          if (param_1 < 0x21) goto _L0;
          uVar2 = 1;
          uVar1 = 0x20;
        }
        else {
          if (param_1 != 0x23) goto _L0;
          uVar2 = 3;
          uVar1 = 0x30;
        }
      }
    }
    else if (param_1 == 0x29) {
      uVar2 = 1;
      uVar1 = 0x19;
    }
    else {
      if (param_1 < 0x29) goto _L0;
      if (param_1 == 0x30) {
        uVar2 = 1;
        uVar1 = 0x30;
      }
      else {
        if (param_1 != 0x31) goto _L0;
        uVar2 = 1;
        uVar1 = 0x29;
      }
    }
  }
  else if (param_1 == 0x41) {
    uVar2 = 3;
    uVar1 = 0x21;
  }
  else if (param_1 < 0x42) {
    if (param_1 == 0x37) {
      uVar2 = 3;
      uVar1 = 0x20;
    }
    else if (param_1 < 0x38) {
      if (param_1 == 0x34) {
        uVar2 = 3;
        uVar1 = 0x20;
      }
      else {
        if ((param_1 < 0x34) || (1 < (param_1 - 0x35 & 0xffff))) goto _L0;
        uVar2 = 1;
        uVar1 = 0x20;
      }
    }
    else if (param_1 == 0x3a) {
      uVar2 = 3;
      uVar1 = 0x20;
    }
    else if (param_1 < 0x3b) {
      if (1 < (param_1 - 0x38 & 0xffff)) goto _L0;
      uVar2 = 1;
      uVar1 = 0x20;
    }
    else {
      if (param_1 != 0x40) goto _L0;
      uVar2 = 3;
      uVar1 = 0x30;
    }
  }
  else if (param_1 == 0x44) {
    uVar2 = 3;
    uVar1 = 0x1b;
  }
  else if (param_1 < 0x45) {
    if (1 < (param_1 - 0x42 & 0xffff)) goto _L0;
    uVar2 = 3;
    uVar1 = 0x30;
  }
  else if (param_1 == 0x46) {
    uVar2 = 1;
    uVar1 = 0x29;
  }
  else if (param_1 == 0x47) {
    uVar2 = 3;
    uVar1 = 0x30;
  }
  else {
    if (param_1 != 0x45) goto _L0;
    uVar2 = 3;
    uVar1 = 0x30;
  }
  uVar1 = esp_zb_internal_cluster_add_attr(0x201,param_1,uVar1,uVar2,0xffff);
  return uVar1;
}

