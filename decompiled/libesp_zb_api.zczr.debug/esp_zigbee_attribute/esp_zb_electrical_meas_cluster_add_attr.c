/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_electrical_meas_cluster_add_attr
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
  
  if (param_1 < 0x518) {
    if (param_1 < 0x511) {
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
      else if (param_1 == 0x50b) {
        uVar2 = 5;
        uVar1 = 0x29;
      }
      else if (param_1 < 0x50c) {
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
        else if (param_1 == 0x508) {
          uVar2 = 5;
          uVar1 = 0x21;
        }
        else {
          if ((param_1 < 0x508) || (1 < (param_1 - 0x509 & 0xffff))) goto _L0;
          uVar2 = 1;
          uVar1 = 0x21;
        }
      }
      else if (param_1 == 0x510) {
        uVar2 = 1;
        uVar1 = 0x28;
      }
      else {
        if (0x510 < param_1) goto _L0;
        if (param_1 == 0x50e) {
          uVar2 = 5;
          uVar1 = 0x29;
        }
        else if (param_1 < 0x50f) {
          if (1 < (param_1 - 0x50c & 0xffff)) goto _L0;
          uVar2 = 1;
          uVar1 = 0x29;
        }
        else {
          if (param_1 != 0x50f) goto _L0;
          uVar2 = 5;
          uVar1 = 0x21;
        }
      }
    }
    else {
      uVar2 = 3;
      uVar1 = 0x21;
    }
  }
  else if (param_1 < 0x80b) {
    if (param_1 < 0x807) {
      if (param_1 < 0x703) {
        if (param_1 < 0x701) {
          if (param_1 < 0x606) {
            if (param_1 < 0x600) goto _L0;
            uVar2 = 5;
            uVar1 = 0x21;
          }
          else {
            if (param_1 != 0x700) {
_L0:
              uVar1 = esp_log_timestamp(param_2);
              esp_log(1,0x10000,"E (%lu) %s: incorrect/unsupported attribute_id!\n",uVar1,0x10000);
              return 0x102;
            }
            uVar2 = 3;
            uVar1 = 0x18;
          }
        }
        else {
          uVar2 = 1;
          uVar1 = 0x29;
        }
      }
      else if (param_1 == 0x800) {
        uVar2 = 3;
        uVar1 = 0x19;
      }
      else {
        if ((param_1 < 0x800) || (5 < (param_1 - 0x801 & 0xffff))) goto _L0;
        uVar2 = 1;
        uVar1 = 0x29;
      }
    }
    else {
      uVar2 = 3;
      uVar1 = 0x29;
    }
  }
  else if (param_1 == 0xa01) {
    uVar2 = 5;
    uVar1 = 0x21;
  }
  else if (param_1 < 0xa02) {
    if (param_1 == 0x90e) {
      uVar2 = 5;
      uVar1 = 0x29;
    }
    else if (param_1 < 0x90f) {
      if (param_1 == 0x908) {
        uVar2 = 5;
        uVar1 = 0x21;
      }
      else if (param_1 < 0x909) {
        if (param_1 == 0x905) {
          uVar2 = 5;
          uVar1 = 0x21;
        }
        else if (param_1 < 0x906) {
          if (param_1 == 0x901) {
            uVar2 = 5;
            uVar1 = 0x21;
          }
          else {
            if ((param_1 < 0x901) || (1 < (param_1 - 0x902 & 0xffff))) goto _L0;
            uVar2 = 5;
            uVar1 = 0x29;
          }
        }
        else {
          if (1 < (param_1 - 0x906 & 0xffff)) goto _L0;
          uVar2 = 1;
          uVar1 = 0x21;
        }
      }
      else if (param_1 == 0x90b) {
        uVar2 = 5;
        uVar1 = 0x29;
      }
      else if (param_1 < 0x90c) {
        if (1 < (param_1 - 0x909 & 0xffff)) goto _L0;
        uVar2 = 1;
        uVar1 = 0x21;
      }
      else {
        if (1 < (param_1 - 0x90c & 0xffff)) goto _L0;
        uVar2 = 1;
        uVar1 = 0x29;
      }
    }
    else if (param_1 == 0x910) {
      uVar2 = 1;
      uVar1 = 0x28;
    }
    else if (param_1 < 0x911) {
      if (param_1 != 0x90f) goto _L0;
      uVar2 = 5;
      uVar1 = 0x21;
    }
    else {
      if (6 < (param_1 - 0x911 & 0xffff)) goto _L0;
      uVar2 = 3;
      uVar1 = 0x21;
    }
  }
  else if (param_1 == 0xa0e) {
    uVar2 = 5;
    uVar1 = 0x29;
  }
  else if (param_1 < 0xa0f) {
    if (param_1 < 0xa0b) {
      if (param_1 < 0xa09) {
        if (param_1 < 0xa08) {
          if (param_1 < 0xa06) {
            if (param_1 < 0xa04) {
              if (param_1 < 0xa02) goto _L0;
              uVar2 = 5;
              uVar1 = 0x29;
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
        else {
          if (param_1 != 0xa08) goto _L0;
          uVar2 = 5;
          uVar1 = 0x21;
        }
      }
      else {
        uVar2 = 1;
        uVar1 = 0x21;
      }
    }
    else if (param_1 == 0xa0b) {
      uVar2 = 5;
      uVar1 = 0x29;
    }
    else {
      if ((param_1 < 0xa0b) || (1 < (param_1 - 0xa0c & 0xffff))) goto _L0;
      uVar2 = 1;
      uVar1 = 0x29;
    }
  }
  else if (param_1 == 0xa10) {
    uVar2 = 1;
    uVar1 = 0x28;
  }
  else if (param_1 < 0xa11) {
    if (param_1 != 0xa0f) goto _L0;
    uVar2 = 5;
    uVar1 = 0x21;
  }
  else {
    if (6 < (param_1 - 0xa11 & 0xffff)) goto _L0;
    uVar2 = 3;
    uVar1 = 0x21;
  }
  uVar1 = esp_zb_internal_cluster_add_attr(0xb04,param_1,uVar1,uVar2,0xffff);
  return uVar1;
}

