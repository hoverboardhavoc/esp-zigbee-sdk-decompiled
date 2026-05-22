/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> price_desc.o -> zcl_price_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_price_cluster_get_attr_properties
                    (uint16_t cluster_role,uint16_t attr_id,uint8_t *type,uint8_t *access)

{
  undefined2 in_register_0000202a;
  undefined2 in_register_0000202e;
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = CONCAT22(in_register_0000202e,attr_id);
  if (type == (uint8_t *)0x0) {
    return 2;
  }
  if (access == (uint8_t *)0x0) {
    return 2;
  }
  if ((CONCAT22(in_register_0000202a,cluster_role) - 1U & 0xffff) < 2) {
    if (CONCAT22(in_register_0000202a,cluster_role) != 1) {
      if (uVar3 < 2) {
        *access = '\x03';
        *type = ' ';
        return 0;
      }
      if (uVar3 == 2) {
        *access = '\x01';
        *type = '0';
        return 0;
      }
      return 6;
    }
  }
  else {
    pcVar2 = "cluster_role == 0x01U || cluster_role == 0x02U";
    pcVar1 = "zcl_price_cluster_get_attr_properties";
    uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/price_desc.c",
                          0x16);
    type = (uint8_t *)pcVar1;
    access = (uint8_t *)pcVar2;
  }
  if (uVar3 == 0x621) goto _L0;
  if (uVar3 < 0x622) {
    if (uVar3 == 0x204) {
_L0:
      *access = '\x01';
      *type = '\x18';
      return 0;
    }
    if (0x204 < uVar3) {
      if (uVar3 == 0x616) {
        *access = '\x01';
        *type = '!';
        return 0;
      }
      if (uVar3 < 0x617) {
        if (uVar3 < 0x307) {
          if (uVar3 < 0x300) {
            return 6;
          }
          uVar3 = 1 << (uVar3 - 0x300 & 0x1f);
          if ((uVar3 & 0x16) == 0) {
            if ((uVar3 & 0x21) == 0) {
              if ((uVar3 & 0x48) == 0) {
                return 6;
              }
              goto _L0;
            }
_L0:
            *access = '\x01';
            *type = '0';
            return 0;
          }
        }
        else {
          if (uVar3 == 0x610) goto _L0;
          if (0x610 < uVar3) {
            if (uVar3 != 0x613) {
              if (uVar3 < 0x614) {
                if (1 < (uVar3 - 0x611 & 0xffff)) {
                  return 6;
                }
                goto _L0;
              }
              if (uVar3 != 0x615) {
                return 6;
              }
            }
            goto _L0;
          }
          if (uVar3 < 0x530) {
            if ((uVar3 < 0x50f) && (0xff < (uVar3 - 0x400 & 0xffff))) {
              return 6;
            }
          }
          else if (1 < (uVar3 - 0x5fe & 0xffff)) {
            return 6;
          }
        }
      }
      else {
        if (uVar3 == 0x617) goto _L0;
        if (uVar3 < 0x617) {
          return 6;
        }
        if (uVar3 == 0x619) goto _L0;
        if (uVar3 != 0x620) {
          return 6;
        }
      }
_L0:
      *access = '\x01';
      *type = '#';
      return 0;
    }
    if (uVar3 < 0x16f) {
      if (uVar3 < 0x160) {
        if (uVar3 < 0x10f) {
          if (uVar3 < 0x100) {
            if (uVar3 < 6) goto _L0;
            if (0x29 < (uVar3 - 6 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
        }
        else if (uVar3 < 0x13f) {
          if (uVar3 < 0x130) {
            if (uVar3 == 0x11f) goto _L0;
            if (uVar3 < 0x120) {
              if (uVar3 == 0x10f) goto _L0;
              if (uVar3 < 0x10f) {
                return 6;
              }
              if (0xe < (uVar3 - 0x110 & 0xffff)) {
                return 6;
              }
            }
            else {
              if (0x12e < uVar3) {
                if (uVar3 != 0x12f) {
                  return 6;
                }
                goto _L0;
              }
              if (uVar3 < 0x120) {
                return 6;
              }
            }
          }
        }
        else {
          if (uVar3 == 0x14f) {
_L0:
            *access = '\x01';
            *type = ' ';
            return 0;
          }
          if (uVar3 < 0x150) {
            if (uVar3 == 0x13f) goto _L0;
            if (uVar3 < 0x13f) {
              return 6;
            }
            if (0xe < (uVar3 - 0x140 & 0xffff)) {
              return 6;
            }
          }
          else {
            if (0x15e < uVar3) {
              if (uVar3 != 0x15f) {
                return 6;
              }
              goto _L0;
            }
            if (uVar3 < 0x150) {
              return 6;
            }
          }
        }
      }
    }
    else {
      if (0x1ce < uVar3) {
        if (uVar3 < 0x1ff) {
          if (0x1ef < uVar3) goto _L0;
          if (uVar3 != 0x1df) {
            if (uVar3 < 0x1e0) {
              if (uVar3 == 0x1cf) goto _L0;
              if (uVar3 < 0x1cf) {
                return 6;
              }
              if (0xe < (uVar3 - 0x1d0 & 0xffff)) {
                return 6;
              }
            }
            else {
              if (0x1ee < uVar3) {
                if (uVar3 != 0x1ef) {
                  return 6;
                }
                goto _L0;
              }
              if (uVar3 < 0x1e0) {
                return 6;
              }
            }
            goto _L0;
          }
        }
        else {
          if (0x203 < uVar3) {
            return 6;
          }
          if (0x200 < uVar3) goto _L0;
          if (uVar3 != 0x1ff) {
            if (uVar3 != 0x200) {
              return 6;
            }
            goto _L0;
          }
        }
        goto _L0;
      }
      if (uVar3 < 0x1c0) {
        if (uVar3 < 0x19f) {
          if (uVar3 < 400) {
            if (uVar3 == 0x17f) goto _L0;
            if (uVar3 < 0x180) {
              if (uVar3 == 0x16f) goto _L0;
              if (uVar3 < 0x16f) {
                return 6;
              }
              if (0xe < (uVar3 - 0x170 & 0xffff)) {
                return 6;
              }
            }
            else {
              if (0x18e < uVar3) {
                if (uVar3 != 399) {
                  return 6;
                }
                goto _L0;
              }
              if (uVar3 < 0x180) {
                return 6;
              }
            }
          }
        }
        else {
          if (uVar3 == 0x1af) goto _L0;
          if (uVar3 < 0x1b0) {
            if (uVar3 == 0x19f) goto _L0;
            if (uVar3 < 0x19f) {
              return 6;
            }
            if (0xe < (uVar3 - 0x1a0 & 0xffff)) {
              return 6;
            }
          }
          else {
            if (0x1be < uVar3) {
              if (uVar3 != 0x1bf) {
                return 6;
              }
              goto _L0;
            }
            if (uVar3 < 0x1b0) {
              return 6;
            }
          }
        }
      }
    }
_L0:
    *access = '\x01';
    *type = '%';
    return 0;
  }
  if (uVar3 < 0x833) {
    if (uVar3 < 0x820) {
      if (uVar3 != 0x802) {
        if (uVar3 < 0x803) {
          if (uVar3 != 0x702) {
            if (uVar3 < 0x703) {
              if (uVar3 != 0x700) {
                if (uVar3 != 0x701) {
                  if (uVar3 != 0x622) {
                    return 6;
                  }
                  goto _L0;
                }
                goto _L0;
              }
            }
            else {
              if (uVar3 == 0x704) goto _L0;
              if (uVar3 < 0x705) {
                if (uVar3 != 0x703) {
                  return 6;
                }
                goto _L0;
              }
              if (uVar3 != 0x800) {
                if (uVar3 != 0x801) {
                  return 6;
                }
                goto _L0;
              }
            }
          }
          goto _L0;
        }
        if (uVar3 != 0x80a) {
          if (uVar3 < 0x80a) {
            return 6;
          }
          if (uVar3 != 0x810) {
            if (uVar3 < 0x811) {
              if (uVar3 != 0x80b) {
                return 6;
              }
              goto _L0;
            }
            if (1 < (uVar3 - 0x811 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          goto _L0;
        }
      }
      *access = '\x01';
      *type = '+';
      return 0;
    }
    uVar3 = 1 << (uVar3 - 0x820 & 0x1f);
    if ((uVar3 & 0x10001) != 0) goto _L0;
    if ((uVar3 & 0x20002) == 0) {
      if ((uVar3 & 0x40004) == 0) {
        return 6;
      }
_L0:
      *access = '\x01';
      *type = 'A';
      return 0;
    }
  }
  else if (uVar3 < 0x8204) {
    if (0x8200 < uVar3) goto _L0;
    if (uVar3 < 0x8030) {
      if (0x7fff < uVar3) {
_L0:
        *access = '\x03';
        *type = 'A';
        return 0;
      }
      if (0x852 < uVar3) {
        return 6;
      }
      if (uVar3 < 0x840) {
        return 6;
      }
      uVar3 = 1 << (uVar3 - 0x840 & 0x1f);
      if ((uVar3 & 0x10001) != 0) goto _L0;
      if ((uVar3 & 0x20002) == 0) {
        if ((uVar3 & 0x40004) == 0) {
          return 6;
        }
        goto _L0;
      }
    }
    else {
      if (uVar3 < 0x810f) {
        if (uVar3 < 0x8100) {
          return 6;
        }
        goto _L0;
      }
      if (uVar3 != 0x8200) {
        return 6;
      }
    }
  }
  else {
    if (uVar3 == 0x8627) goto _L0;
    if (uVar3 < 0x8628) {
      if (uVar3 < 0x8614) {
        if (0x8610 < uVar3) goto _L0;
        if (0x852f < uVar3) {
          if (uVar3 != 0x8610) {
            return 6;
          }
          goto _L0;
        }
        if ((uVar3 < 0x850f) && (0xff < (uVar3 + 0x7c00 & 0xffff))) {
          return 6;
        }
      }
      else if (uVar3 != 0x8625) {
        if ((uVar3 != 0x8626) && (uVar3 != 0x8615)) {
          return 6;
        }
        goto _L0;
      }
      goto _L0;
    }
    if (uVar3 != 0x8702) {
      if (uVar3 < 0x8703) {
        if (uVar3 == 0x8700) goto _L0;
        if (uVar3 != 0x8701) {
          return 6;
        }
      }
      else if (uVar3 != 0x8703) {
        if (uVar3 != 0x8704) {
          return 6;
        }
        goto _L0;
      }
_L0:
      *access = '\x01';
      *type = '\"';
      return 0;
    }
  }
_L0:
  *access = '\x01';
  *type = 0xe2;
  return 0;
}

