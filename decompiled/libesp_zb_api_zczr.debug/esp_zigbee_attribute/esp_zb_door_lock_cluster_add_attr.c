/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_door_lock_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_door_lock_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0x23) {
    uVar2 = 7;
    uVar1 = 0x23;
  }
  else if (param_1 < 0x24) {
    if (param_1 == 0x14) {
      uVar2 = 1;
      uVar1 = 0x20;
    }
    else if (param_1 < 0x15) {
      if (param_1 == 6) {
        uVar2 = 3;
        uVar1 = 0x21;
      }
      else if (param_1 < 7) {
        if (param_1 == 3) {
          uVar2 = 5;
          uVar1 = 0x30;
        }
        else if (param_1 < 4) {
          if (param_1 == 1) {
            uVar2 = 1;
            uVar1 = 0x30;
          }
          else if (param_1 == 2) {
            uVar2 = 1;
            uVar1 = 0x10;
          }
          else {
            if (param_1 != 0) goto _L0;
            uVar2 = 5;
            uVar1 = 0x30;
          }
        }
        else if (param_1 == 4) {
          uVar2 = 3;
          uVar1 = 0x23;
        }
        else {
          if (param_1 != 5) goto _L0;
          uVar2 = 3;
          uVar1 = 0x23;
        }
      }
      else if (param_1 == 0x12) {
        uVar2 = 1;
        uVar1 = 0x21;
      }
      else if (param_1 < 0x13) {
        if (param_1 == 0x10) {
          uVar2 = 1;
          uVar1 = 0x21;
        }
        else {
          if (param_1 != 0x11) goto _L0;
          uVar2 = 1;
          uVar1 = 0x21;
        }
      }
      else {
        if (param_1 != 0x13) goto _L0;
        uVar2 = 1;
        uVar1 = 0x21;
      }
    }
    else if (param_1 == 0x19) {
      uVar2 = 1;
      uVar1 = 0x20;
    }
    else if (param_1 < 0x1a) {
      if (param_1 == 0x17) {
        uVar2 = 1;
        uVar1 = 0x20;
      }
      else if (param_1 < 0x18) {
        if (param_1 == 0x15) {
          uVar2 = 1;
          uVar1 = 0x20;
        }
        else {
          if (param_1 != 0x16) goto _L0;
          uVar2 = 1;
          uVar1 = 0x20;
        }
      }
      else {
        if (param_1 != 0x18) goto _L0;
        uVar2 = 1;
        uVar1 = 0x20;
      }
    }
    else if (param_1 == 0x21) {
      uVar2 = 7;
      uVar1 = 0x42;
    }
    else if (param_1 < 0x22) {
      if (param_1 == 0x1a) {
        uVar2 = 1;
        uVar1 = 0x20;
      }
      else {
        if (param_1 != 0x20) goto _L0;
        uVar2 = 7;
        uVar1 = 0x10;
      }
    }
    else {
      if (param_1 != 0x22) goto _L0;
      uVar2 = 7;
      uVar1 = 0x20;
    }
  }
  else if (param_1 == 0x32) {
    uVar2 = 7;
    uVar1 = 0x10;
  }
  else if (param_1 < 0x33) {
    if (param_1 == 0x29) {
      uVar2 = 7;
      uVar1 = 0x10;
    }
    else if (param_1 < 0x2a) {
      if (param_1 == 0x26) {
        uVar2 = 1;
        uVar1 = 0x19;
      }
      else if (param_1 < 0x27) {
        if (param_1 == 0x24) {
          uVar2 = 7;
          uVar1 = 0x20;
        }
        else {
          if (param_1 != 0x25) goto _L0;
          uVar2 = 7;
          uVar1 = 0x30;
        }
      }
      else if (param_1 == 0x27) {
        uVar2 = 5;
        uVar1 = 0x19;
      }
      else {
        if (param_1 != 0x28) goto _L0;
        uVar2 = 7;
        uVar1 = 0x10;
      }
    }
    else if (param_1 == 0x30) {
      uVar2 = 7;
      uVar1 = 0x20;
    }
    else if (param_1 < 0x31) {
      if (param_1 == 0x2a) {
        uVar2 = 7;
        uVar1 = 0x10;
      }
      else {
        if (param_1 != 0x2b) goto _L0;
        uVar2 = 7;
        uVar1 = 0x10;
      }
    }
    else {
      if (param_1 != 0x31) goto _L0;
      uVar2 = 7;
      uVar1 = 0x20;
    }
  }
  else if (param_1 == 0x43) {
    uVar2 = 7;
    uVar1 = 0x19;
  }
  else if (param_1 < 0x44) {
    if (param_1 == 0x40) {
      uVar2 = 7;
      uVar1 = 0x19;
    }
    else if (param_1 < 0x41) {
      if (param_1 == 0x33) {
        uVar2 = 7;
        uVar1 = 0x10;
      }
      else {
        if (param_1 != 0x34) goto _L0;
        uVar2 = 5;
        uVar1 = 0x30;
      }
    }
    else if (param_1 == 0x41) {
      uVar2 = 7;
      uVar1 = 0x19;
    }
    else {
      if (param_1 != 0x42) goto _L0;
      uVar2 = 7;
      uVar1 = 0x19;
    }
  }
  else if (param_1 == 0x46) {
    uVar2 = 7;
    uVar1 = 0x19;
  }
  else if (param_1 < 0x47) {
    if (param_1 == 0x44) {
      uVar2 = 7;
      uVar1 = 0x19;
    }
    else {
      if (param_1 != 0x45) goto _L0;
      uVar2 = 7;
      uVar1 = 0x19;
    }
  }
  else {
    if (param_1 != 0x47) {
_L0:
      uVar2 = esp_log_timestamp(param_2);
      esp_log_write(1,0x10000,&_LC11,uVar2,0x10000);
      return 0x102;
    }
    uVar2 = 7;
    uVar1 = 0x19;
  }
  uVar2 = esp_zb_internal_cluster_add_attr(0x101,param_1,uVar1,uVar2,0xffff);
  return uVar2;
}

