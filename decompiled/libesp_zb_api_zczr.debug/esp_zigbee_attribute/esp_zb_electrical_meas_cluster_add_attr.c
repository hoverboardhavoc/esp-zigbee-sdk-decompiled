/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_electrical_meas_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_electrical_meas_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == 0x700) {
    uVar2 = 3;
    uVar1 = 0x18;
  }
  else if (param_1 < 0x701) {
    if (param_1 == 0x306) {
      uVar2 = 5;
      uVar1 = 0x23;
    }
    else if (param_1 < 0x307) {
      if (param_1 < 0x109) {
        if (param_1 < 0x100) {
          if (param_1 != 0) goto _L0;
          uVar2 = 1;
          uVar1 = 0x1b;
        }
        else {
          uVar3 = 1 << (param_1 - 0x100 & 0x1f);
          if ((uVar3 & 0x1b6) == 0) {
            if ((uVar3 & 0x49) == 0) goto _L0;
            uVar2 = 5;
            uVar1 = 0x29;
          }
          else {
            uVar2 = 1;
            uVar1 = 0x29;
          }
        }
      }
      else {
        if (0x305 < param_1) goto _L0;
        if (param_1 < 0x304) {
          if (param_1 < 0x303) {
            if (param_1 < 0x301) {
              if (param_1 < 0x206) {
                if (param_1 < 0x200) goto _L0;
                uVar2 = 5;
                uVar1 = 0x21;
              }
              else {
                if (param_1 != 0x300) goto _L0;
                uVar2 = 5;
                uVar1 = 0x21;
              }
            }
            else {
              uVar2 = 1;
              uVar1 = 0x21;
            }
          }
          else {
            if (param_1 != 0x303) goto _L0;
            uVar2 = 5;
            uVar1 = 0x21;
          }
        }
        else {
          uVar2 = 5;
          uVar1 = 0x2b;
        }
      }
    }
    else if (param_1 < 0x406) {
      if (param_1 < 0x404) {
        if (0x403 < param_1) goto _L0;
        if (param_1 < 0x402) {
          if (param_1 < 0x313) {
            if (param_1 < 0x307) goto _L0;
            uVar2 = 5;
            uVar1 = 0x29;
          }
          else {
            if (1 < (param_1 - 0x400 & 0xffff)) goto _L0;
            uVar2 = 5;
            uVar1 = 0x21;
          }
        }
        else {
          uVar2 = 5;
          uVar1 = 0x23;
        }
      }
      else {
        uVar2 = 5;
        uVar1 = 0x28;
      }
    }
    else if (param_1 < 0x50e) {
      if (param_1 < 0x50c) {
        if (param_1 < 0x508) {
          if (param_1 < 0x506) {
            if (param_1 < 0x504) {
              if (param_1 < 0x502) {
                if (param_1 != 0x501) goto _L0;
                uVar2 = 5;
                uVar1 = 0x21;
              }
              else {
                uVar2 = 5;
                uVar1 = 0x29;
              }
            }
            else {
              if (param_1 != 0x505) goto _L0;
              uVar2 = 5;
              uVar1 = 0x21;
            }
          }
          else {
            uVar2 = 1;
            uVar1 = 0x21;
          }
        }
        else if (param_1 < 0x50b) {
          if (param_1 < 0x509) {
            if (param_1 != 0x508) goto _L0;
            uVar2 = 5;
            uVar1 = 0x21;
          }
          else {
            uVar2 = 1;
            uVar1 = 0x21;
          }
        }
        else {
          if (param_1 != 0x50b) goto _L0;
          uVar2 = 5;
          uVar1 = 0x29;
        }
      }
      else {
        uVar2 = 1;
        uVar1 = 0x29;
      }
    }
    else if (param_1 < 0x518) {
      if (param_1 < 0x511) {
        if (param_1 == 0x50f) {
          uVar2 = 5;
          uVar1 = 0x21;
        }
        else if (param_1 == 0x510) {
          uVar2 = 1;
          uVar1 = 0x29;
        }
        else {
          if (param_1 != 0x50e) goto _L0;
          uVar2 = 5;
          uVar1 = 0x29;
        }
      }
      else {
        uVar2 = 3;
        uVar1 = 0x21;
      }
    }
    else {
      if (5 < (param_1 - 0x600 & 0xffff)) goto _L0;
      uVar2 = 5;
      uVar1 = 0x21;
    }
  }
  else if (param_1 == 0x90b) {
    uVar2 = 5;
    uVar1 = 0x29;
  }
  else if (param_1 < 0x90c) {
    if (param_1 < 0x80b) {
      if (param_1 < 0x807) {
        if (param_1 == 0x800) {
          uVar2 = 3;
          uVar1 = 0x19;
        }
        else if (param_1 < 0x801) {
          if (1 < (param_1 - 0x701 & 0xffff)) goto _L0;
          uVar2 = 1;
          uVar1 = 0x29;
        }
        else {
          if (5 < (param_1 - 0x801 & 0xffff)) {
_L0:
            uVar1 = esp_log_timestamp(param_2);
            esp_log_write(1,0x10000,&_LC11,uVar1,0x10000);
            return 0x102;
          }
          uVar2 = 1;
          uVar1 = 0x29;
        }
      }
      else {
        uVar2 = 3;
        uVar1 = 0x29;
      }
    }
    else if (param_1 < 0x908) {
      if (param_1 < 0x906) {
        if (param_1 < 0x904) {
          if (param_1 < 0x902) {
            if (param_1 != 0x901) goto _L0;
            uVar2 = 5;
            uVar1 = 0x21;
          }
          else {
            uVar2 = 5;
            uVar1 = 0x29;
          }
        }
        else {
          if (param_1 != 0x905) goto _L0;
          uVar2 = 5;
          uVar1 = 0x21;
        }
      }
      else {
        uVar2 = 1;
        uVar1 = 0x21;
      }
    }
    else if (param_1 == 0x908) {
      uVar2 = 5;
      uVar1 = 0x21;
    }
    else {
      if ((param_1 < 0x908) || (1 < (param_1 - 0x909 & 0xffff))) goto _L0;
      uVar2 = 1;
      uVar1 = 0x21;
    }
  }
  else if (param_1 < 0xa08) {
    if (param_1 < 0xa06) {
      if (param_1 == 0x910) {
        uVar2 = 1;
        uVar1 = 0x28;
      }
      else if (param_1 < 0x911) {
        if (param_1 == 0x90e) {
          uVar2 = 5;
          uVar1 = 0x29;
        }
        else if (param_1 < 0x90f) {
          if (1 < (param_1 - 0x90c & 0xffff)) goto _L0;
          uVar2 = 1;
          uVar1 = 0x29;
        }
        else {
          if (param_1 != 0x90f) goto _L0;
          uVar2 = 5;
          uVar1 = 0x21;
        }
      }
      else if (param_1 < 0x918) {
        if (param_1 < 0x911) goto _L0;
        uVar2 = 3;
        uVar1 = 0x21;
      }
      else if (param_1 < 0xa04) {
        if (param_1 < 0xa02) {
          if (param_1 != 0xa01) goto _L0;
          uVar2 = 5;
          uVar1 = 0x21;
        }
        else {
          uVar2 = 5;
          uVar1 = 0x29;
        }
      }
      else {
        if (param_1 != 0xa05) goto _L0;
        uVar2 = 5;
        uVar1 = 0x21;
      }
    }
    else {
      uVar2 = 1;
      uVar1 = 0x21;
    }
  }
  else if (param_1 == 0xa10) {
    uVar2 = 1;
    uVar1 = 0x28;
  }
  else if (param_1 < 0xa11) {
    if (param_1 == 0xa0b) {
      uVar2 = 5;
      uVar1 = 0x29;
    }
    else if (param_1 < 0xa0c) {
      if (param_1 == 0xa08) {
        uVar2 = 5;
        uVar1 = 0x21;
      }
      else {
        if ((param_1 < 0xa08) || (1 < (param_1 - 0xa09 & 0xffff))) goto _L0;
        uVar2 = 1;
        uVar1 = 0x21;
      }
    }
    else if (param_1 == 0xa0e) {
      uVar2 = 5;
      uVar1 = 0x29;
    }
    else if (param_1 < 0xa0f) {
      if (1 < (param_1 - 0xa0c & 0xffff)) goto _L0;
      uVar2 = 1;
      uVar1 = 0x29;
    }
    else {
      if (param_1 != 0xa0f) goto _L0;
      uVar2 = 5;
      uVar1 = 0x21;
    }
  }
  else {
    if (6 < (param_1 - 0xa11 & 0xffff)) goto _L0;
    uVar2 = 3;
    uVar1 = 0x21;
  }
  uVar1 = esp_zb_internal_cluster_add_attr(0xb04,param_1,uVar1,uVar2,0xffff);
  return uVar1;
}

