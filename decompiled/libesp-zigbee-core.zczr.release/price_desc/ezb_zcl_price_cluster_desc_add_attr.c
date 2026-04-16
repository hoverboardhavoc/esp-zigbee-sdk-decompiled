/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> price_desc.o -> ezb_zcl_price_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_price_cluster_desc_add_attr
                    (ezb_zcl_cluster_desc_t cluster_desc,uint16_t attr_id,void *value)

{
  ezb_err_t eVar1;
  undefined2 in_register_0000202e;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = CONCAT22(in_register_0000202e,attr_id);
  if (cluster_desc == (ezb_zcl_cluster_desc_t)0x0) {
    return 2;
  }
                    /* WARNING: Load size is inaccurate */
  uVar6 = 2;
  if (*cluster_desc != 0x700) {
    return 2;
  }
  uVar5 = (uint)*(byte *)((int)cluster_desc + 2);
  uVar3 = 1;
  if (1 < (uVar5 - 1 & 0xffff)) {
    uVar5 = 0;
    uVar3 = 0;
    uVar2 = __assert_func(0,0,value);
  }
  if (uVar5 != uVar3) {
    if (uVar3 < uVar2) goto _L0;
    goto _L0;
  }
  if (uVar2 == 0x621) goto _L0;
  if (uVar2 < 0x622) {
    if (uVar2 == 0x204) {
_L0:
      uVar4 = 0x18;
      goto _L0;
    }
    if (0x204 < uVar2) {
      if (uVar2 == 0x616) {
        uVar4 = 0x21;
        goto _L0;
      }
      if (uVar2 < 0x617) {
        if (uVar2 < 0x307) {
          if (uVar2 < 0x300) {
            return 6;
          }
          uVar2 = 1 << (uVar2 - 0x300 & 0x1f);
          if ((uVar2 & 0x16) == 0) {
            if ((uVar2 & 0x21) == 0) {
              uVar2 = uVar2 & 0x48;
              uVar4 = 0x18;
              goto _L0;
            }
_L0:
            uVar4 = 0x30;
            goto _L0;
          }
        }
        else {
          if (uVar2 == 0x610) goto _L0;
          if (0x610 < uVar2) {
            if (uVar2 != 0x613) {
              if (0x613 < uVar2) {
                uVar6 = 0x615;
                uVar4 = 0x30;
                goto _L0;
              }
              goto _L0;
            }
            goto _L0;
          }
          if (uVar2 < 0x530) {
            if (uVar2 < 0x50f) {
              uVar2 = uVar2 - 0x400;
              goto _L135;
            }
          }
          else if (1 < (uVar2 - 0x5fe & 0xffff)) {
            return 6;
          }
        }
      }
      else {
        if (uVar2 == 0x617) goto _L0;
        if (uVar2 == 0x619) goto _L0;
        uVar6 = 0x620;
_L145:
        if (uVar2 != uVar6) {
          return 6;
        }
      }
_L0:
      uVar4 = 0x23;
      goto _L0;
    }
    if (0x16e < uVar2) {
      if (uVar2 < 0x1cf) {
        uVar6 = 0x1bf;
        if (0x1bf < uVar2) goto _L0;
        if (uVar2 < 0x19f) {
          uVar6 = 399;
          if (399 < uVar2) goto _L0;
          if (uVar2 != 0x17f) {
            if (uVar2 < 0x180) {
              uVar6 = 0x16f;
            }
            goto _L0;
          }
        }
        else if (uVar2 != 0x1af) {
          if (uVar2 < 0x1b0) {
            uVar6 = 0x19f;
          }
          goto _L0;
        }
      }
      else if (uVar2 < 0x1ff) {
        uVar6 = 0x1ef;
        if (0x1ef < uVar2) goto _L0;
        if (uVar2 != 0x1df) {
          if (uVar2 < 0x1e0) {
            uVar6 = 0x1cf;
          }
          goto _L0;
        }
      }
      else {
        if (0x200 < uVar2) goto _L0;
        if (uVar2 != 0x1ff) goto _L0;
      }
      goto _L0;
    }
    if (uVar2 < 0x160) {
      if (0x10e < uVar2) {
        if (uVar2 < 0x13f) {
          uVar6 = 0x12f;
          if (0x12f < uVar2) goto _L0;
          if (uVar2 != 0x11f) {
            if (uVar2 < 0x120) {
              uVar6 = 0x10f;
            }
            goto _L0;
          }
        }
        else if (uVar2 != 0x14f) {
          if (uVar2 < 0x150) {
            uVar6 = 0x13f;
          }
          else {
            uVar6 = 0x15f;
          }
_L0:
          if (uVar2 != uVar6) goto _L0;
        }
_L0:
        uVar4 = 0x20;
        goto _L0;
      }
      if (uVar2 < 0x100) {
        if ((5 < uVar2) && (0x29 < (uVar2 - 6 & 0xffff))) {
          return 6;
        }
        goto _L0;
      }
    }
_L0:
    uVar4 = 0x25;
    goto _L0;
  }
  if (uVar2 < 0x833) {
    if (uVar2 < 0x820) {
      if (uVar2 != 0x802) {
        if (uVar2 < 0x803) {
          if (uVar2 != 0x702) {
            if (uVar2 < 0x703) {
              if (uVar2 != 0x700) {
                if (uVar2 != 0x701) {
                  if (uVar2 != 0x622) {
                    return 6;
                  }
                  goto _L0;
                }
_L0:
                uVar4 = 0x22;
                goto _L0;
              }
            }
            else {
              if (uVar2 == 0x704) goto _L0;
              if (uVar2 < 0x705) goto _L0;
              if (uVar2 != 0x800) {
                uVar6 = 0x801;
                goto _L0;
              }
            }
          }
          goto _L0;
        }
        if (uVar2 != 0x80a) {
          if (uVar2 < 0x80a) {
            return 6;
          }
          if (uVar2 != 0x810) {
            if (uVar2 < 0x811) {
              uVar6 = 0x80b;
_L0:
              if (uVar2 != uVar6) {
                return 6;
              }
              goto _L0;
            }
            if (1 < (uVar2 - 0x811 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          goto _L0;
        }
      }
      uVar4 = 0x2b;
      goto _L0;
    }
    uVar5 = uVar5 << (uVar2 - 0x820 & 0x1f);
    if ((uVar5 & 0x10001) != 0) goto _L0;
    if ((uVar5 & 0x20002) == 0) {
      if ((uVar5 & 0x40004) == 0) {
        return 6;
      }
_L0:
      uVar4 = 0x41;
      goto _L0;
    }
  }
  else if (uVar2 < 0x8204) {
    if (0x8200 < uVar2) goto _L0;
    if (uVar2 < 0x8030) {
      if ((short)uVar2 < 0) goto _L0;
      if (0x12 < (uVar2 - 0x840 & 0xffff)) {
        return 6;
      }
      uVar2 = 1 << (uVar2 - 0x840 & 0x1f);
      if ((uVar2 & 0x10001) != 0) goto _L0;
      if ((uVar2 & 0x20002) == 0) {
        uVar2 = uVar2 & 0x40004;
        uVar4 = 0x41;
_L0:
        if (uVar2 == 0) {
          return 6;
        }
        goto _L0;
      }
    }
    else {
      if (uVar2 < 0x810f) {
        if (uVar2 < 0x8100) {
          return 6;
        }
        goto _L0;
      }
      if (uVar2 != 0x8200) {
        return 6;
      }
    }
  }
  else {
    if (uVar2 == 0x8627) goto _L0;
    if (uVar2 < 0x8628) {
      if (uVar2 < 0x8614) {
        uVar6 = 0x8610;
        if (0x8610 < uVar2) goto _L0;
        if (0x852f < uVar2) {
          uVar4 = 0x41;
          goto _L0;
        }
        if (uVar2 < 0x850f) {
          uVar2 = uVar2 + 0x7c00;
_L135:
          if (0xff < (uVar2 & 0xffff)) {
            return 6;
          }
        }
      }
      else if (uVar2 != 0x8625) {
        if (uVar2 != 0x8626) {
          uVar6 = 0x8615;
          goto _L0;
        }
        goto _L0;
      }
      goto _L0;
    }
    if (uVar2 != 0x8702) {
      if (0x8702 < uVar2) {
        if (uVar2 != 0x8703) {
          uVar6 = 0x8704;
          goto _L145;
        }
        goto _L0;
      }
      if (uVar2 != 0x8700) {
        uVar6 = 0x8701;
        uVar4 = 0x22;
_L0:
        if (uVar2 != uVar6) {
          return 6;
        }
        goto _L0;
      }
    }
  }
_L0:
  uVar4 = 0xe2;
_L0:
  eVar1 = ezb_zcl_cluster_desc_add_manuf_attr(uVar4,0);
  return eVar1;
}

